#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hashing.h"

char num[8];

void menu();
void realizarOperacion(int);
void ingresarNumero();

int main()
{

    menu();

    return 0;
}

void menu(){

    int op;

    printf("------- Menu -------\n");
    printf(" 1 - Resta sucesiva\n");
    printf(" 2 - Aritmetica modular\n");
    printf(" 3 - Mitad del cuadrado\n");
    printf(" 4 - Truncamiento\n");
    printf(" 5 - Plegamiento\n");
    printf(" 6 - Salir\n > ");
    scanf("%d", &op);

    realizarOperacion(op);

}

void realizarOperacion(int op){

    switch(op){
        case 1:
            ingresarNumero();
            printf("%d\n", restaSucesiva(num));
            menu();
        break;

        case 2:
            ingresarNumero();
            printf("%d\n", aritmeticaModular(num));
            menu();
        break;
        
        case 3:
            ingresarNumero();
            // printf("%d\n", mitadDelCuadrado(num));
            mitadDelCuadrado(num);
            menu();
        break;
        
        case 4:
            ingresarNumero();
            printf("%d\n", truncamiento(num));
            menu();
        break;
        
        case 5:
            ingresarNumero();
            printf("%d\n", plegamiento(num));
            menu();
        break;
        
        default:
            printf("Saliendo...\n");
        break;
        
    }

}

void ingresarNumero(){

    printf("Ingrese un numero de 8 digitos \n > ");
    fflush(stdin);
    gets(num);

}