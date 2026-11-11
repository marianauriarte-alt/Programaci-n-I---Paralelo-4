// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
using namespace std;

struct Tiempo
{
    int horas;
    int minutos;
    int segundos;
};

Tiempo sumar_tiempo (Tiempo tiempo1, Tiempo tiempo2)
{
    Tiempo resultado;

    resultado.horas = tiempo1.horas + tiempo2.horas;
    resultado.minutos = tiempo1.minutos + tiempo2.minutos;
    resultado.segundos = tiempo1.segundos + tiempo2.segundos;

    if (resultado.segundos >= 60)
    {
        resultado.minutos += resultado.segundos / 60;
        resultado.segundos %= 60;
    }

    if (resultado.minutos >= 60)
    {
        resultado.horas += resultado.minutos / 60;
        resultado.minutos %= 60;
    }

    return resultado;
}

int main ()
{
    Tiempo tiempo1, tiempo2, resultado;

    cout<<"Ingrese el primer tiempo"<<endl;

    cout<<"Horas: ";
    cin>>tiempo1.horas;

    cout<<"Minutos: ";
    cin>>tiempo1.minutos;

    cout<<"Segundos: ";
    cin>>tiempo1.segundos;

    cout<<"\nIngrese el segundo tiempo"<<endl;

    cout<<"Horas: ";
    cin>>tiempo2.horas;

    cout<<"Minutos: ";
    cin>>tiempo2.minutos;

    cout<<"Segundos: ";
    cin>>tiempo2.segundos;

    resultado = sumar_tiempo (tiempo1, tiempo2);

    cout<<"\nTIEMPO TOTAL"<<endl;
    cout<<"Horas: "<<resultado.horas<<endl;
    cout<<"Minutos: "<<resultado.minutos<<endl;
    cout<<"Segundos: "<<resultado.segundos<<endl;

    return 0;
}
