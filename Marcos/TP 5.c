EJERCICIO 1:
int imprimirNaturales(int nro){
    if (nro == 0) {
    return 0;
    }
    else{
    imprimirNaturales(nro-1);
    printf("%d\n", nro);
    }
}
(Cambiar el orden de las sentencias)

int main(){
    int n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);

    printf("Los primeros %d números naturales son:\n", n);
    imprimirNaturales(n);

    return 0;
}



EJERCICIO 2:
int sumaNaturales(int nro){
    if (nro == 0) {
        return 0;
    }
    else{
        return nro + sumaNaturales(nro-1);
    }
}

int main(){
    int n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);

    int suma = sumaNaturales(n);

    printf("La suma de los primeros %d números naturales es: %d\n", n, suma);

    return 0;
}



EJERCICIO 3: 
void cargarNumeros(int vec[], int tam)
{
    int x;
    for (x = 0; x < tam; x++)
    {
        printf("Cargar n%cmero %d: ", 163, x + 1);
        scanf(" %d", &vec[x]);
    }
}

int buscarElemento (int arr[], int cant, int nro, int ind){
    if (ind >= cant){
        return -1;
    }
    if (arr[ind] == nro){
        return ind;
    }
    else{
        return buscarElemento(arr, cant, nro, ind+1);
    }
}

int main()
{
    int numeroABuscar, cantidad, indice = 0;

    printf("Ingrese el tamaño del vector de numeros: ");
    scanf("%d", &cantidad);

    while (cantidad <= 0){
        printf("Ingrese un n%cmero v%clido.", 163, 160);
        scanf("%i", &cantidad);
    }

    int numeros[cantidad];

    cargarNumeros(numeros, cantidad);

    printf("%cQu%c n%cmero desea buscar?: ", 168, 163);
    scanf("%d", &numeroABuscar);

    int pos = buscarElemento(numeros, cantidad, numeroABuscar, indice);

    if (pos == -1) {
        printf("NO SE ENCONTRO EL NUMERO %d.\n", numeroABuscar);
    } else {
        printf("El elemento est%c en la posici%cn %d\n", 160, 162, pos);
    }

    return 0;
}




EJERCICIO 4:
(podria hacerse otra version usando strlwr):
#include <string.h>
#define MAXIMO 100

int compararStrings(char str1[], char str2[], int posicion, int cant){
    if (posicion == cant){
        return 1;
    }
    if (str1[posicion] != str2[posicion]){
        return 0;
    }
     return compararStrings(str1, str2, posicion+1, cant);
}

void verificarStrings(char str1[], char str2[], int cant){
    do{
        printf("Ingrese la primer cadena a comparar: ");
        scanf(" %[^\n]", str1);
        printf("Ingrese la segunda cadena: ");
        scanf(" %[^\n]", str2);
        if (strlen(str1) != strlen(str2)){
            printf("Debe ingresar cadenas de misma longitud. Intente de nuevo.\n");
        }
        if (strlen(str1) != cant || strlen(str2) != cant) {
            printf("Debe ingresar cadenas de longitud %d. Intente de nuevo.\n", cant);
        }
    } while (strlen(str1) != strlen(str2) || strlen(str1) != cant || strlen(str2) != cant);
}


Int main(){
    int opcion, posicion = 0, cantidad = 0;
    char string1[MAXIMO], string2[MAXIMO];
    do {
        printf("****************************************\n");
        printf("*               STRINGS                *\n");
        printf("****************************************\n");
        printf("<1> CARGAR STRINGS\n");
        printf("<2> COMPARAR STRINGS\n");
        printf("<3> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la cantidad que tendr%cn las cadenas (deben ser iguales): ", 160);
                scanf("%d", &cantidad);
                verificarStrings(string1, string2, cantidad);
                puts("\n\n");
                break;
            case 2:
                if (cantidad == 0) {
                    printf("Primero debe cargar las cadenas.");
                    puts("\n\n");
                } else {
                    int iguales = compararStrings(string1, string2, posicion, cantidad);
                    if(iguales){
                        printf("Los strings son IGUALES.\n");
                    }
                    else{
                        printf("Los strings son DIFERENTES.\n");
                    }
                    printf("RETORNA (%d)\n\n", iguales);
                }
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.", 163, 160);
                puts("\n\n");
        }
    } while (opcion != 3);
}


