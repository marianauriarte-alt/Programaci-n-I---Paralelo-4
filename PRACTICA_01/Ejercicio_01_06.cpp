//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int numero;
    do{
        cout<<"Ingrese un numero entero: ";
        cin>>numero;
    }
    while (numero <= 0);

    if (numero%2==0 )
        cout<<"\nel numero ingresado es par.";
    else 
        cout<<"\nel numero ingresado es impar.";

    return 0;
}