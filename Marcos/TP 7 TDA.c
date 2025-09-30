EJERCICIO 2:
MAIN.C:
#include <stdio.h>
#include "fraccion.h"


int main() {
    Fraccion fracciones[TAM];
    Fraccion resultado_temp;
    int cantidad, contador;

    printf("Ingrese la cantidad de fracciones: ");
    scanf("%d", &cantidad);

    for (contador = 0; contador < cantidad; contador++) {
        int num, denom;
        printf("Fracción %d - Numerador: ", contador + 1);
        scanf("%d", &num);
        printf("Fracción %d - Denominador: ", contador + 1);
        scanf("%d", &denom);
        crear_fraccion(&fracciones[contador], num, denom);
    }

    for (contador = 0; contador < cantidad; contador++) {
        printf("Fracción %d: %d/%d\n", contador + 1, get_numerador(fracciones[contador]), get_denominador(fracciones[contador]));
    }

    Fraccion sumaTotal = fracciones[0];
    for (int contador = 1; contador < cantidad; contador++) {
        sumar(&sumaTotal, sumaTotal, fracciones[contador]);
    }

    printf("¿Quiere simplificar la fracci%cn?: (Si = 1; No = 0): ", 162);
    scanf("%d", &simpl);
    if(simpl) simplificar(&sumaTotal);
    printf("La suma total es: %d/%d\n", get_numerador(sumaTotal), get_denominador(sumaTotal));
    return 0;
}


FRACCION.H:
#ifndef FRACCION_H_INCLUDED
#define FRACCION_H_INCLUDED
#define TAM 100

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

void inicializar(Fraccion *fracc) {
    fracc->numerador = 0;
    fracc->denominador = 1;
}

void set_denominador(Fraccion *fracc, int denom) {
    if (denom != 0) {
        fracc->denominador = denom;
    } else {
        printf("Error: El denominador no puede ser 0.\n");
        exit(1);
    }
}

void set_numerador(Fraccion *fracc, int num){
    fracc->numerador = num;
}

void crear_fraccion(Fraccion *fracc, int num, int denom) {
    set_numerador(fracc, num);
    set_denominador(fracc, denom);
}

int get_numerador(Fraccion fracc) {
    return fracc.numerador;
}

int get_denominador(Fraccion fracc) {
    return fracc.denominador;
}

float get_valorReal(Fraccion fracc) {
    return (float)fracc.numerador / fracc.denominador;
}

int mcd(int den1, int den2) {
    if (den2 == 0) {
        return den1;
    }
    return mcd(den2, den1 % den2);
}

void simplificar(Fraccion *fracc) {
    int mcd_temp = mcd(fracc->numerador, fracc->denominador);
    set_numerador(fracc, fracc->numerador / mcd_temp);
    set_denominador(fracc, fracc->denominador / mcd_temp);
}

void sumar(Fraccion *resultado, Fraccion x, Fraccion y) {
    int numerador = x.numerador * y.denominador + x.denominador * y.numerador;
    int denominador = x.denominador * y.denominador;
    crear_fraccion(resultado, numerador, denominador);
}

void restar(Fraccion *resultado, Fraccion x, Fraccion y) {
    int numerador = x.numerador * y.denominador - x.denominador * y.numerador;
    int denominador = x.denominador * y.denominador;
    crear_fraccion(resultado, numerador, denominador);
}

void multiplicar(Fraccion *resultado, Fraccion x, Fraccion y) {
    int numerador = x.numerador * y.numerador;
    int denominador = x.denominador * y.denominador;
    crear_fraccion(resultado, numerador, denominador);
}

void dividir(Fraccion *resultado, Fraccion x, Fraccion y) {
    if (y.numerador != 0) {
        int numerador = x.numerador * y.denominador;
        int denominador = x.denominador * y.numerador;
        crear_fraccion(resultado, numerador, denominador);
    } else {
        printf("Error: División por cero.\n");
        exit(1);
    }
}
#endif // FRACCION_H_INCLUDED





EJERCICIO 3:
PERSONA.H
#define MAX 50
#define MAX_NOMBRE 30
#define MAX_APELLIDO 30
#define MAX_MAIL 50


typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int dni;
    char mail[MAX_MAIL];
} Persona;


void init_per(Persona *per) {
    int contador;
    for (contador = 0; contador < MAX_NOMBRE; contador++) {
        per->nombre[contador] = '\0';
    }
    for (contador = 0; contador < MAX_APELLIDO; contador++) {
        per->apellido[contador] = '\0';
    }
    for (int contador = 0; contador < MAX_MAIL; contador++) {
        per->mail[contador] = '\0';
    }
    per->dni = 0;
}

void set_nombre(Persona *per, char nom[]) {
    strncpy(per->nombre, nom, MAX_NOMBRE - 1);
    per->nombre[MAX_NOMBRE - 1] = '';
}

void set_apellido(Persona *per, char apell[]) {
    strncpy(per->apellido, apell, MAX_APELLIDO - 1);
    per->apellido[MAX_APELLIDO - 1] = '';
}

void set_dni(Persona *per, int nro){
    per->dni = nro;
}

void set_mail(Persona *per, char mailn[]) {
    strncpy(per->mail, mailn, MAX_MAIL - 1);
    per->mail[MAX_MAIL - 1] = '';
}


char* get_nombre(Persona per) {
    char *ptr_nomb = (char *)malloc(strlen(per.nombre) + 1);
    if (ptr_nomb == NULL) exit(1);
    strcpy(ptr_nomb, per.nombre);
    return ptr_nomb;
}

char* get_apellido(Persona per) {
    char *ptr_apell = (char *)malloc(strlen(per.apellido) + 1);
    if (ptr_apell == NULL) exit(1);
    strcpy(ptr_apell, per.apellido);
    return ptr_apell;
}

int get_dni(Persona per) {
    return per.dni;
}

char* get_mail(Persona per) {
    char *ptr_mail = (char *)malloc(strlen(per.mail) + 1);
    if (ptr_mail == NULL) exit(1);
    strcpy(ptr_mail, per.mail);
    return ptr_mail;
}

int buscarDNI(Persona pers[], int cant, int dni) {
    int contador;
    for (contador = 0; contador < cant; contador++) {
        if (pers[contador].dni == dni) {
            return contador;
        }
    }
    return -1;
}

int isEmpty(int total) {
    return total == 0;
}

int isFull(int libre, int maximo) {
    return libre >= maximo;
}



MAIN.C
#include "persona.h"

void cargarPersona(Persona *per) {
    char nombre[MAX_NOMBRE], apellido[MAX_APELLIDO], mail[MAX_MAIL];
    int dni;

    printf("Ingrese nombre: ");
    scanf(" %[^\n0123456789]", nombre);
    set_nombre(per, nombre);

    printf("Ingrese apellido: ");
    scanf(" %[^\n0123456789]", apellido);
    set_apellido(per, apellido);

    printf("Ingrese DNI: ");
    scanf("%d", &dni);
    set_dni(per, dni);

    printf("Ingrese mail: ");
    scanf(" %[^\n]", mail);
    set_mail(per, mail);
}

void cargarPersonas(Persona personas[], int *libre) {
    int personasARegistrar, contador;

    printf("¿Cuántas personas desea ingresar? ");
    scanf("%d", &personasARegistrar);

    if (*libre + personasARegistrar > MAX) {
        printf("ERROR: No hay espacio para agregar %d personas.\n", personasARegistrar);
    } else {

    for (contador = *libre; contador < *libre + personasARegistrar; contador++) {
        printf("\nIngrese datos de la persona %d:\n", *libre + 1);
        cargarPersona(&personas[contador]);
    }
    *libre += personasARegistrar;
        }
}

void mostrarPersona(Persona per) {
    printf("Nombre: %s\n", per.nombre);
    printf("Apellido: %s\n", per.apellido);
    printf("DNI: %d\n", per.dni);
    printf("Correo: %s\n", per.mail);
    printf("\n\n");
}

