// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 8

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void analizarDocumento() 
{
    ifstream archivo("documento.txt");
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir 'documento.txt'.\n";
        return;
    }

    string linea;
    int lineas = 0, palabras = 0, caracteres = 0;

    while (getline(archivo, linea)) 
    {
        lineas++;
        caracteres += linea.length() + 1; // +1 por el salto de línea

        string palabra;
        stringstream ss(linea);
        while (ss >> palabra) 
        {
            palabras++;
        }
    }
    archivo.close();

    cout << "\n--- ESTADÍSTICAS DEL DOCUMENTO ---\n";
    cout << "Total de líneas: " << lineas << endl;
    cout << "Total de palabras: " << palabras << endl;
    cout << "Total de caracteres: " << caracteres << endl;
}

int main() 
{
    analizarDocumento();
    return 0;
}
