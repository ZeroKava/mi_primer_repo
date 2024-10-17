#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int fila = 0;
    int columna = 0;
    float promedio=0;
    int contador = 0;
    int contador_i = 0;
    int contador_j = 0;
    int aux_fila = 0;
    int aux_columna = 0;

    cout << "Coloque el número de filas: \n";
    cin >> fila;
    cout << "Coloque el número de columnas: \n";
    cin >> columna;

    int matriz[fila][columna]; 
    float vector_fila[fila];
    float vector_columna[columna];

    //setear en 0 cada vector
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            vector_columna[j]=0;
            vector_fila[i]=0;
        }
    }

    // Almacenar elementos en la matriz
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            cout << "Coloque un número [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            promedio=promedio+matriz[i][j];
            contador++;
            vector_columna[j]=vector_columna[j]+matriz[i][j]; //si no ponele al revez
            vector_fila[i]=vector_fila[i]+matriz[i][j];
            /*contador_i=i; //siempre toma el último, así que no hace falta colocar if
            contador_j=j;*/
        }
    }
    
    //sacar el promedio en filas y columnas
    for (int i = 0; i < fila; i++) {
        vector_fila[i]=vector_fila[i]/fila;
    }
    for (int j = 0; j < columna; j++) {
        vector_columna[j]=vector_columna[j]/columna;
        }

   

    promedio=promedio/contador;

    // Mostrar la matriz
    cout << "\nLa matriz es:\n";
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n"; // Fin de la fila
    }

    if(columna==fila){
        cout<<"La matriz es cuadrada.";
    }
    else{
        cout<<"La matriz no es cuadrada.";
    }
    cout<< "\nEl promedio es: \n" << promedio;


    //Mostrar los promedios
    cout<< "\n Promedio de las filas: \n";
    for (int i = 0; i < fila; i++) {
        cout<<vector_fila[i] << endl;
    }
    cout<< "\n Promedio de las columnas: \n";
    for (int j = 0; j < columna; j++) {
        cout<<vector_columna[j] << endl;
        }
    getch(); //evita que el programa se cierre automaticamente
    return 0;
}