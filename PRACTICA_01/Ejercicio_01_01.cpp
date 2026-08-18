//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int anio;
    do
    {
        cout<<"ingrese el anio: ";
        cin>>anio;
    }
    while (anio<1000);
    if(anio%4 == 0)
        cout<<"\nEl anio ingresado es bisiesto"<<endl;
    else 
        cout<<"El anio ingresado no es bisiesto"<<endl;

    return 0;

}