#include <iostream>
#include <fstream>
#include <string>
#include "estructuras.h"
#include "algoritmos.h"
#include "metricas_y_salida.h"

using namespace std;

int main()
{
    Proceso base[MAX_PROCESOS];
    int n = 0;

    ifstream entrada("data.txt");
    if (!entrada.is_open())
    {
        cout << "No se pudo abrir data.txt" << endl;
        return 1;
    }

    string linea;
    getline(entrada, linea);
    while (n < MAX_PROCESOS && getline(entrada, linea))
    {
        if (linea == "" || linea[0] == '[')
            continue;
        size_t p1 = linea.find(','), p2 = linea.find(',', p1 + 1);
        base[n].nombre = linea.substr(0, p1);
        base[n].ti = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
        base[n].t = stoi(linea.substr(p2 + 1));
        n++;
    }
    entrada.close();

    ofstream f_out("resultados.txt");
    double resultados_I[3];
    string nombres[] = {"FIFO", "LIFO", "RR"};

    ejecutar_fifo(base, n);
    calcular_y_mostrar(nombres[0], base, n, resultados_I[0], f_out);

    ejecutar_lifo(base, n);
    calcular_y_mostrar(nombres[1], base, n, resultados_I[1], f_out);

    ejecutar_rr(base, n, 4);
    calcular_y_mostrar(nombres[2], base, n, resultados_I[2], f_out);

    comparar_solo_I(resultados_I, nombres, 3, f_out);

    f_out.close();
    return 0;
}
