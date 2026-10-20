//Materia: Programacion I, Parelelo 4
//Autor: Mariana Valeria Uriarte Guzman
//Fecha de creacion: 14/10/2026
//Numero de ejercicio: 7
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
void Generar_notas (int notas [5][3])
{
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<3;j++)
        {
            notas [i][j] = (rand()%100-1+1)+1;
        }
    }
}


void promedio (int notas [5][3],vector<float>&promedios)
{
    int sum;
    float prom;
    for (int i=0;i<5;i++)
    {
        sum=0;
        prom=0;
        for (int j=0;j<3;j++)
        {
            sum+=notas[i][j];
        }

        prom = sum/3.0;
        promedios[i] = prom;
    }
}

void mostrar_boletin (vector<string>alumnos, int notas [5][3],vector<float>promedios)
{
    for (int i=0;i<5;i++)
    {
        cout<<endl;
        cout<<"Alumno "<<i+1<<" :"<<alumnos [i]<<endl;
        for (int j=0;j<3;j++)
        {
            cout<<"nota "<<j+1<<" :"<<notas [i][j]<<endl;
        }
        cout<<"La nota final es: "<<promedios [i]<<endl;
    }
}


void ordenamiento (vector<string>&alumnos, int notas [5][3], vector<float>&promedios)
{
    int min, auxiliar_nota;
    string auxiliar_nombre;
    float auxiliar_promedio;

    for (int i=0;i<5;i++)
    {
        min=i;
        for (int j=i+1;j<5;j++)
        {
            if (alumnos[j]<alumnos[min])
            {
                min = j;
            }
        }
        auxiliar_nombre = alumnos [i];
        alumnos [i]=alumnos [min];
        alumnos [min]=auxiliar_nombre;

        for (int k=0;k<3;k++)
        {
            auxiliar_nota = notas [i][k];
            notas [i][k]=notas[min][k];
            notas [min][k]= auxiliar_nota;
        }

        auxiliar_promedio = promedios [i];
        promedios [i] = promedios [min];
        promedios [min]=auxiliar_promedio;

    }
}

int main ()
{
    srand(time(NULL));

    vector<string>alumnos = {"Valentin","Jaqueline","Mateo","Leonardo","Alejandra"};
    int notas [5][3];
    vector<float>promedios(5);

    Generar_notas(notas);
    promedio (notas,promedios);

    ordenamiento(alumnos,notas,promedios);

    cout<<"BOLETINES"<<endl;
    cout<<"========================"<<endl;
    mostrar_boletin (alumnos,notas,promedios);



    return 0;

}
