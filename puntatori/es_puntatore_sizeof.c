#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n;       // numero di elementi
    int *v;   // puntatore al vettore

    printf("Quanti elementi vuoi inserire?: ");
    scanf("%d", n);

    v = (int*) malloc(*n * sizeof(int));

    printf("Inserisci %d numeri:\n", *n);
    for (int *p = v; p < v + *n; p++) {
        printf("Elemento %d: ", p - v + 1);
        scanf("%d", p);
    }

    printf("\nHai inserito:\n");
    for (int *p = v; p < v + *n; p++) {
        printf("%d ", *p);
    }

    free(v);

    return 0;
}
