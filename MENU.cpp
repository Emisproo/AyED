#include <iostream>
using namespace std;
#include <stdio.h>
typedef int restaurant;
typedef enum {m1, m2, m3, m4, m5}tMesa;
typedef enum {PABLO, ROMINA, KARI} tMozo;
typedef enum {EMPANADAS, RISSOTO, SOPA} tPlato1;
typedef enum {POLLO, SORRENTINOS, MILANESA} tPlatoPr;
typedef enum {HELADO, FLAN, CHEESCAKE} tPostre;

 int main()
 {
    restaurant opmesa, opmozo, opplato1, opplatopr, oppostre;
    string fecha, hora;
    cout <<"INTRODUCIR LA FECHA (DD/MM/AAAA): ";
    cin >> fecha;

    cout << "INTRODUCIR LA HORA (HH:MM): ";
    cin >> hora;

    cout << " SELECCIONE NUMERO DE MESA"<< endl;
    cout << "1) MESA 1   " << "2) MESA 2   "<<"3) MESA 3    "
    << "4) MESA 4   " << "5) MESA 5"<< endl;
    cin >> opmesa;

    cout << " SELECCIONE EL MOZO" << endl;
    cout << " 1) PABLO  "<< "2) ROMINA   " << "3) KARI  " << endl;
    cin >> opmozo;

    cout << "SELECCIONE EL PRIMER PLATO "<< endl;
    cout << "1) EMPANADAS   " << "2) RISSOTO    "<< endl;
    cin >> opplato1;

    cout << "SELECCIONE EL PLATO PRINCIPAL "<< endl;
    cout <<" 1) POLLO   "<< "2) SORRENTINOS "<< endl;
    cin >> opplatopr;

    cout << "SELECCIONE EL POSTRE "<< endl;
    cout << "1) HELADO  "<< "2) FLAN"<< endl;
    cin >> oppostre;

    cout << " FECHA Y HORA: " << fecha<< " " << hora<< endl;
    //mesa
    if (opmesa == tMesa(1))
    {
        cout << " MESA 1"<< endl;
    }
    if (opmesa == tMesa(2))
    {
        cout << " MESA 2"<< endl;
    }
    if (opmesa == tMesa(3))
    {
        cout << " MESA 3"<< endl;
    }
    if (opmesa == tMesa(4))
    {
        cout << " MESA 1"<< endl;
    }
    if (opmesa == tMesa(5))
    {
        cout << " MESA 5"<< endl;
    }
    //MOZO
    if (opmozo == tMozo(1))
    {
        cout << " MOZO: PABLO"<< endl;
    }
    if (opmozo == tMozo(2))
    {
        cout << "MOZO: ROMINA"<< endl;
    }
    if (opmozo == tMozo (3))
    {
        cout<< "MOZO: KARY"<< endl;
    }
    // PRIMER PLATO
    if (opplato1 == tPlato1 (1))
    {
        cout<< " PRIMER PLATO: EMPANADAS"<< endl;
    }
    else
    {
        cout << "PRIMER PLATO: RISSOTO"<< endl;
    }
    // PLATO PRINCIPAL
    if (opplatopr == tPlatoPr (1))
    {
        cout << "PLATO PRINCIPAL: POLLO" << endl;
    }
    else
    {
        cout << "PLATO PRINCIPAL: SORRENTINOS" << endl;
    }
    //POSTRE
    if(oppostre == tPostre (1))
    {
        cout<< "POSTRE: HELADO"<< endl;
    }
    else
    {
        cout<< "POSTRE: FLAN"<< endl;
    }

   cout << " LA COMANDA YA HA LLEGADO A LA COCINA, GRACIAS"<< endl;
    return 0;

 }
