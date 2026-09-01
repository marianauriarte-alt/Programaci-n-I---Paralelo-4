//Materia: Programacion I, Paralelo 4.
//Autor: Mariana Valeria Uriarte Guzman.
//Carrera: Ingenieria Industrial.
//Fecha de creacion: 31/08/2026.

#include <iostream>
using namespace std;

float notas()
{
    int nota1=0, nota2=0, nota3=0, nota_examenfinal=0;
    float nota_final=0;

    do
    {
        cout<<"\nIngrese la nota del primer elemento de competencia: ";
        cin>>nota1;

        if (nota1<0 || nota1>100)
        {
            cout<<"Valor incorrecto, solo se admiten valores entre 0 y 100";
        }

    } while (nota1<0 || nota1>100);

    if (nota1<60)
    {
        cout<<"\nNota 1er parcial: "<<nota1<<endl;
        cout<<"Nota de reprobacion. NO ESTA HABILITADO PARA EL EXAMEN FINAL";
        return -1;
    }

    do
    {
        cout<<"\nIngrese la nota del segundo elemento de competencia: ";
        cin>>nota2;

        if (nota2<0 || nota2>100)
        {
            cout<<"Valor incorrecto, solo se admiten valores entre 0 y 100";
        }

    } while (nota2<0 || nota2>100);

    if (nota2<60)
    {
        cout<<"\nNota 1er parcial: "<<nota1<<endl;
        cout<<"Nota 2do parcial: "<<nota2<<endl;
        cout<<"Nota de reprobacion. NO ESTA HABILITADO PARA EL EXAMEN FINAL";
        return -1;
    }

    do
    {
        cout<<"\nIngrese la nota del tercer elemento de competencia: ";
        cin>>nota3;

        if (nota3<0 || nota3>100)
        {
            cout<<"Valor incorrecto, solo se admiten valores entre 0 y 100";
        }

    } while (nota3<0 || nota3>100);

    if (nota3<60)
    {
        cout<<"\nNota 1er parcial: "<<nota1<<endl;
        cout<<"Nota 2do parcial: "<<nota2<<endl;
        cout<<"Nota 3er parcial: "<<nota3<<endl;
        cout<<"Nota de reprobacion. NO ESTA HABILITADO PARA EL EXAMEN FINAL";
        return -1;
    }

    do
    {
        cout<<"\nIngrese la nota del examen final: ";
        cin>>nota_examenfinal;

        if (nota_examenfinal<0 || nota_examenfinal>100)
        {
            cout<<"Valor incorrecto, solo se admiten valores entre 0 y 100";
        }

    } while (nota_examenfinal<0 || nota_examenfinal>100);


    nota_final=(((nota1+nota2+nota3)/3.0)*0.5)+(nota_examenfinal*0.5);

    cout<<"\nNota 1er parcial: "<<nota1<<endl;
    cout<<"Nota 2do parcial: "<<nota2<<endl;
    cout<<"Nota 3er parcial: "<<nota3<<endl;
    cout<<"Nota examen final: "<<nota_examenfinal<<endl;

    cout<<"\nLa nota final es: "<<nota_final<<endl;

    if (nota_final<51)
    {
        cout<<"REPROBO LA MATERIA"<<endl;
    }
    else
    {
        cout<<"APROBO LA MATERIA"<<endl;
    }

    return nota_final;
}


void hacer_n_veces(int n)
{
    int aprobados=0, reprobados=0;
    float suma_notas=0, nota;

    for (int i=1; i<=n; i++)
    {
        cout<<"\n========== ESTUDIANTE "<<i<<" =========="<<endl;

        nota=notas();

        if (nota==-1)
        {
            reprobados++;
        }
        else
        {
            suma_notas=suma_notas+nota;

            if (nota>=51)
            {
                aprobados++;
            }
            else
            {
                reprobados++;
            }
        }
    }

    cout<<"\n\n========== RESULTADOS GENERALES =========="<<endl;

    cout<<"\nCantidad de estudiantes aprobados: "<<aprobados;
    cout<<"\nCantidad de estudiantes reprobados: "<<reprobados;

    cout<<"\n\nPorcentaje de aprobados: "<<(aprobados*100.0/n)<<"%";
    cout<<"\nPorcentaje de reprobados: "<<(reprobados*100.0/n)<<"%";

    cout<<"\n\nPromedio de notas finales: ";

    if (aprobados+reprobados>0)
    {
        cout<<suma_notas/(aprobados+reprobados);
    }
    else
    {
        cout<<"0";
    }

    cout<<endl;
}


int main()
{
    int n;

    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>n;

    hacer_n_veces(n);

    return 0;
}