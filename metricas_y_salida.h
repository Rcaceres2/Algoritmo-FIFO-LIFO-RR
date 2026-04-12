#ifndef METRICAS_Y_SALIDA_H
#define METRICAS_Y_SALIDA_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "estructuras.h"

using namespace std;

void calcular_y_mostrar(string nombre, Proceso lista[], int n, double &pI_out, ofstream &archivo)
{
    double sumaT = 0, sumaE = 0, sumaI = 0;

    for (int i = 0; i < n; i++)
    {
        lista[i].T = lista[i].tf - lista[i].ti;
        double factor_espera = (1.0 - (double)lista[i].t / lista[i].T);
        lista[i].E = lista[i].T * factor_espera;
        lista[i].I = (lista[i].T != 0) ? (double)lista[i].t / lista[i].T : 0;

        sumaT += lista[i].T;
        sumaE += (double)lista[i].E;
        sumaI += lista[i].I;
    }

    double pT = sumaT / n;
    double pE = sumaE / n;
    double pI = (sumaI / n) * 100;

    pI_out = pI;

    string tabla = "\n Algoritmo: " + nombre + "\n";
    tabla += "================================================\n";
    tabla += "Proceso    | ti   | t    | tf   | T    | E    | I     \n";
    tabla += "------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        tabla += lista[i].nombre + "          | " +
                 to_string(lista[i].ti) + "    | " +
                 to_string(lista[i].t) + "    | " +
                 to_string(lista[i].tf) + "    | " +
                 to_string(lista[i].T) + "    | " +
                 to_string((int)lista[i].E) + "    | " +
                 to_string(lista[i].I).substr(0, 5) + "\n";
    }

    tabla += "------------------------------------------------\n";
    tabla += " Promedios: pT=" + to_string(pT).substr(0, 5) +
             " | pE=" + to_string(pE).substr(0, 5) +
             " | pI=" + to_string(pI).substr(0, 5) + "%\n";
    tabla += "================================================\n";

    cout << tabla;
    if (archivo.is_open())
        archivo << tabla;
}

void comparar_solo_I(double pIs[], string nombres[], int cant, ofstream &archivo)
{
    string res = "\n--- Comparacion ---\n";
    int mejor_idx = 0;
    double min_I = pIs[0];

    for (int i = 0; i < cant; i++)
    {
        res += nombres[i] + ": " + to_string(pIs[i]).substr(0, 5) + "%\n";
        if (pIs[i] < min_I)
        {
            min_I = pIs[i];
            mejor_idx = i;
        }
    }

    res += "\n>>> El mejor algoritmo es: " + nombres[mejor_idx] + " <<<\n";

    cout << res;
    if (archivo.is_open())
        archivo << res;
}

#endif
