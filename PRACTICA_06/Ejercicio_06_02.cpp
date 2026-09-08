//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 06/09/2026.
//Numero de ejercicio: 2
#include <iostream>
#include <conio.h>
using namespace std;

void tiempo (int totalseg,int &horas,int&min,int&seg)
{
    horas = totalseg/3600;
    totalseg%=3600;
    min=totalseg/60;
    seg=totalseg%60;
}

int main ()
{
    int totalseg, horas, min, seg;

    cout<<"Digite el numero total de segundos: ";
    cin>>totalseg;

    tiempo (totalseg,horas,min,seg);

    cout<<"\nTiempo equivalente a la cantidad de segundos digitados: "<<endl;
    cout<<"Horas: "<<horas<<endl;
    cout<<"Minutos: "<<min<<endl;
    cout<<"Segundos: "<<seg<<endl;

    getch ();
    return 0;

}