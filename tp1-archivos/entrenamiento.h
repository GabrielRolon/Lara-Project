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
bool guardarEntren(Entrenamiento); // Guarda el registro de ENTRENAMIENTO dentro de archEntrenamiento.dat


#endif // ENTRENAMIENTO_H_INCLUDED
