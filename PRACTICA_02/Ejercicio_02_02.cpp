//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
#include <conio.h>
using namespace std;
int main ()
{
    int suma=0, cuadrado;

    for (int i=1;i<=10;++i)
    {
        cuadrado = i * i;
        suma += cuadrado;
    }

    cout<<"El resultado de la suma es: "<<suma;

    getch ();
    return 0; 
}