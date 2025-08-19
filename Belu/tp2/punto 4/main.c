#include <stdio.h>
#include <stdlib.h>

void promedio(){
    float n1, n2, n3, n4, prom;

    printf("Nota 1:\n"); scanf("%f", &n1);
    printf("Nota 2:\n"); scanf("%f", &n2);
    printf("Nota 3:\n"); scanf("%f", &n3);
    printf("Nota 4:\n"); scanf("%f", &n4);

    prom = (n1 + n2 + n3 + n4)/4;

    printf("El promedio es: %.2f\n", prom);
    if(prom >= 7)
        printf("APROBADO\n");
    else
        printf("DESAPROBADO\n");
}


int main()
{
    promedio();
}
