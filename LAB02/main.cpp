#include <iostream>

using namespace std;

int main()
{
    int opcion = 1;
    cout<<"Bienvenido a la entrega del Laboratorio 2 de Informatica 2"<<endl;
    cout<<"Elaborado por: Carlos Andres Mesa Roldan, estudiante de Ing. Telecomunicaciones"<<endl;
    cout<<"______________________________________________________________________________________"<<endl;
    cout<<"Ingrese 1 para revisar el Problema 1"<<endl;
    cout<<"Ingrese 2 para revisar el Problema 2"<<endl;
    cout<<"Ingrese 3 para revisar el Problema 3"<<endl;
    cout<<"Ingrese 4 para revisar el Problema 4"<<endl;
    cout<<"Ingrese 5 para revisar el Problema 5"<<endl;
    cout<<"Ingrese 6 para revisar el Problema 6"<<endl;
    cout<<"Ingrese 7 para revisar el Problema 7"<<endl;
    cout<<"Ingrese 8 para revisar el Problema 8"<<endl;
    cout<<"Ingrese 9 para revisar el Problema 9"<<endl;
    cout<<"Ingrese 10 para revisar el Problema 10"<<endl;
    cout<<"Ingrese 11 para revisar el Problema 11"<<endl;
    cout<<"Ingrese 12 para revisar el Problema 12"<<endl;
    cout<<"Ingrese 13 para revisar el Problema 13"<<endl;
    cout<<"Ingrese 14 para revisar el Problema 14"<<endl;
    cout<<"Ingrese 15 para revisar el Problema 15"<<endl;
    cout<<"Ingrese 16 para revisar el Problema 16"<<endl;
    cout<<"Ingrese 17 para revisar el Problema 17"<<endl;
    cout<<"Ingrese 18 para revisar el Problema 18"<<endl;
    cout<<"______________________________________________________________________________________"<<endl;
    cout<<"Si ingresa una opcion invalida, saldra del programa."<<endl;
    cout<<"Ingrese la opcion: "<<endl;

    cin>>opcion;

    switch (opcion) {
    case 1:
    // Problema 1.

    /*Problema 1. Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para
    una cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000
    y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el número de billetes
    y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas
    disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Use arreglos
    y ciclos para realizar el programa.
    Ejemplo: si se ingresa 47810, el programa debe imprimir:
    50000 : 0
    20000: 2
    10000 : 0
    5000: 1
    2000 : 1
    1000: 0
    500 : 1
    200: 1
    100 : 1
    50: 0
    Faltante: 10 */

    {

        int money = 0;
        cout << "Ha elegido el problema 1" << endl;
        cout << "Ingrese una cantidad de dinero:"<<endl;
        cin >> money;

        int cambio[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};

        for(int i = 0; i <= 10; i++){
            cout << cambio[i] << " : "<<money/cambio[i] << endl;
            money = money - ( (money/cambio[i]) * cambio[i]);

            if (money == 0 || money < 50){
                cout << "Faltante: " << money<< endl;
                break;
            }
        }

        break;
    }
    }

    return 0;
}
