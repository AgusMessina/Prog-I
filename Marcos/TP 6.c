EJERCICIO 1:
int main() {
    int *intPtr = (int *)malloc(sizeof(int));
    char *charPtr = (char *)malloc(sizeof(char));
    float *floatPtr = (float *)malloc(sizeof(float));
    int nro, contador;
    *intPtr = 2;
    *charPtr = 'M';
    *floatPtr = 2;

    printf("Ingrese la cantidad de enteros que desea almacenar: ");
    scanf("%d", &nro);

    int *arrayPtr = (int *)malloc(nro * sizeof(int));

    if (intPtr == NULL || charPtr == NULL || floatPtr == NULL || arrayPtr == NULL) {
        printf("No hay memoria suficiente.\n");
        exit(1);
    }

    printf("Puntero a entero: valor = %d, dirección = %p, tamaño = %d bytes\n", *intPtr, intPtr, sizeof(int));
    printf("Puntero a char: valor = %c, dirección = %p, tamaño = %d bytes\n", *charPtr, charPtr, sizeof(char));
    printf("Puntero a float: valor = %f, dirección = %p, tamaño = %d bytes\n", *floatPtr, floatPtr, sizeof(float));

    for (contador = 0; contador < nro; contador++) {
    arrayPtr[contador] = contador + 1;
    printf("Array[%d]:\nValor: %d\nDireccion: %p\nTamaño: %d bytes\n\n",
            contador, arrayPtr[contador], &arrayPtr[contador], sizeof(int));
    }

   free(intPtr);
    free(charPtr);
    free(floatPtr);
    free(arrayPtr);

    return 0;
}



EJERCICIO 2:
int main() {
    int *ptr_array;
    int nro, contador;

    printf("Ingrese la cantidad de enteros que desea almacenar: ");
    scanf("%d", &nro);
   
    if (nro <= 0) {
        printf("Cantidad inv%clida.", 160);
        return 1;
    }

    ptr_array = (int*)malloc(nro * sizeof(int));

    if (ptr_array == NULL) {
        printf("No hay memoria suficiente.\n");
        exit(1);
    }

    for (contador = 0; contador < nro; contador++) {
        ptr_array[contador] = contador + 1;
    }

    printf("Valores almacenados:\n");
    for (contador = 0; contador < nro; contador++) {
        printf("arreglo[%d] = %d\n", contador, ptr_array[contador]);
    }

    free(ptr_array);

    return 0;
}




EJERCICIO 3:
typedef struct {
    char a;
    int b;
} Info;

int main() {
    Info *puntero_info;
    puntero_info = (Info*)malloc(sizeof(Info));

    if (puntero_info == NULL) {
        printf("No hay memoria suficiente.\n");
        exit(1);
    }

    puntero_info->a = 'M';
    puntero_info->b = 1612;

    printf("Valores en los campos:\n");
    printf("a: %c\n", puntero_info->a);
    printf("b: %d\n", puntero_info->b);

    free(puntero_info);
    return 0;
}




EJERCICIO 4:
typedef struct {
    char nombre[20];
    char apellido[20];
    int edad;
} persona;


void cargarPersona(persona *p) {
    printf("Ingrese nombre: ");
    scanf("%[^\n]", p->nombre);
    printf("Ingrese apellido: ");
    scanf(" %[^\n]", p->apellido);
    printf("Ingrese edad: ");
    scanf("%d", &p->edad);
}

void mostrarPersona(persona *p) {
    printf("Nombre: %s \nApellido: %s \nEdad: %d\n", p->nombre, p->apellido, p->edad);
}

void cargarPersonas(persona *ps, int nro) {
    for (int contador = 0; contador < nro; contador++) {
        printf("Cargando persona %d\n", contador + 1);
        cargarPersona(&ps[contador]);
    }
}

void mostrarPersonas(persona *ps, int nro) {
    for (int contador = 0; contador < nro; contador++) {
        printf("Persona %d: ", contador + 1);
        mostrarPersona(&personas[contador]);
    }
}

