#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string frase;
string palabras;

void estribir();
void leer();

int main()
{
	cout << "Introducir una frase " << endl;
	getline(cin, frase);

	estribir();

	leer();

	return 0;
}
void estribir()
{
    ofstream archivo_write;
	archivo_write.open("frase.txt", ios::out);
	if(archivo_write.is_open())
	{
		archivo_write << frase;
	}
	archivo_write.close();
}

void leer()
{
    ifstream archivo_read;
	 archivo_read.open("frase.txt", ios::in);
	if( archivo_read.is_open())
	{
		while(! archivo_read.eof())
		{
			 archivo_read >> palabras;
			cout << "Palabra: "<< palabras << "  Cantidad de letras: " << palabras.length() << endl;
		}
	}
	else
    {
        cout<<"NO SE HA PODIDO ABRIR EL ARCHIVO";
	}
	 archivo_read.close();
}
