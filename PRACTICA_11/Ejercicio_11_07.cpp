// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto
{
    string nombre;
    string codigo;
    double precio;
};

void analizar_productos (vector<Producto> productos)
{
    int mayor=0, menor=0;

    for (int i=1; i<productos.size(); i++)
    {
        if (productos[i].precio > productos[mayor].precio)
        {
            mayor = i;
        }

        if (productos[i].precio < productos[menor].precio)
        {
            menor = i;
        }
    }

    cout<<"\nPRODUCTO MAS CARO"<<endl;
    cout<<"Nombre: "<<productos[mayor].nombre<<endl;
    cout<<"Precio: "<<productos[mayor].precio<<endl;

    cout<<"\nPRODUCTO MAS BARATO"<<endl;
    cout<<"Nombre: "<<productos[menor].nombre<<endl;
    cout<<"Precio: "<<productos[menor].precio<<endl;
}

int main ()
{
    int n;
    vector<Producto> productos;

    cout<<"Ingrese la cantidad de productos: ";
    cin>>n;

    productos.resize(n);

    cin.ignore();

    for (int i=0; i<n; i++)
    {
        cout<<"\nPRODUCTO "<<i+1<<endl;

        cout<<"Ingrese el nombre: ";
        getline(cin, productos[i].nombre);

        cout<<"Ingrese el codigo: ";
        getline(cin, productos[i].codigo);

        cout<<"Ingrese el precio: ";
        cin>>productos[i].precio;

        cin.ignore();
    }

    analizar_productos (productos);

    return 0;
}
