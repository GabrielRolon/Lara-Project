#include <iostream>

using namespace std;
#include "funciones.h"
#include "strUsuario.h"

int main(){

    Usuario user;
    user = cargarDatos();
    mostrarDatos(user);

    return 0;
}
/*
void menu(opcion){

         int opcion;
         while(true){
             switch(opcion){
         case 1:
             break;         case 2:
             break;         case 3:
             break;         case 4:
             break;         case 0: return 0;
             break;
             }
         }


};
*/
