// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante 
{
    string nombre;
    int edad;
    float promedio;
};

void registrarEstudiantes() 
{
    ofstream archivo("estudiantes.txt");
    if (!archivo.is_open()) 
    {
        cout << "Error al abrir el archivo para escritura.\n";
        return;
    }

    int n;
    cout << "¿Cuántos estudiantes deseas registrar?: ";
    cin >> n;

    Estudiante est;
    for (int i = 0; i < n; i++) 
    {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, est.nombre);
        cout << "Edad: ";
        cin >> est.edad;
        cout << "Promedio: ";
        cin >> est.promedio;

        archivo << "Nombre: " << est.nombre << endl;
        archivo << "Edad: " << est.edad << endl;
        archivo << "Promedio: " << est.promedio << endl;
    }
    archivo.close();
    cout << "\nRegistros guardados exitosamente en 'estudiantes.txt'.\n";
}

void leerEstudiantes() 
{
    ifstream archivo("estudiantes.txt");
    if (!archivo.is_open()) 
    {
        cout << "Error al abrir el archivo para lectura.\n";
        return;
    }

    string linea;
    cout << "\n--- INFORMACIÓN DE ESTUDIANTES ---\n";
    while (getline(archivo, linea)) 
    {
        cout << linea << endl;
    }
    archivo.close();
}

int main() 
{
    registrarEstudiantes();
    leerEstudiantes();
    return 0;
}
