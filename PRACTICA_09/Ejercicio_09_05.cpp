// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 07/10/2026
// Número de ejercicio: 5

#include <iostream>
#include <vector>

using namespace std;

void mostrarSala(const vector<vector<int>>& sala) {
    cout << "\n--- ESTADO DE LA SALA VIP ---" << endl;
    cout << "  \tCol 0\tCol 1\tCol 2\tCol 3\tCol 4" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Fila " << i << "\t";
        for (int j = 0; j < 5; ++j) 
        {
            if (sala[i][j] == 0) 
            {
                cout << "L\t";
            } 
            else 
            {
                cout << "O\t";
            }
        }
        cout << endl;
    }
}

void comprarEntrada(vector<vector<int>>& sala) 
{
    int fila, asiento;
    cout << "Ingrese la fila (0 a 4): ";
    cin >> fila;
    cout << "Ingrese el número de asiento (0 a 4): ";
    cin >> asiento;

    if (fila >= 0 && fila < 5 && asiento >= 0 && asiento < 5) 
    {
        if (sala[fila][asiento] == 0) 
        {
            sala[fila][asiento] = 1;
            cout << "¡Reserva exitosa!" << endl;
        } 
        else 
        {
            cout << "Asiento no disponible." << endl;
        }
    } 
    else 
    {
        cout << "Coordenadas inválidas. Intente nuevamente." << endl;
    }
}

void mostrarEstadisticas(const vector<vector<int>>& sala) 
{
    int libres = 0;
    int ocupados = 0;
    int totalAsientos = 25;

    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
        {
            if (sala[i][j] == 0) 
            {
                libres++;
            } 
            else 
            {
                ocupados++;
            }
        }
    }

    double porcentajeLibres = (static_cast<double>(libres) / totalAsientos) * 100.0;
    double porcentajeOcupados = (static_cast<double>(ocupados) / totalAsientos) * 100.0;

    cout << "\n--- ESTADÍSTICAS DE LA SALA ---" << endl;
    cout << "Asientos libres: " << libres << " (" << porcentajeLibres << "%)" << endl;
    cout << "Asientos ocupados: " << ocupados << " (" << porcentajeOcupados << "%)" << endl;
}

int main() 
{
    vector<vector<int>> sala(5, vector<int>(5, 0)); // Inicializada en 0 (libre)
    int opcion = 0;

    while (opcion != 4) 
    {
        cout << "\n=== MENÚ CINE VIP ===" << endl;
        cout << "1. Mostrar la sala" << endl;
        cout << "2. Comprar entrada" << endl;
        cout << "3. Estadísticas" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) 
        {
            case 1:
                mostrarSala(sala);
                break;
            case 2:
                comprarEntrada(sala);
                break;
            case 3:
                mostrarEstadisticas(sala);
                break;
            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
