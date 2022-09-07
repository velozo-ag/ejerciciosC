// Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
// producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
// y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
// del primer nodo almacenado.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Definicion de tipos
typedef char tString[30];


typedef struct{
    int codProducto;
    tString descripcion;
    float precioUnitario;
}tProducto;

typedef struct nodo{
    tProducto producto;
    struct nodo *siguiente;
}tListaProductos;

// Lista Enlazada
tListaProductos *listaProductos;

// Prototipos
void inicializarLista();
tProducto crearProducto();
void insertarPrimerNodo(tProducto);
void mostrarProductos();

int main()
{

    inicializarLista();
    insertarPrimerNodo(crearProducto());
    mostrarProductos();

    return 0;
}


void inicializarLista(){
    listaProductos = NULL;
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

void insertarPrimerNodo(tProducto prod){

    tListaProductos * nuevoNodo;

    nuevoNodo = (tListaProductos*) malloc(sizeof(tListaProductos));

    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = NULL;

    listaProductos = nuevoNodo;

    printf("Primer elemento insertado\n");

}

void mostrarProductos(){

    tListaProductos * aux;
    tProducto producto;
    aux = listaProductos;

    if(aux != NULL){
        
        printf("\n Detalles de los Productos Insertados \n");

        while(aux != NULL){
            
            producto = aux->producto;

            printf("\t%d ", producto.codProducto);
            
            printf("%s ", producto.descripcion);
            
            printf("$%.2f\n", producto.precioUnitario);

            aux = aux->siguiente;

        }

    }

}
