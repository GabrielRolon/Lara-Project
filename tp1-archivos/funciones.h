#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///Las funciones en general

void menuPrincipal();
void menuUsuarios();


///Funciones de verificacion de datos
void validarNombre(char [50]);
void validarApellido(char [50]);
void validarAltura(float);
void validarPeso(float);
void validarPerfilA(char);
void validarAptoM(bool);
void verificarFecha(int, int, int);


#endif // FUNCIONES_H_INCLUDED
