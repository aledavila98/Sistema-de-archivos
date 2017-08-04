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

class BloqueCampos : public Bloques
{
    public:
        std::list<Campos*> camposList;
        BloqueCampos(int nb) : Bloques(nb) {
            numeroBloque = nb;
        }

        //char* to Char()

    /*   char* data = new char[512];
        int pos=0;
        //memcpy(,&Bloques::numeroBloque)
    }*/


    private:
        int numeroBloque;
        int sizeBloque = 512;

};

#endif //SISTEMAARCHIVOS_BLOQUECAMPOS_H
