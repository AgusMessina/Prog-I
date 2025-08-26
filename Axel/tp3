#include <stdio.h>

//3- Responder los siguientes puntos usando lo ya resuelto en los puntos anteriores, siempre que sea posible:

/*a. Definir un arreglo de diez elementos de tipo float llamado números e inicializar los
elementos con los valores 0.0, 1.1, 2.2, ..., 9.9. Asumir que la constante simbólica
SIZE ha sido definida como 10.*/

/*
#define SIZE 10
float numeros [10]{
0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9
}
*/

/*b. Definir un puntero, nPtr, que apunte a un objeto de tipo float.*/

//float *nPtro;

/*c. Imprimir los elementos del arreglo números usando notación de suscriptos de
arreglos. Usar una sentencia for y asumir que la variable de control i entera ha sido
definida.*/

/*
for (int i=0; i<SIZE; i++){
    printf("%f", numeros[i]);
}
*/

/*d. Dar dos sentencias alternativas para asignar la dirección base del arreglo números
en el puntero nPtr.*/

/*
nPtro = numeros;
nPtr = &numeros[0];
*/

/*e. Imprimir los elementos del arreglo números usando notación de punteros con el
puntero nPtr.*/

/*
for (int i = 0; i < SIZE; i++) {
    printf("%f", *(nPtr + i));
}
*/

/*f. Imprimir los elementos del arreglo números usando notación de punteros con el
nombre del arreglo como puntero.*/

/*
for (int i = 0; i < SIZE; i++) {
    printf("%.1f ", *(numeros + i));
}
*/

/*g. Imprimir los elementos del arreglo números usando notación de suscriptos con el
puntero nPtr.*/

/*
for (int i = 0; i < SIZE; i++) {
    printf("%.1f ", nPtr[i]);
}
*/

/*h. Referenciar al elemento 4 del arreglo números usando notación de suscriptos,
notación de puntero con el nombre del arreglo como puntero, notación de suscripto
con el puntero nPtr y notación de puntero con el puntero nPtr.*/

/*
numeros[4]
*(numeros+4)
nPtro[4]
*(p+4)
*/

/*i. Asumir que nPtr apunta al comienzo del arreglo números. ¿Qué dirección es
referenciada por nPtr + 8? ¿Qué valor se encuentra almacenado en esa dirección?*/

//Respuesta:  nPtr + 8 apunta a la dirección del noveno elemento (índice 8) del arreglo. El valor almacenado en nPtr + 8 será 8.8.

/*j. Asumir que nPtr apunta a numeros[5]. ¿Qué dirección es referenciada por nPtr - = 4?
¿Qué valor se encuentra almacenado en esa dirección?/*

//Respuesta: nPtr - = 4 apunta a la direccion del segundo elemento (indice 1) del arreglo. El valor almacenado en nPtr - = 4 sera 1.1
// Si nPtr apunta a numeros[5] y luego se le resta 4, entonces nPtr apuntará a numeros[1].


//////////////////////////////////////////////////////////////////////////////////////////////////
//Ejercicio 12

#include <stdio.h>
/*
void ingreso_precios(float precios[]) {
    printf("\n--INGRESO DE PRECIOS DE LOS PRODUCTOS--\n");
    for (int i = 0; i < 10; i++) {
        printf("Ingrese el precio del producto %i: $", i + 1);
        scanf("%f", &precios[i]);
    }
}

void calcular_promocion(float precios[], float promocion[]) {
    printf("\n--CALCULAR PROMOCION--\n");
    for (int i = 0; i < 10; i++) {
        promocion[i] = precios[i] * 0.85; // Aplica el 15% de descuento
    }
}

void muestra_precios(float precios[], float promocion[]) {
    printf("\n--MOSTRANDO PRECIOS DE PRODUCTOS--\n");
    for (int i = 0; i < 10; i++) {
        printf("Producto %i: Precio Lista = $%.2f, Precio Promoción = $%.2f\n", i + 1, precios[i], promocion[i]);
    }
}

int main() {
    int opcion;
    float precios[10], promocion[10];

    do {
        printf("\nMENU\n");
        printf("1. Ingresar precios de los productos\n");
        printf("2. Calcular promocion\n");
        printf("3. Mostrar precios\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingreso_precios(precios);
                break;
            case 2:
                calcular_promocion(precios, promocion);
                break;
            case 3:
                muestra_precios(precios, promocion);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
*/

