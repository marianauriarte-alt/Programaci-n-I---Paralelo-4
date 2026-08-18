//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int resto,numero,contador_digitos=0,suma=0;
    do {
        cout<<"Ingrese un numero entero: ";
        cin>>numero;
    }
    while (numero<=0);

    while (numero != 0)
    {
        resto = numero%10;
        numero /= 10;
        contador_digitos += 1;
        suma = suma + resto;
    }

    cout<<"\nEl numero ingresado tiene: "<<contador_digitos<<" digitos"<<endl;
    cout<<"La suma del numero ingresado es: "<<suma<<endl;

    return 0;
}