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
}tListaProductos;

// Definicion Lista Enlazada
tListaProductos *listaProductos;

// Prototipos
void inicializarLista();
tProducto crearProducto();

void insertarPrimerNodo(tProducto);
void insertarAlPrincipio(tProducto);
void insertarPosicionK(int,tProducto);

void eliminarPrimerProducto();
void eliminarPosicionK();

void mostrarProductos();
bool listaVacia();

// MAIN
int main(){

    inicializarLista();
    
    // insertarAlPrincipio(crearProducto());
    // insertarAlPrincipio(crearProducto());
    // insertarAlPrincipio(crearProducto());
    // insertarPosicionK(2,crearProducto());
    
    insertarPosicionK(1,crearProducto());
    insertarPosicionK(2,crearProducto());
    insertarPosicionK(3,crearProducto());
    insertarPosicionK(4,crearProducto());
    
    mostrarProductos();

    system("pause");
    system("cls");

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

// INSERTAR NODOS

void insertarPrimerNodo(tProducto prod){

    tListaProductos * nuevoNodo;

    nuevoNodo = (tListaProductos*) malloc(sizeof(tListaProductos));

    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = NULL;

    listaProductos = nuevoNodo;

    printf("Primer elemento insertado\n");

}

void insertarAlPrincipio(tProducto prod){

    if(listaProductos==NULL){
        insertarPrimerNodo(prod);
        return;
    }

    tListaProductos * nuevoNodo;

    nuevoNodo = (tListaProductos*) malloc(sizeof(tListaProductos));

    nuevoNodo->producto = prod;
    nuevoNodo->siguiente = listaProductos;
    
    listaProductos = nuevoNodo;

    printf("Producto insertado correctamente.\n");

}

void insertarPosicionK(int k, tProducto prod){

    if(listaProductos==NULL){
        insertarPrimerNodo(prod);
        return;
    }
    
    tListaProductos * nuevoNodo;
    tListaProductos * aux;

    nuevoNodo = (tListaProductos*)malloc(sizeof(tListaProductos));
    aux = listaProductos;
    
    for(int i = 1; i < k-1; i++){
        aux = aux->siguiente;
    }

    nuevoNodo->producto = prod;

    nuevoNodo->siguiente = aux->siguiente;
    aux->siguiente = nuevoNodo;

    printf("Producto insertado en la posicion %d \n", k);

}

// ELIMINAR NODOS

void eliminarPrimerProducto(){

    tListaProductos * nodoAEliminar;
    nodoAEliminar = listaProductos;

    listaProductos = listaProductos->siguiente;

    free(nodoAEliminar);
    nodoAEliminar = NULL;

    printf("Primer producto eliminado\n");

}

void eliminarPosicionK(int k){

    tListaProductos * nodoAEliminar;
    tListaProductos * aux;
    aux = listaProductos;

    for(int i = 1; i < k -1; i++){
        aux = aux->siguiente;
    }

    nodoAEliminar = aux->siguiente;
    aux->siguiente = nodoAEliminar->siguiente;


    free(nodoAEliminar);
    nodoAEliminar = NULL;

    printf("Producto de la posicion %d eliminado \n", k);

}

// MOSTRAR LISTA

void mostrarProductos(){

    tListaProductos * aux;
    tProducto producto;
    aux = listaProductos;

    if(!listaVacia()){
        
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

bool listaVacia(){
    return (listaProductos == NULL);
}
