#include <stdio.h>
#include <stdlib.h>
#define MAX 25

void ingresar(char a[]){
    int n;

    printf("Ingrese la cantidad de caracteres que quiere ingresar:\n");
    scanf("%d", &n);

    while(n > MAX){
        printf("La cantidad excede la capacidad del arreglo\n");
        scanf("%d", &n);
    }
    imprimir(a, n);
}

void imprimir(char a[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Posicion %d\n", i+1);
        scanf(" %c", &a[i]);
    }
    for(i = 0; i < n; i++){
        printf("%c \n", a[i]);
    }
}

int main()
{
    char a[MAX];

    ingresar(a);

    return 0;
}
