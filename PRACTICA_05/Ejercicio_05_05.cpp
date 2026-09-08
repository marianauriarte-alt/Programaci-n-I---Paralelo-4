//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 5
#include <iostream>
using namespace std;
void Calculartiempo(int totalSegundos, int &horas, int &minutos, int &segundos)
{
    
    if (horas==0)
    {
        horas=totalSegundos/3600;
        totalSegundos%=3600;
    }
    if (totalSegundos != 0)
    {
        minutos=totalSegundos/60;
        totalSegundos%=60;
    }
    if (totalSegundos!= 0)
    {
        segundos=totalSegundos;
    }
}
int main ()
{
    int TotalSegundos,horas=0,minutos=0,segundos=0;
    cout<<"Ingrese los segundos: ";
    cin>>TotalSegundos;

    Calculartiempo (TotalSegundos,horas,minutos,segundos);

    cout<<"\nEn los segundos ingresados hay: "<<endl;
    cout<<"--------------------------------"<<endl<<endl;
    cout<<"Horas: "<<horas<<endl;
    cout<<"Minutos: "<<minutos<<endl;
    cout<<"Segundos: "<<segundos<<endl;

    return 0;


}