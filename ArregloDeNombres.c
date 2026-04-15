#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void MostrarPersonas(char * Lista[], int n);
void BuscarNombre(char * Lista[], char palabra[]);

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

    char palabra_b[30];
    printf("\n============\nBUSQUEDA POR PALABRA");
    printf("\nIngrese una palabra a buscar: ");
    scanf("%s", palabra_b);

    BuscarNombre(Nombres, palabra_b);
    return 0;
}

void MostrarPersonas(char * Lista[], int n){
    printf("\nLos nombres ingresados son:\n");
    for (int i=0; i<n; i++){
        printf("%d - %s\n", i+1, Lista[i]);
    }
}

void BuscarNombre(char * Lista[], char palabra[]){
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

