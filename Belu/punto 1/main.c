#include <stdio.h>
#include <stdlib.h>

int naturales(int n){
    if(n == 1)
        return 1;
    else
        printf("%d ", n);
        return naturales(n-1);
}

int main()
{
    int n;

    printf("Ingrese un numero natural:\n");
    scanf("%d", &n);
    while(n < 0){
        printf("No es un numero natural..\n");
        scanf("%d", &n);
    }
    printf("%d", naturales(n));
}
