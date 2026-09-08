//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 9
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void primo (int numero,int &contador_primos)
{
    int contdiv=0;
    for (int i=1;i<=numero;i++)
    {
        if (numero%i==0)
        {
            contdiv++;
        }
    }
    if (contdiv==2)
    {
        contador_primos++;
    }
}
int main ()
{
    int numero,n;
    int contador_primos=0;
    srand(time(NULL));

    cout<<"Ingrese el valor de n: "<<endl;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        numero = (rand()%10000-1+1)+1;
        cout<<i<<". "<<numero<<endl;
        primo (numero,contador_primos);
    }

    cout<<"El numero de primos es: "<<contador_primos;
    return 0;
    
}