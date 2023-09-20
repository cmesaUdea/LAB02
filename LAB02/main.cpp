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

//Funciones para el problema 11
char resycan(char arreglo[15][20], string seleccion)
{
    // Funcion para el Problema 11

    int t = 0;
    char des[3];
    int fila = seleccion[4]- 65;
    int columna;

    if(seleccion[7]-48 >= 0 and seleccion[7]-48 <= 9){
        columna =((seleccion[6]-48)*10) + (seleccion[7]-49);
    }
    else{
        columna = seleccion[6]-49;
    }
    if(fila < 0 or fila >= 15){
        cout << endl;
        cout << "Comando incorrecto." << endl;
        return arreglo[15][20];
    }
    else if(columna < 0 or columna >= 20){
        cout << endl;
        cout << "Comando incorrecto." << endl;
        return arreglo[15][20];
    }
    for(int i=0; seleccion[i], i <=2; i++,t++){
        *(des+i) = seleccion[i];
    }
    if(des[0] == 'r'){
        if(*(*(arreglo+fila)+columna)== '+'){
            cout << endl;
            cout << "Asiento ya reservado, lamentablemente deberas buscar otro." << endl;
        }
        else{
            *(*(arreglo+fila)+columna) = '+';
        }
    }
    else if(des[0] == 'c'){
        if(*(*(arreglo+fila)+columna) == '-'){
            cout << endl;
            cout << "Este asiento no esta reservado." << endl;
        }
        else{
            *(*(arreglo+fila)+columna) = '-';
        }
    }
    return arreglo[15][20];
}

void printcinema(char arreglo[15][20])
{
    // Funcion para el Problema 11

    cout << endl << endl;
    cout << "Asientos disponibles en -, reservados en +." << endl;
    for(int i = 0; i < 15; i++){
        for(int t= 0; t < 20; t++){
            cout << arreglo[i][t] << " ";
        }
        cout << endl;
    }
}

//funciones para el problema 13
int ** llenarMatriz()
{
    // Funcion para el problema 13

    int **puntero_matriz;
    int nfilas;
    int ncol;

    cout<<"Digite el numero de filas: ";
    cin>>nfilas;
    cout<<"Digite el numero de columnas: ";
    cin>>ncol;

    puntero_matriz = new int*[nfilas];  //reservando memoria para la matriz
    for(int i=0;i<nfilas;i++){
        puntero_matriz[i]=new int[ncol];
    }
    cout<<endl;
    cout<<"Digite los elementos de la imagen: "<<endl;
    for(int i=0;i<nfilas;i++){
        for(int j=0;j<ncol;j++){
            cout<<"Digite el elemento["<<i+1<<"]["<<j+1<<"]: ";
            cin>>*(*(puntero_matriz+i)+j);
        }
    }
    return puntero_matriz;
}

int estrellas(int **puntero,int filas,int columnas)
{
    // Funcion para el problema 13

    int estrellas=0;

    for(int i=1;i<filas-1;i++){       //se recorre toda la matriz, sin tener en cuuenta los bordes
        for(int j=1;j<columnas-1;j++)
            if(((*(*(puntero+i)+j)+*(*(puntero+i)+j-1)+*(*(puntero+i)+j+1)+*(*(puntero+i-1)+j)+*(*(puntero+i+1)+j))/5)>6) //si se cumple la condicion se ha encontrado una estrella2
                estrellas++;
    }
    return estrellas;
}

//funciones para el problema 14
int ** memoria_dinamica(int dim)
{
    // Funcion para el problema 14

    int ** a;

    a = new int * [dim];

    for (int i = 0; i< dim; i ++)
    {
        a [i ] = new int [dim];

    }

    return a;
}

int ** generar_matriz(int dimension)
{
    // Funcion para el problema 14

    int ** matriz = memoria_dinamica(dimension);

    for(int f = 0; f < dimension; f++)
    {

        for(int c = 0; c < dimension; c++)
        {
            matriz[f][c] = (c+1) + dimension * f;
        }
    }

    return matriz;
}



