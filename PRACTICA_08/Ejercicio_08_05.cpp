// Materia: Programación I, Paralelo 4
// Autor: Mariana Valeria Uriarte Guzman
// Fecha creación: 30/09/2026

#include <iostream>
#include <string>

using namespace std;

void parsearURL(const string& url, string& protocolo, string& dominio, string& ruta) 
{
    size_t posProto = url.find("://");
    if (posProto != string::npos) 
    {
        protocolo = url.substr(0, posProto);
        size_t posInicioDominio = posProto + 3;
        size_t posRuta = url.find("/", posInicioDominio);

        if (posRuta != string::npos) 
        {
            dominio = url.substr(posInicioDominio, posRuta - posInicioDominio);
            ruta = url.substr(posRuta);
        } 
        else 
        {
            dominio = url.substr(posInicioDominio);
            ruta = "/";
        }
    }
}

int main() 
{
    string url = "https://www.universidad.edu.bo/carreras/sistemas";
    string protocolo, dominio, ruta;

    parsearURL(url, protocolo, dominio, ruta);

    cout << "Protocolo: " << protocolo << endl;
    cout << "Dominio: " << dominio << endl;
    cout << "Ruta: " << ruta << endl;

    return 0;
}