//Ejercicio 11
/*
#include <stdio.h>

// Función para registrar la hora de ingreso de un operario
void registrarIngreso(int codigoOperario, int *ingresoHoras, int *ingresoMinutos, int posicion) {
    int horas, minutos;
    do {
        printf("Ingrese la hora de ingreso (0-23): ");
        scanf("%d", &horas);
    } while (horas < 0 || horas > 23);

    do {
        printf("Ingrese los minutos de ingreso (0-59): ");
        scanf("%d", &minutos);
    } while (minutos < 0 || minutos > 59);

    ingresoHoras[posicion] = horas;
    ingresoMinutos[posicion] = minutos;
    printf("INGRESO: Código: %d, Hora: %02d:%02d\n", codigoOperario, horas, minutos);
}

// Función para registrar la hora de egreso de un operario
void registrarEgreso(int codigoOperario, int *egresoHoras, int *egresoMinutos, int ingresoHoras[], int ingresoMinutos[], int posicion) {
    int horas, minutos;
    do {
        printf("Ingrese la hora de egreso (0-23): ");
        scanf("%d", &horas);
    } while (horas < 0 || horas > 23);

    do {
        printf("Ingrese los minutos de egreso (0-59): ");
        scanf("%d", &minutos);
    } while (minutos < 0 || minutos > 59);

    egresoHoras[posicion] = horas;
    egresoMinutos[posicion] = minutos;
    printf("EGRESO: Código: %d, Hora: %02d:%02d\n", codigoOperario, horas, minutos);
}

// Función para calcular y mostrar las horas trabajadas por un operario
void calcularHorasTrabajadas(int codigoOperario, int ingresoHoras, int ingresoMinutos, int egresoHoras, int egresoMinutos) {
    int horasTrabajadas = egresoHoras - ingresoHoras;
    int minutosTrabajados = egresoMinutos - ingresoMinutos;

    if (minutosTrabajados < 0) {
        minutosTrabajados += 60;
        horasTrabajadas--;
    }

    if (horasTrabajadas < 0) {
        horasTrabajadas += 24;
    }

    printf("El operario con código %d trabajó %d horas y %d minutos.\n", codigoOperario, horasTrabajadas, minutosTrabajados);
}

int main() {
    int opcion;
    int codigoOperario;
    int ingresoHoras[5] = {-1, -1, -1, -1, -1}; // Inicializar todos los horarios a -1
    int ingresoMinutos[5] = {-1, -1, -1, -1, -1};
    int egresoHoras[5] = {-1, -1, -1, -1, -1};
    int egresoMinutos[5] = {-1, -1, -1, -1, -1};
    int contador = 0;

    do {
        printf("\nMENU\n");
        printf("1. Ingresar\n");
        printf("2. Egresar\n");
        printf("3. Calcular horas trabajadas\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                if (contador < 5) {
                    do {
                        printf("Ingrese su código (4000 a 4004): ");
                        scanf("%d", &codigoOperario);
                    } while (codigoOperario < 4000 || codigoOperario > 4004);

                    int posicionIngreso = codigoOperario - 4000;
                    registrarIngreso(codigoOperario, ingresoHoras, ingresoMinutos, posicionIngreso);
                    contador++;
                } else {
                    printf("Se ha alcanzado el límite de operarios.\n");
                }
                break;

            case 2:
                do {
                    printf("Ingrese su código (4000 a 4004): ");
                    scanf("%d", &codigoOperario);
                } while (codigoOperario < 4000 || codigoOperario > 4004);

                int posicionEgreso = codigoOperario - 4000;
                if (ingresoHoras[posicionEgreso] != -1) {
                    registrarEgreso(codigoOperario, egresoHoras, egresoMinutos, ingresoHoras, ingresoMinutos, posicionEgreso);
                } else {
                    printf("El operario con código %d no ha registrado un ingreso.\n", codigoOperario);
                }
                break;

            case 3:
                do {
                    printf("Ingrese su código (4000 a 4004): ");
                    scanf("%d", &codigoOperario);
                } while (codigoOperario < 4000 || codigoOperario > 4004);

                int posicionCalculo = codigoOperario - 4000;
                if (ingresoHoras[posicionCalculo] != -1 && egresoHoras[posicionCalculo] != -1) {
                    calcularHorasTrabajadas(codigoOperario, ingresoHoras[posicionCalculo], ingresoMinutos[posicionCalculo], egresoHoras[posicionCalculo], egresoMinutos[posicionCalculo]);
                } else {
                    printf("El operario con código %d no tiene un ingreso y egreso registrados.\n", codigoOperario);
                }
                break;

            case 4:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
*/


