#include <stdio.h>

int soma(int a, int b);

int main(){

    printf("%d", soma(1, 3));

    return 0;
}

int soma(int a, int b){
    if(a == b) return a;
    return soma(a+1, b) + a;
}
