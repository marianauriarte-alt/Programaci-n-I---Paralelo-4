//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
    int numero,suma=0;
    do
    {
        cout<<"digite un numero: ";
        cin>>numero;
        if (numero>0)
        {
            suma += numero;
        }
    } while (((numero <20 || numero>30))&&(numero != 0));

    cout<<"\nLa suma es: "<<suma<<endl;
    

    return 0; 
}