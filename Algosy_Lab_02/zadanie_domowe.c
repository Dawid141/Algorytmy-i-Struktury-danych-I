#include <stdio.h>

int potega(int x,int n){
if(n%2 == 0){
int k = n/2;
if(k == 0){
    return 1;
}
else
return x*x*(potega(x,(k-1)));
}

}

int main(){

int x,n;

scanf("%i",&x);
scanf("%i",&n);

printf("%i",potega(x,n));
}