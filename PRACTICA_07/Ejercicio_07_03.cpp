// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/09/2026
// Número de ejercicio: 3

#include <iostream>
#include <vector>
using namespace std;

void cargarCalificaciones(vector<int>& v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Ingrese calificacion " << i + 1 << ": ";
        cin >> v[i];
    }
}

int obtenerSuma(vector<int> v) 
{
    int suma = 0;
    for (int i = 0; i < v.size(); i++) 
    {
        suma = suma + v[i];
    }
    return suma;
}

void calcularDesviaciones(vector<int> v, vector<double>& desv, double prom) 
{
    for (int i = 0; i < v.size(); i++) 
    {
        desv[i] = v[i] - prom;
    }
}

double obtenerVarianza(vector<double> desv) 
{
    double sumaCuadrados = 0;
    for (int i = 0; i < desv.size(); i++) 
    {
        sumaCuadrados = sumaCuadrados + (desv[i] * desv[i]);
    }
    return sumaCuadrados / desv.size();
}

void mostrarResultados(vector<int> v, vector<double> desv, int suma, double prom, double varianza) 
{
    cout << "\nSuma total: " << suma << endl;
    cout << "Promedio: " << prom << endl;
    cout << "Varianza: " << varianza << endl;
    cout << "\nCalificacion\tDesviacion" << endl;
    for (int i = 0; i < v.size(); i++) 
    {
        cout << v[i] << "\t\t" << desv[i] << endl;
    }
}

int main() 
{
    int n;
    cout << "Ingrese la cantidad de calificaciones: ";
    cin >> n;

    vector<int> calificaciones(n);
    cargarCalificaciones(calificaciones, n);

    int suma = obtenerSuma(calificaciones);
    double promedio = (double)suma / n;

    vector<double> desviacion(n);
    calcularDesviaciones(calificaciones, desviacion, promedio);

    double varianza = obtenerVarianza(desviacion);

    mostrarResultados(calificaciones, desviacion, suma, promedio, varianza);

    return 0;
}
