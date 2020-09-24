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
void mostrarEnt(Entrenamiento);
bool guardarEntren(Entrenamiento); // Guarda el registro de ENTRENAMIENTO dentro de archEntrenamiento.dat

int cantidadEntren(); // Indica la cantidad total de entrenamientos registrados
int validarAct();
float validarCalorias();
int validarMin();
Entrenamiento leerEntren(int);
void listarEnTodos(); // Lista todos los datos del archEntrenamiento.dat
#endif // ENTRENAMIENTO_H_INCLUDED
