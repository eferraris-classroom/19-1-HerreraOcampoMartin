#ifndef INC_19_1_HERRERAOCAMPOMARTIN_PILACOLA_H
#define INC_19_1_HERRERAOCAMPOMARTIN_PILACOLA_H

#include "Nodo.h"

typedef struct pila {
    Nodo *primero;
    int tam;
} Pila;

typedef struct cola{
    int tam;
    Nodo *primero;
} Cola;


// ------- Pila -------
Pila *crearPila();
Pila *apilarCola(Cola *cola);
void apilar(Pila *pila, Nodo *nodoAInsertar);
void imprimirPila(Pila *pila);
void liberarPila(Pila *pila);

// ------- Cola -------
Cola *crearCola();
Cola *encolarPila(Pila *pila);
void encolarNodo(Cola *cola, Nodo *nuevo);
void imprimirCola(Cola *cola);
void liberarCola(Cola *cola);

#endif
