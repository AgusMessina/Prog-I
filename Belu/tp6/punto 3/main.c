#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
    char a;
    int b;
}Info;

int main()
{
    Info *in = (Info*)malloc(sizeof(Info));

    if(in == NULL){
        printf("No se puede asignar memoria..\n");
        exit(1);
    }

    printf("Ingrese un caracter:\n");
    scanf(" %c", &(*in).a);
    printf("Ingrese un entero:\n");
    scanf("%d", &in->b);

    printf("Caracter: %c\nEntero: %d\n", (*in).a, (*in).b);
}
