// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tarea
{
    string descripcion;
    bool completada;
};

void mostrar_pendientes (vector<Tarea> tareas)
{
    cout<<"\nTAREAS PENDIENTES"<<endl;

    for (int i=0; i<tareas.size(); i++)
    {
        if (tareas[i].completada == false)
        {
            cout<<i+1<<". "<<tareas[i].descripcion<<endl;
        }
    }
}

void completar_tarea (vector<Tarea> &tareas, int indice)
{
    if (indice >= 1 && indice <= tareas.size())
    {
        tareas[indice-1].completada = true;

        cout<<"\nTarea completada correctamente."<<endl;
    }
    else
    {
        cout<<"\nIndice no valido."<<endl;
    }
}

int main ()
{
    int n, opcion, indice;
    vector<Tarea> tareas;

    cout<<"Ingrese la cantidad de tareas: ";
    cin>>n;

    tareas.resize(n);

    cin.ignore();

    for (int i=0; i<n; i++)
    {
        cout<<"Ingrese la descripcion de la tarea "<<i+1<<": ";
        getline(cin, tareas[i].descripcion);

        tareas[i].completada = false;
    }

    do
    {
        cout<<"\nMENU DE TAREAS"<<endl;
        cout<<"1. Mostrar tareas pendientes"<<endl;
        cout<<"2. Completar una tarea"<<endl;
        cout<<"3. Salir"<<endl;

        cout<<"\nIngrese una opcion: ";
        cin>>opcion;

        if (opcion == 1)
        {
            mostrar_pendientes (tareas);
        }
        else if (opcion == 2)
        {
            mostrar_pendientes (tareas);

            cout<<"\nIngrese el numero de la tarea: ";
            cin>>indice;

            completar_tarea (tareas, indice);
        }
        else if (opcion == 3)
        {
            cout<<"\nSaliendo del programa..."<<endl;
        }
        else
        {
            cout<<"\nOpcion no valida."<<endl;
        }

    } while (opcion != 3);

    return 0;
}
