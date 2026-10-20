//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 4
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void generar_precios (vector<double>&precios,int n)
{
    for (int i=0;i<n;i++)
    {
        precios [i] = 5.0+(double)rand()/RAND_MAX * (150.0-5.0);
    }
}

void mostrar_matriz (vector<double>segundos,int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<segundos [i]<<"\t";
    }
}

void ordenamiento (vector<double>&precios, int n)
{
    double min,aux;
    for (int i=0;i<n;i++)
    {
        min=i;
        for (int j=i+1;j<n;j++)
        {
            if (precios[j]<precios[min])
            {
                min=j;
            }
        }
        aux=precios[i];
        precios[i]=precios[min];
        precios [min]=aux;
    }
}

double Promedio (vector<double>precios,int n)
{
    double sum,mediana;

    for (int i=0;i<n;i++)
    {
        sum+=precios[i];
    }

    mediana=sum/n;

    return mediana;
}

int main ()
{
    srand(time(NULL));
    int n;
    cout<<"Ingrese n: ";
    cin>>n;

    vector<double>precios (n);

    double Producto_masbarato, Producto_mascaro,Mediana;

    generar_precios (precios,n);
    mostrar_matriz(precios,n);
    ordenamiento (precios,n);
    cout<<"\n";
    mostrar_matriz(precios,n);

    Producto_masbarato = precios [0];
    cout<<"\nEl producto mas barato de la lista es: "<<Producto_masbarato<<endl;

    Producto_mascaro = precios [n-1];
    cout<<"El producto mas caro de la lista es: "<<Producto_mascaro<<endl;

    Mediana=Promedio(precios,n);
    cout<<"La mediana es: "<<Mediana;

    return 0;

}