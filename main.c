#include <stdio.h>
#include <stdlib.h>
#include "algebra.h"
#include "menumatrix.h"
#include "menusystem.h"



int main(){
	cls();
	int s;
	do {
		printf("----Menù Principale----\n");
		printf("1. Matrici\n");
		printf("2. Sistemi Lineari\n");
		printf("0. Esci\n");
		scanf("%d",&s);
		switch (s) {
			case 1:
				Mmenu();
				break;

			case 2:
				Sysmenu();
				break;

			case 0:
				cls();
				break;

			default:
				cls();
				printf("Opzione non valida\n\n\n");
		}
	}while (s != 0);


return 0;
}