#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
#include <cstdio>
#include "entrenamiento.h"
#include "strUsuario.h"

const char *FILEENTRENAMIENTO = "datos/archEntrenamiento.dat";

Entrenamiento cargarEntrenamiento(){
    system("cls");
    Entrenamiento reg;
    reg.id = cantidadEntren()+1;
    cout << "Su ID es: " << reg.id << endl;
    cout << "Ingresar ID de Usuario: ";
    cin >> reg.idUsuario;
    while(buscarUsuario(reg.idUsuario) == -1){
        cout << "Ingresar un ID valido";
        cin >> reg.idUsuario;
    }
    cout << "Ingresar fecha de entrenamiento: ";
    reg.diEntrenamiento = cargarFechaEn();

    reg.actividad = validarAct();

    reg.calorias = validarCalorias();

    reg.tiempo = validarMin();

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
void mostrarEnt(Entrenamiento reg){
    cout << endl;
    cout << "----------" << endl;
    cout << "ID: " << reg.id << endl;
    cout << "ID Usuario: " << reg.idUsuario << endl;
    cout << "Fecha de Entrenamiento: " << reg.diEntrenamiento.dia << " / " << reg.diEntrenamiento.mes << " / " << reg.diEntrenamiento.anio << endl;
    switch(reg.actividad){
        case 1: cout << "Actividad: Caminata" << endl;
        break;
        case 2: cout << "Actividad: Correr" << endl;
        break;
        case 3: cout << "Actividad: Bicicleta" << endl;
        break;
        case 4: cout << "Actividad: Natacion" << endl;
        break;
        case 5: cout << "Actividad: Pesas" << endl;
        break;
    }
    cout << "Calorias: " << reg.calorias << endl;
    cout << "Tiempo: " << reg.tiempo << " Min" << endl;
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
// Devuelve la cantidad de registros
int cantidadEntren(){
    FILE *f = fopen(FILEENTRENAMIENTO, "rb");
    if(f == NULL){
        fclose(f);
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Entrenamiento);
    return cant;
}

///Funcion para validar calorias
float validarCalorias(){
    fflush(stdin);
    float calorias;
    cout << "Ingresar calorias: ";
    cin >> calorias;
    while(calorias<0){
        cout<<"ERROR - El peso no puede ser un valor negativo: ";
        cin >> calorias;
    }
    return calorias;
}
///Funcion para validar minutos
int validarMin(){
    fflush(stdin);
    int minutos;
    cout << "Ingresar tiempo en minutos: ";
    cin >> minutos;
    while(minutos<0){
        cout<<"ERROR - El peso no puede ser un valor negativo: ";
        cin >> minutos;
    }
    return minutos;
}

int validarAct(){
    int opc, mayor = 5, menor = 1;

    //validamos que el ingreso sea un entero y entre el 1 y el 5

    cout << "Ingresar Actividad 1 - Caminata, 2 - Correr, 3 - Bicicleta, 4 - Natación y 5 - Pesas: ";

    while(!(cin >> opc) || (opc < menor || opc > mayor)){
        //le indicamos el error al usuario
        cout << "\nError: Ingrese un numero del " << menor << " al " << mayor << " por favor: ";
        //limpiamos el ultimo ingreso
        cin.clear();
        //descartamos el ultimo ingreso
        cin.ignore(132, '\n');
    }
    return opc;
}

/// LEE el archivo.dat todos los entrenamientos
void listarEnTodos(){
    system("cls");
    int cant = cantidadEntren();
    for(int i=0; i<cant; i++){
        Entrenamiento reg = leerEntren(i);
        mostrarEnt(reg);
        //if(reg.estado){}
    }
    cout << endl << endl;
    system("pause");
}

Entrenamiento leerEntren(int pos){
    Entrenamiento reg;
    FILE *f = fopen(FILEENTRENAMIENTO, "rb");
    if(f == NULL){
        reg.id = 0;
        return reg;
    }
    fseek(f, pos *sizeof(Entrenamiento), SEEK_SET);
    fread(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
}

/// Busca la posicion del ID entrenamiento
int buscarEnt(int id){
    int pos=0;
    Entrenamiento reg;
    FILE *f = fopen(FILEENTRENAMIENTO, "rb");
    if(f == NULL){
        cout << "No se puede leer el archivo.dat .";
        return -1;
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, f)){
        if(id == reg.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}

void modificarEnt(){
    system("cls");
    int codigo, pos, opc;
    cout << "Ingresar ID de Entrenamiento a buscar: ";
    cin >> codigo;
    pos = buscarEnt(codigo);
    if(pos >= 0){
        cout << "\nEntrenamiento a modificar: " << endl;
        cout << "---------------------" << endl;
        Entrenamiento reg = leerEntren(pos);
        mostrarEnt(reg);
        cout << endl;
        cout << "Ingresar opcion a modificar: " << endl;
        cout << "1) Tiempo" << endl;
        cout << "2) Calorías" << endl;

        cin >> opc;
        switch(opc){
            case 1:
                cout << "Nuevo Tiempo" << endl;
                reg.tiempo = validarMin();
            break;
            case 2:
                cout << "Nueva Calorías" << endl;
                reg.calorias = validarCalorias();
            break;

        }
        guardarModificacionEnt(reg, pos);

    } else {
        cout << "No existe ID entrenamiento" << endl;
    }
}

bool guardarModificacionEnt(Entrenamiento reg, int pos){
    bool guardo;
    FILE *f = fopen(FILEENTRENAMIENTO, "rb+");
    if(f == NULL){
        cout << "No se puede modificar.";
        return false;
    }
    fseek(f, pos *sizeof(Entrenamiento), SEEK_SET);
    guardo = fwrite(&reg, sizeof(Entrenamiento), 1, f);
    fclose(f);
    return guardo;
}




