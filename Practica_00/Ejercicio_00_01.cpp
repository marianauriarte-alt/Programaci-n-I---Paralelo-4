//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int n1,n2,suma=0,resta=0,multiplicacion=0,division=0;
    cout<<"Digite un numero: ";
    cin>>n1;
    cout<<"Digite otro numero: ";
    cin>>n2;
    suma = n1 + n2;
    resta = n1 - n2;
    multiplicacion = n1 * n2;
    division = n1/n2;

    cout<<"\n La suma es es: "<<suma<<endl;
    cout<<"\n La resta es es: "<<resta<<endl;
    cout<<"\n La multiplicacion es es: "<<multiplicacion<<endl;
    cout<<"\n La division es es: "<<division<<endl;
    return 0;

}