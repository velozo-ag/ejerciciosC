#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[30];

typedef struct{
    int codProducto;
    tString descripcion;
    float precioUnitario;
}tProducto;

typedef struct nodo{
    tProducto producto;
    struct nodo *siguiente;
}tPila;

tPila *pilaCajas;
int tamanio;

void inicializarLista();
tProducto crearProducto();

void insertarProducto(tProducto);

int main(){

    inicializarLista();
    crearProducto();

}

void inicializarLista(){
    pilaCajas = NULL;
    tamanio = 0;
}

tProducto crearProducto(){
    tProducto nuevoProducto;

    printf("Ingrese el codigo del producto: \n > ");
    scanf("%d", &nuevoProducto.codProducto);

    printf("Ingrese la descripcion del producto: \n > ");
    // gets(nuevoProducto.descripcion);
    fflush(stdin);
    scanf("%s", &nuevoProducto.descripcion);

    printf("Ingrese el precio del producto: \n > ");
    scanf("%f", &nuevoProducto.precioUnitario);

    return nuevoProducto;
}