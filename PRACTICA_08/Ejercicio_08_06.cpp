// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>

using namespace std;

string limpiarEspacios(const string& texto) 
{
    size_t inicio = texto.find_first_not_of(" ");
    size_t fin = texto.find_last_not_of(" ");

    if (inicio == string::npos) 
      return "";

    string resultado = "";
    bool enEspacio = false;

    for (size_t i = inicio; i <= fin; ++i) 
    {
        if (texto[i] == ' ') 
        {
            if (!enEspacio) 
            {
                resultado += ' ';
                enEspacio = true;
            }
        } else 
        {
            resultado += texto[i];
            enEspacio = false;
        }
    }

    return resultado;
}

int main() 
{
    string texto = "   Juan   Perez   Gonzalez   ";
    cout << "Entrada: \"" << texto << "\"" << endl;
    cout << "Salida:  \"" << limpiarEspacios(texto) << "\"" << endl;

    return 0;
}
