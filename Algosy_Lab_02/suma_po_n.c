#include <stdio.h>

int suma(int n){
    if(n==1){
        return 1;
    }
    return n+suma(n-1);
}

int main(){

    int n = 5;


    printf("%d",suma(n));

    /**/
}