int main() {
    int numero;
    persona *personas;

    do {
        printf("Ingrese la cantidad de personas a almacenar (max 10): ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 10);

    personas = (persona *)malloc(numero * sizeof(persona));
    if (personas == NULL) {
        printf("No hay suficiente memoria.\n");
        exit(1);
    }

    cargarPersonas(personas, numero);

    printf("\nPersonas cargadas:\n");
    mostrarPersonas(personas, numero);

    free(personas);
    return 0;
}





EJERCICIO 5:
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[20];
    char apellido[20];
    char sexo;
    Fecha fechaNacimiento;
    float peso;
    float altura;
} Salud;

Salud *pedirMemoriaSalud() {
    Salud *ptrSalud = (Salud *)malloc(sizeof(Salud));
    if (ptrSalud == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    return ptrSalud;
}

void cargarDatosSalud(Salud *regSal) {
    printf("Ingrese su nombre: ");
    scanf("%s", regSal->nombre);
    printf("Ingrese su apellido: ");
    scanf("%s", regSal->apellido);
    printf("Ingrese si es masculino (M) o femenino (F): ");
    scanf(" %c", &regSal->sexo);
    printf("Ingrese la fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &regSal->fechaNacimiento.dia, &regSal->fechaNacimiento.mes, &regSal->fechaNacimiento.anio);
    printf("Ingrese el peso (en Kg): ");
    scanf("%f", &regSal->peso);
    printf("Ingrese la altura (en metros): ");
    scanf("%f", &regSal->altura);
}

void mostrarDatosSalud(Salud *regSal) {
    printf("\nRegistro de salud:\n");
    printf("--------------------\n");
    printf("Nombre: %s\n", regSal->nombre);
    printf("Apellido: %s\n", regSal->apellido);
    printf("Género: %c\n", regSal->sexo);
    printf("Fecha de nacimiento: %d-%d-%d\n", regSal->fechaNacimiento.dia, regSal->fechaNacimiento.mes, regSal->fechaNacimiento.anio);
    printf("Peso: %.2f\n", regSal->peso);
    printf("Altura: %.2f\n", regSal->altura);
}

int main() {
    int n, i;

    Salud *saludPtr = pedirMemoriaSalud();

    cargarDatosSalud(saludPtr);

    mostrarDatosSalud(saludPtr);

    free(saludPtr);

    Salud *saludArray = (Salud *)malloc(50000 * sizeof(Salud));
    if (saludArray == NULL) {
        printf("Error: No se pudo asignar memoria para las 50,000 estructuras.\n");
        exit(1);
    }

    printf("\n¿Cuántos registros de salud desea ingresar (hasta 50,000)? ");
    scanf("%d", &n);
    if (n > 50000 || n <= 0) {
        printf("Número no válido. Fin del programa.\n");
        free(saludArray);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("\nRegistro #%d\n", i + 1);
        cargarDatosSalud(&saludArray[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nMostrando registro #%d\n", i + 1);
        mostrarDatosSalud(&saludArray[i]);
    }

    free(saludArray);

    return 0;
}



EJERCICIO 6:
(ver versión nueva con funcion de liberar todos los espacios en ATRFINAL.c)
typedef struct {
    int dia, mes, anio;
} Fecha;

typedef struct {
    char nom[30];
    int TipoDoc;
    int NroDoc;
    int Hijos;
    Fecha Nacim;
} Empleado;

Empleado* arr[10];


void ingresarInformacionEmpleado(int index) {
    arr[index] = (Empleado*)malloc(sizeof(Empleado));
    
    if (arr[index] == NULL) {
        printf("Error: No se pudo asignar memoria para empleado %d.
", index + 1);
        exit(1);
    }

    printf("Ingrese el nombre del empleado: ");
    scanf(" %[^\n]", arr[index]->nom);

    printf("Ingrese el tipo de documento (1=DNI, 2=PAS, 3=CF, 4=CIPE): ");
    scanf("%d", &arr[index]->TipoDoc);

    printf("Ingrese el numero de documento: ");
    scanf("%d", &arr[index]->NroDoc);

    printf("Ingrese la cantidad de hijos: ");
    scanf("%d", &arr[index]->Hijos);

    printf("Ingrese la fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &arr[index]->Nacim.dia, &arr[index]->Nacim.mes, &arr[index]->Nacim.anio);
}

void mostrarInformacionEmpleados(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("\nEmpleado %d:\n", i + 1);
        printf("Nombre: %s\n", arr[i]->nom);
        printf("Tipo de Documento: %d\n", arr[i]->TipoDoc);
        printf("Numero de Documento: %d\n", arr[i]->NroDoc);
        printf("Cantidad de Hijos: %d\n", arr[i]->Hijos);
        printf("Fecha de Nacimiento: %d-%d-%d\n", arr[i]->Nacim.dia, arr[i]->Nacim.mes, arr[i]->Nacim.anio);
    }
}

void listarEmpleadosMayoresDe40(int cantidad) {
    int anioActual = 2024;
    for (int i = 0; i < cantidad; i++) {
        int edad = anioActual - arr[i]->Nacim.anio;
        if (arr[i]->Nacim.mes > 10 || (arr[i]->Nacim.mes == 10 && arr[i]->Nacim.dia > 15)) {
            edad--;
        }
        if (edad >= 40) {
            printf("Empleado mayor de 40: %s\n", arr[i]->nom);
        }
    }
}

int contarEmpleadosSinHijos(int cantidad) {
    int contador = 0;
    for (int i = 0; i < cantidad; i++) {
        if (arr[i]->Hijos == 0) {
            contador++;
        }
    }
    return contador;
}


int main() {
    int opcion, cantidadEmpleados = 0;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ingresar informacion de empleados\n");
        printf("2. Mostrar informacion de empleados\n");
        printf("3. Listar empleados mayores de 40 años\n");
        printf("4. Contar empleados sin hijos\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cantidadEmpleados < 10) {
                    ingresarInformacionEmpleado(cantidadEmpleados);
                    cantidadEmpleados++;
                } else {
                    printf("No se pueden agregar mas empleados.\n");
                }
                break;
            case 2:
                mostrarInformacionEmpleados(cantidadEmpleados);
                break;
            case 3:
                listarEmpleadosMayoresDe40(cantidadEmpleados);
                break;
            case 4:
                printf("Cantidad de empleados sin hijos: %d\n", contarEmpleadosSinHijos(cantidadEmpleados));
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 5);

    for (int i = 0; i < cantidadEmpleados; i++) {
        free(arr[i]);
    }

    return 0;
}




