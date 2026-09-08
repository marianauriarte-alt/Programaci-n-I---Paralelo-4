//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 05/09/2026.
#include <iostream>
using namespace std;
void intercambiar_valores (int&a, int&b)
{
    int d;
    d=a;
    a=b;
    b=d;
}
int main ()
{
    int num1, num2;
    cout<<"Ingrese el primer numero: ";
    cin>>num1;
    cout<<"Ingrese el segundo numero: ";
    cin>>num2;

    cout<<"Los numeros ingresados son: "<<endl;
    cout<<"Numero 1: "<<num1<<endl;
    cout<<"Numero 2: "<<num2<<endl;

    intercambiar_valores(num1,num2);

    cout<<"\nLos numeros intercambiados son: "<<endl;
    cout<<"Numero 1: "<<num1<<endl;
    cout<<"Numero 2: "<<num2<<endl;

    return 0;

}