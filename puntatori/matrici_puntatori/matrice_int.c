#include <stdio.h>
#include <stdlib.h>

#define DIM1 5
#define DIM2 8

int main() {
    int **a;
    int i, j;

    a = (int **)malloc(DIM1 * sizeof(int *));
    if (a == NULL) {
        printf("Errore di allocazione memoria!\n");
        return 1;
    }

    for (i = 0; i < DIM1; i++) {
        a[i] = (int *)malloc(DIM2 * sizeof(int));
        if (a[i] == NULL) {
            printf("Errore di allocazione memoria alla riga %d!\n", i);
            return 1;
        }
    }

    // Inizializzazione della matrice
    for (i = 0; i < DIM1; i++) {
        for (j = 0; j < DIM2; j++) {
            a[i][j] = i * j;
        }
    }

    // Stampa della matrice
    printf("Matrice %dx%d:\n", DIM1, DIM2);
    for (i = 0; i < DIM1; i++) {
        for (j = 0; j < DIM2; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    // Deallocazione della memoria
    for (i = 0; i < DIM1; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
