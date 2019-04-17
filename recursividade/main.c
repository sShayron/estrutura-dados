#include <stdio.h>
#include <stdlib.h>

int printsecres(int n) {
    if (n == 0){
        printf("%d-", n);
    } else {
        printf("%d-", n);
        printsecres(n-1);
    }
}

int fibonaci(int n) {
    if(n < 0) return;

    if (n == 0) {
        return 0;
    } else {
        if (n == 1) {
            return 1;
        } else {
            return (fibonaci(n-1) + fibonaci(n -2));
        }
    }
}
int maiorElem (int *vet, int n) {
    if (n == 0) return 0;
    if (n == 1) return vet[0];

    int maior = vet[n-1];
    int anterior = maiorElem(vet, n-1);
    if (anterior > maior) {
        maior = anterior;
    }
    return maior;
}
int somaVet(int *vet, int n) {
    if(n == 1) return vet[0];
    return vet[n-1] + somaVet(vet, n-1);
}

int main()
{
    int n = 10;
    printsecres(n);
    printf("Hello world!\n");

    printf("\nFIBONACI 8: %d", fibonaci(8));

    int sizeVet = 5;
    int vetor[sizeVet];
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 5;
    vetor[4] = 2;
    printf("\nMAIOR ELEM: %d", maiorElem(vetor, sizeVet));

    printf("\nSOMA: %d", somaVet(vetor, sizeVet));

    return 0;
}
