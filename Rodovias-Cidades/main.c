#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo Cidade
typedef struct TCidade {
    char *nome;
    struct TCidade *prox;
    struct TCidade *ant;
} *pCidade;

// Tipo Rodovia
typedef struct TRodovia {
    char *nome;
    struct TCidade *cidades;
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
void setIterador(pLista lst, pRodovia rodovia) {
    lst->iterator = rodovia;
}
void setUltimo(pLista lst, pRodovia rodovia) {
    lst->ultimo = rodovia;
}

static pRodovia criaRodovia(char *nome, pCidade cidades, pRodovia prox) {
  pRodovia rodovia = (pRodovia)malloc(sizeof(struct TRodovia));
  rodovia->nome = nome;
  rodovia->cidades = cidades;
  rodovia->prox = prox;
  return rodovia;
}

static pCidade criaCidade(char *nome, pCidade ant, pCidade prox) {
    pCidade cidade = (pCidade)malloc(sizeof(struct TCidade));
    cidade->nome = nome;
    cidade->ant = ant;
    cidade->prox = prox;
    return cidade;
}

int main() {

//    printf("Hello world!\n");
//    char val[61];
//    printf("val: ");
//    scanf("%s", val);
//    printf("O nome armazenado foi: %s", val);

    pCidade vitoria = criaCidade("Vitoria", NULL, NULL);
    pCidade vilavelha = criaCidade("Vila Velha", NULL, vitoria);
    vitoria->ant = vilavelha;
    pRodovia rodovia = criaRodovia("BR-101", NULL, NULL);
    rodovia->cidades = vilavelha;
    printf("Nome da rodovia: %s", rodovia->nome);
    printf("\nPassa pelas cidades:\n");

    while(rodovia->cidades != NULL) {
        printf("%s", rodovia->cidades->nome);
        if (rodovia->cidades->prox != NULL) {
            printf("->");
        }
        rodovia->cidades = rodovia->cidades->prox;
    }
    return 0;
}
