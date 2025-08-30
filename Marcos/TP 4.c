EJERCICIO 1:
struct parte{
    int numero;
    char nombre[25];
    };

    typedef struct parte Parte;

    Parte a;
    Parte b[10];

    printf("Ingrese el n%cmero de parte: ", 163);
    scanf("%d", &a.numero);
    printf("Ingrese el nombre de la parte:");
    scanf("%s", a.nombre);

    b[3] = a;
    b[3].numero = a.numero;
    strcpy(b[3].nombre, a.nombre);
    printf("Elemento 3 del arreglo b:\n");
    printf("Número de parte: %d\n", b[3].numero);
    printf("Nombre de parte: %s\n", b[3].nombre);


EJERCICIO 2:
struct rectangulo{
        float base;
        float altura;
    };

    struct triangulo{
        float base;
        float altura;
    };

    struct trapecio{
        float lado1;
        float lado2;
        float altura;
    };

    struct coordenadas{
        float x;
        float y;
    };

    struct direccion{
        char callenumero[];
        char localidad[];
        int codigoPostal;
        int nroTelefono;
    };


    struct Fecha {
    int dia;
    int mes;
    int anio;
    };

    struct Documento {
        char tipo[10];   // Ejemplo: "DNI", "Pasaporte"
        int numero;
    };

    struct Materia {
        char nombre[50];
        struct Fecha fechaRegularizacion;
        struct Fecha fechaAprobacion;
    };

    // Estructura para el alumno
    struct Alumno {
        char nombre[30];
        int numeroRegistro; 
        struct Documento documento;
        struct Direccion direccion;
        struct Materia materias[10]; 
    };

    struct empleado {
        char nombre[30];
        struct Documento documento;
        struct Fecha FechaNacimiento;
        char estadoCivil[15];
        int cantidadHijos;
        char sexo;
    };


    struct proyector{
        char marca[];
        char color[];
        int controlRemoto;
    };

    struct aula{
        int nroIdentificacion;
        char ubicacion[20];
        char tipo[20];
        int cantidadMesas;
        int cantidadSillas;
        int cantidadPizarras;
        struct proyector Proyector;
    };




EJERCICIO 3:
#include <conio.h>

typedef struct proyector{
    char marca[30];
    char color[30];
    int controlRemoto;
} Proyector;

typedef struct aula{
    int nroIdentificacion;
    char ubicacion[20];
    char tipo[20];
    int cantidadMesas;
    int cantidadSillas;
    int cantidadPizarras;
    Proyector proyector;
} Aula;


void ingresarAula(Aula *aula){
    printf("Ingrese el n%cmero de identificaci%cn: ", 163, 162);
    scanf("%i", &aula->nroIdentificacion);
    getchar();
    printf("Ingrese la ubicaci%cn: ", 162);
    scanf("%[^\n]", aula->ubicacion);
    printf("Ingrese el tipo de aula (Lab, Conf, Teor%ca, Pr%cctica): ", 161, 160);
    scanf(" %s", aula->tipo);
    printf("Ingrese la cantidad de mesas: ");
    scanf("%i", &aula->cantidadMesas);
    printf("Ingrese la cantidad de sillas: ");
    scanf("%i", &aula->cantidadSillas);
    printf("Ingrese la cantidad de pizarras: ");
    scanf("%i", &aula->cantidadPizarras);
    printf("Ingrese la marca del proyector: ");
    scanf("%s", aula->proyector.marca);
    printf("Ingrese el color del proyector: ");
    scanf(" %[^\n]", aula->proyector.color);
    printf("¿Tiene control remoto? (1 = si | 0 = no): ");
    scanf("%d", &aula->proyector.controlRemoto);
}

void imprimirAula(Aula aula){
    printf("\nDatos del Aula:\n");
    printf("N%cmero de Identificaci%cn: %d\n", 163, 162, aula.nroIdentificacion);
    printf("Ubicaci%cn (bloque): %s\n", 162, aula.ubicacion);
    printf("Tipo de Aula: %s\n", aula.tipo);
    printf("Cantidad de Mesas: %d\n", aula.cantidadMesas);
    printf("Cantidad de Sillas: %d\n", aula.cantidadSillas);
    printf("Cantidad de Pizarras: %d\n", aula.cantidadPizarras);
    printf("Proyector Marca: %s\n", aula.proyector.marca);
    printf("Proyector Color: %s\n", aula.proyector.color);
    printf("¿Tiene control remoto?: %s\n", aula.proyector.controlRemoto ? "Sí" : "No");
}


