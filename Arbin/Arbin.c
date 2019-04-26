#if !defined(ARBIN_H_INCLUDED)
#include "Arbin.h"
#endif

Arbin inicArbin() {
    return NULL;
}

Arbin esqArbin(Arbin a) {
    return a->esq;
}

Arbin dirArbin(Arbin a) {
    return a->dir;
}

TipoA raizArbin(Arbin a) {
    return a->info;
}

int vaziaArbin(Arbin a) {
    if(a == NULL)
        return 1;
    return 0;
}

int estaArbin(Arbin a, TipoA elem) {
    if(vaziaArbin(a)) {
        return 0;
    }
    if (raizArbin(a) == elem) {
        return 1;
    }

    return estaArbin(esqArbin(a), elem) || estaArbin(dirArbin(a), elem);
}

Arbin insereABB(Arbin a, TipoA elem) {
    if(vaziaArbin(a)) {
        a = (Arbin)malloc(sizeof(struct NodoArbin));
        a->info = elem;
        a->esq = NULL;
        a->dir = NULL;
    } else if (elem < a->info) {
        a->esq = insereABB(esqArbin(a), elem);
    } else {
        a->dir = insereABB(dirArbin(a), elem);
    }

    return a;
}

void visitar(TipoA elem) {
    printf("  %d  \n", elem);
}

void preOrdemArbin(Arbin a) {
    if(!vaziaArbin(a)) {
        visitar(a->info);
        preOrdemArbin(esqArbin(a));
        preOrdemArbin(dirArbin(a));
    }
}

int buscaNaArbinB(Arbin a, TipoA elem) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (elem == raizArbin(a)) {
        return 1;
    } else if (elem < raizArbin(a)) {
        buscaArbin(esqArbin(a), elem);
    } else {
        buscaArbin(dirArbin(a), elem);
    }
    return 0;
}

int buscaNaArbin(Arbin a, TipoA elem) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (elem == raizArbin(a)) {
        return 1;
    } else (elem < raizArbin(a)) {
        return (buscaArbin(esqArbin(a), elem) || buscaArbin(dirArbin(a), elem));
    }
    return 0;
}
