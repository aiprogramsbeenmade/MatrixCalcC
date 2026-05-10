#include <stdio.h>
#include "algebra.h"
#include <math.h>


void stampaMatrixint(int matrice[RIGHE][COLONNE]){

        for(int i = 0; i < RIGHE; i++){
                for(int j = 0; j < COLONNE; j++){
                        printf("|%d| ", matrice[i][j]);
                }
        printf("\n");
        }
}

void stampaMatrixfloat(float matrice[RIGHE][COLONNE]){
        printf("\n\n");

        for(int i = 0; i < RIGHE; i++){
                for(int j = 0; j < COLONNE; j++){
                        printf("|%.2f| ", matrice[i][j]);
                }
                printf("\n");
        }
        printf("\n\n");
}


void prodottoRxC(int matrix1[RIGHE][COLONNE], int matrix2[RIGHE][COLONNE]){
        int risultato[RIGHE][COLONNE];
        int temp = 0;

        for(int i = 0; i < RIGHE; i++){
                for(int j = 0; j < COLONNE; j++){
                        for(int k = 0; k < RIGHE; k++){
                                temp += matrix1[i][k]*matrix2[k][j];
                        }
                        risultato[i][j] = temp;
                        temp = 0;
                }
        }
        stampaMatrixint(risultato);
}

void trasp(int matrix1[RIGHE][COLONNE]) {
        int temp[COLONNE][RIGHE];
        for(int i = 0; i < RIGHE; i++) {
                for(int j = 0; j < COLONNE; j++) {
                        temp[i][j] = matrix1[j][i];
                        printf("%d ", temp[i][j]);
                }
                printf("\n");
        }
}


void defMatrix(int matrix[RIGHE][COLONNE]) {
        int scelta = 0;
        for(int i = 0; i < RIGHE; i++) {
                for(int j = 0; j < COLONNE; j++) {
                        scanf("%d", &matrix[i][j]);
                }
        }
}


void resetMatrix(int matrix[RIGHE][COLONNE]) {
        for(int i = 0; i < RIGHE; i++) {
                for(int j = 0; j < COLONNE; j++) {
                        matrix[i][j] = 0;
                }
        }
}

int traccia(int matrix[RIGHE][COLONNE]) {
        int tr = 0;

        for (int i = 0; i < RIGHE; i++) {
                tr += matrix[i][i];
        }
        return tr;
}

float detM2x2(int matrix[RIGHE][COLONNE]) {
        float det = 0;
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        return det;
}

float detM3x3(int matrix[RIGHE][COLONNE]) {
        float det = 0;
        det = (matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]+matrix[0][2]*matrix[1][0]*matrix[2][1]) - (matrix[0][2]*matrix[1][1]*matrix[2][0]+matrix[0][1]*matrix[1][0]*matrix[2][2]+matrix[0][0]*matrix[1][2]*matrix[2][1]);
        return det;
}

float determinanteGauss(int matrix[RIGHE][COLONNE]) {
        float tempMatrix[RIGHE][COLONNE];
        for(int i = 0; i < RIGHE; i++) {
                for(int j = 0; j < COLONNE; j++) {
                        tempMatrix[i][j] = (float)matrix[i][j];
                }
        }

        float det = 1.0;

        for(int i = 0; i < RIGHE; i++) {
                for(int k = i + 1; k < RIGHE; k++) {
                        float fattore = tempMatrix[k][i] / tempMatrix[i][i];
                        for(int j = i; j < COLONNE; j++) {
                                tempMatrix[k][j] -= fattore * tempMatrix[i][j];
                        }
                }
        }

        for(int i = 0; i < RIGHE; i++) {
                det *= tempMatrix[i][i];
        }

        return det;
}

void triang(float tempMatrix[RIGHE][COLONNE]) {

        for(int i = 0; i < RIGHE; i++) {
                int rigaPivot = i;
                for(int m = i + 1; m < RIGHE; m++) {
                        if (fabs(tempMatrix[m][i]) > fabs(tempMatrix[rigaPivot][i])) {
                                rigaPivot = m;
                        }
                }

                if (rigaPivot != i) {
                        for(int n = 0; n < COLONNE; n++) {
                                float temp = tempMatrix[i][n];
                                tempMatrix[i][n] = tempMatrix[rigaPivot][n];
                                tempMatrix[rigaPivot][n] = temp;
                        }
                }

                if (fabs(tempMatrix[i][i]) > 1e-9) {
                        for(int k = i + 1; k < RIGHE; k++) {
                                float fattore = tempMatrix[k][i] / tempMatrix[i][i];
                                for(int j = i; j < COLONNE; j++) {
                                        tempMatrix[k][j] -= fattore * tempMatrix[i][j];
                                }
                        }
                }
        }
        stampaMatrixfloat(tempMatrix);
}

int get_rank(int originalMatrix[RIGHE][COLONNE]) {
        float temp[RIGHE][COLONNE];
        for(int i = 0; i < RIGHE; i++)
                for(int j = 0; j < COLONNE; j++)
                        temp[i][j] = (float)originalMatrix[i][j];

        triang(temp);

        int rango = 0;
        for(int i = 0; i < RIGHE; i++) {
                int rigaTuttaZeri = 1;
                for(int j = 0; j < COLONNE; j++) {
                        if(fabs(temp[i][j]) > 1e-9) {
                                rigaTuttaZeri = 0;
                                break;
                        }
                }
                if(!rigaTuttaZeri) rango++;
        }
        return rango;
}