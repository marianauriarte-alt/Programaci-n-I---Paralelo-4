// Materia: Programacion I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha de creacion: 20/11/2026.
// Numero de ejercicio: 1
// Archivo: Ejercicio_13_01.cpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct structEstudiante
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct structNotas
{
    char ci[10];
    char materia[30];
    int nota;
};

void LeerTexto(const char *mensaje, char destino[], int capacidad)
{
    string texto;
    do
    {
        cout << mensaje;
        if (!getline(cin >> ws, texto))
            return;

        if (texto.size() < capacidad)
        {
            strcpy(destino, texto.c_str());
            return;
        }
        cout << "Ingrese hasta " << capacidad - 1 << " caracteres." << endl;
    } while (cin);
}

bool ExisteEstudiante(const char ci[])
{
    ifstream archivo("Estudiantes.bin", ios::binary);
    structEstudiante estudiante;

    while (archivo.read((char *)&estudiante, sizeof(estudiante)))
    {
        if (strcmp(ci, estudiante.ci) == 0)
            return true;
    }
    return false;
}

bool ExisteNota(const char ci[], const char materia[])
{
    ifstream archivo("Notas.bin", ios::binary);
    structNotas registro;

    while (archivo.read((char *)&registro, sizeof(registro)))
    {
        if (strcmp(ci, registro.ci) == 0 && strcmp(materia, registro.materia) == 0)
            return true;
    }
    return false;
}

void IngresarEstudiante()
{
    structEstudiante estudiante = {};

    LeerTexto("Ingrese CI: ", estudiante.ci, sizeof(estudiante.ci));
    if (ExisteEstudiante(estudiante.ci))
    {
        cout << "Ya existe un estudiante con ese CI." << endl;
        return;
    }

    LeerTexto("Ingrese nombres: ", estudiante.nombres, sizeof(estudiante.nombres));
    LeerTexto("Ingrese apellidos: ", estudiante.apellidos, sizeof(estudiante.apellidos));
    if (!cin)
        return;

    ofstream archivo("Estudiantes.bin", ios::binary | ios::app);
    if (archivo.write((char *)&estudiante, sizeof(estudiante)))
        cout << "Estudiante registrado." << endl;
    else
        cout << "Error al guardar el estudiante." << endl;
}

void IngresarNota()
{
    structNotas registro = {};

    LeerTexto("Ingrese CI del estudiante: ", registro.ci, sizeof(registro.ci));
    if (!ExisteEstudiante(registro.ci))
    {
        cout << "El estudiante no esta registrado." << endl;
        return;
    }

    LeerTexto("Ingrese materia: ", registro.materia, sizeof(registro.materia));
    if (ExisteNota(registro.ci, registro.materia))
    {
        cout << "El estudiante ya tiene una nota en esa materia." << endl;
        return;
    }

    do
    {
        cout << "Ingrese nota de 0 a 100: ";
        if (!(cin >> registro.nota))
            return;
    } while (registro.nota < 0 || registro.nota > 100);

    ofstream archivo("Notas.bin", ios::binary | ios::app);
    if (archivo.write((char *)&registro, sizeof(registro)))
        cout << "Nota registrada." << endl;
    else
        cout << "Error al guardar la nota." << endl;
}

void MostrarReporte()
{
    ifstream estudiantes("Estudiantes.bin", ios::binary);
    structEstudiante estudiante;
    bool hayEstudiantes = false;

    while (estudiantes.read((char *)&estudiante, sizeof(estudiante)))
    {
        hayEstudiantes = true;
        cout << "\nCI: " << estudiante.ci << endl;
        cout << "Estudiante: " << estudiante.nombres << " "
             << estudiante.apellidos << endl;

        ifstream notas("Notas.bin", ios::binary);
        structNotas registro;
        bool tieneNotas = false;

        while (notas.read((char *)&registro, sizeof(registro)))
        {
            if (strcmp(estudiante.ci, registro.ci) == 0)
            {
                cout << registro.materia << ": " << registro.nota << endl;
                tieneNotas = true;
            }
        }

        if (!tieneNotas)
            cout << "Sin notas registradas." << endl;
    }

    if (!hayEstudiantes)
        cout << "No hay estudiantes registrados." << endl;
}

int main()
{
    int opcion;
    do
    {
        cout << "\nMENU DE ESTUDIANTES" << endl;
        cout << "1. Ingreso de datos de estudiantes" << endl;
        cout << "2. Ingreso de materias y notas" << endl;
        cout << "3. Reporte de estudiantes y notas" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion))
            break;

        switch (opcion)
        {
            case 1: IngresarEstudiante(); break;
            case 2: IngresarNota(); break;
            case 3: MostrarReporte(); break;
            case 4: break;
            default: cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 4);

    return 0;
}