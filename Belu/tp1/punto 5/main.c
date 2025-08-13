#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Ingrese un numero del 1 al 26\n");
    scanf("%d", &n);

    if(n > 26 || n < 1){
        printf("Numero invalido\n");
        scanf("%d", &n);
    }

    int abc = 65;

    for(i = 0; i < n; i++){
        printf("%c", abc);
        abc++;
    }
}
