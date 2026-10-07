// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string aMinusculas(string str) 
{
    for (size_t i = 0; i < str.length(); ++i) 
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

vector<string> buscarContactos(const vector<string>& contactos, string prefijo) 
{
    vector<string> resultados;
    string prefijoLower = aMinusculas(prefijo);

    for (const string& contacto : contactos) 
    {
        if (contacto.length() >= prefijoLower.length()) 
        {
            string sub = contacto.substr(0, prefijoLower.length());
            if (aMinusculas(sub) == prefijoLower) 
            {
                resultados.push_back(contacto);
            }
        }
    }
    return resultados;
}

int main() 
{
    vector<string> contactos = {"Marcelo", "Maria", "Martin", "Juan", "Marcos"};
    string prefijo = "Mar";

    vector<string> hallados = buscarContactos(contactos, prefijo);

    cout << "Resultados: ";
    for (size_t i = 0; i < hallados.size(); ++i) 
    {
        cout << hallados[i] << (i + 1 < hallados.size() ? ", " : "");
    }
    cout << endl;

    return 0;
}
