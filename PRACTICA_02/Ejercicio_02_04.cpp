#include <iostream>
#include <conio.h>
using namespace std;
int main ()
{
    int suma=0, n;

    cout<<"Digite el numero de elementos: ";
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        suma+=i;
    }

    cout<<"\nLa suma es: "<<suma<<endl;
    

    getch ();
    return 0; 
}