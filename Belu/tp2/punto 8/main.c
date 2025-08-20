#include <stdio.h>
#include <stdlib.h>

void ingreso(int codigo, int horarioI){
    printf("---INGRESO:---\n");
    printf("---Hora de ingreso: %d\nCodigo: %d\n---", horarioI, codigo);
}

void egreso(int codigo, int horarioE){
    printf("---EGRESO:---\n");
    printf("---Hora de egreso: %d\nCodigo: %d\n---", horarioE, codigo);
}

int main()
{
    int i, n, opcion, codigo, horarioI, horarioE;

    printf("Ingrese la cantidad de empleados que desea cargar:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("EMPLEADO %d:\n", i+1);
        printf("Ingrese su codigo (4 digitos):\n");
        scanf("%d", &codigo);

        while(codigo < 1000 || codigo > 9999){
            printf("Codigo invalido. Ingrese nuevamente:\n");
            scanf("%d", &codigo);
            }

        printf("Ingrese el horario de ingreso:\n");
        scanf("%d", &horarioI);
        printf("Ingrese el horario de egreso:\n");
        scanf("%d", &horarioE);

        do{
            printf("\t<1> Ingresar\t<2> Egresar\n<3> Siguiente empleado\n");
            scanf("%d", &opcion);

            switch(opcion){
                case 1:
                    ingreso(codigo, horarioI);
                    break;
                case 2:
                    egreso(codigo, horarioE);
                    break;
                case 3:
                    break;
                default:
                    printf("Opcion invalida\n");
            }
        }while(opcion != 3);
    }
    printf("Saliendo..\n");
}
