#ifndef STRUSUARIO_H_INCLUDED
#define STRUSUARIO_H_INCLUDED

/// Declaracion de struct fecha y usuario
struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Usuario{
    int id;
    char nombre[50];
    char apellido[50];
    Fecha nacimiento;
    float altura;
    float peso;
    char actividad;
    bool aptoMedico;
    bool estado;
};

// Declaracion de prototipos para las funciones de fecha y usuario
Fecha cargarFecha();
void mostrarFecha(Fecha);

Usuario cargarDatos();
void mostrarDatos(Usuario);

#endif // STRUSUARIO_H_INCLUDED
