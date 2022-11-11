// Escribir un programa que permita ingresar 10 valores reales por teclado. Luego escribir funciones que
// permitan:
// a) Ordenar un vector de menor a mayor por el método directo de burbuja.
// b) Ordenar un vector de menor a mayor por el método directo de selección.
// c) Ordenar un vector de menor a mayor por el método directo de inserción.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef int tVector[MAX];

tVector vector;

void generarVector();
void mostrarVector(tVector);
void ordenarBurbuja(tVector);
void seleccionDirecta(tVector);
void insercionDirecta(tVector);

int main(){
    
    generarVector();
    mostrarVector(vector);
    ordenarBurbuja(vector);
    seleccionDirecta(vector);
    insercionDirecta(vector);
    
    return 0;
}

void generarVector(){

    int i;

    srand(time(NULL));

    for(i = 0; i < MAX; i++){
        vector[i] = rand()%200;
    }

}

void mostrarVector(tVector vector){

    int i;

    for(i = 0; i < MAX; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");

}

// INTERCAMBIO
void ordenarBurbuja(tVector vector){
    
    int i;
    int j;
    int aux;

    for(i=0;i<MAX-1;i++) {
    
        for(j=0;j<MAX-1;j++) {
    
            if(vector[j] >= vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }


        }
    
    }
    
    mostrarVector(vector);
    printf("Elementos ordenados por BURBUJAAAAAAAAAA\n");

}

// SELECCION DIRECTA
void seleccionDirecta(tVector vector){

    int i, j, posMenor;
    int menor, aux;

    for (i = 0; i < MAX - 1; i++){
    
        menor = vector[i];
        posMenor = i;
        
        for(j = i+1; j < MAX; j++){
        
            if(vector[j] < menor){
                menor = vector[j];
                posMenor = j;
            }

        }

        if(posMenor != i){
            aux = vector[i];
            vector[i] = vector[posMenor];
            vector[posMenor] = aux;
        }
    
    }

    mostrarVector(vector);
    printf("Elementos ordenados por SELECCION DIRECTA PAPAAAA\n");

}

// BARAJA 
void insercionDirecta(tVector vector){

    int i, j;
    int aux;

    for(i = 1; i < MAX; i++){
    
        aux = vector[i];
        j = i - 1;

        while ((j >= 0) && (vector[j] > aux)){

            vector[j+1] = vector[j];
            j = j-1;

            mostrarVector(vector);

        }

        vector[j+1] = aux;

    }

    mostrarVector(vector);
    printf("Elementos ordenados por BARAJINHA\n");

}
