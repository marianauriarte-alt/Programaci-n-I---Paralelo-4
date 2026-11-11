// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Cancion
{
    string titulo;
    string artista;
    int duracionSegundos;
};

void calcular_duracion (vector<Cancion> canciones)
{
    int total=0;
    int minutos, segundos;

    for (int i=0; i<canciones.size(); i++)
    {
        total += canciones[i].duracionSegundos;
    }

    minutos = total / 60;
    segundos = total % 60;

    cout<<"\nDURACION TOTAL DE LA PLAYLIST"<<endl;
    cout<<"Minutos: "<<minutos<<endl;
    cout<<"Segundos: "<<segundos<<endl;
}

int main ()
{
    int n;
    vector<Cancion> canciones;

    cout<<"Ingrese la cantidad de canciones: ";
    cin>>n;

    canciones.resize(n);

    cin.ignore();

    for (int i=0; i<n; i++)
    {
        cout<<"\nCANCIÓN "<<i+1<<endl;

        cout<<"Ingrese el titulo: ";
        getline(cin, canciones[i].titulo);

        cout<<"Ingrese el artista: ";
        getline(cin, canciones[i].artista);

        cout<<"Ingrese la duracion en segundos: ";
        cin>>canciones[i].duracionSegundos;

        cin.ignore();
    }

    calcular_duracion (canciones);

    return 0;
}
