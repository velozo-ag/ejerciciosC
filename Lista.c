#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tElemento{
    int *dato;
    struct tElemento *siguiente;
} tElemento;

typedef struct Lista{
	tElemento *inicio;
}  Lista;

Lista *lista;

tElemento *crearElemento();
void agregarElemento();
	void agregarAlPrincipio();
	void agregarAlFinal();
	void agregarLugarX(int);
void mostrarLista();

int main(){

	agregarAlPrincipio();
	agregarAlFinal();
	agregarLugarX(3);
	mostrarLista();

    return 0;
}

tElemento *crearElemento(){
	tElemento *Elemento = (tElemento*)malloc(sizeof(tElemento));
	int dato;

	printf("Ingrese un dato: \n > ");
	scanf("%d", &dato);

	Elemento->dato = &dato;
	Elemento->siguiente = NULL;

	return Elemento;
}

void agregarAlPrincipio(){
	tElemento *nuevoElemento = crearElemento();
	nuevoElemento->siguiente = lista->inicio;
	lista->inicio = nuevoElemento;
}

void agregarAlFinal(){
	tElemento *nuevoElemento = crearElemento();
	
	if(lista->inicio == NULL){
	
		lista->inicio = nuevoElemento;
	
	}else{

		tElemento *aux = lista->inicio;

		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}

		aux->siguiente = nuevoElemento;

	}

}

void agregarLugarX(int x){

	tElemento *nuevoElemento = crearElemento();
	tElemento *aux;
	int pos;

	if(lista->inicio == NULL){
		lista->inicio = nuevoElemento;
	}else{

		aux = lista->inicio;
		pos = 0;

		while(pos < x && aux->siguiente != NULL){
			aux = aux->siguiente;
			pos++;
		}

		nuevoElemento->siguiente = aux->siguiente;
		aux->siguiente = nuevoElemento;

	}

}

void mostrarLista(){

	tElemento *aux = lista->inicio;

	while(aux != NULL){
		printf("%d\n", aux->dato);
	}

}
