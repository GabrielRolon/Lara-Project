/**
    Trabajo practico 1,2 y 3 de Laboratorio 2

    Autores:    •Maximiliano Miranda
                •Gabriel Rolón
                •Cristian Uhrig
*/
#include <iostream>
#include <locale.h> ///Para poner idioma en español
#include <windows.h> ///Para funciones system

using namespace std;
#include "funciones.h"
#include "strUsuario.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    system("color 5f");
    creditos();
    menuPrincipal();

    return 0;
}
