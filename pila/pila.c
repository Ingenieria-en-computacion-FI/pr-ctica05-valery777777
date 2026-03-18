#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


Pila* pila_crear()
{
    Pila *p;
    p=(Pila*)malloc(sizeof(Pila));
    p->head=NULL;
    p->tail=NULL;
    return p;
}

bool pila_vacia(Pila* pila)
{
    if(pila->head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void pila_push(Pila* pila, int dato)
{
    Nodo *NewNode=nodo_crear(dato);
    if(pila_vacia(pila)){
        pila->head=pila->tail=NewNode;
    }else{
        pila->tail->siguiente=NewNode;
        pila->tail=NewNode;
    }
}

int pila_pop(Pila* pila)
{
    if(pila_vacia(pila))
        return -1;
    int dato=pila->tail->dato;

    if(pila->head==pila->tail){
        nodo_destruir(pila->head);
        pila->head=pila->tail=NULL;
    }else{
        Nodo *actual=pila->head;
        while(actual->siguiente != pila->tail){
            actual = actual->siguiente;
        }
        nodo_destruir(pila->tail);
        pila->tail=actual;
        pila->tail->siguiente=NULL;
    }
    return dato;
}

int pila_top(Pila* pila)
{
    return pila->head->dato;
}

void pila_destruir(Pila* pila)
{
    while(!pila_vacia(pila)){
        pila_vacia(pila);
            pila_pop(pila);
        free(pila);
        pila=NULL;
    }
}
