// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarMatriz(vector<vector<int>>& matriz, int n, int a, int b) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            matriz[i][j] = a + rand() % (b - a + 1);
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

int sumarUltimaColumna(const vector<vector<int>>& matriz, int n) 
{
    int suma = 0;
    for (int i = 0; i < n; ++i) 
    {
        suma += matriz[i][n - 1];
    }
    return suma;
}

long long productoUltimaFila(const vector<vector<int>>& matriz, int n) 
{
    long long producto = 1;
    for (int j = 0; j < n; ++j) 
    {
        producto *= matriz[n - 1][j];
    }
    return producto;
}

void mayorValorMatriz(const vector<vector<int>>& matriz, int n, int& mayor, int& posX, int& posY) 
{
    mayor = matriz[0][0];
    posX = 0;
    posY = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (matriz[i][j] > mayor) 
            {
                mayor = matriz[i][j];
                posX = i;
                posY = j;
            }
        }
    }
}

double calcularPromedio(const vector<vector<int>>& matriz, int n) 
{
    double sumaTotal = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            sumaTotal += matriz[i][j];
        }
    }
    return sumaTotal / (n * n);
}

int main() 
{
    srand(time(nullptr));
    int n, a, b;
    cout << "Ingrese el orden N de la matriz: ";
    cin >> n;
    cout << "Ingrese el límite inferior A: ";
    cin >> a;
    cout << "Ingrese el límite superior B: ";
    cin >> b;

    if (a > b) 
    {
        cout << "El límite A debe ser menor o igual a B." << endl;
        return 0;
    }

    vector<vector<int>> matriz(n, vector<int>(n));
    generarMatriz(matriz, n, a, b);

    cout << "\nMatriz generada:" << endl;
    mostrarMatriz(matriz, n);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Suma de la última columna: " << sumarUltimaColumna(matriz, n) << endl;
    cout << "Producto total de la última fila: " << productoUltimaFila(matriz, n) << endl;

    int mayor, posX, posY;
    mayorValorMatriz(matriz, n, mayor, posX, posY);
    cout << "Mayor valor: " << mayor << " en la posición [" << posX << "][" << posY << "]" << endl;
    cout << "Promedio total de la matriz: " << calcularPromedio(matriz, n) << endl;

    return 0;
}
