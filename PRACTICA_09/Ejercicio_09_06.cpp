// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarTemperaturas(vector<vector<int>>& temps) 
{
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 7; ++j) 
        {
            temps[i][j] = 5 + rand() % 31;
        }
    }
}

void mostrarTemperaturas(const vector<vector<int>>& temps) 
{
    cout << "\n--- MATRIZ DE TEMPERATURAS (°C) ---" << endl;
    cout << "      \tD1\tD2\tD3\tD4\tD5\tD6\tD7" << endl;
    for (int i = 0; i < 4; ++i) 
    {
        cout << "Semana " << i + 1 << "\t";
        for (int j = 0; j < 7; ++j) 
        {
            cout << temps[i][j] << "\t";
        }
        cout << endl;
    }
}

void temperaturaMasAlta(const vector<vector<int>>& temps) 
{
    int maxTemp = temps[0][0];
    int semanaMax = 0;
    int diaMax = 0;

    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 7; ++j) 
        {
            if (temps[i][j] > maxTemp) 
            {
                maxTemp = temps[i][j];
                semanaMax = i + 1;
                diaMax = j + 1;
            }
        }
    }
    cout << "Temperatura más alta: " << maxTemp << "°C (Semana " << semanaMax << ", Día " << diaMax << ")" << endl;
}

void promedioSemanas(const vector<vector<int>>& temps) 
{
    cout << "\nPromedio de temperatura por semana:" << endl;
    for (int i = 0; i < 4; ++i) 
    {
        double suma = 0;
        for (int j = 0; j < 7; ++j) 
        {
            suma += temps[i][j];
        }
        double promedio = suma / 7.0;
        cout << "Semana " << i + 1 << ": " << promedio << "°C" << endl;
    }
}

void contarDiasSuperiores30(const vector<vector<int>>& temps) 
{
    int contador = 0;
    for (int i = 0; i < 4; ++i) 
    {
        for (int j = 0; j < 7; ++j) 
        {
            if (temps[i][j] > 30) 
            {
                contador++;
            }
        }
    }
    cout << "Cantidad de días con temperatura superior a 30°C: " << contador << " días." << endl;
}

int main() 
{
    srand(time(nullptr));
    vector<vector<int>> temperaturas(4, vector<int>(7));

    generarTemperaturas(temperaturas);
    mostrarTemperaturas(temperaturas);

    cout << "\n--- ANÁLISIS CLIMÁTICO ---" << endl;
    temperaturaMasAlta(temperaturas);
    promedioSemanas(temperaturas);
    contarDiasSuperiores30(temperaturas);

    return 0;
}
