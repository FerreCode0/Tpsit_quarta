#include <stdio.h>

int main(){
    int vet[5];
    int *pi;
    pi = vet;
    
    printf("%p %p", vet + 20, pi);
    printf("\n%d", *(vet + 20));
    return 0;
}