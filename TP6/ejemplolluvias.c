/*Ejemplo de cátedra - AED 2 - 2021*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ordenamientoEnteros.h"
#define MAX 270

int vector1[MAX];
int vector2[MAX];
int vector3[MAX];
int vector4[MAX];

void generarVector(int[], int);
void verVector(int[], int);

int main(){
	int i;
	generarVector(vector1, MAX);
	for (i=0; i<MAX; i++){
        vector2[i] = vector1[i];
        vector3[i] = vector1[i];
        vector4[i] = vector1[i];
    }	
	printf("\nMilimetros registrados en los últimos 9 meses:");
	verVector(vector1, MAX);
	
	seleccionDirecta(vector1, MAX);
	printf("\n\nPrecipitaciones en milimetros de los ultimos 9 meses (ordenado ascendentemente por seleccion de menores):");
	verVector(vector1, MAX);
	
	insercionDirecta(vector2, MAX);
	printf("\n\nPrecipitaciones en milimetros de los ultimos 9 meses (ordenado ascendentemente por baraja):");
	verVector(vector2, MAX);
	
	ordenacionPorIntercambio(vector3, MAX);
	printf("\n\nPrecipitaciones en milimetros de los ultimos 9 meses (ordenado ascendentemente por burbuja):");
	verVector(vector3, MAX);
	
	ordenacionBurbujaMejorada(vector4, MAX);
	printf("\n\nPrecipitaciones en milimetros de los ultimos 9 meses (ordenado ascendentemente por burbuja mejorada):");
	verVector(vector4, MAX);
	
	
	
}

void generarVector(int pVector[], int pDim){
	int i;
	/*for (i = 0; i < pDim; i++)	{
		printf("Ingrese la cantidad de milimetros que se precipitaron en la provincia en el día %d: ", i+1);
		scanf("%f", &pVector[i]); fflush(stdin);
	}*/
	srand(time(NULL));
    for (i=0; i<pDim; i++){
        pVector[i]=rand()%200;
    }
}

void verVector(int pVector[], int pDim){
	int i;
	printf("\nContenido del vector:\n");
	for (i = 0; i < pDim; i++)	{
		printf("%d\t", pVector[i]);
	}
}

