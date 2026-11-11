// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contacto
{
    string nombreCompleto;
    int telefono;
};

void buscar_contacto (vector<Contacto> contactos, string busqueda)
{
    cout<<"\nRESULTADOS DE LA BUSQUEDA"<<endl;

    for (int i=0; i<contactos.size(); i++)
    {
        if (contactos[i].nombreCompleto.find(busqueda) != string::npos)
        {
            cout<<"\nNombre: "<<contactos[i].nombreCompleto<<endl;
            cout<<"Telefono: "<<contactos[i].telefono<<endl;
        }
    }
}

int main ()
{
    int n;
    string busqueda;
    vector<Contacto> contactos;

    cout<<"Ingrese la cantidad de contactos: ";
    cin>>n;

    contactos.resize(n);

    cin.ignore();

    for (int i=0; i<n; i++)
    {
        cout<<"\nCONTACTO "<<i+1<<endl;

        cout<<"Ingrese el nombre completo: ";
        getline(cin, contactos[i].nombreCompleto);

        cout<<"Ingrese el telefono: ";
        cin>>contactos[i].telefono;

        cin.ignore();
    }

    cout<<"\nIngrese el nombre que desea buscar: ";
    getline(cin, busqueda);

    buscar_contacto (contactos, busqueda);

    return 0;
}
