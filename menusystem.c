#include <stdio.h>
#include "menusystem.h"
#include "algebra.h"


void Sysmenu() {
    cls();
    int inc;
    int eq;
    int r;
    int c;
    int cb = 1;

    printf("A quante incognite è il sistema? ");
    scanf("%d", &inc);
    printf("A quante equazioni ha il sistema? ");
    scanf("%d", &eq);

    c = inc;
    r = eq;

    float A[eq][inc];
    float b[eq][cb];
    float B[eq][inc+1];


    int definedA = 0;
    int definedb = 0;


    int scelta;
    do {
        printf("---- Sistemi Lineari ----\n");
        printf("1. Risoluzione\n");
        printf("2. Trova Matrice Completa\n");
        printf("99. Resetta Variabili e Matrici\n");
        printf("0. Esci\n");
        scanf("%d",&scelta);

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
                    defMatrix(eq, inc, A);
                    printf("\n\nA:\n");
                    stampaMatrix(eq, inc, A);
                    definedA = 1;
                }

                if (definedb == 0) {
                    printf("Definisci la matrice b (risultati): \n");
                    defMatrix(eq, cb, b);
                    printf("\n\nb:\n");
                    stampaMatrix(eq, cb, b);
                    definedb = 1;
                }

                matcompleta(r, c, cb, A, b, B);

                if (s == 1) {
                    risOpElem(r, c, A, B);
                }
                if (s == 2) {
                    risCramer(r, c, cb, A, b);
                }
                break;
            }

            case 2:
                if (definedA == 0) {
                    printf("Definisci la matrice A (coefficienti): \n");
                    defMatrix(eq, inc, A);
                    printf("\n\nA:\n");
                    stampaMatrix(eq, inc, A);
                    definedA = 1;
                }

                if (definedb == 0) {
                    printf("Definisci la matrice b (risultati): \n");
                    defMatrix(eq, cb, b);
                    printf("\n\nb:\n");
                    stampaMatrix(eq, cb, b);
                    definedb = 1;
                }

                matcompleta(r, c, cb, A, b, B);
                printf("B:\n");
                stampaMatrix(r, c+1, B);
                break;

            case 99:
                resetMatrix(r, c, A);
                resetMatrix(r,c, b);
                resetMatrix(r, c+1, B);

                definedA = 0;
                definedb = 0;

                cls();
                printf("Tutte le variabili e matrici resettate!\n\n");
                printf("Ridefinisci a quante incognite è il sistema? ");
                scanf("%d", &inc);
                printf("Ridefinisci a quante equazioni ha il sistema? ");
                scanf("%d", &eq);
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