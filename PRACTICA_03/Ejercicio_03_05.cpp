#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{
    srand(time(NULL));
    int numero,numero_aleatorio=0,interruptor=0,opcion=0,limite_superior=100,limite_inferior=1,contador_intentos=0;
    
    cout<<"Piense en un numero entre el 1 y 100"<<endl;
    numero_aleatorio=(rand()%(100-1+1))+1;

    while (interruptor == 0)
    {
        cout<<"\nEl numero generado es:"<<numero_aleatorio<<endl;
        cout<<"El numero que penso es mayor o menor?"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"\nEs mayor -> 1"<<endl;
        cout<<"Es menor -> 2"<<endl;
        cout<<"El numero es el mismo -> 3"<<endl;
        cin>>opcion;
        switch (opcion)
        {
            case 1:
            limite_inferior=numero_aleatorio;
            numero_aleatorio=(rand()%(limite_superior-limite_inferior+1))+limite_inferior;
            contador_intentos ++;
            break;
            case 2:
            limite_superior=numero_aleatorio;
            numero_aleatorio=(rand()%(limite_superior-limite_inferior+1))+limite_inferior;
            contador_intentos ++;
            break;
            case 3:
            interruptor=1;
            cout<<"Se adivino en "<<contador_intentos<<" intentos"<<endl;
            break;
            default:
            cout<<"Opcion no valida.";
            break;
        }
    }



    return 0;
}