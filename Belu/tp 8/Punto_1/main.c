#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct e{
    char nomb[30]; //string
    char ape[30]; //string
    int antiguedad;
} empleado;

void leer(empleado o[], int *cant){
    FILE *archivo = fopen("nuevo.txt", "r");
    int total = 0;

    if(archivo == NULL){
        printf("ERROR NO EXISTE EL ARCHIVO");
        exit(1);
    }else{
//        fprintf(archivo, "%s\n",o[total].nomb);
//        fprintf(archivo, "%s\n",o[total].ape);
//        fprintf(archivo, "%d\n",o[total].antiguedad);
        while(feof(archivo) == 0){
            fscanf(archivo, "%s", o[total].nomb);
            fscanf(archivo, "%s", o[total].ape);
            fscanf(archivo, "%d", &o[total].antiguedad);
            total++;
        }
    }
    *cant = total;
    fclose(archivo);
}

int main(){
    int cantTotal = 0;

    empleado otro_personal[100];
    leer(otro_personal, &cantTotal);

    empleado personal[100];

    int i = 0;
    for(i; i < cantTotal; i++){
        printf("\nEMPLEADO %d\n", i+1);
        printf("Nombre: %s\n", otro_personal[i].nomb);
        printf("Apellido: %s\n", otro_personal[i].ape);
        printf("Antiguedad: %d\n", otro_personal[i].antiguedad);
    }
}
