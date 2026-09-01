//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 30/08/2026.

#include <iostream>
using namespace std;

bool numero_par(int numero)
{
    if (numero % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int numero;
    bool d;

    cout<<"Ingrese un numero: ";
    cin>>numero;

    d=numero_par(numero);

    if (d==true)
    {
        cout<<"El numero es par";
    }
    else
    {
        cout<<"El numero es impar";
    }

    return 0;
}