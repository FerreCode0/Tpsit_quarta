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

    int *p = v;
    int *q = v + 1;

    for(p = v; p < v + DIM - 1; p++){
        for(q = p + 1; q < v + DIM; q++){
            if(*p > *q){
                int temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }

    for(p = v; p < v + DIM; p++){
        printf("%d\n", *p);
    }

    return 0;
}
