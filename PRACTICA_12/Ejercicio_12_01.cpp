// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void guardarNombres() 
{
    ofstream archivo("nombres.txt");
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo para escritura.\n";
        return;
    }
    
    int n;
    cout << "¿Cuántos nombres deseas ingresar?: ";
    cin >> n;
    cin.ignore();

    string nombre;
    for (int i = 0; i < n; i++) 
    {
        cout << "Ingrese el nombre " << i + 1 << ": ";
        getline(cin, nombre);
        archivo << nombre << endl;
    }
    archivo.close();
    cout << "Nombres guardados exitosamente en 'nombres.txt'.\n";
}

void leerNombres() 
{
    ifstream archivo("nombres.txt");
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo para lectura.\n";
        return;
    }

    string nombre;
    cout << "\n--- NOMBRES LEÍDOS DEL ARCHIVO ---\n";
    while (getline(archivo, nombre)) 
    {
        cout << nombre << endl;
    }
    archivo.close();
}

int main() 
{
    guardarNombres();
    leerNombres();
    return 0;
}
