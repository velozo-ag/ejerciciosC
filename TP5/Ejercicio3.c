// Escribir un programa que permita ingresar por teclado la cantidad de elementos de un vector, y cada uno
// de los valores de los elementos del vector. Además, escribir funciones para obtener:
// a) el máximo valor almacenado en el vector
// b) el mínimo valor almacenado en el vector
// c) la media de todos los valores
// d) la semisuma (promedio entre el máximo y mínimo).

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int tVector[MAX];

tVector vector = {1,3,5,6,8,9,13,16,19,21};

int valorMinimo(tVector);
int valorMinimoIndice(tVector);
int valorMaximo(tVector);
int calcularMedia(tVector);
int calcularSemisuma(tVector);

int main(){

    printf("%d\n", valorMinimo(vector));
    printf("%d\n", valorMinimoIndice(vector));
    printf("%d\n", valorMaximo(vector));
    printf("%d\n", calcularMedia(vector));
    printf("%d\n", calcularSemisuma(vector));

    return 0;
}

int valorMinimo(tVector vector){

    int i;
    int minimo = 999;

    for(i = 0; i < MAX; i++){
        if(vector[i] < minimo){
            minimo = vector[i];
        }
    }

    return minimo;

}

int valorMinimoIndice(tVector vector){
    int i;
    int minimo = 0;

    for(i = 0; i < MAX; i++){
        if(vector[i] < vector[minimo]){
            minimo = i;
        }
    }

    return minimo;

}

int valorMaximo(tVector vector){

    int i;
    int maximo = 0;

    for(i = 0; i < MAX; i++){

        if(vector[i] > vector[maximo]){
            maximo = i;
        }

    }

    return vector[maximo];

}

int calcularMedia(tVector vector){

    int i;
    int media = 0;

    for(i = 0; i < MAX; i++){
        media += vector[i];
    }

    media /= MAX;

    return media;

}

int calcularSemisuma(tVector vector){

    return (valorMinimo(vector) + valorMaximo(vector)) / 2;

}