//Ejercicio 10
/*
#include <stdio.h>

// Función para imprimir el arreglo de cadenas y valores de compra y venta
void imprimir_dolar(char *bancos[], float d_compra[], float d_venta[], int cantidad) {
    int i;
    printf("\nBANCOS\t | COMPRA | VENTA\n");
    printf("-------------------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%-35s | %.3f | %.3f\n", bancos[i], d_compra[i], d_venta[i]);
    }
}

void valor_promedio(float d_compra[], float d_venta[], int cantidad){
    float promedio_compra = 0.0;
    float promedio_venta = 0.0;

for (int i = 0; i < cantidad; i++) {
        promedio_compra += d_compra[i];
        promedio_venta += d_venta[i];
    }
        promedio_compra /= cantidad;
        printf("\nEl valor promedio del dolar Compra es: $%.3f\n", promedio_compra);
        promedio_venta /= cantidad;
        printf("\nEl valor promedio del dolar Venta es: $%.3f\n", promedio_venta);

}

int main(){
    // Declaración correcta del arreglo de cadenas (strings)
    char *bancos[] = {
        "BANCO DE GALICIA Y BUENOS AIRES S.A.U.",
        "BANCO DE LA NACION ARGENTINA"
    };

    // Declaración correcta de los arreglos de float con valores
    float d_compra[] = {923.000, 926.050};
    float d_venta[] = {998.000, 965.950};

    // Determinar el número de elementos en los arreglos
    int cantidad = sizeof(d_compra) / sizeof(d_compra[0]); // En este caso, 2

    // Llamada a la función para imprimir los datos
    imprimir_dolar(bancos, d_compra, d_venta, cantidad);

    valor_promedio(d_compra, d_venta, cantidad);

    return 0;
}
*/

//Ejercicio 9
/*
// Función para ingresar las notas en dos arreglos.
void cargarNotas(float notas[]) {
    printf("--INGRESO DE NOTAS--\n");
    for (int f = 0; f < 13; f++) {
        printf("Ingrese la nota de la materia %i: ", f + 1);
        scanf("%f", &notas[f]);
        while (notas[f] > 10 || notas[f] < 1) {
            printf("Ingreso de notas inválido.\nIngrese del 1 al 10: ");
            scanf("%f", &notas[f]);
        }
    }
}

// Función para mostrar las notas.
void muestraNotas(float notas[]) {
    printf("\n--MOSTRANDO NOTAS--\n");
    for (int f = 0; f < 13; f++) {
        printf("La nota de la materia %i es: %.2f\n", f + 1, notas[f]);
    }
}

void aplazos(float notas[]){
int s_nota = 0;
int a_nota = 0;
int r_nota = 0;

for (int f=0; f<13; f++){
    if (notas[f] <=10 && notas[f] >=8 ){
        s_nota++;
    }
    if (notas[f] <=7 && notas[f] >=4 ){
        a_nota++;
    }
    if (notas[f] <=3 && notas[f] >=1 ){
        r_nota++;
    }
}

if (r_nota>=7){
    printf("Alta Posibilidad de Repetir");
}else{
    printf("Baja Posibilidad de Repetir");

}

}

int main() {
    float notas[13];

    cargarNotas(notas);
    muestraNotas(notas);
    aplazos(notas);

    return 0;
}
*/

