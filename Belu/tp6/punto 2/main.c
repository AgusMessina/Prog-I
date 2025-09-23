#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int i, n;

    printf("Ingrese una cantidad n de enteros:\n");
    scanf("%d", &n);

    int *arr = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++){
        arr[i] = i+1;
        printf("Valor: %d\n", arr[i]);
    }
    free((void*)arr);
}
