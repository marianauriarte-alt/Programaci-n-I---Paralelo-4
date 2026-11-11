// Materia: Programación I, Paralelo 4.
// Autor: Mariana Valeria Uriarte Guzman.
// Fecha creación: 30/10/2026.

#include <iostream>
#include <string>
using namespace std;

struct Cuenta
{
    string titular;
    int numeroCuenta;
    double saldo;
};

void depositar (Cuenta &cuenta, double cantidad)
{
    cuenta.saldo += cantidad;
}

void retirar (Cuenta &cuenta, double cantidad)
{
    if (cantidad <= cuenta.saldo)
    {
        cuenta.saldo -= cantidad;
        cout<<"\nRetiro realizado correctamente."<<endl;
    }
    else
    {
        cout<<"\nSaldo insuficiente."<<endl;
    }
}

int main ()
{
    Cuenta cuenta;
    double deposito, retiro;

    cout<<"Ingrese el nombre del titular: ";
    cin>>cuenta.titular;

    cout<<"Ingrese el numero de cuenta: ";
    cin>>cuenta.numeroCuenta;

    cout<<"Ingrese el saldo inicial: ";
    cin>>cuenta.saldo;

    cout<<"\nIngrese la cantidad a depositar: ";
    cin>>deposito;

    depositar (cuenta, deposito);

    cout<<"\nIngrese la cantidad a retirar: ";
    cin>>retiro;

    retirar (cuenta, retiro);

    cout<<"\nDATOS FINALES DE LA CUENTA"<<endl;
    cout<<"Titular: "<<cuenta.titular<<endl;
    cout<<"Numero de cuenta: "<<cuenta.numeroCuenta<<endl;
    cout<<"Saldo final: "<<cuenta.saldo<<endl;

    return 0;
}
