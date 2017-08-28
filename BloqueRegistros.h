//
// Created by alejandro on 07-26-17.
//

#ifndef SISTEMAARCHIVOS_BLOQUEREGISTROS_H
#define SISTEMAARCHIVOS_BLOQUEREGISTROS_H

#include "Bloques.h"

class Registros {
    public:
        int length;
        std::list<CampoDatos*> campDatosList;
        Registros(int l)
        {
            length = l;
        }

        Registros() {}
    char* ToChar()
    {
        char* data = new char[length];
        int pos=0;
        for (std::list<CampoDatos*>::iterator c = campDatosList.begin(); c!=campDatosList.end(); c++)
        {
            CampoDatos* tmp = *c;
            char* entry =  tmp->ToChar();
            memcpy(&data[pos],&entry,20);
            pos+=20;
        }
        return data;
    }

    void ToRegistro(char* data)
    {
        int pos = 0;
        for (int c=0; c<length/20; c++)
        {
            CampoDatos* tmp = new CampoDatos("",0);
            tmp->ToCampoDatos(&data[pos]);
            pos+=20;
        }
    }

};

class BloqueRegistros : public Bloques
{
public:
    std::list<Registros*> listRegistros;
    int cantReg;

    BloqueRegistros(DataFile* fil,int nb) : Bloques(file, nb) {
        BloqueRegistros::numeroBloque = nb;
        BloqueRegistros::siguiente = -1;
        cantReg=0;
        file = fil;
    }

  /*  int getLengthRegistros()
    {
        int sum = 0;
        Registros* reg = new Registros();
        for (int c=0; c<reg->length; c++)
            sum+=1;
    }*/
    char* ToChar()
    {
        int size = listRegistros.size();
        char* data = new char[(size*20)+12];
        int pos=0;
        memcpy(&data[pos],&numeroBloque,4);
        pos+=4;
        memcpy(&data[pos],&siguiente,4);
        pos+=4;
        memcpy(&data[pos],&cantReg,4);
        pos+=4;
        for (std::list<Registros*>::iterator c = listRegistros.begin(); c!=listRegistros.end(); c++)
        {
            Registros* tmp = *c;
            char* entry = tmp->ToChar();
            memcpy(&data[pos],&entry,20);
            pos+=20;
        }
        return data;
    }

    void ToRegistros(char* data)
    {
        int pos=0;
        memcpy(&numeroBloque,&data[pos],4);
        pos+=4;
        memcpy(&siguiente,&data[pos],4);
        pos+=4;
        memcpy(&cantReg,&data[pos],4);
        pos+=4;
        for (int c=0; c<cantReg; c++)
        {
            Registros* tmp = new Registros();
            tmp->ToRegistro(&data[pos]);
            listRegistros.push_back(tmp);
            pos+=20;
        }
    }

    void escribir()
    {
        file->abrir();
        char * data= this->ToChar();
        int pos= numeroBloque * sizeBloque+20;
        file->escribir(data,pos,sizeBloque);
        file->cerrar();
    }

    void cargar()
    {

        file->abrir();
        int pos= numeroBloque *sizeBloque+20;
        char* data = file->leer(pos,sizeBloque);
        ToRegistros(data);
        file->cerrar();
    }

private:
    DataFile* file;

};


#endif //SISTEMAARCHIVOS_BLOQUEREGISTROS_H
