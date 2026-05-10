#include <stdio.h>
#include <stdlib.h>
#include "algebra.h"

int RIGHE;
int COLONNE;

int main(){

	printf("Dammi le dimensioni delle matrici [righe, colonne]: ");
	scanf("%d, %d", &RIGHE, &COLONNE);

	int matrice1[RIGHE][COLONNE];
	int matrice2[RIGHE][COLONNE];
	int matricet[RIGHE][COLONNE];
	int matricetr[RIGHE][COLONNE];
	int matricedet[RIGHE][COLONNE];
	int matricetriang[RIGHE][COLONNE];
	int matricerank[RIGHE][COLONNE];


	int definedM1 = 0;
	int definedM2 = 0;
	int definedMT = 0;
	int definedMtr = 0;
	int definedMdet = 0;
	int definedMtriang = 0;
	int definedMrk = 0;


	int scelta;
	do {
		printf("-----Calcolatore Matrici-----\n");
		printf("1. Prodotto Riga per Colonna\n");
		printf("2. Trasposta\n");
		printf("3. Traccia\n");
		printf("4. Determinante\n");
		printf("5. Triangolarizzazione\n");
		printf("6. Rango\n");
		printf("99. Elimina Matrici in Memoria\n");
		printf("0. Esci\n");
		scanf("%d",&scelta);

		switch (scelta) {

			case 1:
				if (definedM1 == 0) {
					printf("Definisci matrice1: \n");
					defMatrix(matrice1);
					definedM1 = 1;
				}
				if (definedM2 == 0) {
					printf("Definisci matrice2: \n");
					defMatrix(matrice2);
					definedM2 = 1;
				}
				prodottoRxC(matrice1, matrice2);
				break;
			case 2: {
				if (definedMT == 0) {
					printf("Definisci matrice: \n");
					defMatrix(matricet);
					definedMT = 1;
				}
				trasp(matricet);
				break;
			}

			case 3:
				if (RIGHE != COLONNE) {
					printf("La traccia di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}

				if (definedMtr == 0) {
					printf("Definisci matrice: \n");
					defMatrix(matricetr);
					stampaMatrixint(matricetr);
					definedMtr = 1;
				}
				printf("Traccia = %d\n\n", traccia(matricetr));
				break;

			case 4:
				if (RIGHE != COLONNE) {
					printf("Il determinante di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}
				if (definedMdet == 0) {
					printf("Definisci matrice: \n");
					defMatrix(matricedet);
					stampaMatrixint(matricedet);
					definedMdet = 1;
				}
				if (RIGHE == 2) {
					printf("Determinante: %f\n\n", detM2x2(matricedet));
				}
				else if (RIGHE == 3) {
					printf("eterminante: %f\n\n", detM3x3(matricedet));
				}
				else {
					printf("Determinante: %f\n\n", determinanteGauss(matricedet));
				}
				break;

			case 5: {
				if (definedMtriang == 0) {
					printf("Definisci matrice: \n");
					defMatrix(matricetriang);
					definedMtriang = 1;
					stampaMatrixint(matricetriang);
				}

				float tempMatrix[RIGHE][COLONNE];
				for(int i = 0; i < RIGHE; i++) {
					for(int j = 0; j < COLONNE; j++) {
						tempMatrix[i][j] = (float)matricetriang[i][j];
					}
				}
				triang(tempMatrix);
				break;
			}

			case 6:
				if (definedMrk == 0) {
					printf("Definisci matrice: \n");
					defMatrix(matricerank);
					definedMrk = 1;
					stampaMatrixint(matricerank);
				}

				printf("Il rango della matrice è: %d\n\n", get_rank(matricerank));

				break;



			case 99:
				resetMatrix(matrice1);
				resetMatrix(matrice2);
				resetMatrix(matricet);
				resetMatrix(matricetr);
				resetMatrix(matricedet);
				resetMatrix(matricetriang);
				resetMatrix(matricerank);

				definedM1 = 0;
				definedM2 = 0;
				definedMT = 0;
				definedMtr = 0;
				definedMdet = 0;
				definedMtriang = 0;
				definedMrk = 0;

				printf("Tutte le matrici resettate\n");
				printf("Dammi le dimensioni delle nuove matrici [righe, colonne]: ");
				scanf("%d, %d", &RIGHE, &COLONNE);
				break;

			case 0:
				printf("Chiusura....\n");
				break;

			default:
				printf("Opzione non valida.\n");
		}
	}while(scelta!=0);

return 0;
}