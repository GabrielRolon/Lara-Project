#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct Fecha{
    int dia;
    int mes;
    int anio;
};

Fecha cargarFecha();
void mostrarFecha(Fecha);

#endif // FECHA_H_INCLUDED
