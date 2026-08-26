//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int numero_1,numero_2,sec;
    cout<<"Ingrese el primer numero: ";
    cin>>numero_1;
    do{
        cout<<"\nIngrese el segundo numero: ";
        cin>>numero_2;
    }while (numero_1==numero_2);

    if (numero_1 > numero_2)
    {
        for (int i=0;i<=(numero_1-numero_2);i++)
        {
            cout<<numero_1-i<<",";
        }
    }
    else 
    {
        for (int i=0;i<=(numero_2-numero_1);i++)
        {
            cout<<numero_1+i<<",";
        }
    }

    return 0;
}