// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 6

#include <iostream>
#include <vector>
using namespace std;

void pedirDatos(vector<int>& v) 
{
    for (int i = 0; i < 5; i++) 
    {
        cout << "Elemento [" << i << "]: ";
        cin >> v[i];
    }
}

void sumar(vector<int> v1, vector<int> v2, vector<int>& v3) 
{
    for (int i = 0; i < 5; i++) 
    {
        v3[i] = v1[i] + v2[i];
    }
}

void mostrar(vector<int> v) 
{
    for (int i = 0; i < 5; i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> vector1(5);
    vector<int> vector2(5);
    vector<int> vector3(5);

    cout << "Ingrese valores para vector1:\n";
    pedirDatos(vector1);

    cout << "Ingrese valores para vector2:\n";
    pedirDatos(vector2);

    sumar(vector1, vector2, vector3);

    cout << "Resultado (vector3 = vector1 + vector2):\n";
    mostrar(vector3);

    return 0;
}
