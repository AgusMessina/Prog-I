EJERCICIO 1 CON FORMATO
typedef struct {
    int nroCuenta;
    char tipoTransaccion; // 'D' o 'E'
    float monto;
} Transaccion;

void ingresarTransacciones(FILE *archivo) {
    Transaccion t;
    char opcion;

    do {
        printf("Entre la cuenta, el tipo de transacción y el monto.\n? ");
        scanf("%d %c %f", &t.nroCuenta, &t.tipoTransaccion, &t.monto);

        // Guardar en el archivo con formato: número, tab, tipo, tab, monto, newline
        fprintf(archivo, "%d\t%c\t%.2f\n", t.nroCuenta, t.tipoTransaccion, t.monto);

        printf("¿Desea ingresar otra transacción? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
}

int main() {
    FILE *archivo;

    archivo = fopen("transacciones.dat", "w");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    ingresarTransacciones(archivo);

    fclose(archivo);

    printf("Archivo 'transacciones.dat' creado correctamente.\n");
    printf("Puede abrirlo con un editor de texto para verificar su contenido.\n");

    return 0;
}


// EN MODO SIN FORMATO
void ingresarTransacciones(FILE *archivo) {
    Transaccion t;
    char opcion;

    do {
        printf("Entre la cuenta, el tipo de transacción y el monto.\n? ");
        scanf("%d %c %f", &t.nroCuenta, &t.tipoTransaccion, &t.monto);

        // Guardar la estructura completa en modo binario
        fwrite(&t, sizeof(Transaccion), 1, archivo);

        printf("¿Desea ingresar otra transacción? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
}

int main() {
    FILE *archivo;

    archivo = fopen("transacciones.dat", "wb"); // modo binario escritura
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    ingresarTransacciones(archivo);

    fclose(archivo);

    printf("Archivo binario 'transacciones.dat' creado correctamente.\n");

    return 0;
}




EJERCICIO 2:
CON FORMATO
#define MAX_EMPLEADOS 100

typedef struct {
    char nomb[30];
    char ape[30];
    int antiguedad;
} empleado;

void guardarEmpleadosEnArchivo(empleado p[], int cant) {
    FILE *archivo = fopen("empleados.txt", "w");
    if (archivo == NULL) {
        perror("Error al abrir empleados.txt para escritura");
        return;
    }
    for (int contador = 0; contador < cant; contador++) {
        // escribo cada empleado en formato: nombre(tab)apellido(tab)antiguedad nueva linea
        fprintf(archivo, "%s\t%s\t%d\n", p[contador].nomb, p[contador].ape, p[contador].antiguedad);
    }
    fclose(archivo);
    printf("Datos guardados en empleados.txt correctamente.\n");
}

int leerEmpleadosDesdeArchivo(empleado nuevo[], int max) {
    FILE *archivo = fopen("nuevo.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir nuevo.txt para lectura");
        return 0;
    }
    int contador = 0;
    while (contador < max && fscanf(archivo, "%29s %29s %d", nuevo[contador].nomb, nuevo[contador].ape, &nuevo[contador].antiguedad) == 3) {
        contador++;
    }
    fclose(archivo);
    return contador;
}

void mostrarEmpleados(empleado emps[], int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Empleado %d: %s %s, Antig%cedad: %d\n", i + 1, emps[i].nomb, emps[i].ape, 129, emps[i].antiguedad);
    }
}

empleado cargarEmpleado() {
    empleado e;
    printf("Ingrese nombre: ");
    scanf(" %[^\n]", e.nomb);
    printf("Ingrese apellido: ");
    scanf(" %[^\n]", e.ape);
    printf("Ingrese antig%cedad: ", 129);
    scanf("%d", &e.antiguedad);
    return e;
}

int main() {
    empleado personal[MAX_EMPLEADOS];
    empleado otro_personal[MAX_EMPLEADOS];
    int cant_personal = 0;
    int cant_otro_personal = 0;
    int opcion;

    do {
        printf("\nMENU\n");
        printf("1. Agregar empleado al personal\n");
        printf("2. Actualizar empleados.txt\n");
        printf("3. Pasar nuevos empleados\n");
        printf("4. Mostrar empleados personal\n");
        printf("5. Mostrar empleados nuevos\n");
        printf("6. Salir\n");
        printf("Eleg%c opci%cn: ", 161, 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cant_personal < MAX_EMPLEADOS) {
                    personal[cant_personal++] = cargarEmpleado();
                } else {
                    printf("Arreglo \"personal\" lleno.\n");
                }
                break;
            case 2:
                if (cant_personal > 0) {
                    guardarEmpleadosEnArchivo(personal, cant_personal);
                } else {
                    printf("No hay empleados en \"personal\" para guardar.\n");
                }
                break;
            case 3:
                cant_otro_personal = leerEmpleadosDesdeArchivo(otro_personal, MAX_EMPLEADOS);
                printf("%d empleados le%cdos desde nuevo.txt.\n", cant_otro_personal, 161);
                break;
            case 4:
                if (cant_personal > 0) {
                    mostrarEmpleados(personal, cant_personal);
                } else {
                    printf("No hay empleados en \"personal\" para mostrar.\n");
                }
                break;
            case 5:
                if (cant_otro_personal > 0) {
                    mostrarEmpleados(otro_personal, cant_otro_personal);
                } else {
                    printf("No hay empleados le%cdos de archivo para mostrar.\n", 161);
                }
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn inv%clida, intente nuevamente.\n", 162, 160);
                break;
        }

    } while (opcion != 6);

    return 0;
}


SIN FORMATO

