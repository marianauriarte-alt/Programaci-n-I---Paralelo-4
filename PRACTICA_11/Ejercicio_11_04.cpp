// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <cstring>
using namespace std;

struct Paquete
{
    string codigoRastreo;
    char direccion[50];
    double pesoKg;
    char estado[20];
};

void entregar (Paquete &paquete)
{
    strcpy(paquete.estado, "Entregado");

    cout<<"\nRECIBO DEL PAQUETE"<<endl;
    cout<<"Codigo de rastreo: "<<paquete.codigoRastreo<<endl;
    cout<<"Direccion: "<<paquete.direccion<<endl;
    cout<<"Peso: "<<paquete.pesoKg<<" kg"<<endl;
    cout<<"Estado: "<<paquete.estado<<endl;
}

int main ()
{
    Paquete paquete;

    cout<<"Ingrese el codigo de rastreo: ";
    cin>>paquete.codigoRastreo;

    cin.ignore();

    cout<<"Ingrese la direccion: ";
    cin.getline(paquete.direccion, 50);

    cout<<"Ingrese el peso en Kg: ";
    cin>>paquete.pesoKg;

    strcpy(paquete.estado, "En Transito");

    cout<<"\nEstado inicial: "<<paquete.estado<<endl;

    entregar (paquete);

    cout<<"\nBytes que ocupa la estructura: "<<sizeof(paquete);

    return 0;
}
