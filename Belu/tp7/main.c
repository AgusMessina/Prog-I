#include <stdio.h>
#include <stdlib.h>
#include "TDApila.h"

int main()
{
    pila_int p;
    int n;
    init(&p);

    printf("Ingrese un numero\n");
    scanf("%d", &n);

    insertar(&p, n);
    if(!isempty(p))
        printf("numero %d", copyy(p));
}