void modificarPersona(Persona pers[], int tam, int dni_a_mod) {
    int contador, opcion_temp;
    for (contador = 0; contador < tam; contador++) {
        if (pers[contador].dni == dni_a_mod) {
            printf("Persona encontrada: %s %s (DNI: %d)\n\n", pers[contador].nombre, pers[contador].apellido, pers[contador].dni);
            printf("¿Qu%c dato desea modificar?\n", 130);
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Mail\n");
            printf("Ingrese su opci%cn: ", 162);
            scanf("%d", &opcion_temp);

            switch (opcion_temp) {
                case 1: {
                    char n_nombr[MAX_NOMBRE];
                    printf("Ingrese el nuevo nombre: ");
                    scanf(" %[^\n0123456789]", n_nombr);
                    for (contador = 0; contador < MAX_NOMBRE; contador++) {
                        pers[contador].nombre[contador] = '\0';
                    }
                    set_nombre(&pers[contador], n_nombr);
                    printf("Nombre actualizado.\n");
                    break;
                }
                case 2: {
                    char n_apell[MAX_APELLIDO];
                    printf("Ingrese el nuevo apellido: ");
                    scanf(" %[^\n0123456789]", n_apell);
                    for (contador = 0; contador < MAX_NOMBRE; contador++) {
                        pers[contador].apellido[contador] = '\0';
                    }
                    set_apellido(&pers[contador], n_apell);
                    printf("Apellido actualizado.\n");
                    break;
                }
                case 3: {
                    char n_mail[MAX_MAIL];
                    printf("Ingrese el nuevo mail: ");
                    scanf(" %[^\n]", n_mail);
                    for (contador = 0; contador < MAX_NOMBRE; contador++) {
                        pers[contador].mail[contador] = '\0';
                    }
                    set_mail(&pers[contador], n_mail);
                    printf("Mail actualizado.\n");
                    break;
                }
                default:
                    printf("Opci%cn no v%clida.\n", 162, 160);
                    break;
            }
        return 1;
        }
    }
    printf("Persona con DNI %s no encontrada.\n", dni_a_mod);
    return 0;
}

