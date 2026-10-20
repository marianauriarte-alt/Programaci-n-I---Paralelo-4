//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 3
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void generar_segundos (vector<float>&segundos,int n,float max,float min)
{
    for (int i=0;i<n;i++)
    {
        segundos [i] = min + (float)rand()/RAND_MAX*(max-min);
    }
}
void ordenamiento (vector<float>&segundos,int n)
{

    for (int i=0;i<n;i++)
    {
        float aux;
        int posicion = n-1;
        while (posicion>0)
        {
            if (segundos [posicion]<segundos[posicion-1])
            {
                aux=segundos [posicion];
                segundos[posicion]=segundos[posicion-1];
                segundos[posicion-1]=aux;
            }
            posicion--;
        }
}
}
void mostrar_matriz (vector<float>segundos,int n)
{
    cout<<"\n";
    for (int i=0;i<n;i++)
    {
        cout<<segundos [i]<<"\t";
    }
}
int main ()
{
    srand(time(NULL));
    int n;
    float max=20.0, min=10.0;
    cout<<"Ingrese el numero de jugadores: ";
    cin>>n;
    vector<float>segundos (n);

    generar_segundos (segundos,n,max,min);
    cout<<"La lista: ";
    mostrar_matriz (segundos,n);
    ordenamiento (segundos,n);
    cout<<"\n\nLa lista oradenada: ";
    mostrar_matriz (segundos,n);

    return 0;
}