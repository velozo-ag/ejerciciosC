 	/* Grafo NO ponderado */
#include <stdio.h>
#include <stdbool.h>
#define N 7

// definition of types
typedef int tVertice;

// record definition
typedef struct {
	tVertice origen;
	tVertice destino;
}tArco;

// definition of types
typedef bool conjVertices [N];
typedef bool conjArcos [N][N];

// record definition
typedef struct {
	conjVertices vertices;
	conjArcos arcos;
}tGrafo;

// variables
tGrafo grafo;
tArco arco;

// prototypes
void inicializarGrafo (tGrafo *);
void agregarVertice (tGrafo *, tVertice);
void agregarArco (tGrafo *, tArco);
void eliminarVertice (tGrafo *, tVertice);
void eliminarArco (tGrafo *, tArco);

int maximoVertice (tGrafo);
void visualizarMatriz (tGrafo);
bool existeVertice (tGrafo, int);

void menu ();

//main block
int main () {
	inicializarGrafo (&grafo);
	menu ();
	
	return 0;
}	

void inicializarGrafo (tGrafo * pGrafo) {
	int x, y;
	
	for (x = 0; x < N; x++) {
		pGrafo -> vertices [x] = 0;
		
		for (y = 0; y < N; y++) {
			pGrafo -> arcos [x][y] = 0;
		}
	}
}

void agregarVertice (tGrafo * pGrafo, tVertice pVertice) {
	pGrafo -> vertices [pVertice] = 1;	// activa el vertice
	printf ("Se agrego el vertice %d\n", pVertice);
}
 	
void agregarArco (tGrafo * pGrafo, tArco pArco) {
	if (pGrafo -> vertices [pArco.origen] == 1 && pGrafo -> vertices [pArco.destino] == 1) {
		pGrafo -> arcos [pArco.origen][pArco.destino] = 1;	// crea el arco
		printf ("Se agrego el arco (%d, %d)\n", pArco.origen, pArco.destino);
	}
}	
 	
void eliminarVertice (tGrafo * pGrafo, tVertice pVertice) {
	if (pGrafo -> vertices [pVertice] != 0) {
		pGrafo -> vertices [pVertice] = 0;
		printf ("Se desactivo el vertice\n");
	}
	else {
		printf ("No se encuentra activo\n");
	}
}	

void eliminarArco (tGrafo * pGrafo, tArco pArco) {
	if (pGrafo -> arcos [pArco.origen][pArco.destino] != 0) {
		pGrafo -> arcos [pArco.origen][pArco.destino] = 0;
		printf ("Arco eliminado\n");
	}
	else {
		printf ("No existe el arco\n");
	}
}
 	
int maximoVertice (tGrafo pGrafo) {
	int i, max;
	max = 0;
	
	for (i = 0; i < N; i++) {
		if (pGrafo.vertices[i] == 1) {
			max = i;
		}
	}
	
	return max;
} 	
 	
bool existeVertice (tGrafo pGrafo, int pVertice) {
	return (pGrafo.vertices [pVertice] != 0);
} 	
 	
void visualizarMatriz (tGrafo pGrafo) {
	int i, j, maxVertice;
	maxVertice = maximoVertice (pGrafo);
	
	for (i = 1; i <= maxVertice; i++) {
		for (j = 1; j <= maxVertice; j++) {
			if (pGrafo.arcos[i][j] == true && existeVertice (pGrafo, i) && existeVertice (pGrafo, j)) {
				printf ("1");
			}
			else {
				printf ("0");
			}
			printf (" ");
		}
		printf ("\n");
	}
} 	
 	
void menu () {
	int opcion;
	tVertice agregarVer;
	tVertice eliminarVer;
	
	tArco agregarArc;
	tArco eliminarArc;
	
	printf ("Seleccione que operacion desea realizar\n\n");
	printf ("1. Agregar vertice\n");
	printf ("2. Agregar arco\n");
	printf ("3. Eliminar vertice\n");
	printf ("4. Eliminar arco\n");
	printf ("5. Visualizar matriz de adyacencia\n");
	
	printf ("Opcion: ");
	scanf ("%d", &opcion);
	
	switch (opcion) {
		case 1:
			printf ("Indique que vertice desea agregar: ");
			scanf ("%d", &agregarVer);
			agregarVertice (&grafo, agregarVer);
			printf ("\n");
			menu ();
			break;
		case 2:
			printf ("Ingrese el origen del arco: ");
			scanf ("%d", &agregarArc.origen);
			printf ("Ingrese el destino del arco: ");
			scanf ("%d", &agregarArc.destino);
			agregarArco (&grafo, agregarArc);
			printf ("\n");
			menu ();
			break;
		case 3:
			printf ("Que vertice desea eliminar?: ");
			scanf ("%d", &eliminarVer);
			eliminarVertice (&grafo, eliminarVer);
			printf ("\n");
			menu ();
			break;
		case 4:
			printf ("Ingrese el origen del arco: ");
			scanf ("%d", &eliminarArc.origen);
			printf ("Ingrese el destino del arco: ");
			scanf ("%d", &eliminarArc.destino);
			eliminarArco (&grafo, eliminarArc);
			printf ("\n");
			menu ();
			break;
		case 5:
			visualizarMatriz (grafo);
			printf ("\n");
			menu ();
			break;
	}
}	
 	
 	
 	
 	
 	
 	
 	
 	
 	