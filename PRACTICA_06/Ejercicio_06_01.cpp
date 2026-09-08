//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 06/09/2026.
//Numero de ejercicio: 1
#include <iostream>
#include <conio.h>
using namespace std;

void intercambiar (int&num1, int &num2)
{
    int aux;
    aux =num1;
    num1 = num2;
    num2 = aux;
}

int main ()
{
    int num1=10, num2=15;
    cout<<"El valor de num1 es: "<<num1<<endl;
    cout<<"El valor de num2 es:  "<<num2<<endl;

    intercambiar (num1,num2);

    cout<<"\n El nuevo valor de num1 es: "<<num1<<endl;
    cout<<"El nuevo valor de num2 es: "<<num2<<endl;

    getch ();
    return 0;
}