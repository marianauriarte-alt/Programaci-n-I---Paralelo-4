//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int precio,precio_final;
    cout<<"Ingrese el precio del producto: ";
    cin>>precio;
    precio_final=precio;
    precio *= 0.13;
    precio_final+=precio;
    cout<<"\nEl precio del producto aplicando el IVA (13%) es: "<<precio_final<<endl;

    return 0;
}