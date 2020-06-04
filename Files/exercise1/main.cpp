#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;
    int sum = 0;
    int number;
    file = fopen("Numeros.txt", "r");
    while(fscanf(file, "%d", &number) != EOF){
        sum += number;
    }
    fclose(file);

    printf("%d", sum);

    return 0;
}