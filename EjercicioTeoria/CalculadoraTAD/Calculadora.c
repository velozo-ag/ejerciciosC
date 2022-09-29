#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Calculadora.h"

int x,y;

void menu();
void ingresoNumeros();

int main(){

    menu();

    return 0;
}

void menu(){

    int op;

    do{

        system("cls");

        printf("\t Menu \n");
        printf(" 1- Hallar Maximo Comun Divisor \n");
        printf(" 2- Hallar Minimo Comun Multiplo \n");
        printf(" 3- Hallar factorial \n");
        printf(" 4- salir \n");

        scanf("%d", &op);

        switch(op){
            case 1:

                ingresoNumeros();        
                printf("El maximo comun divisor entre %d y %d es %d. \n", x, y, mcd(x,y));
                
                system("pause>nul");
                break;
            case 2:

                ingresoNumeros();        
                printf("El minimo comun multiplo entre %d y %d es %d. \n", x, y, mcm(x,y));
                
                system("pause>nul");
                break;
            case 3:

                printf("Ingrese un numero\n");
                scanf("%d",&x);
                printf("El factorial de %d es %d\n", x, factorial(x));
                
                system("pause>nul");
                break;
            case 4:

                printf("Saliendo...\n");
                
                break;
            default:

                printf("Numero equivocado...\n");
                
                system("pause");
                break;
        }

    } while(op != 4);

}

void ingresoNumeros(){
    printf("Ingrese el numero mayor: \n");
    scanf("%d", &x);
    printf("Ingrese el numero menor: \n");
    scanf("%d", &y);
};