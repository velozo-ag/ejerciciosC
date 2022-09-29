#include <stdio.h>

int res = 1;

int mcd(int, int);
int mcm(int, int);
int factorial(int);

int mcd(int x, int y){
 
    int r;

    r = y;
    y = x % y;

    x = r;

    if(y != 0){
        r = mcd(x,y);
    };

    return r;

}

int mcm(int x, int y){

    return (x * y) / mcd(x,y);

}

int factorial(int x){

    int a = 1;

    for(int i=1;i<=x;i++){    
        a=a*i;
    }

    return a;

}
