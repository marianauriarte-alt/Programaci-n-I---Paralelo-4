//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 7
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void simulacion_moneda(float &contador_caras,float &contador_cruz)
{
    int aux;
    aux = (rand()%2-1+1)+1;
    if (aux ==1)
    {
        contador_caras++;
    }
    else
    {
        contador_cruz++;
    }
}
int main ()
{
    
    srand(time(NULL));

    int n;
    float contador_caras=0,contador_cruz=0,pc=0,pcz=0;
    cout<<"Ingrese el valor de n: ";
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        simulacion_moneda(contador_caras,contador_cruz);
    }

    cout<<"\nUna vez ejecutado el simulador se pueden ver los siguientes resultados"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Caras: "<<contador_caras<<endl;
    cout<<"Cruz: "<<contador_cruz<<endl;

    pc=(contador_caras/n)*100;
    pcz=(contador_cruz/n)*100;

    cout<<"Los porcentajes son"<<endl;
    cout<<"Caras: "<<pc<<" %"<<endl;
    cout<<"Cruz: "<<pcz<<"%"<<endl;

    return 0;
}