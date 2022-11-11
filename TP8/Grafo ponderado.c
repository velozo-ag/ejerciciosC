#include <stdio.h>
#include <stdbool.h>
#define N 10

// definition of types
typedef int tVertice;
typedef int tPeso;

// record definition
typedef struct {
	tVertice origen;
	tVertice destino;
	tPeso peso;
}tArco;

// definition of types
typedef bool conjVertices[N];
typedef tPeso conjArcos[N][N];

// structure definition
typedef struct {
	conjVertices vertices;
	conjArcos arcos;
}tGrafo;

// variables
tArco arco;
tGrafo grafo;

// prototypes
void inicializarGrafo (tGrafo *);

void agregarVertice (tGrafo *, tVertice);
void agregarArco (tGrafo *, tArco);

void eliminarVertice (tGrafo *, tVertice);
void eliminarArco (tGrafo *, tArco);

int maxVertice (tGrafo);
bool existeVertice (tGrafo, int);
void visualizarMatrizPesos (tGrafo);

void menu ();

// main block
int main () {
	inicializarGrafo (&grafo);
	menu ();
	return 0;
}

// implementation
void inicializarGrafo (tGrafo * pGrafo) {
	int x, y;
	
	for (x = 0; x < N; x ++) {
		pGrafo -> vertices[x] = 0;
		
		for (y = 0; y < N; y ++) {
			pGrafo -> arcos[x][y] = 0;
		}
	}
	printf ("Grafo inicializado!\n\n");
}

void agregarVertice (tGrafo * pGrafo, tVertice pVertice) {
	pGrafo -> vertices [pVertice] = 1;
	printf ("Vertice activado\n");
}

void agregarArco (tGrafo * pGrafo, tArco pArco) {
	if (pGrafo -> vertices [pArco.origen] == 1 && pGrafo -> vertices [pArco.destino] == 1) {
		pGrafo -> arcos[pArco.origen][pArco.destino] = pArco.peso;
		
		printf ("Arco (%d, %d) agregado\n", pArco.origen, pArco.destino);
	}
}

void eliminarVertice (tGrafo * pGrafo, tVertice pVertice) {
	if (pGrafo -> vertices [pVertice] != 0) {
		pGrafo -> vertices [pVertice] = 0;
		printf ("Vertice eliminado\n");
	}
	else {
		printf ("Error: el vertice se encuentra inactivo\n");
	}
}

void eliminarArco (tGrafo * pGrafo, tArco pArco) {
	if (pGrafo -> arcos [pArco.origen][pArco.destino] != 0) {
		pGrafo -> arcos [pArco.origen][pArco.destino] = 0;
		printf ("Arco eliminado\n");
	}
	else {
		printf ("Error: no existe el arco\n");
	}
}

int maxVertice (tGrafo pGrafo) {
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
	return (pGrafo.vertices [pVertice]);
}

void visualizarMatrizPesos (tGrafo pGrafo) {
	int x, y, mayor;
	mayor = maxVertice (pGrafo);
	
	printf ("***Matriz de pesos***\n");
	for (x = 1; x <= mayor; x++) {
		for (y = 1; y <= mayor; y++) {
			if (pGrafo.arcos[x][y] != 0 && existeVertice (pGrafo, x) && existeVertice (pGrafo, y)) {
				printf ("%d", pGrafo.arcos[x][y]);
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
	tVertice agregarV;
	tVertice eliminarV;
	tArco agregarA;
	tArco eliminarA;
	
	printf ("Seleccione la operacion que desea realizar:\n\n");
	printf ("1. Agregar vertice\n");
	printf ("2. Agregar arco\n");
	printf ("3. Eliminar vertice\n");
	printf ("4. Eliminar arco\n");
	printf ("5. Visualizar pesos\n");
	
	printf("Opcion: ");
	scanf ("%d", &opcion);
	
	switch (opcion) {
		case 1:
			printf ("Ingrese el vertice: ");
			scanf ("%d", &agregarV);
			agregarVertice (&grafo, agregarV);
			printf ("\n");
			menu ();
			break;
		case 2:
			printf ("Ingrese el origen del arco: ");
			scanf ("%d", &agregarA.origen);
			printf ("Ingrese el destino del arco: ");
			scanf ("%d", &agregarA.destino);
			printf ("Ingrese el peso: ");
			scanf ("%d", &agregarA.peso);
			agregarArco (&grafo, agregarA);
			printf ("\n");
			menu ();
			break;
		case 3:
			printf ("Vertice a eliminar: ");
			scanf ("%d", &eliminarV);
			eliminarVertice (&grafo, eliminarV);
			printf ("\n");
			menu ();
			break;
		case 4:
			printf ("Origen del arco: ");
			scanf ("%d", &eliminarA.origen);
			printf ("Destino del arco: ");
			scanf ("%d", &eliminarA.destino);
			eliminarArco (&grafo, eliminarA);
			printf ("\n");
			menu ();
			break;
		case 5:
			visualizarMatrizPesos (grafo);
			printf ("\n");
			menu ();
			break;
	}
}
































