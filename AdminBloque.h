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
    AdminBloque()
    {
        contBloques+=1;
    }

    void formatDataFile() {

    }

    Bloques* loadBloque(int numBlock) {
        Bloques* bloque = new Bloques(numBlock);
        bloque->cargar();
        return bloque;
    };

    Bloques* asignarBloque(MasterBlock* mb)
    {
        Bloques* block = new Bloques(mb->sigBloqueDisponible++);
        block->escribir();
        ActualizarMasterBlock();
        return block;
    }

    void ActualizarMasterBlock() {}

    private:
        int contBloques=0;
        DataFile* file;

};

#endif //SISTEMAARCHIVOS_ADMINBLOQUE_H