//Ejercicio 8
/*
#include <stdio.h>
#include <string.h>

#define MAXIMO 100

// Función para ingresar los strings en dos arreglos.
void ingresarStrings(char str1[], char str2[]) {
    printf("Ingrese el primer string: ");
    scanf("%s", str1);

    printf("Ingrese el segundo string: ");
    scanf("%s", str2);
}

// Función para comparar dos strings e indicar cuál es el menor.
char* obtenerMenorString(char str1[], char str2[]) {
    if (strcmp(str1, str2) < 0) {
        return str1;
    } else {
        return str2;
    }
}

// Función para almacenar el mayor string en una variable.
char* obtenerMayorString(char str1[], char str2[]) {
    if (strcmp(str1, str2) > 0) {
        return str1;
    } else {
        return str2;
    }
}

// Función para contar los caracteres de un string sin usar `strlen`.
int contarCaracteres(char str[]) {
    int contador = 0;
    while (str[contador] != '\0') {
        contador++;
    }
    return contador;
}

// Función para comparar y almacenar el string mayor de todos los pares.
void compararMayorTotal(char mayorActual[], char nuevoString[], char mayorTotal[]) {
    if (strcmp(nuevoString, mayorActual) > 0) {
        strcpy(mayorTotal, nuevoString);
    } else {
        strcpy(mayorTotal, mayorActual);
    }
}

int main() {
    char str1[MAXIMO], str2[MAXIMO];
    char mayor[MAXIMO], menor[MAXIMO];
    char mayorTotal[MAXIMO] = "";

    for (int i = 1; i <= 2; i++) {
        printf("\n--- Ingresando par de strings %d ---\n", i);
        ingresarStrings(str1, str2);

        strcpy(menor, obtenerMenorString(str1, str2));
        printf("El menor string es: %s\n", menor);

        strcpy(mayor, obtenerMayorString(str1, str2));
        printf("El mayor string es: %s\n", mayor);

        printf("Cantidad de caracteres en '%s': %d\n", str1, contarCaracteres(str1));
        printf("Cantidad de caracteres en '%s': %d\n", str2, contarCaracteres(str2));

        compararMayorTotal(mayor, mayorTotal, mayorTotal);
    }

    printf("\nEl string mayor de todos es: %s\n", mayorTotal);

    return 0;
}
*/


//Ejercicio 7
/*
#define MAXIMO 100

void cargarCadenas(char vec[], int cant) {
    int posicionLibre = 0, contador, contadorTemp;
    char temp[MAXIMO];
    printf("Carga de cadenas de caracteres:\n");

    for (contador = 0; (contador < cant && posicionLibre < cant); contador++) {
        printf("Ingrese una cadena (espacio disponible: %d): ", cant - posicionLibre);
        scanf("%s", temp);

        for (int contadorTemp = 0; (temp[contadorTemp] != '\0' && posicionLibre < cant); contadorTemp++) {
            vec[posicionLibre++] = temp[contadorTemp];
        }

        if (posicionLibre < cant - 1) {
            vec[posicionLibre++] = ' ';
        }
    }

    if (posicionLibre < cant || posicionLibre == cant) {
        vec[posicionLibre] = '\0';
    }
}

void imprimirCadenas(char vec[]) {
    printf("\nCadenas concatenadas:\n");
    printf("%s\n", vec);
}

int main() {
    int cantidad;
    printf("Ingrese el tamaño del vector de números: ");
    scanf("%d", &cantidad);

    while (cantidad <= 0 || cantidad > MAXIMO) {
        printf("Ingrese un número válido: ");
        scanf("%d", &cantidad);
    }

    char vector[cantidad + 1];
    cargarCadenas(vector, cantidad);
    imprimirCadenas(vector);

    return 0;
}
*/

//Ejercicio 6
/*
void ingresar_reales(float *arreglo, int capacidad) {
    int i;
    float valor;

    for (i = 0; i < capacidad; i++) {
        do {
            printf("Ingrese el carácter para la posición %d (no puede ser un espacio): ", i);
            scanf("%f", &valor);
            if (valor == ' ') {
                printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
            }
        } while (valor == ' ');

        arreglo[i] = valor;
    }
}

// Función para imprimir el arreglo de caracteres
void imprimir_reales(float *arreglo, int cantidad) {
    int i;
    printf("\nPosición | Valor\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %f\n", i, arreglo[i]);
    }
}

void ordenar_reales(float *arreglo, int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (arreglo[j] < arreglo[minIndex]) {
                minIndex = j;  // Encuentra el índice del valor mínimo
            }
        }
        // Intercambia el valor mínimo encontrado con el valor en la posición i
        if (minIndex != i) {
            float temp = arreglo[i];
            arreglo[i] = arreglo[minIndex];
            arreglo[minIndex] = temp;
        }
    }
}



int main() {
    int capacidad;

    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    float arreglo[capacidad];

    // Llenar el arreglo con caracteres
    ingresar_reales(arreglo, capacidad);

    // Mostrar el arreglo antes de la eliminación
    printf("\nArreglo antes de ordenar:\n");
    imprimir_reales(arreglo, capacidad);

    ordenar_reales(arreglo, capacidad);

    // Mostrar el arreglo después de la eliminación
    printf("\nArreglo después de ordenar:\n");
    imprimir_reales(arreglo, capacidad);

    return 0;
}
*/



