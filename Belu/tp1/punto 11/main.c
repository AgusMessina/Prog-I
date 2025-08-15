#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    float n1, n2, n3, n4, n5, promedio, menor;

    do{
        printf("****************************************\n*\t\t BIENVENIDO\t\t*\n****************************************\n");
        printf("<1> Cargar notas (permite cargar la nota 5 alumnos)\n");
        printf("<2> Mostrar Notas\n");
        printf("<3> Calcular Promedio\n");
        printf("<4> Calcular el Menor\n");
        printf("<5> Salir\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:{
            printf("Ingrese nota 1:"); scanf("%f", &n1);
            printf("Ingrese nota 2:"); scanf("%f", &n2);
            printf("Ingrese nota 3:"); scanf("%f", &n3);
            printf("Ingrese nota 4:"); scanf("%f", &n4);
            printf("Ingrese nota 5:"); scanf("%f", &n5);
            break;}
            case 2:{
            printf(" Nota 1: %.2f\n Nota 2: %.2f\n Nota 3: %.2f\n Nota 4: %.2f\n Nota 5: %.2f\n", n1, n2, n3, n4, n5);
            break;}
            case 3:{
            promedio = (n1 + n2 + n3 + n4 + n5)/5;
            printf("Su promedio es: %.2f\n", promedio);
            break;}
            case 4:{
            menor = n1;
            if(menor > n2)
                menor = n2;
            if(menor > n3)
                menor = n3;
            if(menor > n4)
                menor = n4;
            if(menor > n5)
                menor = n5;
            printf("La menor nota es: %.2f\n", menor);
            break;}
            case 5: break;
            default:
            printf("Opcion invalida\n");
        }
    }while(opcion !=5);
}
