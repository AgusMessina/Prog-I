#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ID, sexo, edad, sector;

    printf("\tIngresar datos de empleado\n");
    printf("Ingrese su numero de identificacion (1000 a 9999)\n");
    scanf("%d", &ID);
    while(ID < 1000 || ID > 9999){
        printf("Identificacion invalida\nIngrese nuevamente\n");
        scanf("%d", &ID);
    }
    printf("Ingrese su sexo: [1] Hombre [2] Mujer\n");
    scanf("%d", &sexo);
    while(sexo < 1 || sexo > 2){
        printf("Numero invalido.\nIngrese nuevamente\n");
        scanf("%d", &sexo);
    }
    printf("Ingrese su edad\n");
    scanf("%d", &edad);
    while(edad < 18 || edad > 65){
        printf("Ingrese nuevamente (boe)\n");
        scanf("%d", &edad);
    }
    printf("Ingrese el sector al que pertenece\n[1] A\t [2] B\t[3] C\t[4] D\t\n");
    scanf("%d", &sector);
    while(sector < 1 || sector > 4){
        printf("Sector invalido\nIngrese nuevamente\n");
        scanf("%d", &sector);
    }
    printf("\tDATOS DE EMPLEADO\t\n");
    printf("Numero de Identificacion: %d\n", ID);

    if(sexo == 1)
        printf("Sexo: Hombre\n");
    else
        printf("Sexo: Mujer\n");

    printf("Edad: %d anos\n", edad);

    if(sector == 1)
        printf("Sector: A\n");
    if(sector == 2)
        printf("Sector: B\n");
    if(sector == 3)
        printf("Sector: C\n");
    if(sector == 4)
        printf("Sector: D\n");
}
