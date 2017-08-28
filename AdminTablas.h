//
// Created by alejandro on 07-27-17.
//

#ifndef SISTEMAARCHIVOS_ADMINTABLAS_H
#define SISTEMAARCHIVOS_ADMINTABLAS_H

#include "BloqueTablas.h"
#include "MasterBlock.h"
#include <list>

class AdminTablas
{
public:
    std::list<BloqueTablas*> bTablasList;
    DataFile* file;
    AdminTablas(DataFile* file, MasterBlock* mb) {
        this->file = file;
        if (mb->primerBloqueTabla != -1) {
            loadBloqueTabla();
            for(std::list<BloqueTablas*>::iterator c = bTablasList.begin(); c!= bTablasList.end();c++)
            {
                BloqueTablas* bt= *c;
                for(std::list<Tablas*>::iterator x = bt->listaTablas.begin(); x!=bt->listaTablas.end(); x++)
                {
                    Tablas* t= *x;
                    t->CargarCampos();
                }
            }
        }
    }

    void CrearTablas(char nom[20], AdminBloque* bloque, int ID) {
        Tablas *t = new Tablas(file,nom, ID, -1, -1, -1, -1, 0);
        if (bloque->masterBlock->primerBloqueTabla == -1) {
            BloqueTablas *blockTablas = new BloqueTablas(file, 0);
            blockTablas->listaTablas.push_back(t);
            blockTablas->cantEntradas++;
            blockTablas->escribir();
            bTablasList.push_back(blockTablas);
            bloque->masterBlock->actualBloqueTabla = 0;
            bloque->masterBlock->primerBloqueTabla = 0;
            bloque->masterBlock->escribir();
            return;
        }
        int x = 0;
        for (std::list<BloqueTablas *>::iterator c = bTablasList.begin(); c != bTablasList.end(); c++) {
            BloqueTablas *bt = *c;
            int max = 11;
            if (bt->cantEntradas < max) {
                t->numeroBloque = bt->numeroBloque;
                bt->listaTablas.push_back(t);
                bt->cantEntradas++;
                bt->escribir();

                return;
            }
            x++;
        }

        std::list<BloqueTablas *>::iterator c = bTablasList.begin();
        std::advance(c, x-1);
        BloqueTablas *bt = *c;
        int nbloque=bloque->asignarBloque()->numeroBloque;
        bt->siguiente = nbloque;
        bt->escribir();
        BloqueTablas *tmp = new BloqueTablas(file, nbloque);
        t->numeroBloque = tmp->numeroBloque;
        tmp->listaTablas.push_back(t);
        tmp->cantEntradas++;
        tmp->escribir();
        bloque->masterBlock->actualBloqueTabla = tmp->numeroBloque;
        bloque->masterBlock->escribir();
        bTablasList.push_back(tmp);

    }

    void CrearCampo(char nombreCampo[20],int id,int tipo, AdminBloque* manejador)
    {
        Tablas* tablas = BuscarTabla(id);
        if(tablas!=0)
        {
            tablas->crearCampo(manejador,nombreCampo,tipo);
            BloqueTablas* bt = BuscarBloqueTabla(tablas->numeroBloque);
            bt->escribir();
        }
    }

    Tablas* BuscarTabla(int ID)
    {
        for (std::list<BloqueTablas*>::iterator x = bTablasList.begin(); x!= bTablasList.end(); x++ ){
            BloqueTablas* tmp = *x;
            for (std::list<Tablas*>::iterator c = tmp->listaTablas.begin(); c!=tmp->listaTablas.end(); c++)
            {
                Tablas* temp = *c;
                if (temp->ID == ID)
                    return temp;
            }
        }
    }

    BloqueTablas* BuscarBloqueTabla(int n)
    {
        for(std::list<BloqueTablas*>::iterator c = bTablasList.begin(); c!=bTablasList.end(); c++)
        {
            BloqueTablas* bt= *c;
            if(bt->numeroBloque == n)
                return bt;
        }
        return 0;
    }

    void ListarTablas(std::list<BloqueTablas*> bt)
    {
        for (std::list<BloqueTablas*>::iterator i = bt.begin(); i!=bt.end(); i++) {
            BloqueTablas* bt = *i;
            for (std::list<Tablas *>::iterator c = bt->listaTablas.begin(); c != bt->listaTablas.end(); c++) {
                Tablas *tmp = *c;
                printf(tmp->nombre);
            }
        }
    }

    void ListarTablas()
    {
        ListarTablas(bTablasList);
    }


    void loadBloqueTabla()
    {
        int actual = 0;
        BloqueTablas* bloque= new BloqueTablas(file,actual);
        bloque->cargar();
        bTablasList.push_back(bloque);
        while(bloque->siguiente !=-1)
        {
            actual=bloque->siguiente;
            bloque= new BloqueTablas(file,actual);
            bloque->cargar();
            bTablasList.push_back(bloque);
        }
    }

    void AddRegistro(int ID, AdminBloque* adblock, Registros* reg)
    {
        Tablas* tablas = BuscarTabla(ID);
        if (tablas!=0)
        {
            tablas->CrearRegistro(adblock,reg);
            BloqueTablas* tmp = BuscarBloqueTabla(tablas->numeroBloque);
            tmp->escribir();
        }
    }

};

#endif //SISTEMAARCHIVOS_ADMINTABLAS_H
