#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 500;
typedef struct{
    string nombre;
    int cod;
    float precio;
    int stock;
} tProducto;

typedef tProducto tArray[MAX];

typedef struct{
    tArray elementos;
    int contador;
} tLista;

int i;

void cargarArchivo(tLista &lista);
void guardarArchivo(tLista &lista);
void addProd(tLista &lista);
void mostrarProd (tLista &lista);
void maxValor (tLista &lista);
void eliminarProd(tLista &lista, int cod);

int main()
{
    tLista lista;
    int tempText;
    int op;
    lista.contador = 0;
    cargarArchivo(lista);

    do {
        cout << "1 - Agregar producto" << endl;
        cout << "2 - Mostrar productos" << endl;
        cout << "3 - Producto de mayor valor" << endl;
        cout << "4 - Eliminar producto" << endl;
        cout << "0 - Salir" << endl;
        cin >> op;

        switch(op)
        {
        case 1:
            //Añadir producto
            addProd(lista);
            break;
        case 2:
            //Listado de productos
            mostrarProd(lista);
            break;
        case 3:
            //mayor valor
            maxValor(lista);
            break;
        case 4:
            //Eliminar producto
            cout << "Ingrese el codigo del producto que desee eliminar: ";
            cin >> tempText;
            eliminarProd(lista,tempText);
            break;
        case 0:
            //Guardamos y salimos
            guardarArchivo(lista);
            break;
        default:
            cout << "Opcion desconocida!" << endl;
            break;
        }
    } while (op != 0);
return 0;
}

void cargarArchivo(tLista &lista)
{
    ifstream Archivo;
    Archivo.open("Almacen.txt", ios::in);
    if(Archivo.is_open())
    {
        while (!Archivo.eof())
        {
            Archivo >> lista.elementos[lista.contador].nombre;
            Archivo.get( );
            Archivo >> lista.elementos[lista.contador].cod;
            Archivo >> lista.elementos[lista.contador].precio;
            Archivo >> lista.elementos[lista.contador].stock;

            if((!lista.elementos[lista.contador].cod!=0)&&
               (!lista.elementos[lista.contador].nombre.empty())
               &&(!lista.elementos[lista.contador].precio!=0)&&
               (lista.elementos[lista.contador].stock != 0))
            {
                lista.contador++;
            }
        }
    }
    Archivo.close();
}
void guardarArchivo(tLista &lista)
{
    ofstream Archivo;
    Archivo.open("Almacen.txt", ios::out);
    if(Archivo.is_open())
    {
        for(i = 0; i < lista.contador; i++)
        {
             Archivo << lista.elementos[i].cod<< " " << lista.elementos[i].nombre << " " <<
             lista.elementos[i].precio << " " << lista.elementos[i].stock <<endl;
        }
    }
    Archivo.close();
}

void addProd(tLista &lista)
{
    if(lista.contador < MAX)
    {
        cout << "Ingrese el codigo del producto: ";
        cin.ignore();
        cin>>lista.elementos[lista.contador].cod;
        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin,lista.elementos[lista.contador].nombre);
        cout << "Ingrese el precio del producto: ";
        cin>> lista.elementos[lista.contador].precio;
        cout << "Ingrese el stock disponible: ";
        cin >> lista.elementos[lista.contador].stock;
        lista.contador = (lista.contador + 1);

    } else
        cout << "Maximo de archivos alcanzados (500)!" << endl;
}

void mostrarProd (tLista &lista)
{
    cout << setfill('*')<< "Listado de productos" <<setfill('*')  << endl;
    cout << "COD"<<"        "<< "NOMBRE"<< "        "<< "PRECIO" <<"        "<<"STOCK" << endl;
    for(i = 0; i < lista.contador; i++)
    {
        cout<< lista.elementos[i].cod <<"           "<< lista.elementos[i].nombre <<"        " <<
         "$ " << lista.elementos[i].precio <<"           "<< lista.elementos[i].stock << endl;
    }
}

void maxValor (tLista &lista)
{
    int codigo, cantidad;
    string nombre;
    float total, Valmax = 0;

    for(i = 0; i < lista.contador; i++)
    {
        if(lista.elementos[i].precio >= Valmax)
        {
            codigo = lista.elementos[i].cod;
            nombre = lista.elementos[i].nombre;
            Valmax = lista.elementos[i].precio;
            cantidad = lista.elementos[i].stock;

        }
        total = cantidad*Valmax;
    }

    cout << "El producto de mayor valor es el: "<< codigo << " " << nombre <<
            " " <<"$ "<< Valmax <<" "<< cantidad <<endl;
    cout << "VALOR TOTAL DEL STOCK " <<"$ "<< total << endl;
}

void eliminarProd(tLista &lista, int cod)
{
    int pos = 0;
    for(i = 0; i < lista.contador; i++)
    {
        if(lista.elementos[i].cod == cod)
        {
            pos = i;
            for(i = pos; i < lista.contador - 1; i++)
            {
             lista.elementos[i] = lista.elementos[i+1];
            }
            lista.contador = (lista.contador - 1);
            cout << "Producto eliminado correctamente!" << endl;
        }
    }
}
