//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int dia;
    cout<<"Ingrese un numero entre el 1 o 7: ";
    cin>>dia;
    switch (dia)
    {
        case 1: 
        cout<<"Lunes"; break;
        case 2: 
        cout<<"Martes"; break;
        case 3: 
        cout<<"Miercoles"; break;
        case 4: 
        cout<<"Jueves"; break;
        case 5: 
        cout<<"Viernes"; break;
        case 6: 
        cout<<"Sabado"; break;
        case 7: 
        cout<<"Domingo"; break;
        default:
        break;
    }
    return 0;
}