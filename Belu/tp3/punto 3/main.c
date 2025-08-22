#include <stdio.h>
#include <stdlib.h>
#define MAX 25

void ingresar(int a[]){
    int n;

    printf("Ingrese la cantidad de numeros que quiere ingresar:\n");
    scanf("%d", &n);

    while(n > MAX){
        printf("La cantidad excede la capacidad del arreglo\n");
        scanf("%d", &n);
    }
    buscar_menor(a, n);
}

void buscar_menor(int a[], int n){
    int i, menor = a[0];

    for(i = 0; i < n; i++){
        printf("Posicion %d\n", i+1);
        scanf(" %d", &a[i]);
    }

    for(i = 0; i < n; i++){
        if(menor > a[i])
            menor = a[i];
    }
    printf("El menor numero es %d", menor);
}

int main()
{
    int a[MAX];

    ingresar(a);

    return 0;
}
