// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Estudiante
{
    string nombres;
    int notaFinal;
};

void filtrar_estudiantes (vector<Estudiante> estudiantes)
{
    cout<<"\nESTUDIANTES APROBADOS"<<endl;

    for (int i=0; i<estudiantes.size(); i++)
    {
        if (estudiantes[i].notaFinal >= 60)
        {
            cout<<estudiantes[i].nombres<<" - Nota: ";
            cout<<estudiantes[i].notaFinal<<endl;
        }
    }

    cout<<"\nESTUDIANTES REPROBADOS"<<endl;

    for (int i=0; i<estudiantes.size(); i++)
    {
        if (estudiantes[i].notaFinal < 60)
        {
            cout<<estudiantes[i].nombres<<" - Nota: ";
            cout<<estudiantes[i].notaFinal<<endl;
        }
    }
}

int main ()
{
    int n;
    vector<Estudiante> estudiantes;

    srand(time(0));

    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;

    estudiantes.resize(n);

    cin.ignore();

    for (int i=0; i<n; i++)
    {
        cout<<"\nIngrese el nombre del estudiante "<<i+1<<": ";
        getline(cin, estudiantes[i].nombres);

        estudiantes[i].notaFinal = rand() % 101;

        cout<<"Nota generada: "<<estudiantes[i].notaFinal<<endl;
    }

    filtrar_estudiantes (estudiantes);

    return 0;
}
