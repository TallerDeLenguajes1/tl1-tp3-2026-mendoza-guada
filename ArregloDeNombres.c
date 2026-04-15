#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void MostrarPersonas(char * Lista[], int n);

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

    return 0;
}

void MostrarPersonas(char * Lista[], int n){
    printf("\nLos nombres ingresados son:\n");
    for (int i=0; i<n; i++){
        printf("%d - %s\n", i+1, Lista[i]);
    }
}

