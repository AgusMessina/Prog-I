#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct p{
    char nomb[20];
    char ape[20];
    int edad;
}Persona;

void cargar(Persona per[], int n, int *cant){
    int i;
    int total = *cant + n;

    for(i = *cant; i < total; i++){
        printf("PERSONA %d:\nIngrese nombre\n", i+1);
        scanf("%19s", per[i].nomb);
        getchar();
        printf("Ingrese apellido\n");
        scanf("%19s", per[i].ape);
        getchar();
        printf("Ingrese edad\n");
        scanf("%d", &per[i].edad);
    }*cant = total;
}

void mostrar(Persona per[], int cant){
    int i;

    for(i = 0; i < cant; i++){
        printf("---DATOS DE PERSONA %d---\n", i+1);
        printf("Nombre: %s\nApellido: %s\nEdad: %d\n", per[i].nomb, per[i].ape, per[i].edad);
    }
}

int main()
{
    int n, op, cant = 0;

    printf("Ingrese la cantidad que quiere almacenar (Max 10)\n");
    scanf("%d", &n);
    while(n > 10){
        printf("Excede la cantidad\n");
        scanf("%d", &n);
    }
    Persona *per = (Persona*)malloc(sizeof(Persona)*n);

    printf("<1> Cargar\t<2> Mostrar\t<3> Salir\n");
    scanf("%d", &op);
    do{
        switch(op){
        case 1: cargar(per, n, &cant); break;
        case 2: mostrar(per, cant); break;
        case 3: printf("Saliendo..\n"); break;
        default: printf("Opcion invalida\n");
        }
    }while(op != 3);



}