int main(){
    Persona personas[MAX];
    int totalPersonas = 0;
    int opcion, posicion, dni_temp;

    for(posicion = 0; posicion < MAX; posicion++){
        init_per(&personas[posicion]);
    }

    do{
        printf("MENU\n");
        printf("1. Ingresar persona\n");
        printf("2. Modificar persona por DNI\n");
        printf("3. Buscar persona por DNI\n");
        printf("4. Mostrar todas las personas\n");
        printf("5. Salir\n");
        printf("Elija una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            if (isFull(totalPersonas, MAX)) printf("El arreglo de personas est%c lleno.\n", 160);
            else cargarPersonas(personas, &totalPersonas);
            printf("\n\n");
            break;
        case 2:
            if (isEmpty(totalPersonas)) printf("El arreglo de personas est%c vac%co.\n", 160, 161);
            else {
                printf("Ingrese el DNI de la persona a modificar: ");
                scanf("%d", &dni_temp);
                modificarPersona(personas, totalPersonas, dni_temp);
                }
            printf("\n\n");
            break;
        case 3:
            if (isEmpty(totalPersonas)) printf("El arreglo de personas est%c vac%co.\n", 160, 161);
            else {
                printf("Ingrese el DNI de la persona a buscar: ");
                scanf("%d", &dni_temp);
                int pos = buscarDNI(personas, totalPersonas, dni_temp);
                if (pos >= 0) {
                        printf("Persona encontrada en la posición %d:
", pos + 1);
                        mostrarPersona(personas[pos]);
                } else {
                        printf("Persona con DNI %d no encontrada.
", dni_temp);
                    }
                }
            printf("\n\n");
            break;
        case 4:
            if (isEmpty(totalPersonas)) {
                printf("El arreglo de personas est%c vac%co.\n\n", 160, 161);
            } else {
                int contador_temp;
                for(contador_temp = 0; contador_temp < totalPersonas; contador_temp++){
                    printf("Persona n. %d\n", contador_temp + 1);
                    mostrarPersona(personas[contador_temp]);
                }
            }
            printf("\n\n");
            break;
        case 5:
            printf("Saliendo del programa...\n\n");
            break;
        default:
            printf("Opci%cn no v%clida. Intente de nuevo.\n\n", 162, 160);
            break;
        }
    } while (opcion != 5);
    return 0;
}





EJERCICIO 4:
PILA.H
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

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
        p->tope++;
        p->elementos[p->tope] = nro;
}

void desapilar(PilaEst *p) {
        p->tope--;
}

int top(PilaEst p) {
    return p.elementos[p.tope];
}
#endif // PILA_H_INCLUDED


MAIN.C
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void imprimir_pila(PilaEst p) {
    printf("Elementos en la pila: ");
    while (!isEmpty(p)) {
        printf("%d ", top(p));
        desapilar(&p);
    }
    printf("\n");
}

int main() {
    PilaEst pilaEnteros;
    init(&pilaEnteros);

    apilar(&pilaEnteros, 10);
    apilar(&pilaEnteros, 20);
    apilar(&pilaEnteros, 30);

    imprimir_pila(pilaEnteros);

    printf("Elemento superior: %d\n", top(pilaEnteros));

    desapilar(&pilaEnteros);
    printf("Elemento superior despu%cs de la supresi%cn: %d\n", 131, 162, top(pilaEnteros));

    imprimir_pila(pilaEnteros);

    return 0;
}




EJERCICIO 5:
VER TDAestructuras
#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

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


#endif // FILA_H_INCLUDED

MAIN PRUEBA:
#include "fila.h"

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

int main() {
    FilaEst filaChar;
    initFila(&filaChar);

    insertF(&filaChar, 'A');
    insertF(&filaChar, 'B');
    insertF(&filaChar, 'C');

    imprimirFila(filaChar);
    printf("Elemento al frente de la fila (sin suprimir): %c\n\n", copyF(filaChar));

    char sacado = copyF(filaChar);
    if (supress(&filaChar)) {
    printf("Elemento suprimido de la fila: %c\n", sacado);
    } else {
    printf("No se pudo suprimir elemento, la fila est%c vac%ca.\n", 160, 161);
    }

    printf("FILA DESPUES DE SACAR AL PRIMERO: \n");
    imprimirFila(filaChar);

    printf("\n\nAGREGO 8 X IGUALES\n");
    for (int i = 0; i < 8; i++) {
        insertF(&filaChar, 'X');
    }

    imprimirFila(filaChar);

    return 0;
}




EJERCICIO 6:
PERSONA + PILA + 2 MAINS:
HEADER
#ifndef PYF_PERSONA_H_INCLUDED
#define PYF_PERSONA_H_INCLUDED
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#define MAX_MAIL 50
#define MAX 100

typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int dni;
    char mail[MAX_MAIL];
} Persona;


void init_per(Persona *per) {
    int contador;
    for (contador = 0; contador < MAX_NOMBRE; contador++) {
        per->nombre[contador] = '\0';
    }
    for (contador = 0; contador < MAX_APELLIDO; contador++) {
        per->apellido[contador] = '\0';
    }
    for (int contador = 0; contador < MAX_MAIL; contador++) {
        per->mail[contador] = '\0';
    }
    per->dni = 0;
}

void set_nombre(Persona *per, char nom[]) {
    strncpy(per->nombre, nom, MAX_NOMBRE - 1);
    per->nombre[MAX_NOMBRE - 1] = '\0';
}

void set_apellido(Persona *per, char apell[]) {
    strncpy(per->apellido, apell, MAX_APELLIDO - 1);
    per->apellido[MAX_APELLIDO - 1] = '\0';
}

void set_dni(Persona *per, int nro){
    per->dni = nro;
}

void set_mail(Persona *per, char mailn[]) {
    strncpy(per->mail, mailn, MAX_MAIL - 1);
    per->mail[MAX_MAIL - 1] = '\0';
}


char* get_nombre(Persona per) {
    char *ptr_nomb = (char *)malloc(strlen(per.nombre) + 1);
    if (ptr_nomb == NULL) exit(1);
    strcpy(ptr_nomb, per.nombre);
    return ptr_nomb;
}

char* get_apellido(Persona per) {
    char *ptr_apell = (char *)malloc(strlen(per.apellido) + 1);
    if (ptr_apell == NULL) exit(1);
    strcpy(ptr_apell, per.apellido);
    return ptr_apell;
}

int get_dni(Persona per) {
    return per.dni;
}

