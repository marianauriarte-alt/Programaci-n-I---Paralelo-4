// Materia: Programacion I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha de creacion: 20/11/2026.
// Numero de ejercicio: 4
// Archivo: Ejercicio_13_04.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct structEstudiante
{
    char carnet[20];
    char nombres[40];
    char apellidos[40];
    char materia[50];
    int paralelo;
    int pesoAcumulado;
    double notaAcumulada;
    bool tieneNotaMenor;
    bool activo;
};

streamoff BuscarEstudiante(const char carnet[], const char materia[],
                           int paralelo, structEstudiante &estudiante)
{
    ifstream archivo("ESTUDIANTES.BIN", ios::binary);
    streamoff posicion = 0;

    while (archivo.read((char *)&estudiante, sizeof(estudiante)))
    {
        if (estudiante.activo && strcmp(estudiante.carnet, carnet) == 0 &&
            strcmp(estudiante.materia, materia) == 0 && estudiante.paralelo == paralelo)
            return posicion;

        posicion += sizeof(estudiante);
    }
    return -1;
}

streamoff SeleccionarEstudiante(structEstudiante &estudiante)
{
    string carnet, materia;
    int paralelo;

    cout << "Ingrese carnet: ";
    cin >> carnet;
    cout << "Ingrese materia: ";
    getline(cin >> ws, materia);
    cout << "Ingrese paralelo: ";
    if (!(cin >> paralelo))
        return -1;

    streamoff posicion = BuscarEstudiante(carnet.c_str(), materia.c_str(), paralelo, estudiante);
    if (posicion == -1)
        cout << "Estudiante no encontrado en esa materia y paralelo." << endl;

    return posicion;
}

bool ActualizarEstudiante(streamoff posicion, const structEstudiante &estudiante)
{
    fstream archivo("ESTUDIANTES.BIN", ios::binary | ios::in | ios::out);
    archivo.seekp(posicion);
    if (archivo.write((char *)&estudiante, sizeof(estudiante)))
        return true;

    cout << "Error al actualizar el registro." << endl;
    return false;
}

void AdicionarEstudiante()
{
    structEstudiante estudiante = {}, encontrado;

    cout << "Ingrese carnet: ";
    cin >> ws;
    cin.getline(estudiante.carnet, sizeof(estudiante.carnet));
    cout << "Ingrese nombres: ";
    cin.getline(estudiante.nombres, sizeof(estudiante.nombres));
    cout << "Ingrese apellidos: ";
    cin.getline(estudiante.apellidos, sizeof(estudiante.apellidos));
    cout << "Ingrese materia: ";
    cin.getline(estudiante.materia, sizeof(estudiante.materia));

    do
    {
        cout << "Ingrese paralelo: ";
        if (!(cin >> estudiante.paralelo))
            return;
    } while (estudiante.paralelo <= 0);

    if (BuscarEstudiante(estudiante.carnet, estudiante.materia,
                         estudiante.paralelo, encontrado) != -1)
    {
        cout << "El estudiante ya esta registrado en esa materia y paralelo." << endl;
        return;
    }

    estudiante.activo = true;
    ofstream archivo("ESTUDIANTES.BIN", ios::binary | ios::app);
    if (archivo.write((char *)&estudiante, sizeof(estudiante)))
        cout << "Estudiante registrado." << endl;
    else
        cout << "Error al guardar el estudiante." << endl;
}

void AdicionarNota()
{
    structEstudiante estudiante;
    streamoff posicion = SeleccionarEstudiante(estudiante);
    if (posicion == -1)
        return;

    int pesoDisponible = 10000 - estudiante.pesoAcumulado;
    if (pesoDisponible == 0)
    {
        cout << "Ya se registro el 100% de las notas." << endl;
        return;
    }

    double nota, porcentaje;
    do
    {
        cout << "Ingrese nota de 0 a 100: ";
        if (!(cin >> nota))
            return;
    } while (nota < 0 || nota > 100);

    cout << fixed << setprecision(2);
    cout << "Porcentaje disponible: " << pesoDisponible / 100.0 << "%" << endl;

    int peso;
    do
    {
        cout << "Ingrese porcentaje de la nota (hasta dos decimales): ";
        if (!(cin >> porcentaje))
            return;

        peso = 0;
        if (porcentaje > 0 && porcentaje <= 100)
            peso = static_cast<int>(round(porcentaje * 100));

    } while (peso <= 0 || peso > pesoDisponible ||
             fabs(porcentaje * 100 - peso) > 0.000001);

    estudiante.pesoAcumulado += peso;
    estudiante.notaAcumulada += nota * peso / 10000.0;
    if (nota < 60)
        estudiante.tieneNotaMenor = true;

    if (ActualizarEstudiante(posicion, estudiante))
        cout << "Nota registrada." << endl;
}

void EliminarEstudiante()
{
    structEstudiante estudiante;
    streamoff posicion = SeleccionarEstudiante(estudiante);
    if (posicion == -1)
        return;

    estudiante.activo = false;
    if (ActualizarEstudiante(posicion, estudiante))
        cout << "Registro del estudiante eliminado." << endl;
}

void ListarEstudiantes()
{
    ifstream archivo("ESTUDIANTES.BIN", ios::binary);
    structEstudiante estudiante;
    double sumaNotas = 0;
    int cantidadConNotaFinal = 0;

    cout << "\nLISTADO DE HABILITACION" << endl;
    cout << left << setw(13) << "CARNET" << setw(18) << "NOMBRES"
         << setw(18) << "APELLIDOS" << setw(23) << "MATERIA"
         << setw(10) << "PARALELO" << setw(20) << "NOTA HABILITACION"
         << "ESTADO" << endl;

    while (archivo.read((char *)&estudiante, sizeof(estudiante)))
    {
        if (!estudiante.activo)
            continue;

        cout << left << setw(13) << estudiante.carnet << setw(18) << estudiante.nombres
             << setw(18) << estudiante.apellidos << setw(23) << estudiante.materia
             << setw(10) << estudiante.paralelo;

        if (estudiante.pesoAcumulado == 10000)
        {
            cout << fixed << setprecision(1) << setw(20) << estudiante.notaAcumulada;
            sumaNotas += estudiante.notaAcumulada;
            cantidadConNotaFinal++;
        }
        else
            cout << setw(20) << "PENDIENTE";

        if (estudiante.tieneNotaMenor)
            cout << "NO HABILITADO, TIENE UNA NOTA MENOR A 60" << endl;
        else if (estudiante.pesoAcumulado < 10000)
            cout << "PENDIENTE DE NOTAS" << endl;
        else
            cout << "HABILITADO" << endl;
    }

    if (cantidadConNotaFinal > 0)
    {
        cout << "\nPromedio de las notas de habilitacion: "
             << fixed << setprecision(1) << sumaNotas / cantidadConNotaFinal << endl;
    }
    else
        cout << "\nSin notas finales para calcular el promedio." << endl;
}

int main()
{
    int opcion;
    do
    {
        cout << "\nMENU NOTAS UCB" << endl;
        cout << "1. Adicionar estudiante" << endl;
        cout << "2. Listado de estudiantes habilitados" << endl;
        cout << "3. Eliminar un estudiante" << endl;
        cout << "4. Adicionar notas de habilitacion" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion))
            break;

        switch (opcion)
        {
            case 1: AdicionarEstudiante(); break;
            case 2: ListarEstudiantes(); break;
            case 3: EliminarEstudiante(); break;
            case 4: AdicionarNota(); break;
            case 5: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 5);

    return 0;
}