EJERCICIO 5:
(para el efecto de redondeo, probar con:
1.55+2.511+3.517+4.511|4519
La función podría hacerse con un puntero de posiciones. Solución esa abajo)
#define MAXIMO 100

void cargarNumeros(float vec[], int cant) {
    int cont;
    printf("Carga de un vector de enteros de tamaño %d.\n", cant);
    for (cont = 0; cont < cant; cont++) {
        printf("Cargar número %d: ", cont + 1);
        scanf("%f", &vec[cont]);
    }
}

float sumarNumeros(float vec[], int cant){
    if (cant == 0){
        return 0;
    }
    else{
        return vec[cant-1] + sumarNumeros(vec, cant-1);
    }
}


main(){

    int opcion, cantidad = 0;
    float numeros[MAXIMO];
    do {
        printf("****************************************\n");
        printf("*               STRINGS                *\n");
        printf("****************************************\n");
        printf("<1> INICIALIZAR ARREGLO\n");
        printf("<2> SUMAR TODOS LOS ELEMENTOS\n");
        printf("<3> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el tama%co del vector de n%cmeros: ", 164, 163);
                scanf("%d", &cantidad);

                while (cantidad <= 0) {
                        printf("Ingrese un n%cmero v%clido: ", 163, 160);
                scanf("%d", &cantidad);
                }

                cargarNumeros(numeros, cantidad);
                puts("\n\n");
                break;
            case 2:
                if (cantidad == 0) {
                    printf("Primero debe cargar el arreglo.");
                }
                else{
                    printf("la suma de todos los n%cmeros del arreglo es: \n", 163);
                    printf("%.4g", sumarNumeros(numeros, cantidad));
                }
                puts("\n\n");
                break;
            case 3:
                printf("Saliendo...\n");
                puts("\n\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.", 163, 160);
                puts("\n\n");
        }
    } while (opcion != 3);
}



SOLUCIÓN 2 (actualizando cada vez las posiciones libres):
void agregarNumeros(float vec[], int *libre, int cant) {
    int numAAgregar, contador;

    printf("¿Cuántos números desea agregar?\n");
    scanf("%d", &numAAgregar);

    if (*libre + numAAgregar > cant) {
        printf("ERROR: No hay espacio para agregar otros %d números.\n", numAAgregar);
        return;
    }

    for (contador = 0; contador < numAAgregar; contador++) {
        printf("Ingrese el número %d: ", *libre + 1);
        scanf("%f", &vec[*libre]);
        (*libre)++;
    }
}

int main() {
    int opcion, cantidad = 0;
    float numeros[MAXIMO];
    do {
        printf("****************************************\n");
        printf("*               STRINGS                *\n");
        printf("****************************************\n");
        printf("<1> INICIALIZAR ARREGLO\n");
        printf("<2> AGREGAR NÚMEROS AL ARREGLO\n");
        printf("<3> SUMAR TODOS LOS ELEMENTOS\n");
        printf("<4> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el tamaño del vector de números: ");
                scanf("%d", &cantidad);

                while (cantidad <= 0) {
                    printf("Ingrese un número válido: ");
                    scanf("%d", &cantidad);
                }

                cargarNumeros(numeros, cantidad);
                puts("\n\n");
                break;

            case 2:
                if (cantidad == 0) {
                    printf("Primero debe inicializar el arreglo.\n");
                } else {
                    agregarNumeros(numeros, &cantidad, MAXIMO);
                }
                puts("\n\n");
                break;

            case 3:
                if (cantidad == 0) {
                    printf("Primero debe cargar el arreglo.\n");
                } else {
                    printf("La suma de todos los números del arreglo es: \n");
                    printf("%.4g", sumarNumeros(numeros, cantidad));
                }
                puts("\n\n");
                break;

            case 4:
                printf("Saliendo...\n");
                puts("\n\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                puts("\n\n");
        }
    } while (opcion != 4);

    return 0;
}



EJERCICIO 6:
#define MAXIMO 101

void cargarString(char str[], int *cant) {
    printf("Ingrese la longitud del string: ");
    scanf("%d", cant);

    while (*cant <= 0 || *cant >= MAXIMO) {
        printf("Ingrese un n%cmero v%clido (entre 1 y %d): ", 163, 160, MAXIMO-1);
        scanf("%d", cant);
    }

    printf("Ingrese el string: ");
    scanf(" %[a-zA-Z ]", str);
}

