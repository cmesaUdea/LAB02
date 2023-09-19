#include <iostream>

using namespace std;

//Función para el problema 2
void contarFrecuencia (char arreglo[],int frecuencia[]){
    // Funcion para el Problema 2
    for (int i = 0; i < 200; i++){
        frecuencia[arreglo[i] - 65]++;
    }

}

void imprimirFrecuencia (int frecuencia[]){
    // Funcion para el Problema 2
    for (int i = 0; i < 26 ; i++){
        if (frecuencia[i] > 0){
            cout<<(char)('A' + i)<<": "<<frecuencia[i]<<endl;
        }
    }
}

//Función para el problema 3
bool parecidas_o_no(char arreglo_1[],char arreglo_2[])
{
    // Funcion para el Problema 3

    char *puntero_1 = arreglo_1;
    char *puntero_2 = arreglo_2;

    while (*puntero_1 != '\0' and *puntero_2 != '\0' and *puntero_1 == *puntero_2 ){
        puntero_1++;
        puntero_2++;
    }

    if (*puntero_1 == '\0' and *puntero_2 == '\0'){

        return true;
    }

    else {
        return false;
    }

}

//Función para el problema 4
int cadena_numerica (char numero[])
{
    // Funcion para el Problema 4

    int longitud = sizeof(numero) / sizeof(numero[0]); // Obtener la longitud del arreglo
    int numero_convertido[longitud]; // Crear un arreglo de enteros del mismo tamaño
    int contador = 0;

    for (char *recorrido = numero; *recorrido != '\0'; recorrido++) {
        numero_convertido[contador] = *recorrido - '0';
        contador++;
    }

    int resultado = 0;

    for (int i = 0; i < contador; i++) {
        resultado = resultado * 10 + numero_convertido[i];
    }

    return resultado;

}

//función para el prblema 5
void cadena_caracteres(int numero_entero, char *& numero_caracter)
{
    // Funcion para el Problema 5

    int numero = numero_entero;
    int digitos = 0;

    while ( numero != 0)
    {
        numero = numero / 10; // En esta parte se cuentan el numero de digitos que tiene el numero
        digitos++;

    }

    numero_caracter = new char[digitos + 1];

    numero_caracter[digitos] = '\0';

    for (int i = digitos - 1; i >= 0; i-- ){
        numero_caracter[i] = 48 + numero_entero % 10;
        numero_entero = numero_entero / 10;
    }

}

//Función para el problema 7
bool verificacion (char letra,char ConjuntoLetras[]){
    int cont=0;
    bool existe = false;

    //contar letras
    while(ConjuntoLetras[cont]!='\0')
        cont++;

    //Comparar
    for(int i=0;i<cont;i++){
        if(letra==ConjuntoLetras[i]){   //aqui miramos si la letra pasada a la funcion esta en la cadena sin caracteres repetidos
            existe = true;
            break;
        }
    }
    //cout<<letra<<"-"<<ConjuntoLetras<<"-"<<existe<<endl;
    return existe;
}

//Funciones para el problema 8
void imprimirletras(string palabra)
{


    for (int i = 0; i < palabra.length(); i++) {
        char c = palabra[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            cout << c << " ";
        }
    }
    cout << endl;
}

