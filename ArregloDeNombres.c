#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void MostrarPersonas(char * Lista[], int n);
void buscarNombre(char *Lista[], int id);

int main(){
    char *Nombres[N];
    char buffer[90];
    int cant_letras;

    printf("\nIngrese %d nombres: \n", N);
    for (int i=0; i<N; i++){
        printf("%d- ",i+1);
        scanf("%s", buffer);
        cant_letras= strlen(buffer);    
        Nombres[i] = (char *) malloc(sizeof(char)*cant_letras);
        strcpy(Nombres[i], buffer);
    }

    MostrarPersonas(Nombres, N);
    
    int id;
    printf("\n====\nBúsqueda por ID");
    printf("\nIngrese un número de 1 a %d: ", N);
    scanf("%d", &id);
   /* do{
        printf("\nNúmero inválido.\nIngrese un número de 1 a %d: ", N);
        scanf("%d", &id);
    } while (id>N);*/
    buscarNombre(Nombres, id);

    return 0;
}

void MostrarPersonas(char * Lista[], int n){
    printf("\nLos nombres ingresados son:\n");
    for (int i=0; i<n; i++){
        printf("%d - %s\n", i+1, Lista[i]);
    }
}

void buscarNombre(char *Lista[], int id){
    if (id>N || id<1){
        printf("No se encontró el valor buscado.");
    } else {
        for (int i=0; i<N; i++){
            if (i=id-1){
                printf("%d- %s", i+1, Lista[i]);
            }
        }
    }
}
