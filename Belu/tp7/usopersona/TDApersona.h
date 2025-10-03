#ifndef TDAPERSONA_H_INCLUDED
#define TDAPERSONA_H_INCLUDED
#include <string.h>

typedef struct{
    char nombre[31];
    char apellido[31];
    int dni;
    char mail[31];
}Persona;

void inic(Persona *p){
    (*p).dni = 0;
}

void setNombre(Persona *p, char nom[]){
    strcpy((*p).nombre, nom);
}

char* getNombre(Persona p){
    char *n = (char*)malloc(strlen(n)+1);
    if(n == NULL) exit(1);
    else
        strcpy(n, p.nombre);
    return n;
}

void setApellido(Persona *p, char ape[]){
    strcpy((*p).apellido, ape);
}

char* getApellido(Persona p){
    char* ap = (char*)malloc(strlen(ap)+1);
    if(ap == NULL) exit(1);
    else
        strcpy(ap, p.apellido);
    return ap;
}

void setDNI(Persona *p, int id){
    (*p).dni = id;
}

int getDNI(Persona p){
    return p.dni;
}

void setMail(Persona *p, char m[]){
    strcpy((*p).mail, m);
}

char* getMail(Persona p){
    char *meil = (char*)malloc(strlen(meil)+1);
    if(meil = NULL)exit(1);
    else
        strcpy(meil, p.mail);
        return meil;
}

#endif // TDAPERSONA_H_INCLUDED
