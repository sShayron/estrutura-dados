#if !defined(PILHA_H_INCLUDED)
#include "pilha.h"
#endif
#if !defined(LISTA_H_INCLUDED)
#include "lista.h"
#endif

Pilha inicPilha() {
    Pilha p = (Pilha)malloc(sizeof(struct TPilha));
    p->topo = -1;
    return p;
}

int cheiaPilha(Pilha p) {
    return p->topo == MAX - 1;
}

int vaziaPilha(Pilha p) {
    return p->topo == -1;
}

void push(Pilha p, TipoP elem) {
    if (cheiaPilha(p)) {
        printf("\nPilha cheia\n");
        return;
    }
    p->topo++;
    p->info[p->topo] = elem;
}

TipoP pop(Pilha p) {
    TipoP elem;

    if (vaziaPilha(p)) {
        printf("\nPilha vazia\n");
        return -1; // error
    }

    elem = p->info[p->topo];
    p->topo--;
    return elem;
}

void destruirPilha(Pilha p) {
    free(p);
}

TipoP infoPilha(Pilha p){
    if(vaziaPilha(p)) {
        printf("\nPilha vazia\n");
        return -1; // error
    }
    return p->info[p->topo];
}

void printPilha(Pilha p) {
    if(vaziaPilha(p)) {
        printf("\nPrintPilha: Pilha vazia\n");
        return;
    }
    int i;
    for(i = p->topo; i >= 0; i--) {
        printf("[%i]: %i\n", i, p->info[i]);
    }
}

// Pilha-01)
void invLista(Lista lst) {
    if (longLista(lst) == 1 || longLista(lst) == 0) {
        return;
    }

    Pilha p = inicPilha();
    int i;

    for(i = longLista(lst); i > 0; i--) {
        pListaNo noAux = noNaPosicao(lst, i);
        push(p, noAux->info);
        removeNo(lst, noAux);
    }

    while(!vaziaPilha(p)) {
        insLista(lst, pop(p));
    }
    destruirPilha(p);
}
// Pilha-02)
Pilha copiarPilha(Pilha p) {
    if (vaziaPilha(p)) {
        printf("\ncopiarPilha: Pilha vazia\n");
        return;
    }
    Pilha pAux = inicPilha();
    Lista lstAux = inicLista();

    while(!vaziaPilha(p)) {
        insLista(lstAux, pop(p));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        push(pAux, infoLista(lstAux));
        push(p, infoLista(lstAux));
    }

    free(lstAux);

    return pAux;
}
// Pilha-03)
void invPilha(Pilha p) {
    if (vaziaPilha(p)) {
        printf("\invPilha: Pilha vazia\n");
        return;
    }
    Lista lstAux = inicLista();

    while(!vaziaPilha(p)) {
        anexLista(lstAux, pop(p));
    }
    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        push(p, infoLista(lstAux));
    }

    free(lstAux);
}

// Pilha-04)
int iguaisPilhas(Pilha p1, Pilha p2) {
    if (vaziaPilha(p1) && vaziaPilha(p2)) {
        return 1;
    }
    if (p1->topo != p2->topo) {
        return 0;
    }
    int equals = 1;
    Lista lstAux1 = inicLista();
    Lista lstAux2 = inicLista();

    while(!vaziaPilha(p1)) {
        TipoP tpAux1 = pop(p1);
        TipoP tpAux2 = pop(p2);
        if(tpAux1 != tpAux2) {
            equals = 0;
        }
        insLista(lstAux1, tpAux1);
        insLista(lstAux2, tpAux2);
    }

    primLista(lstAux1);
    primLista(lstAux2);
    while(!fimLista(lstAux1)) {
        push(p1, infoLista(lstAux1));
        push(p2, infoLista(lstAux2));
        segLista(lstAux1);
        segLista(lstAux2);
    }

    return equals;
}
// Pilha-05)
int avaliarExpressao(ListaExp lstExp) {
    if (lstExp->longitude == 0) {
        printf("avaliarExpressao: Lista vazia.");
        return -1;
    }

    Pilha pAux = inicPilha();
    int sum = 0;

    for(primListaExp(lstExp); !fimListaExp(lstExp); segListaExp(lstExp)) {
        if( isdigit(lstExp->iterador->info[0]) ) {
            push(pAux, atoi(lstExp->iterador->info));
        } else {
            if (strcmp(lstExp->iterador->info, "+") == 0) {
                while(!vaziaPilha(pAux)) {
                    sum = sum + pop(pAux);
                }
            }
            if (strcmp(lstExp->iterador->info, "*") == 0) {
                while(!vaziaPilha(pAux)) {
                    if (sum == 0) {
                        sum = 1;
                    }
                    sum = sum * pop(pAux);
                }
           }
        }
    }
    return sum;
}
// Pilha-06)
void imprimePilha(Pilha p){
    printPilha(p);
}
// Pilha-07)
void fundoPilha(Pilha p, TipoP elem) {
    if (vaziaPilha(p)) {
        push(p, elem);
        return;
    }
    Lista lstAux = inicLista();

    while(!vaziaPilha(p)) {
        insLista(lstAux, pop(p));
    }

    push(p, elem);

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        push(p, infoLista(lstAux));
    }

    free(lstAux);
}
// Pilha-08)
int longPilha(Pilha p) {
    return p->topo + 1;
}
// Pilha-09)
void elimTodosPilha(Pilha p, TipoP elem) {
    if (vaziaPilha(p)) {
        printf("\nelimTodosPilha: Pilha vazia nenhum elemento para eliminar");
        return;
    }
    Lista lstAux = inicLista();

    while(!vaziaPilha(p)) {
        insLista(lstAux, pop(p));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        if (infoLista(lstAux) != elem) {
            push(p, infoLista(lstAux));
        }
    }
}
// Pilha-10)
int somaPilha(Pilha p) {
    if(vaziaPilha(p)) {
        printf("\somaPilha: Pilha vazia\n");
        return;
    }
    int i;
    int sum = 0;
    for(i = p->topo; i >= 0; i--) {
        sum += p->info[i];
    }
    return sum;
}
// Pilha-11)
int palindromePilha(Pilha p) {
    int i;
    int j;
    for (i = 0, j = p->topo; i < j; i++, j--){
        if (p->info[i] != p->info[j]) {
            return 0;
        }
    }
    return 1;
}


