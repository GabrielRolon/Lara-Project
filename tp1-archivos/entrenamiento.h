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
int validarAct(); //valida actividad que sea correcta 1 a 5
float validarCalorias(); //valida numero real positivo
int validarMin(); //valida numero entero positivo
Entrenamiento leerEntren(int); //lee el archivo
void listarEnTodos(); // Lista todos los datos del archEntrenamiento.dat
int buscarEnt(int); // Busca el entrenamiento ID y devuelve la posicion
void modificarEnt(); // Modifica entrenamiento
bool guardarModificacionEnt(Entrenamiento, int);
void listarPorIdEnt(); // Lista por ID
void listarPorIdUsuario();
//void listarPorIdUsuario(reg);
#endif // ENTRENAMIENTO_H_INCLUDED
