#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 26

void ingresar(char s1[], char s2[]){
    printf("Ingrese el primer string:\n");
    scanf("%25s", s1);
    printf("Ingrese el segundo string:\n");
    scanf("%25s", s2);
}

void mostrar(char s1[], char s2[]){
    printf(" String 1: %s\n String 2: %s\n", s1, s2);
}

void menor(char s1[], char s2[]){
    if(strlen(s1) == strlen(s2)){
        printf("Los strings son iguales!\n");
    }else{
        if(strlen(s1) > strlen(s2))
            printf("El string %s es menor\n", s2);
        else
            printf("El string %s es menor\n", s1);
    }
}

void mayor(char s1[], char s2[]){
    char m[MAX];

    if(strlen(s1) == strlen(s2)){
        printf("Los strings son iguales!\n");
    }else{
        if(strlen(s1) > strlen(s2)){
            strcpy(m, s1);
            printf("El mayor es %s\n", m);
        }
        else{
            strcpy(m, s2);
            printf("El mayor es %s\n", m);
        }
    }
}

void cant(char s1[], char s2[]){
    printf("Cantidad de caracteres del String 1: %d\n", strlen(s1));
    printf("Cantidad de caracteres del String 2: %d\n", strlen(s2));

}

int main()
{
    char s1[MAX], s2[MAX];
    int opcion;

    do{
        printf("<1> Ingresar\n<2> Mostrar\n<3> Calcular el menor\n<4> Calcular el mayor\n<5> Mostrar caracteres\n<6> Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: ingresar(s1, s2);
                break;
            case 2: mostrar(s1, s2);
                break;
            case 3: menor(s1, s2);
                break;
            case 4: mayor(s1, s2);
                break;
            case 5: cant(s1, s2);
                break;
            case 6: printf("Saliendo\n");
                break;
            default: printf("Opcion invalida\n");
                break;
        }
    }while(opcion != 6);
}
