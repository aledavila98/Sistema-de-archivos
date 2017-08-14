//
// Created by alejandro on 08-03-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUECAMPOS_H
#define SISTEMAARCHIVOS_BLOQUECAMPOS_H

#include "Bloques.h"
#include <list>

class Campos{
    public:
        char nombre[20];
        int tipo;
        int longi;
        Campos* next;

        Campos(char nom[20], int t, int l){
            strncpy(this->nombre,nom,sizeof(nombre)-1);
            nombre[19] = '\0';
            tipo = t;
            longi = l;
            next = 0;
        }

        char * toChar()
        {
            char* data = new char[28];
            int pos=0;
            memcpy(&data[pos],&nombre,20);
            pos+=20;
            memcpy(&data[pos],&tipo,4);
            pos+=4;
            memcpy(&data[pos],&longi,4);
            pos+=4;
            return data;
        }
        void toCampo(char* data){
            int pos=0;
            memcpy(&nombre,&data[pos],20);
            pos+=20;
            memcpy(&tipo,&data[pos],4);
            pos+=4;
            memcpy(&longi,&data[pos],4);
            pos+=4;
        }
};

class CampoDatos{

};

class BloqueCampos : public Bloques
{
    public:
        int cant;
        int numeroBloque;
        std::list<Campos*> camposList;
        BloqueCampos(DataFile* fil,int nb) : Bloques(fil,nb) {
            numeroBloque = nb;
            file = fil;
        }

        char* toChar()
        {
            char* data = new char[sizeBloque];
            int pos = 0;
            memcpy(&data[pos],&numeroBloque,4);
            pos+=4;
            memcpy(&data[pos],&sizeBloque,4);
            pos+=4;
            memcpy(&data[pos],&siguiente,4);
            pos+=4;
            for (std::list<Campos*>::iterator c = camposList.begin(); c!=camposList.end(); c++)
            {
                Campos* tmp = *c;
                char* entries = tmp->toChar();
                memcpy(&data[pos],&entries,28);
                pos+=28;
            }
            return data;
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
            for (std::list<Campos*>::iterator c = camposList.begin(); c!=camposList.end(); c++)
            {
                Campos* campos = new Campos("",0,28);
                campos->toCampo(&data[pos]);
                camposList.push_back(campos);
                pos+=40;
            }
        }

    /*   char* data = new char[512];
        int pos=0;
        //memcpy(,&Bloques::numeroBloque)
    }*/


    private:
        int sizeBloque = 512;
        DataFile* file;

};

#endif //SISTEMAARCHIVOS_BLOQUECAMPOS_H
