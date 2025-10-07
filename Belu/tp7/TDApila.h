#ifndef TDAPILA_H_INCLUDED
#define TDAPILA_H_INCLUDED
#define MAX 100

typedef struct{
    int tope;
    int elem[MAX];
}pila_int;

void init(pila_int *p){
    p->tope = -1;
}

int isempty(pila_int p){
    if(p.tope == -1)
        return 1;
    else
        return 0;
}

int copyy(pila_int p){
    return p.elem[p.tope];
}

void insertar(pila_int *p, int n){
    p->tope++;
    p->elem[p->tope] = n;
}

void suprimir(pila_int *p){
    p->tope--;
}

#endif // TDAPILA_H_INCLUDED
