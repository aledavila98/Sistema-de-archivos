#include <iostream>
#include "Bloques.h"
#include "DataFile.h"
#include "BloqueTablas.h"
#include "MasterBlock.h"

int main() {
    //DataFile *dat = new DataFile("/home/alejandro/Documentos/hola.tp");
    //dat->crear();
/*    Bloques* block = new Bloques(0,1, "/home/alejandro/Documentos/hola.tp");//creo un nuevo bloque y de paso se crea el archivo
    block->escribir();// en el archivo guardo que numero=0, tamano = 512 y que sig= -1
    block->siguiente = 73;//aqui modifico el sig=-1 y lo cambio por sig = 73 (EN LA RAM)
    block->cargar();//voy a modificar todos los atributos por los mismos atributos que estaban en el disco duro
   std::cout << "siguiente de block: " << block->siguiente << std::endl;*/
    //DataFile* dat = new DataFile("/home/alejandro/Documentos/hola.tp");
    DataFile* file = new DataFile("/home/alejandro/Documentos/hola.tp");
    MasterBlock* mb = new MasterBlock(file,-1,-1,-1);




    return 0;
}