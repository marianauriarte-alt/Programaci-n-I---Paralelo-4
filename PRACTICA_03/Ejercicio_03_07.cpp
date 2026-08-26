//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int numero,divisor=1,verificacion=0;
    cout<<"Ingrese un numero para verificar si es un numero perfecto: ";
    cin>>numero;
    while (divisor < numero)
    {
        if (numero%divisor==0)
        {
            verificacion+=divisor;
        }
        divisor++;
    }
    
    if (verificacion == numero){
        cout<<"\nEs un numero perfecto";
    }
    else{
        cout<<"\nNo es un numero perfecto";
    }


}