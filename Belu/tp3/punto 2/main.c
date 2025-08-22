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
    buscar(a, n);
}

void buscar(int a[], int n){
    int i, num, control = 0;

    for(i = 0; i < n; i++){
        printf("Posicion %d\n", i+1);
        scanf(" %d", &a[i]);
    }

    printf("Ingrese el numero que quiere buscar:\n");
    scanf("%d", &num);

    for(i = 0; i < n; i++){
        if(num == a[i]){
            printf("Se encontro el numero %d en la posicion: %d\n", num, i+1);
            control = 1;
        }
    }

    if(control == 0){
        printf("No se encontro el numero %d", num);
    }

}

int main()
{
    int a[MAX];

    ingresar(a);

    return 0;
}
