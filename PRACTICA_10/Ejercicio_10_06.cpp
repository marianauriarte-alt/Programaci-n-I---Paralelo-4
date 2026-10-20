//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 6
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
void Generar_nombres (vector<string>&alumnos,int n)
{
    int nombre;
    vector<string>nombres = {"Valeria","Matias","Leticia","Omar","Lucia","Ivan","Cristal","Camilo","Belen","Alvaro"};
    for (int i=0;i<n;i++)
    {
        nombre = (rand()%10);
        alumnos[i]=nombres[nombre];
    }
}
void mostrar_vector (vector<string>alumnos,int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<alumnos[i]<<"\t";
    }
}
void ordenamiento (vector<string>&alumnos,int n)
{
    string nombre;
    int posicion;
    for (int i=0;i<n;i++)
    {
        posicion = n-1;
        while (posicion>0)
        {
            if (alumnos [posicion] < alumnos [posicion-1])
            {
                nombre=alumnos[posicion];
                alumnos[posicion]=alumnos[posicion-1];
                alumnos[posicion-1]=nombre;
            }
            posicion--;
        }
    }
}

int main ()
{
    srand(time(NULL));
    int n;

    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;

    vector<string>alumnos (n);

    Generar_nombres(alumnos,n);
    cout<<"Lista de los Alumnos: "<<endl;
    mostrar_vector(alumnos,n);

    ordenamiento (alumnos,n);
    cout<<"\nLista de los Alumnos ordenada: "<<endl;
    mostrar_vector(alumnos,n);


    return 0;
}