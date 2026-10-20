//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 1

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void Simulacion (vector<string>nombres, vector<string>apellidos,int n)
{
    int nombre, apellido;
    for (int i=0; i<n; i++)
    {
        nombre = (rand() % 10);
        apellido = (rand() % 10);

        cout<<i+1<<". "<<nombres[nombre]<<" "<<apellidos[apellido]<<endl;
    }

}

int main ()
{
    srand(time(NULL));
    vector<string>nombres = {"Valeria","Matias","Leticia","Omar","Lucia","Ivan","Cristal","Camilo","Belen","Alvaro"};
    vector<string>apellidos = {"Uriarte", "Vargas", "Zapata", "Courtz", "Angulo","Luna","Soria","Villarruel","Manrrique","Diaz"};
    int n;
    cout<<"Ingrese n: ";
    cin>>n;

    Simulacion (nombres,apellidos,n);

    return 0;

}