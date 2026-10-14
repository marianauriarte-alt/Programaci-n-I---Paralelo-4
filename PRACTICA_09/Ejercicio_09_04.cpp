// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 4

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void llenarMatriz(vector<vector<int>>& matriz, int filas, int columnas) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            matriz[i][j] = 1 + rand() % 10;
        }
    }
}

void mostrarMatriz(const vector<vector<int>>& matriz, int filas, int columnas) 
{
    for (int i = 0; i < filas; ++i) 
    {
        for (int j = 0; j < columnas; ++j) 
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void buscarPuntoSilla(const vector<vector<int>>& matriz, int filas, int columnas) 
{
    bool encontrado = false;

    for (int i = 0; i < filas; ++i) 
    {
        int colMin = 0;
        int minFila = matriz[i][0];
        for (int j = 1; j < columnas; ++j) 
        {
            if (matriz[i][j] < minFila) 
            {
                minFila = matriz[i][j];
                colMin = j;
            }
        }

        bool esMaxColumna = true;
        for (int k = 0; k < filas; ++k) 
        {
            if (matriz[k][colMin] > minFila) 
            {
                esMaxColumna = false;
            }
        }

        if (esMaxColumna) 
        {
            cout << "¡Punto de Silla encontrado!" << endl;
            cout << "Valor: " << minFila << " en la coordenada (Fila: " << i << ", Columna: " << colMin << ")" << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontró ningún punto de silla en la matriz." << endl;
    }
}

int main() 
{
    srand(time(nullptr));
    int filas, columnas;
    cout << "Ingrese el número de filas (N): ";
    cin >> filas;
    cout << "Ingrese el número de columnas (M): ";
    cin >> columnas;

    vector<vector<int>> matriz(filas, vector<int>(columnas));
    llenarMatriz(matriz, filas, columnas);

    cout << "\nMatriz generada:" << endl;
    mostrarMatriz(matriz, filas, columnas);

    cout << "\nBuscando puntos de silla..." << endl;
    buscarPuntoSilla(matriz, filas, columnas);

    return 0;
}
