#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 const int DIM = 100;
 typedef struct
 {
   string alumno;
   string carrera;
   int curso;
 } tAlumnos;

typedef tAlumnos tArray[DIM];

typedef struct {
   tArray elementos;
   int contador=0;
} tLista;
tLista lista;

int i;
int op;
string eliminar_estudiante, buscado;
int pos;
bool ok;

 void openFile(tLista &lista);
 void Insertar(tLista &lista, bool &ok);
 void Mostrar_lista(tLista &lista);
 bool operator > (tAlumnos opIzq, tAlumnos opDer);
 bool operator < (tAlumnos opIzq, tAlumnos opDer);

 void Buscar_alumno(tLista &lista, string buscado);
 void Eliminar(tLista &lista, string alumno);
 void up_date_file (tLista &lista);
 void ordenar(tLista &lista);

 int main()
 {
     string eliminar_estudiante;
    openFile(lista);

    do
     {
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Cargar un nuevo alumno." << endl;
        cout << "2.- Mostrar lista completa" << endl;
        cout << "3.- Buscar un alumno ." << endl;
        cout << "4.- Eliminar alumno" << endl;
        cout << "5.- Guardar/Salir" << endl;

        cin >> op;
        cin.ignore();

        switch (op)
        {
            case 1: Insertar (lista, ok);
                    break;

            case 2: ordenar(lista); break;

            case 3: cout<< "Nombre y apellido del alumno buscado"<< endl;
                    getline(cin, buscado);
                    Buscar_alumno (lista, buscado);
                    break;

            case 4: cout << "Nombre y apellido del alumno"<< endl;
                    getline(cin, eliminar_estudiante);
                    Eliminar(lista, eliminar_estudiante); break;

            case 5: up_date_file (lista); break;
                    cout << "Fin del programa" << endl;
                    break;

            default: cout << "¡Opción desconocida!" << endl;
                     break;
        }
     } while (op != 5);
 }

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


                if((!lista.elementos[i].alumno.empty())
                   && (!lista.elementos[i].carrera.empty())
                   && (!lista.elementos[i].curso != 0)) //si el renglon no esta vacio...
                {
                    lista.contador++;
                }
              }
        }
            OpenFile.close();
}

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


void ordenar(tLista &lista)
{
    for (i = 1; i < lista.contador; i++) // Desde el segundo elemento hasta el último
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

void Mostrar_lista(tLista &lista) //ORDENADA POR INSERCION: DAR OPCION POR CAMPO
{
    for(i = 0; i < lista.contador; i++)
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

void Buscar_alumno(tLista &lista, string buscado )
{
  for(i = 0; i < lista.contador; i++)
    {
        if(lista.elementos[i].alumno == buscado)
        {
            cout<< "El alumno "<< buscado << " se encuentra en la posicion " << i + 1 << endl;
        }
    }
}

void Eliminar(tLista& lista, string alumno) //parametros=atributos=lo que se necesita en la funcion
{
    int pos = 0;
    for(i = 0; i < lista.contador; i++)
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
void up_date_file (tLista &lista)
{
     ofstream gArchivo;
    gArchivo.open("Alumnos.txt", ios::out);
    if(gArchivo.is_open())
    {
        for(i = 0; i < lista.contador; i++)
        {
             gArchivo << lista.elementos[i].alumno<< " " << lista.elementos[i].carrera << " " <<
             lista.elementos[i].curso <<endl;
        }
    }
    gArchivo.close();
}
