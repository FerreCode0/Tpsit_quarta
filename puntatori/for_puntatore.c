// funzione = int, float, char ...
// procedura = void
// || = or (o uno o l'altro)
// && = and (deve essere tutto)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define DIM 5

int main(){
    int v[DIM] = {1, 2, 3, 5, 4};

    for(int *p = v; p < v + DIM; p++){   // se si sommo v + DIM un vettore piu un numero si ottiene un piuntatore
        printf("insdirizzo %d\n", p);
        printf("valore %d\n", *p);
        printf("differenza tra 2 puntatori %d\n", p - v); // la differenza tra due puntatori danno come risultato in int(intero)
    }
    return 0;
}