char* get_mail(Persona per) {
    char *ptr_mail = (char *)malloc(strlen(per.mail) + 1);
    if (ptr_mail == NULL) exit(1);
    strcpy(ptr_mail, per.mail);
    return ptr_mail;
}



/** PILA DE PERSONAS **/
typedef struct {
    Persona personas[MAX];
    int tope;
} PilaPer;

void initPila(PilaPer *p) {
    p->tope = -1;
}

int isEmptyP(PilaPer p) {
    return p.tope == -1;
}

int isFullP(PilaPer p) {
    return p.tope == MAX - 1;
}

void insertP(PilaPer *p, Persona pers) {
    p->tope++;
    p->personas[p->tope] = pers;
}

void desapilar(PilaPer *p) {
    p->tope--;
}

void pop(PilaPer *p) {
    p->tope--;
}

Persona copyP(PilaPer *p) {
    return p->personas[p->tope];
}
#endif // PYF_PERSONA_H_INCLUDED


MAIN VERSION 1 (EJEMPLO LISTO)
void mostrarPersona(Persona p) {
    printf("Nombre: %s %s, DNI: %d, Mail: %s\n\n", p.nombre, p.apellido, p.dni, p.mail);
}

int main() {
    PilaPer pila;
    initPila(&pila);

    Persona p1, p2, p3;
    init_per(&p1);
    set_nombre(&p1, "Ana");
    set_apellido(&p1, "Gomez");
    set_dni(&p1, 12345678);
    set_mail(&p1, "ana@mail.com");

    init_per(&p2);
    set_nombre(&p2, "Luis");
    set_apellido(&p2, "Perez");
    set_dni(&p2, 87654321);
    set_mail(&p2, "luis@mail.com");

    init_per(&p3);
    set_nombre(&p3, "Maria");
    set_apellido(&p3, "Lopez");
    set_dni(&p3, 11223344);
    set_mail(&p3, "maria@mail.com");

    insertP(&pila, p1);
    insertP(&pila, p2);
    insertP(&pila, p3);

    printf("Persona en el tope:\n");
    mostrarPersona(copyP(&pila));

    printf("Desapilando...\n");
    desapilar(&pila);

    printf("Ahora la persona en el tope:\n");
    mostrarPersona(copyP(&pila));

    return 0;
}


MAIN VERSION 2 (MENU + FUNCIONES EXTRAS + VALIDACIONES)
#include "PyF Persona.h"
Persona cargarPersona() {
    Persona p;
    printf("Ingrese nombre: ");
    scanf(" %[^\n]", p.nombre);
    printf("Ingrese apellido: ");
    scanf(" %[^\n]", p.apellido);
    printf("Ingrese DNI: ");
    scanf("%d", &p.dni);
    printf("Ingrese mail: ");
    scanf(" %[^\n]", p.mail);
    return p;
}

void mostrarPersona(Persona p) {
    printf("Nombre: %s %s, \nDNI: %d, \nMail: %s\n\n", p.nombre, p.apellido, p.dni, p.mail);
}

int buscarDNI(Persona pers[], int cant, int dni) {
    int contador;
    for (contador = 0; contador < cant; contador++) {
        if (pers[contador].dni == dni) {
            return contador;
        }
    }
    return -1;
}

void mostrarPila(PilaPer *p) {
    if (isEmptyP(*p)) {
        printf("La pila est%c vac%ca. No hay personas para mostrar.\n", 160, 161);
        return;
    }
    printf("Personas en la pila:\n");
    for (int i = 0; i <= p->tope; i++) {
        printf("Nombre: %s %s, \nDNI: %d, \nMail: %s\n\n",
               p->personas[i].nombre,
               p->personas[i].apellido,
               p->personas[i].dni,
               p->personas[i].mail);
    }
}

void cargarVariasPersonas(PilaPer *p) {
    int cantidad;
    Persona temp;
    printf("¿Cu%cntas personas desea ingresar?: ", 160);
    scanf("%d", &cantidad);

    if (isFullP(*p)) {
        printf("La fila est%c llena.\n", 160);
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        if (isFullP(*p)) {
            printf("La fila est%c llena.\n", 160);
            break;
        }
        printf("Ingresar persona %d:\n", i+1);
        temp = cargarPersona();
        insertP(p, temp);
    }
}


