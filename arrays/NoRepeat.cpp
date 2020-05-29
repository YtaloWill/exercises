#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void semRepetidos(int v[], int tam);
int buscaElemento(int v[], int valor, int tam);

int main(){
    srand(time(NULL));
    int length = rand() % 30 + 1;
    int array[length];

    populateArray(array, length);
    
    printf("Array Length: %d\n", length);
    printf("Array: ");
    
    int i;
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
        
    int test;
    scanf("\nWrite the value to search: %d", &test);
    getPosition(array, test, length);

    return 0;
}

void semRepetidos(int v[], int tam){
    int i, j;
    for (i = 0; i < tam; i++){
        int finded;
        int randomValue;
        do{
            finded = 0;
            randomValue = rand() % 10 + 1;
            for (j = 0; j < tam; j++){
                if (v[j] == randomValue){
                    finded = 1;
                    break;
                }
            }
        } while(finded);
        v[i] = randomValue;
    }
}

int buscaElemento(int v[], int valor, int tam){
    int i;
    for (i = 0; i < tam; i++)
        if (v[i] == valor)
            return i;
    return -1;
}
