#include <stdio.h>
#include <stdlib.h>

int tiempo_seg(int hs, int min, int seg){
    int total = (hs * 3600) + (min * 60) + seg;
    return total;
}

int main()
{
    int hs, min, seg;

    printf("Ingrese hora:\n");
    scanf("%d", &hs);
    printf("Ingrese minutos:\n");
    scanf("%d", &min);
    printf("Ingrese segundos:\n");
    scanf("%d", &seg);

    printf("El numero de segundos pasados desde las 00:00 es: %d segundos", tiempo_seg(hs, min, seg));
}
