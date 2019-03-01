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
}

//adiciona nó antes do iterador
void insLista(Lista lst, TipoL elem) {
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
}

// retorna verdadeiro se o iterador estiver indefinido
int fimLista(Lista lst) {
}

void printLista(Lista lst) {
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        printf("%i", infoLista(lst));
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
    struct ListaNo p;
    printf("Digita valor q vai ser info do no: ");
    scanf("%i", &i);
    p.info = i;
    p.prox = NULL;

    printf("Valor escolhido: %i", p.info);
    return 0;
}
