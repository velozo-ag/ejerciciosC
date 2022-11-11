// Escribir un programa que permita determinar si un número entero ingresado por teclado, existe en un
// vector. Para ello será necesario, disponer de lo siguiente:
// a) Una función que permita cargar elementos en un vector de números enteros.
// b) Una función que permita visualizar los elementos almacenados en el vector.
// c) Una función que devuelva verdadero en el caso que el elemento a buscar exista en el vector, y falso
// en caso contrario.

#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int vector[MAX];

void cargarVector();
void visualizarVector();
bool buscarValor(int);

int main(){

    int valor;

    cargarVector();
    visualizarVector();
    
    printf("Ingrese el valor a buscar: ");
    scanf("%d",&valor);
    printf("%d\n", buscarValor(valor));

    return 0;

}

void cargarVector(){

    int i;
    int valor;

    printf("Cargando los elementos...\n");

    for(i = 0; i < MAX; i++){

        scanf("%d", &valor);
        vector[i] = valor;

    }

    printf("Elementos cargados \n\n");

}

void visualizarVector(){

    int i;

    for(i = 0; i < MAX; i++){

        printf("%d ", vector[i]);

    }

    printf("\n");

}

bool buscarValor(int buscar){

    int i;
    bool encontrado;

    for(i = 0; i < MAX; i++){

        if(vector[i] == buscar){
            encontrado = true;
            return encontrado;
        }

    }

    return encontrado;

}