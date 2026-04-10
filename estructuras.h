#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

using namespace std;

const int MAX_PROCESOS = 50;

struct Proceso
{
    string nombre;
    int ti;   // Tiempo de inicio
    int t;    // Tiempo de ejecucion
    int tf;   // Tiempo final
    int T;    // Tiempo de servicio
    int E;    // Tiempo de espera
    double I; // Indice de servicio
};

#endif
