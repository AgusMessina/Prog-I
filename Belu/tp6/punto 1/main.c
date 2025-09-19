#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define M 10

int main()
{
    int *n = (int*)malloc(sizeof(int)*M);
    int i;

    for(i = 0; i < M; i++){
        printf("Ingrese un entero:\n");
        scanf("%d", &n[i]);
    }

    for(i = 0; i < M; i++){
        printf("Direccion: %i\nValor: %d\nTamaño: %d", n[i], M*sizeof(n);
    }
    printf("\n");

    printf("Direccion: %d\nContenido: %d", n, *n);
    free((void*)n);
    getchar();

    float *f = (float*)malloc(sizeof(float));

    printf("Ingrese un num real\n");
    scanf("%f", f);
    printf("Direccion: %i\n Valor: %.2f\n Tamaño del puntero: %d", &f, *f, sizeof(*f));

    char *c = (char*)malloc(sizeof(char));

    printf("Ingrese caracter\n");
    scanf(" %c", c);
    printf("Valor: %c\nDireccion: %i\nTamaño: %d", *c, &c, sizeof(*c));

}
