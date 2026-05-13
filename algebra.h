#ifndef ALGEBRA_H
#define ALGEBRA_H

void stampaMatrix(int r, int c, float matrice[r][c]);
void prodottoRxC(int r, int c, float matrix1[r][c], float matrix2[r][c]);
void trasp(int r, int c, float matrix1[r][c]);
void defMatrix(int r, int c, float matrix[r][c]);
void resetMatrix(int r, int c, float matrix[r][c]);
int traccia(int r, int c, float matrix[r][c]);
float determinanteGauss(int r, int c, float matrix[r][c]);
float detM3x3(int r, int c, float matrix[r][c]);
float detM2x2(int r, int c, float matrix[r][c]);
void triang(int r, int c, float tempMatrix[r][c]);
int get_rank(int r, int c, float originalMatrix[r][c]);
void cls();
void matcompleta(int r, int c, int cb, float A[r][c], float b[r][cb], float B[r][c+1]);
int calcolaDet(int r, int c, float matrix[r][c]);
void eguaglia(int r, int c, float mat1[r][c], float mat2[r][c]);
void risCramer(int r, int c, int cb, float A[r][c], float b[r][cb]);
void risOpElem(int r, int c, float A[r][c], float B[r][c+1]);
#endif
