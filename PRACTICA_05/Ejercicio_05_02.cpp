//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 1
#include <iostream>
using namespace std;
void modificar_valores (int a, int&b)
{
    a*=2;
    b+=10;
}
int main ()
{
    int num1, num2;
    cout<<"Ingrese el primer numero: ";
    cin>>num1;
    cout<<"Ingrese el segundo numero: ";
    cin>>num2;

    cout<<"\nEl resultado es: "<<endl;
    modificar_valores (num1,num2);
    cout<<"Numero 1: "<<num1<<endl;
    cout<<"Numero 2: "<<num2<<endl;

    return 0;

}