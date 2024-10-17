#include <iostream>
using namespace std;

struct Libro {
    string codigo;
    string autor;
    string titulo;
    string editorial;
    float precio_unitario;
    int stock;
    Libro* siguiente;
};

struct Movimiento {
    string fecha;
    string codigo_libro;
    int cantidad_vendida;
    Movimiento* siguiente;
};

// Función para crear un nuevo movimiento
Movimiento* Crear_movimiento(string fecha, string codigo_libro, int cantidad_vendida) {
    Movimiento* nuevo_movimiento = new Movimiento;
    nuevo_movimiento->fecha = fecha;
    nuevo_movimiento->codigo_libro = codigo_libro;
    nuevo_movimiento->cantidad_vendida = cantidad_vendida;
    nuevo_movimiento->siguiente = nullptr;
    return nuevo_movimiento;
}

// Función para agregar un movimiento a la lista
void Agregar_movimiento_lista(Movimiento*& cabecera, Movimiento* nuevo_movimiento) {
    if (cabecera == nullptr) {
        cabecera = nuevo_movimiento;
    } else {
        Movimiento* actual = cabecera;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_movimiento;
    }
}

// Función para crear un nuevo libro
Libro* Crear_libro(string codigo, string autor, string titulo, string editorial, float precio_unitario, int stock) {
    Libro* nuevo_libro = new Libro;
    nuevo_libro->codigo = codigo;
    nuevo_libro->autor = autor;
    nuevo_libro->titulo = titulo;
    nuevo_libro->editorial = editorial;
    nuevo_libro->precio_unitario = precio_unitario;
    nuevo_libro->stock = stock;
    nuevo_libro->siguiente = nullptr;
    return nuevo_libro;
}

// Función para agregar un libro a la lista
void Agregar_libro_lista(Libro*& cabecera, Libro* nuevo_libro) {
    if (cabecera == nullptr) {
        cabecera = nuevo_libro;
    } else {
        Libro* actual = cabecera;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_libro;
    }
}

// Función para imprimir la lista de libros
void Imprimir_libros(Libro* cabecera) {
    Libro* actual = cabecera;
    while (actual != nullptr) {
        cout << "Codigo: " << actual->codigo << endl;
        cout << "Autor: " << actual->autor << endl;
        cout << "Titulo: " << actual->titulo << endl;
        cout << "Editorial: " << actual->editorial << endl;
        cout << "Precio Unitario: " << actual->precio_unitario << endl;
        cout << "Stock: " << actual->stock << endl;
        cout << "-------------------------------" << endl;
        actual = actual->siguiente;
    }
}

// Función para imprimir la lista de movimientos
void Imprimir_movimientos(Movimiento* cabecera) {
    Movimiento* actual = cabecera;
    while (actual != nullptr) {
        cout << "Fecha: " << actual->fecha << endl;
        cout << "Codigo Libro: " << actual->codigo_libro << endl;
        cout << "Cantidad Vendida: " << actual->cantidad_vendida << endl;
        cout << "-------------------------------" << endl;
        actual = actual->siguiente;
    }
}

// Función para cargar datos de un libro
Libro* Cargar_datos_libro() {
    string codigo, autor, titulo, editorial;
    float precio_unitario;
    int stock;

    cout << "Ingrese codigo del libro: ";
    cin >> codigo;
    cin.ignore();  // Para limpiar el buffer
    cout << "Ingrese autor del libro: ";
    getline(cin, autor);
    cout << "Ingrese titulo del libro: ";
    getline(cin, titulo);
    cout << "Ingrese editorial del libro: ";
    getline(cin, editorial);
    cout << "Ingrese precio unitario del libro: ";
    cin >> precio_unitario;
    cout << "Ingrese stock del libro: ";
    cin >> stock;

    return Crear_libro(codigo, autor, titulo, editorial, precio_unitario, stock);
}

// Función para cargar datos de un movimiento
Movimiento* Cargar_datos_movimiento() {
    string fecha, codigo_libro;
    int cantidad_vendida;

    cout << "Ingrese fecha de movimiento (YYYY-MM-DD): ";
    cin >> fecha;
    cout << "Ingrese codigo del libro: ";
    cin >> codigo_libro;
    cout << "Ingrese cantidad vendida: ";
    cin >> cantidad_vendida;

    return Crear_movimiento(fecha, codigo_libro, cantidad_vendida);
}

int main() {
    Libro* lista_libros = nullptr;
    Movimiento* lista_movimientos = nullptr;

    int opcion;
    do {
        cout << "Menu:\n";
        cout << "1. Agregar libro\n";
        cout << "2. Agregar movimiento\n";
        cout << "3. Imprimir lista de libros\n";
        cout << "4. Imprimir lista de movimientos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Libro* nuevo_libro = Cargar_datos_libro();
                Agregar_libro_lista(lista_libros, nuevo_libro);
                break;
            }
            case 2: {
                Movimiento* nuevo_movimiento = Cargar_datos_movimiento();
                Agregar_movimiento_lista(lista_movimientos, nuevo_movimiento);
                break;
            }
            case 3:
                Imprimir_libros(lista_libros);
                break;
            case 4:
                Imprimir_movimientos(lista_movimientos);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (opcion != 5);

    return 0;
}
