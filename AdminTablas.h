//
// Created by alejandro on 07-27-17.
//

#ifndef SISTEMAARCHIVOS_ADMINTABLAS_H
#define SISTEMAARCHIVOS_ADMINTABLAS_H

#include "BloqueTablas.h"
#include "MasterBlock.h
#include <list>

class AdminTablas
{
    AdminTablas() {}

    Tablas* CrearTablas(char nom[20], int ID, int pb, int ab, int pbr, int abr)
    {
        return new Tablas(nom,ID,pb,ab,pbr,abr);
    }

    bool BuscarTabla(char* nom, BloqueTablas* bt)
    {
        for (int c=0; c<bt->sizeBloque; c++){
            for (std::list<Tablas*>::iterator c = bt->listaTablas.begin(); c!=bt->listaTablas.end(); c++)
            {
                Tablas* tmp = *c;
                if (tmp->nombre == nom)
                    return true;
            }
        }
        return false;
    }

    void ListarTablas(std::list<Tablas*> tablas)
    {
        for (std::list<Tablas*>::iterator c = tablas.begin(); c!=tablas.end(); c++)
        {
            Tablas* tmp = *c;
            printf(tmp->nombre);
        }
    }

};

#endif //SISTEMAARCHIVOS_ADMINTABLAS_H
