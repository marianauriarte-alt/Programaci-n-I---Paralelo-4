//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 30/08/2026.
#include <iostream>
using namespace std;
double conversor (int bolivianos)
{
    double dolares;
    dolares=bolivianos/11.79;

    cout<<"\n"<<bolivianos<< "Bs. son "<<dolares<<"$ Dolares (al tipo de cambio actual).";

    return dolares;

}
int main ()
{
    int bolivianos;
    cout<<"Ingrese el monto en bolivianos que desea convertir: ";
    cin>>bolivianos;

    conversor (bolivianos);

    return 0;
}