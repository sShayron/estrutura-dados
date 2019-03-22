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
        *iterador,
        *ultimo;
    int tamanho;
} *pLista;

void setPrimeiro(pLista lst, pRodovia rodovia) {
    lst->primeiro = rodovia;
}
void setIterador(pLista lst, pRodovia rodovia) {
    lst->iterador = rodovia;
}
void setUltimo(pLista lst, pRodovia rodovia) {
    lst->ultimo = rodovia;
}
void incrementaLongitude(pLista lst) {
    lst->tamanho++;;
}
void decrementaLongitude(pLista lst) {
    lst->tamanho--;
}
pLista inicLista(void) {
    pLista lst = (pLista)malloc(sizeof(struct TLista));
    setPrimeiro(lst, NULL);
    setUltimo(lst, NULL);
    setIterador(lst, NULL);
    lst->tamanho = 0;
    return lst;
}
void segLista(pLista lst){
    if (lst->iterador == NULL)
        return;
    lst->iterador = lst->iterador->prox;
}
int longLista(pLista lst) {
    return lst->tamanho;
}
int fimLista(pLista lst) {
    return lst->iterador == NULL;
}
void primLista(pLista lst) {
    lst->iterador = lst->primeiro;
}
void anexLista(pLista lst, pRodovia rodovia) {
    if (lst->tamanho == 0) {
        setIterador(lst, rodovia);
        setPrimeiro(lst, rodovia);
        setUltimo(lst, rodovia);
        incrementaLongitude(lst);
        return;
    }
    if (lst->iterador->prox != NULL) {
        rodovia->prox = lst->iterador->prox;
    } else {
        setUltimo(lst, rodovia);
    }
    lst->iterador->prox = rodovia;
    setIterador(lst, rodovia);
    incrementaLongitude(lst);
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
    pCidade tmp = rodovia->cidade;
    while(rodovia->cidade != NULL) {
        printf("%s", rodovia->cidade->nome);
        if (rodovia->cidade->prox != NULL) {
            if (rodovia->cidade->prox->prox == NULL) {
                printf(" e ");
            } else {
                printf(", ");
            }
        }
    rodovia->cidade = rodovia->cidade->prox;
    }
    rodovia->cidade = tmp;
}

void exibeRodoviaInfos(pRodovia rodovia) {
    printf("\n%s", rodovia->nome);
    if (rodovia->cidade != NULL) {
        printf("\nPassa pelas cidades: ");
        exibeCidades(rodovia);
    }
}

void exibeRodoviasNaLista(pLista lst) {
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        exibeRodoviaInfos(lst->iterador);
        printf("\n");
    }
}
pLista rodoviasCidade(char nomeCidade[120], pLista lstRodovias) {
    pLista newLstRodovias = inicLista();
    pRodovia newRodovia;
    pCidade tmp;
    for(primLista(lstRodovias); !fimLista(lstRodovias); segLista(lstRodovias)) {
        primCidade(lstRodovias->iterador);
        tmp = lstRodovias->iterador->cidade;
        while(lstRodovias->iterador->cidade != NULL) {
            if(strcmp(lstRodovias->iterador->cidade->nome, nomeCidade) == 0) {
                newRodovia = criaRodovia(lstRodovias->iterador->nome, NULL, NULL);
                anexLista(newLstRodovias, newRodovia);
            }
            lstRodovias->iterador->cidade = lstRodovias->iterador->cidade->prox;
        }
        lstRodovias->iterador->cidade = tmp;
    }

    return newLstRodovias;
}


