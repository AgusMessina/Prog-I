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
#define MAX_EMPLEADOS 100

typedef struct {
    char nomb[30];
    char ape[30];
    int antiguedad;
} empleado;

void guardarEmpleadosEnArchivo(empleado p[], int cant) {
    FILE *archivo = fopen("empleados.dat", "wb");
    if (archivo == NULL) {
        perror("Error al abrir empleados.dat para escritura");
        return;
    }
    fwrite(p, sizeof(empleado), cant, archivo);
    fclose(archivo);
    printf("Datos guardados en empleados.dat correctamente.\n");
}

int leerEmpleadosDesdeArchivoBinario(empleado nuevo[], int max) {
    FILE *archivo = fopen("nuevo.dat", "rb");
    if (archivo == NULL) {
        perror("Error al abrir nuevo.dat para lectura");
        return 0;
    }
    int leidos = fread(nuevo, sizeof(empleado), max, archivo);
    fclose(archivo);
    return leidos;
}

void mostrarEmpleados(empleado arr[], int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Empleado %d: %s %s, Antig%cedad: %d\n", i + 1, arr[i].nomb, arr[i].ape, 129, arr[i].antiguedad);
    }
}

empleado cargarEmpleado() {
    empleado e;
    printf("Ingrese nombre (sin espacios): ");
    scanf(" %[^\n]", e.nomb);
    printf("Ingrese apellido (sin espacios): ");
    scanf(" %[^\n]", e.ape);
    printf("Ingrese antigüedad: ");
    scanf("%d", &e.antiguedad);
    return e;
}

