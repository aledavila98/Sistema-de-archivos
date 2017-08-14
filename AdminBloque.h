//
// Created by alejandro on 07-25-17.
//

#ifndef SISTEMAARCHIVOS_ADMINBLOQUE_H
#define SISTEMAARCHIVOS_ADMINBLOQUE_H
class MasterBlock;
#include "Bloques.h"
#include "BloqueCampos.h"
#include "BloqueTablas.h"
#include "BloqueRegistros.h"
#include "MasterBlock.h"


class AdminBloque
{
    MasterBlock* masterBlock;
    AdminBloque(DataFile* fil)
    {
        file=fil;
        if(file->isEmpty())
        {
            formatDataFile();
            masterBlock->asignarBloque();
            masterBlock->UpdateMasterBlock();
        }else
        {
            masterBlock= new MasterBlock(file,0,-1,-1);
            masterBlock->cargar();
        }
        contBloques+=1;
    }

    void formatDataFile() {
        masterBlock = new MasterBlock(0,-1,-1,-1);
        masterBlock->escribir();
    }

    Bloques* loadBloque(int numBlock) {
        Bloques* bloque = new Bloques(numBlock);
        bloque->cargar();
        return bloque;
    };

    private:
        int contBloques=0;
        DataFile* file;

};

#endif //SISTEMAARCHIVOS_ADMINBLOQUE_H
