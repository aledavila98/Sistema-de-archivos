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
        DataFile* file;

        MasterBlock(DataFile* file1, int sigBD, int primBT, int actBT) : Bloques(0,sizeMasterBlock,sigBD) {
            file=file1;
            sigBloqueDisponible = sigBD;
            primerBloqueTabla = primBT;
            actualBloqueTabla = actBT;
            sizeMasterBlock = 20;
            sizeBloque = 512;
        }

        Bloques* asignarBloque()
        {
            Bloques* block = new Bloques(this->file,this->sigBloqueDisponible++);
            block->escribir();
            UpdateMasterBlock();
            return block;
        }

        void UpdateMasterBlock(){
            this->cargar();
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