int main() {
    empleado personal[MAX_EMPLEADOS];
    empleado otro_personal[MAX_EMPLEADOS];
    int cant_personal = 0;
    int cant_otro_personal = 0;
    int opcion;

    FILE *archivo = fopen("nuevo.dat", "wb");
    if (archivo == NULL) {
        perror("Error al abrir nuevo.dat para escritura");
        return 1;
    }

    empleado e1 = { "Marcos", "Lucero", 2 };
    empleado e2 = { "Samay", "Ortiz", 5 };
    empleado e3 = { "Ronaldo", "Ortega", 1 };

    fwrite(&e1, sizeof(empleado), 1, archivo);
    fwrite(&e2, sizeof(empleado), 1, archivo);
    fwrite(&e3, sizeof(empleado), 1, archivo);

    fclose(archivo);
    printf("Archivo nuevo.dat creado en formato binario con datos de ejemplo.\n");

    do {
        printf("\nMENU\n");
        printf("1. Agregar empleado al arreglo personal\n");
        printf("2. Guardar arreglo personal en archivo binario empleados.dat\n");
        printf("3. Leer empleados desde archivo binario nuevo.dat al arreglo otro_personal\n");
        printf("4. Mostrar empleados personal\n");
        printf("5. Mostrar empleados otro_personal\n");
        printf("6. Salir\n");
        printf("Elija opción: ");
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
                    printf("No hay empleados en arreglo \"personal\" para guardar.\n");
                }
                break;
            case 3:
                cant_otro_personal = leerEmpleadosDesdeArchivoBinario(otro_personal, MAX_EMPLEADOS);
                printf("%d empleados le%cdos desde nuevo.dat.\n", cant_otro_personal, 161);
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




EJERCICIO 3:
CON FORMATO:
#include <stdio.h>
#include <stdlib.h>

void filtrarPares(const char *archivoEntrada, const char *archivoSalida) {
    FILE *aentrada = fopen(archivoEntrada, "r");
    if (aentrada == NULL) {
        perror("No se pudo abrir el archivo de entrada");
        return;
    }

    FILE *asalida = fopen(archivoSalida, "w");
    if (asalida == NULL) {
        perror("No se pudo abrir el archivo de salida");
        fclose(asalida);
        return;
    }

    float numero;
    while (fscanf(aentrada, "%f", &numero) == 1) {
        int parteEntera = (int)numero;
        if (parteEntera % 2 == 0) {
            fprintf(asalida, "%.2f\n", numero);
        }
    }

    fclose(aentrada);
    fclose(asalida);
}

int main() {
    const char *archivoEntrada = "costos.txt";
    const char *archivoSalida = "pares.txt";

    filtrarPares(archivoEntrada, archivoSalida);

    printf("Proceso finalizado. Los n%cmeros pares est%cn en %s\n", 163, 160, archivoSalida);
    return 0;
}


SIN FORMATO:
#include <stdio.h>
#include <stdlib.h>


/** PRIMERO CREAR EL .DAT
int main() {
    const char *archivo = "costos.dat";
    FILE *f = fopen(archivo, "wb");
    if (f == NULL) {
        perror("Error al crear costos.dat");
        return 1;
    }
    float numeros[10] = {12.4, 7.5, 8.0, 3.1, 20.0, 16.2, 5.6, 10.0, 25.0, 4.8};
    fwrite(numeros, sizeof(float), 10, f);
    fclose(f);
    printf("Archivo costos.dat creado con 10 n%cmeros en formato binario.\n", 163);
    return 0;
}
*/


void filtrarParesBin(const char *archivoEntrada, const char *archivoSalida) {
    FILE *archEntrada = fopen(archivoEntrada, "rb");
    if (archEntrada == NULL) {
        perror("No se pudo abrir el archivo binario de entrada");
        return;
    }

    FILE *archSalida = fopen(archivoSalida, "wb");
    if (archSalida == NULL) {
        perror("No se pudo abrir el archivo binario de salida");
        fclose(archSalida);
        return;
    }

    float numero;
    while (fread(&numero, sizeof(float), 1, archEntrada) == 1) {
        int parteEntera = (int)numero;
        if (parteEntera % 2 == 0) {
            fwrite(&numero, sizeof(float), 1, archSalida);
        }
    }

    fclose(archEntrada);
    fclose(archSalida);
}

int main() {
    const char *archivoEntrada = "costos.dat";
    const char *archivoSalida = "pares.dat";

    filtrarParesBin(archivoEntrada, archivoSalida);

    printf("Proceso finalizado. Los n%cmeros pares est%cn en %s (formato binario).\n", 163, 160, archivoSalida);
    return 0;
}




EJERCICIO 4:
#include <string.h>

#define MAX_LINEA 1024

/** PROBAR 3 CASOS con archivocomp1 y archivocomp2:
-ARCHIVO 1 > ARCHIVO 2 EN LÍNEAS:
ARCHIVO 1: Hola
Esto es una prueba
Linea extra en archivo1
ARCHIVO 2: Hola
Esto es una prueba


-ARCHIVO 2 > ARCHIVO 1
ARCHIVO 1: Hola
Linea común
ARCHIVO 2: Hola
Linea común
Linea extra en archivo2


-ARCHIVO 1 == ARCHIVO 2 Y NO DIFIEREN NADA
ARCHIVO 1: Primera línea
Segunda línea
Tercera línea
ARCHIVO 2: Primera línea
Segunda línea
Tercera línea


-ARCHIVO 1 == ARCHIVO 2 Y DIFIEREN
ARCHIVO 1: Línea 1 igual
Línea 2 diferente en archivo1
Línea 3 igual
ARCHIVO 2: Línea 1 igual
Línea 2 diferente en archivo2
Línea 3 igual
*/


void compararArchivos(FILE *fp1, FILE *fp2) {
    char linea1[MAX_LINEA];
    char linea2[MAX_LINEA];
    int numLinea = 1;

    while (1) {
        char *res1 = fgets(linea1, MAX_LINEA, fp1);
        char *res2 = fgets(linea2, MAX_LINEA, fp2);

        // CASO 1: SON IGUALES
        if (res1 == NULL && res2 == NULL) {
            printf("Archivos iguales.\n");
            break;
        }

        // CASO 2: UNO TIENE MÁS LÍNEAS QUE EL OTRO
        if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL)) {
            printf("Los archivos difieren en la l%cnea %d:\n", 161, numLinea);
            printf("Archivo 1: %s", res1 ? linea1 : "<SIN LINEA>\n");
            printf("Archivo 2: %s", res2 ? linea2 : "<SIN LINEA>\n");
            break;
        }

        // CASO 3: MISMA CANTIDAD DE LÍNEAS, DIFERENTE CONTENIDO
        // Sacar \n que puede dar error
        int len1 = strlen(linea1);
        if (len1 > 0 && linea1[len1-1] == '\n') linea1[len1-1] = '\0';
        int len2 = strlen(linea2);
        if (len2 > 0 && linea2[len2-1] == '\n') linea2[len2-1] = '\0';

        if (strcmp(linea1, linea2) != 0) {
            printf("Los archivos difieren en la l%cnea %d:\n", 161, numLinea);
            printf("Archivo 1: %s\n", linea1);
            printf("Archivo 2: %s\n", linea2);
            break;
        }
        numLinea++;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char archivo1[51], archivo2[51];

    printf("Ingrese nombre del primer archivo: ");
    scanf("%50s", archivo1);

    printf("Ingrese nombre del segundo archivo: ");
    scanf("%50s", archivo2);

    fp1 = fopen(archivo1, "r");
    fp2 = fopen(archivo2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error abriendo archivos.\n");
        return 1;
    }

    compararArchivos(fp1, fp2);

    fclose(fp1);
    fclose(fp2);
    return 0;
}




