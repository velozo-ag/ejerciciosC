#include <stdio.h>
#define MAX 10

//Variables Globales
int vector[MAX]; //= {0,0,0,0,0,0,0,0,0,0};


//Prototipo de Funciones
void cargarDatos();
void ordenarSeleccion(int [],int);
void visualizarVector(int [],int);
void busquedaBinaria(int [],int);

//Funcion Principal
int main() {
    cargarDatos();
    visualizarVector(vector,MAX);
    ordenarSeleccion(vector,MAX);
    visualizarVector(vector,MAX);
    busquedaBinaria(vector,MAX);
    return 0;
}

//Implementacion
void cargarDatos() {
    int i;
    for(i=0;i<MAX;i++){
        printf("Ingrese un numero entero: ");
        scanf("%d",&vector[i]);
    }
}

void ordenarSeleccion(int pVector[], int pDim){
	int i, j, posMenor;
	int valMenor, aux;
	for (i = 0; i < pDim-1; i++) { 	
		valMenor = pVector[i];
		posMenor = i;
		for (j = i+1; j < pDim; j++) { 
			if (pVector[j] < valMenor){
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if (posMenor != i) {
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}
	}
    printf("Elementos ordenados\n");
}

void visualizarVector(int pVector[],int pDim){
    int i;
    for(i=0;i<pDim;i++) {
        printf("\t %d ",pVector[i]);
    }
    printf("\n");
}


void busquedaBinaria(int pVector[], int pDim) {
    int aux;
    int pos;
    int inferior, superior, mitad;
    int dato = -1;
    printf("Ingrese el elemento a buscar en el vector: ");
    scanf("%d",&aux);
    inferior = 0;
    superior = pDim;
    while(inferior <= superior) {
        mitad = (inferior + superior) / 2;
        if(pVector[mitad] == aux){
            dato = 1;
            pos = mitad;
            break;
        }
        if(pVector[mitad] > aux){
            superior = mitad;
            mitad = (inferior + superior) / 2;
        }
        if(pVector[mitad] < aux) {
            inferior = mitad;
            mitad = (inferior + superior) / 2;
        }
    }   
    printf("%d\n",dato);
}