void imprimirStringAlReves(char str[], int posicion) {
    if (posicion < 0) {
        return;
    } else {
        printf("%c", str[posicion]);
        imprimirStringAlReves(str, posicion - 1);
    }
}



Int main() {
    char string1[MAXIMO];
    int opcion, cantidad = 0;

    do {
        printf("****************************************\n");
        printf("*               STRINGS                *\n");
        printf("****************************************\n");
        printf("<1> CARGAR STRING\n");
        printf("<2> IMPRIMIR STRING INVERTIDO\n");
        printf("<3> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                cargarString(string1, &cantidad);
                puts("\n\n");
                break;
            case 2:
                if(cantidad == 0){
                    printf("Debe cargar el string primero.");
                }
                else{
                    printf("El string invertido se ve como: \n");
                    imprimirStringAlReves(string1, cantidad-1);
                }
                puts("\n\n");
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.", 163, 160);
                puts("\n\n");
        }
    } while (opcion != 3);
}



EJERCICIO 7:
#define MAXIMO 100

void longitudArreglo(int *cant){
    printf("Ingrese el tamaño del vector de n%cmeros: ", 160);
    scanf("%d", cant);
    while (*cant <= 0) {
        printf("Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", cant);
    }
}

void cargarNumeros(int vec[], int cant) {
    int cont;
    for (cont = 0; cont < cant; cont++) {
        printf("Cargar número %d: ", cont + 1);
        scanf("%d", &vec[cont]);
    }
}

int elementoMayor(int vec[], int posicion, int cant) {
    if (posicion == cant - 1) {
        return vec[posicion];
    }
    int mayor = elementoMayor(vec, posicion + 1, cant);
    if (vec[posicion] > mayor) {
        return vec[posicion];
    } else {
        return mayor;
    }

    /* o sino: int mayorRest = elementoMayor(vec, posicion + 1, cant);
    return (vec[posicion] > mayorRest) ? vec[posicion] : mayorRest; */
}



int main() {
    int cantidad, posicion = 0;
    longitudArreglo(&cantidad);
    int numeros[cantidad];
    cargarNumeros(numeros, cantidad);

    printf("El mayor en el arreglo es el: %d", elementoMayor(numeros, posicion, cantidad));
}



EJERCICIO 8:
#include <string.h>
#define MAX 50

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
    char apellido[30];
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
    printf("Ingrese el apellido: ");
    scanf(" %[^\n]", empleado->apellido);
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
    printf(" N%cmero de tel%cfono: ", 163, 130);
    scanf("%lld", &empleado->direccion.nroTelefono);
}

void ingresarEmpleados(Empleado emp[], int *libre) {
    int empleadosAReg, contador;
    printf("%cCu%cntos empleados desea ingresar? ", 168, 160);
    scanf("%d", &empleadosAReg);

    if (*libre + empleadosAReg > MAX) {
        printf("ERROR: No hay espacio para agregar %d empleados.\n", empleadosAReg);
        return;
    }

    for (contador = 0; contador < empleadosAReg; contador++){
        printf("\nIngrese datos del empleado %d:\n", *libre + 1);
        ingresarEmpleado(&emp[*libre]);
        (*libre)++;
    }
}

