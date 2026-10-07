// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool esTarjetaValida(const string& tarjeta) 
{
    if (tarjeta.length() != 16) 
      return false;

    int suma = 0;
    bool duplicar = false;

    for (int i = tarjeta.length() - 1; i >= 0; --i) 
    {
        if (!isdigit(tarjeta[i])) return false;

        int digito = tarjeta[i] - '0';

        if (duplicar) 
        {
            digito *= 2;
            if (digito > 9) digito -= 9;
        }

        suma += digito;
        duplicar = !duplicar;
    }

    return (suma % 10 == 0);
}

int main() 
{
    string tarjeta = "4992739871604799";
    cout << "Tarjeta: " << tarjeta << " -> " 
         << (esTarjetaValida(tarjeta) ? "Tarjeta válida" : "Tarjeta inválida") << endl;

    return 0;
}
