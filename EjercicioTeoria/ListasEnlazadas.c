// Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
// producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
// y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
// del primer nodo almacenado. 
// a) Generar o inicializar la lista. -
// b) Función para determinar si una lista está vacía. -
// c) Insertar el primer producto (nodo) de la lista. -
// d) Insertar un producto al principio de la lista. -
// f) Insertar un producto en una determinada posición dentro de la lista. -
// e) Eliminar el primer producto de la lista. -
// g) Eliminar un producto de una determinada posición de la lista. -
// h) Visualizar todos los datos de los productos que están en la lista. -

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
}tPila;

// Definicion Pila
tPila *pilaCajas;
int tamanio;

// Prototipos
void inicializarLista();
tProducto crearProducto();

void insertarProducto(tProducto);
void insertarPrimerNodo(tProducto);
void apilar(tProducto);

void desapilar();
void mostrarCajas();

// MAIN
int main(){

    inicializarLista();
    insertarProducto(crearProducto());
    insertarProducto(crearProducto());
    insertarProducto(crearProducto());
    
    mostrarCajas();

    system("pause");
    // system("cls");

    desapilar();

    mostrarCajas();

    return 0;
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

void inicializarLista(){
    pilaCajas = NULL;
    tamanio = 0;
}

// INSERTAR NODOS

void insertarProducto(tProducto prod){

    if(pilaCajas == NULL){
        insertarPrimerNodo(prod);
    }else{
        apilar(prod);
    }

    tamanio ++;

}

void insertarPrimerNodo(tProducto prod){

    tPila * nuevoNodo;

    nuevoNodo = (tPila*) malloc(sizeof(tPila));

    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = NULL;

    pilaCajas = nuevoNodo;

    printf("\nPrimer elemento insertado\n\n");

}

void apilar(tProducto prod){

    tPila * nuevoNodo;
    tPila * aux;

    nuevoNodo = (tPila*)malloc(sizeof(tPila));
    aux = pilaCajas;

    while(aux->siguiente != NULL){
        aux = aux->siguiente;
    }

    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = NULL;

    aux->siguiente = nuevoNodo;

    printf("\nElemento insertado al final\n\n");

}

// ELIMINAR NODOS

void desapilar(){

    tPila * nodoAEliminar;
    tPila * aux;
    aux = pilaCajas;

    for(int i = 1; i < tamanio-1; i++){
        aux = aux->siguiente;
    }

    nodoAEliminar = aux->siguiente;
    aux->siguiente = NULL;
    free(nodoAEliminar);
    nodoAEliminar = NULL;

    tamanio--;

    printf("\nProducto desapilado\n");

}

// MOSTRAR LISTA

void mostrarCajas(){

    tPila * aux;
    tProducto producto;
    aux = pilaCajas;

    if(pilaCajas != NULL){
        
        printf(" Detalles de los Productos Insertados \n");

        while(aux != NULL){
            
            producto = aux->producto;

            printf("\t%d - %s $%.2f\n", producto.codProducto, producto.descripcion, producto.precioUnitario);

            aux = aux->siguiente;

        }
    }else{
        printf("No hay elementos en la lista\n");
    }

}
