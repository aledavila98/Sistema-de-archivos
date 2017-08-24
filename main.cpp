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
    DataFile* file = new DataFile("/home/alejandro/Documentos/ED2/SistemaArchivos/prueba.pe");
    file->crear();
    file->isEmpty();
    file->abrir();
    AdminBloque* adminBloque = new AdminBloque(file);
    AdminTablas* adminTablas = new AdminTablas(file,adminBloque->masterBlock);
    for(int c=0;c<=15;c++) {
        char *nombre = new char[20];
        nombre[0] = 't';
        nombre[1] = 'A';
        nombre[2] = 'b';
        nombre[3] = 'l';
        nombre[4] = 'A';
        nombre[5] = 'S';

        char cadena[15];
          sprintf(cadena, "%d", c);
          for (int x = 0; cadena[x] != '\0'; x++) {
              nombre[x + 6] = cadena[x];
          }

        adminTablas->CrearTablas(nombre, adminBloque, c);
    }

    adminTablas->loadBloqueTabla();
    adminTablas->ListarTablas(adminTablas->bTablasList);
   /* std::list<BloqueTablas*>::iterator it = adTablas->bTablasList.begin();
    std::advance(it,1);
    BloqueTablas* bt = *it;
 //   bt->cargar();
    std::cout<<bt->numeroBloque;
*//*
  for(int c=0;c<15;c++)
    {
        char* nombre= new char[20];
        nombre[0] = 't';
        nombre[1] = 'A';
        nombre[2] = 'b';
        nombre[3] = 'l';
        nombre[4] = 'A';
        nombre[5] = 'S';

        char cadena[15];
        sprintf(cadena, "%d", c);
        for(int x=0;cadena[x]!='\0';x++)
        {
            nombre[x+6]=cadena[x];
        }

        adTablas->CrearTablas(nombre,adBlock,c);
        int tipo=0;
        /*for(int i=0;i<10;i++)
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
        }//*/



 //   }




    return 0;
}