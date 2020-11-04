#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string>
using namespace std;

const int DIM = 100;

//Estructura
typedef struct{
    string alumno;
    string carrera;
    string curso;
} tAlumnos;
//Array de struct
typedef tAlumnos tArray[DIM];

//Lista
typedef struct{
    tArray elementos;
    int contador;
} tLista;

//Verifica y añade alumnos a la lista
void Insertar(tLista &lista, bool &ok);
//Obtiene la pos del alumno ingresado
void BuscarAlumno(tLista &lista, string alumno);
//Muestra toda la lista
void Mostrar_lista(tLista &lista);

bool operator > (tAlumnos opIzq, tAlumnos opDer);
bool operator < (tAlumnos opIzq, tAlumnos opDer);

void ordenar(tLista &lista);
//Elimina un alumno
void Eliminar(tLista &lista, string alumno);

#endif // LISTA_H_INCLUDED
