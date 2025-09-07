#include <stdio.h>
#include <stdlib.h>
#define MAX 25

void ingresar(char ar[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("Posicion %d\n", i+1);
        scanf("%c", &ar[i]);
        getchar();
    }
}

void insertar(char ar[], int *n, char nuevo, int pos){
    int i;
    char aux, temp;

    aux = ar[pos - 1];

    for(i = pos; i < *n; i++){
        temp = ar[i];
        ar[i] = aux;
        aux = ar[i + 1];
    }
    ar[pos - 1] = nuevo;
}

void mostrar(char ar[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Posicion %d: %c\n", i+1, ar[i]);
    }
}

int main()
{
    char ar[MAX], nuevo;
    int n, pos;

    printf("Ingrese el numero de caracteres que quiere ingresar:\n");
    scanf("%d", &n);

    while(n > MAX){
        printf("La cantidad excede la capacidad del arreglo. Ingrese nuevamente.\n");
        scanf("%d", &n);
    }

    ingresar(ar, n);

    printf("Ingrese el caracter que quiere insertar:\n");
    scanf("%c", &nuevo);
    getchar();
    printf("Y la posicion donde lo quiere insertar:\n");
    scanf("%d", &pos);

    printf("Antes de insertar:\n");
    mostrar(ar, n);
    insertar(ar, &n, nuevo, pos);
    printf("Despues de insertar:\n");
    mostrar(ar, n);
}
