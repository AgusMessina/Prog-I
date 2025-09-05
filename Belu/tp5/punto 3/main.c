#include <stdio.h>
#include <stdlib.h>
#define MAX 11

int buscar(int ar[], int pos, int n){
    if(pos == MAX)
        return -1;
    else
        if(ar[pos] == n)
        return pos;

    return buscar(ar, pos+1, n);
}

int main()
{
    int n;
    int ar[MAX] = {1,2,3,4,5,6,7,8,9,0,12};
    printf("Ingrese un numero natural:\n");
    scanf("%d", &n);
    while(n < 0){
        printf("No es un numero natural..\n");
        scanf("%d", &n);
    }
    printf("%d", buscar(ar, 0, n));
}
