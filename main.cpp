#include <iostream>
#include "Bloques.h"
#include "DataFile.h"
#include "BloqueTablas.h"
#include "MasterBlock.h"
#include "AdminTablas.h"

int main() {
    //DataFile *dat = new DataFile("/home/alejandro/Documentos/hola.tp");
    //dat->crear();
/*    Bloques* block = new Bloques(0,1, "/home/alejandro/Documentos/hola.tp");//creo un nuevo bloque y de paso se crea el archivo
    block->escribir();// en el archivo guardo que numero=0, tamano = 512 y que sig= -1
    block->siguiente = 73;//aqui modifico el sig=-1 y lo cambio por sig = 73 (EN LA RAM)
    block->cargar();//voy a modificar todos los atributos por los mismos atributos que estaban en el disco duro
   std::cout << "siguiente de block: " << block->siguiente << std::endl;*/
    //DataFile* dat = new DataFile("/home/alejandro/Documentos/hola.tp");
    DataFile* file = new DataFile("/home/alejandro/Documentos/ED2/SistemaArchivos/probando.tp");
    file->crear();
    file->isEmpty();
    file->abrir();
    AdminBloque* adBlock = new AdminBloque(file);
    AdminTablas* adTablas = new AdminTablas(file,adBlock->masterBlock);

    for(int c=0;c<100;c++)
    {
        char* nom= new char[20];
        nom[0] = 'B';
        nom[1] = 'A';
        nom[2] = 'C';
        nom[3] = 'A';
        nom[4] = 'A';
        nom[5] = 'S';

        char cadena[100];
        sprintf(cadena, "%d", c);
        for(int x=0;cadena[x]!='\0';x++)
        {
            nom[x+6]=cadena[x];
        }

        adTablas->CrearTablas(nom,adBlock,c);
        int tipo=0;
        for(int i=0;i<10;i++)
        {
            char* nombreC = new char[20];
            nombreC[0] = 'A';
            nombreC[1] = 'C';
            nombreC[2] = 'O';
            nombreC[3] = 'H';
            nombreC[5] = 'S';
            nombreC[6] = 'A';
            char cadena1[10];
            sprintf(cadena1, "%d", i);
            for(int x=0;cadena1[x]!='\0';x++)
            {
                nombreC[x+6]=cadena1[x];
            }
            if(i==4)
                tipo=1;
            if(i==9)
                tipo=1;
            adTablas->CrearCampo(&nombreC,c,tipo,adBlock);
            tipo=0;
        }
    }



    return 0;
}