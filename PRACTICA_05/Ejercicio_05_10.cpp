//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 10
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int generar_numero ()
{
    int numero;
    numero = (rand()%1000-1+1)+1;
    return numero;
}

int SumaPares (int numero, int &suma_pares)
{
    suma_pares+=numero;
    return suma_pares;
}

float Promedio (float contador_impares,float n)
{
    float promedio;
    return (promedio = contador_impares/n)*100;
}

int N_Primo (int numero,int &primomayor )
{
    if (numero>primomayor)
    {
        primomayor=numero;
    }

    return primomayor;
}


int main ()
{
    int numero,n,suma_pares=0,divisores=0,primomayor;
    float contador_impares=0,promedio=0;
    srand(time(NULL));
    cout<<"Ingrese N: ";
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        numero = generar_numero ();
        cout<<i<<". "<<numero<<endl;

        divisores = 0;

        if (numero%2==0)
        {
            SumaPares(numero,suma_pares);
        }
        else 
        {
            contador_impares++;
        }

        for (int j=1;j<=numero;j++)
        {
            if (numero % j==0)
            {
                divisores++;
            }
        }
        
        if (divisores==2)
        {
            N_Primo(numero,primomayor);
        }
    }

    promedio = Promedio (contador_impares,n);

    cout<<"\nSuma de los numeros pares: "<<suma_pares<<endl;
    cout<<"Promedio de impares: "<<promedio<<"%"<<endl;
    cout<<"Primo: "<<primomayor;

    return 0;
    
}