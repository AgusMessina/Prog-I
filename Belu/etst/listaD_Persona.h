#ifndef LISTAD_PERSONA_H_INCLUDED
#define LISTAD_PERSONA_H_INCLUDED
#include "persona.h"
#include <malloc.h>

struct nodo{
    Persona dato;
    struct nodo *siguiente;
};
typedef struct nodo Nodo;

typedef struct{
    Nodo *cur;
    Nodo *acc;
    Nodo *aux;
}ListaD;

void init(ListaD *l){
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

void reset(ListaD *l){
    l->cur = l->acc;
    l->aux = l->acc;
}

int isOos(ListaD l){
    if(l.cur == NULL)
        return 1;
    else
        return 0;
}

void iinsert(ListaD *l, Persona p){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));      //NODO A INSERTAR

    strcpy(nuevo->dato.nombre, getNombre(p));       //NOMBRE
    strcpy(nuevo->dato.apellido, getApellido(p));
    nuevo->dato.dni = getDNI(p);                    //DNI
    strcpy(nuevo->dato.mail, getMail(p));

    if(l->cur == l->acc){ //Si ingreso en el primero
        l->acc = nuevo;
        nuevo->siguiente = l->cur;
        l->cur = nuevo;
        l->aux = nuevo;
    }else{
        l->aux->siguiente = nuevo;
        nuevo->siguiente = l->cur;
        l->cur = nuevo;
    }
}

void supress(ListaD *l){
    if(l->cur == l->acc){
        l->acc = l->cur->siguiente;
        free((void*)l->cur);
        l->cur = l->acc;
        l->aux = l->acc;
    }else{
        l->aux = l->cur->siguiente;
        free((void*)l->cur);
        l->cur = l->aux->siguiente;
    }
}

int isempty(ListaD l){
    if(l.acc == NULL)
        return 1;
    else
        return 0;
}

int isfull(ListaD l){
    if(l.cur != l.acc && l.cur != NULL)
        return 1;
    else
        return 0;
}

Persona copyy(ListaD l){
    return l.cur.dato;
}

#endif // LISTAD_PERSONA_H_INCLUDED
