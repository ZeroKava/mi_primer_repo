//Directivas de Preprocesador

#include<stdio.h> //cabecera estandar de entrada y salida de datos, este ocupa printf
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.1416 //una macro

int y = 7; //variable global

int main(){
    int x = 10; //variable local

    float suma = PI + x;

    printf("La suma es: %.2f", suma); //acá transformé a entero, % es para mostrar el tipo, y el .2 es para mostrar solo 2, y los redondea

    return 0;
}
