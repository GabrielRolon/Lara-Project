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

Usuario cargarDatos(); // Carga los datos de un user
void mostrarDatos(Usuario); // Muestra el reg de un user
int buscarUsuario(int); // Busca el usuario y devuelve la posicion
bool guardarUsuario(Usuario); // Guarda el registro de un user dentro de archivo.dat
void listarUsuarios(); // Lista todos los datos del archivo.dat
int cantidadUsuarios(); // Indica la cantidad total de usuarios registrados
Usuario leerUser(int); // Lee el reg del usuario por la posicion
void listarPorId(); // Lista por ID
void modificarUser();
bool eliminarUser();
bool guardarModificacion(Usuario, int);
/// BACKUP DE ARCHIVO.DAT
void copiaDeSeguridad();
void restaurarCopia();

#endif // STRUSUARIO_H_INCLUDED
