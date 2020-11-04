#include <iostream>
using namespace std;
#include <stdio.h>
typedef int opcion;
typedef enum {PRIMERA, BUSSINESS, ECONOMICA}tClase;
typedef enum {BAHIA_BLANCA, AEROPARQUE, EL_PALOMAR, EZEIZA, BARILOCHE, CATAMARCA, COMODORO_RIVADAVIA} tD_O;

 int main()
 {
     opcion opClase, opD, opO;
     string Nombre, Apellido, DNI;
     cout << "RESERVA DE VUELOS IDA Y VUELTA"<< endl;
     cout << "INGRESE SU NOMBRE" << endl;
     cin >> Nombre;

     cout << " INGRESE SU APELLIDO"<< endl;
     cin >> Apellido;

     cout << " INGRESE SU DNI"<< endl;
     cin >> DNI;

     cout << " ¿EN QUÉ CLASE DESEA VIAJAR? ELIJA UNA OPCION"<< endl;
     cout << "1) PRIMERA    "<< "2) BUSSINESS   "<< "3) ECONOMICA" << endl;
     cin >> opClase;

     cout <<" INTRODUCIR ORIGEN DEL VUELO, POR FAVOR. ELIJA UNA OPCION"<< endl;
     cout << "1) BAHIA_BLANCA   "<< "2) AEROPARQUE    "<<" 3) EL_PALOMAR    " << "4) EZEIZA   "<< endl;
     cout <<"5) BARILOCHE    "<< "6)CATAMARCA    "<< "7) COMODORO_RIVADAVIA"<< endl;
     cin >> opO;

      cout <<" INTRODUCIR DESTINO DEL VUELO, POR FAVOR. ELIJA UNA OPCION"<< endl;
     cout << "1) BAHIA_BLANCA   "<< "2) AEROPARQUE    "<<" 3) EL_PALOMAR    " << "4) EZEIZA   "<< endl;
     cout <<"5) BARILOCHE    "<< "6)CATAMARCA    "<< "7) COMODORO_RIVADAVIA"<< endl;
     cin >> opD;

     cout<< "NOMBRE Y APELLIDO DEL PASAJERO:" << Nombre << " " << Apellido<< endl<<
     "DNI: " << DNI<< endl;
     //clase
     if (opClase == tClase (1))
     {
         cout << " CLASE: PRIMERA"<< endl;
     }
     if (opClase == tClase (2))
     {
         cout << " CLASE: BUSSINESS"<< endl;
     }
      if (opClase == tClase (3))
     {
         cout << " CLASE: ECONOMICA"<< endl;
     }
     // ORIGEN
     if (opO == tD_O (1))
     {
         cout << "ORIGEN: BAHIA BLANCA - BHI."<< endl;
     }
     if (opO == tD_O (2))
     {
         cout << "ORIGEN: BUENOS AIRES AEROPARQUE - AEP."<< endl;
     }
     if (opO == tD_O (3))
     {
         cout << "ORIGEN: BUENOS AIRES EL PALOMAR - EPA ."<< endl;
     }
     if (opO == tD_O (4))
     {
         cout << "ORIGEN: BUENOS AIRES EZEIZA - EZE ."<< endl;
     }
     if (opO == tD_O (5))
     {
         cout << "ORIGEN: SAN CARLOS DE BARILOCHE - BRC ."<< endl;
     }
     if (opO == tD_O (6))
     {
         cout << "ORIGEN: SAN FERNANDO DEL VALLE DE CATAMARCA - CTC ."<< endl;
     }
     if (opO == tD_O (7))
     {
         cout << "ORIGEN: COMODORO RIVADAVIA."<< endl;
     }
     //DESTINO
     if (opD == tD_O (1))
     {
         cout << "DESTINO: BAHIA BLANCA - BHI."<< endl;
     }
     if (opD == tD_O (2))
     {
         cout << "DESTINO: BUENOS AIRES AEROPARQUE - AEP."<< endl;
     }
     if (opD == tD_O (3))
     {
         cout << "DESTINO: BUENOS AIRES EL PALOMAR - EPA ."<< endl;
     }
     if (opD == tD_O (4))
     {
         cout << "DESTINO: BUENOS AIRES EZEIZA - EZE ."<< endl;
     }
     if (opD == tD_O (5))
     {
         cout << "DESTINO: SAN CARLOS DE BARILOCHE - BRC ."<< endl;
     }
     if (opD == tD_O (6))
     {
         cout << "DESTINO: SAN FERNANDO DEL VALLE DE CATAMARCA - CTC ."<< endl;
     }
     if (opD == tD_O (7))
     {
         cout << "DESTINO: COMODORO RIVADAVIA."<< endl;
     }
    cout << "LA INFORMACION HA SIDO INGRESADA, GRACIAS POR ELEGIRNOS."<< endl;
     return 0;
}
