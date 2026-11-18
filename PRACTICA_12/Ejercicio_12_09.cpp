// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 9

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char cifrarCaracter(char c) 
{
    if (c >= 'a' && c <= 'z') 
    {
        return 'a' + (c - 'a' + 3) % 26;
    } 
    else if (c >= 'A' && c <= 'Z') 
    {
        return 'A' + (c - 'A' + 3) % 26;
    }
    return c;
}

void cifrarArchivo() 
{
    ifstream archivoEntrada("mensaje.txt");
    if (!archivoEntrada.is_open()) 
    {
        cout << "No se pudo abrir 'mensaje.txt'.\n";
        return;
    }

    ofstream archivoSalida("mensaje_cifrado.txt");
    if (!archivoSalida.is_open()) 
    {
        cout << "No se pudo crear 'mensaje_cifrado.txt'.\n";
        archivoEntrada.close();
        return;
    }

    char c;
    while (archivoEntrada.get(c)) 
    {
        archivoSalida.put(cifrarCaracter(c));
    }

    archivoEntrada.close();
    archivoSalida.close();
    cout << "Archivo cifrado correctamente en 'mensaje_cifrado.txt'.\n";
}

int main() 
{
    cifrarArchivo();
    return 0;
}
