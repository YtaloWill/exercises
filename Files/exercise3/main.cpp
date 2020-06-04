#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file;
    char word[16];
    
    file = fopen("palavras2.txt", "w");

    fgets(word, sizeof(word), stdin);
    while(strcmp(word, "fim\n")){
        fprintf(file, "%s", word);
        fflush(stdin);
        fgets(word, sizeof(word), stdin);
    }
    fprintf(file, "%s", word);
    fclose(file);

    return 0;
}