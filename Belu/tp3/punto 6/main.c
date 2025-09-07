#include <stdio.h>
#include <stdlib.h>
#define MAX 25

void ingresar(float a[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Ingrese la posicion %d\n", i+1);
        scanf("%f", &a[i]);
    }
}

void mostrar(float a[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Posicion %d: %.2f\n", i+1, a[i]);
    }
}

void ordenar(float a[], int n){
    int i, j;
    float aux;

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++)
            {if(a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

int main()
{
    float a[MAX];
    int n;

    printf("Ingrese la cantidad de numeros a ingresar:\n");
    scanf("%d", &n);

    while(n > MAX){
        printf("La cantidad excede el arreglo:\n");
        scanf("%d", &n);
    }
    ingresar(a, n);

    printf("Sin ordenar:\n");
    mostrar(a, n);

    printf("Ordenado:\n");
    ordenar(a, n);
    mostrar(a, n);
}
