#include "cola.h"

Cola* cola_crear()
{
    Cola *c;
    c=(Cola*)malloc(sizeof(Cola));
    c->head=NULL;
    c->tail=NULL;
    return c;
}

bool cola_vacia(Cola* cola)
{
    if(cola->head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void cola_enqueue(Cola* cola, int dato)
{
    Nodo *NewNode=nodo_crear(dato);
    if(cola_vacia(cola)){
        cola->head=cola->tail=NewNode;
    }else{
        cola->tail->siguiente=NewNode;
        cola->tail=NewNode;
    }
}

int cola_dequeue(Cola* cola)
{
    if(cola_vacia(cola))
        return -1;

    Nodo *tmp = cola->head;
    int dato = tmp->dato;
    cola->head=cola->head->siguiente;

    if(cola_vacia(cola))
        cola->tail=NULL;

    nodo_destruir(tmp);
    return dato;
}

int cola_frente(Cola* cola)
{
    return cola->dato[cola->head];
}

void cola_destruir(Cola* cola)
{
    while(!cola_vacia(cola)){
        cola_vacia(cola);
            cola_dequeue(cola);
        free(cola);
        cola=NULL;
    }
}
