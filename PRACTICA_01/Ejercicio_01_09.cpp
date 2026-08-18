//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int resto,numero,columna=1,fila=1;
    do {
        cout<<"Ingrese un numero entero: ";
        cin>>numero;
    }
    while (numero<=0);

    while (numero != 0)
    {
        resto = numero%10;
        numero /= 10;
        columna = 1;
        while (columna<=resto)
        {
            fila=1;
            while (fila<=resto)
            {
               cout<<resto;
               fila++; 
            }
            cout<<endl;
            columna++;
        }

    }

    return 0;
}