//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int practicas,teoria,participacion,nota_final;
    cout<<"Ingrese la nota de las practicas: ";
    cin>>practicas;
    cout<<"Ingrese la nota de la teoria: ";
    cin>>teoria;
    cout<<"Ingrese la nota de las participacion: ";
    cin>>participacion;
    
    practicas*=0.3;
    teoria*=0.6;
    participacion *=0.1;

    nota_final=practicas+teoria+participacion;

    cout<<"\nLa nota final es: "<<nota_final<<endl;

    return 0;

}