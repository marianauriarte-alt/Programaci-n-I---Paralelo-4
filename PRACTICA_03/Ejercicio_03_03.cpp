//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
using namespace std;
int main()
{
    int n,contador=0,suma=0;
    cout<<"ingrese los n numeros que desea generar: ";
    cin>>n;

    while (contador<n)
    {
        contador++;
        suma+=contador;
    }

    cout<<"\nLa suma total es: "<<suma<<endl;

    return 0;

}