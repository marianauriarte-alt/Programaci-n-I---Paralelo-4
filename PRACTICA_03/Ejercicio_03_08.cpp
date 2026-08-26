#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{   
    srand(time(NULL));
    float utilidad=0.87,impuesto=0.13,descuento,total,total_IVA=0,total_descuentos=0;
    int productos_vendidos,precio,total_ganado=0,mas_alto,mas_bajo;

    cout<<"Ingrese el numero de ventas realizadas: ";
    cin>>productos_vendidos;
    for (int i=0;i<productos_vendidos;i++)
    {
        utilidad = 0.87; impuesto=0.13;total=0; descuento = 0;
        precio = (rand() % (10000 - 10 + 1))+10;

        cout<<precio<<endl;
        utilidad*=precio;
        impuesto*=precio;
        total_IVA+=impuesto;
        total = utilidad + impuesto;
        if (total>2500)
        {
            descuento=total*0.05;
            total-=descuento;
            total_descuentos+=descuento;
        }
        total_ganado+=total;

        if (i==0)
        {
            mas_alto=precio;
            mas_bajo=precio;
        }
        else 
        {
            if (total> mas_alto)
            {
                mas_alto=total;
            }
            else if (total<mas_bajo)
            {
                mas_bajo=total;
            }
        }

    }

    cout<<"\nEl total de las ganancias es: "<<total_ganado<<endl;
    cout<<"El total de impuestos es: "<<total_IVA<<endl;
    cout<<"El total descuento corporativo aplicado a los clientes es: "<<total_descuentos<<endl;
    cout<<"El precio mas bajo fue: "<<mas_bajo<<endl;
    cout<<"El precio mas alto fue: "<<mas_alto<<endl;

    return 0;

}