//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 30/08/2026.
#include <iostream>
using namespace std;
int encontar_el_mayor(int numero_1, int numero_2, int numero_3)
{
    if (numero_1>numero_2 && numero_1>numero_3)
    {
        cout<<"\nEl numero mayor es: "<<numero_1;
    }
    else if (numero_2>numero_1 && numero_2>numero_3)
    {
        cout<<"\nEl numero mayor es: "<<numero_2;
    }
    else 
    {
        cout<<"\nEl numero mayor es: "<<numero_3;
    }

    return 0;
}
int main ()
{
    int numero_1,numero_2,numero_3;
    
    cout<<"ingrese el primer numero: ";
    cin>>numero_1;
    cout<<"ingrese el segundo numero: ";
    cin>>numero_2;
    cout<<"ingrese el tercer numero: ";
    cin>>numero_3;

    encontar_el_mayor (numero_1,numero_2,numero_3);

    return 0;
}