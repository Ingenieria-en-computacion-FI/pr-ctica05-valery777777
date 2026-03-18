#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

Lista* lista_crear()
{
    Lista *l;
    l=(Lista*)malloc(sizeof(Lista));
    l->head=NULL;
    l->tail=NULL;
    return l;
}

bool lista_vacia(Lista* l)
{
    if(l->head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void lista_insertar_head(Lista* l, int dato)
{
    Nodo *NewNode= nodo_crear(dato);

    if(lista_vacia(l)){
        l->head = l->tail = NewNode;
    }else{
        NewNode->siguiente = l->head;
        l->head = NewNode;
    }
}

void lista_insertar_tail(Lista* l, int dato)
{
    Nodo *NewNode=nodo_crear(dato);
    if(lista_vacia(l)){
        l->head=l->tail=NewNode;
    }else{
        l->tail->siguiente=NewNode;
        l->tail=NewNode;
    }
}

int lista_eliminar_head(Lista* l)
{
    if(lista_vacia(l))
        return -1;

    Nodo *tmp = l->head;
    int dato = tmp->dato;
    l->head=l->head->siguiente;

    if(lista_vacia(l))
        l->tail=NULL;

    nodo_destruir(tmp);
    return dato;
}

int lista_eliminar_tail(Lista* l)
{
    if(lista_vacia(l))
        return -1;
    int dato=l->tail->dato;

    if(l->head==l->tail){
        nodo_destruir(l->head);
        l->head=l->tail=NULL;
    }else{
        Nodo *actual=l->head;
        while(actual->siguiente != l->tail){
            actual = actual->siguiente;
        }
        nodo_destruir(l->tail);
        l->tail=actual;
        l->tail->siguiente=NULL;
    }
    return dato;
}

void lista_imprimir(Lista* l)
{
    Nodo* actual = l->head;

    while(actual != NULL)
    {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

void lista_destruir(Lista* l)
{
    while(!lista_vacia(l)){
        lista_vacia(l);
            lista_eliminar_head(l);
        free(l);
        l=NULL;
    }
}
