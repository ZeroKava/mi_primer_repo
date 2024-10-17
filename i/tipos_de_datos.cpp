#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    char a = 'e'; /*tamaño= 1byte Rango: 0 a 255
    si usas comillas dobles no te va a dar
    si no se coloca un un puntero no sabe de donde buscar la primera letra, solo es UNA letra
*/

    string s0 ("Hola Buen dia bendiciones");//s0 marca el primer string
    short b = -15; //tamaño= 2bytes Rango: -128 a 127, se muestra con %i
    int c = 1024; //tamaño= 2bytes Rango: 32768 a 322767
    unsigned int d = 128; //tamaño= 2bytes Rango: 0 a 65535
    long e = 123456; //tamaño= 4bytes Rango: -2 147 483 648 a -2 147 483 637, se pone %li
    float f = 10.568; //tamaño=4bytes Rango: 3.4*(10) a 3.4*(10), se pone %f
    double m = 123123.123123; //tamaño=8bytes 1.7*(10) a 1.7*(10)
    char* p = "holiwi uwu"; // Puntero a char


    printf("Char: %c\n", a);           // char
    printf("String: %s\n", s0.c_str()); // string as C-string
    printf("Short: %d\n", b);                     // short
    printf("Int: %d\n", c);                       // int
    printf("Unsigned int: %u\n", d);              // unsigned int
    printf("Long: %li\n", e);                     // long
    printf("Float: %.2f\n", f);                   // float (2 decimal places)
    printf("Double: %.6lf\n", m);                 // double (6 decimal places)
    printf("Char*: %s\n\n\n", p);    // char* 


    printf("Ahora con cout:\n");

    // Usando cout para imprimir las variables
    cout << "Char: " << a << endl;            // char
    cout << "String: " << s0 << endl;     // string
    cout << "Short: " << b << endl;                     // short
    cout << "Int: " << c << endl;                       // int
    cout << "Unsigned int: " << d << endl;              // unsigned int
    cout << "Long: " << e << endl;                      // long
    cout << "Float: " << f << endl;                     // float
    cout << "Double: " << m << endl;                    // double
    cout << "Char*: " << p << endl;       // char*

    return 0;

}