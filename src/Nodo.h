#ifndef INC_19_1_HERRERAOCAMPOMARTIN_NODO_H
#define INC_19_1_HERRERAOCAMPOMARTIN_NODO_H

typedef struct nodo {
    int codigo;
    struct nodo *siguiente;
} Nodo;

Nodo *crearNodo(int codigo);

#endif
