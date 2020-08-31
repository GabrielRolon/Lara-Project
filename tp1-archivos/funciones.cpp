#include <iostream>

using namespace std;
#include "funciones.h"
#include "strUsuario.h"

Usuario cargarDatos(){
    Usuario aux;
    cout<<"Ingresar ID: ";
    cin>>aux.id;

    cout<<endl<<"ingresar nombre/s: ";
    cin.ignore();
    cin.getline(aux.nombre,50);
    cout<<endl<<aux.nombre<<endl;

    cout<<endl<<"Ingresar Apellido/s: ";
    cin.ignore();
    cin.getline(aux.apellido,50);

   /* cout<<endl<<"ingresar fecha de nacimiento: ";
    cin>>fecha; */

    cout<<endl<<"ingresar Altura: ";
    cin>>aux.altura;

    cout<<endl<<"ingresar peso: ";
    cin>>aux.peso;

    /* cout<<endl<<"ingresar si está apto el paciente: ";
    cin>>aux.aptomedico; */

    return aux;
}

void mostrarDatos(Usuario reg){
    cout << endl;
    cout << "ID: " << reg.id << endl;
    cout << "Nombre: " << reg.nombre << endl;
    cout << "Apellido: " << reg.apellido << endl;
   // cout << "Fecha: " << reg.fecha << endl;
    cout << "Altura: " << reg.altura << endl;
    cout << "Peso: " << reg.peso << endl;
}
