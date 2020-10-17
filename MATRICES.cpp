#include <iostream>
#include <fstream>
using namespace std;
const int MAXF =10;
const int MAXC =10;

typedef int tMatriz1[MAXF][MAXC];
tMatriz1 matrix1; //variable matriz1

typedef int tMatriz2 [MAXF][MAXC];
tMatriz2 matrix2;//variable matriz2

typedef int tMatriz3 [MAXF][MAXC];
tMatriz3 matrix_total;

typedef int tMatriz4 [MAXF][MAXC];
tMatriz4 matrix_tran;//variable matriz4

typedef int tMatriz5 [MAXF][MAXC];
tMatriz5 punto_silla;

int FM1,FM2, CM1, CM2;
int i,j,z;

void matrices();
void sumar();
void restar();
void multiplicar();
void MTA();
void MTB ();
void puntoSillaA();
void puntoSillaB();

int main()
{
   int op,op1;
   do
   {
        cout << "OPERACIONES DE DOS MATRICES" << endl;
        cout << "Elija una opcion: "<< endl;
        cout << "1.- Establecer matrices"<< endl
             << "2.- Sumar matrices"<< endl
             << "3.- Restar matrices"<< endl
             << "4.- Multiplicar matrices"<< endl
             << "5.- Trasposicion de matrices" << endl
             << "6.- Punto silla de una matriz" << endl
             << "7.- Salir"<< endl;
        cin>> op;

        switch(op)
        {
            case 1: //matrices
                    matrices();
                    break;
            case 2: //sumar
                    sumar();
                    break;
            case 3: // restar
                    restar();
                    break;
            case 4: //multiplicar
                    multiplicar();
                    break;
            case 5: //traspuesta
                     cout<< "MATRIZ A (1) O MATRIZ B (2)?";
                     cin>>op1;
                    switch (op1)
                    {
                        case 1:MTA(); break;
                        case 2:MTB(); break;
                    }
                    break;
            case 6://silla
                    cout<< "MATRIZ A (1) O MATRIZ B (2)?";
                    cin >> op1;
                     switch (op1)
                    {
                        case 1:puntoSillaA(); break;
                       // case 2://puntoSillaB(); break;
                    }
                    break;
            case 7:
                    default:
                      cout << "TERMINO PROGRAMA";
        }

   }while (op !=7);
   return 0;
}

void matrices()
{
    //establecer orden
    cout << "INGRESAR CANTIDAD DE FILAS DE LA MATRIZ A: ";
    cin >> FM1;
    cout << "INGRESAR CANTIDAD DE COLUMNAS DE LA MATRIZ A: ";
    cin >> CM1;
    cout << "INGRESAR CANTIDAD DE FILAS DE LA MATRIZ B: ";
    cin >> FM2;
    cout << "INGRESAR CANTIDAD DE COLUMNAS DE LA MATRIZ B: ";
    cin >> CM2;
    //VALORES DE MATRIZ 1
    for ( i = 0; i<FM1 ; i++)
    {
        for ( j = 0; j < CM1; j++)
            {
                cout << "INGRESE VALORES MATRIZ A ["<< i << "]:["<< j<<"] = ";
                cin >> matrix1[i][j];
            }
    }
    //VALORES DE MATRIZ 2
    for ( i = 0; i<FM2; i++)
    {
        for ( j = 0; j < CM2; j++)
            {
                cout << "INGRESE VALORES MATRIZ B ["<< i << "]:["<< j<< "] = ";
                cin >> matrix2[i][j];
            }
    }
}

