#include <iostream>
#include "Bloques.h"
#include "DataFile.h"
#include "BloqueTablas.h"
#include "MasterBlock.h"
#include "AdminTablas.h"
#include "JsonManager.h"

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
    DataFile* fil = new DataFile("/home/alejandro/Documentos/ED2/SistemaArchivos/prueba.json");
    JsonManager* json = new JsonManager();
    fil->crear();
    file->crear();
    file->isEmpty();
    file->abrir();
    AdminBloque* adminBloque = new AdminBloque(file);
    AdminTablas* adminTablas = new AdminTablas(file,adminBloque->masterBlock);

    /*char* nombre= new char[20];
    nombre[0] = 't';
    nombre[1] = 'A';
    nombre[2] = 'b';
    nombre[3] = 'l';
    nombre[4] = 'A';
    nombre[5] = 'S';
    Tablas* tablas = new Tablas(file,nombre,0,-1,-1,-1,-1,0);
    BloqueTablas* bt = new BloqueTablas(file,0);
    bt->listaTablas.push_back(tablas);
    bt->escribir();
    bt->cargar();
    std::list<Tablas*>::iterator c = bt->listaTablas.begin();
    std::advance(c,0);
    Tablas* tmp = *c;
    printf(tmp->nombre);
*/

   /* std::list<BloqueTablas*>::iterator it = adTablas->bTablasList.begin();
    std::advance(it,1);
    BloqueTablas* bt = *it;
 //   bt->cargar();
    std::cout<<bt->numeroBloque;
*/
  for(int c=0;c<100;c++)
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

        adminTablas->CrearTablas(nombre,adminBloque,c);
        int tipo=0;
        for(int i=0;i<10;i++)
        {
            char* nombreC = new char[20];
            nombreC[0] = 'c';
            nombreC[1] = 'a';
            nombreC[2] = 'm';
            nombreC[3] = 'p';
            nombreC[5] = 'o';
            char cadena1[15];
            sprintf(cadena1, "%d", i);
            for(int x=0;cadena1[x]!='\0';x++)
            {
                nombreC[x+6]=cadena1[x];
            }
            if(i==4)
                tipo=1;
            if(i==9)
                tipo=1;
            adminTablas->CrearCampo(nombreC,c,tipo,adminBloque);
            tipo=0;
        }
    }

   for(int c=0;c<10;c++)
    {

        Registros* r= new Registros(adminTablas->BuscarTabla(c)->GetLongitudRegistros());
        for(int i=0;i<10;i++)
        {
            char * datos= new char[20];
            datos[0]='d';
            datos[1]='a';
            datos[2]='t';
            datos[3]='o';
            datos[4]='_';

            char cadena2[10];
            sprintf(cadena2, "%d", c);
            for(int x=0;cadena2[x]!='\0';x++)
            {
                datos[x+5]=cadena2[x];
            }
            if(i==4 || i==9)
            {
                datos=new char[10];
                sprintf(datos, "%d", i);
            }
            std::list<Campos*>::iterator it = adminTablas->BuscarTabla(c)->listCampos.begin();
            std::advance(it,c);
            Campos* tmp = *it;
            CampoDatos * datosN=new CampoDatos(datos,tmp);
            r->campDatosList.push_back(datosN);

        }
        adminTablas->AddRegistro(c,adminBloque,r);
    }



    //adminTablas->loadBloqueTabla();
    adminTablas->ListarTablas();

    return 0;
}