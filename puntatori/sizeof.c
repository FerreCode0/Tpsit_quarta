// funzione = int, float, char ...
// procedura = void
// || = or (o uno o l'altro)
// && = and (deve essere tutto)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(){
    printf("int: %d byte\n", sizeof(int));
    printf("float: %d byte\n", sizeof(float));
    printf("double: %d byte\n", sizeof(double));
    printf("char: %d byte\n", sizeof(char));
    printf("bool: %d byte\n", sizeof(bool));
    

    return 0;
}