int main() {
    PilaPer pilaPersonas;
    int opcion;
    Persona persona_temp;
    initPila(&pilaPersonas);

    do {
        printf("MENU\n");
        printf("1. Insertar persona\n");
        printf("2. Insertar personas\n");
        printf("3. Eliminar persona\n");
        printf("4. Mostrar el tope\n");
        printf("5. Mostrar pila completa\n");
        printf("6. Salir\n");
        printf("Elija una opci%cn: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                persona_temp = cargarPersona();
                insertP(&pilaPersonas, persona_temp);
                printf("\n\n");
                break;
            case 2:
                cargarVariasPersonas(&pilaPersonas);
                printf("\n\n");
                break;
            case 3:
                if (isEmptyP(pilaPersonas)) {
                printf("No hay personas para eliminar.\n");
                initPila(&pilaPersonas);
                } else {
                persona_temp = copyP(&pilaPersonas);
                pop(&pilaPersonas);
                printf("Persona eliminada: %s %s, DNI: %d\n", persona_temp.nombre, persona_temp.apellido, persona_temp.dni);
                }
                printf("\n\n");
                break;
            case 4:
                if (isEmptyP(pilaPersonas)) {
                printf("No hay un tope.\n");
                initPila(&pilaPersonas);
                } else {
                persona_temp = copyP(&pilaPersonas);
                mostrarPersona(persona_temp);
                }
                printf("\n");
                break;
            case 5:
                if (isEmptyP(pilaPersonas)) {
                printf("No hay personas para mostrar.\n");
                initPila(&pilaPersonas);
                } else {
                mostrarPila(&pilaPersonas);
                }
                printf("\n\n");
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                break;
        }
    } while (opcion != 6);
    return 0;
}





PERSONA + FILA + MAIN:
HEADER:
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#define MAX_MAIL 50
#define MAX 100


typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int dni;
    char mail[MAX_MAIL];
} Persona;


void init_per(Persona *per) {
    int contador;
    for (contador = 0; contador < MAX_NOMBRE; contador++) {
        per->nombre[contador] = '\0';
    }
    for (contador = 0; contador < MAX_APELLIDO; contador++) {
        per->apellido[contador] = '\0';
    }
    for (int contador = 0; contador < MAX_MAIL; contador++) {
        per->mail[contador] = '\0';
    }
    per->dni = 0;
}

void set_nombre(Persona *per, char nom[]) {
    strncpy(per->nombre, nom, MAX_NOMBRE - 1);
    per->nombre[MAX_NOMBRE - 1] = '\0';
}

void set_apellido(Persona *per, char apell[]) {
    strncpy(per->apellido, apell, MAX_APELLIDO - 1);
    per->apellido[MAX_APELLIDO - 1] = '\0';
}

void set_dni(Persona *per, int nro){
    per->dni = nro;
}

void set_mail(Persona *per, char mailn[]) {
    strncpy(per->mail, mailn, MAX_MAIL - 1);
    per->mail[MAX_MAIL - 1] = '\0';
}


char* get_nombre(Persona per) {
    char *ptr_nomb = (char *)malloc(strlen(per.nombre) + 1);
    if (ptr_nomb == NULL) exit(1);
    strcpy(ptr_nomb, per.nombre);
    return ptr_nomb;
}

char* get_apellido(Persona per) {
    char *ptr_apell = (char *)malloc(strlen(per.apellido) + 1);
    if (ptr_apell == NULL) exit(1);
    strcpy(ptr_apell, per.apellido);
    return ptr_apell;
}

int get_dni(Persona per) {
    return per.dni;
}

char* get_mail(Persona per) {
    char *ptr_mail = (char *)malloc(strlen(per.mail) + 1);
    if (ptr_mail == NULL) exit(1);
    strcpy(ptr_mail, per.mail);
    return ptr_mail;
}


typedef struct {
    Persona pers[MAX];
    int ultimo;
} FilaPer;


void initFila(FilaPer *f){
    f->ultimo = -1;
}

int isEmptyF(FilaPer f){
    return f.ultimo == -1;
}

