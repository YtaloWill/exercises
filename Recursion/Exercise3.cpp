#include <stdio.h>

void bolha_rec (int *vet, int tam);

int main(){
    int array[] = {2,3,5,1,3,2};
    int arrayLength = 6;

    bolha_rec(array, arrayLength);

    int i;
    for (i = 0; i < arrayLength; i++)
        printf("%d ", array[i]);
    
}

void bolha_rec(int *vet, int tam){
    if(tam == 0) return;
    int i;
    for (i = 0; i < tam-1; i++){
        if (vet[i] > vet[i+1]){
            int aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
        }
    }
    bolha_rec(vet, tam-1);
}

/*
for i ate total - 1
    for j ate total - i - 1
        if j > j+1
            troca()

*/