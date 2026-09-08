//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 3
#include <iostream>
using namespace std;
float preciototal (float precio, float impuesto)
{
    float precio_total, aux;
    if (impuesto == 0)
    {
        impuesto = 0.13;
    }
    else
    {
        impuesto /=100;
    }
    aux=precio*impuesto;
    precio_total=precio+aux;
    return precio_total;
    
}
int main ()
{
    float precio, impuesto;
    cout<<"Ingrese el precio: ";
    cin>>precio;
    cout<<"Ingrese el porcentaje de impuesto: ";
    cin>>impuesto;

    if (impuesto == 0)
    {
        cout<<"\nSe aplico el impuesto de 13%"<<endl;
    }


    cout<<"\nEl precio total es de: "<<preciototal(precio,impuesto);

    return 0;


}