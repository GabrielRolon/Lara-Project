#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
#include <cstdio>
#include "funciones.h"
#include "strUsuario.h"
#include "ui.h"

///Funciones generales

void menuPrincipal(){
    system("cls");
    cout << "MENU PRINCIPAL" << endl;
    cout << "--------------" << endl;
    cout << "1) USUARIOS" << endl;
    cout << "2) ENTRENAMIENTOS" << endl;
    cout << "3) REPORTES" << endl;
    cout << "4) CONFIGURACION" << endl;
    cout << "5) Copia de seguridad del archivo.dat antes de cada ejecucion" << endl;
    cout << "--------------" << endl;
    cout << "0) SALIR DEL PROGRAMA" << endl << endl;

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
            system("cls");
            break;
    }
}

void menuUsuarios(){
    system("cls");
    //title("MENU USUARIOS");; cout << endl;
    cout << "MENU USUARIOS" << endl;
    cout << "--------------" << endl;
    cout << "1) NUEVO USUARIO" << endl;
    cout << "2) MODIFICAR USUARIO" << endl;
    cout << "3) LISTAR USUARIO POR ID" << endl;
    cout << "4) LISTAR TODOS LOS USUARIOS" << endl;
    cout << "5) ELIMINAR USUARIO" << endl;
    cout << "--------------" << endl;
    cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;

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
            eliminarUser();
        break;
        case 0:
            menuPrincipal();
        break;
    }
    menuUsuarios();
}

///Funciones de verificacion de datos

///Funcion para validar nombre
void validarNombre(char nombre[50]){
    fflush(stdin);
    cout<<"Ingresar nombre: ";
    cin.getline(nombre,50);
    while(strlen(nombre)==0 ){
        cout<<"ERROR - El nombre no puede ir vac�o - Intente nuevamente: ";
        cin.getline(nombre,50);
    }
}

///Funcion para validar apellido
void validarApellido(char apellido[50]){
    fflush(stdin);
    cout<<"Ingresar apellido: ";
    cin.getline(apellido,50);
    while(strlen(apellido)==0 ){
        cout<<"ERROR - El apellido no puede ir vac�o - Intente nuevamente: ";
        cin.getline(apellido,50);
    }
}

///Funcion para validar altura
void validarAltura(float altura){
    fflush(stdin);
    cout << "Ingrese la altura: ";
    cin >> altura;
    while(altura<0){
        cout<<"ERROR - La altura no puede ser un valor negativo: ";
        cin >> altura;
    }
}

///Funcion para validar altura
void validarPeso(float peso){
    fflush(stdin);
    cout << "Ingrese el peso: ";
    cin >> peso;
    while(peso<0){
        cout<<"ERROR - El peso no puede ser un valor negativo: ";
        cin >> peso;
    }
}

///Validar perfil de actividad
void validarPerfilA(char perfil){
    fflush(stdin);
    cout << "Ingrese el perfil de actividad (A-B-C): ";
    cin >> perfil;
    while(perfil!='A' && perfil!='B' && perfil!='C' && perfil!='a' && perfil!='b' && perfil!='c'){
        cout << "ERROR - El perfil solo puede ser A, B o C: ";
        cin >> perfil;
    }
}

///Validar apto medico
void validarAptoM(bool estado){
    fflush(stdin);
    cout << "Ingrese el estado del paciente (0 o 1): ";
    while(true){
        fflush(stdin);
        cin >> estado;
        if(estado == 1 || estado == 0){
            break;
        }else{
            cout << "ERROR - El estado solo puede ser 1 o 0: ";
        }
    }
}
