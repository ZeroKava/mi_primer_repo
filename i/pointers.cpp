#include <iostream>
using namespace std;

int main(){
    int x = 1; //declaramos x
    int *p_x = &x; /*Existe una diferencia al colocar el puntero "*" a la hora de declarar o llamarlo, cuando se declara
    significa que en esa posicion se almacena una direccion de memoria, cuando llamas ahí no te va a mostrar la direccion, sino
    que te manda a ella, y cuando se llama con * lo que haces es modificar la variable en memoria (usado en funciones)
    
    & es para sacar la dirección nomás*/
    int y = *p_x;
    cout << "Acá tenes Y: " << y;
}