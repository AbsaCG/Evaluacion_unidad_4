#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo
struct Nodo {
    int valor;
    string mensaje;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v, string m) : valor(v), mensaje(m), izquierda(NULL), derecha(NULL) {}
};

// Insertar nodo en el árbol binario
Nodo* insertarNodo(Nodo* raiz, int valor, string mensaje) {
    if (raiz == NULL) {
        return new Nodo(valor, mensaje);
    }

    if (valor < raiz->valor) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor, mensaje);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertarNodo(raiz->derecha, valor, mensaje);
    } else {
        cout << "El nodo con valor " << valor << " ya existe." << endl;
    }
    return raiz;
}

// Recorridos
void preOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << ": " << raiz->mensaje << endl;
        preOrden(raiz->izquierda);
        preOrden(raiz->derecha);
    }
}

void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierda);
        cout << raiz->valor << ": " << raiz->mensaje << endl;
        inOrden(raiz->derecha);
    }
}

void postOrden(Nodo* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierda);
        postOrden(raiz->derecha);
        cout << raiz->valor << ": " << raiz->mensaje << endl;
    }
}

// Módulo independiente para buscar un nodo y mostrar el mensaje
void buscarYMostrarMensaje(Nodo* raiz, int valorBuscado) {
    if (raiz == NULL) {
        cout << "No se encontró un mensaje para el número ingresado." << endl;
        return;
    }

    if (valorBuscado == raiz->valor) {
        cout << "Carrera recomendada: " << raiz->mensaje << endl;
    } else if (valorBuscado < raiz->valor) {
        buscarYMostrarMensaje(raiz->izquierda, valorBuscado);
    } else {
        buscarYMostrarMensaje(raiz->derecha, valorBuscado);
    }
}

int main() {
    Nodo* raiz = NULL;

    // Insertar nodos iniciales según tabla de la consigna
    raiz = insertarNodo(raiz, 10, "Quieres Estudiar");
    raiz = insertarNodo(raiz, 2, "Estudia LETRAS");
    raiz = insertarNodo(raiz, 1, "Estudia DERECHO");
    raiz = insertarNodo(raiz, 3, "Estudia ADMINISTRACION");
    raiz = insertarNodo(raiz, 6, "Estudia NÚMEROS");
    raiz = insertarNodo(raiz, 5, "Estudia FISICA");
    raiz = insertarNodo(raiz, 7, "Estudia INGENIERÍA");

    int opcion, valor;
    string mensajeNuevo;

    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Insertar nodo o hoja\n";
        cout << "2. Mostrar recorrido Inorden\n";
        cout << "3. Mostrar recorrido Preorden\n";
        cout << "4. Mostrar recorrido Postorden\n";
        cout << "5. Buscar y mostrar carrera segun el numero\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa el numero para el nuevo nodo: ";
                cin >> valor;
                cout << "Ingresa el mensaje de recomendacion de carrera: ";
                cin.ignore(); // limpiar buffer
                getline(cin, mensajeNuevo);
                raiz = insertarNodo(raiz, valor, mensajeNuevo);
                cout << "Nodo insertado correctamente.\n";
                break;
            case 2:
                cout << "\nRecorrido Inorden:\n";
                inOrden(raiz);
                break;
            case 3:
                cout << "\nRecorrido Preorden:\n";
                preOrden(raiz);
                break;
            case 4:
                cout << "\nRecorrido Postorden:\n";
                postOrden(raiz);
                break;
            case 5:
                cout << "Ingresa el numero del nodo a buscar: ";
                cin >> valor;
                buscarYMostrarMensaje(raiz, valor);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo." << endl;
        }
    } while(opcion != 6);

    return 0;
}
