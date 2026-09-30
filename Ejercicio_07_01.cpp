// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void generarVoltajes() 
{
    vector<double> v(100);
    cout << "=== a. Voltajes (20.0 - 220.0) ===\n";
    for (int i = 0; i < 100; i++) 
    {
        v[i] = 20.0 + ((double)rand() / RAND_MAX) * (220.0 - 20.0);
        cout << v[i] << "V ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarTemperaturas() 
{
    vector<double> t(50);
    cout << "=== b. Temperaturas (0.0 - 100.0) ===\n";
    for (int i = 0; i < 50; i++) 
    {
        t[i] = ((double)rand() / RAND_MAX) * 100.0;
        cout << t[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarCaracteres() 
{
    vector<char> c(30);
    char alfa[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    cout << "=== c. Caracteres ===\n";
    for (int i = 0; i < 30; i++) 
    {
        c[i] = alfa[rand() % 62];
        cout << c[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarAnios() 
{
    vector<int> a(100);
    cout << "=== d. Anios (1990 - 2025) ===\n";
    for (int i = 0; i < 100; i++) 
    {
        a[i] = 1990 + rand() % (2025 - 1990 + 1);
        cout << a[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarVelocidades() 
{
    vector<double> vel(32);
    cout << "=== e. Velocidades (10.0 - 300.0) ===\n";
    for (int i = 0; i < 32; i++) 
    {
        vel[i] = 10.0 + ((double)rand() / RAND_MAX) * (300.0 - 10.0);
        cout << vel[i] << " ";
        if ((i + 1) % 8 == 0) cout << endl;
    }
    cout << endl;
}

void generarDistancias() 
{
    vector<double> d(1000);
    cout << "=== f. Distancias (Primeros 20 elementos) ===\n";
    for (int i = 0; i < 1000; i++) 
    {
        d[i] = 1.0 + ((double)rand() / RAND_MAX) * (1000.0 - 1.0);
    }
    for (int i = 0; i < 20; i++)
    {
        cout << d[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    generarVoltajes();
    generarTemperaturas();
    generarCaracteres();
    generarAnios();
    generarVelocidades();
    generarDistancias();
    return 0;
}