int isFullF(FilaPer f){
    return f.ultimo == MAX - 1;
}

int insertF(FilaPer *f, Persona p){
    if(isFullF(*f)) return -1;
    f->ultimo++;
    f->pers[f->ultimo] = p;
    return 1;
}

int pop(FilaPer *f) {
    if (isEmptyF(*f)) return -1;
    int i;
    int cant = f->ultimo;
    for (i = 0; i < cant; i++) {
        f->pers[i] = f->pers[i + 1];
    }
    f->ultimo--;
    return 1;
}

Persona copyF(FilaPer f){
    return f.pers[0];
}



MAIN VERSION 2 (MENU + FUNCIONES EXTRAS + VALIDACIONES)
#include "PyF Persona.h"
Persona cargarPersona() {
    Persona p;
    printf("Ingrese nombre: ");
    scanf(" %[^\n]", p.nombre);
    printf("Ingrese apellido: ");
    scanf(" %[^\n]", p.apellido);
    printf("Ingrese DNI: ");
    scanf("%d", &p.dni);
    printf("Ingrese mail: ");
    scanf(" %[^\n]", p.mail);
    return p;
}

void mostrarPersona(Persona p) {
    printf("Nombre: %s %s, \nDNI: %d, \nMail: %s\n\n", p.nombre, p.apellido, p.dni, p.mail);
}

int buscarDNI(Persona pers[], int cant, int dni) {
    int contador;
    for (contador = 0; contador < cant; contador++) {
        if (pers[contador].dni == dni) {
            return contador;
        }
    }
    return -1;
}

void mostrarFila(FilaPer f) {
    if (isEmptyF(f)) {
        printf("La fila est%c vac%ca. No hay personas para mostrar.\n", 160, 161);
    } else {
        int contador = 0;
        printf("Personas en la fila:\n");
        while (!isEmptyF(f)) {
            Persona p_temp = copyF(f);
            printf("Persona %d:\n", contador + 1);
            mostrarPersona(p_temp);
            pop(&f);
            contador++;
        }
    }
}

void cargarVariasPersonas(FilaPer *f) {
    int cantidad;
    Persona temp;
    printf("¿Cu%cntas personas desea ingresar?: ", 160);
    scanf("%d", &cantidad);

    if (isFullF(*f)) {
        printf("La fila est%c llena.\n", 160);
        exit(1);
    }

    for (int i = 0; i < cantidad; i++) {
        if (isFullF(*f)) {
            printf("La fila est%c llena.\n", 160);
            break;
        }
        printf("Ingresar persona %d:\n", i+1);
        temp = cargarPersona();
        insertF(f, temp);
        printf("\n");
    }
}


int main() {
    FilaPer filaPersonas;
    int opcion;
    Persona persona_temp;
    initFila(&filaPersonas);

    do {
        printf("MENU\n");
        printf("1. Insertar persona\n");
        printf("2. Insertar personas\n");
        printf("3. Eliminar persona (del frente)\n");
        printf("4. Mostrar la primera persona\n");
        printf("5. Mostrar fila completa\n");
        printf("6. Salir\n");
        printf("Elija una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                persona_temp = cargarPersona();
                if(!insertF(&filaPersonas, persona_temp)){
                    printf("No se pudo insertar: la fila est%c llena.\n", 160);
                }
                break;
            case 2:
                cargarVariasPersonas(&filaPersonas);
                break;
            case 3:
                if (isEmptyF(filaPersonas)) {
                printf("No hay personas para eliminar.\n");
                } else {
                persona_temp = copyF(filaPersonas);
                pop(&filaPersonas);
                printf("Persona eliminada:\n");
                mostrarPersona(persona_temp);
                }
                break;
            case 4:
                if (isEmptyF(filaPersonas)) {
                printf("No hay personas para mostrar.\n");
                } else {
                persona_temp = copyF(filaPersonas);
                mostrarPersona(persona_temp);
                }
                break;
            case 5:
                if (isEmptyF(filaPersonas)) {
                printf("No hay personas para mostrar.\n");
                } else {
                mostrarFila(filaPersonas);
                }
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci%cn no v%clida.\n", 162, 160);
                break;
        }
    } while (opcion != 6);
    return 0;
}