void imprimir_matriz(int **matriz, int dimension)
{
    // Funcion para el problema 14

    for(int f = 0; f < dimension; f++)
    {

        for(int c = 0; c < dimension; c++)
        {
            cout<< matriz[f][c]<<"\t";
        }
        cout<<endl<<endl;
    }


}

int ** rotate_90 (int **matriz, int dimension)
{
    // Funcion para el problema 14

    int **R_matriz = memoria_dinamica(dimension);


    for(int f = 0; f < dimension; f++)
    {

        for(int c = 0; c < dimension; c++)
        {
            R_matriz[c][dimension - f- 1] = matriz[f][c] ;
        }
    }

    return R_matriz;
}

int *** rotate_matriz(int dim)
{
    // Funcion para el problema 14

    int *** conj_matriz = new int **[4];

    conj_matriz[0] = generar_matriz(dim);


    for (int i = 1; i<4; i++)
    {
        conj_matriz[i] = rotate_90(conj_matriz[i - 1],dim);
    }
    return conj_matriz;

}



void imprimir_conjunto_matriz(int ***conj_mat , int dim)
{
    // Funcion para el problema 14

    for (int i = 0; i < 4 ; i++)
    {
        cout<<"Matriz rotada "<<i*90<<" grados"<<endl<<endl;
        imprimir_matriz(conj_mat[i],dim);
        cout<<endl<<endl;
    }
}

//Funciones proble 15
int * interseccion_rectangulos_C(int A[],int B[]){
    // Funcion para el problema 15

    int ancho ,x,y,alto;
    if (A[1]<=B[0]){
        ancho=A[0]+A[2]-B[0];}
    else{ancho=B[0]+B[2]-A[0];}
    if (A[0]<=B[0]){
        x=B[0];}
    else{x=A[0];}
    if (B[1]<=A[1]){
        y=A[1];}
    else{y=B[1];}
    if (B[1]<=A[1]){
        alto=B[1]+B[3]-A[1];}
    else{alto=A[1]+A[3]-B[1];}
    static int C[]={x,y,ancho,alto};
    //cout<<"{"<<C[0]<<","<<C[1]<<","<<C[2]<<","<<C[3]<<"}"<<endl;
    return C;
}

//Funcion para el problema 16
int Factorial(int a){
    // Funcion para el problema 16

    long long int fact=1;
    if (a==0){
        return fact;
    }
    else if(a!=0){
        for (int i=1;i<= a;i++){
            fact*=i;
        }}

    return fact;
}

