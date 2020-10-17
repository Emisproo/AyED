#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 const int DIM = 50;
 typedef struct
 {
   string nombre_apellido;
   int edad;
   int dni;
   float nota;
 } tStudents;

typedef tStudents tArray[DIM];

typedef struct {
   tArray elementos;
   int contador=0;
} tLista;
tLista lista;

int i;
int op;

void openFile(tLista &lista);
 void caso1(tLista &lista);
 void caso2(tLista &lista, string nombre_apellido);
 void caso3(tLista &lista);
 void caso4(tLista &lista);
 void up_date_file (tLista &lista);

 int main()
 {
     string eliminar_estudiante;
    openFile(lista);

    do
     {
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir un nuevo estuduiante." << endl;
        cout << "2.- Eliminar estudiante." << endl;
        cout << "3.- Calificar estudiante." << endl;
        cout << "4.- Ver listado de notas y media general" << endl;
        cout << "5.- Salir" << endl;

        cin >> op;
        cin.ignore();

        switch (op)
        {
            case 1: caso1 (lista); break;
            case 2:
                    cout << "Nombre y apellido del estudiante"<< endl;
                    getline(cin, eliminar_estudiante);

                    caso2(lista, eliminar_estudiante); break;

            case 3: caso3(lista); break;
            case 4: caso4 (lista); break;
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
        OpenFile.open("AyEDI.txt", ios::in);
        if(OpenFile.is_open())
        {
            while(!OpenFile.eof())
               {
                getline(OpenFile, lista.elementos[i].nombre_apellido);
                OpenFile.get( );
                OpenFile >> lista.elementos[i].edad;
                OpenFile.get( );
                OpenFile >> lista.elementos[i].dni;
                OpenFile.get( );
                OpenFile >> lista.elementos[i].nota;
                OpenFile.get( );

                if((!lista.elementos[i].nombre_apellido.empty()) &&  (!lista.elementos[i].edad != 0) && (!lista.elementos[i].dni != 0)) //si el renglon no esta vacio...
                {
                    lista.contador++;
                }
              }
        }
            OpenFile.close();
}


void caso1(tLista &lista)
{
     if (lista.contador < DIM)   // Si queda hueco
            {
                cout << "Nombre y Apellido " << endl;
                getline(cin, lista.elementos[lista.contador].nombre_apellido);
                cout << "Edad"<< endl;
                cin >> lista.elementos[lista.contador].edad;
                cout << " DNI"<< endl;
                cin >> lista.elementos[lista.contador].dni;

                ofstream archivo;
                archivo.open("AyEDI.txt", ios::out | ios::app);
                if(archivo.is_open())
                    {
                         archivo <<lista.elementos[lista.contador].nombre_apellido<<" "<<
                         lista.elementos[lista.contador].edad << " " << lista.elementos[lista.contador].dni
                          << lista.elementos[lista.contador].nota << endl;
                    }

                archivo.close();
                lista.contador++;
            }
            else   // Si no hay hueco para más archivos, avisamos
            {
                cout << "¡Máximo de archivos alcanzado (50)!" << endl;
            }
}

void caso2(tLista &lista, string eliminar_estudiante) //eliminar
{

    int pos = 0;
        for(i = 0; i < lista.contador; i++)
         {
		    if ((lista.elementos[i].nombre_apellido == eliminar_estudiante))
             {
                pos = i;
                for(i = pos; i < lista.contador - 1; i++)
                {
                    lista.elementos[i] = lista.elementos[i+1];
                }

                lista.contador = (lista.contador - 1);
                cout << "Estudiante eliminado" << endl;
             }
             else
             {cout << "Estudiante no encontrado";}
        }
}

void up_date_file(tLista &lista)
{
	ofstream archivo;
	archivo.open("AyEDI.txt", ios::out);
	if(archivo.is_open())
	{
		for(i=0; i<lista.contador; i++)
		{
			archivo << lista.elementos[i].nombre_apellido << " "<<lista.elementos[i].edad <<" "<<
			lista.elementos[i].dni <<" "<< lista.elementos[i].nota << endl;
		}
	}
	  archivo.close();
	}

void caso3(tLista &lista)//CALIFICAR ESTUDIANTE
{
   int nota;
    for(i=0; i < lista.contador; i++)
    {
        cout << "Estudiante: " << lista.elementos[i].nombre_apellido << endl;
        cout << "Nota: ";
        cin >> nota;
        if((nota>=1)&&(nota <=10))
        {
            lista.elementos[i].nota = nota;
        }

    }
}

void caso4(tLista &lista)
{
    float promedio;
    int total, nota_max=0;
    string nombre_apellido;

    cout << "Listado de notas:" << endl;
    for(i = 0; i < lista.contador; i++)
    {
        cout << lista.elementos[i].nota << endl;
        if(lista.elementos[i].nota >= nota_max)
        {
            nota_max = lista.elementos[i].nota;
            nombre_apellido = lista.elementos[i].nombre_apellido;
        }
        promedio += lista.elementos[i].nota;
        total = i;
    }
    promedio /= i;
    cout << "La nota mas alta " << nota_max << " " << "Etudiante: " << nombre_apellido << endl;
    cout << "El promedio general es " << promedio << endl;
}
