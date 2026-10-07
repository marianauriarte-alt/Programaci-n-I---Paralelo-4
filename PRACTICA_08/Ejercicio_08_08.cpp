// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> tokenizar(const string& texto) 
{
    vector<string> palabras;
    stringstream ss(texto);
    string palabra;
    while (ss >> palabra) 
    {
        palabras.push_back(palabra);
    }
    return palabras;
}

bool detectarPlagio(const string& oracionA, const string& oracionB) 
{
    vector<string> palabrasA = tokenizar(oracionA);
    vector<string> palabrasB = tokenizar(oracionB);

    int coincidencias = 0;

    for (size_t i = 0; i < palabrasA.size(); ++i) 
    {
        bool encontrada = false;
        for (size_t j = 0; j < palabrasB.size() && !encontrada; ++j) 
        {
            if (palabrasA[i] == palabrasB[j]) 
            {
                coincidencias++;
                encontrada = true; // Controla el flujo del bucle sin usar break
            }
        }
    }

    return coincidencias > 3;
}

int main() 
{
    string oracionA = "El sistema fue desarrollado en C++";
    string oracionB = "El nuevo sistema fue codificado en C++";

    bool esPlagio = detectarPlagio(oracionA, oracionB);
    cout << "Alerta de plagio: " << (esPlagio ? "Verdadero" : "Falso") << endl;

    return 0;
}
