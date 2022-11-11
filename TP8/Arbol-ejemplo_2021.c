/*Ejemplo de clase - AED 2 - 2021*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int tElem;

typedef struct nodoArbol {
	tElem contenido;			
    struct nodoArbol * hijoIzdo;    
    struct nodoArbol * hijoDcho;    
}tArbol;

tArbol * arbol;

void crearArbolVacio(tArbol *);
bool esArbolVacio(tArbol *);

tArbol * subIzquierdo(tArbol *);
tArbol * subDerecho(tArbol *);
int datoRaiz(tArbol *);

void recorrerEnPreorden(tArbol *);
void recorrerEnInorden(tArbol *);
void recorrerEnPostorden(tArbol *);

void insertar(tArbol **, tElem);
void eliminar(tArbol **, tElem);

tArbol * buscar_min(tArbol *);

bool buscar(tArbol *, tElem);
void buscar2(tArbol *, tElem);

int contarEnInorden1(tArbol *);

int main() {	
	int bandera = 1;
	int dato;
	crearArbolVacio(arbol);	
	printf("*** Carga inicial de nodos al arbol ***\n ");
	do {
		printf("Ingrese el nuevo nodo del arbol: ");
		scanf ("%d", &dato);
		insertar(&arbol, dato);
		printf("Desea ingresar otro nodo? (1- Si, 0- No)  ");
		scanf ("%d", &bandera);
	} while (bandera == 1);
	
	menu(); //Opciones del menu


	return 0;
}

void menu (){ //Menu recursivo
	int opcion, dato; 
	int cant = 0;
	printf("\n\nIngrese la accion que desea realizar: \n");
	printf("1 - Ingrese nuevo nodo \n");
	printf("2 - Eliminar un nodo \n");
	printf("3 - Buscar nodo \n");
	printf("4 - Mostrar preorden \n");
	printf("5 - Mostrar inorden \n");
	printf("6 - Mostrar postorden \n");
	printf("7 - Contar nodos \n");
	printf("8 - Mostrar raiz \n");
	printf("9 - Mostrar hijos izquierdo y derecho \n");
	printf("Otro numero- Salir \n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: {
			printf("Ingrese el nuevo nodo del arbol: ");
			scanf ("%d", &dato);
			insertar(&arbol, dato);
			menu();
			break;
		}
		case 2: {
			printf("Ingrese el valor del nodo a eliminar: ");
			scanf ("%d", &dato);
			eliminar(&arbol, dato);
			menu();
			break;
		}
		case 3: {
			printf("Ingrese el valor del nodo que desea buscar: ");
			scanf ("%d", &dato);
			printf("\nExiste el valor %d? %s\n", dato, buscar(arbol, dato) ? "si" : "no");
			menu();
			break;
		}
		case 4: {
			printf("\nPreOrden: \n");
			recorrerEnPreorden(arbol);
			printf("\n");
			menu();
			break;
		}
		case 5: {
			printf("\nInOrden: \n");
			recorrerEnInorden(arbol);
			printf("\n");
			menu();
			break;
		}
		case 6: {
			printf("\nPostOrden: \n");
			recorrerEnPostorden(arbol);
			printf("\n");
			menu();
			break;
		}
		case 7: {
			printf("\nTotal de nodos del arbol (version 1): %d \n", contarEnInorden1(arbol));
			menu();
			break;
		}
		case 8: {
			printf("\nDato raiz: %d\n", datoRaiz(arbol));
			menu();
			break;
		}
		case 9: {
			printf("SubIzquierdo: %d\n", subIzquierdo(arbol)->contenido);
			printf("SubDerecho: %d\n", subDerecho(arbol)->contenido);
			menu();
			break;
		} default: {
			printf("Fin programa ...\n");
		} 
	}
}
void crearArbolVacio(tArbol * pArbol) {
	pArbol = NULL;		
}

bool esArbolVacio(tArbol * pArbol) {
	return pArbol == NULL;
}

//Funci�n que devuelve el Nodo Izquierdo
tArbol * subIzquierdo(tArbol * pArbol) {
	return pArbol->hijoIzdo;
}

//Funci�n que devuelve el Nodo Derecho
tArbol * subDerecho(tArbol * pArbol) {
	return pArbol->hijoDcho;
}

tElem datoRaiz(tArbol * pArbol) {
	return pArbol->contenido;	
}

/* 	Primero se lee el valor del nodo y 
	despu�s se recorren los sub-�rboles */
void recorrerEnPreorden(tArbol * pArbol) {
	if (pArbol != NULL) {
		printf("%d ", pArbol->contenido);
		recorrerEnPreorden(pArbol->hijoIzdo);
		recorrerEnPreorden(pArbol->hijoDcho);
	}
}

