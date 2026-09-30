// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 5

#include <iostream>
#include <vector>
using namespace std;

void leerVector(vector<int>& v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Elemento [" << i << "]: ";
        cin >> v[i];
    }
}

void combinar(vector<int> v1, vector<int> v2, vector<int>& v3, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        v3[i] = v1[i];
    }
    for (int i = 0; i < n; i++) 
    {
        v3[n + i] = v2[i];
    }
}

void mostrarVector(vector<int> v, int tam) 
{
    for (int i = 0; i < tam; i++) 
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

    vector<int> vec1(n);
    vector<int> vec2(n);
    vector<int> combinado(2 * n);

    cout << "Cargar Vector 1:\n";
    leerVector(vec1, n);

    cout << "Cargar Vector 2:\n";
    leerVector(vec2, n);

    combinar(vec1, vec2, combinado, n);

    cout << "Vector Combinado:\n";
    mostrarVector(combinado, 2 * n);

    return 0;
}
