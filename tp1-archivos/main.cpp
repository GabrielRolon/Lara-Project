#include <iostream>
#include <locale.h> ///Para poner idioma en espa�ol
#include <stdlib.h> ///Para funciones system

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