void imprimirEmpleado(Empleado empleado) {
    printf("\nNombre: %s\n", empleado.nombre);
    printf("Apellido: %s\n", empleado.apellido);
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

void imprimirEmpleados(Empleado emp[], int cant){
    int contador;
    if (cant == 0) {
        printf("Primero debe cargar empleados para usar esta funci%cn.\n\n", 162);
    } Else {
    printf("\nEMPLEADOS CARGADOS:\n");
    for (contador = 0; contador < cant; contador++) {
        printf("\n\nEMPLEADO N%CMERO %d", 233, contador+1);
        imprimirEmpleado(emp[contador]); }
    }
}

void buscarDocumento(Empleado emp[], int cant) {
    int contador, numeroDoc;
    char tipoDoc[10];
    printf("Ingrese tipo de documento: ");
    scanf(" %[^\n]", tipoDoc);
    printf("Ingrese n%cmero de documento: ", 163);
    scanf("%d", &numeroDoc);

    for (int contador = 0; contador < cant; contador++) {
        if (strcmp(emp[contador].doc.tipo, tipoDoc) == 0 && emp[contador].doc.numero == numeroDoc) {
            imprimirEmpleado(emp[contador]);
            return;
        }
    }
    printf("Empleado con documento %s %d no encontrado.\n", tipoDoc, numeroDoc);
}

void ordenarEmpleadosPorNombre(Empleado emp[], int cant) {
    if (cant == 0) {
        printf("Primero debe cargar empleados para usar esta funci%cn.\n\n", 162);
    } Else {
    int contExterno, contInterno;
    Empleado temporal;

    for (contExterno = 0; contExterno < cant-1; contExterno++) {
        for (contInterno = 0; contInterno < cant-1 - contExterno; contInterno++) {
            if (strcmp(emp[contInterno].nombre, emp[contInterno + 1].nombre) > 0) {
                temporal = emp[contInterno];
                emp[contInterno] = emp[contInterno + 1];
                emp[contInterno + 1] = temporal;
            }
        }
    }
}
}

void imprimirDeAZ(Empleado emp[], int cant, int posicion){
    if (posicion >= cant){
        return;
    }

    printf("%s\n", emp[posicion].nombre);
    imprimirDeAZ(emp, cant, posicion + 1);
}

void imprimirDeZA(Empleado emp[], int cant, int posicion){
    if (posicion >= cant){
        return;
    }
    imprimirDeZA(emp, cant, posicion + 1);
    printf("%s\n", emp[posicion].nombre);
}

void buscarPorApellido(Empleado emp[], int cant, int posicion, char apellidoBusc[], int *contApell){
    if (posicion >= cant){
        return;
    }
    if (strcmp(emp[posicion].apellido, apellidoBusc) == 0){
        imprimirEmpleado(emp[posicion]);
        (*contApell)++;
    }
    buscarPorApellido(emp, cant, posicion+1, apellidoBusc, contApell);
}

void copiarArreglo(Empleado original[], Empleado destino[], int cant) {
    int contador;
    for (contador = 0; contador < cant; contador++) {
        destino[contador] = original[contador];
    }
}

int main() {
    Empleado empleados[MAX];
    Empleado copiaTemp[MAX];
    int agregados = 0, encontradosApell = 0;
    int opcion;
    char apellidoBusq[30];

    do {
        printf("****************************************\n");
        printf("*        PROGRAMA DE EMPLEADOS         *\n");
        printf("****************************************\n");
        printf("<1> INGRESAR EMPLEADOS\n");
        printf("<2> BUSCAR EMPLEADO POR DOCUMENTO\n");
        printf("<3> BUSCAR EMPLEADOS POR APELLIDO\n");
        printf("<4> VER TODOS LOS EMPLEADOS\n");
        printf("<5> IMPRIMIR NOMBRES (A-Z)\n");
        printf("<6> IMPRIMIR NOMBRES (Z-A)\n");
        printf("<7> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarEmpleados(empleados, &agregados);
                printf("\n\n");
                break;
            case 2:
                buscarDocumento(empleados, agregados);
                printf("\n\n");
                break;
            case 3:
                printf("Ingrese el apellido para buscar empleados: ");
                scanf(" %[^\n]", apellidoBusq);
                encontradosApell = 0;
                buscarPorApellido(empleados, agregados, 0, apellidoBusq, &encontradosApell);
                if (encontradosApell == 0) {
                    printf("No se encontraron empleados con el apellido %c %s %c.\n", 34, apellidoBusq, 34);
                }
                printf("\n\n");
                break;
            case 4:
                imprimirEmpleados(empleados, agregados);
                printf("\n\n");
                break;
            case 5:
                copiarArreglo(empleados, copiaTemp, agregados);
                ordenarEmpleadosPorNombre(copiaTemp, agregados);
                imprimirDeAZ(copiaTemp, agregados, 0);
                printf("\n\n");
                break;
            case 6:
                copiarArreglo(empleados, copiaTemp, agregados);
                ordenarEmpleadosPorNombre(copiaTemp, agregados);
                imprimirDeZA(copiaTemp, agregados, 0);
                printf("\n\n");
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.", 163, 160);
                printf("\n\n");
                break;
        }
    } while (opcion != 7);
    return 0;
}



