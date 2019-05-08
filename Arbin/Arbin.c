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

int buscaNaArbinABB(Arbin a, TipoA elem) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (elem == raizArbin(a)) {
        return 1;
    } else if (elem < raizArbin(a)) {
        buscaNaArbinABB(esqArbin(a), elem);
    } else {
        buscaNaArbinABB(dirArbin(a), elem);
    }
    return 0;
}

int buscaNaArbin(Arbin a, TipoA elem) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (elem == raizArbin(a)) {
        return 1;
    } else {
        return (buscaArbin(esqArbin(a), elem) || buscaArbin(dirArbin(a), elem));
    }
    return 0;
}

int pesoArbin(Arbin a) {
    if (vaziaArbin(a)) {
        return 0;
    }

    return 1 + pesoArbin(esqArbin(a)) + pesoArbin(dirArbin(a));
}

int eFolha(Arbin a) {
    return !vaziaArbin(a) && vaziaArbin(esqArbin(a)) && dirArbin(dirArbin(a));
}

int numFolhas(Arbin a) {
    if(vaziaArbin(a)) {
        return 0;
    }
    if (eFolha(a)) {
        return 1;
    }
    return numFolhas(esqArbin(a)) + numFolhas(dirArbin(a));
}

int existeCaminho(Arbin a, TipoA elem1, TipoA elem2) {
    if(vaziaArbin(a)) {
        return 0;
    }
    if (elem1 === raizArbin(a)) {
        return buscaNaArbin(a, elem2);
    }
    return existeCaminho(esqArbin(a), elem1, elem2) || existeCaminho(dirArbin(a), elem1, elem2);
}

int existeCaminhoABB(Arbin a, TipoA elem1, TipoA elem2) {
    if(vaziaArbin(a)) {
        return 0;
    }
    if (elem1 === raizArbin(a)) {
        return buscaNaArbin(a, elem2);
    }
    if (elem1 < raizArbin(a)) {
        return existeCaminhoABB(esqArbin(a), elem1, elem2);
    }
    return existeCaminho(dirArbin(a), elem1, elem2);
}

int contaNivel(Arbin a, int nivel) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (nivel == 0) {
        return 1;
    }
    return contaNivel(esqArbin(a), nivel - 1) + contaNivel(esqArbin(a), nivel - 1);
}

int iguaisArbin(Arbin a1, Arbin a2) {
    if(vaziaArbin(a1) && vaziaArbin(a2)) {
        return 1;
    }
    if (raizArbin(a1) == raizArbin(a2)) {
        return iguaisArbin(esqArbin(a1), esqArbin(a2)) && iguaisArbin(dirArbin(a1), dirArbin(a2));
    }
    return 0;
}
