#include <stdio.h>
#include "algebra.h"
#include <math.h>
#include <stdlib.h>

void stampaMatrix(int r, int c, float matrice[r][c]){
        printf("\n\n");

        for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                        printf("|%.2f| ", matrice[i][j]);
                }
                printf("\n");
        }
        printf("\n\n");
}


void prodottoRxC(int r, int c, float matrix1[r][c], float matrix2[r][c]){
        float risultato[r][c];
        int temp = 0;

        for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                        for(int k = 0; k < r; k++){
                                temp += matrix1[i][k]*matrix2[k][j];
                        }
                        risultato[i][j] = temp;
                        temp = 0;
                }
        }
        stampaMatrix(r, c, risultato);
}

void trasp(int r, int c, float matrix1[r][c]) {
        int temp[c][r];
        for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                        temp[i][j] = matrix1[j][i];
                        printf("|%d| ", temp[i][j]);
                }
                printf("\n");
        }
}


void defMatrix(int r, int c, float matrix[r][c]) {
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        scanf("%f", &matrix[i][j]);
                }
        }
}


void resetMatrix(int r, int c, float matrix[r][c]) {
        for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                        matrix[i][j] = 0;
                }
        }
}

int traccia(int r, int c, float matrix[r][c]) {
        float tr = 0;

        for (int i = 0; i < r; i++) {
                tr += matrix[i][i];
        }
        return tr;
}

float detM2x2(int r, int c, float matrix[r][c]) {
        float det = 0;
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        return det;
}

float detM3x3(int r, int c, float matrix[r][c]) {
        float det = 0;
        det = (matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]+matrix[0][2]*matrix[1][0]*matrix[2][1]) - (matrix[0][2]*matrix[1][1]*matrix[2][0]+matrix[0][1]*matrix[1][0]*matrix[2][2]+matrix[0][0]*matrix[1][2]*matrix[2][1]);
        return det;
}

float determinanteGauss(int r, int c, float matrix[r][c]) {
        float tempMatrix[r][c];
        for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                        tempMatrix[i][j] = matrix[i][j];
                }
        }

        float det = 1.0;

        for(int i = 0; i < r; i++) {
                for(int k = i + 1; k < r; k++) {
                        float fattore = tempMatrix[k][i] / tempMatrix[i][i];
                        for(int j = i; j < c; j++) {
                                tempMatrix[k][j] -= fattore * tempMatrix[i][j];
                        }
                }
        }

        for(int i = 0; i < r; i++) {
                det *= tempMatrix[i][i];
        }

        return det;
}

int calcolaDet(int r, int c, float matrix[r][c]) {
        if (r != c) {
                printf("Per calcolare il determinante serve una matrice quadrata!\n\n");
                return 0;
        }
        else {
                if (r == 2) {
                        return detM2x2(r, c, matrix);
                }
                if (r == 3) {
                        return detM3x3(r, c, matrix);
                }
                if (r > 3) {
                        return determinanteGauss(r, c, matrix);
                }
        }

return 0;
}

void triang(int r, int c, float tempMatrix[r][c]) {

        for(int i = 0; i < r; i++) {
                int rigaPivot = i;
                for(int m = i + 1; m < r; m++) {
                        if (fabs(tempMatrix[m][i]) > fabs(tempMatrix[rigaPivot][i])) {
                                rigaPivot = m;
                        }
                }

                if (rigaPivot != i) {
                        for(int n = 0; n < c; n++) {
                                float temp = tempMatrix[i][n];
                                tempMatrix[i][n] = tempMatrix[rigaPivot][n];
                                tempMatrix[rigaPivot][n] = temp;
                        }
                }

                if (fabs(tempMatrix[i][i]) > 1e-9) {
                        for(int k = i + 1; k < r; k++) {
                                float fattore = tempMatrix[k][i] / tempMatrix[i][i];
                                for(int j = i; j < c; j++) {
                                        tempMatrix[k][j] -= fattore * tempMatrix[i][j];
                                }
                        }
                }
        }
        stampaMatrix(r, c, tempMatrix);
}

int get_rank(int r, int c, float originalMatrix[r][c]) {
        float temp[r][c];
        for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                        temp[i][j] = originalMatrix[i][j];

        triang(r, c, temp);

        int rango = 0;
        for(int i = 0; i < r; i++) {
                int rigaTuttaZeri = 1;
                for(int j = 0; j < c; j++) {
                        if(fabs(temp[i][j]) > 1e-9) {
                                rigaTuttaZeri = 0;
                                break;
                        }
                }
                if(!rigaTuttaZeri) rango++;
        }
        return rango;
}


// So che non c'entra nulla ma è l'unica libreria che importo ovunque e mi faceva comodo averla qui

void cls() {
        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif
}


void matcompleta(int r, int c, int cb, float A[r][c], float b[r][cb], float B[r][c+1]) {
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        B[i][j] = A[i][j];
                }
        }

        for (int i = 0; i < r; i++) {
                B[i][c] = b[i][0];
        }
}

void risCramer(int r, int c, int cb, float A[r][c], float b[r][cb]) {
        int detA;
        cb = 1;
        detA = calcolaDet(r, c, A);

        float x;
        int detAprimo;
        float Aprimo[r][c];
        int k = 0;

        if (abs(detA) < 1e-9) {
                printf("Il determinante è 0: il sistema non è risolvibile con Cramer.\n");
                return;
        }

        if (r != c) {
                printf("Matrice non quadrata, sistema non risolvibile con Cramer.\n\n");
                return;
        }

        for (int i = 0; i < r; i++) {
                for (int j=0; j<c; j++) {
                        Aprimo[i][j] = A[i][j];
                }
        }

        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        Aprimo[j][k] = b[j][0];
                }
                printf("----------------\n");
                printf("Matrice %d\n", i+1);
                stampaMatrix(r, c, Aprimo);
                detAprimo = calcolaDet(r, c, Aprimo);
                x = detAprimo/detA;
                printf("Soluzione = %.2f\n", x);
                eguaglia(r, c, Aprimo, A);
                k++;
        }
        printf("----------------\n");

}

void risOpElem(int r, int c, float A[r][c], float B[r][c+1]) {
        int rankB = get_rank(r, c+1, B);
        int rankA = get_rank(r, c, A);

        float Bprimo[r][c+1];

        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c+1; j++) {
                        Bprimo[i][j] = B[i][j];
                }
        }

        if (rankA != rankB) {
                printf("Sistema non compatibile:\n\n    rk A' = %d\n\n    rk B' = %d\n", rankA, rankB);
        }
        else {
                printf("\n\nB':\n");
                triang(r, c, Bprimo);
                stampaMatrix(r, c+1, Bprimo);

                int rkBprimo = get_rank(r, c, Bprimo);
                printf("\n\nrk B' = %d\n", rkBprimo);

                int varlib = c - rkBprimo;

                if (varlib == 0) {
                        printf("Il sistema ha un'unica soluzione\nPossiamo risolverlo con Cramer!\n");
                }
                else {
                        printf("Il sistema ha: inf^%d soluzioni\n", varlib);
                        printf("Non posso ancora aiutarti in questo!\n\n");
                }
        }
}


void eguaglia(int r, int c, float mat1[r][c], float mat2[r][c]) {
                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                                mat1[i][j] = mat2[i][j];
                        }
                }
        }



