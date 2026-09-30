// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 4

#include <iostream>
#include <vector>
using namespace std;

void leerVector(vector<double>& v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Elemento [" << i << "]: ";
        cin >> v[i];
    }
}

void multiplicar(vector<double> v1, vector<double> v2, vector<double>& v3, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        v3[i] = v1[i] * v2[i];
    }
}

void mostrarVector(vector<double> v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int n;
    cout << "Ingrese la dimension N: ";
    cin >> n;

    vector<double> vec1(n);
    vector<double> vec2(n);
    vector<double> res(n);

    cout << "Cargar Vector 1:\n";
    leerVector(vec1, n);

    cout << "Cargar Vector 2:\n";
    leerVector(vec2, n);

    multiplicar(vec1, vec2, res, n);

    cout << "Resultado de la multiplicacion:\n";
    mostrarVector(res, n);

    return 0;
}
