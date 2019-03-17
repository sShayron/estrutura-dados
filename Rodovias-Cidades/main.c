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
    struct TCidade *cidade;
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

pRodovia criaRodovia(char *nome, pCidade cidade, pRodovia prox) {
  pRodovia rodovia = (pRodovia)malloc(sizeof(struct TRodovia));
  rodovia->nome = nome;
  rodovia->cidade = cidade;
  rodovia->prox = prox;
  return rodovia;
}

pCidade criaCidade(char *nome, pCidade ant, pCidade prox) {
    pCidade cidade = (pCidade)malloc(sizeof(struct TCidade));
    cidade->nome = nome;
    cidade->ant = ant;
    cidade->prox = prox;
    return cidade;
}

// Aponta cidades da rodovia para primeira cidade
void primCidade(pRodovia rodovia) {
    if (rodovia->cidade == NULL)
        return;
    while(rodovia->cidade->ant != NULL) {
        rodovia->cidade = rodovia->cidade->ant;
    }
}
// Aponta cidades da rodovia para ultima cidade
void ultCidade(pRodovia rodovia) {
    if (rodovia->cidade == NULL)
        return;
    while(rodovia->cidade->prox != NULL) {
        rodovia->cidade = rodovia->cidade->prox;
    }
}

void anexCidade(pRodovia rodovia, pCidade cidade) {
    ultCidade(rodovia);

    if (rodovia->cidade != NULL) {
        cidade->ant = rodovia->cidade;
        rodovia->cidade->prox = cidade;
        return;
    }

    rodovia->cidade = cidade;
}

void exibeCidades(pRodovia rodovia) {
    primCidade(rodovia);

    while(rodovia->cidade != NULL) {
        printf("%s", rodovia->cidade->nome);
        if (rodovia->cidade->prox != NULL) {
            printf("->");
        }
        rodovia->cidade = rodovia->cidade->prox;
    }
}


int main() {

//    printf("Hello world!\n");
//    char val[61];
//    printf("val: ");
//    scanf("%s", val);
//    printf("O nome armazenado foi: %s", val);

    pCidade vitoria = criaCidade("Vitoria", NULL, NULL);
    pCidade vilavelha = criaCidade("Vila Velha", NULL, NULL);
    pRodovia rodovia = criaRodovia("BR-101", NULL, NULL);
    anexCidade(rodovia, vilavelha);
    anexCidade(rodovia, vitoria);
    printf("Nome da rodovia: %s", rodovia->nome);
    printf("\nPassa pelas cidades:\n");
    exibeCidades(rodovia);
    return 0;
}