main()
{
    Aula aula;

    ingresarAula(&aula);
    imprimirAula(aula);

    return 0;
}



EJERCICIO 4:
#include<stdio.h>
#include <conio.h>

typedef struct{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct{
    char nombre[20];
    char apellido[20];
    char sexo;
    Fecha fechaNacimiento;
    float peso;
    float altura;
} Salud;


void ingresarRegistroSalud(Salud *regSal){

    printf("Ingrese su nombre: ");
    scanf("%[^\n0-9]", regSal->nombre);
    getchar();
    printf("Ingrese su apellido: ");
    scanf("%[^\n0-9]", regSal->apellido);
    getchar();
    printf("Ingrese si es masculino (M) o femenino (F): ");
    scanf("%c", &regSal->sexo);

    do {
        printf("Ingrese la fecha de nacimiento (dd-mm-aaaa): ");
        scanf("%d%*c%d%*c%d", &regSal->fechaNacimiento.dia, &regSal->fechaNacimiento.mes, &regSal->fechaNacimiento.anio);

        if (regSal->fechaNacimiento.dia < 1 || regSal->fechaNacimiento.dia > 31 ||
            regSal->fechaNacimiento.mes < 1 || regSal->fechaNacimiento.mes > 12 ||
            regSal->fechaNacimiento.anio <= 0) {
            printf("Fecha err%cnea. Ingrese de nuevo.\n", 162);
        }
    } while (regSal->fechaNacimiento.dia < 1 || regSal->fechaNacimiento.dia > 31 ||
             regSal->fechaNacimiento.mes < 1 || regSal->fechaNacimiento.mes > 12 ||
             regSal->fechaNacimiento.anio <= 0);

     do {
        printf("Ingrese el peso (en Kg): ");
        scanf("%f", &regSal->peso);
        if (regSal->peso <= 0 || regSal->peso >= 700) {
            printf("Error: Peso no v%clido. Ingrese de nuevo.\n", 160);
        }
    } while (regSal->peso <= 0 || regSal->peso >= 700);

    do {
        printf("Ingrese la altura (en metros): ");
        scanf("%f", &regSal->altura);
        if (regSal->altura <= 0 || regSal->altura >= 3.00) {
            printf("Error: Altura no v%clida. Ingrese de nuevo.\n", 160);
        }
    } while (regSal->altura <= 0 || regSal->altura >= 3.00);
}


void mostrarRegistroSalud(Salud regSal){
    printf("\nRegistro de salud:\n");
    printf("--------------------\n");
    printf("Nombre: %s\n", regSal.nombre);
    printf("Apellido: %s\n", regSal.apellido);
    printf("G%cnero: %c\n", 130, regSal.sexo);
    printf("Fecha de nacimiento: %d-%d-%d\n", regSal.fechaNacimiento.dia, regSal.fechaNacimiento.mes, regSal.fechaNacimiento.anio);
    printf("Peso: %.2f\n", regSal.peso);
    printf("Altura: %.2f\n", regSal.altura);
}

int calcularEdad(Salud regSal){
    Fecha fechaActual;
    do {
        printf("Ingrese la fecha de actual (dd-mm-aaaa): ");
        scanf("%d%*c%d%*c%d", &fechaActual.dia, &fechaActual.mes, &fechaActual.anio);

        if (fechaActual.dia < 1 || fechaActual.dia > 31 ||
            fechaActual.mes < 1 || fechaActual.mes > 12 ||
            fechaActual.anio <= 0) {
            printf("Fecha err%cnea. Ingrese de nuevo.\n", 162);
        }
    } while (fechaActual.dia < 1 || fechaActual.dia > 31 ||
            fechaActual.mes < 1 || fechaActual.mes > 12 ||
            fechaActual.anio <= 0);

    int edad = fechaActual.anio - regSal.fechaNacimiento.anio;
    if(fechaActual.mes < regSal.fechaNacimiento.mes || (fechaActual.mes == regSal.fechaNacimiento.mes && fechaActual.dia < regSal.fechaNacimiento.dia)){
        edad--;
    }
    return edad;
}

void calcularImc(Salud regSal){
    float imc;
    imc = regSal.peso / (regSal.altura*regSal.altura);

    if (imc < 18.5) {
            printf("Bajo peso.\n");
    }
    else {
        if (imc >= 18.5 && imc < 25) {
            printf("Peso normal.\n");
        }
        else {
            if (imc >= 25 && imc < 30) {
                    printf("Sobrepeso.\n");
            }
            else{
                if (imc >= 30){
                        printf("Obeso.\n");
                }
            }
        }
    }
    printf("Su Masa Corporal es: %.2f", imc);
}

int main()
{
    Salud salud1;
    ingresarRegistroSalud(&salud1);
    mostrarRegistroSalud(salud1);
    printf("\n\nSu edad es %d a%cos.\n", calcularEdad(salud1), 164);
    calcularImc(salud1);
    return 0;
}



EJERCICIO 5:
typedef struct proyector{
    char marca[30];
    char color[30];
    int controlRemoto;
} Proyector;

typedef struct aula{
    int nroIdentificacion;
    char ubicacion[20];
    char tipo[20];
    int cantidadMesas;
    int cantidadSillas;
    int cantidadPizarras;
    Proyector proyector;
} Aula;


void ingresarAula(Aula *aula){
    printf("Ingrese el n%cmero de identificaci%cn: ", 163, 162);
    scanf("%i", &aula->nroIdentificacion);
    getchar();
    printf("Ingrese la ubicaci%cn: ", 162);
    scanf("%[^\n]", aula->ubicacion);
    printf("Ingrese el tipo de aula (Lab, Conf, Teor%ca, Pr%cctica): ", 161, 160);
    scanf(" %[^\n]", aula->tipo);
    printf("Ingrese la cantidad de mesas: ");
    scanf("%i", &aula->cantidadMesas);
    printf("Ingrese la cantidad de sillas: ");
    scanf("%i", &aula->cantidadSillas);
    printf("Ingrese la cantidad de pizarras: ");
    scanf("%i", &aula->cantidadPizarras);
    printf("Ingrese la marca del proyector: ");
    scanf(" %[^\n]", aula->proyector.marca);
    printf("Ingrese el color del proyector: ");
    scanf(" %[^\n]", aula->proyector.color);
    printf("%cTiene control remoto? (1 = si | 0 = no): ", 168);
    scanf("%d", &aula->proyector.controlRemoto);
}

void imprimirAula(Aula aula){
    printf("\nDatos del Aula:\n");
    printf("N%cmero de Identificaci%cn: %d\n", 163, 162, aula.nroIdentificacion);
    printf("Ubicaci%cn (bloque): %s\n", 162, aula.ubicacion);
    printf("Tipo de Aula: %s\n", aula.tipo);
    printf("Cantidad de Mesas: %d\n", aula.cantidadMesas);
    printf("Cantidad de Sillas: %d\n", aula.cantidadSillas);
    printf("Cantidad de Pizarras: %d\n", aula.cantidadPizarras);
    printf("Proyector Marca: %s\n", aula.proyector.marca);
    printf("Proyector Color: %s\n", aula.proyector.color);
    printf("¿Tiene control remoto?: %s\n", aula.proyector.controlRemoto ? "SI" : "NO");
}

void ingresarAulas(Aula aulas[], int *libre, int tam) {
    int aulasAReg, contador;

    printf("¿Cu%cntas aulas desea agregar?\n", 160);
    scanf("%d", &aulasAReg);

    if (*libre + aulasAReg > tam) {
        printf("ERROR: No hay espacio para agregar otras %d aulas.\n", aulasAReg);
        return;
    }

    for (contador = 0; contador < aulasAReg; contador++) {
        printf("\nIngresando datos para el aula %d:\n", *libre + 1);
        ingresarAula(&aulas[*libre]);
        (*libre)++;
    }
}

void imprimirAulas(Aula aula[], int cant){
    int contador;
    printf("\nAULAS ACTUALES:\n");
    for (contador = 0; contador < cant; contador++) {
        printf("\n\nAULA N%CMERO %d\n", 163, contador+1);
        imprimirAula(aula[contador]);
    }
}



int main()
{
    int capacidadAulas, opcion, posicion = 0;
    printf("Ingrese la capacidad de aulas: ");
    scanf("%d", &capacidadAulas);
    Aula aulas[capacidadAulas];

    do {
        printf("\n\n****************************************\n");
        printf("*        PROGRAMA PARA AULAS :D        *\n");
        printf("****************************************\n");
        printf("<1> CARGAR AULAS\n");
        printf("<2> IMPRIMIR TODAS LAS AULAS\n");
        printf("<3> SALIR\n");
        printf("****************************************\n");
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarAulas(aulas, &posicion, capacidadAulas);
                break;
            case 2:
                imprimirAulas(aulas, posicion);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci%cn no v%clida. Intente de nuevo.\n", 163, 160);
        }
    } while (opcion != 3);

    return 0;
}



