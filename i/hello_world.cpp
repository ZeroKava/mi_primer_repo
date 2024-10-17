#include <iostream> //esta libreria ocupa cout y cin
#include <vector> //define un vector similar a un array dinamico
#include <string> //soporte para trabajar con cadenas de caracteres en C++

using namespace std; //es para no poner std:: delante de coutm vector o string, se utiliza un espacio de nombres estandar 

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"}; //declara vector de tipo string llamado msg

    for (const string& word : msg)
    /*Se usa un bucle for de rango que itera sobre cada elemento del vector msg.
const string& word indica que, en cada iteración,
 word será una referencia constante a una cadena de texto del vector msg. 
 Se usa una referencia constante para evitar hacer copias innecesarias de 
 los elementos y garantizar que no se modifican.*/
    {
        cout << word << " ";
    }
    cout << endl;
}
