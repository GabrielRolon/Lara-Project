#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
#include <cstdio>
#include "entrenamiento.h"
#include "strUsuario.h"

const char *FILEENTRENAMIENTO = "datos/archEntrenamiento.dat";

Entrenamiento cargarEntrenamiento(){
    Entrenamiento reg;
    //id autonumerico
    cout << "Ingresar ID de Usuario: " << endl;
    cin >> reg.idUsuario;
    while(buscarUsuario(reg.idUsuario) == -1){
        cout << "Ingresar un ID valido"<< endl;
        cin >> reg.idUsuario;
    }
    //validar idUsuario
    cout << "Ingresar fecha de entrenamiento: " << endl;
    reg.diEntrenamiento = cargarFechaEn();
    cout << "Ingresar Actividad: " << endl;
    cout << "1 - Caminata, 2 - Correr, 3 - Bicicleta, 4 - Natación y 5 - Pesas" << endl;
    cin >> reg.actividad;
    //validar actividad numero entre 1 y 5 y apto medico aprobado
    cout << "Ingresar calorias: " << endl;
    cin >> reg.calorias;
    cout << "Ingresar tiempo en minutos: " << endl;
    cin >> reg.tiempo;

    return reg;
}

FechaEn cargarFechaEn(){
    time_t tiempo;
    struct tm *tmPtr;
    int Diasenmeses[12]={31,28,31,30,30,30,31,31,30,31,30,31};


    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int diaActual = tmPtr->tm_mday;
    int mesActual = tmPtr->tm_mon+1;
    int anioActual = 1900+tmPtr->tm_year;
    int edadDias;

    FechaEn reg;
    cout << endl;
    cout << "Dia: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "Año: ";
    cin >> reg.anio;

    while (reg.anio<0||reg.anio>((anioActual))){
    cout << "Fecha invalida, ingresar un año correcto" << endl;
    cout << endl;
    cout << "Año: ";
    cin >> reg.anio;
    }

    if((reg.anio%4)==0){
    Diasenmeses[1]=29;
    }

    while(reg.mes>12||reg.mes<0){
    cout << "Fecha invalida, ingresar un mes correcto" << endl;
    cout << endl;
    cout << "Mes: ";
    cin >> reg.mes;
    }


    while(reg.dia>Diasenmeses[reg.mes]){
    cout << "Fecha invalida, ingresar un día correcto" << endl;
    cout << endl;
    cout << "Día: ";
    cin >> reg.dia;
    }


    return reg;
}

/// CREA archEntrenamiento.dat que permite almacenar los datos
bool guardarEntren(Entrenamiento reg){
    bool guardo;
    FILE *f = fopen(FILEENTRENAMIENTO, "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return guardo;
}

