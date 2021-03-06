//
// Created by alejandro on 07-26-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUETABLAS_H
#define SISTEMAARCHIVOS_BLOQUETABLAS_H


#include "Bloques.h"
#include "BloqueCampos.h"
#include "BloqueRegistros.h"
#include "AdminBloque.h"

#include <list>

class Tablas{
    public:
        char nombre[20];
        int ID;
        int primerBloqueCampos;
        int actualBloqueCampos;
        int primerBloqueRegistros;
        int actualBloqueRegistros;
        int numeroBloque;
        std::list<Campos*> listCampos;
        std::list<Registros*> listRegistros;

        Tablas(DataFile* file1,char nom[20],int ID,int pb,int ab, int pbr,int abr,int numBlock) {
            strncpy(this->nombre,nom, sizeof(this->nombre));
            this->ID = ID;
            primerBloqueCampos=pb;
            actualBloqueCampos=ab;
            primerBloqueRegistros=pbr;
            actualBloqueRegistros=abr;
            numeroBloque = numBlock;
            file = file1;
        }

        Tablas() {}

        void CargarCampos()
        {
            int actual=primerBloqueCampos;
            while(actual!=-1)
            {
                BloqueCampos* blockCampos= new BloqueCampos(file,actual);
                blockCampos->cargar();
                std::list<Campos*>::iterator itBC = blockCampos->camposList.begin();
                for(int c=0;c<blockCampos->cant;c++)
                {
                    listCampos.push_back(*itBC);
                    itBC++;
                }
                actual=blockCampos->siguiente;
            }
        }

        void crearCampo(AdminBloque* block,char name[20],int tipo) {
            Campos *campos = new Campos(name, tipo, 28);
            if (primerBloqueCampos == -1) {
                int numBlock = block->asignarBloque()->numeroBloque;
                BloqueCampos *blockCamps = new BloqueCampos(file, numBlock);
                blockCamps->camposList.push_back(campos);
                blockCamps->cant++;
                blockCamps->escribir();
                listCampos.push_back(campos);
                primerBloqueCampos = blockCamps->numeroBloque;
                actualBloqueCampos = blockCamps->numeroBloque;
                return;
            }
                int actual = primerBloqueCampos;
                while (actual != -1) {
                    BloqueCampos *blockCamps = new BloqueCampos(file, actual);
                    blockCamps->cargar();
                    int maximo = 17;
                    if (blockCamps->cant < maximo) {
                        blockCamps->camposList.push_back(campos);
                        blockCamps->cant++;
                        blockCamps->escribir();
                        listCampos.push_back(campos);
                        return;
                    }
                    actual = blockCamps->siguiente;
                }
                BloqueCampos *bloqueCampos = new BloqueCampos(file, block->asignarBloque()->numeroBloque);
                BloqueCampos *tmpBlock = new BloqueCampos(file, actualBloqueCampos);
                tmpBlock->cargar();
                tmpBlock->siguiente = bloqueCampos->numeroBloque;
                tmpBlock->escribir();
                bloqueCampos->camposList.push_back(campos);
                bloqueCampos->cant++;
                bloqueCampos->escribir();
                actualBloqueCampos = bloqueCampos->numeroBloque;

        }

        void CrearRegistro(AdminBloque* adblock, Registros* reg)
        {
            if(primerBloqueRegistros==-1)
            {
                Bloques* b = adblock->asignarBloque();
                BloqueRegistros* br= new BloqueRegistros(file, b->numeroBloque);
                br->listRegistros.push_back(reg);
                br->cantReg++;
                br->escribir();
                listRegistros.push_back(reg);
                primerBloqueRegistros=b->numeroBloque;
                actualBloqueRegistros=b->numeroBloque;
                return;
            }
            int actual=primerBloqueRegistros;
            while(actual!=-1)
            {
                BloqueRegistros* br = new BloqueRegistros(file,actual);
                br->cargar();
                int max = 496/reg->length;
                if(br->listRegistros.size() < 2)
                {
                    br->listRegistros.push_back(reg);
                    br->cantReg++;
                    br->escribir();
                    listRegistros.push_back(reg);
                    return;
                }
                actual=br->siguiente;
            }

            Bloques* b=adblock->asignarBloque();
            BloqueRegistros* br = new BloqueRegistros(file,b->numeroBloque);
            BloqueRegistros* tmp = new BloqueRegistros(file,actualBloqueRegistros);
            tmp->cargar();
            tmp->siguiente = br->numeroBloque;
            tmp->escribir();
            br->listRegistros.push_back(reg);
            listRegistros.push_back(reg);
            br->cantReg++;
            br->escribir();
            actualBloqueRegistros=b->numeroBloque;
        }

