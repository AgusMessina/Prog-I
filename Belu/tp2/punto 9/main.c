#include <stdio.h>
#include <stdlib.h>

void consultar(float saldo){
    printf("Su saldo actual es: %.2f\n", saldo);
}

float retirar(float *saldo){
    float chau;
    printf("Ingrese cuanto dinero quiere retirar:\n");
    scanf("%f", &chau);

    return *saldo = *saldo - chau;
}

float depositar(float *saldo){
    float hola;
    printf("Ingrese cuanto dinero quiere depositar:\n");
    scanf("%f", &hola);

    return *saldo = *saldo + hola;
}

int main()
{
    int opcion;
    float saldo = 3000;

    printf("Bienvenido al cajero virtual en C\n");

    do{
        printf("<1> Consultar saldo\n");
        printf("<2> Retirar dinero\n");
        printf("<3> Depositar dinero\n");
        printf("<4> Salir\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                consultar(saldo);
                break;
            case 2:
                retirar(&saldo);
                break;
            case 3:
                depositar(&saldo);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Ingrese nuevamente\n");
        }
    }while(opcion != 4);
}
