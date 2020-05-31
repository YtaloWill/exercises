#include <stdio.h>

double juroscompostos(double valor, double taxa, int meses);

int main(){

    printf("%lf", juroscompostos(1000.0, 10.0, 3)); // 1331

    return 0;
}

double juroscompostos(double valor, double taxa, int meses){
    double tax = taxa / 100.0;
    if (meses == 0) return valor;
    double newValue = juroscompostos(valor, taxa, meses-1);
    return newValue * tax + newValue;
}
