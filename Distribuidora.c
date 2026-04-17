#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la ariable
}typedef Cliente; // “CantidadProductosAPedir”

void cargaDeClientes(Cliente * arregloDeClientes, int cant_clientes);
void mostrarClientes(Cliente * arregloDeClientes, int cant_clientes);
float totalProducto(int cantidad, float precio);

int main(){
    int cant_clientes;
    Cliente *arregloDeClientes;
    srand(time(NULL));

    printf("\nIngrese la cantidad de clientes a cargar: ");
    scanf("%d", &cant_clientes);
    printf("\n====================\nCARGA DE %d CLIENTES\n====================\n", cant_clientes);

    arregloDeClientes= (Cliente *) malloc(sizeof(Cliente)*cant_clientes);
    
    cargaDeClientes(arregloDeClientes, cant_clientes);
    mostrarClientes(arregloDeClientes, cant_clientes);

    return 0;
}

void cargaDeClientes(Cliente * arregloDeClientes, int cant_clientes){
    srand(time(NULL));
    for (int i=0; i<cant_clientes; i++){
        arregloDeClientes[i].ClienteID=i;
        printf("\nCLIENTE %d", i+1);
        char temporal[30];
        printf("\nIngrese el nombre del cliente: ");
        scanf("%s", temporal);
        arregloDeClientes[i].NombreCliente= (char *) malloc(sizeof(char)*(strlen(temporal)+1));
        strcpy(arregloDeClientes[i].NombreCliente, temporal);
        arregloDeClientes[i].CantidadProductosAPedir=1+rand()%5;
        arregloDeClientes[i].Productos=malloc(sizeof(Producto)*arregloDeClientes[i].CantidadProductosAPedir);
        for (int j=0; j<arregloDeClientes[i].CantidadProductosAPedir; j++){
            arregloDeClientes[i].Productos[j].ProductoID=j+1;
            arregloDeClientes[i].Productos[j].TipoProducto=TiposProductos[rand()%5];
            arregloDeClientes[i].Productos[j].Cantidad=1+rand()%10;
            arregloDeClientes[i].Productos[j].PrecioUnitario=10+rand()%100;
        }
    }
}

void mostrarClientes(Cliente * arregloDeClientes, int cant_clientes){
    printf("\n===========================\n----LISTA DE CLIENTES----\n===========================\n");
    for (int i=0; i<cant_clientes; i++){
        printf("\nCLIENTE ID: %d\n", arregloDeClientes[i].ClienteID);
        printf("\nNombre: %s.", arregloDeClientes[i].NombreCliente);
        printf("\nCantidad de productos a pedir: %d\n", arregloDeClientes[i].CantidadProductosAPedir);
        float suma_total=0;
        for (int j=0; j<arregloDeClientes[i].CantidadProductosAPedir; j++){
            printf("\nProducto ID: %d - %s",arregloDeClientes[i].Productos[j].ProductoID, arregloDeClientes[i].Productos[j].TipoProducto);
            printf("\nCantidad: %d", arregloDeClientes[i].Productos[j].Cantidad);
            printf("\nPrecio por unidad: $%.2f", arregloDeClientes[i].Productos[j].PrecioUnitario);
            float total_producto=totalProducto(arregloDeClientes[i].Productos[j].Cantidad, arregloDeClientes[i].Productos[j].PrecioUnitario);
            printf("\nTotal por %d unidades: $%.2f", arregloDeClientes[i].Productos[j].Cantidad, total_producto);
            printf("\n\n");
            suma_total+=total_producto;
        }
        printf("\nTOTAL DE LA COMPRA: $%.2f.", suma_total);
        printf("\n------------------\n");
    }
}

float totalProducto(int cantidad, float precio){
    return cantidad*precio;
}