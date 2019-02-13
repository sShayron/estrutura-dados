#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main()
{
    int i;
    float *v1, *v2, *prodVet;
    v1 = (float *) malloc(MAX * sizeof(float));
    v2 = (float *) malloc(MAX * sizeof(float));
    prodVet = (float *) malloc(MAX * sizeof(float));

    void print_vet(float * v) {
        for (i = 0; i < MAX ; i++) {
            printf("vet[%i]: %f\n", i, *(v+i));
        }
        printf("\n\n");
    }

    printf("Entre com os valores do 1o vetor\n");
    for (i=0; i<MAX; i++) scanf("%f",&v1[i]);

    printf("Entre com os valores do 2o vetor\n");
    for (i=0; i<MAX; i++) scanf("%f",&v2[i]);

    void prod_vet(float* u, float* v) {
        int x = 0, y = 1, z = 2;
        prodVet[0] = u[y] * v[z] - v[y] * u[z];
        prodVet[1] = u[z] * v[x] - v[y] * u[x];
        prodVet[2] = u[x] * v[y] - v[x] * u[y];
    }


    print_vet(v1);
    print_vet(v2);
    prod_vet(v1, v2);
    printf("Calcula produto dos vetores...\n\n");
    print_vet(prodVet);
    free(v1);
    free(v2);
    free(prodVet);
    return 0;
}
