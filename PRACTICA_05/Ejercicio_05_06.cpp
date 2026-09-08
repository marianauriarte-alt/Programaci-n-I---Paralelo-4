//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 6
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void agregarNota(double &sumaTotal, int &cantidadNotas, double nuevaNota)
{
    nuevaNota=(rand()%100-1+1)+1;
    sumaTotal+=nuevaNota;
    cantidadNotas++;
}
int main ()
{
    srand(time(NULL));
    double sumaTotal=0;
    int cantidadNotas=0,n; 
    double nuevaNota;

    cout<<"Ingrese el valor de n: ";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        agregarNota (sumaTotal,cantidadNotas,nuevaNota);
    }
    cout<<"Suma total: "<<sumaTotal<<endl;
    cout<<"Cantidad de Notas: "<<cantidadNotas<<endl;


    return 0; 
}