#include <stdio.h>
#include <stdlib.h>
#define M 13

void CargaNota(int notas[], int n, int *cant){
    int i;

    printf("Ingrese la cantidad de notas que quiere cargar:\n");
    scanf("%d", &n);
    while(n > M){
        printf("Excede la capacidad. Ingrese nuevamente\n");
        scanf("%d", &n);
    }

    int total = *cant + n;

    if(total > M)
        printf("Excede la cantidad de lugares.\n");
    else{
        for(i = *cant; i < total; i++){
            printf("Ingrese la nota %d:\n", i+1);
            scanf("%d", &notas[i]);
            getchar();
            while(notas[i] < 0 || notas[i] > 10){
                printf("Debe ser entre 1 y 10\n");
                scanf("%d", &notas[i]);
                getchar();
            }
        }
        *cant = total;
    }
}

void MuestraNota(int notas[], int *cant){
    int i;

    if(*cant == 0)
        printf("No hay notas cargadas\n");
    else{
        for(i = 0; i < *cant; i++){
            printf("Nota num %d: %d\n", i+1, notas[i]);
        }
    }
}

int Aplazos(int notas[], int *cant){
    int i, rep = 0;

    if(*cant == 0)
        printf("No hay notas cargadas\n");
    else{
    for(i = 0; i < *cant; i++){
        if(notas[i] < 4)
            rep++;
    }
    if(rep >= 7)
        printf("Alta Posibilidad de Repetir..");
    }
    return rep;
}

int main()
{
    int notas[M];
    int n, opcion, cant = 0;

    do{
        printf("<1> Cargar\n<2> Mostrar\n<3> Aplazos\n<4> Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: CargaNota(notas, n, &cant); break;
            case 2: MuestraNota(notas, &cant); break;
            case 3: printf("Cantidad de aplazos es: %d\n", Aplazos(notas, &cant)); break;
            case 4: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida\n");
        }
    }while(opcion != 4);
}

