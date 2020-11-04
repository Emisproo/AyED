#include <iostream>
using namespace std;
#include <stdio.h>

 typedef enum {BANANA, PERA, MANZANA, LIMON, FRUTILLA, NARANJA}tFruit;

int main()
{
 tFruit Fruta;
 string rs, fs, fe, cod;
 int kilo, KB, KP, KM,KL,KF,KN,B, P, M, L, F, N;
    cout << "SOLICITUD DE COMPRA"<< endl;
    cout << "CODIGO DE PROVEEDOR"<< endl;
    cin >> cod;
    cout << " RAZON SOCIAL: "<< endl;
    cin >> rs;
    cout << "FECHA DE SOLICITUD" << endl;
    cin >> fs;
    cout << " FECHA DE ENTREGA"<< endl;
    cin >> fe;

    cout << "SELECCIONE LA FRUTA QUE DESEA, CUANDO FINALICE INGRESE 0" << endl;
    cout << "1) BANANA  "<< "2) PERA    "<< "3) MANZANA    "<< "4) LIMON    "<<endl
    << "5) FRUTILLA    "<< "6) NARANJA"<< endl;
    cin >> Fruta;
    cout << "INGRESE LOS KILOSGRAMOS"<< endl;
    cin >> kilo;

    while( Fruta > 0, Fruta >=6, Fruta  !=0)
    {
        cout << "SELECCIONE LA FRUTA QUE DESEA, CUANDO FINALICE INGRESE 0" << endl;
    cout << "1) BANANA  "<< "2) PERA    "<< "3) MANZANA    "<< "4) LIMON    "<<endl<<
            "5) FRUTILLA    "<< "6) NARANJA"<< endl;
    cin >>Fruta ;
    cout << "INGRESE LOS KILOSGRAMOS"<< endl;
    cin >> kilo;

   if (Fruta  == tFruit (1))
    {
        B = Fruta;
        KB = kilo;
    }
    if (Fruta  == tFruit (2))
    {
        P = Fruta;
        KP = kilo;
    }
    if (Fruta  == tFruit (3))
    {
        M = Fruta;
        KM = kilo;
    }
    if (Fruta  == tFruit (4))
    {
        L = Fruta;
        KL = kilo;
    }
    if (Fruta  == tFruit (5))
    {
        F = Fruta;
        KF = kilo;
    }
    if (Fruta  == tFruit (1))
    {
        N = Fruta;
        KN = kilo;
    }
   }
        cout <<"CODIGO DE PROVEEDOR: "<< cod << endl;
        cout << "RAZON SOCIAL: "<< rs << endl;
        cout <<"FECHA DE SOLICITUD: " << fs << endl;
        cout << "FECHA DE ENTREGA: " << fe << endl;
        if (B == 1)
         {
             cout << "BANANA: "<< KB << " KG"<< endl;
         }
        if (P == 2)
         {
             cout << "PERA: "<< KP << " KG"<<endl;
         }
         if (M == 3)
         {
             cout << " MANZANA: "<< KM << " KG"<< endl;
         }
         if (L == 4)
         {
             cout << " LIMON: "<< KL << " KG"<< endl;
         }
         if (F == 5)
         {
             cout << " FRUTILLA: "<< KF << " KG"<< endl;
         }
         if (N == 6)
         {
             cout << " NARANJA: "<< KN << " KG"<< endl;
         }
 return 0;
}
