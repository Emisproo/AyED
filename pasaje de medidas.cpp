//a.	Hacer un programa en C++ que convierta centímetros a pulgadas Celsius a Farenheit y libras a kilogramos
#include <iostream>
using namespace std;

int main ()
{
    int op;
    float c ,f;
    double cm,pl, lb, kg;

    cout << " SELECCIONES LAS MAGNITUDES QUE DESEA CONVERTIR"<< endl<<
        "1) CENTIMETRO/PULGADAS " << "2) CELSIUS/FARENHEIT " << "3) LIBRAS/KILOGRAMOS"<<
        endl;
    cin >> op;

    switch ( op )
    {
        case 1:{ cout<< " INGRESE LOS CENTIMETROS: ";
                 cin >> cm;
                 pl = cm / 2.54;
                 cout << cm << " CM SON "<< pl << " PULGADAS";
                } break;
        case 2: { cout<< " INGRESE LOS GRADOS CELSIUS: ";
                 cin >> c;
                 f = ((c * 9/5) + 32) ;
                 cout << c << " °C SON "<< f << " °F";
                } break;
        case 3: { cout << " INGRESE LAS LIBRAS: ";
                 cin >> lb;
                 kg = lb /2.205;
                 cout << lb << " LB SON "<< kg << " KG";
                } break;
        default: {cout<<"ERROR DE OPCION";}
    }
    return 0;
}
