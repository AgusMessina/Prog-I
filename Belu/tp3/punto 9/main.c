#include <stdio.h>
#include <stdlib.h>
#define M 14

float carganota(float notas[], int *canttotal){
    int i, n;

    printf("Cuantas notas quiere cargar?\n");
    scanf("%d", &n);

    canttotal = canttotal + n;
    for(i = 0; i < canttotal; i++){
        printf("Ingrese nota %d:\n", i+1);
        scanf("%f", &notas[i]);
    }
}

void muestranota(float notas[], int *canttotal){
    int i;
    for(i = 0; i < canttotal; i++){
        printf("Nota %d:\n", i+1);
    }
}

int aplazos(float notas[], int *canttotal){
    int i, acum = 0;
    for(i = 0; i < canttotal; i++){
        if(notas[i] <= 3)
            acum++;
    }
    if(acum >= 7)
        printf("Alta Posibilidad de Repetir...\n");
    return acum;
}

int main()
{
    float notas[M];
    int opcion, canttotal = 0;

    do{
        printf("<1> Cargar notas\n <2> Mostrar notas\n <3> Aplazos\n <4> Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: carganota(notas, &canttotal);
                break;
            case 2: muestranota(notas, &canttotal);
                break;
            case 3: printf("La cantidad de aplazo es %d", aplazos(notas, &canttotal));
                break;
            case 4: printf("Saliendo...\n");
                break;
            default: printf("pelotudo\n");
        }
    }while(opcion != 4);
}
