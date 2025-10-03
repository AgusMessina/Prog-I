#include <stdio.h>
#include <stdlib.h>
#include "TDApersona.h"

int main()
{
    Persona p;
    char nom[21], ape[21], m[31];
    int dni;

    inic(&p);

    printf("Ingrese nombre:");
    scanf("%21[^\n]s", nom);
    setNombre(&p, nom);

    printf("Nombre: %s", getNombre(p));
}
