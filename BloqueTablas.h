//
// Created by alejandro on 07-26-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUETABLAS_H
#define SISTEMAARCHIVOS_BLOQUETABLAS_H


#include "Bloques.h"
#include "BloqueCampos.h"

#include <list>

class Tablas{
    public:
        char nombre[20];
        int ID;
        int primerBloque;
        int actualBloque;
        int primerBloqueRegistros;
        int actualBloqueRegistros;


        Tablas(char nom[20],int ID,int pb,int ab, int pbr,int abr) {
            strncpy(this->nombre,nom, sizeof(this->nombre)-1);
            nombre[19]='\0';
            this->ID = ID;
            primerBloque=pb;
            actualBloque=ab;
            primerBloqueRegistros=pbr;
            actualBloqueRegistros=abr;
        }
        void CargarCampos()
        {
            actualBloqueRegistros = primerBloqueRegistros;
            while (actualBloqueRegistros!=-1)
            {
                BloqueCampos* bloque = new BloqueCampos(actualBloqueRegistros);
                bloque->cargar();
                int lengthReg = 0;
            }
        }

        void InterpretarRegistros(char* data, int length)
        {

        }

        char* toChar(){
            char* data = new char[40];
            int pos = 0;
            memcpy(&data[pos],&nombre,20);
            pos+=20;
            memcpy(&data[pos],&ID,4);
            pos+=4;
            memcpy(&data[pos],&primerBloque,4);
            pos+=4;
            memcpy(&data[pos],&actualBloque,4);
            pos+=4;
            memcpy(&data[pos],&primerBloqueRegistros,4);
            pos+=4;
            memcpy(&data[pos],&actualBloqueRegistros,4);
            pos+=4;
        }

        Tablas() {}

        void toBloque(char* data)
        {
            int pos=0;
            memcpy(&nombre,&data[pos],20);
            pos+=20;
            memcpy(&ID,&data[pos],4);
            pos+=4;
            memcpy(&primerBloque,&data[pos],4);
            pos+=4;
            memcpy(&actualBloque,&data[pos],4);
            pos+=4;
            memcpy(&primerBloqueRegistros,&data[pos],4);
            pos+=4;
            memcpy(&actualBloqueRegistros,&data[pos],4);
            pos+=4;
        }
};


class BloqueTablas : public Bloques
{

    public:
        std::list<Tablas*> listaTablas;
        BloqueTablas(int nb, int siguiente, char* path, char nom[20], int ID, int primerBloque, int actualBloque, int primerBloqueRegistros
        ,int actualBloqueRegistros) : Bloques(nb, siguiente, path) {
            BloqueTablas::numeroBloque = nb;
            BloqueTablas::siguiente = siguiente;
            listaTablas.push_back(new Tablas(nom,ID,primerBloque,actualBloque,primerBloqueRegistros,actualBloqueRegistros));
        }

        char* toChar()
        {
            char* data = new char[Bloques::sizeBloque];
            int pos = 0;
            memcpy(&data[pos],&numeroBloque,4);
            pos+=4;
            memcpy(&data[pos],&sizeBloque,4);
            pos+=4;
            memcpy(&data[pos],&siguiente,4);
            pos+=4;
            memcpy(&data[pos],&cantEntradas,4);
            pos+=4;
            for (std::list<Tablas*>::iterator c = listaTablas.begin(); c!=listaTablas.end(); c++)
            {
                Tablas* tmp = *c;
                char* entries = tmp->toChar();
                memcpy(&data[pos],&entries,40);
                pos+=40;
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
                pos+=40;
            }
        }

    private:
        int cantEntradas = listaTablas.size();
        DataFile* file;
};

#endif //SISTEMAARCHIVOS_BLOQUETABLAS_H
