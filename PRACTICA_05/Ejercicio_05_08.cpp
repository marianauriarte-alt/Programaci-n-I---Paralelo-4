//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Fecha de creacion: 05/09/2026.
//Numero de ejercicio: 8
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int factorial (int numero)
{
    int factorial = 1;
    for (int i=1;i<=numero;i++)
    {
        factorial *= i;
    }

    return factorial;
}
int main ()
{
    int numero;
    srand(time(NULL));
    numero = (rand()%10-1+1)+1;
    cout<<"el factorial del numero "<<numero<< " es: "<<factorial(numero);

    return 0;
    
}