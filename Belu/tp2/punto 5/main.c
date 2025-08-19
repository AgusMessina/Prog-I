#include <stdio.h>
#include <stdlib.h>

float promo(float p1, float p2, float p3){
    float mayor;
    mayor = p1;

    if(mayor < p2)
        mayor = p2;
    if(mayor < p3)
        mayor = p3;

    return (p1 + p2 + p3) - mayor;
}

int main()
{
    float p1, p2, p3;

    printf("Ingrese el primer precio:\n"); scanf("%f", &p1);
    printf("Ingrese el segundo precio:\n"); scanf("%f", &p2);
    printf("Ingrese el tercer precio:\n"); scanf("%f", &p3);

    printf("Su cantidad a pagar es de %.2f pesos\n", promo(p1, p2, p3));
}
