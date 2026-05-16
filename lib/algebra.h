#ifndef ALGEBRA_H
#define ALGEBRA_H

typedef struct {
    int r;
    int c;
    float matrix[10][10];
} Matrice;

void stampaMatrix(Matrice matrice);
void prodottoRxC(Matrice m, Matrice m2);
void trasp(Matrice m);
void defMatrix(Matrice *m);
void resetMatrix(Matrice *m);
int traccia(Matrice matrix);
float determinanteGauss(Matrice m);
float detM3x3(Matrice m);
float detM2x2(Matrice m);
void triang(Matrice *m);
int get_rank(Matrice m);
void cls();
int scanfcls(char* msg);
void matcompleta(Matrice A, Matrice b, Matrice *B);
int calcolaDet(Matrice m);
void risCramer(Matrice A, Matrice b);
void risOpElem(Matrice A, Matrice B);
#endif
