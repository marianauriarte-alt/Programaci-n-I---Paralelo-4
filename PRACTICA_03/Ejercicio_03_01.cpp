//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int numero;
    do{
    cout<<"Ingrese un numero del 1 al 10: ";
    cin>>numero;
    }
    while (numero <=0 || numero>10);

    cout<<"\nLa tabla de multiplicar del numero ingresado es: "<<endl;
    
    for (int i=1;i<=10;i++)
    {
        cout<<numero<<" * "<<i<<" = "<<numero*i<<endl;
    }

    return 0;

}