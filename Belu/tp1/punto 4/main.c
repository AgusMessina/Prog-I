#include <stdio.h>
#include <stdlib.h>

int main()
{
   int edad;

    printf("Ingrese su edad:\n");
    scanf("%d", &edad);

    if(edad >= 16){
        printf("Usted ahora puede votar\n");
        if(edad < 18 || edad > 70)
            printf("Su voto es opcional\n");
        else
            printf("Su voto es obligatorio\n");
    }
    else
        printf("Usted es menor, no puede votar\n");
}