EJERCICIO 5:
PARA PILA ESTÁTICA EJERCICIO 4 TP 7 + MAIN PRUEBA:
#define MAX 100

typedef struct {
    int elementos[MAX];
    int tope;
} PilaEst;

void init(PilaEst *p) {
    p->tope = -1;
}

int isEmpty(PilaEst p) {
    return p.tope == -1;
}

int isFull(PilaEst p) {
    return p.tope == MAX - 1;
}

void apilar(PilaEst *p, int nro) {
    if (!isFull(*p)) {
        p->tope++;
        p->elementos[p->tope] = nro;
    } else {
        printf("La pila est%c llena.\n", 160);
    }
}

void desapilar(PilaEst *p) {
    if (!isEmpty(*p)) {
        p->tope--;
    } else {
        printf("La pila est%c vac%ca.\n", 160, 161);
    }
}

int top(PilaEst p) {
    return p.elementos[p.tope];
}

void imprimir_pila(PilaEst p) {
    printf("Elementos en la pila (de tope a base): ");
    while (!isEmpty(p)) {
        printf("%d ", top(p));
        desapilar(&p);
    }
    printf("\n");
}

void guardar_pila_en_archivo(PilaEst p, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir archivo para guardar la pila");
        return;
    }

    // Guardar cada elemento por línea, del tope hacia abajo
    while (!isEmpty(p)) {
        fprintf(archivo, "%d\n", top(p));
        desapilar(&p);
    }
    fclose(archivo);
    printf("Pila guardada correctamente en %s\n", nombreArchivo);
}

int main() {
    PilaEst pilaEnteros;
    init(&pilaEnteros);

    apilar(&pilaEnteros, 10);
    apilar(&pilaEnteros, 20);
    apilar(&pilaEnteros, 30);
    apilar(&pilaEnteros, 40);
    apilar(&pilaEnteros, 50);
    apilar(&pilaEnteros, 60);
    apilar(&pilaEnteros, 70);

    imprimir_pila(pilaEnteros);

    printf("Elemento superior: %d\n", top(pilaEnteros));

    desapilar(&pilaEnteros);
    printf("Elemento superior despu%cs de la supresi%cn: %d\n", 130, 162, top(pilaEnteros));
    imprimir_pila(pilaEnteros);

    desapilar(&pilaEnteros);
    printf("Elemento superior despu%cs de la supresi%cn: %d\n", 130, 162, top(pilaEnteros));
    imprimir_pila(pilaEnteros);

    desapilar(&pilaEnteros);
    printf("Elemento superior despu%cs de la supresi%cn: %d\n", 130, 162, top(pilaEnteros));
    imprimir_pila(pilaEnteros);

    guardar_pila_en_archivo(pilaEnteros, "backup.txt");

    return 0;
}


MENÚ dinámico:
int main() {
    PilaEst pilaEnteros;
    int opcion;
    int valor;

    init(&pilaEnteros);

    do {
        printf("Menu:\n");
        printf("1. Apilar un n%cmero\n", 163);
        printf("2. Mostrar elemento tope\n");
        printf("3. Desapilar Pila\n");
        printf("4. Imprimir tope\n");
        printf("5. Guardar pila en archivo backup.txt\n");
        printf("6. Salir\n");
        printf("Elija opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if(!isFull(pilaEnteros)){
                printf("Ingrese n%cmero a apilar: ", 163);
                scanf("%d", &valor);
                apilar(&pilaEnteros, valor);
                }
                else printf("ERROR. LA PILA ESTA LLENA.");
                printf("\n\n");
                break;
            case 2:
                if(!isEmpty(pilaEnteros)) printf("TOPE: %d\n\n", top(pilaEnteros));
                else printf("ERROR. LA PILA ESTA VACIA.");
                printf("\n\n");
                break;
            case 3:
                if(!isEmpty(pilaEnteros)){
                    desapilar(&pilaEnteros);
                    printf("Elemento superior despu%cs de la supresi%cn: %d\n", 130, 162, top(pilaEnteros));
                    imprimir_pila(pilaEnteros);
                }
                else printf("ERROR. LA PILA ESTA VACIA.");
                printf("\n\n");
                break;
            case 4:
                if(!isEmpty(pilaEnteros)) imprimir_pila(pilaEnteros);
                else printf("ERROR. LA PILA ESTA VACIA.");
                printf("\n\n");
                break;
            case 5:
                if(!isEmpty(pilaEnteros)){
                guardar_pila_en_archivo(pilaEnteros, "backup.txt");
                printf("\n\n");
                }
                else printf("ERROR. LA PILA ESTA VACIA. \n\n");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn inv%clida. Intente de nuevo.\n", 162, 160);
        }
    } while (opcion != 6);

    return 0;
}




