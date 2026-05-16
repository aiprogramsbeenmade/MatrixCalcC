#import <stdio.h>
#import <stdlib.h>
#import "../lib/algebra.h"
#import "../lib/menumatrix.h"

Matrice m;

void Mmenu() {
	cls();
	printf("Dammi le dimensioni delle matrici [r, c]: ");
	scanf("%d, %d", &m.r, &m.c);

	Matrice matrice1 = m;
	Matrice matrice2 = m;
	Matrice matricet = m;
	Matrice matricetr = m;
	Matrice matricedet = m;
	Matrice matricetriang = m;
	Matrice matricerank = m;


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
		scelta = scanfcls("Scelta: ");

		switch (scelta) {

			case 1:
				if (definedM1 == 0) {
					printf("Definisci matrice1: \n");
					defMatrix(&matrice1);
					definedM1 = 1;
				}
				if (definedM2 == 0) {
					printf("Definisci matrice2: \n");
					defMatrix(&matrice2);
					definedM2 = 1;
				}
				prodottoRxC(matrice1, matrice2);
				break;

			case 2: {
				if (definedMT == 0) {
					printf("Definisci matrice: \n");
					defMatrix(&matricet);
					definedMT = 1;
				}
				trasp(matricet);
				break;
			}

			case 3:
				if (m.r != m.c) {
					printf("La traccia di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}

				if (definedMtr == 0) {
					printf("Definisci matrice: \n");
					defMatrix(&matricetr);
					stampaMatrix(matricetr);
					definedMtr = 1;
				}
				printf("Traccia = %d\n\n", traccia(matricetr));
				break;

			case 4:
				if (m.r != m.c) {
					printf("Il determinante di una matrice si può trovare solo per matrici quadrate!\n\n");
					break;
				}
				if (definedMdet == 0) {
					printf("Definisci matrice: \n");
					defMatrix(&matricedet);
					stampaMatrix(matricedet);
					definedMdet = 1;
				}
				if (m.r == 2) {
					printf("Determinante: %f\n\n", detM2x2(matricedet));
				}
				else if (m.r == 3) {
					printf("eterminante: %f\n\n", detM3x3(matricedet));
				}
				else {
					printf("Determinante: %f\n\n", determinanteGauss(matricedet));
				}
				break;

			case 5: {
				if (definedMtriang == 0) {
					printf("Definisci matrice: \n");
					defMatrix(&matricetriang);
					definedMtriang = 1;
					stampaMatrix(matricetriang);
				}

				Matrice tempMatrix;

				tempMatrix = matricetriang;
				triang(&tempMatrix);
				printf("\nB':\n");
				stampaMatrix(tempMatrix);
				break;
			}

			case 6:
				if (definedMrk == 0) {
					printf("Definisci matrice: \n");
					defMatrix(&matricerank);
					definedMrk = 1;
					stampaMatrix(matricerank);
				}

				printf("Il rango della matrice è: %d\n\n", get_rank(matricerank));

				break;



			case 99:
				resetMatrix(&m);
				definedM1 = 0;
				definedM2 = 0;
				definedMT = 0;
				definedMtr = 0;
				definedMdet = 0;
				definedMtriang = 0;
				definedMrk = 0;

				printf("Tutte le matrici resettate\n");
				printf("Dammi le dimensioni delle nuove matrici [r, c]: ");
				scanf("%d, %d", &m.r, &m.c);

				matrice1 = m;
				matrice2 = m;
				matricedet = m;
				matricerank = m;
				matricet = m;
				matricetr = m;
				matricetriang = m;

				cls();
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