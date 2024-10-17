#include<stdio.h>
#include<stdlib.h>

//DEFINICIÓN DE UN NODO

typedef struct{
    //definición de la estructura
    int nro; //por ejemplo
}Item;

typedef struct Elemento{
    Item dato; //creamos un campo que nos permita almacenar nuestro item
    struct Elemento *siguiente; //creamos el campo siguiente, puntero al tipo de dato que estoy creando, estructura autoreferenciada
}Nodo; //nombramos el tipo de dato como nodo


/*-----------------------------------------------------------------
DECLARACIÓN DE LISTA VACÍA*/

//cuando creamos la lista no tiene elementos, por tanto la cabeza al contener el primer elemento de la lista está vacía
Nodo *crear_lista(){
    Nodo *cabeza = nullptr; /*esto es un puntero a Nodo que tiene un valor null
    nullptr significa un puntero que no apunta a ninguna dirección de memoria*/
    return cabeza;
}

/*-----------------------------------------------------------------
CREACIÓN DE UN NODO*/ 

Nodo *crear_nodo(Item x){ //Item es el tipo
    Nodo *a; //definimos un puntero a nodo
    a = (Nodo*) malloc(sizeof(Nodo)); /*cast explícito para convertir de void* a Nodo. A ese puntero le asignamos la dirección del bloque de memoria que se reserva para almacenar los datos del nodo
    llamamos a la función malloc y le enviamos el tamaño en bytes de la función Nodo y asignamos la dirección al puntero a Nodo a*/
    a->dato=x; //utilizamos la notación de flecha para acceder a los campos de esa estructura Nodo
    a->siguiente=nullptr; //y como todavía no sabemos a donde va a apuntar le asignamos un valor nulo
    return a; //retornamos la dirección de ese nodo
}

/*-----------------------------------------------------------------
INSERTAR UN ELEMENTO AL INICIO*/

void inser_inicio(Nodo **cabeza, Item entrada){ /*puntero doble a nodo, usamos puntero doble, un puntero que apunta a otro puntero, 
vamos a modificar el valor original del puntero que estamos enviando, si enviamos un puntero simple solo mandaremos una copia de esa direccón
y modificariamos solo esa copia. Enviamos la dirección del puntero con un puntero doble*/
    Nodo *nuevo; 
    nuevo = crear_nodo(entrada); //le asignamos la dirección del nuevo nodo que creamos
    nuevo->siguiente = *cabeza; //para que apunte al siguiente, osea el anterior primero
    *cabeza = nuevo; //acá reasignamos este nodo como el principio
}

/*-----------------------------------------------------------------
INSERTAR UN ELEMENTO AL INICIO*/
void inser_final(Nodo **cabeza, Item entrada){
    Nodo *ultimo;
    ultimo=*cabeza;
    if(ultimo==nullptr){//caso particular
        *cabeza=crear_nodo(entrada);
    }
    else{//vamos hasta el último nodo
        while(ultimo->siguiente!=nullptr) ultimo = ultimo->siguiente;
        ultimo->siguiente = crear_nodo(entrada);
    }
}

/*-----------------------------------------------------------------
MOSTRAR ELEMENTOS DE LA LISTA*/

void imprimir_lista(Nodo *cabeza){ //dirección del primer elemento
    Nodo *actual;
    printf("La lista es: \n");
    for(actual=cabeza; actual!=nullptr; actual=actual->siguiente) /*actual va iniciar en el primer nodo, 
    la condición para que el ciclo siga es que sea diferente de nulo, "i++" = "actual=actual->siguiente"*/
        printf("%d ", actual->dato.nro);
    printf("\n\n");
}

/*-----------------------------------------------------------------
BÚSQUEDA*/
Nodo *buscar(Nodo* cabeza, Item dato_buscado){
    Nodo *actual;
    for(actual=cabeza; actual!=nullptr ; actual=actual->siguiente)
        if(dato_buscado.nro == actual->dato.nro) return actual;
    return nullptr;
    
}

int main(){
    Nodo *cab = crear_lista(); //definimos una lista vacía
    int i;
    Item x;
    for(i=0;i<10;i++){//insertamos elementos a la lista, funciona como una pila
        x.nro = i;
        inser_final(&cab,x);
    }
    imprimir_lista(cab);

    //buscaremos el elemento 7
    x.nro = 7;
    Nodo *sal = buscar(cab,x); //devuelve el resultado a un puntero a nodo
    if(sal==nullptr) printf("No se encontró el dato %d en la lista \n", x.nro);
    else printf("El elemento %d está en la dirección: %p\n", x.nro,sal);

    //buscaremos el elemento 11
    x.nro = 11;
    sal = buscar(cab,x); //devuelve el resultado a un puntero a nodo
    if(sal==nullptr) printf("No se encontró el dato %d en la lista \n", x.nro);
    else printf("El elemento %d está en la dirección: %p\n", x.nro,sal);
}