//Ejercicio 5
/*
#include <stdio.h>

// Función para ingresar los caracteres en el arreglo
void ingresar_caracteres(char *arreglo, int capacidad) {
    int i;
    char caracter;

    for (i = 0; i < capacidad; i++) {
        do {
            printf("Ingrese el carácter para la posición %d (no puede ser un espacio): ", i);
            scanf(" %c", &caracter);
            if (caracter == ' ') {
                printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
            }
        } while (caracter == ' ');

        arreglo[i] = caracter;
    }
}

// Función para imprimir el arreglo de caracteres
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;
    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

// Función para eliminar un carácter en una posición específica
void eliminar_caracter(char *arreglo, int capacidad) {
    int posicion;

    do {
        printf("Ingrese la posición donde desea eliminar el carácter (0 a %d): ", capacidad - 1);
        scanf("%d", &posicion);

        if (posicion < 0 || posicion >= capacidad) {
            printf("Posición inválida. Intente nuevamente.\n");
        }
    } while (posicion < 0 || posicion >= capacidad);

    // Desplazar caracteres hacia la izquierda
    for (int i = posicion; i < capacidad - 1; i++) {
        arreglo[i] = arreglo[i + 1];
    }

    // Rellenar la última posición con un carácter nulo para indicar espacio vacío
    arreglo[capacidad - 1] = '\0';
}

int main() {
    int capacidad;

    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    char arreglo[capacidad];

    // Llenar el arreglo con caracteres
    ingresar_caracteres(arreglo, capacidad);

    // Mostrar el arreglo antes de la eliminación
    printf("\nArreglo antes de la eliminación:\n");
    imprimir_caracteres(arreglo, capacidad);

    // Eliminar un carácter en la posición especificada
    eliminar_caracter(arreglo, capacidad);

    // Mostrar el arreglo después de la eliminación
    printf("\nArreglo después de la eliminación:\n");
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/


/*
int main(){

char b[10] = {'a', 'b', '?'};

   printf("%c", b[3]);
return 0;

}
*/


//EJERCICO 4

