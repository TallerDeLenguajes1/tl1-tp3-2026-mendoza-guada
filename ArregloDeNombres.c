#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void MostrarPersonas(char * Lista[], int n);
void BuscarNombrePorPalabra(char * Lista[], char palabra[]);
void buscarNombrePorID(char *Lista[], int id);

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
    buscarNombrePorID(Nombres, id);

    char palabra_b[30];
    printf("\n============\nBUSQUEDA POR PALABRA");
    printf("\nIngrese una palabra a buscar: ");
    scanf("%s", palabra_b);

    BuscarNombrePorPalabra(Nombres, palabra_b);

    return 0;
}

void MostrarPersonas(char * Lista[], int n){
    printf("\nLos nombres ingresados son:\n");
    for (int i=0; i<n; i++){
        printf("%d - %s\n", i+1, Lista[i]);
    }
}

void BuscarNombrePorPalabra(char * Lista[], char palabra[]){
    int aux;
    tolower(palabra);
    for (int i=0; i<N; i++){
        tolower(Lista[i]);
        char *busqueda=strstr(Lista[i], palabra);
        aux=i;
    }
    if (aux){
        printf("\n%d- %s ",aux+1,Lista[aux]);
    } else {
        printf("\nNo se encontraron resultados. ");
    }
}

void buscarNombrePorID(char *Lista[], int id){
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