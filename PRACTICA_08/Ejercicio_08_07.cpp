// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> extraerHashtags(const string& texto) 
{
    vector<string> hashtags;
    stringstream ss(texto);
    string palabra;

    while (ss >> palabra) 
    {
        if (!palabra.empty() && palabra[0] == '#') 
        {
            hashtags.push_back(palabra);
        }
    }
    return hashtags;
}

int main() 
{
    string tweet = "Estudiando #Programacionl en la #UCB para ser #Ingeniero";
    vector<string> lista = extraerHashtags(tweet);

    cout << "Lista de hashtags: [";
    for (size_t i = 0; i < lista.size(); ++i) 
    {
        cout << lista[i] << (i + 1 < lista.size() ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}
