//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 11
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generar_numero (int &simulacion)
{
    return (simulacion = (rand ()%3-1+1)+1);
}
void tipodeninio (int opcion,int &contador1, int &contador2, int &contador3)
{
    switch (opcion)
    {
        case 1: contador1++;
        break;
        case 2: contador2++;
        break;
        case 3: contador3++;
        break;
        default:
        break;
    }
}
int cantidad_de_paniales (int contador1, int contador2, int contador3)
{
    int cantidad_total;
    cantidad_total= ((contador1*6)+(contador2*3)+(contador3*2));
    return cantidad_total;

}
int main ()
{
    srand (time (NULL));
    int n,opcion,contador1=0,contador2=0,contador3=0;
    cout<<"Ingrese la cantidad de ninios: ";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        generar_numero(opcion);
        tipodeninio (opcion,contador1,contador2,contador3);
    }

    cout<<"\nNinios de 1 anio: "<<contador1<<endl;
    cout<<"Ninios de 2 anio: "<<contador2<<endl;
    cout<<"Ninios de 3 anio: "<<contador3<<endl;

    cout<<"\nLa cantidad total de paniales consumidos es de: "<< cantidad_de_paniales (contador1,contador2,contador3);

    return 0;
}