/*Determinar si un numero insertado por teclado es par o impar,
dichas funciones se llamaran una a otra en cada llamada restará
una unidad al numero instertado hasta que este se convierta en cero,
cuando sea cero se devuelve la información sobre si era par o impar*/
#include <iostream>
using namespace std;

float impar(float num, float *aux);

float par(float num, float *aux)
{
    if (num == 0)
    {
        cout << "El número ingresado " << aux << " es par";
    }
    else
    {
        num = num - 1;
        impar(num, *aux);
    }
    return 0;
}

float impar(float num, float *aux)
{
    if (num == 0)
    {
        cout << "El número ingresado " << aux << " es impar";
    }
    else
    {
        num = num - 1;
        par(num, *aux);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    float num = 0, aux = 0;
    cout << "Ingrese un número\n";
    cin >> num;
    aux = num;
    par(num, *aux);

    return 0;
}
