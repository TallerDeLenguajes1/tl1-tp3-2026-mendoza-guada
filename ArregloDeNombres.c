#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

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

    return 0;
}


