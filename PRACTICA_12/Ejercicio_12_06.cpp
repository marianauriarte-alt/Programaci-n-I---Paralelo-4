// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 6

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void filtrarTemperaturas() 
{
    ifstream archivoEntrada("temperaturas.txt");
    if (!archivoEntrada.is_open()) 
    {
        cout << "No se pudo abrir 'temperaturas.txt'.\n";
        return;
    }

    ofstream archivoSalida("altas_temperaturas.txt");
    if (!archivoSalida.is_open()) 
    {
        cout << "No se pudo crear 'altas_temperaturas.txt'.\n";
        archivoEntrada.close();
        return;
    }

    float n;
    cout << "Ingrese la temperatura límite (N°C): ";
    cin >> n;

    string ciudad;
    float temp;
    int contador = 0;

    while (archivoEntrada >> ciudad >> temp) {
        if (temp > n) 
        {
            archivoSalida << ciudad << " " << temp << endl;
            contador++;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Filtrado completado. Se guardaron " << contador << " registros en 'altas_temperaturas.txt'.\n";
}

int main() 
{
    filtrarTemperaturas();
    return 0;
}
