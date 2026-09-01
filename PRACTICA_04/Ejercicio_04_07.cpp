#include <iostream>
using namespace std;
int calculo_mru(int velocidad,int tiempo)
{
    int distancia;
    distancia = velocidad * tiempo;

    return distancia;
}
int main ()
{
    int velocidad,tiempo;
    cout<<"Ingrese la velocidad constante: ";
    cin>>velocidad;
    cout<<"Ingrese el tiempo: ";
    cin>>tiempo;

    cout<<"\nEl calculo de la distancia es: "<<calculo_mru (velocidad,tiempo);

    return 0;
}