        void CargarRegistros()
        {
            int actual = primerBloqueRegistros;
            while(actual!=-1)
            {
                BloqueRegistros* br = new BloqueRegistros(file,actual);
                int longitudRegistro = this->GetLongitudRegistros();
                br->cargar();
                std::list<Registros*>::iterator c = br->listRegistros.begin();
                for(int x=0;x< br->listRegistros.size();x++)
                {
                    std::advance(c,x);
                    Registros* tmp = *c;
                    listRegistros.push_back(InterpretarRegistros(tmp->ToChar(),longitudRegistro));
                }
                actual=br->siguiente;
            }
        }

        int GetLongitudRegistros()
        {
            int sum=0;
            for(std::list<Campos*>::iterator c = listCampos.begin(); c!=listCampos.end(); c++)
            {
                Campos* tmp = *c;
                sum+=tmp->longi;
            }
            return sum;
        }



        Registros* InterpretarRegistros(char* data, int length)
        {
            int pos=0;
            Registros * registros= new Registros(length);
            std::list<Campos*>::iterator c = listCampos.begin();
            for(int i=0; i<listCampos.size(); i++)
            {
                std::advance(c,i);
                Campos* tmp = *c;
                CampoDatos* campoDatos= new CampoDatos();
                Campos* defCampo= tmp;
                campoDatos->campos =defCampo;
                memcpy(&campoDatos->valor,&data[pos],20);
                pos+=defCampo->longi;
                registros->campDatosList.push_back(campoDatos);
            }
            return registros;
        }

        char* toChar(){
            char* data = new char[44];
            int pos = 0;
            memcpy(&data[pos],&nombre,20);
            pos+=20;
            memcpy(&data[pos],&ID,4);
            pos+=4;
            memcpy(&data[pos],&primerBloqueCampos,4);
            pos+=4;
            memcpy(&data[pos],&actualBloqueCampos,4);
            pos+=4;
            memcpy(&data[pos],&primerBloqueRegistros,4);
            pos+=4;
            memcpy(&data[pos],&actualBloqueRegistros,4);
            pos+=4;
            memcpy(&data[pos],&numeroBloque,4);
            pos+=4;
        }

        void toBloque(char* data)
        {
            int pos=0;
            memcpy(&nombre,&data[pos],20);
            pos+=20;
            memcpy(&ID,&data[pos],4);
            pos+=4;
            memcpy(&primerBloqueCampos,&data[pos],4);
            pos+=4;
            memcpy(&actualBloqueCampos,&data[pos],4);
            pos+=4;
            memcpy(&primerBloqueRegistros,&data[pos],4);
            pos+=4;
            memcpy(&actualBloqueRegistros,&data[pos],4);
            pos+=4;
            memcpy(&numeroBloque,&data[pos],4);
            pos+=4;
        }

private:
    DataFile* file;
};


class BloqueTablas : public Bloques
{

    public:
        std::list<Tablas*> listaTablas;

        BloqueTablas(DataFile* file, int nB) : Bloques(file,nB)
        {
            this->file = file;
            this->numeroBloque = nB;
            siguiente=-1;
        }

        char* toChar()
        {
            char* data = new char[(listaTablas.size()*44)+16];
            int pos = 0;
            memcpy(&data[pos],&numeroBloque,4);
            pos+=4;
            memcpy(&data[pos],&sizeBloque,4);
            pos+=4;
            memcpy(&data[pos],&siguiente,4);
            pos+=4;
            memcpy(&data[pos],&cantEntradas,4);
            pos+=4;
            for (std::list<Tablas*>::iterator c = listaTablas.begin(); c != listaTablas.end(); c++)
            {
                Tablas* tmp = *c;
                char* entries = tmp->toChar();
                memcpy(&data[pos],&entries,44);
                pos+=44;
            }
            return  data;
        }

        void toBloque(char* data)
        {
            int pos=0;
            memcpy(&numeroBloque,&data[pos],4);
            pos+=4;
            memcpy(&sizeBloque,&data[pos],4);
            pos+=4;
            memcpy(&siguiente,&data[pos],4);
            pos+=4;
            memcpy(&cantEntradas,&data[pos],4);
            pos+=4;
            for (int c=0; c<cantEntradas; c++)
            {
                Tablas* tabla = new Tablas();
                tabla->toBloque(&data[pos]);
                listaTablas.push_back(tabla);
                pos+=44;
            }
        }

    void escribir()
    {
        file->abrir();
        char* data = this->toChar();
        int pos= numeroBloque*sizeBloque+20;
        file->escribir(data,pos,sizeBloque);
        file->cerrar();
    }

    void cargar()
    {
        file->abrir();
        int pos= numeroBloque * sizeBloque+20;
        char* data = file->leer(pos,sizeBloque);
        toBloque(data);
        file->cerrar();
    }

    int cantEntradas = 0;

    DataFile* file;
};

#endif //SISTEMAARCHIVOS_BLOQUETABLAS_H
