#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

char comparar(char s1[], char s2[], int pos){

    if(strlen(s1) == pos)
        return 0;
    else{
        if(s1[pos] == s2[pos])
            return 1;
    }

    return comparar(s1, s2, pos+1);
}

int main()
{
    char s1[MAX], s2[MAX];

    printf("Ingrese el primer string:\n");
    scanf("%20s", s1);
    printf("Ingrese el segundo string:\n");
    scanf("%20s", s2);
    while(strlen(s1) != strlen(s2)){
        printf("Los strings no tienen la misma longitud\n");
        printf("Ingrese el primer string:\n");
        scanf("%20s", s1);
        printf("Ingrese el segundo string:\n");
        scanf("%20s", s2);
    }
    printf("%d", comparar(s1, s2, 0));
}