//Funcion problema 17
int sum_div(int n) { // función que calcula la suma de los divisores propios de n
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
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

    /* Problema 10. Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo
    usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su equivalente arábigo:
    M: 1000
    D: 500
    C: 100
    L: 50
    X: 10
    V: 5
    I: 1
    Los números romanos se forman usando estos caracteres en base a dos reglas:
    Si un carácter esta seguido por uno de igual o menor valor, su valor se suma al total.
    Si un carácter esta seguido por uno de mayor valor, su valor se resta del total.*/

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

    case 11:
    // Problema 11

    /* Problema 11. Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
    la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
    de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
    realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).*/

    {
        char sala[15][20];
        string seleccion;

        for(int i=0;i<15;i++){ //ciclos que generan el arreglo en dos dimensiones de la sala
            for(int j=0;j<20;j++){
                sala[i][j] = '-';
            }
        }
        printcinema(sala); //Impresión de la sala

        while(true){
            cout << "Indique el asiento a reservar o a cancelar. Ejemplo: 'can A-17', 'res B-20', ingrese x para salir" << endl;
            cout << "Comando: ";
            getline(cin, seleccion);

            if (seleccion == "x"){
                break;
            }

            sala[15][20] = resycan(sala, seleccion); //Utilización de la función que reserva y cancela
            printcinema(sala); //Impresión de la sala actualizada
        }
        break;
    }

    case 12:

    /* Problema 12. Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
    en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
    que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
    mágico.
    */

    {
        int n, numeros, sumatoria=0, sumatoria1=0, ban = 1;
        cout << "Ingrese el tamano de la matriz: ";
        cin >> n;
        int matriz[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matriz[i][j] = '0';
            }
        }
        while(true){
            for(int i=0;i<n;i++){
                for(int j=0; j<n;j++){
                    cout << "Ingrese un numero en la posicion: " << i << "," << j << ": ";
                    cin >> numeros;
                    matriz[i][j] = numeros;
                }
            }
            break;
        }


        for(int i=0;i<n;i++){
            sumatoria = 0;
            for(int j=0; j<n;j++){
                sumatoria += matriz[i][j];
            }
            if(sumatoria1==0){
                sumatoria1=sumatoria;
            }
            if(sumatoria1!=sumatoria){
                ban = 0;
                break;
            }
        }
        if(ban==1){
            for(int j=0;j<n;j++){
                sumatoria = 0;
                for(int i=0; i<n;i++){
                    sumatoria += matriz[i][j];
                }
                if(sumatoria1!=sumatoria){
                    ban = 0;
                    break;
                }
            }
        }
        if(ban==1){
            sumatoria = 0;
            int t = n-1;
            for(int i=0; i<n;i++){
                sumatoria += matriz[i][i];
            }
            if((sumatoria)!=sumatoria1){
                ban=0;
            }
            sumatoria = 0;
            for(int i=0; i<n;i++,t--){
                sumatoria += matriz[i][t];
            }
            if(sumatoria!=sumatoria1){
                ban=0;
            }
        }
        cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                if(matriz[i][j]/104 >= 1){
                    cout << matriz[i][j] << " ";
                }
                else{
                    cout << " " << matriz[i][j] << " ";
                }
            }
            cout << endl;
        }
        if(ban==1){
            cout << "La matriz es magica" << endl;
        }
        else{
            cout << "La matriz no es magica" << endl;
        }
        break;
    }

    case 13:

    /* Problema 13. Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a
    61.000.000 de años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz
    de números enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen, así:
    Elabore y pruebe una función que reciba un puntero a la matriz de enteros como argumento y que retorne el número
    de estrellas encontradas en la imagen. Ignore las posibles estrellas que puedan existir en los bordes de la matriz.*/

    {
        int **puntero=llenarMatriz();
        cout<<"El numero de estrellas es: "<<estrellas(puntero,6,8)<<endl;
        break;
    }

    case 14:

    /* Problema 14. Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
    imprima la matriz rotada 90, 180 y 270 grados. El profe lo hizo general, es decir, con un numero ingresado
    por el usuario */

    {
        int dim = 5;

        int *** m = rotate_matriz(dim);

        imprimir_conjunto_matriz(m,dim);

        break;
    }

    case 15:

    {
        int A[]={0,0,8,4};
        int B[]={5,2,3,2};
        int *zoe=interseccion_rectangulos_C(A,B);
        cout<<"{"<<zoe[0]<<","<<zoe[1]<<","<<zoe[2]<<","<<zoe[3]<<"}"<<endl;
        break;
    }

    case 16:
    {

        long long int n=0,fact1=0,fact2=0;
        cout<<"Ingrese un numero"<<endl;
        cin>>n;
        fact1=Factorial(n);
        cout<<"Para una malla de "<<n<<"x"<<n<<" hay ";
        n=n+n;
        fact2=Factorial(n);
        n=fact2/(fact1*fact1);
        cout<<n<<" caminos"<<endl;

    }

    case 17:
    {
        int n1, n2;
        cout << "Ingrese dos numeros: " << endl;
        cin >> n1 >> n2;
        int sum1 = sum_div(n1); // calcula la suma de los divisores propios de n1
        int sum2 = sum_div(n2); // calcula la suma de los divisores propios de n2
        if (sum1 == n2 && sum2 == n1) { // verifica si son amigos
        cout << n1 << " y " << n2 << " son numeros amigos." << endl;
        } else {
        cout << n1 << " y " << n2 << " no son numeros amigos." << endl;
        }
        break;

    }








   }
    return 0;
}
