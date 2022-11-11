#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
} tArco; /* El arco es un par de vértices [ origen, destino ] */

typedef bool conjuntoVertices [N];  /* vector de vértices */
typedef bool conjuntoArcos [N][N];	/* matriz de arcos */

/* 	El grafo es una estructura compuesta por un conjunto de vértices
	y un conjunto de arcos o aristas */
typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoNoPonderado;

void inicializarGrafo( tGrafoNoPonderado * );
void agregarVertice( tGrafoNoPonderado *, tVertice );
void agregarArco( tGrafoNoPonderado *, tArco );
void borrarVertice( tGrafoNoPonderado *, tVertice );
void borrarArco( tGrafoNoPonderado *, tArco );
int maximoVertice( tGrafoNoPonderado );
void visualizarMatrizAdyacencia( tGrafoNoPonderado );
bool existeVertice( tGrafoNoPonderado, int ); 

tGrafoNoPonderado grafo;	
tArco arco;

int main() {			
	inicializarGrafo( &grafo );

	agregarVertice( &grafo, 1 );
	agregarVertice( &grafo, 2 );
	agregarVertice( &grafo, 3 );
	agregarVertice( &grafo, 4 );
	
	arco.origen = 1;
	arco.destino = 2;	
	agregarArco( &grafo, arco );
	
	arco.origen = 2;
	arco.destino = 3;	
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 3;	
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;	
	agregarArco( &grafo, arco );
	
	arco.origen = 4;
	arco.destino = 2;	
	agregarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
	
	// borrarVertice( &grafo, 3 ); 
	
	borrarArco( &grafo, arco );
			
	visualizarMatrizAdyacencia( grafo );
	
	return 0;
}

void inicializarGrafo( tGrafoNoPonderado * pGrafo ) {
	int x, y;
	
	for ( x = 0; x < N; x++ ) {
		// ( *pGrafo ).vertices[x] = 0;	
		pGrafo->vertices[x] = 0;
				
		for ( y = 0; y < N; y++ ) {
			pGrafo->arcos[x][y] = 0;
		}
	}
}

void agregarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	( *pGrafo ).vertices[pVertice] = 1;
	// pGrafo->vertices[vert] = 1;	
	printf( "Se agrego el vertice %d\n", pVertice );
}

void agregarArco( tGrafoNoPonderado * pGrafo, tArco pArco ) {
	if( ( pGrafo->vertices[pArco.origen] == 1 ) && ( pGrafo->vertices[pArco.destino] == 1 ) ) {
		// ( *pGrafo ).arcos[arc.origen][arc.destino] = 1;	
		pGrafo->arcos[pArco.origen][pArco.destino] = 1;	
		printf("Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino);
	}
}

void borrarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	if( pGrafo->vertices[pVertice]  != 0 ) {
		pGrafo->vertices[pVertice] = 0;
		printf( "\nSe desactivo el vertice %d\n", pVertice );
	} else {
		printf( "\nEl vertice que desea borrar no se encuentra activo\n" );
	}	
}

void borrarArco( tGrafoNoPonderado * pGrafo, tArco pArco ) {
	if( pGrafo->arcos[pArco.origen][pArco.destino]  != 0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0;
		printf( "\nSe elimino el arco ( %d, %d )\n", pArco.origen, pArco.destino );
	} else {
		printf( "\nEl arco que desea borrar no existe\n" );
	}	
}

int maximoVertice( tGrafoNoPonderado pGrafo ) {
	int i, max;
	max = 0;
	for (i = 0; i< N; i++) {
		if ( pGrafo.vertices[i] == 1 ) {
			max = i;
		}		
	}
	return max;
}

void visualizarMatrizAdyacencia( tGrafoNoPonderado pGrafo ) {	
	int i, j, maxVer;
	printf("\nMATRIZ DE ADYACENCIA\n\n");
	maxVer = maximoVertice( pGrafo );
	for (i = 1; i<= maxVer; i++) {
		for (j = 1; j<= maxVer; j++) {		
			if ( pGrafo.arcos[i][j] == true && existeVertice( pGrafo, i ) && existeVertice( pGrafo, j )) {
				printf("1");
			} else { printf("0"); }
			printf(" ");
		}	
		printf("\n");
	}
}

bool existeVertice( tGrafoNoPonderado pGrafo, int pVertice ) {
	return pGrafo.vertices[pVertice] != 0;
}


