#include <stdlib.h>
#include "nodo.h"

Nodo* nodo_crear(int d)
{
    Nodo *n;
    n=(Nodo *)malloc(sizeof(Nodo));
    if(n!=NULL){
    n->siguiente=NULL;
    n->dato=d;
    }
    return n;
}

void nodo_destruir(Nodo* nodo)
{
    if(!nodo->siguiente){
        free(nodo);
    }
}
