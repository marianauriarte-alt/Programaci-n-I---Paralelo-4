// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contarPalabras() 
{
    ifstream archivo("texto.txt");
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo 'texto.txt'. Asegúrate de crearlo previamente.\n";
        return -1;
    }

    string palabra;
    int contador = 0;
    while (archivo >> palabra) 
    {
        contador++;
    }
    archivo.close();
    return contador;
}

int main() 
{
    int total = contarPalabras();
    if (total != -1) 
    {
        cout << "El archivo 'texto.txt' contiene " << total << " palabras.\n";
    }
    return 0;
}
