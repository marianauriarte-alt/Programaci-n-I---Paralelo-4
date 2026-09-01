//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 30/08/2026.
#include <iostream>
using namespace std;
int volumen (int radio, int altura)
{
    const double pi=3.14159;
    int volumen;
    volumen = (pi*radio*radio*altura);
    cout<<"\nEl volumen del cilindro es: "<<volumen;

    return volumen;
}

int main ()
{
    int radio,altura;
    cout<<"Ingrese el radio del cilindro: ";
    cin>>radio;
    cout<<"Ingrese la altura del cilindro: ";
    cin>>altura;

    volumen (radio,altura);

    return 0;
}