/*
    En un depósito se ubican las cajas de televisores LED en pilas de hasta 20 como máximo, no se puede
    apilar una caja grande sobre otra más chica. Escribir un programa que permita:
    
    ▪ ingresar y almacenar el dato compuesto referido a las pulgadas y a la marca de los distintos televisores,
    según se van apilando
    ▪ obtener un listado de todos los televisores apilados
    ▪ una consulta que a partir del ingreso de un valor x de pulgadas retorne la cantidad de televisores con
    más de x pulgadas que se encuentran apilados
    ▪ conforme se vayan retirando las cajas, detectar las pulgadas y la marca del televisor que queda en el
    tope.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    | crearPilaVacia() -> pilaLlena() -> pilaVacia() -> apilar() -> desapilar() -> mostrarPila() -> mostrarTope()
    | crearTelevisor() -> mostrarXPulgadas(int)
    | desplegarMenu() -> seleccionarOpcion() -> ejecutarMetodo()
*/

#define MAX 5

// Definicion de tipos
typedef char tString[30];

typedef struct{
    tString marca;
    int pulgadas;
}tTelevisor;

typedef tTelevisor pTVS[MAX];

typedef struct{
    pTVS pilaTV;
    int tope;
}tPila;

tPila pilaTelevisores;

int main(){
    
    return 0;
}