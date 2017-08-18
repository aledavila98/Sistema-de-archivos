//
// Created by alejandro on 07-25-17.
//

#ifndef SISTEMAARCHIVOS_ADMINBLOQUE_H
#define SISTEMAARCHIVOS_ADMINBLOQUE_H
#include "Bloques.h"
#include "BloqueCampos.h"
#include "BloqueTablas.h"
#include "BloqueRegistros.h"
#include "MasterBlock.h"


class AdminBloque
{
public:
    MasterBlock* masterBlock;
    AdminBloque(DataFile* fil)
    {
        file=fil;
        if(file->isEmpty())
        {
            formatDataFile();
            asignarBloque();
            UpdateMasterBlock();
        }else
        {
            masterBlock= new MasterBlock(file,0,-1,-1);
            masterBlock->cargar();
        }
        contBloques+=1;
    }

    void formatDataFile() {
        masterBlock = new MasterBlock(file,-1,-1,-1);
        masterBlock->escribir();
    }


    Bloques* asignarBloque()
    {
        Bloques* block = new Bloques(this->file,this->sigBloqueDisponible++);
        block->escribir();
        UpdateMasterBlock();
        return block;
    }

    Bloques* loadBloque(int numBlock) {
        Bloques* bloque = new Bloques(numBlock);
        bloque->cargar();
        return bloque;
    };

    void UpdateMasterBlock(){
        masterBlock->cargar();
    }

    private:
        int contBloques=0;
        DataFile* file;
        int sigBloqueDisponible=0;

};

#endif //SISTEMAARCHIVOS_ADMINBLOQUE_H