int main() {
    // BR 101
    pCidade br101c1 = criaCidade("Rio de Janeiro", NULL, NULL);
    pCidade br101c2 = criaCidade("Natal", NULL, NULL);
    pCidade br101c3= criaCidade("Aracaju", NULL, NULL);
    pCidade br101c4= criaCidade("Itabuna", NULL, NULL);
    pCidade br101c5= criaCidade("Teixeira de Freitas", NULL, NULL);
    pCidade br101c6= criaCidade("Alagoinhas", NULL, NULL);
    pCidade br101c7= criaCidade("Serra", NULL, NULL);
    pCidade br101c8= criaCidade("Vitoria", NULL, NULL);

    pRodovia rodoviaBR101 = criaRodovia("BR-101", NULL, NULL);
    anexCidade(rodoviaBR101, br101c1);
    anexCidade(rodoviaBR101, br101c2);
    anexCidade(rodoviaBR101, br101c3);
    anexCidade(rodoviaBR101, br101c4);
    anexCidade(rodoviaBR101, br101c5);
    anexCidade(rodoviaBR101, br101c6);
    anexCidade(rodoviaBR101, br101c7);
    anexCidade(rodoviaBR101, br101c8);

    // BR 262
    pCidade br262c1 = criaCidade("Manhuacu", NULL, NULL);
    pCidade br262c2 = criaCidade("Belo Horizonte", NULL, NULL);
    pCidade br262c3= criaCidade("Araxa", NULL, NULL);
    pCidade br262c4= criaCidade("Uberaba", NULL, NULL);
    pCidade br262c5= criaCidade("Campo Grande", NULL, NULL);
    pCidade br262c6= criaCidade("Tres Lagoas", NULL, NULL);
    pCidade br262c7= criaCidade("Serra", NULL, NULL);
    pCidade br262c8= criaCidade("Vitoria", NULL, NULL);

    pRodovia rodoviaBR262 = criaRodovia("BR-262", NULL, NULL);
    anexCidade(rodoviaBR262, br262c1);
    anexCidade(rodoviaBR262, br262c2);
    anexCidade(rodoviaBR262, br262c3);
    anexCidade(rodoviaBR262, br262c4);
    anexCidade(rodoviaBR262, br262c5);
    anexCidade(rodoviaBR262, br262c6);
    anexCidade(rodoviaBR262, br262c7);
    anexCidade(rodoviaBR262, br262c8);

    // BR 393
    pCidade br393c1 = criaCidade("Volta Redonda", NULL, NULL);
    pCidade br393c2 = criaCidade("Muqui", NULL, NULL);
    pCidade br393c3= criaCidade("Itaperuna", NULL, NULL);
    pCidade br393c4= criaCidade("Mimoso do Sul", NULL, NULL);
    pCidade br393c5= criaCidade("Pirapetinga", NULL, NULL);
    pCidade br393c6= criaCidade("Cachoeiro de itapemirim", NULL, NULL);
    pCidade br393c7= criaCidade("Vassouras", NULL, NULL);
    pCidade br393c8= criaCidade("Tres rios", NULL, NULL);

    pRodovia rodoviaBR393 = criaRodovia("BR-393", NULL, NULL);
    anexCidade(rodoviaBR393, br393c1);
    anexCidade(rodoviaBR393, br393c2);
    anexCidade(rodoviaBR393, br393c3);
    anexCidade(rodoviaBR393, br393c4);
    anexCidade(rodoviaBR393, br393c5);
    anexCidade(rodoviaBR393, br393c6);
    anexCidade(rodoviaBR393, br393c7);
    anexCidade(rodoviaBR393, br393c8);

    // Lista das rodovias
    pLista lstRodovias = inicLista();
    anexLista(lstRodovias, rodoviaBR101);
    anexLista(lstRodovias, rodoviaBR262);
    anexLista(lstRodovias, rodoviaBR393);
    exibeRodoviasNaLista(lstRodovias);

    printf("\n\n");
    char val[120];
    printf("Pesquisar rodovias que passam na cidade: ");
    gets(val);
    pLista lstRodoviasQPassamCidade = rodoviasCidade(val, lstRodovias);
    if (lstRodoviasQPassamCidade->tamanho == 0) {
        printf("Nenhuma rodovia encontrada");
    } else {
        printf("\nRodovias que passam na cidade %s: ", val);
        exibeRodoviasNaLista(lstRodoviasQPassamCidade);
    }


    return 0;
}
