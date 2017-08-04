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
        int sigBloqueDisponible=0;
        int sizeBloque;
        int sizeMasterBlock;
        int primerBloqueTabla;
        int actualBloqueTabla;
        int ultimoBloqueDisponible;
        int cantBloquesUsados;
        DataFile* file;

        MasterBlock(int nb, int sig, char* p) : Bloques(nb,sig,p) {
            Bloques::numeroBloque = nb;
            Bloques::siguiente = sig;
            numeroBloque=nb;
            file = new DataFile(p);
            file->crear();
        }
        Bloques* asignarBloque()
        {

        }

        void updateMasterBlock(){

        }

        Bloques* loadBlock(int i)
        {
            Bloques* bloque = new Bloques(i);
            bloque->cargar();
            return  bloque;
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

    private:

};

#endif //SISTEMAARCHIVOS_MASTERBLOCK_H
