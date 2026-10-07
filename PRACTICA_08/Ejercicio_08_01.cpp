// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarCombinacionesRandom(int n, const vector<string>& nombres, const vector<string>& apellidos, const vector<int>& edades) 
{
    for (int i = 0; i < n; ++i) 
    {
        int iNom = rand() % nombres.size();
        int iApe = rand() % apellidos.size();
        int iEdad = rand() % edades.size();

        cout << "Muestra " << (i + 1) << ": " 
             << nombres[iNom] << " " << apellidos[iApe] << ", " 
             << edades[iEdad] << " años" << endl;
    }
}

int main() 
{
    srand(time(0)); // Inicializar la semilla aleatoria

    vector<string> nombres = {"Juan", "Maria", "Carlos", "Ana", "Luis", "Sofia", "Pedro", "Lucia", "Diego", "Elena"};
    vector<string> apellidos = {"Perez", "Gomez", "Lopez", "Rodriguez", "Fernandez", "Garcia", "Martinez", "Sanchez", "Romero", "Torres"};
    vector<int> edades = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27};

    int n;
    cout << "Ingrese la cantidad de selecciones (N): ";
    cin >> n;

    generarCombinacionesRandom(n, nombres, apellidos, edades);

    return 0;
}
