//
// Created by alejandro on 08-27-17.
//

#ifndef SISTEMAARCHIVOS_JSONMANAGER_H
#define SISTEMAARCHIVOS_JSONMANAGER_H

#include "json.hpp"
#include "BloqueTablas.h"

using json = nlohmann::json;

class JsonManager{
public:
    json arrayTablas;
    json arrayCampos;

    JsonManager() {}

    void AgregarTablas(BloqueTablas* bt)
    {
        for (std::list<Tablas*>::iterator c = bt->listaTablas.begin(); c!=bt->listaTablas.end(); c++)
        {
            Tablas* tmp = *c;
            arrayTablas.push_back(tmp);
        }
    }

    void AgregarCampos(BloqueTablas* bt)
    {

    }
};

#endif //SISTEMAARCHIVOS_JSONMANAGER_H
