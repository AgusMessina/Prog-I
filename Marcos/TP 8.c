EJERCICIO 1
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


// EN MODO SIN ESCRITURA
/*
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
*/
