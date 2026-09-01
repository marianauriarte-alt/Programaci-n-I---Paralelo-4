#include <iostream>
using namespace std;
int sumatoria_naturales (int n)
{
    int suma=0;
    for (int i=1;i<=n;i++)
    {
        suma+=i;
    }

    return suma;
}
int main ()
{
    int n;
    cout<<"Ingrese los n numeros naturales que desea sumar: ";
    cin>>n;
    
    cout<<"\nEl resultado de la suma de los n numeros es: "<<sumatoria_naturales (n);

    return 0;
}