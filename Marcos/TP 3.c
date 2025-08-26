EJERCICIO UNO:
void cargar_caracteres(char vec[], int tam)
{
    int x;
    printf("\nCarga de un vector de car%ccteres de tamaño %d.\n", 160, tam);
    for (x = 0; x < tam; x++)
    {
        printf("Cargar carácter %d: ", x + 1);
        scanf(" %c", &vec[x]);
    }
}


void imprimir_caracteres(char vec[], int tam)
{
    int x;
    printf("\nPosici%cn | Car%ccter\n", 162, 160);
    printf("-------------------\n");
    for (x = 0; x < tam; x++)
    {
        printf("%8d | %c\n", x, vec[x]);
    }
    printf("\n");
}

int main()
{
    int tam;
    do {
        printf("Ingrese el tamaño del vector de car%ccteres: ", 160);
        scanf("%d", &tam);
        if (tam <= 0) {
            printf("El tamaño del vector debe ser un n%cmero positivo.\n\n", 163);
        }
    } while (tam <= 0 || tam > 100);

    char vector[tam];
    cargar_caracteres(vector, tam);
    imprimir_caracteres(vector, tam);

    return 0;
}




EJERCICIO DOS:
void cargarNumeros(int vec[], int tam)
{
    int x;
    printf("\nCarga de un vector de enteros de tamaño %d.\n", tam);
    for (x = 0; x < tam; x++)
    {
        printf("Cargar car%ccter %d: ", 160, x + 1);
        scanf(" %d", &vec[x]);
    }
}


void buscarNumero(int vec[], int tam)
{
    int cont, nro;
    int esta = 0;
    printf("\n\n%cQu%c n%cmero desea buscar?: ", 168, 130, 163);
    scanf("%d", &nro);
    puts("-------------------");

    for (cont = 0; cont < tam; cont++){
        if (vec[cont] == nro){
            printf("\nEl numero est%c.\n", 160);
            puts("-------------------");
            esta = 1;
            break;
        }
    }
    if (!esta){
        printf("\nEl n%cmero no est%c\n", 163, 160);
        puts("-------------------");
    }
}

int main()
{
    int cantidad, numero;
    printf("Ingrese el tamaño del vector de numeros: ");
    scanf("%d", &cantidad);

    while (cantidad <= 0){
        printf("\nIngrese un n%cmero v%clido: ", 163, 160);
        scanf("%i", &cantidad);
    }
    int vector[cantidad];

    cargarNumeros(vector, cantidad);
    buscarNumero(vector, cantidad);
    return 0;
}


MEJORA??:
int buscarNumero(int vec[], int tam, int nro) {
    for (int i = 0; i < tam; i++) {
        if (vec[i] == nro)
            return i;
    }
    return -1;
}

MAIN:
….
int nroBuscar;
    printf("\nIngrese número a buscar: ");
    scanf("%d", &nroBuscar);

    int pos = buscarNumero(vector, cantidad, nroBuscar);

    if (pos != -1) {
        printf("El número %d está en la posición %d.\n", nroBuscar, pos);
    } else {
        printf("El número %d no está en el arreglo.\n", nroBuscar);
    }
    return 0;
}




EJERCICIO TRES:
void cargarNumeros(int *vec, int tam) { // o se pone *vec o vec[] o alguna otra forma, son todos lo mismo.
    int cont;
    printf("Carga de un vector de enteros de tamaño %d.\n", tam);
    for (cont = 0; cont < tam; cont++) {
        printf("Cargar número %d: ", cont + 1);
        scanf("%d", &vec[cont]);
    }
}

int numeroMenor(int vec[], int tam) {
    int cont, menor;
    menor = vec[0];

    for (cont = 1; cont < tam; cont++) {
        if (vec[cont] < menor) {
            menor = vec[cont];
        }
    }
    return menor;
}

