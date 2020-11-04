#include <iostream>
#include "Lista.h"
#include "FunTxt.h"

using namespace std;

int main()
{
    tLista lista;
    int op;
    bool ok;
    lista.contador = 0;
    string eliminar_estudiante, buscado;

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
                    BuscarAlumno(lista, buscado);
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

    return 0;
 }

