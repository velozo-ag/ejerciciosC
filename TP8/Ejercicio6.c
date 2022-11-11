#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct nodoArbol{
    int elemento;
    struct nodoArbol * hijoIzq;
    struct nodoArbol * hijoDer;
}tArbol;

tArbol * arbol;
int cantElementos;

void inicializarArbol(tArbol*);
bool esArbolVacio(tArbol*);

void recorrerEnPreorden(tArbol*);
void recorrerEnPosorden(tArbol*);
void recorrerEnInorden(tArbol*);

void insertarNodo(tArbol **, int);
void eliminarNodo(tArbol **, int);

tArbol * buscarMin(tArbol*);

int main(){

    return 0;
}

void inicializarArbol(tArbol * arbol){
    arbol = NULL;
}

bool esArbolVacio(tArbol * arbol){
    return (arbol == NULL);
}

void recorrerEnPreorden(tArbol * arbol){
    if(arbol != NULL){
        printf("%d \n", arbol->elemento);
        recorrerEnPreorden(arbol->hijoIzq);
        recorrerEnPreorden(arbol->hijoDer);
    }
}

void recorrerEnPosorden(tArbol * arbol){
    if(arbol != NULL){
        recorrerEnPosorden(arbol->hijoIzq);
        recorrerEnPosorden(arbol->hijoDer);
        printf("%d\n", arbol->elemento);
    }
}

void recorrerEnInorden(tArbol * arbol){
    if(arbol != NULL){
        recorrerEnInorden(arbol->hijoIzq);
        printf("%d\n", arbol->elemento);
        recorrerEnInorden(arbol->hijoDer);
    }
}

void insertarNodo(tArbol ** arbol, int dato){
    if(esArbolVacio(*arbol)){
        arbol = malloc(sizeof(tArbol));

        if(!esArbolVacio(*arbol)){
            (*arbol)->elemento = dato;
            (*arbol)->hijoIzq = NULL;
            (*arbol)->hijoDer = NULL;
        }else{
            if(dato < (*arbol)->elemento){
                insertarNodo(&(*arbol)->hijoIzq,dato);
            }else{
                if(dato > (*arbol)->elemento){
                    insertarNodo(&(*arbol)->hijoDer,dato);
                }else{
                    pritnf("Dato duplicado\n");
                }
            }
        }
    }
}

void eliminarNodo(tArbol ** arbol, int dato){

    tArbol * aux;

    if(esArbolVacio(*arbol)){
        printf("Elemento no encontrado\n");
    }else{
        if(dato < (*arbol)->elemento){
            eliminarNodo(&(*arbol)->hijoIzq, dato);
        }else{
            if(dato > (*arbol)->elemento){
                eliminarNodo(&(*arbol)->hijoDer, dato);
            }else{

                // Encontramos el elemento a eliminar
                if((*arbol)->hijoIzq == NULL){
                    aux = *arbol;
                    arbol = (*arbol)->hijoDer;
                    free(aux);
                }else{
                    if((*arbol)->hijoDer == NULL){
                        aux = *arbol;
                        *arbol = (*arbol)->hijoIzq;
                        free(aux);
                    }else{
                        aux = buscarMin((*arbol)->hijoDer);
                        (*arbol)->elemento = aux->elemento;
                        eliminarNodo(&((*arbol)->hijoDer),(*arbol)->elemento);
                    }
                }

            }
        }
    }

}

tArbol * buscarMin(tArbol * arbol){
    if(esArbolVacio(arbol)){
        return NULL;
    }else{
        if(esArbolVacio(arbol->hijoIzq)){
            return arbol;
        }else{
            return (buscarMin(arbol->hijoIzq));
        }
    }
}