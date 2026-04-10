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

void ejecutar_lifo(Proceso lista[], int n)
{
    int t_clock = 0, completados = 0;
    bool done[MAX_PROCESOS] = {false};
    while (completados < n)
    {
        bool encontrado = false;
        for (int i = n - 1; i >= 0; i--)
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

void ejecutar_rr(Proceso lista[], int n, int q)
{
    int t_clock = 0, completados = 0;
    int rem[MAX_PROCESOS];
    bool done[MAX_PROCESOS] = {false};
    for (int i = 0; i < n; i++)
        rem[i] = lista[i].t;

    while (completados < n)
    {
        bool encontrado_ciclo = false;
        for (int i = 0; i < n; i++)
        {
            if (!done[i] && lista[i].ti <= t_clock)
            {
                int run_time = (rem[i] < q) ? rem[i] : q;
                t_clock += run_time;
                rem[i] -= run_time;
                encontrado_ciclo = true;
                if (rem[i] == 0)
                {
                    done[i] = true;
                    lista[i].tf = t_clock;
                    completados++;
                }
            }
        }
        if (!encontrado_ciclo)
            t_clock++;
    }
}

#endif