void imprimirnumeros(string palabra)
{


    for (int i = 0; i < palabra.length(); i++) {
        char c = palabra[i];
        if (c >= '0' && c <= '9') {
            cout << c << " ";
        }
    }
    cout << endl;
}



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



    case 2:
    /* Problema 2. Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
    y luego imprima cuantas veces se repite cada letra en el arreglo.
    Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABARSECAAB
    A: 4
    B: 2
    C: 1
    Y así sucesivamente.*/

    {
        char mayus[200]; // Se crea el arreglo de letras con 200 letras

        int frecuencia[26] = {0}; // Se crea para comparar con las letras que salen y contar cuantas veces sale la letra

        for (int i = 0; i < 200 ; i++){
            mayus [i] = 'A' + rand() % 26;

        }

        cout <<"El arreglo con 200 letras mayusculas es: "<<mayus<<endl;

        contarFrecuencia(mayus,frecuencia);
        cout<<"Frecuencia de cada letra:"<<endl;
        imprimirFrecuencia(frecuencia);
        break;
    }

    case 3:
    /* Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
    iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
    de prueba. */
    {
        char lista_caracter_1 [200],lista_caracter_2 [200];
        bool veredicto;


        cout<<"Ingrese la primera cadena de caracteres: "<<endl;
        cin>>lista_caracter_1;

        cout<<"Ingrese la segunda cadena de caracteres: "<<endl;
        cin>>lista_caracter_2;

        veredicto = parecidas_o_no(lista_caracter_1,lista_caracter_2);

        if (veredicto == true){
            cout<<"La cadenas de caracteres ingresadas son iguales"<<endl;
        }

        else{
            cout<<"Las cadenas de caracteres ingresadas NO son iguales"<<endl;
        }

        break;
    }

    case 4:

    /* Problema 4. Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
    y retorne dicho número. Escriba un programa de prueba.
    Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.*/
    {
        char numero_usuario[100];
        int numero_final = 0;

        cout<<"Ingrese el numero, se capturara como caracter: "<<endl;
        cin>>numero_usuario;

        numero_final = cadena_numerica(numero_usuario);

        cout<<"El numero convertido es: "<<numero_final<<endl;

        break;
    }

    case 5:
    /*Problema 5. Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use
    parámetros por referencia para retornar la cadena. Escriba un programa de prueba.
    Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”. */
    {
        int n = 0;
        char *numero_caracter;

        cout<<"Ingrese un numero: "<<endl;
        cin>>n;

        cadena_caracteres ( n, numero_caracter);

        cout<<"El numero ingresado: "<<n<<" convertido a cadena es: "<<numero_caracter<<endl;

        delete[]numero_caracter;

        break;
    }

    case 6:

    // Problema 6.

    /* Problema 6. Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas,
    los demás caracteres no deben ser alterados.
    Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
    Nota: la salida del programa debe ser: Original: Man-zana. En mayuscula: MAN-ZANA.*/

    {
        int cont=0,i;
        char Mayus[20]={};
        cout<<"Ingrese una cadena de caracteres"<<endl;
        cin>>Mayus;
        while(Mayus[cont]!='\0')
            cont+=1;
        for(i=0;i<=cont;i++){
            if(Mayus[i]>=97 and Mayus[i]<=122)  //Aqui el 97 y 122 es por quue en ese intervalo estan las letras minusculas en la tablas ascii
                Mayus[i]=Mayus[i]-32;           //y aqui se le resta 32 al valor de la letra minuscula por que asi se obtiene la misma letras en mayuscula
            else
                cout<<Mayus<<endl;
        }
        break;
    }

    case 7:

    /* Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
    Ejemplo: se recibe bananas debe mostrar bans.
    Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans. */
    {
        int i=0,j=0,cont=0;
        char CaracOriginal[20]={};
        char CaracNRep[20]={};
        bool TF;
        cout<<"Ingrese una palabra"<<endl;
        cin>>CaracOriginal;

        while(CaracOriginal[cont]!='\0')
            cont++;

        //en el primer for me paro en la posicion CaracOriginal[0] y en el segundo for  me paro en la posicion cero +1
        //luego el primer if pregunto que si la posicion CaracOriginal[0] es diferente a CaracOriginal[1] debo agregar esa posicion cero
        //en  la posicion CaracNRep[0] pero antes debo recorrer CaracNRep y preguntar si la la posicion CaracOriginal[0] ya estaba
        //agregada, y si lo estaba pues no la agrego
        for(i=0, j=0;i<cont;i++){
            TF=verificacion(CaracOriginal[i],CaracNRep);
            if(TF==false){
                CaracNRep[j]=CaracOriginal[i];
                j++;
            }
        }
        cout<<CaracNRep<<endl;
        break;
    }

    case 8:

    /* Problema 8. Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
    generando una cadena que no tiene números y otra con los números que había en la cadena original.
    Ejemplo: Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
    Nota: la salida del programa debe ser:
    Original: abc54rst.
    Texto: abcrst. Numero: 54.*/

    cout << "Pendiente" << endl;

    break;


    case 9:

    /* Problema 9. Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
    debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
     dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
    Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
    Nota: la salida del programa debe ser:
    Original: 87512395.
    Suma: 994. */

    {
        int n=0,cond=0,acum=0,it=0,acum1=0,cambio=1;
        cout << "Ingrese n: ";
        cin>>n;
        char arreglo[] = "87512395";
        cout<< "Ingrese el arreglo: ";cin>>arreglo;
        //int longitud = sizeof(arreglo);
        int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
        //cout<<longitud<<endl;
        int paso = longitud-1 ;

        while(cond!=n){
            while(it!=n){
                if(paso<0){
                    break;}
                else{
                    acum += (arreglo[paso] - '0') * cambio;
                    paso--;
                    cambio*=10;
                    it++;
                }
            }
            acum1+=acum;
            acum=0;
            cond++;
            it=0;
            cambio=1;

        }
        cout<<"Original: "<<arreglo<<endl;
        cout<<"Suma: "<<acum1<<endl;
        break;

    }

    case 10:

    {
        int cont=0,i,j,suma=0,k=0;
        char NumRomanos[7]={'M','D','C','L','X','V','I'};
        int  NumEquivalentes[7]={1000,500,100,50,10,5,1};
        char Letras[10]={};
        int Numero[10]={};
        cout<<"Ingrese el numero romano a convertir en MAYUSCULAS"<<endl;
        cin>>Letras;
        while(Letras[cont]!='\0')     //Para saber la longitud del numero romano ingresado
            cont++;
        for(i=0;i<cont;i++){
            for(j=0;j<7;j++){
                if (Letras[i]==NumRomanos[j]){   //aqui recorro cada letra del numero romano ingresado y las comparo con el arreglo NumRomanos
                    Numero[i]=NumEquivalentes[j];//aqui si coinciden las letras en el anterior if les asigno el valor correspondiente al sistema arabigo
                }
            }
        }
        //aqui ya hemos almacenado todos los valores del numero ingresado por el usuario
        for (k=0;k<10;k++){
            if (Numero[k]>Numero[k+1]) //aqui comparamos el numero en la posicion k con el de la posicion k+1 y si es mayor lo sumamos
                suma+=Numero[k];
            else if (Numero[k]<Numero[k+1]) //aqui el caso contrario si es menor lo restamos
                suma-=Numero[k];
            else					//aqui es el default por si depronto solo se ingreso solo una letra
                suma+=Numero[k];
        }
        cout<<suma<<endl;
        break;
    }


   }
    return 0;
}
