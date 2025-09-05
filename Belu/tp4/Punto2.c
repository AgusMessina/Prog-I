#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID, bloque, tipo;
    int mesas, sillas, pizarras;
    struct{
        char marca[20];
        int color, control;
    }Proyector;
}Aula;

void ingresar(Aula au){
    printf("Ingrese su numero de Identificacion\n");
    scanf("%d", &au.ID);
    printf("Ingrese el bloque (1-4):\n");
    scanf("%d", &au.bloque);
    while(au.bloque > 4 || au.bloque < 1){
        printf("El bloque no existe. Ingrese nuevamente\n");
        scanf("%d", &au.bloque);
    }
    printf("Ingrese el tipo:\n1- Laboratorio\t2- Conferencia\t3- Teoria-Practica\n");
    scanf("%d", &au.tipo);
    while(au.tipo > 3 || au.tipo < 1){
        printf("Tipo invalido. Ingrese nuevamente\n");
        scanf("%d", &au.tipo);
    }
    printf("Ingrese la cantidad de mesas, sillas y pizarras:\n");
    scanf("%d" "%d" "%d", &au.sillas, &au.mesas, &au.pizarras);
    printf("Ingrese la marca del proyector:\n");
    scanf("%s", au.Proyector.marca);
    printf("Ingrese el color:\n1- Blanco\t2- Negro\n");
    scanf("%d", &au.Proyector.color);
    while(au.Proyector.color < 1 || au.Proyector.color > 2){
        printf("Opcion invalida. Ingrese nuevamente\n");
        scanf("%d", &au.Proyector.color);
    }
    printf("Tiene control remoto?\n1- SI\n2- NO\n");
    scanf("%d", &au.Proyector.control);
    while(au.Proyector.control < 2 || au.Proyector.control > 1){
        printf("Opcion invalida. Ingrese nuevamente\n");
        scanf("%d", &au.Proyector.control);
    }
}

void mostrar(Aula au){
    printf("---DATOS DE AULA:---\n");
    printf("N° DE IDENTIFICACION: %d\n", au.ID);
    printf("UBICACION: Bloque %d\n", au.bloque);
    printf("TIPO:\n");
    if(au.tipo == 1)
        printf("Laboratorio\n");
    if(au.tipo == 2)
        printf("Conferencia\n");
    if(au.tipo == 3)
        printf("Teoria-Practica\n");
    printf("CANTIDAD DE:\n Mesas: %d\ Sillas: %d\n Pizarras: %d\n", au.mesas, au.sillas, au.pizarras);
    printf("PROYECTOR:\nMarca: %s", au.Proyector.marca);
    if(au.Proyector.color == 1)
        printf("Color blanco\n");
    else
        printf("Color negro\n");
    printf("Control remoto\n");
    if(au.Proyector.control == 1)
        printf("SI\n");
    else
        printf("NO\n");

}

int main()
{
    Aula au;

    ingresar(au);
    mostrar(au);
}
