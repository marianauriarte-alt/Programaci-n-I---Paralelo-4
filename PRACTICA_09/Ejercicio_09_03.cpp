// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 3

#include <iostream>
#include <vector>

using namespace std;

void generarMatrizPatron(vector<vector<int>>& matriz, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            matriz[i][j] = (2 * i) + j + 1;
        }
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
    cout << "Ingrese el orden N de la matriz: ";
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));
    generarMatrizPatron(matriz, n);

    cout << "\nMatriz generada con el patrón:" << endl;
    mostrarMatriz(matriz, n);

    return 0;
}
