#include <stdio.h>
#include <stdlib.h>

// Tipo Cidade
typedef struct TCidade {
    char nome[50];
    struct TCidade *prox;
    struct TCidade *ant;
} *pCidade;

// Tipo Rodovia
typedef struct TRodovia {
    char nome[50];
    struct TCidade cidades;
    struct TRodovia *prox;
} *pRodovia;

// Lista de rodovias
typedef struct TLista {
    struct TRodovia
        *primeiro,
        *iterator,
        *ultimo;
    int tamanho;
} *pLista;

void setPrimeiro(pLista lst, pRodovia rodovia) {
    lst->primeiro = rodovia;
}

int main() {

    printf("Hello world!\n");
    return 0;
}
