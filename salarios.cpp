//b.	Hacer un programa en C++ que ayude a una empresa a incrementar los salarios de los trabajadores de la siguiente manera: Tipo de salario %
//De 0 a $9 000 20%, De $9 000 a $15 000 10%, De $15 000 a $20 000 5%, Más de $20 000 3%

#include <iostream>
using namespace std;

int main ()
{
    int op;
    float total, salario;

        cout << " SELECCIONES LA OPCION A LA QUE PERTENECE SU SALARIO"<< endl<<
        "1) DE $0 A $9.000      " << "2) DE $9.000 A $15.000 " <<endl<< "3) DE $15.000 A $20.000 "<<
        " 4) MAS DE $20.000"<<endl;
        cin >> op;
        cout << "INGRESE SU SALARIO: ";
        cin >> salario;
    switch ( op )
    {
        case 1:{ total = salario* 1.2;
                 cout <<" SU SALARIO TOTAL ES DE $ "<< total;
                } break;
        case 2: { total = salario* 1.1;
                 cout <<" SU SALARIO TOTAL ES DE $ "<< total;
                } break;
        case 3: { total = salario* 1.05;
                 cout <<" SU SALARIO TOTAL ES DE $ "<< total;
                } break;
        case 4: { total = salario* 1.03;
                 cout <<" SU SALARIO TOTAL ES DE $ "<< total;
                } break;
        default: {cout<<"ERROR DE OPCION";}
    }
    return 0;
}