void sumar()
{
    if (FM1!= FM2 || CM1!=CM2)
    {
        cout << "ERROR. LAS DIMENCIONES DE LAS MATRICES DEBEN SER IGUALES";
    }
    else
    {
         cout<< "LA SUMA DE LAS MATRICES ES: "<< endl;
        for ( i = 0; i < FM1 ; i++)
        {
           for ( j = 0; j < CM2; j++)
            {
                matrix_total[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
     for ( i = 0; i < FM1 ; i++) //mostrar resultado
        {
            for ( j = 0; j < CM2 ; j++)
            {
                cout<< matrix_total [i][j]<< " ";
            }
            cout<< endl<< endl;
        }

}

void restar()
{
    if (FM1!= FM2 || CM1!=CM2)
    {
        cout << "ERROR. LAS DIMENCIONES DE LAS MATRICES DEBEN SER IGUALES";
    }
    else
    {
        cout<< "LA RESTA DE LAS MATRICES ES: "<< endl;
        for ( i = 0; i < FM1 ; i++)
        {
           for ( j = 0; j < CM2; j++)
            {
               matrix_total[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }
     for ( i = 0; i < FM1 ; i++) //mostrar resultado
        {
            for ( j = 0; j < CM2 ; j++)
            {
                cout<< matrix_total [i][j]<< " ";
            }
            cout<< endl<< endl;
        }
}

void multiplicar()
{
     for ( i = 0; i < FM1 ; i++)
            for ( j = 0; j < CM2 ; j++)
            { matrix_total [i][j]= 0;}

    if(CM1 != FM2)
    {
       cout<< "ERROR: DEBEN COINCIDIR COLUMNAS DE MATRIZ A CON FILAS DE MATRIZ B  "<< endl;
    }
    else
    {
         cout << "EL PRODUCTO DE MATRICES ES "<< endl;
        for ( i = 0; i < FM1 ; i++)
        {
            for ( j = 0; j < CM2 ; j++)
            {
               for (z =0 ; z < CM1; z++ )
               {
                   matrix_total [i][j] += matrix1[i][z] * matrix2[z][j];
                }
            }
        }
    }
     for ( i = 0; i < FM1 ; i++) //mostrar resultado
        {
            for ( j = 0; j < CM2 ; j++)
            {
                cout<< matrix_total [i][j]<< " ";
            }
            cout<< endl<< endl;
        }
}

void MTA ()
{

     cout << "LA MATRIZ TRANSPUESTA DE A ES"<< endl;
    for ( i = 0; i<FM1 ; i++)
    {
        for ( j = 0; j < CM1; j++)
        {
            cout << matrix1[j][i] << " ";
        }
        cout<< endl;
    }
}

void MTB ()
{
    cout << "LA MATRIZ TRANSPUESTA DE B ES"<< endl;
    for ( i = 0; i<FM2 ; i++)
    {
        for ( j = 0; j < CM2; j++)
        {
            cout << matrix2 [j][i] << " ";
        }
        cout<< endl;
    }
}
void puntoSillaA()
{
    int mayor;
    int menor;

    for (i=0; i<FM1; i++)
    {
        for (j=0; j<CM1; j++)
        {
            if (matrix1[i][j] > matrix1[i++][j++])
            {
                menor= matrix1 [i++][j++];
            }
           if (matrix1[j][i] > matrix1[j++][i++])
           {
             mayor= matrix1 [i][j];
           }
        }
    }

    if(menor == mayor)
    {
        cout << "el numero silla es ["<< i<<"]:["<<j<<"] "<< mayor<<endl;
    }
    else{cout<< "NO SE ENCONTRO EL PUNTO DE SILLA"<< endl;}
}
/*void puntoSillaB()
{
    for(int i=0; i<FM2 ; i++)
		{
			for(int j=0; j<CM2 ; j++)
			{
                if (matrix1[i][j]> maxfilasA[i])
                {
                    maxfilasA[i] = matrix1[i][j];
                }
                if (matrix1[i][j]< mincolumnasA[j])
                {
                     mincolumnasA[j] = matrix1[i][j];
                }
		    }
	    }
    for(int i = 0; i<FM2 ;i++)
    {
		    for(int j = 0; j<CM2 ; j++)
		    {
			    if(maxfilasA[i]== mincolumnasA[j])
			    {
			    	cout << "EL PUNTO SILLA ES : " << i << " : " << j << endl;
			    	 cout<< endl;
			    }
			    else
			    {
			    	cout << "NO SE HA ENCONTRADO PUNTO SILLA." << endl;
			    }
		    }
    }
}*/

