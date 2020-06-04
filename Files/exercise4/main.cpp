#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    float numbers[10];
    float number;
    int i;
    file = fopen("NumBin.bin", "wb+rb");
    for (i = 0; i < 10; i++){
        scanf("%f", &number);
        fwrite(&number, sizeof(number), 1, file);
    }
    rewind(file);
    fread(numbers, sizeof(numbers), i, file);
    fclose(file);
    for(i=0; i<10;i++)
        printf("%f\t",numbers[i]);

    return 0;
}