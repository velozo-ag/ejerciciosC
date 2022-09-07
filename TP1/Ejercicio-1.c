/*
    En un gimnasio se apilan discos con pesos diferentes en forma desordenada. Los pesos de los discos varían
    de 10 a 100 Kg., con un máximo de 12 discos en la pila. Se pide diseñar un programa que disponga de un
    menú para invocar las funciones que permitan:

    ▪ cargar la pila con los pesos de los discos
    ▪ listar los pesos de los discos apilados
    ▪ a medida que cada gimnasta quita un disco, este debe ser eliminado de la pila
    ▪ detectar cuál es el disco que se encuentra en el tope
    ▪ mostrar la cantidad de discos apilados
    ▪ calcular el promedio de pesos de los discos que tiene la pila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/*
    | crearPilaVacia() -> apilar(int) -> desapilar() -> mostrarPila() | 
    | acumularPeso() - sacarPeso() - calcularPromedio() | 
    | desplegarMenu() -> seleccionarOpcion() -> ejecutarAccion() |
*/

#define MAX 5

// Definicion de Tipos
typedef int pilaDiscos[MAX];

typedef struct{
    pilaDiscos pDiscos;
    int tope;
} tPila;

// Variables
tPila pilaDeDiscos;
int pesoAcumulado = 0;

// Prototipos
void crearPilaVacia();
bool pilaVacia();
bool pilaLlena();

void apilarDisco();
void desapilarDisco();
void mostrarPila();

float calcularPromedio();

void desplegarMenu();
int seleccionarOpcion();
void ejecutarAccion(int);

// Main
int main(){

    int op;

    crearPilaVacia();

    desplegarMenu();
    op = seleccionarOpcion();

    while(op < 7)
    {
        ejecutarAccion(op);
        desplegarMenu();
        op = seleccionarOpcion();

    };

    printf("Saliendo...\n");

    return 0;
}

void crearPilaVacia(){
    pilaDeDiscos.tope = -1;
};

void apilarDisco(){

    int peso;

    if(!pilaLlena()){

        printf("Ingrese el peso del disco: \n > ");
        scanf("%d", &peso);

        pilaDeDiscos.tope ++;
            
        pilaDeDiscos.pDiscos[pilaDeDiscos.tope] = peso;
        
        pesoAcumulado += peso;

        printf("%d",pilaDeDiscos.tope);

    }else {

        printf("La pila esta llena!!\n");

    }

};

void desapilarDisco(){

    if(!pilaVacia()){

        pesoAcumulado -= pilaDeDiscos.pDiscos[pilaDeDiscos.tope];

        pilaDeDiscos.pDiscos[pilaDeDiscos.tope] = 0;
        pilaDeDiscos.tope--;
    
    }else {
        printf("La pila esta vacia. Nada que desapilar. \n");
    }


};

void mostrarPila(){

    int i;

    for(i = 0; i < MAX; i++){
        printf("%d | ", pilaDeDiscos.pDiscos[i]);
    }

    printf("\n");

};

float calcularPromedio(){

    return ((float)pesoAcumulado / (float)(pilaDeDiscos.tope + 1));

};

void desplegarMenu(){

    printf("\n ---------- Menu ---------- \n");
    printf("     1- Agregar disco \n");
    printf("     2- Sacar disco \n");
    printf("     3- Mostrar pila \n");
    printf("     4- Mostrar tope \n");
    printf("     5- Mostrar cantidad \n");
    printf("     6- Peso promedio \n");
    printf("     7- Salir \n");

};

int seleccionarOpcion(){
    int op;
    scanf("%d",&op);
    return op;
};

void ejecutarAccion(int opcion){

    switch (opcion){
    case 1:
        apilarDisco();
        break;
    
    case 2:
        desapilarDisco();
        break;
    
    case 3:
        mostrarPila();
        break;
    
    case 4:
        printf("El tope se encuentra en la posicion %d y es un disco de %d kg. \n", pilaDeDiscos.tope, pilaDeDiscos.pDiscos[pilaDeDiscos.tope]);
        break;
    
    case 5:
        printf("Hay %d discos apilados.\n", pilaDeDiscos.tope + 1);
        break;
    
    case 6:
        printf("El peso promedio es de %.2fkg. \n", calcularPromedio());
        break;
    
    default:
        printf("Saliendo...\n\n\n");
        break;
    }

};

bool pilaVacia(){
    return (pilaDeDiscos.tope == -1);
};

bool pilaLlena(){
    return (pilaDeDiscos.tope == MAX -1);
};