#include <stdio.h>
#include "../lib/algebra.h"
#include <math.h>
#include <stdlib.h>


void defMatrix(Matrice *m) {
        for (int i = 0; i < m->r; i++) {
                for (int j = 0; j < m->c; j++) {
                        scanf("%f", &m->matrix[i][j]);
                }
        }
}

void stampaMatrix(Matrice m){
        printf("\n\n");

        for(int i = 0; i < m.r; i++){
                for(int j = 0; j < m.c; j++){
                        printf("|%.2f| ", m.matrix[i][j]);
                }
                printf("\n");
        }
        printf("\n\n");
}


void prodottoRxC(Matrice m, Matrice m2){
        Matrice risultato;

        risultato.r = m.r;
        risultato.c = m.c;

        int temp = 0;

        for(int i = 0; i < m.r; i++){
                for(int j = 0; j < m.c; j++){
                        for(int k = 0; k < m.r; k++){
                                temp += m.matrix[i][k]*m2.matrix[k][j];
                        }
                        risultato.matrix[i][j] = temp;
                        temp = 0;
                }
        }
        stampaMatrix(risultato);
}

void trasp(Matrice m) {
        Matrice ris;

        ris.r = m.c;
        ris.c = m.r;

        for(int i = 0; i < m.r; i++) {
                for(int j = 0; j < m.c; j++) {
                        ris.matrix[i][j] = m.matrix[j][i];
                }
                printf("\n");
        }
        printf("Matrice di partenza:\n");
        stampaMatrix(m);
        printf("\nMatrice Trasposta:\n");
        stampaMatrix(ris);
}



void resetMatrix(Matrice *m) {
        for(int i = 0; i < m->r; i++) {
                for(int j = 0; j < m->c; j++) {
                        m->matrix[i][j] = 0;
                }
        }
}

int traccia(Matrice matrix) {
        float tr = 0;

        for (int i = 0; i < matrix.r; i++) {
                tr += matrix.matrix[i][i];
        }
        return tr;
}

float detM2x2(Matrice m) {
        float det = 0;
        det = (m.matrix[0][0] * m.matrix[1][1]) - (m.matrix[0][1] * m.matrix[1][0]);
        return det;
}

float detM3x3(Matrice m) {
        float det = 0;
        det = (m.matrix[0][0]*m.matrix[1][1]*m.matrix[2][2]+m.matrix[0][1]*m.matrix[1][2]*m.matrix[2][0]+m.matrix[0][2]*m.matrix[1][0]*m.matrix[2][1]) - (m.matrix[0][2]*m.matrix[1][1]*m.matrix[2][0]+m.matrix[0][1]*m.matrix[1][0]*m.matrix[2][2]+m.matrix[0][0]*m.matrix[1][2]*m.matrix[2][1]);
        return det;
}

float determinanteGauss(Matrice m) {
        float tempMatrix[m.r][m.c];
        for(int i = 0; i < m.r; i++) {
                for(int j = 0; j < m.c; j++) {
                        tempMatrix[i][j] = m.matrix[i][j];
                }
        }

        float det = 1.0;

        for(int i = 0; i < m.r; i++) {
                for(int k = i + 1; k < m.r; k++) {
                        float fattore = tempMatrix[k][i] / tempMatrix[i][i];
                        for(int j = i; j < m.c; j++) {
                                tempMatrix[k][j] -= fattore * tempMatrix[i][j];
                        }
                }
        }

        for(int i = 0; i < m.r; i++) {
                det *= tempMatrix[i][i];
        }

        return det;
}

int calcolaDet(Matrice m) {
        if (m.r != m.c) {
                printf("Per calcolare il determinante serve una matrice quadrata!\n\n");
                return 0;
        }
        else {
                if (m.r == 2) {
                        return detM2x2(m);
                }
                if (m.r == 3) {
                        return detM3x3(m);
                }
                if (m.r > 3) {
                        return determinanteGauss(m);
                }
        }

return 0;
}