/* 	Primero se recorre el sub-�rbol izquierdo
	luego se lee el valor del nodo y, 
	finalmente se recorre el sub-�rbol derecho */
void recorrerEnInorden(tArbol * pArbol) {
	if (pArbol != NULL) {		
		recorrerEnInorden(pArbol->hijoIzdo);
		printf("%d ", pArbol->contenido);
		recorrerEnInorden(pArbol->hijoDcho);
	}
}

/*	Se visitan primero los sub-�rboles izquierdo y derecho y 
	despu�s se lee el valor del nodo */
void recorrerEnPostorden(tArbol * pArbol) {
	if (pArbol != NULL) {		
		recorrerEnPostorden(pArbol->hijoIzdo);		
		recorrerEnPostorden(pArbol->hijoDcho);		    	
		printf("%d ", pArbol->contenido);			
	}
}

void insertar(tArbol ** pArbol, int pDato) { 
	if (esArbolVacio(*pArbol)) { 
		(*pArbol) = malloc(sizeof(tArbol));		
		/* si la memoria est� asignada, entonces asigna el dato */
		if ((*pArbol) != NULL) { 
			(*pArbol)->contenido = pDato;
			(*pArbol)->hijoIzdo = NULL;
			(*pArbol)->hijoDcho = NULL;
		} else { printf("No hay memoria disponible!\n", pDato); } 
	} else {		
		if (pDato < (*pArbol)->contenido) {
			insertar(&((*pArbol)->hijoIzdo), pDato);
		} else {
				if (pDato > (*pArbol)->contenido) {
					insertar(&((*pArbol)->hijoDcho), pDato);
				} else { printf("Valor duplicado!\n"); }
		} 	
	}
}

void eliminar(tArbol ** pArbol, int elem) {
	tArbol * aux;

	if (esArbolVacio(*pArbol)) {
		printf("Elemento no encontrado! \n");   // No existe el nodo
	} else {
		if (elem < (*pArbol)->contenido) { // seguir por la izquierda
			eliminar(&((*pArbol)->hijoIzdo), elem);	
		} else {
			if (elem > (*pArbol)->contenido) { // seguir por la derecha
				eliminar(&((*pArbol)->hijoDcho), elem);
			} else { 
					/* 	encontramos el nodo a eliminar, 
						antes de eliminar el nodo, se debe buscar el elemento 
						que se debe re-enlazar para quitar el elemento buscado */
					if ((*pArbol)->hijoIzdo == NULL) { // solo tiene un hijo derecho
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoDcho;
						free(aux);
				} else {
					if ((*pArbol)->hijoDcho == NULL) { // solo tiene un hijo izquierdo
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzdo;
						free(aux);
					}
					else { // entonces tiene 2 hijos, se reemplaza con el menor del subarbol derecho
						aux = buscar_min((*pArbol)->hijoDcho);
						(*pArbol)->contenido = aux->contenido;					
						eliminar(&((*pArbol)->hijoDcho), (*pArbol)->contenido);													
					}
				}
			}
		}
	}
}

// Devuelve el nodo del elemento menor
tArbol * buscar_min(tArbol * pArbol) {
	if (esArbolVacio(pArbol)){
		return NULL;
	} else {
		if (esArbolVacio(pArbol->hijoIzdo)) {
			return pArbol;
		} else {
			return buscar_min(pArbol->hijoIzdo);
		}
	}	
}

bool buscar(tArbol * pArbol ,int pDato) {
	/* 	Devuelve un puntero al nodo con dato, si el dato est� en arbol, 
		o null en otro caso */
	if (esArbolVacio(pArbol)) {
		return false;
	} else {
		if (pDato < pArbol->contenido) {
			return buscar(pArbol->hijoIzdo, pDato);
		} else {
			if (pDato > pArbol->contenido) {
				return buscar(pArbol->hijoDcho, pDato);	
			} else { return true; }	
		}		
	}			
}

void buscar2(tArbol * pArbol ,int pDato) {
	/* Devuelve la respuesta afirmativa, si el dato est� en arbol, 
		o mensaje correspondiente en otro caso */
	if (pArbol == NULL) {
		printf("No existe el elemento!\n");
	} else {
		if (pDato < pArbol->contenido) {
			buscar2(pArbol->hijoIzdo, pDato);
		} else {
			if (pDato > pArbol->contenido) {
					buscar2(pArbol->hijoDcho, pDato);
			} else { printf("Si!\n"); }
		}			
	}		
}

int contarEnInorden1(tArbol * pArbol) { 
	if (!esArbolVacio(pArbol)) {		
		return contarEnInorden1(pArbol->hijoIzdo) + 1 + contarEnInorden1(pArbol->hijoDcho);
	} 
}


