#include <iostream>


using namespace std;

    struct paciente{
    int ID;
    char Nombres[50];
    char Apellidos[50];
    int Fecha;
    float Altura;
    float Peso;
    char Actividad;
    bool Aptomedico, Estado;
    };


int main()
{


    paciente p;
    cout<<"Ingresar ID: ";
    cin>>p.ID;

    cout<<endl<<"ingresar nombre/s: ";
    cin.ignore();
    cin.getline(p.Nombres,50);
    cout<<endl<<p.Nombres<<endl;

    cout<<endl<<"Ingresar Apellido/s: ";
    cin.ignore();
    cin.getline(p.Apellidos,50);

    cout<<endl<<"ingresar fecha de nacimiento: ";
    cin>>p.Fecha;

    cout<<endl<<"ingresar Altura: ";
    cin>>p.Altura;

    cout<<endl<<"ingresar peso: ";
    cin>>p.Peso;

    cout<<endl<<"ingresar si está apto el paciente: ";
    cin>>p.Aptomedico;


    return 0;
}

//    void menu(opcion){
//
//        int opcion;
//        while(true){
//            switch(opcion){
//        case 1:
//            break;//        case 2:
//            break;//        case 3:
//            break;//        case 4:
//            break;//        case 0: return 0;
//            break;
//            }
//        }
//
//
//    };
