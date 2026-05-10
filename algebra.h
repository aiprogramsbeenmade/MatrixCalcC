#ifndef ALGEBRA_H
#define ALGEBRA_H

extern int RIGHE;
extern int COLONNE;

void stampaMatrixint(int matrice[RIGHE][COLONNE]);
void stampaMatrixfloat(float matrice[RIGHE][COLONNE]);
void prodottoRxC(int matrix1[RIGHE][COLONNE], int matrix2[RIGHE][COLONNE]);
void trasp(int matrix1[RIGHE][COLONNE]);
void defMatrix(int matrix[RIGHE][COLONNE]);
void resetMatrix(int matrix[RIGHE][COLONNE]);
int traccia(int matrix[RIGHE][COLONNE]);
float determinanteGauss(int matrix[RIGHE][COLONNE]);
float detM3x3(int matrix[RIGHE][COLONNE]);
float detM2x2(int matrix[RIGHE][COLONNE]);
void triang(float tempMatrix[RIGHE][COLONNE]);
int get_rank(int originalMatrix[RIGHE][COLONNE]);

#endif
