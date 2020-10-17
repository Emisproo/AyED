#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void crearArchivo();
void leerArchivo();
void CantPalabras();
int contarPalabras(string);
string palabraMasLarga();

int main(){

    int op;

            cout << " Frases de Bjarne" << endl;
            cout << "Elija una opcion: " << endl;
            cout << "1) Crear nuevo archivo"  << endl;
            cout << "2) Leer archivo (con interlineado)" << endl;
            cout << "3) Ver cantidad de palabras por linea"  << endl;
            cout << "4) Buscar la palabra mas larga" << endl;
            cout << "0) Salir" << endl << endl;
            cin >> op;

            switch (op) {
                            case 1: crearArchivo(); break;
                            case 2: leerArchivo(); break;
                            case 3: CantPalabras(); break;
                            case 4: palabraMasLarga(); break;
                        }
            while (op != 0)
            {
                cout << endl;
               cout << "Elija una opcion: " << endl;
               cout << "1) Crear nuevo archivo"  << endl;
               cout << "2) Leer archivo (con interlineado)" << endl;
               cout << "3) Ver cantidad de palabras por linea"  << endl;
               cout << "4) Buscar la palabra mas larga" << endl;
               cout << "0) Salir" << endl << endl;
               cin >> op;

            switch (op) {
                            case 1: crearArchivo(); break;
                            case 2: leerArchivo(); break;
                            case 3: CantPalabras(); break;
                            case 4: palabraMasLarga(); break;
                        }
                cout << endl;
            }

  return 0;
}

void crearArchivo(){

  ofstream archivo;
  string frase, ending;
  archivo.open("frasesDeBjarne.txt");
  ending = "fin";

    do {
        cout << "Ingrese una frase o escriba (fin) para terminar: ";
        getline(cin,frase);

        if (!frase.empty() && frase != ending)
            {
                archivo << frase << endl;
            }
        }

    while (frase != ending);

        archivo.close();
}

void leerArchivo(){
    ifstream archivo;
    string frase,str;
    archivo.open("frasesDeBjarne.txt");

    if (archivo.is_open())
    {
        while ( getline(archivo,frase) )
            {
                cout << frase << endl;
            }
        archivo.close();
    }
    else {
            cout << "No se pudo abrir el archivo o no existe...";
         }

  archivo.close();
}

void CantPalabras(){
    ifstream archivo;
    string frase;

    archivo.open("frasesDeBjarne.txt");

    if (archivo.is_open())
    {
        while ( getline(archivo,frase) )
            {
                cout << " La frase tiene " << contarPalabras(frase) << " palabras"<< endl;
            }
    archivo.close();
    }
    else {
            cout << "No se pudo abrir el archivo o no existe...";
         }
  archivo.close();
}

int contarPalabras(string str){
  int cantPalabras = 0;
  char anterior = ' ';

  for(int i = 0; i < str.length(); i++)
    {
      if ( str[i] != ' ' && anterior == ' ') cantPalabras++;
      anterior = str[i];
  }

  return cantPalabras;
}

string palabraMasLarga() {
  ifstream archivo;
  string frase, texto;

  archivo.open("frasesDeBjarne.txt");       // Leo todo el archivo:
  if (archivo.is_open())
    {
     while (!archivo.eof())
     {
      getline(archivo, frase);
      texto.append(frase);
      texto.append(" ");
     }
   }
  archivo.close();

  int counter = 0;
  int max_word = -1;
  int total_caracteres = texto.length();    // Total de caracteres en el string.
  string longest = " ";     // Palabra con mas caracteres.

  for (int i = 0; i < total_caracteres; i++)     //Recorre caracter por caracter.
    {
        if (texto[i] != ' ')         //Busca el espacio que separa entre palabras.
        {
            counter++;
        }

        if ( texto[i] == ' ' || i == total_caracteres - 1)
            {
                if (counter > max_word)
                {
                    max_word = counter;
                    if ( i == total_caracteres - 1)
                        longest = texto.substr( i + 1 - max_word, max_word);
                    else
                        longest = texto.substr( i - max_word, max_word);
                }
                counter = 0;
            }
    }
  cout <<"La palabra mas larga es "<< longest << " ( con " << max_word << " chars)" << endl;
}
