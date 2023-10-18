#include <iostream>
using namespace std;
int suma;

int main(){
    int a[] = {31,17,19,20,25,24,27,30,34,31};

    for(int i=0;i<10;i++){
     suma = suma + a[i];
    }
    cout<<"srednia to "<<suma/10<<endl;
}