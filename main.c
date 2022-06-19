#include <stdio.h>
#include <stdlib.h>
#include "src/PilaCola.h"

void puntoA();
void puntoB();

int main() {

    puntoA(); // Se invierte la cola
    puntoB(); // Se invierte la pila

    return 0;
}

void puntoA(){
    Cola *cola = crearCola();

    encolarNodo(cola, crearNodo(43));
    encolarNodo(cola, crearNodo(435));
    encolarNodo(cola, crearNodo(543));
    encolarNodo(cola, crearNodo(87));
    encolarNodo(cola, crearNodo(9));

    imprimirCola(cola);

    Pila *pila = apilarCola(cola);
    imprimirPila(pila);

    Cola *colaNueva = encolarPila(pila);
    imprimirCola(colaNueva);

    liberarCola(colaNueva);
    free(pila);
    free(cola);
}

void puntoB() {
    Pila *pila = crearPila();

    apilar(pila, crearNodo(321));
    apilar(pila, crearNodo(43));
    apilar(pila, crearNodo(423));
    apilar(pila, crearNodo(65));
    apilar(pila, crearNodo(8675));
    apilar(pila, crearNodo(23));
    apilar(pila, crearNodo(1));

    imprimirPila(pila);

    Cola *cola = encolarPila(pila);
    imprimirCola(cola);

    Pila *pilaNueva = apilarCola(cola);
    imprimirPila(pilaNueva);

    liberarPila(pilaNueva);
    free(cola);
    free(pila);
}
