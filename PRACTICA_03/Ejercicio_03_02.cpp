//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 25/08/2026.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{
    srand(time(NULL));
    int n,suma=0,suma_pares=0,suma_impares=0,suma_primos=0,numero_aleatorio,divisores=0;
    cout<<"Ingrese los n numeros que desea generar: ";
    cin>>n;
    cout<<"\nLos numeros generados son:"<<endl;

    for (int i=1; i<=n; ++i)
    {
        divisores=0;
        numero_aleatorio=(rand()%(100-1+1))+1;
        cout<<numero_aleatorio<<endl;
        suma+=numero_aleatorio;
        if (numero_aleatorio%2==0)
        {
            suma_pares+=numero_aleatorio;
        }
        else 
        {
            suma_impares+=numero_aleatorio;
        }
        for(int j=1;j<=numero_aleatorio;++j)
        {
            if (numero_aleatorio%j==0)
            {
                divisores++;
            }
        }
        if (divisores==2)
        {
            suma_primos+=numero_aleatorio;
        }
    }

    cout<<"\nla suma de todos los numeros es: "<<suma<<endl;
    cout<<"la suma de todos los numeros pares es: "<<suma_pares<<endl;
    cout<<"la suma de todos los numeros impares es: "<<suma_impares<<endl;
    cout<<"la suma de todos los numeros primos es: "<<suma_primos<<endl;

    return 0;

}