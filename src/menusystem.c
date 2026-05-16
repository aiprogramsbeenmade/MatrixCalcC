#include <stdio.h>
#include "../lib/menusystem.h"
#include "../lib/algebra.h"

Matrice m;


void Sysmenu() {
    cls();

    printf("A quante incognite è il sistema? ");
    scanf("%d", &m.c);
    printf("A quante equazioni ha il sistema? ");
    scanf("%d", &m.r);

    Matrice A = m;
    Matrice b;
    Matrice B;

    b.r = m.r;
    b.c = 1;

    B.r = m.r;
    B.c = m.c + 1;


    int definedA = 0;
    int definedb = 0;


    int scelta;
    do {
        printf("---- Sistemi Lineari ----\n");
        printf("1. Risoluzione\n");
        printf("2. Trova Matrice Completa\n");
        printf("99. Resetta Variabili e Matrici\n");
        printf("0. Esci\n");
        scelta = scanfcls("Scelta: ");

        switch (scelta) {

            case 1: {
                int s = 0;

                printf("----------------\n");
                printf("Scegli il metodo risolutivo:\n");
                printf("1. Operazioni Elementari\n");
                printf("2. Cramer\n");
                printf("----------------\n");
                scanf("%d", &s);

                if (definedA == 0) {
                    printf("Definisci la matrice A (coefficienti): \n");
                    defMatrix(&A);
                    printf("\n\nA:\n");
                    stampaMatrix(A);
                    definedA = 1;
                }

                if (definedb == 0) {
                    printf("Definisci la matrice b (risultati): \n");
                    defMatrix(&b);
                    printf("\n\nb:\n");
                    stampaMatrix(b);
                    definedb = 1;
                }

                matcompleta(A, b, &B);

                if (s == 1) {
                    risOpElem(A, B);
                }
                if (s == 2) {
                    risCramer(A, b);
                }
                break;
            }

            case 2:
                if (definedA == 0) {
                    printf("Definisci la matrice A (coefficienti): \n");
                    defMatrix(&A);
                    printf("\n\nA:\n");
                    stampaMatrix(A);
                    definedA = 1;
                }

                if (definedb == 0) {
                    printf("Definisci la matrice b (risultati): \n");
                    defMatrix(&b);
                    printf("\n\nb:\n");
                    stampaMatrix(b);
                    definedb = 1;
                }

                matcompleta(A, b, &B);
                printf("B:\n");
                stampaMatrix(B);
                break;

            case 99:
                resetMatrix(&A);
                resetMatrix(&b);
                resetMatrix(&B);

                definedA = 0;
                definedb = 0;

                cls();
                printf("Tutte le variabili e matrici resettate!\n\n");
                printf("Ridefinisci a quante incognite è il sistema? ");
                scanf("%d", &m.c);
                printf("Ridefinisci a quante equazioni ha il sistema? ");
                scanf("%d", &m.r);

                A.r = m.r;
                A.c = m.c;

                b.r = m.r;
                b.c = 1;

                B.r = m.r;
                B.c = m.c + 1;

                cls();
                break;

            case 0:
                cls();
                break;

            default:
                cls();
                printf("Opzione non valida\n\n\n");
        }
    }while (scelta != 0);
}