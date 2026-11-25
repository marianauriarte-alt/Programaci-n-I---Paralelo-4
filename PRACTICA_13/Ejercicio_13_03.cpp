// Materia: Programacion I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha de creacion: 20/11/2026.
// Numero de ejercicio: 3
// Archivo: Ejercicio_13_03.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

struct structPizza
{
    int codigo;
    char nombre[50];
    char tipo[15];
    char tamano[20];
    double precio;
    bool activa;
};

streamoff BuscarCodigo(int codigo, structPizza &pizza)
{
    ifstream archivo("PRODUCTO.BIN", ios::binary);
    streamoff posicion = 0;

    while (archivo.read((char *)&pizza, sizeof(pizza)))
    {
        if (pizza.codigo == codigo)
            return posicion;
        posicion += sizeof(pizza);
    }
    return -1;
}

streamoff SeleccionarPizza(structPizza &pizza)
{
    int codigo;
    cout << "Ingrese codigo de la pizza: ";
    if (!(cin >> codigo))
        return -1;

    streamoff posicion = BuscarCodigo(codigo, pizza);
    if (posicion == -1 || !pizza.activa)
    {
        cout << "Pizza no encontrada en el catalogo." << endl;
        return -1;
    }
    return posicion;
}

bool IngresarPrecio(structPizza &pizza)
{
    double precioBase;
    do
    {
        cout << "Ingrese precio tradicional de este tamano en Bs: ";
        if (!(cin >> precioBase))
            return false;
    } while (precioBase <= 0);

    pizza.precio = precioBase;
    if (strcmp(pizza.tipo, "ESPECIAL") == 0)
        pizza.precio = precioBase * 1.10;

    return true;
}

void AdicionarPizza()
{
    structPizza pizza = {}, encontrada;
    int tipo, tamano;
    const char tamanos[5][20] = {"XS", "MEDIANA", "GRANDE", "FAMILIAR", "INTERMINABLE"};

    cout << "Ingrese codigo: ";
    if (!(cin >> pizza.codigo))
        return;

    if (BuscarCodigo(pizza.codigo, encontrada) != -1)
    {
        cout << "Ese codigo ya fue utilizado." << endl;
        return;
    }

    cout << "Ingrese nombre: ";
    cin >> ws;
    cin.getline(pizza.nombre, sizeof(pizza.nombre));

    do
    {
        cout << "Tipo (1. Tradicional, 2. Especial): ";
        if (!(cin >> tipo))
            return;
    } while (tipo < 1 || tipo > 2);

    if (tipo == 1)
        strcpy(pizza.tipo, "TRADICIONAL");
    else
        strcpy(pizza.tipo, "ESPECIAL");

    do
    {
        cout << "Tamano (1. XS, 2. Mediana, 3. Grande, 4. Familiar, 5. Interminable): ";
        if (!(cin >> tamano))
            return;
    } while (tamano < 1 || tamano > 5);

    strcpy(pizza.tamano, tamanos[tamano - 1]);
    if (!IngresarPrecio(pizza))
        return;

    pizza.activa = true;
    ofstream archivo("PRODUCTO.BIN", ios::binary | ios::app);
    if (archivo.write((char *)&pizza, sizeof(pizza)))
        cout << "Pizza registrada." << endl;
    else
        cout << "Error al guardar la pizza." << endl;
}

int CantidadVendida(const structPizza &pizza)
{
    ifstream archivo("VENTAS.TXT");
    string linea, ci, tamano;
    int codigo, cantidad, total = 0;
    char separador;

    while (getline(archivo, linea))
    {
        istringstream venta(linea);
        if (getline(venta, ci, ';') && venta >> codigo >> separador &&
            separador == ';' && getline(venta >> ws, tamano, ';') && venta >> cantidad)
        {
            if (codigo == pizza.codigo && tamano == pizza.tamano)
                total += cantidad;
        }
    }
    return total;
}

void ListarPizzas()
{
    ifstream archivo("PRODUCTO.BIN", ios::binary);
    structPizza pizza;

    cout << "\nLISTADO DE PIZZAS" << endl;
    cout << left << setw(9) << "CODIGO" << setw(22) << "NOMBRE"
         << setw(15) << "TIPO" << setw(16) << "TAMANO" << setw(12) << "PRECIO"
         << setw(12) << "CANTIDAD" << "TOTAL" << endl;

    while (archivo.read((char *)&pizza, sizeof(pizza)))
    {
        if (pizza.activa)
        {
            int cantidad = CantidadVendida(pizza);
            cout << left << setw(9) << pizza.codigo << setw(22) << pizza.nombre
                 << setw(15) << pizza.tipo << setw(16) << pizza.tamano
                 << fixed << setprecision(2) << setw(12) << pizza.precio
                 << setw(12) << cantidad << pizza.precio * cantidad << endl;
        }
    }
}

bool ActualizarPizza(streamoff posicion, const structPizza &pizza)
{
    fstream archivo("PRODUCTO.BIN", ios::binary | ios::in | ios::out);
    archivo.seekp(posicion);
    if (archivo.write((char *)&pizza, sizeof(pizza)))
        return true;

    cout << "Error al actualizar el catalogo." << endl;
    return false;
}

void ModificarPrecio()
{
    structPizza pizza;
    streamoff posicion = SeleccionarPizza(pizza);
    if (posicion != -1 && IngresarPrecio(pizza) && ActualizarPizza(posicion, pizza))
        cout << "Precio modificado." << endl;
}

void EliminarPizza()
{
    structPizza pizza;
    streamoff posicion = SeleccionarPizza(pizza);
    if (posicion == -1)
        return;

    pizza.activa = false;
    if (ActualizarPizza(posicion, pizza))
        cout << "Pizza eliminada." << endl;
}

void AdicionarVenta()
{
    structPizza pizza;
    string ci;
    int cantidad;

    if (SeleccionarPizza(pizza) == -1)
        return;

    cout << pizza.nombre << " - " << pizza.tamano << endl;
    cout << "Ingrese carnet del cliente: ";
    cin >> ci;
    if (ci.find(';') != string::npos)
    {
        cout << "Carnet incorrecto." << endl;
        return;
    }

    do
    {
        cout << "Ingrese cantidad de pizzas vendidas: ";
        if (!(cin >> cantidad))
            return;
    } while (cantidad <= 0);

    ofstream archivo("VENTAS.TXT", ios::app);
    if (archivo << ci << ';' << pizza.codigo << ';' << pizza.tamano << ';' << cantidad << '\n')
        cout << "Venta registrada." << endl;
    else
        cout << "Error al guardar la venta." << endl;
}

int main()
{
    int opcion;
    do
    {
        cout << "\nMENU PIZZERIA ELIS" << endl;
        cout << "1. Adicionar pizza" << endl;
        cout << "2. Listado de pizzas" << endl;
        cout << "3. Modificar precio por codigo" << endl;
        cout << "4. Eliminar una pizza" << endl;
        cout << "5. Adicionar venta de pizzas" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion))
            break;

        switch (opcion)
        {
            case 1: AdicionarPizza(); break;
            case 2: ListarPizzas(); break;
            case 3: ModificarPrecio(); break;
            case 4: EliminarPizza(); break;
            case 5: AdicionarVenta(); break;
            case 6: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 6);

    return 0;
}