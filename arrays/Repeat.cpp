#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateArray(int array[], int length);
void buscaRepetidos(int v[], int valor, int tam);

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
    buscaRepetidos(array, test, length);

    return 0;
}

void populateArray(int array[], int length){
    int i;
    for (i = 0; i < length; i++)
        array[i] = rand() % 30 + 1;
}

void buscaRepetidos(int v[], int valor, int tam){
    int i, finded = 0;
    for (i = 0; i < tam; i++){
        if (v[i] == valor){
            printf("Position: %d\n", i);
            finded = 1;
        }
    }
    if (!finded)
        printf("Value not found");
}
