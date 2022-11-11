#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

//Definicio de Tipos
typedef int tVector[MAX];

//Variables Globales
tVector vectorEnteros = {0,0,0,0,0,0,0,0,0,0};

//Prototipo de Funciones
void generarVector();
void visualizarVector(tVector,int);
void ordenarShell(tVector,int);
void ordenarQuickSort(int*, int*);
void intercambio(int*, int*);
void miniMenu();

//Funcion Principal
int main() {
    miniMenu();
    return 0;
}

//Implementacion
void miniMenu() {
    int respuesta = 0;
    printf("Ingrese el metodo para ordenar\n");
    printf("1. Metodo Shell\n");
    printf("2. Metodo QuickSort\n");
    printf("3. Salir: ");
    scanf("%d",&respuesta);

    switch (respuesta) {
        case 1:
            generarVector();
            visualizarVector(vectorEnteros,MAX);
            ordenarShell(vectorEnteros,MAX);
            visualizarVector(vectorEnteros,MAX);
            miniMenu();
        break;
        case 2:
            generarVector();
            visualizarVector(vectorEnteros,MAX);
            ordenarQuickSort(&vectorEnteros[0],&vectorEnteros[MAX-1]);
            visualizarVector(vectorEnteros,MAX);
            miniMenu();
        break;
        default: 
            printf("Programa finalizado!\n");
        break;
    }
}

void generarVector() {
    int i;
    srand(time(NULL));
    for(i=0;i<MAX;i++){
        vectorEnteros[i] = (rand() % 11);
    }
}

void visualizarVector(tVector pVector, int pDim) {
    int i;
    printf("\n\t\t *** Vector Desordenado ***\n");
    for(i=0;i<pDim;i++) {
        printf("\t %d ",pVector[i]);
    }
    printf("\n\n");
}

void ordenarShell(tVector pVector, int pDim){
    int mitad = (pDim / 2);
    int i, j, k, aux;
    while(mitad > 0){
        for(i=mitad;i<pDim;i++) {
            j = i - mitad;
            while(j >= 0) {
                k = j + mitad;
                if(pVector[j] <= pVector[k]){
                    j--;
                } else {
                    aux = pVector[j];
                    pVector[j] = pVector[k];
                    pVector[k] = aux;
                    j = j - mitad;
                }
            }
        }
        mitad = mitad / 2;
    }
}

//Quicksort Recursivo
void ordenarQuickSort(int * izq, int * der) {
    if(der < izq) {
        return;
    }
    int pivote = *izq;
    int * ult = der;
    int * pri = izq;
    while(*izq < *der) {
        while (*izq >= pivote && izq > der + 1){
            izq++;
        }
        while(*der <= pivote && der < izq-1){
            der--;
        }
        if(*izq < *der) {
            intercambio(izq, der);
        }
    }
    ordenarQuickSort(pri, der-1);
    ordenarQuickSort(izq+1,ult);
}

void intercambio(int * a, int * b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}