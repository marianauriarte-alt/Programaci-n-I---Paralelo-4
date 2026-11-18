// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void buscarTexto() 
{
    ifstream archivo("datos.txt");
    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo 'datos.txt'.\n";
        return;
    }

    string buscar;
    cout << "Ingrese la palabra o frase a buscar: ";
    cin.ignore();
    getline(cin, buscar);

    string linea;
    int contador = 0;
    while (getline(archivo, linea)) 
    {
        size_t pos = linea.find(buscar);
        while (pos != string::npos) 
        {
            contador++;
            pos = linea.find(buscar, pos + buscar.length());
        }
    }
    archivo.close();

    cout << "La palabra o frase \"" << buscar << "\" aparece " << contador << " veces en el archivo.\n";
}

int main() 
{
    buscarTexto();
    return 0;
}
