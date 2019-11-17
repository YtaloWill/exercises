#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct TCoordinates{
    int x;
    int y;
};

double Pythagoras(TCoordinates bolim, TCoordinates bocha);
void bubbleSort(double *array, int length);
int countPoints(double *player1, double *player2, int length, int lessIndex);

int main(){
    int line, turn;
    int inputData1, inputData2;
    int whitePoints, redPoints;
    int amountBochas, amountTurns;
    double *whiteBochas = NULL, *redBochas = NULL;
    TCoordinates bolim, currentBocha;
    FILE *fileIn;
    fileIn = fopen("3_in.txt", "r");
    line = 0;
    turn = 0;
    whitePoints = 0;
    redPoints = 0;
    while (fscanf(fileIn, "%d %d", &inputData1, &inputData2) != EOF){
        if(!line){
            amountBochas = inputData1;
            amountTurns = inputData2;
            whiteBochas = (double *)malloc(sizeof(double)*amountBochas);
            redBochas = (double *)malloc(sizeof(double)*amountBochas);
            line++;
        } else if(line == 1){
            bolim.x = inputData1;
            bolim.y = inputData2;
            line++;
        } else{
            currentBocha.x = inputData1;
            currentBocha.y = inputData2;
            if (turn < amountBochas){
                whiteBochas[turn] = Pythagoras(bolim, currentBocha);
                turn++;
            } else {
                if (turn < amountBochas*2){
                    redBochas[turn-amountBochas] = Pythagoras(bolim, currentBocha);
                    turn++;
                }
            }
        }
        if (turn == amountBochas*2){
            bubbleSort(whiteBochas, amountBochas);
            bubbleSort(redBochas, amountBochas);
            int lessIndex = 0;
            while(whiteBochas[lessIndex] == redBochas[lessIndex])
                lessIndex++;

            if (whiteBochas[lessIndex] < redBochas[lessIndex])
                whitePoints += countPoints(whiteBochas, redBochas, amountBochas, lessIndex);
            else
                redPoints += countPoints(redBochas, whiteBochas, amountBochas, lessIndex);
            turn = 0;
        }
    }

    printf("PONTOS DAS BOCHAS BRANCAS = %d\n", whitePoints);
    printf("PONTOS DAS BOCHAS VERMELHAS = %d\n", redPoints);
    printf("VENCEDOR: ");
    if(redPoints > whitePoints)
    	printf("BOCHAS VERMELHAS");
    else
    	printf("BOCHAS BRANCAS");
    printf("\n");

    fclose(fileIn);

    return 0;
}

double Pythagoras(TCoordinates bolim, TCoordinates bocha){
    return sqrt(pow(bocha.x - bolim.x, 2.0) + pow(bocha.y - bolim.y, 2.0));
}

void bubbleSort(double *array, int length){
    int i, j, trade;
    for (i = 0; i < length-1; i++){
        for (j = 0; j < length-i-1; j++){
            if (array[j] > array[j+1]){
                trade = array[j];
                array[j] = array[j+1];
                array[j+1] = trade;
            }
        }
    }
}

int countPoints(double *player1, double *player2, int length, int lessIndex){
    int i = 0;
    int finalPoints = 0;
    while(player1[i] < player2[lessIndex] && i < length){
        finalPoints++;
        i++;
    }
    return finalPoints;
}
