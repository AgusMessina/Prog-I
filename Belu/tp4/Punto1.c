#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct{
        char nombre[MAX];
        int edad;
        float altura;
        float peso;
        long DNI;
    }Persona;

void carga(Persona per){
    printf("Ingrese nombre:\n");
    scanf("%s", per.nombre);
    printf("Ingrese su edad:\n");
    scanf("%d", &per.edad);
    printf("Ingrese altura:\n");
    scanf("%f", &per.altura);
    printf("Ingrese peso:\n");
    scanf("%f", &per.peso);
    printf("Ingrese DNI:\n");
    scanf("%ld", &per.DNI);
}

void imprimir(Persona poblacion[], Persona per){
    strcpy(poblacion[3].nombre, per.nombre);
    poblacion[3].edad = per.edad;
    poblacion[3].altura = per.altura;
    poblacion[3].peso = per.peso;
    poblacion[3].DNI = per.DNI;

    printf("Nombre: %s\n", poblacion[3].nombre);
    printf("Edad: %d\n", poblacion[3].edad);
    printf("Altura: %f\n", poblacion[3].altura);


   Persona per, poblacion[MAX];

    carga(per);
    imprimir(poblacion, per);

}
