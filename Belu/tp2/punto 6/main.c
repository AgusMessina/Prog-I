#include <stdio.h>
#include <stdlib.h>

float salario(int horas, float sueldo){
    float total;
    if(horas <= 30)
        total = horas * sueldo;
    else{
        int extra = horas - 30;
        total = (30 * sueldo) + (extra * sueldo * 1.5); // 1.5 xq 1--100%; 1.5--150% (regla de 3)
    }
    return total;
}

int main()
{
    int horas;
    float sueldo;

    printf("Ingrese el sueldo por hora:\n");
    scanf("%f", &sueldo);
    printf("Ingrese horas trabajadas:\n");
    scanf("%d", &horas);

    printf("Su salario total es: %.2f\n", salario(horas, sueldo));
}
