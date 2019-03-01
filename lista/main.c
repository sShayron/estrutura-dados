#include <stdio.h>
#include <stdlib.h>

typedef int TipoL;
typedef struct ListaNo {
    TipoL info;
    struct ListaNo *prox;
} *pListaNo;
typedef struct Tlista {
    pListaNo
        primeiro,
        ultimo,
        iterador;
    int longitude;
} *Lista;

//adiciona nó depois do iterador
void anexLista(Lista lst, TipoL elem) {
    pListaNo no = malloc(sizeof(struct ListaNo));
    no->info = elem;
    if (lst->iterador == NULL) {
        lst->iterador = no;
        lst->primeiro = no;
        lst->ultimo = no;
        return;
    }
    if (lst->iterador->prox != NULL) {
        no->prox = lst->iterador->prox;
        lst->iterador->prox = no;
    } else {
        lst->ultimo = no;
    }
    lst->iterador = no;
}

//adiciona nó antes do iterador
void insLista(Lista lst, TipoL elem) {
    pListaNo no = malloc(sizeof(struct ListaNo));
    no->info = elem;
    if (lst->iterador == NULL) {
        lst->iterador = no;
        lst->primeiro = no;
        lst->ultimo = no;
        return;
    }
    if (lst->iterador == lst->primeiro) {
        lst->primeiro = no;
    }
    no->prox = lst->iterador;
    lst->iterador = no;
}

//remove um nó da lista
void elimLista(Lista lst) {
}

//coloca iterador sobre o primeiro element
void primLista(Lista lst) {
}

//coloca iterador sobre o ultimo element
void ultLista(Lista lst) {
}

// avança o iterador uma posicao
void segLista(Lista lst){
}

//coloca o iterador sobre a posicao pos
void posLista(Lista lst, int pos) {
}

// retorna o elemento sob o iterador
TipoL infoLista(Lista lst) {
}

// retorna a quantidade de elementos na lista
TipoL longLista(Lista lst) {
    return lst->longitude;
}

// retorna verdadeiro se o iterador estiver indefinido
int fimLista(Lista lst) {
}

void printLista(Lista lst) {
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        printf("%i", infoLista(lst));
    }
}

int iguaisListas(Lista lst1, Lista lst2){

    //verificar se lst1 e lst2 sao vazias
    if(longLista(lst1) == 0 && longLista(lst2)== 0)
        return 1;
    //senao se long de lst1 == long lst2
    if(longLista(lst1) == longLista(lst2)){
        //percorrer lst1 e lst2 e comparar noh a noh
        for(primLista(lst1), primLista(lst2); !fimLista(lst1); segLista(lst1), segLista(lst2)){
            if(infoLista(lst1) != infoLista(lst2))
                return 0;
        }
        return 1;
    }
    else{
        //senao nao sao iguais
        return 0;
    }

}



TipoL maiorElemento(Lista lst) {
    TipoL maior;
    if (longLista(lst) == 0) {
        return NULL;
    } else {
        primLista(lst);
        maior = infoLista(lst);

        for(primLista(lst); !fimLista(lst); segLista(lst)) {
            if (infoLista(lst) > maior) {
                maior = infoLista(lst);
            }
        }
    }
    return maior;
}

int estaLista(Lista lst, TipoL elem) {
    if (longLista(lst) == 0) {
        return 0;
    } else {
        for(primLista(lst); !fimLista(lst); segLista(lst)) {
            if (infoLista(lst) == elem) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i;

    // COM STRUCT
    struct ListaNo p;
    printf("Digita valor q vai ser info do no: ");
    scanf("%i", &i);
    p.info = i;
    p.prox = NULL;
    printf("Valor escolhido: %i", p.info);

    // COM PONTEIRO
    pListaNo pp = malloc(sizeof(struct ListaNo));
    printf("\n\nDigita valor q vai ser info do no: ");
    scanf("%i", &i);
    pp->info = i;
    pp->prox = NULL;
    printf("Valor escolhido: %i", pp->info);
    return 0;
}