int main() {
    int cantidad;
    printf("Ingrese el tamaño del vector de n%cmeros: ", 160);
    scanf("%d", &cantidad);

    while (cantidad <= 0) {
        printf("Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &cantidad);
    }

    int vector[cantidad];

    cargarNumeros(vector, cantidad);
    printf("El número menor en el arreglo es: %d\n", numeroMenor(vector, cantidad));
    return 0;
}

// (otra versión en perpl.)



EJERCICIO CUATRO:
#define MAXIMO 256

void cargarCaracteres(char vec[], int tam)
{
    int x;
    printf("Carga de un vector de car%ccteres de tamaño %d.\n", 160, tam);
    for (x = 0; x < tam; x++)
    {
        printf("Cargar carácter %d: ", x + 1);
        scanf(" %c", &vec[x]);
    }
}

void imprimirCaracteres(char vec[], int tam)
{
    int x;
    printf("\nPosici%cn | Car%ccter\n", 162, 160);
    printf("-------------------\n");
    for (x = 0; x < tam; x++)
    {
        printf("%8d | %c\n", x, vec[x]);
    }
    printf("\n");
}

void insertarCaracter(char vec[], int tam){
    int contador, pos;
    char elem, temporal, siguiente;
    printf("Ingrese el car%ccter a agregar: ", 160);
    scanf(" %c", &elem);

    do {
        printf("\nAhora, ingrese la posici%cn (0 a %d): ", 162, tam-1);
        scanf("%d", &pos);
        if (pos < 0 || pos >= tam) {
        printf("Posición inválida. No se pudo insertar el car%ccter.\n", 160);
        }
    } while (pos < 0 || pos >= tam);

    temporal = vec[pos];
    for (contador = pos + 1; contador < tam; contador++) {
        siguiente = vec[contador];
        vec[contador] = temporal;
        temporal = siguiente;
    }
    vec[pos] = elem;
}

void insertarCaracteres(char vec[], int cant){
    int opcion;
    do {
        insertarCaracter(vec, cant);
        printf("\nEl arreglo luego de insertar: ");
        imprimirCaracteres(vec, cant);
        puts("Desea insertar otro elemento? (1 = si || 0 = no)");
        scanf("%d", &opcion);
    }
    while (opcion == 1);
    puts("Saliendo...");
}


int main() {
    int cantidad;
    printf("Ingrese el tamaño del vector de n%cmeros: ", 160);
    scanf("%d", &cantidad);

    while (cantidad <= 0 || cantidad > MAXIMO) {
        printf("Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &cantidad);
    }

    char vector[cantidad];

    cargarCaracteres(vector, cantidad);
    puts("El arreglo inicialmente: ");
    imprimirCaracteres(vector, cantidad);

    insertarCaracteres(vector, cantidad);
    return 0;
}


EJERCICIO 6:
#include <stdio.h>
void cargarNumeros(float vec[], int cant) {
    int cont;
    printf("Carga de un vector de enteros de tama%co %d.\n", 164, cant);
    for (cont = 0; cont < cant; cont++) {
        printf("Cargar n%cmero %d: ", 163, cont + 1);
        scanf("%f", &vec[cont]);
    }
}

void ordenarNumeros(int vec[], int cant) {
    int contExterno, contInterno;
    float temporal;
    for (contExterno = 0; contExterno < cant-1; contExterno++) {
        for (contInterno = 0; contInterno < cant - 1 - contExterno; contInterno++) {
            if (vec[contInterno] > vec[contInterno + 1]) {
                temporal = vec[contInterno];
                vec[contInterno] = vec[contInterno + 1];
                vec[contInterno + 1] = temporal;
            }
        }
    }
}

void imprimirNumeros(float vec[], int cant)
{
    int contador;
    printf("\nPosici%cn | Car%ccter\n", 162, 160);
    printf("-------------------\n");
    for (contador = 0; contador < cant; contador++) {
        printf("%8d | %.2f\n", contador, vec[contador]);
    }
    printf("\n");
}


int main() {
    int cantidad;
    printf("Ingrese el tamaño del vector de n%cmeros: ", 160);
    scanf("%d", &cantidad);

    while (cantidad <= 0) {
        printf("Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &cantidad);
    }

    float vector[cantidad];

    cargarNumeros(vector, cantidad);
    puts("El arreglo inicialmente: ");
    imprimirNumeros(vector, cantidad);
    printf("El arreglo despu%cs de ordenarlo: \n", 130);
    ordenarNumeros(vector, cantidad);
    imprimirNumeros(vector, cantidad);
    return 0;
}





EJERCICIO SIETE:
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
    printf("Ingrese el tamaño del vector de n%cmeros: ", 160);
    scanf("%d", &cantidad);

    while (cantidad <= 0 || cantidad > MAXIMO) {
        printf("Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &cantidad);
    }

    char vector[cantidad+1];
    cargarCadenas(vector, cantidad);
    imprimirCadenas(vector);
}

OPCIÓN 2 (CON MATRICES/BIDIMENSIONAL):
#include <stdio.h>
#define MAXIMO 100
#define MAXLONG 50  // longitud máxima por cadena

void cargarCadenas(char vec[][MAXLONG], int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Ingrese la cadena %d: ", i + 1);
        scanf("%s", vec[i]);
    }
}

void imprimirCadenas(char vec[][MAXLONG], int cant) {
    printf("\nCadenas ingresadas:\n");
    for (int i = 0; i < cant; i++) {
        printf("Cadena %d: %s\n", i + 1, vec[i]);
    }
}

int main() {
    int cantidad;

    printf("Ingrese la cantidad de cadenas (máximo %d): ", MAXIMO);
    scanf("%d", &cantidad);
    while (cantidad <= 0 || cantidad > MAXIMO) {
        printf("Ingrese un número válido (1-%d): ", MAXIMO);
        scanf("%d", &cantidad);
    }

    char vector[cantidad][MAXLONG];

    cargarCadenas(vector, cantidad);
    imprimirCadenas(vector, cantidad);

    return 0;
}


EJERCICIO OCHO:
(mini mejora en main tres.c)
#include <string.h>
#define MAXIMO 100

void cantidadCaracteresStrings(char vec[], char vec2[]){
    int tamStr = strlen(vec);
    int tamStr2 = strlen(vec2);

    printf("\nLa longitud del primer string es de %d\n", tamStr);
    printf("La longitud del segundo string es de %d\n\n", tamStr2);
}

void compararCadenas(char vec[], char vec2[]) {
    static char strMayor[MAXIMO];

    if (strlen(vec) < strlen(vec2)) {
        printf("El menor de los strings es: %s\n", vec);
    }
    else {
        if (strlen(vec) > strlen(vec2)) {
        printf("El menor de los strings es: %s\n", vec2);
        }
        else {
            if (strcmp(vec, vec2) < 0) {
            printf("El menor de los strings es: %s\n", vec);
            }
            else {
            printf("El menor de los strings es: %s\n", vec2);
            }
        }
    }


    if (strlen(vec) > strlen(strMayor)) {
        strcpy(strMayor, vec);
    }
    if (strlen(vec2) > strlen(strMayor)) {
        strcpy(strMayor, vec2);
    }

    printf("El string mayor de todos es: %s\n", strMayor);
}

int main() {
    char string1[MAXIMO], string2[MAXIMO];
    int opcion;

    do {
        printf("Ingrese el primer string para comparar: ");
        scanf("%s", string1);
        printf("Ingrese el segundo string: ");
        scanf("%s", string2);

        cantidadCaracteresStrings(string1, string2);
        compararCadenas(string1, string2);

        printf("\n\nDesea comparar otros strings? (1 = S%c | 0 = No): ", 160);
        scanf("%d", &opcion);
        printf("\n");
    } while (opcion != 0);

    return 0;
}



EJERCICIO NUEVE:
#define MATERIAS 13

void cargarNotas(int arrNota[MATERIAS], char arrCat[MATERIAS]){
    int contador;
    for (contador = 0; contador < MATERIAS; contador++){
        printf("Ingrese la nota de la materia %d: ", contador + 1);
        scanf("%d", &arrNota[contador]);
        if (arrNota[contador] >= 8 && arrNota[contador] <= 10){
            arrCat[contador] = 'S';
        }
        else if (arrNota[contador] >= 4 && arrNota[contador] <= 7){
            arrCat[contador] = 'A';
        }
        else if (arrNota[contador] >= 1 && arrNota[contador] <= 3){
            arrCat[contador] = 'R';
        }
        else {
            printf("Nota inválida. Ingrese un valor entre 1 y 10.\n");
            contador--;
        }
    }
}

void imprimirNotas(int arrNota[MATERIAS], char arrCat[MATERIAS]) {
    int contador;
    printf("\nNotas | Condici%cn\n", 162);
    printf("--------------------\n");
    for (contador = 0; contador < MATERIAS; contador++) {
        printf("%8d | %c\n", arrNota[contador], arrCat[contador]);
    }
    printf("\n");
}

int cantidadReprobadas(char arrCat[MATERIAS]){
    int contador, aplazos = 0;
    for (contador = 0; contador < MATERIAS; contador++) {
        if (arrCat[contador] == 'R'){
            aplazos++;
        }
    }
    return aplazos;
}

void probabilidadAplazo(int aplazos){
    if (aplazos >= 7){
        printf("Alta posibilidad de repetir.");
    }
    else{
        printf("Baja posibilidad de repetir.");
    }
}


int main() {
    int notas[MATERIAS], cantidad_reprobadas;
    char categoriaNotas[MATERIAS];

    cargarNotas(notas, categoriaNotas);
    imprimirNotas(notas, categoriaNotas);
    cantidad_reprobadas = cantidadReprobadas(categoriaNotas);
    probabilidadAplazo(cantidad_reprobadas);

    return 0;
}



EJERCICIO DIEZ: 
#include <stdio.h>
#define BANCOS 10

void imprimirPrecios(float compra[], float venta[]) {
    int contador;
    char *nombres[BANCOS] = {
        "BANCO GALICIA",
        "BANCO NACION",
        "BANK OF CHINA",
        "BANCO BBVA",
        "BANCO SUPERVIELLE",
        "BANCO DE CBA",
        "BANCO PATAGONIA",
        "BANCO SANTANDER",
        "BRUBANK",
        "HSBC BANK"
    };
    printf("Banco                               Compra      Venta\n");
    printf("-------------------------------------------------------------\n");
    for (contador = 0; contador < BANCOS; contador++) {
        printf("%-35s  %.3f     %.3f\n", nombres[contador], compra[contador], venta[contador]);
    }
}

void calcularPromedio(float compra[], float venta[], int tam) {
    float sumaCompra = 0.0, sumaVenta = 0.0;
    for (int i = 0; i < tam; i++) {
        sumaCompra += compra[i];
        sumaVenta += venta[i];
    }
    printf("\nPromedio Dólar Compra: %.3f\n", sumaCompra / tam);
    printf("Promedio Dólar Venta: %.3f\n", sumaVenta / tam);
}

int main() {
    float compra[BANCOS] = {923.000, 926.050, 919.500, 934.000, 925.000, 926.000, 930.000, 935.000, 920.000, 919.000};
    float venta[BANCOS] = {998.000, 965.950, 987.000, 999.000, 995.000, 966.000, 995.000, 995.000, 995.000, 994.000};

    imprimirPrecios(compra, venta);
    calcularPromedio(compra, venta, BANCOS);

    return 0;
}


EJERCICIO ONCE: 
#include <stdio.h>
#define MAXIMO 100

void ingresar(float arrIngr[MAXIMO], int *posicion){
    int hora, minuto;
    float total;
    if (*posicion >= MAXIMO) {
        printf("No se pueden agregar m%cs empleados.\n", 160);
        return;
    }
    do {
        printf("Ingrese la hora de ingreso (0-23): ");
        scanf("%d", &hora);
    } while (hora < 0 || hora > 23);

    do {
        printf("Ingrese los minutos de ingreso (0-59): ");
        scanf("%d", &minuto);
    } while (minuto < 0 || minuto > 59);

    total = hora + ((float)minuto/100);
    arrIngr[*posicion] = total;
}

void ingresarEmpleados(float arrIngr[MAXIMO], int cantidad){
    int contador;
    for (contador = 0; contador < cantidad; contador++){
        ingresar(arrIngr, &contador);
    }
}

void verIngreso(float arrIngr[MAXIMO], int posicion){
    int hora = (int)arrIngr[posicion];
    int minuto = (int)((arrIngr[posicion] - hora) * 100);
    printf("El empleado %d ingres%c a las %d : %d\n", 4000 + posicion, 162, hora, minuto);
}

void imprimirIngresos(float arrIngr[MAXIMO], int cantidad){
    int contador;
    if (cantidad == 0) {
        printf("No hay ingresos para mostrar.\n");
        imprimirIngresos(arrIngr, cantidad);
    }
    for (contador = 0; contador < cantidad; contador++){
        int hora = (int)arrIngr[contador];
        int minuto = (int)((arrIngr[contador] - hora) * 100) + 0.5;
        verIngreso(arrIngr, contador);
    }
}


void egresar(float arrEgr[MAXIMO], int *posicion){
    int hora, minuto;
    float total;
    if (*posicion >= MAXIMO) {
        printf("No se pueden agregar m%cs egresos.\n", 160);
        return;
    }
    do {
        printf("Ingrese la hora de salida (0-23): ");
        scanf("%d", &hora);
    } while (hora < 0 || hora > 23);

    do {
        printf("Ingrese los minutos de salida (0-59): ");
        scanf("%d", &minuto);
    } while (minuto < 0 || minuto > 59);

    total = hora + ((float)minuto/100);
    arrEgr[*posicion] = total;
}

void egresarEmpleados(float arrEgr[MAXIMO], int cantidad){
    int contador;
    for (contador = 0; contador < cantidad; contador++){
        egresar(arrEgr, &contador);
    }
}

void verEgreso(float arrEgr[MAXIMO], int posicion){
    int hora = (int)arrEgr[posicion];
    int minuto = (int)((arrEgr[posicion] - hora) * 100 + 0.5);
    printf("El empleado %d sali%c a las %d : %d\n", 4000 + posicion, 162, hora, minuto);
}

void imprimirEgresos(float arrEgr[MAXIMO], int cantidad){
    int contador;
    if (cantidad == 0) {
        printf("No hay salidas para mostrar.\n");
        return;
    }
    for (contador = 0; contador < cantidad; contador++){
        int hora = (int)arrEgr[contador];
        int minuto = (int)((arrEgr[contador] - hora) * 100);
        verEgreso(arrEgr, contador);
    }
}


void horasTrabajadasEmpleado(float arrIngr[MAXIMO], float arrEgr[MAXIMO], int posicion){
    int hsIng = (int)arrIngr[posicion];
    int minIng = (int)((arrIngr[posicion] - hsIng) * 100 + 0.5);
    int hsEgr = (int)arrEgr[posicion];
    int minEgr = (int)((arrEgr[posicion] - hsEgr) * 100 + 0.5);

    int minutosIngreso = (hsIng * 60) + minIng;
    int minutosEgreso = (hsEgr * 60) + minEgr;

    if (minutosIngreso > minutosEgreso) {
        minutosEgreso += 1440; // Sumar 24 horas en minutos al egreso
    }

    int minutosTotales = minutosEgreso - minutosIngreso;
    int hrTrabajadas = minutosTotales / 60;
    int minsTrabajados = minutosTotales % 60;

    printf("El empleado %d trabajo %d horas y %d minutos\n", 4000 + posicion, hrTrabajadas, minsTrabajados);
}

void horasTrabajadasEmpleados(float arrIngr[MAXIMO], float arrEgr[MAXIMO], int cantidad) {
    int contador;
    if (cantidad == 0) {
        printf("No hay horas trabajadas para mostrar.\n");
        return;
    }
    for (contador = 0; contador < cantidad; contador++) {
        horasTrabajadasEmpleado(arrIngr, arrEgr, contador);
    }
}


int main() {
    float Ingresos[MAXIMO], Egresos[MAXIMO];
    int opcion, cantidadEmpleados = 0;

    printf("Ingrese la cantidad de empleados (m%cx %d): ", 160, MAXIMO);
    scanf("%d", &cantidadEmpleados);
    if (cantidadEmpleados > MAXIMO || cantidadEmpleados < 1) {
        printf("Cantidad de empleados inv%clida.\n", 160);
        return 1;
    }

    do {
        printf("\n\n********** MEN%c PRINCIPAL **********\n", 233);
        printf("<1> Ingresar empleados\n");
        printf("<2> Mostrar todos los ingresos\n");
        printf("<3> Egresar empleados\n");
        printf("<4> Mostrar todos los egresos\n");
        printf("<5> Horas trabajadas de un empleado\n");
        printf("<6> Horas trabajadas de todos los empleados\n");
        printf("<7> Salir\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarEmpleados(Ingresos, cantidadEmpleados);
                break;
            case 2:
                imprimirIngresos(Ingresos, cantidadEmpleados);
                break;
            case 3:
                egresarEmpleados(Egresos, cantidadEmpleados);
                break;
            case 4:
                imprimirEgresos(Egresos, cantidadEmpleados);
                break;
            case 5: {
                int posicion;
                printf("Ingrese la posici%cn del empleado (0-%d): ", 162, cantidadEmpleados - 1);
                scanf("%d", &posicion);
                if (posicion >= 0 && posicion < cantidadEmpleados) {
                    horasTrabajadasEmpleado(Ingresos, Egresos, posicion);
                } else {
                    printf("Posici%cn inválida.\n", 160);
                }
                break;
            }
            case 6:
                horasTrabajadasEmpleados(Ingresos, Egresos, cantidadEmpleados);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn inv%clida.\n", 162, 160);
        }
    } while(opcion != 7);

    return 0;
}




EJERCICIO DOCE:
#define PRODUCTOS 10

void cargaPrecio(float precios[PRODUCTOS]){
    int contador;
    float precio;
    for (contador = 0; contador < PRODUCTOS; contador++){
        do {
            printf("Ingrse el precio del producto %d: ", contador + 1);
            scanf("%f", &precio);
            if (precio <= 0) {
                printf("El precio debe ser un n%cmero positivo.\n", 163);
            }
        } while (precio <= 0);
        precios[contador] = precio;
    }
}

void cargaPromo(float precios[PRODUCTOS], float promos[PRODUCTOS]){
    int contador;
    for (contador = 0; contador < PRODUCTOS; contador++){
        promos[contador] = precios[contador] - ((precios[contador] * 15) / 100);
    }
}

void muestraPrecios(float precios[PRODUCTOS], float promos[PRODUCTOS]){
    int contador;
    printf("PRODUCTO\t PRECIO\t\t PRECIO C/DESC\n");
    for (contador = 0; contador < PRODUCTOS; contador++){
        printf(" %d\t\t %.2f\t\t %.2f\n", contador+1, precios[contador], promos[contador]);
    }
}

int main(){
    float preciosLista[PRODUCTOS] = {0};
    float preciosPromo[PRODUCTOS] = {0};
    int opcion, contador;

    do {
        printf("****************************************\n");
        printf("*              BIENVENIDO              *\n");
        printf("****************************************\n");
        printf("<1> CARGAR PRECIOS\n");
        printf("<2> CARGAR PROMOCIONES\n");
        printf("<3> VER TODOS LOS PRECIOS\n");
        printf("<4> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);
        switch(opcion) {
        case 1:
            cargaPrecio(preciosLista);
            printf("\n\n");
            break;
        case 2:
            if(preciosLista[0] == 0){
                printf("Debe colocar los precios primero.\n\n\n");
            }
            else{
                cargaPromo(preciosLista, preciosPromo);
                printf("Las promociones han sido cargadas autom%cticamente.\n\n", 160);
            }
            break;
        case 3:
            if(preciosLista[0] == 0 || preciosPromo[0] == 0){
                printf("Debe colocar los precios o promociones primero.\n\n\n");
            }
            else{
            muestraPrecios(preciosLista, preciosPromo);
            printf("\n\n");
            }
            break;
        case 4:
            printf("Saliendo...\n\n");
            break;
        default:
            printf("Opci%cn inv%clida.\n\n", 162, 160);
        }
    } while(opcion != 4);
    return 0;
}
