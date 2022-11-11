/*Ejercicio de clase*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5
typedef int tVectorInt [MAX];
int busquedaSecuencial(tVectorInt, int);
int busquedaSecuencialOrdenada(tVectorInt, int);
int busquedaBinaria(tVectorInt, int);
bool busquedaBinariaBool(tVectorInt, int);
int buscarMayor(tVectorInt);
int buscarMenor(tVectorInt);

void cargarVectorOrdenado();
void cargarVectorDesordenado();
void mostrarElementos();

tVectorInt v;

int main() {		
	cargarVectorDesordenado();
	mostrarElementos();
	printf("Posicion del elemento buscado segun busquedaSecuencial: %d\n\n", busquedaSecuencial(v, 50));
 	
 	cargarVectorOrdenado();
	mostrarElementos();
	printf("Posicion del elemento buscado segun busquedaSecuencialOrdenada: %d\n", busquedaSecuencialOrdenada(v, 40));
	printf("Posicion del elemento buscado segun busquedaBinaria: %d\n\n", busquedaBinaria(v, 30));
	if (busquedaBinariaBool(v, 50)){
		printf("Elemento encontrado\n\n");
	} else {
		printf("Elemento no encontrado\n\n");
	}
	cargarVectorDesordenado();
	mostrarElementos();
	printf("Posicion del mayor elemento segun supuesto o prepo: %d\n", buscarMayor(v));
	printf("Posicion del menor elemento segun supuesto o prepo: %d\n\n", buscarMenor(v));
	
 	return 0;
 }

void cargarVectorOrdenado() {
	v[0]= 10;
	v[1]= 20;
	v[2]= 30;
	v[3]= 40;
	v[4]= 50;	
}

void cargarVectorDesordenado() {
	int i;
	/*  la funci�n srand recibe como par�metro un n�mero que se utilizar� 
		como semilla del inicial para las cuentas de los n�meros aleatorios. 
		A esta funci�n s�lo debemos llamarla una vez en nuestro programa. */
	srand(time(NULL));
	for (i = 0; i<MAX; i++) {
		/*  numeros aleatorios entre M y N: 
			M + (N+1-M) � dicho de otra manera:
			limite_inferior + rand() % (limite_superior + 1 - limite_inferior)*/
		v[i] = 1 + rand() % (7); 
	}
}

void mostrarElementos() {
	int i;
	for (i=0; i<MAX; i++) {
 		printf("%d\t", v[i]);
 	}
 	printf("\n");
}

int busquedaSecuencial(tVectorInt p_v, int elem){
	int result = -1; // result se usar� para guardar la posici�n del valor encontrado � -1 en caso contrario
	int i = 0; // se inicia el contador
	while((p_v[i] != elem) && (i != MAX)){
		i = i + 1;	
	}	
	if(p_v[i] == elem){ 
		/* significa que se ha encontrado el elemento elem, 
			entonces se devuelve la posici�n del elemento en el vector */
		result = i;
	} else { 
		result = -1;
	}
	return result;
}

int busquedaSecuencialOrdenada(tVectorInt p_v, int elem) {	
	/* Pre-Condicion: p_v ordenado crecientemente */
	int result = -1; // result se usar� para guardar la posici�n del valor encontrado � -1 en caso contrario
	int i = 0; // se inicia el contador
	while ((p_v[i] < elem) && (i < MAX)){
		i = i + 1;
	}
	if (p_v[i] == elem) {
		// se ha encontrado el elemento elem
		result = i;
	}else {
		result = -1;
	}
}

int busquedaBinaria(tVectorInt p_v, int elem) {	
	
	int final, comienzo;
	int medio;
	bool encontrado;

	final = MAX -1;
	comienzo = 0;
	encontrado = false;

	while((!encontrado) && (final >= comienzo)){

		medio = (final + comienzo)/2;

		if(p_v[medio] == elem){
			encontrado = true;
		}else{
			if(elem > p_v[medio]){
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

bool busquedaBinariaBool(tVectorInt p_v, int elem) {	
	/* 	Pre-Condicion: p_v ordenado crecientemente */
	int extInf, extSup; // extremos del intervalo
	int posMed; // posicion central del intervalo
	bool encontrado;

	extInf = 0;
	extSup = MAX-1;
	encontrado = false;
	while ((!encontrado) && (extSup >= extInf)) {
		posMed = (extSup + extInf) / 2;
		if (elem == p_v[posMed]) {
			encontrado = true;
		} 
		else {
			if (elem > p_v[posMed]) {
				/* se actualizan los extremos del intervalo */
				extInf = posMed + 1;
			} else {
				extSup= posMed - 1;
			}			
		}	
	} 
	
	return encontrado;
}

/* Busca el mayor valor y devuelve la posici�n en la cual se encuentra - Supuesto o prepo */
int buscarMayor(tVectorInt p_v)  {
	int i, va_mayor, va_indMayor;
	va_mayor = 0;
	va_indMayor = -1;
	for (i = 0; i<MAX; i++) {
		if (p_v[i] > va_mayor) {
			va_mayor = p_v[i];
			va_indMayor = i;
		}
	}
	return va_indMayor;
} 

/* Busca el menor valor y devuelve la posici�n en la cual se encuentra - Supuesto o prepo */
int buscarMenor(tVectorInt p_v)  {
	int i, va_menor, va_indMenor;
	va_menor = 99999;
	va_indMenor = -1;
	for (i = 0; i<MAX; i++) {
		if (p_v[i] < va_menor) {
			va_menor = p_v[i];
			va_indMenor = i;
		}
	}
	return va_indMenor;
} 





