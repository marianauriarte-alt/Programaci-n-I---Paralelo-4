// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 2

#include <iostream>
#include <vector>
using namespace std;

void mostrarVoltios(vector<double> voltios) 
{
    for (int i = 0; i < voltios.size(); i++) 
    {
        cout << voltios[i] << "\t";
        if ((i + 1) % 3 == 0) 
        {
            cout << endl;
        }
    }
}

int main() 
{
    vector<double> voltios = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};
    
    cout << "Valores de voltios:" << endl;
    mostrarVoltios(voltios);

    return 0;
}
