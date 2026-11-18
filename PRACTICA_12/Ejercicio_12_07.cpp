// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 7

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void calcularPromedios() 
{
    ifstream archivoEntrada("calificaciones.txt");
    if (!archivoEntrada.is_open()) 
    {
        cout << "No se pudo abrir 'calificaciones.txt'.\n";
        return;
    }

    ofstream archivoSalida("promedios.txt");
    if (!archivoSalida.is_open()) 
    {
        cout << "No se pudo crear 'promedios.txt'.\n";
        archivoEntrada.close();
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) 
    {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre;
        ss >> nombre;

        float calificacion, suma = 0;
        int cantidad = 0;

        while (ss >> calificacion) 
        {
            suma += calificacion;
            cantidad++;
        }

        if (cantidad > 0) 
        {
            float promedio = suma / cantidad;
            archivoSalida << nombre << " " << promedio << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "Promedios calculados y guardados en 'promedios.txt' exitosamente.\n";
}

int main() 
{
    calcularPromedios();
    return 0;
}
