#include <stdio.h>
#include <stdlib.h>

typedef struct TCidades {
    char nome[50];
    struct TCidades *prox;
    struct TCidades *ant;
} *pCidades;

typedef struct TRodovias {
    char nome[50]; // nome da rodovia
    struct TRodovias
        *iterator,
        *primeiro,
        *ultimo;
    pCidades cidades; // cidades que a rodovia passa
} *pRodovias;


int main()
{

    printf("Hello world!\n");
    return 0;
}
