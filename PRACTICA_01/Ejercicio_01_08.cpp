//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int nota;
    do {
        cout<<"ingrese la nota: ";
        cin>>nota;
        if (nota>=0 && nota<=100)
            cout<<"Nota resgistrada correctamente";
    }
    while (nota<0 || nota>100);
    return 0;
}