void triang(Matrice *m) {

        Matrice tempMatrix;

        tempMatrix = *m;

        for(int i = 0; i < m->r; i++) {
                int rigaPivot = i;
                for(int l = i + 1; l < m->r; l++) {
                        if (fabs(tempMatrix.matrix[l][i]) > fabs(tempMatrix.matrix[rigaPivot][i])) {
                                rigaPivot = l;
                        }
                }

                if (rigaPivot != i) {
                        for(int n = 0; n < m->c; n++) {
                                float temp = tempMatrix.matrix[i][n];
                                tempMatrix.matrix[i][n] = tempMatrix.matrix[rigaPivot][n];
                                tempMatrix.matrix[rigaPivot][n] = temp;
                        }
                }

                if (fabs(tempMatrix.matrix[i][i]) > 1e-9) {
                        for(int k = i + 1; k < m->r; k++) {
                                float fattore = tempMatrix.matrix[k][i] / tempMatrix.matrix[i][i];
                                for(int j = i; j < m->c; j++) {
                                        tempMatrix.matrix[k][j] -= fattore * tempMatrix.matrix[i][j];
                                }
                        }
                }
        }
        *m = tempMatrix;
}

int get_rank(Matrice m) {
        Matrice temp;

        temp.r = m.r;
        temp.c = m.c;

        for(int i = 0; i < m.r; i++)
                for(int j = 0; j < m.c; j++)
                        temp.matrix[i][j] = m.matrix[i][j];

        triang(&temp);

        int rango = 0;
        for(int i = 0; i < m.r; i++) {
                int rigaTuttaZeri = 1;
                for(int j = 0; j < m.c; j++) {
                        if(fabs(temp.matrix[i][j]) > 1e-9) {
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

// Anche questa non c'entra con l'algebra ma è lo stesso motivo di prima.
int scanfcls(char* msg) {
        int val;
        int res;

        while (1) {
                printf("%s", msg);
                res = scanf("%d", &val);

                if (res == 1) {
                        while (getchar() != '\n'){}

                        return val;
                }
                else {
                        printf("Inserisci solo numeri interi!\n");
                        while (getchar() != '\n');
                }
        }
}


void matcompleta(Matrice A, Matrice b, Matrice *B) {
        for (int i = 0; i < A.r; i++) {
                for (int j = 0; j < A.c; j++) {
                        B->matrix[i][j] = A.matrix[i][j];
                }
        }

        for (int i = 0; i < A.r; i++) {
                B->matrix[i][A.c] = b.matrix[i][0];
        }
}

void risCramer(Matrice A, Matrice b) {
        // calcolaDet ora accetta solo la struct A
        float detA = calcolaDet(A);

        // Creiamo la matrice di supporto Aprimo
        Matrice Aprimo;
        int k = 0;

        if (fabs(detA) < 1e-9) { // Usa fabs per i float, abs è per gli int!
                printf("Il determinante è 0: il sistema non è risolvibile con Cramer.\n");
                return;
        }

        if (A.r != A.c) {
                printf("Matrice non quadrata, sistema non risolvibile con Cramer.\n\n");
                return;
        }

        Aprimo = A;

        for (int i = 0; i < A.r; i++) {
                for (int j = 0; j < A.r; j++) {
                        Aprimo.matrix[j][k] = b.matrix[j][0];
                }

                printf("----------------\n");
                printf("Matrice %d\n", i + 1);
                stampaMatrix(Aprimo);

                float detAprimo = calcolaDet(Aprimo);
                float x = detAprimo / detA;
                printf("Soluzione = %.2f\n", x);


                Aprimo = A;
                k++;
        }
        printf("----------------\n");
}

void risOpElem(Matrice A, Matrice B) {

        int rankB = get_rank(B);
        int rankA = get_rank(A);

        Matrice Bprimo;

        Bprimo = B;

        if (rankA != rankB) {
                printf("Sistema non compatibile:\n\n    rk A' = %d\n\n    rk B' = %d\n", rankA, rankB);
        }
        else {
                printf("\n\nB':\n");
                triang(&Bprimo);
                stampaMatrix(Bprimo);

                int rkBprimo = get_rank(Bprimo);
                printf("\n\nrk B' = %d\n", rkBprimo);
                int varlib = A.c - rkBprimo;
                if (varlib == 0) {
                        printf("Il sistema ha un'unica soluzione\nPossiamo risolverlo con Cramer!\n");
                }
                else {
                        printf("Il sistema ha: inf^%d soluzioni\n", varlib);
                        printf("Non posso ancora aiutarti in questo!\n\n");
                }
        }
}

