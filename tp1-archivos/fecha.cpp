#include <iostream>

using namespace std;
#include "fecha.h"

Fecha cargarFecha(){
    Fecha reg;
    cout << "Dia: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "A�o: ";
    cin >> reg.anio;
    return reg;
}

