#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int i;
    int * vet;
    vet = (int *) malloc (MAX * sizeof(int));

    for (i = 0; i < MAX ; i++) {
        vet[i] = i + 1;
    }

    void print_vet(int * v) {
        for (i = 0; i < MAX ; i++) {
            printf("vet[%i]: %i\n", i, v[i]);
        }
    }

    void incr_vet(int * v, int n) {
        for (i = 0; i < n ; i++) {
            vet[i] = vet[i] + 1;
        }
    }

    print_vet(vet);
    incr_vet(vet, MAX);
    printf("\n\nSOMANDO +1 ...\n\n");
    print_vet(vet);
    printf("\n\nEndereco do vetor: %i\n\n", vet);
    free(vet);
    return 0;
}
