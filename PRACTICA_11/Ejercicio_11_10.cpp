// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Equipo
{
    string nombre;
    int partidosJugados;
    int victorias;
    int puntosTotales;
};

void registrar_equipos (vector<Equipo> &equipos, int n)
{
    equipos.resize(n);

    for (int i=0; i<n; i++)
    {
        cout<<"\nIngrese el nombre del equipo "<<i+1<<": ";
        cin>>equipos[i].nombre;

        equipos[i].partidosJugados = 0;
        equipos[i].victorias = 0;
        equipos[i].puntosTotales = 0;
    }
}

void simular_partido (vector<Equipo> &equipos)
{
    int equipo1, equipo2, ganador;

    equipo1 = rand() % equipos.size();

    do
    {
        equipo2 = rand() % equipos.size();

    } while (equipo1 == equipo2);

    cout<<"\nPARTIDO SIMULADO"<<endl;

    cout<<equipos[equipo1].nombre<<" VS ";
    cout<<equipos[equipo2].nombre<<endl;

    ganador = rand() % 2;

    if (ganador == 0)
    {
        equipos[equipo1].victorias++;
        equipos[equipo1].partidosJugados++;
        equipos[equipo1].puntosTotales += 3;

        equipos[equipo2].partidosJugados++;

        cout<<"\nGanador: "<<equipos[equipo1].nombre<<endl;
    }
    else
    {
        equipos[equipo2].victorias++;
        equipos[equipo2].partidosJugados++;
        equipos[equipo2].puntosTotales += 3;

        equipos[equipo1].partidosJugados++;

        cout<<"\nGanador: "<<equipos[equipo2].nombre<<endl;
    }
}

void ordenar_equipos (vector<Equipo> &equipos)
{
    Equipo auxiliar;

    for (int i=0; i<equipos.size()-1; i++)
    {
        for (int j=i+1; j<equipos.size(); j++)
        {
            if (equipos[i].puntosTotales < equipos[j].puntosTotales)
            {
                auxiliar = equipos[i];
                equipos[i] = equipos[j];
                equipos[j] = auxiliar;
            }
        }
    }
}

void mostrar_tabla (vector<Equipo> equipos)
{
    cout<<"\nTABLA DE POSICIONES"<<endl;

    cout<<"Posicion | Equipo | Jugados | Victorias | Puntos"<<endl;

    for (int i=0; i<equipos.size(); i++)
    {
        cout<<i+1<<" | ";
        cout<<equipos[i].nombre<<" | ";
        cout<<equipos[i].partidosJugados<<" | ";
        cout<<equipos[i].victorias<<" | ";
        cout<<equipos[i].puntosTotales<<endl;
    }
}

int main ()
{
    int n;
    vector<Equipo> equipos;

    srand(time(0));

    cout<<"Ingrese la cantidad de equipos: ";
    cin>>n;

    if (n < 2)
    {
        cout<<"\nSe necesitan al menos dos equipos.";
        return 0;
    }

    registrar_equipos (equipos, n);

    simular_partido (equipos);

    ordenar_equipos (equipos);

    mostrar_tabla (equipos);

    return 0;
}
