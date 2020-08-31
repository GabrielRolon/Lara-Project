#ifndef STRUSUARIO_H_INCLUDED
#define STRUSUARIO_H_INCLUDED

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

Usuario cargarDatos();
void mostrarDatos(Usuario);

#endif // STRUSUARIO_H_INCLUDED
