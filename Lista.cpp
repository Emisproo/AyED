#include <iostream>
#include "lista.h"

void Insertar(tLista &lista, bool &ok)
{
    tAlumnos alumno;
    ok = true;
    if(lista.contador < DIM)
    {

        cout<<"Nombre y apellido del alumno: ";
        cin.ignore();
        getline(cin,alumno.alumno);
        cout << "Carrera que cursa el alumno: ";
        getline(cin,alumno.carrera);
        cout << "Curso: ";
        cin >> alumno.curso;

        if (lista.contador == DIM)
        {
            ok = false;
        }
        else
        {
            int i=0;
            while ((i < lista.contador) && (lista.elementos[i] < alumno))
            {
                i++;
            }
                // Insertamos en la posición i (primer mayor o igual)
            for (int j = lista.contador; j > i; j--)
            {
                // Desplazamos una posición a la derecha
                lista.elementos[j] = lista.elementos[j-1];
            }
            lista.elementos[i] = alumno;
            lista.contador++;
        }
    }
    else
        cout << "Maximo de alumnos cargados (100)!" << endl;
}

void BuscarAlumno(tLista &lista, string buscado )
{
  for(int i = 0; i < lista.contador; i++)
    {
        if(lista.elementos[i].alumno == buscado)
        {
            cout<< "El alumno "<< buscado << " se encuentra en la posicion " << i + 1 << endl;
        }
    }
}

void Mostrar_lista(tLista &lista)
{
    for(int i = 0; i < lista.contador; i++)
    {
        cout << "Alumno: " << lista.elementos[i].alumno << endl;
        cout << "Carrera: " << lista.elementos[i].carrera << endl;
        cout << "Curso: " << lista.elementos[i].curso << endl;
        cout << "**********************"<< endl;
    }
}

bool operator >(tAlumnos opIzq, tAlumnos opDer)
{
    return(opIzq.alumno > opDer.alumno);
}

bool operator <(tAlumnos opIzq, tAlumnos opDer)
{
    return(opIzq.alumno < opDer.alumno);
}

void ordenar(tLista &lista)
{
    for (int i = 1; i < lista.contador; i++) // Desde el segundo elemento hasta el último
        {
         int pos=i;
         while ((pos > 0)&& (lista.elementos[pos-1] > lista.elementos[pos]))
            {
                tAlumnos tmp;
                tmp = lista.elementos[pos];
                lista.elementos[pos]= lista.elementos[pos - 1];
                lista.elementos[pos - 1] = tmp;
                pos--;
              }
    Mostrar_lista(lista);
    }
}

void Eliminar(tLista& lista, string alumno) //parametros=atributos=lo que se necesita en la funcion
{
    int pos = 0;
    for(int i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].alumno == alumno))
        {
            pos = i;
            for(i = pos; i < lista.contador - 1; i++)
            {
             lista.elementos[i] = lista.elementos[i+1];
            }
            lista.contador = (lista.contador - 1);
            cout << "Alumno eliminado correctamente!" << endl;
        }
    }
}
