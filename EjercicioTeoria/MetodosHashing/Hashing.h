#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int claveNumerica = 10000000;

int restaSucesiva(char[]);
int aritmeticaModular(char[]);
void mitadDelCuadrado(char[]);
int truncamiento(char[]);
int plegamiento(char[]);
void mostrarClave();

void mostrarClave(){
    printf("%d\n",claveNumerica);
}

int restaSucesiva(char numero[]){

    int num = atoi(numero);
    int resta;

    resta = num - claveNumerica;
    // printf("%d\n",claveNumerica);

    if(resta > 0){

        return resta;
    
    }else{

        return -resta;

    }

}

int aritmeticaModular(char numero[]){

    return atoi(numero) % 3;

}

void mitadDelCuadrado(char numero[]){

    int num = atoi(numero);
    int i;
    int mitad, mitad2;
    char resultado[2];
    num *= num;

    mitad = strlen(numero) / 2;


    itoa(num, numero, 10);

    if(strlen(numero) %2 == 0){

        mitad = strlen(numero) / 2;

        resultado[0] = numero[mitad-1];
        resultado[1] = numero[mitad];

    }else{

        mitad = ((strlen(numero) + 1) / 2) - 1;
        
        resultado[0] = numero[mitad-1];
        resultado[1] = numero[mitad];

    }

    num = atoi(resultado);

    printf("%s\n",resultado);

}

int truncamiento(char numero[]){

    int num;
    char truncado[3];

    if(strlen(numero) > 5){

        truncado[0] = numero[0];
        truncado[1] = numero[3];
        truncado[2] = numero[strlen(numero)-1];

    }else{

        truncado[0] = numero[0];
        truncado[1] = numero[strlen(numero)-1];

    }

    num = atoi(truncado);

    return num;

}

int plegamiento(char numero[]){

    char num1[3];
    char num2[3];
    char num3[3];
    int num = 0;
    int i;


    // for(i = 0; i < strlen(numero); i++){
        
    //     if(i % 2 == 0 && num1 == NULL){

    //         num1[0] = numero[i-2];
    //         num1[1] = numero[i-1];
    //         num1[2] = numero[i];

    //     }else if(i % 5 == 0 && num2 == NULL){

    //         num2[0] = numero[i-2];
    //         num2[1] = numero[i-1];
    //         num2[2] = numero[i];

    //     }else if(i % 8 && num3 == NULL){

    //         num3[0] = numero[i-2];
    //         num3[1] = numero[i-1];
    //         num3[2] = numero[i];

    //         completoTercero = true;

    //     }
    
    // }

    for(i = 0; i < 3; i++){
        num1[i] = numero[i];
    }

    num += atoi(num1);
    // printf("%d\n",num);

    for(i = 3; i < 6; i++){
        num2[i-3] = numero[i];
        // printf("%d %d \n", i, atoi(num2)); 
    }

    num = num + atoi(num2);
    // printf("%d\n",num);

    for(i = 6; i < strlen(numero); i++){
        num3[i-6] = numero[i];
    }
    // printf("%d\n", atoi(num3));

    num += atoi(num3);

    printf("%d\n", atoi(numero));

    return num;

}


