#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int dato;
    struct nodo *siguiente;
} tElemento;

int main(){
	
	tElemento *lista;
	
	lista = (tElemento*)malloc(sizeof(tElemento));
	
	lista->dato = 1; 
	
	printf("%d\n", lista->dato);
	printf("%p\n", lista->siguiente);
	
	if(lista->siguiente != NULL){
		printf("hola");
	}
	
//	------------------------------------------------
	
	int *punteroAEntero;
	
	punteroAEntero = malloc(sizeof(int));
	
	*punteroAEntero = 1234;

	printf("%d\n", *punteroAEntero);

    return 0;
}



