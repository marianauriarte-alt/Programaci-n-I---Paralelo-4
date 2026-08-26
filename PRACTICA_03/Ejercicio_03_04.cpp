//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int n,numero,factorial=1,suma=0;
    cout<<"ingrese los n numeros que desea generar: ";
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        numero=i;
        factorial=1;
        for (int j=1;j<=numero;j++)
        {
            factorial*=j;
        }
        suma+=factorial;
    }
    cout<<"La suma de los n numeros ! (factorial) es: "<<suma;

    return 0;
}

    
