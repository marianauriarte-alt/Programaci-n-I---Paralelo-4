// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 7

#include <iostream>
#include <vector>
using namespace std;

int rellenar(vector<int>& v) 
{
    int cantidad = 0;
    int num = 0;
    cout << "Ingrese numeros (numero negativo para salir):\n";
  
    while (cantidad < 100 && num >= 0) 
    {
        cout << "Elemento [" << cantidad << "]: ";
        cin >> num;
        if (num >= 0) 
        {
            v[cantidad] = num;
            cantidad++;
        }
    }
    return cantidad;
}

void imprimir(vector<int> v, int cantidad) 
{
    cout << "\nElementos introducidos:\n";
    for (int i = 0; i < cantidad; i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> vec(100);
    int elementosCargados = rellenar(vec);
    imprimir(vec, elementosCargados);

    return 0;
}
