//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 30/08/2026.
#include <iostream>
using namespace std;
int calculo_area (int base, int altura)
{
    int area;
    area = (base*altura)/2;
    cout<<"\nLa area es: "<<area<<endl;

    return area;
}
int main ()
{
    int base,altura;
    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<"Ingrese la altura: ";
    cin>>altura;

    calculo_area (base,altura);

    return 0;
}