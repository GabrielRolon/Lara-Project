#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
#include <cstdio>
#include <ctime>
#include "funciones.h"
#include "strUsuario.h"
#include "entrenamiento.h"
#include "ui.h"


///Funciones generales

void creditos()
{
    cout << "\t\t\tTrabajo pr�ctico 1, 2 y 3 de Laboratorio 2";
    cout << "\n\n\tAutores: ";
    cout << "\n\t\tMaximiliano Miranda";
    cout << "\n\t\tGabriel Rol�n";
    cout << "\n\t\tCristian Uhrig" << endl << endl;
    Sleep(8000);
}
void menuPrincipal(){
    bool menu = true;
    while(menu){
        system("cls");
        cout << "MENU PRINCIPAL" << endl;
        cout << "--------------" << endl;
        cout << "1) USUARIOS" << endl;
        cout << "2) ENTRENAMIENTOS" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACION" << endl;
        cout << "--------------" << endl;
        cout << "0) SALIR DEL PROGRAMA" << endl << endl;

        int opcion;
        cin >> opcion;
        switch(opcion){
            case 1:
                menuUsuarios();
            break;
            case 2:
                menuEntrenamientos();
            break;
            case 3:
                //menuReportes();
            break;
            case 4:
                menuConfiguracion();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}

void menuUsuarios(){
    bool menu = true;
    while(menu){
        system("cls");
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
                menu = false;
            break;
        }
    }
}

void menuEntrenamientos(){
    bool menu = true;
    while(menu){
        system("cls");
        //title("MENU ENTRENAMIENTOS");; cout << endl;
        cout << "MENU ENTRENAMIENTOS" << endl;
        cout << "--------------" << endl;
        cout << "1) NUEVO ENTRENAMIENTO" << endl;
        cout << "2) MODIFICAR ENTRENAMIENTO" << endl;
        cout << "3) LISTAR ENTRENAMIENTO POR ID" << endl;
        cout << "4) LISTAR ENTRENAMIENTO POR IDUSUARIO" << endl;
        cout << "5) LISTAR TODOS LOS ENTRENAMIENTOS" << endl;
        cout << "--------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;

        int opcion;
        cin >> opcion;

        switch(opcion){
            case 1:
               guardarEntren(cargarEntrenamiento());
            break;
            case 2:
                modificarEnt();
            break;
            case 3:
                listarPorIdEnt();
            break;
            case 4:
                //listarEnPorIdUsuario();
            break;
            case 5:
                listarEnTodos();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}
void menuConfiguracion(){
    bool menu = true;
    while(menu){
        system("cls");
        cout << "MENU CONFIGURACI�N" << endl;
        cout << "--------------" << endl;
        cout << "1) REALIZAR COPIA DE SEGURIDAD" << endl;
        cout << "2) RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << "--------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        int opcion;
        cin >> opcion;

        switch(opcion){
            case 1:
               copiaDeSeguridad();
            break;
            case 2:
                restaurarCopia();
            break;
            case 0:
                menu = false;
            break;
        }
    }
}
///Funciones de verificacion de datos

///Funcion para validar nombre
void validarNombre(char nombre[50]){
    fflush(stdin);
    cout << "Ingresar Nombre: ";
    cin.getline (nombre,50);
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
float validarAltura(){
    fflush(stdin);
    float altura;
    cout << "Ingrese la altura: ";
    cin >> altura;
    while(altura<0){
        cout<<"ERROR - La altura no puede ser un valor negativo: ";
        cin >> altura;
    }
    return altura;
}

///Funcion para validar peso
float validarPeso(){
    fflush(stdin);
    float peso;
    cout << "Ingrese el peso: ";
    cin >> peso;
    while(peso<0){
        cout<<"ERROR - El peso no puede ser un valor negativo: ";
        cin >> peso;
    }
    return peso;
}

///Validar perfil de actividad
char validarPerfilA(){
    fflush(stdin);
    char perfil;
    cout << "Ingrese el perfil de actividad (A-B-C): ";
    cin >> perfil;
    while(perfil!='A' && perfil!='B' && perfil!='C' && perfil!='a' && perfil!='b' && perfil!='c'){
        cout << "ERROR - El perfil solo puede ser A, B o C: ";
        cin >> perfil;
    }
    return perfil;
}

///Validar apto medico
bool validarAptoM(){
    fflush(stdin);
    bool estado;
    cout << "Ingrese Apto M�dico (0 o 1): ";
    while(true){
        fflush(stdin);
        cin >> estado;
        if(estado == 1 || estado == 0){
            break;
        }else{
            cout << "ERROR - El estado solo puede ser 1 o 0: ";
        }
    }
    return estado;
}
/* void verificarFecha(int dia, int mes, int anio){
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
    int edadmin = 13;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int diaActual = tmPtr->tm_mday;
    int mesActual = tmPtr->tm_mon+1;
    int anioActual = 1900+tmPtr->tm_year;
    int edadDias;

    edadDias = ((anioActual - anio)*(365.242189))+((diaActual - dia)+((mesActual - mes)*(365.242189/12)));
    while(edadDias+1 < 4749){
        cout << "Fecha invalida, ingresar una fecha correcta (edad minima 13 a�os)" << endl;
        cout << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "A�o: ";
        cin >> anio;
        edadDias = ((anioActual - anio)*(365.242189))+((diaActual - dia)+((mesActual - mes)*(365.242189/12)));
    }
}
*/
 void verificarFecha(int dia, int mes, int anio){
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
    int edadmin = 13;
    int Diasenmeses[12]={31,28,31,30,30,30,31,31,30,31,30,31};


    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int diaActual = tmPtr->tm_mday;
    int mesActual = tmPtr->tm_mon+1;
    int anioActual = 1900+tmPtr->tm_year;
    int edadDias;

//    while (anio<0||anio>anioActual){
//        cout << "Fecha invalida, ingresar un a�o correcto" << endl;
//        cout << endl;
//        cout << "A�o: ";
//        cin >> anio;
//    }
//
//    if((anio%4)==0){
//        Diasenmeses[1]=29;
//    }
//
//
//    while(mes>12||mes<0){
//        cout << "Fecha invalida, ingresar un mes correcto" << endl;
//        cout << endl;
//        cout << "Mes: ";
//        cin >> mes;
//    }
//
//
//    while(dia>Diasenmeses[mes]){
//        cout << "Fecha invalida, ingresar un d�a correcto" << endl;
//        cout << endl;
//        cout << "D�a: ";
//        cin >> dia;
//    }



    edadDias = ((anioActual - anio)*(365.242189))+((diaActual - dia)+((mesActual - mes)*(365.242189/12)));
    while(edadDias+1 < 4749){
        cout << "Fecha invalida, ingresar una fecha correcta (edad minima 13 a�os)" << endl;
        cout << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "A�o: ";
        cin >> anio;
        edadDias = ((anioActual - anio)*(365.242189))+((diaActual - dia)+((mesActual - mes)*(365.242189/12)));
    }
}
