#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///Las funciones en general

void menuPrincipal();
void menuUsuarios();
void menuEntrenamientos();
void menuConfiguracion();

///Funciones de verificacion de datos
char validarNombre();
char validarApellido();
float validarAltura();
float validarPeso();
char validarPerfilA();
bool validarAptoM();
void verificarFecha(int, int, int);


#endif // FUNCIONES_H_INCLUDED
