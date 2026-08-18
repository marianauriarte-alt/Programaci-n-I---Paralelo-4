//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    float practica,teoria,participacion,nota_final=0;
    cout<<"Digite la nota de practica: ";
    cin>>practica;
    cout<<"Digite la nota de participacion: ";
    cin>>participacion;
    cout<<"Digite la nota de teoria: ";
    cin>> teoria;

    practica *= 0.30;
    teoria *= 0.60;
    participacion *= 0.10;
    
    nota_final = practica + teoria + participacion;

    cout<<"\nLa nota final es: "<<nota_final;

    return 0;
}