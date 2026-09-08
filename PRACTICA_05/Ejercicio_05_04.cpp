//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 4
#include <iostream>
using namespace std;
const float PI = 3.14159;
double calcular_Area(double longitud)
{
    double Area;
    Area=longitud*longitud;

    return Area;
}
double calcular_Area(double base,double altura)
{
    double Area;
    Area= base*altura;

    return Area;
}
float calcular_Area(float radio,float PI)
{
    float Area;
    Area = (radio*radio)*PI;

    return Area;
}
void menu ()
{
    cout<<"\nElija que tipo de area desea calcular: "<<endl;
    cout<<"1. Area de un cuadrado"<<endl;
    cout<<"2. Area de un rectangulo"<<endl;
    cout<<"3. Area de un circulo"<<endl;
    cout<<"0. Salir"<<endl;
}
int main ()
{
    int opcion;
    double longitud,base,altura;
    float radio;
    menu ();
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    switch (opcion)
    {
    case 1: 
    cout<<"Ingrese la longitud del cuadrado: ";
    cin>>longitud;
    cout<<"\nEl Area del cuadrado es: "<<calcular_Area(longitud);
    break;

    case 2:
    cout<<"Ingrese la base del rectangulo: ";
    cin>>base;
    cout<<"Ingrese la altura del rectangulo: ";
    cin>>altura;
    cout<<"\nEl Area del rectangulo es: "<<calcular_Area(base,altura);
    break;

    case 3:
    cout<<"Ingrese el radio del circulo: ";
    cin>>radio;
    cout<<"\nEl Area del rectangulo es: "<<calcular_Area(radio,PI);
    break;

    default:
    break;
    }
}