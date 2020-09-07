#include <iostream>

using namespace std;
#include <cstdio>
#include "funciones.h"
#include "strUsuario.h"

const char *FILEUSUARIOS = "datos/archUsuarios.dat";

Usuario cargarDatos(){
    Usuario user;
    cout<<"Ingresar ID: ";
    cin>>user.id;
    while(buscarUsuario(user.id) >= 0){
        cout << "ID ya existe, reingresar: ";
        cin >> user.id;
    }

    cout<<endl<<"ingresar nombre/s: ";
    cin.ignore();
    cin.getline(user.nombre,50);

    cout<<endl<<"Ingresar Apellido/s: ";
    cin.ignore();
    cin.getline(user.apellido,50);

    cout<<endl<<"ingresar fecha de nacimiento: ";
    user.nacimiento = cargarFecha();

    cout<<endl<<"ingresar Altura: ";
    cin>>user.altura;

    cout<<endl<<"ingresar peso: ";
    cin>>user.peso;

    cout<<endl<<"ingresar perfil de actividad: ";
    cin>>user.actividad;

    cout<<endl<<"ingresar si est� apto el paciente: ";
    cin>>user.aptoMedico;

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
    cout << "Peso: " << reg.peso << endl;
}

Fecha cargarFecha(){
    Fecha reg;
    cout << endl;
    cout << "Dia: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "Anio: ";
    cin >> reg.anio;
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
    int cant = cantidadUsuarios();
    for(int i=0; i<cant; i++){
        Usuario user = leerUser(i);
        mostrarDatos(user);
    }
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
    int codigo, pos;
    cout << "Ingresar ID a buscar: " << endl;
    cin >> codigo;
    pos = buscarUsuario(codigo);
    if(pos >= 0){
        Usuario user;
        user = leerUser(pos);
        mostrarDatos(user); //alternativa tambien funciona: mostrarDatos(leerUser(pos));
    } else {
        cout << "Codigo inexistente" << endl;
    }
}
bool modificarUser(){
    int codigo, pos, opc;
    cout << "Ingresar ID a buscar: " << endl;
    cin >> codigo;
    pos = buscarUsuario(codigo);
    if(pos >= 0){
        cout << "Usuario a modificar: " << endl;
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
                cin >> user.peso;
            break;
            case 2:
                cout << "Nueva Actividad" << endl;
                cin >> user.actividad;
            break;
            case 3:
                cout << "Nuevo Apto medico" << endl;
                cin >> user.aptoMedico;
            break;
        }
        guardarModificacion(user, pos);

    } else {
        cout << "No existe Usuario" << endl;
        return false;
    }

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
bool backupArchivo(){
    Usuario user;
    FILE *f = fopen(FILEUSUARIOS, "rb");
    if(f == NULL){
        cout << "No se puede leer el archivo.dat .";
        return false;
    }
    while(fread(&user, sizeof(Usuario), 1, f)){
        FILE *bk;
    bk = fopen("datos/archUsuariosBK.dat", "ab");
    if(bk == NULL){
        cout << "No se puede guardar.";
        return false;
    }
        fwrite(&user, sizeof(Usuario), 1, bk);
        fclose(bk);
    }
    fclose(f);
    cout << "Se realizo Backup del archivo.dat llamado archUsuariosBK" << endl;
    return true;
}
