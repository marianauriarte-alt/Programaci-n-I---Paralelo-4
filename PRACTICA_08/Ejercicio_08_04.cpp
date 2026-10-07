// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string censurarMensaje(string mensaje, const vector<string>& prohibidas) 
{
    for (const string& palabra : prohibidas) 
    {
        size_t pos = mensaje.find(palabra);
        while (pos != string::npos) 
        {
            mensaje.replace(pos, palabra.length(), "***");
            pos = mensaje.find(palabra, pos + 3);
        }
    }
    return mensaje;
}

int main() 
{
    string mensaje = "Eres un manco en este juego";
    vector<string> prohibidas = {"manco", "tonto", "noob"};

    cout << "Entrada: " << mensaje << endl;
    cout << "Salida:  " << censurarMensaje(mensaje, prohibidas) << endl;

    return 0;
}
