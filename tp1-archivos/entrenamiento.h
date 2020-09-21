#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED

struct FechaEn{
    int dia;
    int mes;
    int anio;
};

struct Entrenamiento{
    int id; // autonumerico
    int idUsuario;
    FechaEn diEntrenamiento;
    int actividad;
    float calorias;
    int tiempo;
};

Entrenamiento cargarEntrenamiento();
FechaEn cargarFechaEn();


#endif // ENTRENAMIENTO_H_INCLUDED
