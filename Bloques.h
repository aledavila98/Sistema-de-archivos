//
// Created by alejandro on 07-24-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUES_H
#define SISTEMAARCHIVOS_BLOQUES_H

#include <list>
#include <memory.h>
#include "DataFile.h"

class Bloques{
    public:
        int numeroBloque;
        int sizeBloque=512;
        int siguiente;
        DataFile* file;

        Bloques(int nb)
        {
            numeroBloque = nb;
        }

        Bloques(int nb, int siguiente,char* path) {
            numeroBloque=nb;
            Bloques::siguiente=siguiente;
            file = new DataFile(path);
            file->crear();//lo movere luego
        }

       /* void numBlock()
        {
            if (numeroBloque == 0)
                numeroBloque = 1;
            else{}
        }
        */



        void cargar()
        {
            file->abrir();
            int pos= numeroBloque * sizeBloque;
            char* data = file->leer(pos,sizeBloque);
            toBloque(data);
            file->cerrar();
        }

        void escribir()
        {
            file->abrir();
            char* data = this->toChar();
            int pos= numeroBloque*sizeBloque;
            file->escribir(data,pos,sizeBloque);
            file->cerrar();
        }

    private:
        void toBloque(char* data)
        {
            int pos = 0;
            memcpy(&numeroBloque,&data[pos],4);
            pos+=4;
            memcpy(&sizeBloque,&data[pos],4);
            pos+=4;
            memcpy(&siguiente,&data[pos],4);
            pos+=4;
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
            return data;
        }


};

#endif //SISTEMAARCHIVOS_BLOQUES_H
