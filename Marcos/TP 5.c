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