// Función para ingresar los caracteres en el arreglo
/*
void ingresar_caracteres(char *arreglo, int capacidad) {
    int i;
    char caracter;

    for (i = 0; i < capacidad; i++) {
        do {
            printf("Ingrese el carácter para la posición %d (no puede ser un espacio): ", i);
            scanf(" %c", &caracter);
            if (caracter == '\n') {
                printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
            }
        } while (caracter == '\n');

        arreglo[i] = caracter;
    }
}

// Función para imprimir el arreglo de caracteres
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;
    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

// Función para insertar un carácter en una posición específica
void insertar_caracter(char *arreglo, int capacidad) {
    int posicion;
    char caracter;

    do {
        printf("Ingrese la posición donde desea insertar el carácter (0 a %d): ", capacidad - 1);
        scanf("%d", &posicion);

        if (posicion < 0 || posicion >= capacidad) {
            printf("Posición inválida. Intente nuevamente.\n");
        }
    } while (posicion < 0 || posicion >= capacidad);

    do {
        printf("Ingrese el carácter que desea insertar (no puede ser un espacio): ");
        scanf(" %c", &caracter);
        if (caracter == ' ') {
            printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
        }
    } while (caracter == ' ');

    // Desplazar caracteres hacia la derecha
    for (int i = capacidad - 1; i > posicion; i--) {
        arreglo[i] = arreglo[i - 1];
    }

    // Insertar el carácter en la posición seleccionada
    arreglo[posicion] = caracter;
}

int main() {
    int capacidad;

    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    char arreglo[capacidad];

    ingresar_caracteres(arreglo, capacidad);

    printf("\nArreglo antes de la inserción:\n");
    imprimir_caracteres(arreglo, capacidad);

    insertar_caracter(arreglo, capacidad);

    printf("\nArreglo después de la inserción:\n");
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/


/*
// Función para insertar un carácter en una posición específica y desplazar el resto (ANTES DEL DESPLAZAMIENTO)
void insertar_caracter(char *arreglo, int capacidad) {
    int posicion;
    char caracter;

    do {
        // Solicitar al usuario la posición donde desea insertar el carácter
        printf("Ingrese la posición donde desea insertar el carácter (0 a %d): ", capacidad - 1);
        scanf("%d", &posicion);

        // Verificar si la posición está dentro del rango permitido
        if (posicion < 0 || posicion >= capacidad) {
            printf("Posición inválida. Intente nuevamente.\n");
        }
    } while (posicion < 0 || posicion >= capacidad);

    // Limpiar el buffer de entrada para evitar problemas con `scanf` y `getchar`
    getchar();

    // Solicitar al usuario el carácter a insertar
    do {
        printf("Ingrese el carácter que desea insertar (no puede ser un espacio): ");
        scanf("%c", &caracter);
        if (caracter == ' ') {
            printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
        }
    } while (caracter == ' ');

    // Desplazar los caracteres a la derecha para hacer espacio
    for (int i = capacidad - 1; i > posicion; i--) {
        arreglo[i] = arreglo[i - 1];
    }

    // Insertar el carácter en la posición seleccionada
    arreglo[posicion] = caracter;
}

// Función para imprimir los caracteres en formato de tabla
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario e inicializarlo con '\0'
    char arreglo[capacidad];
    for (int i = 0; i < capacidad; i++) {
        arreglo[i] = '\0';
    }

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    // Llamar a la función para insertar un carácter en el arreglo
    insertar_caracter(arreglo, capacidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/


/*
//FUNCIONA SIN DESPLAZAMIENTO Y TIENE RESTRICCION PARA EL "ENTER"
// Función para insertar un carácter en una posición específica
void insertar_caracter(char *arreglo, int capacidad) {
    int posicion;
    char caracter;

    do {
        // Solicitar al usuario la posición donde desea insertar el carácter
        printf("Ingrese la posición donde desea insertar el carácter (0 a %d): ", capacidad - 1);
        scanf("%d", &posicion);

        // Verificar si la posición está dentro del rango permitido
        if (posicion < 0 || posicion >= capacidad) {
            printf("Posición inválida. Intente nuevamente.\n");
        }
        // Verificar si la posición está ocupada
        else if (arreglo[posicion] != '\0') {
            printf("La posición %d ya está ocupada. Intente con otra posición.\n", posicion);
        }
    } while (posicion < 0 || posicion >= capacidad || arreglo[posicion] != '\0');

    // Limpiar el buffer de entrada para evitar problemas con `scanf` y `getchar`
    getchar();

    // Solicitar al usuario el carácter a insertar
    do {
        printf("Ingrese el carácter que desea insertar (no puede ser un espacio): ");
        scanf("%c", &caracter);
        if (caracter == '\n') {
            printf("Error: No se permite ingresar un espacio. Intente nuevamente.\n");
        }
    } while (caracter == '\n');

    // Insertar el carácter en la posición seleccionada
    arreglo[posicion] = caracter;
}

// Función para imprimir los caracteres en formato de tabla
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario e inicializarlo con '\0'
    char arreglo[capacidad];
    for (int i = 0; i < capacidad; i++) {
        arreglo[i] = '\0';
    }

        // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    // Llamar a la función para insertar un carácter en el arreglo
    insertar_caracter(arreglo, capacidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/



#include <stdio.h>
/*


// Función para insertar un carácter en una posición específica
void insertar_caracter(char *arreglo, int capacidad) {
    int posicion;
    char caracter;

    do {
        // Solicitar al usuario la posición donde desea insertar el carácter
        printf("Ingrese la posición donde desea insertar el carácter (0 a %d): ", capacidad - 1);
        scanf("%d", &posicion);

        // Verificar si la posición está dentro del rango permitido
        if (posicion < 0 || posicion >= capacidad) {
            printf("Posición inválida. Intente nuevamente.\n");
        }
        // Verificar si la posición está ocupada
        else if (arreglo[posicion] != '\0') {
            printf("La posición %d ya está ocupada. Intente con otra posición.\n", posicion);
        }
    } while (posicion < 0 || posicion >= capacidad || arreglo[posicion] != '\0');

    // Limpiar el buffer de entrada para evitar problemas con `scanf` y `getchar`
    getchar();

    // Solicitar al usuario el carácter a insertar
    printf("Ingrese el carácter que desea insertar: ");
    scanf("%c", &caracter);
    while (caracter == '\n'){
        printf("Error");
        scanf(" %c", &caracter);
        getchar();
    }
    // Insertar el carácter en la posición seleccionada
    arreglo[posicion] = caracter;
}

// Función para imprimir los caracteres en formato de tabla
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario e inicializarlo con '\0'
    char arreglo[capacidad];
    for (int i = 0; i < capacidad; i++) {
        arreglo[i] = '\0';
    }

    // Llamar a la función para insertar un carácter en el arreglo
    insertar_caracter(arreglo, capacidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/


/*

//FUNCIONA PARA LLENAR EL ARREGLO
// Función para ingresar caracteres en el arreglo
void ingresar_caracteres(char *arreglo, int capacidad) {
    int posicion;
    char caracter;
    int elementos_ingresados = 0;

    while (elementos_ingresados < capacidad) {
        do {
            // Solicitar al usuario la posición
            printf("Ingrese la posición donde desea insertar el carácter (0 a %d): ", capacidad - 1);
            scanf("%d", &posicion);

            // Verificar si la posición está dentro del rango permitido
            if (posicion < 0 || posicion >= capacidad) {
                printf("Posición inválida. Intente nuevamente.\n");
            }
            // Verificar si la posición está ocupada
            else if (arreglo[posicion] != '\0') {
                printf("La posición %d ya está ocupada. Intente con otra posición.\n", posicion);
            }
        } while (posicion < 0 || posicion >= capacidad || arreglo[posicion] != '\0');

        // Limpiar el buffer de entrada para evitar problemas con `scanf` y `getchar`
        getchar();

        // Solicitar al usuario el carácter a insertar
        printf("Ingrese el carácter que desea insertar: ");
        scanf("%c", &caracter);  // Leer el carácter

        // Insertar el carácter en la posición seleccionada
        arreglo[posicion] = caracter;
        elementos_ingresados++;
    }
}

// Función para imprimir los caracteres en formato de tabla
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de caracteres que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario e inicializarlo con '\0'
    char arreglo[capacidad];
    for (int i = 0; i < capacidad; i++) {
        arreglo[i] = '\0';
    }

    // Llamar a la función para ingresar caracteres en el arreglo
    ingresar_caracteres(arreglo, capacidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, capacidad);

    return 0;
}
*/



