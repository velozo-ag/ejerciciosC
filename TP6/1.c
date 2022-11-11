#include <stdio.h>
#define MAX 10

//Variables Globales
float vector[MAX]; 

//Prototipo de Funciones
void ordenarBurbuja(float[], int);
void ordenarSeleccion(float[],int);
void ordenarInsercion(float[], int);
void cargarDatos();
void menu();
void menuOpciones(int);
void visualizarVector(float[], int);

//Funcion Principal
int main() {
    menu();
    return 0;
}

//Implementacion
void menu(){
    int respuesta = 0;
    printf("\n***MENU***\n");
    printf("1 - Ordenar por metodo de Burbuja\n");
    printf("2 - Ordenar por metodo de Seleccion\n");
    printf("3 - Ordenar por metodo de Insercion\n");
    printf("4 - Salir: ");
    scanf("%d",&respuesta);
    menuOpciones(respuesta);
}

void menuOpciones(int pRespuesta){
    switch(pRespuesta){
        case 1:
            cargarDatos();
            visualizarVector(vector,MAX);
            ordenarBurbuja(vector,MAX);
            menu();
        break;
        case 2:
            cargarDatos();
            visualizarVector(vector,MAX);
            ordenarSeleccion(vector,MAX);
            menu();
        break;
        case 3:
            cargarDatos();
            visualizarVector(vector,MAX);
            ordenarInsercion(vector,MAX);
            menu();
        break;
        default:
            printf("Programa finalizado!\n");
        break;
    }
}


void cargarDatos(){
    int i;
    for(i=0;i<MAX;i++) {
        printf("Ingrese un numeor real: ");
        scanf("%f",&vector[i]);
    }
}

void visualizarVector(float pVector[], int pDim){
    int i;
    for(i=0;i<pDim;i++) {
        printf("\t%.2f ",pVector[i]);
    }
    printf("\n");
}

void ordenarBurbuja(float pVector[], int pDim){
    int i;
    int j;
    float aux;

    for(i=0;i<pDim;i++) {
    
        for(j=0;j<pDim-i;j++) {
    
            if(pVector[j] >= pVector[j+1]){
                aux = pVector[j];
                pVector[j] = pVector[j+1];
                pVector[j+1] = aux;
            }
    
        }
    
    }
    
    printf("Elementos ordenados\n");
    visualizarVector(vector,MAX);
}

void ordenarInsercion(float pVector[], int pDim) {
    int i;
    int j;
    float aux;

    for(i = 1;i < pDim;i++){
    
        j = i - 1;
    
        aux = pVector[i];
    
        while(j > 0 && aux < pVector[j]) {
            pVector[j+1] = pVector[j];
            j--;
        }
    
        pVector[j+1] = aux;
    
    }
    
    printf("Elementos ordenados\n");
    visualizarVector(vector,MAX);
}

void ordenarSeleccion(float pVector[], int pDim){
	int i, j, posMenor;
	float valMenor, aux;
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
    visualizarVector(vector,MAX);
}
