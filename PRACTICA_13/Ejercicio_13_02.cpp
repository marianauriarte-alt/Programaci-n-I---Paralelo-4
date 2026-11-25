// Materia: Programacion I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha de creacion: 20/11/2026.
// Numero de ejercicio: 2
// Archivo: Ejercicio_13_02.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

struct structProducto
{
    int codigo;
    char nombre[60];
    int cantidadInicial;
    double precio;
};

streamoff BuscarCodigo(int codigo, structProducto &producto)
{
    ifstream archivo("PRODUCTOS.BIN", ios::binary);
    streamoff posicion = 0;

    while (archivo.read((char *)&producto, sizeof(producto)))
    {
        if (producto.codigo == codigo)
            return posicion;
        posicion += sizeof(producto);
    }
    return -1;
}

int CantidadVendida(int codigo)
{
    ifstream archivo("VENTAS.txt");
    string linea, ci, nombre;
    int codigoVenta, cantidad, total = 0;
    char separador;

    while (getline(archivo, linea))
    {
        istringstream venta(linea);
        if (getline(venta, ci, ';') && getline(venta, nombre, ';') &&
            venta >> codigoVenta >> separador >> cantidad)
        {
            if (separador == ';' && codigoVenta == codigo)
                total += cantidad;
        }
    }
    return total;
}

bool LeerDatos(structProducto &producto, int vendida)
{
    cout << "Ingrese nombre del producto: ";
    cin >> ws;
    cin.getline(producto.nombre, sizeof(producto.nombre));

    do
    {
        cout << "Ingrese cantidad inicial (minimo " << vendida << "): ";
        if (!(cin >> producto.cantidadInicial))
            return false;
    } while (producto.cantidadInicial < vendida);

    do
    {
        cout << "Ingrese precio unitario: ";
        if (!(cin >> producto.precio))
            return false;
    } while (producto.precio <= 0);

    return true;
}

void AdicionarProducto()
{
    structProducto producto = {}, encontrado;
    cout << "Ingrese codigo del producto: ";
    if (!(cin >> producto.codigo))
        return;

    if (BuscarCodigo(producto.codigo, encontrado) != -1)
    {
        cout << "El codigo ya esta registrado." << endl;
        return;
    }

    if (LeerDatos(producto, 0))
    {
        ofstream archivo("PRODUCTOS.BIN", ios::binary | ios::app);
        if (archivo.write((char *)&producto, sizeof(producto)))
            cout << "Producto registrado." << endl;
        else
            cout << "Error al guardar el producto." << endl;
    }
}

void MostrarCabecera()
{
    cout << left << setw(10) << "CODIGO" << setw(25) << "NOMBRE PRODUCTO"
         << setw(18) << "CANTIDAD INICIAL" << setw(12) << "PRECIO"
         << setw(18) << "CANTIDAD VENDIDA" << "TOTAL" << endl;
}

void MostrarProducto(const structProducto &producto)
{
    int vendida = CantidadVendida(producto.codigo);

    cout << left << setw(10) << producto.codigo << setw(25) << producto.nombre
         << setw(18) << producto.cantidadInicial << fixed << setprecision(2)
         << setw(12) << producto.precio << setw(18) << vendida
         << producto.precio * vendida << endl;
}

void ListarProductos()
{
    ifstream archivo("PRODUCTOS.BIN", ios::binary);
    structProducto producto;
    MostrarCabecera();

    while (archivo.read((char *)&producto, sizeof(producto)))
        MostrarProducto(producto);
}

void BuscarProducto()
{
    structProducto producto;
    int codigo;

    cout << "Ingrese codigo a buscar: ";
    if (!(cin >> codigo))
        return;

    if (BuscarCodigo(codigo, producto) == -1)
        cout << "Producto no encontrado." << endl;
    else
    {
        MostrarCabecera();
        MostrarProducto(producto);
    }
}

void ModificarProducto()
{
    structProducto producto;
    int codigo;

    cout << "Ingrese codigo a modificar: ";
    if (!(cin >> codigo))
        return;

    streamoff posicion = BuscarCodigo(codigo, producto);
    if (posicion == -1)
    {
        cout << "Producto no encontrado." << endl;
        return;
    }

    if (LeerDatos(producto, CantidadVendida(codigo)))
    {
        fstream archivo("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
        archivo.seekp(posicion);
        if (archivo.write((char *)&producto, sizeof(producto)))
            cout << "Producto modificado." << endl;
        else
            cout << "Error al modificar el producto." << endl;
    }
}

void AdicionarVenta()
{
    structProducto producto;
    string ci, nombre;
    int codigo, cantidad;

    cout << "Ingrese codigo del producto: ";
    if (!(cin >> codigo))
        return;

    if (BuscarCodigo(codigo, producto) == -1)
    {
        cout << "Producto no encontrado." << endl;
        return;
    }

    int disponible = producto.cantidadInicial - CantidadVendida(codigo);
    cout << "Cantidad disponible: " << disponible << endl;
    if (disponible == 0)
        return;

    cout << "Ingrese CI del cliente: ";
    cin >> ci;
    cout << "Ingrese nombre del cliente: ";
    getline(cin >> ws, nombre);
    if (ci.find(';') != string::npos || nombre.find(';') != string::npos)
    {
        cout << "El CI y el nombre deben escribirse sin punto y coma." << endl;
        return;
    }

    cout << "Ingrese cantidad comprada: ";
    if (!(cin >> cantidad))
        return;

    if (cantidad <= 0 || cantidad > disponible)
    {
        cout << "Cantidad de venta incorrecta." << endl;
        return;
    }

    ofstream archivo("VENTAS.txt", ios::app);
    if (archivo << ci << "; " << nombre << "; " << codigo << "; " << cantidad << '\n')
        cout << "Venta registrada." << endl;
    else
        cout << "Error al guardar la venta." << endl;
}

int main()
{
    int opcion;
    do
    {
        cout << "\nMENU NOTAS UCB - FARMACIAS CHAVEZ" << endl;
        cout << "1. Adicionar producto" << endl;
        cout << "2. Listado de productos" << endl;
        cout << "3. Buscar un producto por codigo" << endl;
        cout << "4. Modificar un producto" << endl;
        cout << "5. Adicionar venta del producto" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion))
            break;

        switch (opcion)
        {
            case 1: AdicionarProducto(); break;
            case 2: ListarProductos(); break;
            case 3: BuscarProducto(); break;
            case 4: ModificarProducto(); break;
            case 5: AdicionarVenta(); break;
            case 6: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 6);

    return 0;
}