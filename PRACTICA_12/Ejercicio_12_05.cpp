// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 16/11/2026
// Número de ejercicio: 5

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void actualizarProducto() 
{
    ifstream archivoLectura("productos.txt");
    if (!archivoLectura.is_open()) 
    {
        cout << "No se pudo abrir el archivo 'productos.txt'.\n";
        return;
    }

    string productoBuscado;
    float nuevoPrecio;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> productoBuscado;
    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;

    vector<string> productos;
    vector<float> precios;
    string prod;
    float prec;
    bool encontrado = false;

    while (archivoLectura >> prod >> prec) 
    {
        if (prod == productoBuscado) 
        {
            prec = nuevoPrecio;
            encontrado = true;
        }
        productos.push_back(prod);
        precios.push_back(prec);
    }
    archivoLectura.close();

    if (!encontrado) 
    {
        cout << "El producto '" << productoBuscado << "' no existe en el archivo.\n";
        return;
    }

    ofstream archivoEscritura("productos.txt");
    for (size_t i = 0; i < productos.size(); i++) 
    {
        archivoEscritura << productos[i] << " " << precios[i] << endl;
    }
    archivoEscritura.close();

    cout << "Precio actualizado exitosamente.\n";
}

int main() 
{
    actualizarProducto();
    return 0;
}
