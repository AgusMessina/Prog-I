#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAauto.h"

void mostrar(Auto a){
    printf("Patente: %s\n", get_patente(a));
    printf("Marca:");
        switch(get_marca(a)){
            case 1: printf("Fiat\n"); break;
            case 2: printf("Audi\n"); break;
            case 3: printf("Renault\n"); break;
        }
    printf("Modelo: %s\n", get_modelo(a));
    printf("Color:");
        switch(get_color(a)){
            case 1: printf("Negro\n"); break;
            case 2: printf("Blanco\n"); break;
            case 3: printf("Rojo\n"); break;
            case 4: printf("Otro\n"); break;
        }
}

int main()
{
    Auto a;
    char p[8], mod[21];
    int m, c;

    init(&a);
    printf("Ingrese patente:\n");
    scanf("%7[^\n]s", p);
    set_patente(&a, p);
    printf("Ingrese marca:1-Fiat \t2-Audi \t3-Renault\n");
    scanf("%d", &m);
    set_marca(&a, m);
    printf("Ingrese modelo:\n");
    scanf(" %20[^\n]s", mod);
    set_modelo(&a, mod);
    printf("Ingrese color:1-Negro \t2-Blanco \t3-Rojo \t4-Otro\n");
    scanf("%d", &c);
    set_color(&a, c);

    mostrar(a);
}
