#include <iostream>
using namespace std;
int main ()
{
    int numero,divisor=1,verificacion=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    while (divisor < numero)
    {
        if (numero%divisor==0)
        {
            verificacion+=divisor;
        }
        divisor++;
    }
    
    if (verificacion == numero){
        cout<<"\nEs un numero perfecto";
    }
    else{
        cout<<"\nNo es un numero perfecto";
    }


}