#include <stdio.h>

int main(){
    double x=2;
    double n=2;
    double s = 0;

    while(n>0){
       s=x*x;
        n--;
    }
    printf("%lf",s);
}