//Ejercicio 3
/*
// Función para ingresar números en el arreglo
void ingresar_numeros(int *arreglo, int capacidad) {
    int i;

    for (i = 0; i < capacidad; i++) {
        printf("Ingrese un número entero para la posición %d: ", i);
        scanf("%d", &arreglo[i]);
    }
}

void elMenorNumero(int *arreglo, int cantidad) {
    int min = *arreglo; // Inicializa min con el primer valor del arreglo

    for (int i = 1; i < cantidad; i++) { // Comienza desde el segundo elemento
        if (*(arreglo + i) < min) { // Comparación usando el puntero
            min = *(arreglo + i); // Actualiza min si se encuentra un valor menor
        }
    }

    // Aquí puedes imprimir el valor de min o devolverlo si la función lo requiere
    printf("El menor número es: %d\n", min);
}

int main(){

int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de números que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario
    int arreglo[capacidad];

    // Llamar a la función para ingresar números en el arreglo
    ingresar_numeros(arreglo, capacidad);

    elMenorNumero(arreglo, capacidad);


}
*/



//Ejercicio 2
/*
#include <stdio.h>

// Función para ingresar números en el arreglo
void ingresar_numeros(int *arreglo, int capacidad) {
    int i;

    for (i = 0; i < capacidad; i++) {
        printf("Ingrese un número entero para la posición %d: ", i);
        scanf("%d", &arreglo[i]);
    }
}

// Función para buscar un número en el arreglo
int buscar_numero(int *arreglo, int capacidad, int numero_buscado) {
    int i;

    for (i = 0; i < capacidad; i++) {
        if (arreglo[i] == numero_buscado) {
            return i; // Devuelve la posición si se encuentra el número
        }
    }

    return -1; // Devuelve -1 si no se encuentra el número
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad de números que desea almacenar: ");
    scanf("%d", &capacidad);

    // Validar que la capacidad sea mayor que 0
    while (capacidad <= 0) {
        printf("Error: La capacidad debe ser mayor que 0. Intente de nuevo: ");
        scanf("%d", &capacidad);
    }

    // Declarar el arreglo con la capacidad definida por el usuario
    int arreglo[capacidad];

    // Llamar a la función para ingresar números en el arreglo
    ingresar_numeros(arreglo, capacidad);

    // Solicitar al usuario el número a buscar
    int numero_buscado;
    printf("Ingrese el número que desea buscar: ");
    scanf("%d", &numero_buscado);

    // Llamar a la función para buscar el número en el arreglo
    int resultado = buscar_numero(arreglo, capacidad, numero_buscado);

    // Imprimir el resultado de la búsqueda
    if (resultado != -1) {
        printf("El número %d se encuentra en la posición %d del arreglo.\n", numero_buscado, resultado);
    } else {
        printf("El número %d no se encuentra en el arreglo.\n", numero_buscado);
    }

    return 0;
}
*/

