#include <fstream>
#include "FunTxt.h"

void openFile (tLista &lista)
{
        ifstream OpenFile; //abrimos el archivo y se sacan los datos...
        OpenFile.open("Alumnos.txt", ios::in);
        if(OpenFile.is_open())
        {
            while(!OpenFile.eof())
               {
                OpenFile >> lista.elementos[lista.contador].alumno;
                OpenFile.get( );
                OpenFile >> lista.elementos[lista.contador].carrera;
                OpenFile >> lista.elementos[lista.contador].curso;

            if((!lista.elementos[lista.contador].alumno.empty())
                  &&(!lista.elementos[lista.contador].carrera.empty())
                  &&(!lista.elementos[lista.contador].curso.empty()))//si el renglon no esta vacio...
                {
                    lista.contador++;
                }
              }
        }
            OpenFile.close();
}

void up_date_file (tLista &lista)
{
    ofstream Archivo;
    Archivo.open("Alumnos.txt", ios::out);
    if(Archivo.is_open())
    {
        for(int i = 0; i < lista.contador; i++)
        {
             Archivo << lista.elementos[i].alumno<< " " << lista.elementos[i].carrera << " " <<
             lista.elementos[i].curso <<endl;
        }
    }
    Archivo.close();
}
