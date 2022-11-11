// Escribir una función que permita encontrar un valor en un arreglo de números reales, según el método de
// búsqueda binaria. La función debe devolver true en el caso que el elemento a buscar exista dentro del
// arreglo y false en caso contrario. Probar la función en el bloque principal de un programa C.

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef int tVector[MAX];

tVector vector = {1,3,5,6,8,9,13,16,19,21};

int busquedaBinaria(tVector,int);

int main(){

    printf("%d \n", busquedaBinaria(vector,19));

    return 0;
}

int busquedaBinaria(tVector vector, int elemento){

    	
	int final, comienzo;
	int medio;
	bool encontrado;

	final = MAX -1;
	comienzo = 0;
	encontrado = false;

	while((!encontrado) && (final >= comienzo)){

		medio = (final + comienzo)/2;

		if(vector[medio] == elemento){
			encontrado = true;
		}else{
			if(elemento > vector[medio]){
				comienzo = medio +1;
			}else{
				final = medio -1;
			}
		}

	}

	if(encontrado){
		return medio;
	}else{
		return -1;
	}


}