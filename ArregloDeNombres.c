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
    int cant_letras, opcion;

    printf("\nIngrese %d nombres: \n", N);
    for (int i=0; i<N; i++){
        printf("%d- ",i+1);
        scanf("%s", buffer);
        cant_letras= strlen(buffer);    
        Nombres[i] = (char *) malloc(sizeof(char)*cant_letras);
        strcpy(Nombres[i], buffer);
    }

    MostrarPersonas(Nombres, N);
    
    printf("\n==================BÚSQUEDA DE RESULTADOS\n==================\n");
    printf("\nUsted puede realizar una búsqueda del nombre por: \nOpción 1 - Búsqueda por ID: Ingrese un número de orden para hallar el nombre de esa posición.\nOpción 2 - Búsqueda por palabra clave: Ingrese una palabra para encontrar un nombre que la contenga.\n\n");
    printf("Ingrese el número de la opción deseada: ");
    scanf("%d", &opcion);

    if (opcion==1){
        int id;
        printf("\n========================\nBúsqueda por ID\n");
        printf("\nIngrese un número de 1 a %d: ", N);
        scanf("%d", &id);
        buscarNombrePorID(Nombres, id);
    } else {
            if (opcion==2){
                char palabra_b[30];
                printf("\n========================\nBUSQUEDA POR PALABRA");
                printf("\nIngrese una palabra a buscar: ");
                scanf("%s", palabra_b);
                BuscarNombrePorPalabra(Nombres, palabra_b);
            } else {
                printf("\nOpción inválida. Intente nuevamente");
            }
    }

    return 0;
}

void MostrarPersonas(char * Lista[], int n){
    printf("\nLos nombres ingresados son:\n");
    for (int i=0; i<n; i++){
        printf("%d - %s\n", i+1, Lista[i]);
    }
}

void BuscarNombrePorPalabra(char * Lista[], char palabra[]){
    int aux=-1;
    int cant_palabra=strlen(palabra);
    /*for (int i=0; i<cant_palabra; i++){
        palabra[i]=tolower(palabra[i]);
    }*/
    for (int i=0; i<N; i++){
       /* Lista[i]=tolower(Lista[i]);*/
        char *busqueda=strstr(Lista[i], palabra);
        if (busqueda!=NULL){
        aux=i;
        }
    }
    if (aux!=-1){
        printf("\nRESULTADO: \n");
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
            if (i==id-1){
                printf("\nRESULTADO: \n");
                printf("%d- %s", i+1, Lista[i]);
            }
        }
    }
}