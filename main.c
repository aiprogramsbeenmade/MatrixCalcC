#include <stdio.h>
#include "lib/algebra.h"
#include "lib/menumatrix.h"
#include "lib/menusystem.h"



int main(){
	cls();
	int s;
	do {
		printf("----Menù Principale----\n");
		printf("1. Matrici\n");
		printf("2. Sistemi Lineari\n");
		printf("0. Esci\n");
		s = scanfcls("Scelta: ");
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