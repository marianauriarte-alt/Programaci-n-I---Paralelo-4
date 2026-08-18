//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    float a , b, resultado = 0;

    cout<<"Digite el valor de a: ";
    cin>> a;
    cout<<"Digite el valor de b: ";
    cin>> b;

    resultado = (a/b) + 1;

    cout.precision(2);
    cout<<"\nEl resultado es: "<<resultado<<endl;

    return 0;

}