FILA ESTÁTICA:
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char elementos[MAX];
    int ultimo;
} FilaEst;


void initFila(FilaEst *f) {
    f->ultimo = -1;
}

int isEmpty(FilaEst f) {
    return f.ultimo == -1;
}

int isFull(FilaEst f) {
    return f.ultimo == MAX - 1;
}

int insertF(FilaEst *f, char elemento) {
    if (isFull(*f)) return -1;
        f->ultimo++;
        f->elementos[f->ultimo] = elemento;
        return 1;
}

int supress(FilaEst *f) {
    if (isEmpty(*f)) return -1;
    int i,n;
    n=f->ultimo;
    for (i=0; i<n; i++) {
        f->elementos[i] = f->elementos[i + 1];
     }
    f->ultimo--;
    return 1;
}

char copyF(FilaEst f){
    return f.elementos[0];
}

void imprimirFila(FilaEst f) {
    if (isEmpty(f)) {
        printf("La fila est%c vac%ca.\n", 160, 161);
        return;
    }
    printf("Fila actual: ");
    while (!isEmpty(f)) {
        printf("%c ", copyF(f));
        supress(&f);
    }
    printf("\n");
}

void guardar_fila_en_archivo(FilaEst f, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir archivo para guardar la fila");
        return;
    }
    while (!isEmpty(f)) {
        fprintf(archivo, "%c\n", copyF(f));
        supress(&f);
    }
    fclose(archivo);
    printf("Fila guardada correctamente en %s\n", nombreArchivo);
}

int main() {
    FilaEst filaChar;
    int opcion;
    char valor;

    initFila(&filaChar);

    do {
        printf("Menu:\n");
        printf("1. Insertar un caracter en la fila\n");
        printf("2. Mostrar elemento al frente\n");
        printf("3. Suprimir elemento del frente\n");
        printf("4. Imprimir toda la fila\n");
        printf("5. Guardar fila en archivo backup.txt\n");
        printf("6. Salir\n");
        printf("Elija opci%cn: ", 162);
        scanf(" %d", &opcion);

        switch (opcion) {
            case 1:
                if (!isFull(filaChar)) {
                    printf("Ingrese un caracter a insertar: ");
                    scanf(" %c", &valor);
                    insertF(&filaChar, valor);
                } else {
                    printf("ERROR. LA PILA ESTA LLENA.");
                }
                printf("\n\n");
                break;
            case 2:
                if (!isEmpty(filaChar)) {
                    printf("Frente de la fila: %c\n", copyF(filaChar));
                } else {
                    printf("ERROR. LA PILA ESTA VACIA.");
                }
                printf("\n\n");
                break;
            case 3:
                if (!isEmpty(filaChar)) {
                    char sup = copyF(filaChar);
                    supress(&filaChar);
                    printf("Elemento suprimido del frente: %c\n", sup);
                } else {
                    printf("ERROR. LA PILA ESTA VACIA.");
                }
                printf("\n\n");
                break;
            case 4:
                if(!isEmpty(filaChar)) imprimirFila(filaChar);
                else printf("ERROR. LA PILA ESTA VACIA.");
                printf("\n\n");
                break;
            case 5:
                if (!isEmpty(filaChar)) {
                    guardar_fila_en_archivo(filaChar, "backup.txt");
                } else {
                    printf("ERROR. LA PILA ESTA VACIA.");
                }
                printf("\n\n");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn inv%clida. Intente de nuevo.\n", 162, 160);
        }
    } while (opcion != 6);

    return 0;
}




LISTA ESTÁTICA:




