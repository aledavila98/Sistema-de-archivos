//
// Created by alejandro on 07-26-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUEREGISTROS_H
#define SISTEMAARCHIVOS_BLOQUEREGISTROS_H

#include "Bloques.h"

class Registros {
    public:
        int length;
        std::list<CampoDatos> campDatosList;

};

class BloqueRegistros : public Bloques
{
public:

    BloqueRegistros(int nb, int siguiente, char *path) : Bloques(file, siguiente) {}

    int getLengthRegistros()
    {
        int sum = 0;
        Registros* reg = new Registros();
        for (int c=0; c<reg->length; c++)
            sum+=1;
    }

private:


};


#endif //SISTEMAARCHIVOS_BLOQUEREGISTROS_H
