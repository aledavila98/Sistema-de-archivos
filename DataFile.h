//
// Created by alejandro on 07-24-17.
//

#ifndef SISTEMAARCHIVOS_DATAFILE_H
#define SISTEMAARCHIVOS_DATAFILE_H

#include <stdio.h>

class DataFile{

    public:
        DataFile(){}
        DataFile(char* toPath){
            path = toPath;
        }
        FILE* archivo;

        void abrir()
        {
            archivo = fopen(path,"r+");
        }

        void crear()
        {
            archivo = fopen(path,"w");
            cerrar();
        }

        void cerrar(){
            fclose(archivo);
        }

        void escribir(char* data, int pos, int longi){
            fseek(archivo,pos, SEEK_SET);
            fwrite(data, sizeof(char), longi,archivo);
        }

        char* leer(int pos, int longi){
            char* m = new char[longi];
            fread(m, sizeof(char),longi,archivo);
            return m;
        }

        bool isEmpty()
        {
            fseek(archivo,0,SEEK_END);
            return ftell(archivo)<=0;
        }

    private:
        char* path;
};

#endif //SISTEMAARCHIVOS_DATAFILE_H
