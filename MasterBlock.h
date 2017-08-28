//
// Created by alejandro on 07-27-17.
//

#ifndef SISTEMAARCHIVOS_MASTERBLOCK_H
#define SISTEMAARCHIVOS_MASTERBLOCK_H

#include "Bloques.h"
#include "DataFile.h"

class MasterBlock : public Bloques
{
    public:
        int sigBloqueDisponible;
        int sizeMasterBlock;
        int primerBloqueTabla;
        int actualBloqueTabla;
        int ultimoBloqueDisponible;
        int cantBloquesUsados;


        MasterBlock(DataFile* file1, int sigBD, int primBT, int actBT) : Bloques(file1,0) {
            file=file1;
            sigBloqueDisponible = sigBD;
            primerBloqueTabla = primBT;
            actualBloqueTabla = actBT;
            sizeMasterBlock = 20;
            sizeBloque = 512;
        }



        char* toChar()
        {
            char* data= new char[sizeMasterBlock];
            int pos=0;
            memcpy(&data[pos],&sigBloqueDisponible,4);
            pos+=4;
            memcpy(&data[pos],&sizeBloque,4);
            pos+=4;
            memcpy(&data[pos],&primerBloqueTabla,4);
            pos+=4;
            memcpy(&data[pos],&actualBloqueTabla,4);
            pos+=4;
            memcpy(&data[pos],&sizeMasterBlock,4);
            pos+=4;
            return data;
        }

        void toBlock(char* data)
        {
            int pos=0;
            memcpy(&sigBloqueDisponible,&data[pos],4);
            pos+=4;
            memcpy(&sizeBloque,&data[pos],4);
            pos+=4;
            memcpy(&primerBloqueTabla,&data[pos],4);
            pos+=4;
            memcpy(&actualBloqueTabla,&data[pos],4);
            pos+=4;
            memcpy(&sizeMasterBlock,&data[pos],4);
            pos+=4;
        }

    void cargar()
    {
        file->abrir();
        char* data = file->leer(0,512);
        toBlock(data);
        file->cerrar();
    }

    void escribir()
    {
        file->abrir();
        char* data = this->toChar();
        file->escribir(data,0,512);
        file->cerrar();
    }


    private:
    DataFile* file;
};

#endif //SISTEMAARCHIVOS_MASTERBLOCK_H
