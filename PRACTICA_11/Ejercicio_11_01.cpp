// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
using namespace std;

struct Jugador
{
    string nickname;
    int nivel;
    int experiencia;
};

void aumentar_experiencia (Jugador &jugador, int puntos)
{
    jugador.experiencia += puntos;

    if (jugador.experiencia > 100)
    {
        jugador.nivel++;
        jugador.experiencia = 0;
    }
}

int main ()
{
    Jugador jugador;
    int puntos;

    cout<<"Ingrese el nickname: ";
    cin>>jugador.nickname;

    cout<<"Ingrese el nivel: ";
    cin>>jugador.nivel;

    cout<<"Ingrese la experiencia: ";
    cin>>jugador.experiencia;

    cout<<"\nDATOS ANTES DE INGRESAR PUNTOS"<<endl;
    cout<<"Nickname: "<<jugador.nickname<<endl;
    cout<<"Nivel: "<<jugador.nivel<<endl;
    cout<<"Experiencia: "<<jugador.experiencia<<endl;

    cout<<"\nIngrese los puntos de experiencia: ";
    cin>>puntos;

    aumentar_experiencia (jugador, puntos);

    cout<<"\nDATOS DESPUES DE INGRESAR PUNTOS"<<endl;
    cout<<"Nickname: "<<jugador.nickname<<endl;
    cout<<"Nivel: "<<jugador.nivel<<endl;
    cout<<"Experiencia: "<<jugador.experiencia<<endl;

    return 0;
}
