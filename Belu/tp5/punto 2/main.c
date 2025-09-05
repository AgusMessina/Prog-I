#include <stdio.h>
#include <stdlib.h>

int suma(int n){
    if(n == 1)
        return 1;
    else
        return n + suma(n - 1);
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
    printf("%d", suma(n));
}
