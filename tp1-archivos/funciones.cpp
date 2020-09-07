#include <iostream>

using namespace std;
#include <cstdio>
#include "funciones.h"
#include "strUsuario.h"

///Funciones generales

void menuPrincipal(){
    cout << "MENU PRINCIPAL" << endl;
    cout << "--------------" << endl;
    cout << "1) USUARIOS" << endl;
    cout << "2) ENTRENAMIENTOS" << endl;
    cout << "3) REPORTES" << endl;
    cout << "4) CONFIGURACION" << endl;
    cout << "5) Copia de seguridad del archivo.dat antes de cada ejecucion" << endl;
    cout << "--------------" << endl;
    cout << "0) SALIR DEL PROGRAMA" << endl;

    int opcion;
    cin >> opcion;
    switch(opcion){
        case 1:
            menuUsuarios();
        break;
        case 2:
            //menuEntrenamiento();
        break;
        case 3:
            //menuReportes();
        break;
        case 4:
            //menuConfiguracion();
        break;
        case 5:
            backupArchivo();
        break;
        case 0:
            //CerrarPrograma();
        break;
    }
}

void menuUsuarios(){
    system("cls");
    cout << "MENU USUARIOS" << endl;
    cout << "--------------" << endl;
    cout << "1) NUEVO USUARIO" << endl;
    cout << "2) MODIFICAR USUARIO" << endl;
    cout << "3) LISTAR USUARIO POR ID" << endl;
    cout << "4) LISTAR TODOS LOS USUARIOS" << endl;
    cout << "5) ELIMINAR USUARIO" << endl;
    cout << "--------------" << endl;
    cout << "0) VOLVER AL MENU PRINCIPAL" << endl;

    int opcion;
    cin >> opcion;

    switch(opcion){
        case 1:
           guardarUsuario(cargarDatos());
        break;
        case 2:
            modificarUser();
        break;
        case 3:
            listarPorId();
        break;
        case 4:
            listarUsuarios();
        break;
        case 5:
            //menuUsuarios();
        break;
        case 0:
            //menuUsuarios();
        break;
    }
}



