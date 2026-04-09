#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

using namespace std;

const int MAX_PROCESOS = 50;

struct Proceso
{
    string nombre;
    int ti;   
    int t;    
    int tf;   
    int T;    
    int E;    
    double I;
};

#endif
