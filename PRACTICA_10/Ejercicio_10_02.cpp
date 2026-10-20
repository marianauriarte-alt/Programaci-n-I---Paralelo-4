//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 2
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


void generar_puntuaciones (vector<int> &puntuaciones, int n)
{
    for (int i=0;i<n;i++)
    {
        puntuaciones [i] = (rand()%100-1+1)+1;
    }

}

void ordenamiento (vector<int>&puntuaciones,int n)
{
    int aux;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            if (puntuaciones[j]<puntuaciones[j+1])
            {
                aux = puntuaciones [j];
                puntuaciones [j] = puntuaciones [j+1];
                puntuaciones [j+1]=aux;
            }
        }
    }
}

void mostrar_matriz (vector<int>puntuaciones,int n)
{
    cout<<"El podio de las puntaciones mas altas es: "<<endl;
    for (int i=0;i<3;i++)
    {
        cout<<puntuaciones [i]<<"\t";
    }
}


int main ()
{
    srand(time(NULL));
    int n;
    cout<<"Ingrese el numero de jugadores: ";
    cin>>n;

    vector<int>puntuaciones(n);

    generar_puntuaciones (puntuaciones,n);
    ordenamiento (puntuaciones,n);
    mostrar_matriz (puntuaciones,n);


    return 0;
}
