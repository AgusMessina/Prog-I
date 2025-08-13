#include <stdio.h>
#include <stdlib.h>
#define dolar 1318.51

int main()
{
    float pesos, cambio;

    printf("Ingrese un valor en pesos:\n");
    scanf("%f", &pesos);

    cambio = pesos/dolar;

    printf("Su valor en dolar es %.2f\n", cambio);
}
