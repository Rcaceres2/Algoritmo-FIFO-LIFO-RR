#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "estructuras.h"

void ejecutar_fifo(Proceso lista[], int n)
{
    int t_clock = 0, completados = 0;
    bool done[MAX_PROCESOS] = {false};
    while (completados < n)
    {
        bool encontrado = false;
        for (int i = 0; i < n; i++)
        {
            if (!done[i] && lista[i].ti <= t_clock)
            {
                t_clock += lista[i].t;
                lista[i].tf = t_clock;
                done[i] = true;
                completados++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            t_clock++;
    }
}

#endif
