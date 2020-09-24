#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
#include <cstdio>
#include "funciones.h"
#include "strUsuario.h"
#include "entrenamiento.h"

const char *FILEUSUARIOS = "datos/archUsuarios.dat";

Usuario cargarDatos(){
    system("cls");
    Usuario user;
    cout<<"Ingresar ID: ";
    cin>>user.id;
    while(buscarUsuario(user.id) >= 0){
        cout << "ID existente, reingresar: ";
        cin >> user.id;
    }
    validarNombre(user.nombre);

    validarApellido(user.apellido);

    user.nacimiento = cargarFecha();

    user.altura = validarAltura();

    user.peso = validarPeso();

    user.actividad = validarPerfilA();

    user.aptoMedico = validarAptoM();

    user.estado = true;

    return user;
}

void mostrarDatos(Usuario reg){
    cout << endl;
    cout << "----------" << endl;
    cout << "ID: " << reg.id << endl;
    cout << "Nombre: " << reg.nombre << endl;
    cout << "Apellido: " << reg.apellido << endl;
    cout << "Fecha: " << reg.nacimiento.dia << " / " << reg.nacimiento.mes << " / " << reg.nacimiento.anio << endl;
    cout << "Altura: " << reg.altura << endl;
    cout << "Peso: " << reg.peso << " Kg" << endl;
    cout << "Perfil de Actividad: " << reg.actividad << endl;
    if(reg.aptoMedico){
        cout << "Apto Medico: Aprobado"<< endl;
    } else {
        cout << "Apto Medico: No Aprobado"<< endl;
    }
}

