#import <stdio.h>
#import <stdlib.h>
#import "algebra.h"
#import "menumatrix.h"

int r;
int c;

void Mmenu() {
	cls();
	printf("Dammi le dimensioni delle matrici [r, c]: ");
	scanf("%d, %d", &r, &c);

	float matrice1[r][c];
	float matrice2[r][c];
	float matricet[r][c];
	float matricetr[r][c];
	float matricedet[r][c];
	float matricetriang[r][c];
	float matricerank[r][c];


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
					defMatrix(r, c, matrice1);
					definedM1 = 1;
				}
				if (definedM2 == 0) {
					printf("Definisci matrice2: \n");
					defMatrix(r, c, matrice2);
					definedM2 = 1;
				}
				prodottoRxC(r, c, matrice1, matrice2);
				break;

			case 2: {
				if (definedMT == 0) {
					printf("Definisci matrice: \n");
					defMatrix(r, c, matricet);
					definedMT = 1;
				}
				trasp(r, c, matricet);
				break;
			}

			case 3:
				if (r != c) {
					printf("La traccia di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}

				if (definedMtr == 0) {
					printf("Definisci matrice: \n");
					defMatrix(r, c, matricetr);
					stampaMatrix(r, c, matricetr);
					definedMtr = 1;
				}
				printf("Traccia = %d\n\n", traccia(r, c, matricetr));
				break;

			case 4:
				if (r != c) {
					printf("Il determinante di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}
				if (definedMdet == 0) {
					printf("Definisci matrice: \n");
					defMatrix(r, c, matricedet);
					stampaMatrix(r, c, matricedet);
					definedMdet = 1;
				}
				if (r == 2) {
					printf("Determinante: %f\n\n", detM2x2(r, c, matricedet));
				}
				else if (r == 3) {
					printf("eterminante: %f\n\n", detM3x3(r, c, matricedet));
				}
				else {
					printf("Determinante: %f\n\n", determinanteGauss(r, c, matricedet));
				}
				break;

			case 5: {
				if (definedMtriang == 0) {
					printf("Definisci matrice: \n");
					defMatrix(r, c, matricetriang);
					definedMtriang = 1;
					stampaMatrix(r, c, matricetriang);
				}

				float tempMatrix[r][c];
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						tempMatrix[i][j] = matricetriang[i][j];
					}
				}
				triang(r, c, tempMatrix);
				break;
			}

			case 6:
				if (definedMrk == 0) {
					printf("Definisci matrice: \n");
					defMatrix(r, c, matricerank);
					definedMrk = 1;
					stampaMatrix(r, c, matricerank);
				}

				printf("Il rango della matrice è: %d\n\n", get_rank(r, c, matricerank));

				break;



			case 99:
				resetMatrix(r, c, matrice1);
				resetMatrix(r, c, matrice2);
				resetMatrix(r, c, matricet);
				resetMatrix(r, c, matricetr);
				resetMatrix(r, c, matricedet);
				resetMatrix(r, c, matricetriang);
				resetMatrix(r, c, matricerank);

				definedM1 = 0;
				definedM2 = 0;
				definedMT = 0;
				definedMtr = 0;
				definedMdet = 0;
				definedMtriang = 0;
				definedMrk = 0;

				printf("Tutte le matrici resettate\n");
				printf("Dammi le dimensioni delle nuove matrici [r, c]: ");
				scanf("%d, %d", &r, &c);
				break;

			case 0:
				cls();
				break;

			default:
				cls();
				printf("Opzione non valida.\n\n\n");
		}
	}while(scelta!=0);
}