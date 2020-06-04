#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file;
    int totalCount = 0, countBalls = 0;
    char lineContent[40];
    file = fopen("palavras.dat", "r");
    while(fgets(lineContent, 40, file) != NULL){
        totalCount++;
        if(!strcmp(lineContent, "bola") || !strcmp(lineContent, "bola\n")) countBalls++;
    }
    fclose(file);

    printf("quantidade de linhas: %d\n", totalCount);
    printf("quantidade de bolas: %d", countBalls);

    return 0;
}