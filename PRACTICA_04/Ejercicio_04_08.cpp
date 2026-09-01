//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 31/08/2026.
# include <iostream>
using namespace std;
int contador_digitos (int numero)
{
    int contador=0;
    while (numero != 0)
    {
        numero/=10;
        contador++;
    }

    return contador;
}
int main ()
{
    int numero;
    cout<<"Ingrese el numero del cual desea contar los digitos: ";
    cin>>numero;

    cout<<"\nEl numero de digitos en este numero es: "<<contador_digitos (numero);

    return 0;
}