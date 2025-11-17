#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 5


int main() {
    int n[LUNG];
    int *p;
    int max = 0;

    printf("inserisci i numeri di cui vuoi sapere il piu grande\n");
    for(p = n; p < n + LUNG; p++) {
        printf("numero:");
        scanf("%d", p);
        if(max <= *p) max = *p;
    }
    printf("il numero piu grande e': %d", max);

    return 0;
}




/*void bubbleSort1(int vett[], int n) {
    int k, sup;
    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k+1])
                scambio( &vett[k],&vett[k+1]);
                   
        }
            
    }
}

void scambio(int *a, int *b) {
    int z;
    z = *a;
    *a = *b;
        *b = z;
}*/
