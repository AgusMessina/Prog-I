#ifndef TDAAUTO_H_INCLUDED
#define TDAAUTO_H_INCLUDED
#include <string.h>

typedef struct{
    char patente[8];
    int marca;
    char modelo[21];
    int color;
}Auto;

void init(Auto *a){
    (*a).marca = 0;
    (*a).color = 0;
}

void set_patente(Auto *a, char p[]){
    strcpy((*a).patente, p);
}

void set_marca(Auto *a, int m){
    (*a).marca = m;
}

void set_modelo(Auto *a, char mod[]){
    strcpy((*a).modelo, mod);
}

void set_color(Auto *a, int c){
    (*a).color = c;
}

//get

char* get_patente(Auto a){
    char *p = (char*)malloc(strlen(a.patente)+1);
    if(p == NULL) exit(1);
    else
        strcpy(p, a.patente);
        return p;
}

int get_marca(Auto a){
    return a.marca;
}

char* get_modelo(Auto a){
    char *mod = (char*)malloc(strlen(a.modelo)+1);
    if(mod == NULL) exit(1);
    else
        strcpy(mod, a.modelo);
        return mod;
}

int get_color(Auto a){
    return a.color;
}

#endif // TDAAUTO_H_INCLUDED