Fecha cargarFecha(){
    time_t tiempo;
    struct tm *tmPtr;
    int edadmin = 13;
    int Diasenmeses[12]={31,28,31,30,30,30,31,31,30,31,30,31};


    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int diaActual = tmPtr->tm_mday;
    int mesActual = tmPtr->tm_mon+1;
    int anioActual = 1900+tmPtr->tm_year;
    int edadDias;

    Fecha reg;
    cout<<endl<<"ingresar fecha de nacimiento: ";
    cout << endl;
    cout << "Dia: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "Año: ";
    cin >> reg.anio;

    while (reg.anio<0||reg.anio>((anioActual)-13)){
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
/// Busca la posicion del usuario
int buscarUsuario(int id){
    int pos=0;
    Usuario user;
    FILE *f = fopen(FILEUSUARIOS, "rb");
    if(f == NULL){
        cout << "No se puede leer el archivo.dat .";
        return -1;
    }
    while(fread(&user, sizeof(Usuario), 1, f)){
        if(id == user.id){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}
/// CREA archivo.dat que permite almacenar los datos
bool guardarUsuario(Usuario user){
    bool guardo;
    FILE *f = fopen(FILEUSUARIOS, "ab");
    if(f == NULL){
        cout << "No se puede guardar.";
        return false;
    }
    guardo = fwrite(&user, sizeof(Usuario), 1, f);
    fclose(f);
    return guardo;
}

/// LEE el archivo.dat todos los usuarios
void listarUsuarios(){
    system("cls");
    int cant = cantidadUsuarios();
    for(int i=0; i<cant; i++){
        Usuario user = leerUser(i);
        if(user.estado){
            mostrarDatos(user);
        }
    }
    cout << endl << endl;
    system("pause");
    menuUsuarios();
}
int cantidadUsuarios(){
    FILE *f = fopen(FILEUSUARIOS, "rb");
    if(f == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(f, 0, SEEK_END);
    bytes = ftell(f);
    fclose(f);
    cant = bytes / sizeof(Usuario);
    return cant;
}

Usuario leerUser(int pos){
    Usuario user;
    FILE *f = fopen(FILEUSUARIOS, "rb");
    if(f == NULL){
        user.id = 0;
        return user;
    }
    fseek(f, pos *sizeof(Usuario), SEEK_SET);
    fread(&user, sizeof(Usuario), 1, f);
    fclose(f);
}
void listarPorId(){
    system("cls");
    int codigo, pos;
    cout << "Ingresar ID a buscar: ";
    cin >> codigo;
    pos = buscarUsuario(codigo);
    if(pos >= 0){
        Usuario user;
        user = leerUser(pos);
        mostrarDatos(user); //alternativa tambien funciona: mostrarDatos(leerUser(pos));
    } else {
        cout << "\nCodigo inexistente" << endl;
    }
    cout << endl << endl;
    system("pause");
}
void modificarUser(){
    system("cls");
    int codigo, pos, opc;
    cout << "Ingresar ID a buscar: ";
    cin >> codigo;
    pos = buscarUsuario(codigo);
    if(pos >= 0){
        cout << "\nUsuario a modificar: " << endl;
        cout << "---------------------" << endl;
        Usuario user = leerUser(pos);
        mostrarDatos(user);
        cout << endl;
        cout << "Ingresar opcion a modificar: " << endl;
        cout << "1) Peso" << endl;
        cout << "2) Actividad" << endl;
        cout << "3) Apto medico" << endl;
        cin >> opc;
        switch(opc){
            case 1:
                cout << "Nuevo Peso" << endl;
                user.peso = validarPeso();
            break;
            case 2:
                cout << "Nueva Actividad" << endl;
                user.actividad = validarPerfilA();
            break;
            case 3:
                cout << "Nuevo Apto medico" << endl;
                user.aptoMedico = validarAptoM;
            break;
        }
        guardarModificacion(user, pos);

    } else {
        cout << "No existe Usuario" << endl;
    }
}
bool eliminarUser(){
    system("cls");
    int codigo, pos;
    char opc[2];
    cout << "Ingresar ID a buscar para eliminar: ";
    cin >> codigo;
    pos = buscarUsuario(codigo);
    if(pos >= 0){
        cout << "\nUsuario a eliminar: " << endl;
        cout << "---------------------" << endl;
        Usuario user = leerUser(pos);
        mostrarDatos(user);
        cout << endl;
        cout << "Ingresar opcion a modificar: " << endl;
        cout << "Eliminar user? (Si / No)" << endl;
        cin >> opc;
        if(opc == "Si"){
            user.estado = false;
        } else {
            user.estado = true;
        }
        guardarModificacion(user, pos);

    } else {
        cout << "No existe Usuario" << endl;
        return false;
    }
    system("pause");
    menuUsuarios();
}
bool guardarModificacion(Usuario user, int pos){
    bool guardo;
    FILE *f = fopen(FILEUSUARIOS, "rb+");
    if(f == NULL){
        cout << "No se puede modificar.";
        return false;
    }
    fseek(f, pos *sizeof(Usuario), SEEK_SET);
    guardo = fwrite(&user, sizeof(Usuario), 1, f);
    fclose(f);
    return guardo;
}


/// BACKUP DE ARCHIVO.DAT
void copiaDeSeguridad(){
    Usuario user;
    FILE *f = fopen(FILEUSUARIOS, "rb");
    FILE *backup = fopen("datos/archUsuariosBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(backup);
    if(f == NULL){
        cout << "No se puede leer el archivo.dat .";
    }
    while(fread(&user, sizeof(Usuario), 1, f)){
        FILE *bk = fopen("datos/archUsuariosBK.dat", "ab");
        if(bk == NULL){
            cout << "No se puede guardar.";
        }
        fwrite(&user, sizeof(Usuario), 1, bk);
        fclose(bk);
    }
    fclose(f);
    cout << "Se CREO copia de seguridad USUARIO.DAT" << endl;
    system("pause");

    //COPIA DE ENTRENAMIENTO.DAT
    Entrenamiento reg;
    FILE *e = fopen("datos/archEntrenamiento.dat", "rb");
    FILE *Entbk = fopen("datos/archEntrenamientoBK.dat", "wb"); //Seteo a 0 el archivo de bk
    fclose(Entbk);
    if(e == NULL){
        cout << "No se puede leer el archivo.dat .";
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, e)){
        FILE *Ebk = fopen("datos/archEntrenamientoBK.dat", "ab");
        if(Ebk == NULL){
            cout << "No se puede guardar.";
        }
        fwrite(&reg, sizeof(Entrenamiento), 1, Ebk);
        fclose(Ebk);
    }
    fclose(e);
    cout << "Se CREO copia de seguridad Entrenamiento BK" << endl;
    system("pause");
}

void restaurarCopia(){
    Usuario user;
    FILE *bk = fopen("datos/archUsuariosBK.dat", "rb");
    FILE *orig = fopen(FILEUSUARIOS, "wb"); //Seteo a 0 el archivo original
    fclose(orig);
    if(bk == NULL){
        cout << "No se puede leer el archivo.dat .";
    }
    while(fread(&user, sizeof(Usuario), 1, bk)){
        FILE *f = fopen(FILEUSUARIOS, "ab");
        if(f == NULL){
            cout << "No se puede guardar.";
        }
        fwrite(&user, sizeof(Usuario), 1, f);
        fclose(f);
    }
    fclose(bk);
    cout << endl;
    cout << "Se RESTAURO copia de seguridad usuario.dat" << endl;
    system("pause");

    //RESTAURA DE ENTRENAMIENTOBK.DAT a original
    Entrenamiento reg;
    FILE *e = fopen("datos/archEntrenamientoBK.dat", "rb");
    FILE *Entorig = fopen("datos/archEntrenamiento.dat", "wb"); //Seteo a 0 el archivo original
    fclose(Entorig);
    if(e == NULL){
        cout << "No se puede leer el Entrenamiento.dat .";
    }
    while(fread(&reg, sizeof(Entrenamiento), 1, e)){
        FILE *EnOriginal = fopen("datos/archEntrenamiento.dat", "ab");
        if(EnOriginal == NULL){
            cout << "No se puede guardar.";
        }
        fwrite(&reg, sizeof(Entrenamiento), 1, EnOriginal);
        fclose(EnOriginal);
    }
    fclose(e);
    cout << endl;
    cout << "Se RESTAURO copia de seguridad Entrenamiento.dat" << endl;
    system("pause");
}
