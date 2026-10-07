// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool esContrasenaSegura(const string& password) 
{
    if (password.length() < 8) return false;

    bool tieneMayus = false;
    bool tieneMinus = false;
    bool tieneNumero = false;
    bool tieneEspecial = false;

    for (char c : password) {
        if (isupper(c)) tieneMayus = true;
        else if (islower(c)) tieneMinus = true;
        else if (isdigit(c)) tieneNumero = true;
        else tieneEspecial = true;
    }

    return tieneMayus && tieneMinus && tieneNumero && tieneEspecial;
}

int main() 
{
    string pwd1 = "HolaMundo123!";
    string pwd2 = "holamundo";

    cout << pwd1 << " -> " << (esContrasenaSegura(pwd1) ? "Contraseña segura" : "Contraseña vulnerable") << endl;
    cout << pwd2 << " -> " << (esContrasenaSegura(pwd2) ? "Contraseña segura" : "Contraseña vulnerable") << endl;

    return 0;
}
