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
    menuPrincipal();

    return 0;
}
