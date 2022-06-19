#include "PilaCola.h"
#include <stdio.h>
#include <stdlib.h>

Cola *crearCola() {
    Cola *cola = (Cola *) malloc(sizeof (Cola));

    if (cola == NULL){
        printf("No hay memoria libre");
        exit(-1);
    }

    cola->tam = 0;
    cola->primero = NULL;

    return cola;
}

Cola *encolarPila(Pila *pila){
    Nodo *aux = pila->primero;
    Cola *nueva = crearCola();

    while(aux != NULL){
        Nodo *sig = aux->siguiente;
        aux->siguiente = NULL;
        encolarNodo(nueva, aux);
        aux = sig;
    }

    return nueva;
}

void encolarNodo(Cola *cola, Nodo *nuevo) {
    Nodo *aux = cola->primero;

    if (aux == NULL){
        cola->primero = nuevo;
        cola->tam++;
        return;
    }

    for (; aux->siguiente != NULL; aux = aux->siguiente){}

    aux->siguiente = nuevo;
    cola->tam++;
}

void imprimirCola(Cola *cola) {
    Nodo *aux = cola->primero;

    if (aux == NULL){
        printf("La cola esta vacía.\n");
        return;
    }

    printf("\nCola:\n");
    for (;aux != NULL; aux = aux->siguiente) {
        printf("%d ", aux->codigo);
    }
    printf("\n");
}

void liberarCola(Cola *cola){
    Nodo *aux = cola->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Nodo *ant = aux;
            aux = aux->siguiente;
            free(ant);
        }

        free(aux);
    }

    free(cola);
}

// ----------------------------------------- Código Pila -----------------------------------------
Pila *crearPila(){
    Pila *pila = (Pila*) malloc(sizeof (Pila));

    if(pila == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    pila->tam = 0;
    pila->primero = NULL;

    return pila;
}

Pila *apilarCola(Cola *cola){
    Nodo *aux = cola->primero;
    Pila *nueva = crearPila();

    while(aux != NULL){
        Nodo *sig = aux->siguiente;
        aux->siguiente = NULL;
        apilar(nueva, aux);
        aux = sig;
    }

    return nueva;
}

void apilar(Pila *pila, Nodo *nodoAInsertar){
    nodoAInsertar->siguiente = pila->primero;
    pila->primero = nodoAInsertar;
    pila->tam++;
}

void imprimirPila(Pila *pila){
    Nodo *aux = pila->primero;

    if(aux == NULL){
        printf("La lista esta vacía.\n");
        return;
    }

    printf("\nPila:\n");
    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->codigo);
    }

    printf("\n");
}

void liberarPila(Pila *pila){
    Nodo *aux = pila->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Nodo *ant = aux;
            aux = aux->siguiente;
            free(ant);
        }

        free(aux);
    }

    free(pila);
}


