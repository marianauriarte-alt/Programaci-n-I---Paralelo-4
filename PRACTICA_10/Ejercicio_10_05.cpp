//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 5
#include <iostream>
#include <string>
using namespace std;
void ordenamiento (string &palabra)
{
    char aux;
    for (int i=0;i<palabra.size();i++)
    {
        for (int j=0;j<palabra.size()-1;j++)
        {
            if (palabra[j] > palabra[j+1])
            {
                aux = palabra[j+1];
                palabra [j+1] = palabra [j];
                palabra [j] = aux;

            }
        }
    }
}
int main ()
{
    string palabra;
    cout<<"Ingrese una palabra: ";
    cin>>palabra;

    ordenamiento (palabra);
    cout<<palabra;


    return 0;
}