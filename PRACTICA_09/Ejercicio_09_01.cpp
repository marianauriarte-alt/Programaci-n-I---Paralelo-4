// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <vector>

using namespace std;

void leerMatriz(vector<vector<int>>& matriz, int n) 
{
    cout << "Ingrese los elementos de la matriz de " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void intercambiarFilas(vector<vector<int>>& matriz, int n) 
{
    for (int j = 0; j < n; ++j) 
    {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[n - 1][j];
        matriz[n - 1][j] = temp;
    }
}

void mostrarMatriz(const vector<vector<int>>& matriz, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() 
{
    int n;
    cout << "Ingrese el orden de la matriz (n x n): ";
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));

    leerMatriz(matriz, n);

    cout << "\nMatriz original:" << endl;
    mostrarMatriz(matriz, n);

    intercambiarFilas(matriz, n);

    cout << "\nMatriz con la primera y ultima fila intercambiadas:" << endl;
    mostrarMatriz(matriz, n);

    return 0;
}
