#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    char calleNumero[30];
    char localidad[30];
    short codigoPostal;
    long long nroTelefono;
} Direccion;

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char tipo[10];
    int numero;
} Documento;

typedef struct{
    char nombre[30];
    Documento doc;
    Fecha fechaNac;
    char estadoCivil[15];
    int cantidadHijos;
    char sexo;
    Direccion direccion;
} Empleado;


void ingresarEmpleado(Empleado *empleado){
    printf("Ingrese el nombre del empleado: ");
    scanf(" %[^\n]", empleado->nombre);
    printf("Ingrese tipo de documento (DNI, Pasaporte, etc.): ");
    scanf(" %[^\n]", empleado->doc.tipo);
    printf("Ingrese n%cmero de documento: ", 163);
    scanf("%d", &empleado->doc.numero);

    do {
        printf("Ingrese la fecha de nacimiento (dd-mm-aaaa): ");
        scanf("%d%*c%d%*c%d", &empleado->fechaNac.dia, &empleado->fechaNac.mes, &empleado->fechaNac.anio);

        if (empleado->fechaNac.dia < 1 || empleado->fechaNac.dia > 31 ||
            empleado->fechaNac.mes < 1 || empleado->fechaNac.mes > 12 ||
            empleado->fechaNac.anio <= 0) {
            printf("Fecha err%cnea. Ingrese de nuevo.\n", 162);
        }
    } while (empleado->fechaNac.dia < 1 || empleado->fechaNac.dia > 31 ||
             empleado->fechaNac.mes < 1 || empleado->fechaNac.mes > 12 ||
             empleado->fechaNac.anio <= 0);
    printf("Ingrese estado civil: ");
    scanf(" %[^\n]", empleado->estadoCivil);
    printf("Ingrese cantidad de hijos: ");
    scanf("%d", &empleado->cantidadHijos);
    printf("Ingrese si es masculino (M) o femenino (F): ");
    scanf(" %c", &empleado->sexo);
    printf("Ingrese direcci%cn:\n", 162);
    printf(" Calle y n%cmero: ", 163);
    scanf(" %[^\n]", empleado->direccion.calleNumero);
    printf(" Localidad: ");
    scanf(" %[^\n]", empleado->direccion.localidad);
    printf(" C%cdigo postal: ", 162);
    scanf("%d", &empleado->direccion.codigoPostal);
    printf("  N%cmero de tel%cfono: ", 163, 130);
    scanf("%lld", &empleado->direccion.nroTelefono);
}

void imprimirEmpleado(Empleado empleado) {
    printf("\nNombre: %s\n", empleado.nombre);
    printf("Documento: %s %d\n", empleado.doc.tipo, empleado.doc.numero);
    printf("Fecha de nacimiento: %d-%d-%d\n", empleado.fechaNac.dia, empleado.fechaNac.mes, empleado.fechaNac.anio);
    printf("Estado Civil: %s\n", empleado.estadoCivil);
    printf("Cantidad de hijos: %d\n", empleado.cantidadHijos);
    printf("Sexo: %c\n", empleado.sexo);
    printf("Direcci%cn:\n", 162);
    printf("  Calle y n%cmero: %s\n", 163, empleado.direccion.calleNumero);
    printf("  Localidad: %s\n", empleado.direccion.localidad);
    printf("  C%cdigo postal: %d\n", 162, empleado.direccion.codigoPostal);
    printf("  N%cmero de tel%cfono: %lld\n", 163, 130, empleado.direccion.nroTelefono);
}

void imprimirEmpleados(Empleado empleados[], int cant){
    int contador;
    if (cant == 0) {
        printf("Primero debe cargar empleados para usar esta funci%cn.\n\n", 162);
    }
    else {
    printf("\nEMPLEADOS CARGADOS:\n");
    for (contador = 0; contador < cant; contador++) {
        printf("\n\nEMPLEADO N%CMERO %d\n", 233, contador+1);
        imprimirEmpleado(empleados[contador]);
     }
    }
}


void buscarDocumento(Empleado empleados[], int cant) {
    int contador, numeroDoc;
    char tipoDoc[10];
    int encontrado;
    printf("Ingrese tipo de documento: ");
    scanf(" %[^\n]", tipoDoc);
    printf("Ingrese n%cmero de documento: ", 163);
    scanf("%d", &numeroDoc);

    for (int contador = 0; contador < cant; contador++) {
        if (strcmp(empleados[contador].doc.tipo, tipoDoc) == 0 && empleados[contador].doc.numero == numeroDoc) {
            imprimirEmpleado(empleados[contador]);
            encontrado = 1;
        }
    }
    if(!encontrado) {
    printf("Empleado con documento %s %d no encontrado.\n", tipoDoc, numeroDoc);
    }
}


void ingresarEmpleados(Empleado empleados[], int *libre) {
    int empleadosAReg, contador;
    printf("%cCu%cntos empleados desea ingresar? ", 168, 160);
    scanf("%d", &empleadosAReg);

    if (*libre + empleadosAReg > MAX) {
        printf("ERROR: No hay espacio para agregar %d empleados.\n", empleadosAReg);
    }
    else{
        for (int contador = 0; contador < empleadosAReg; contador++){
            printf("\nIngrese datos del empleado %d: \n", *libre + 1);
            ingresarEmpleado(&empleados[*libre]);
            (*libre)++;
        }
    }
}



int main() {
    Empleado empleados[MAX];
    int posicion = 0;
    int opcion;

    do {
        printf("****************************************\n");
        printf("*        PROGRAMA DE EMPLEADOS        :D*\n");
        printf("****************************************\n");
        printf("<1> INGRESAR EMPLEADOS\n");
        printf("<2> BUSCAR EMPLEADO POR DOCUMENTO\n");
        printf("<3> VER TODOS LOS EMPLEADOS\n");
        printf("<4> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarEmpleados(empleados, &posicion);
                printf("\n\n");
                break;
            case 2:
                buscarDocumento(empleados, posicion);
                printf("\n\n");
                break;
            case 3:
                imprimirEmpleados(empleados, posicion);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.", 163, 160);
                printf("\n\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}


