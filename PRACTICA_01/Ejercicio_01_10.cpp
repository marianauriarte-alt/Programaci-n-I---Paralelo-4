//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha: 18/08/2026.
#include <iostream>
using namespace std;
int main ()
{
    int numero;
    do{
    cout<<"ingrese un numero entre 1 y 12: ";
    cin>>numero;
    }
    while (numero<=0 || numero>12);

    switch (numero)
    {
        case 1: cout<<"\nEnero"; break;
        case 2: cout<<"\nFebrero"; break;
        case 3: cout<<"\nMarzo"; break;
        case 4: cout<<"\nAbril"; break;
        case 5: cout<<"\nMayo"; break;
        case 6: cout<<"\nJunio"; break;
        case 7: cout<<"\nJulio"; break;
        case 8: cout<<"\nAgosto"; break;
        case 9: cout<<"\nSeptiembre"; break;
        case 10: cout<<"\nOctubre"; break;
        case 11: cout<<"\nNoviembre"; break;
        case 12: cout<<"\nDiciembre"; break;
    }

    return 0;
}