/*
// Función para ingresar caracteres en el arreglo
void ingresar_caracteres(int *arreglo, int capacidad) {
    int i;
    int caracter;

    for (i = 0; i < capacidad; i++) {
        printf("Ingrese un carácter (o presione Enter para finalizar): ");

        // Leer un carácter usando getchar
        caracter = getchar();

        // Verificar si se presionó Enter sin ingresar ningún carácter
        if (caracter == '\n') {
            break;
        }

        // Limpiar el buffer para eliminar el salto de línea
        getchar();

        arreglo[i] = caracter;
    }
}
void imprimir_caracteres(int *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad máxima de caracteres que quiere almacenar: ");
    scanf("%d", &capacidad);
    while (capacidad <=0){
        printf("Error al ingresar un numero negativo o 0. Intente de nuevo");
        scanf("%d", &capacidad);
    }

    // Limpiar el buffer del salto de línea
    getchar();

    // Declarar el arreglo con la capacidad definida por el usuario
    char arreglo[capacidad];

    // Llamar a la función para ingresar caracteres
    ingresar_caracteres(arreglo, capacidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, 5);

    return 0;
}
*/

//Ejercicio 1
/*
#include <stdio.h>

// Función para ingresar caracteres en el arreglo
void ingresar_caracteres(char *arreglo, int capacidad, int *cantidad) {
    int i;
    char caracter;

    for (i = 0; i < capacidad; i++) {
        printf("Ingrese un carácter (o presione Enter para finalizar): ");

        // Leer un carácter usando getchar
        caracter = getchar();

        // Verificar si se presionó Enter sin ingresar ningún carácter
        if (caracter == '\n') {
            break;
        }

        // Limpiar el buffer para eliminar el salto de línea
        getchar();

        arreglo[i] = caracter;
        (*cantidad)++; // Incrementa la cantidad de caracteres ingresados
    }
}

// Función para imprimir los caracteres en formato de tabla
void imprimir_caracteres(char *arreglo, int cantidad) {
    int i;

    printf("\nPosición | Carácter\n");
    printf("-------------------\n");
    for (i = 0; i < cantidad; i++) {
        printf("%8d | %c\n", i, arreglo[i]);
    }
}

int main() {
    int capacidad;
    int cantidad = 0;

    // Pedir al usuario la capacidad del arreglo
    printf("Ingrese la cantidad máxima de caracteres que quiere almacenar: ");
    scanf("%d", &capacidad);
    while (capacidad <=0){
        printf("Error al ingresar un numero negativo o 0. Intente de nuevo");
        scanf("%d", &capacidad);
    }

    // Limpiar el buffer del salto de línea
    getchar();

    // Declarar el arreglo con la capacidad definida por el usuario
    char arreglo[capacidad];

    // Llamar a la función para ingresar caracteres
    ingresar_caracteres(arreglo, capacidad, &cantidad);

    // Llamar a la función para imprimir los caracteres ingresados
    imprimir_caracteres(arreglo, cantidad);

    return 0;
}
*/


/*
#define MAX 5
int main(){


void muestraArreglo(int [], int);void modificaArreglo(int [], int);void modificaUnElemento(int *, int);


int a[MAX] = {2, 4, 6, 8, 10};
int i;
printf("Los valores del arreglo antes de”“ modificarlos son:\n");
muestraArreglo(a, MAX);
modificaArreglo(a, MAX);
printf("Valores del arreglo despues de llamar a modificaArreglo son:\n"); muestraArreglo(a, MAX);
for (i = 0; i < MAX; i++)
modificaUnElemento(&a[i], i);
printf("Valores del arreglo despues de llamar a modificaUnElemento son:\n"); muestraArreglo(a, MAX);
return 0;
}
void muestraArreglo(int b[], int max){
int i;
for (i = 0; i < max; i++)
printf("%d ", b[i]);
printf("\n");
}
void modificaArreglo(int b[], int max){
int i;
for (i = 0; i < max; i++)
b[i] = b[i] + 1;
}

void modificaUnElemento(int *elem, int pos){
*elem = 0;
printf("El valor del elemento %d dentro de modificaUnElemento es: %d\n", pos, *elem);
}
*/


/*
int a[5] = {1, 4, -5, 0, 8};
int *p;
p = a; //es equivalente a p = &a[0];

printf("%d", a[0]);
printf("%d", *p);
printf("%d", *a);
*/
/*
int x[5] = {10, -3, 7, 6, 4};
*/
