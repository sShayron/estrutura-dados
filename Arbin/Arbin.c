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

// 2)
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


// 1)
int pesoArbin(Arbin a) {
    if (vaziaArbin(a)) {
        return 0;
    }

    return 1 + pesoArbin(esqArbin(a)) + pesoArbin(dirArbin(a));
}

int eFolha(Arbin a) {
    return !vaziaArbin(a) && vaziaArbin(esqArbin(a)) && dirArbin(dirArbin(a));
}

// 3)
int numFolhas(Arbin a) {
    if(vaziaArbin(a)) {
        return 0;
    }
    if (eFolha(a)) {
        return 1;
    }
    return numFolhas(esqArbin(a)) + numFolhas(dirArbin(a));
}

// 5)
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

// 6)
int contaNivel(Arbin a, int nivel) {
    if (vaziaArbin(a)) {
        return 0;
    }
    if (nivel == 0) {
        return 1;
    }
    return contaNivel(esqArbin(a), nivel - 1) + contaNivel(esqArbin(a), nivel - 1);
}

// 18)
int nivelArbin(Arbin a, TipoA elem) {
    if (!estaArbin(a, elem)) {
        return -1;
    }

    return 1 + nivelArbin(esqArbin(a), elem) + nivelArbin(dirArbin(a), elem);
}

// 19)
int maiorElementoArbin(Arbin a) {
    if (vaziaArbin(a)) {
        return -1;
    }

    int maior = raizArbin(a);
    int maiorEsq = 0;
    int maiorDir = 0;

    if (!vaziaArbin(esqArbin(a))) {
        maiorEsq = maiorElementoArbin(esqArbin(a));

        if (maiorEsq > maior) {
            maior = maiorEsq;
        }
    }

    if (!vaziaArbin(dirArbin(a))) {
        maiorDir = maiorElementoArbin(dirArbin(a));

        if (maiorDir > maior) {
            maior = maiorDir;
        }
    }

    return maior;
}

// 11)
int iguaisArbin(Arbin a1, Arbin a2) {
    if(vaziaArbin(a1) && vaziaArbin(a2)) {
        return 1;
    }
    if (raizArbin(a1) == raizArbin(a2)) {
        return iguaisArbin(esqArbin(a1), esqArbin(a2)) && iguaisArbin(dirArbin(a1), dirArbin(a2));
    }
    return 0;
}

//4)
int numOcorrencias(Arbin a, tipoInfo elem){
    if(vaziaArbin(a))
        return 0;
    else if(raizArbin(a) == elem)
        return 1 + numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
    else
        return numOcorrencias(esqArbin(a),elem) + numOcorrencias(dirArbin(a),elem);
}

// 7)
int semelhantesArbin(Arbin a1, Arbin a2) {
    if (pesoArbin(a1) != pesoArbin(a2)) {
        return 0;
    }
    return semelhantesArbin(a1, a2);
}

int semelhantesArbinB(Arbin a1, Arbin a2) {
    if(vaziaArbin(a1)) {
        return 1;
    }
    if (estaArbin(a2, raizArbin(a1))) {
        return semelhantesArbin(esqArbin(a1), a2) && semelhantesArbin(dirArbin(a1), a2);
    }
    return 0;
}
int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}//maior

// 10)
int alturaArbin(Arbin a){
   if((a == NULL) || (esqArbin(a) == NULL && dirArbin(a) == NULL))
       return 0;
   else
       return 1 + maior(alturaArbin(esqArbin(a)), alturaArbin(dirArbin(a)));
}

// 12)
int isomorfas(Arbin a1, Arbin a2) {
    return (pesoArbin(a1) == pesoArbin(a2)) && (alturaArbin(a1) == alturaArbin(a2));
}

// 13)
int completaArbin(Arbin a) {
    int esqEdirVazia = (vaziaArbin(esqArbin(a)) && vaziaArbin(dirArbin(a)));
    int esqEdirExiste = (!vaziaArbin(esqArbin(a)) && !vaziaArbin(dirArbin(a)));
    if(a == NULL)
       return 1;

    if (esqEdirVazia || esqEdirExiste) {
        return completaArbin(dirArbin(a)) && completaArbin(esqArbin(a));
    }
    return 0;
}

// 14)
int cheiaArbin(Arbin a) {
    if (vaziaArbin(a)) {
        return 1;
    }
    if (numFolhas(dirArbin(a)) == numFolhas(esqArbin(a))) {
        return cheiaArbin(esqArbin(a)) && cheiaArbin(dirArbin(a));
    }
    return 0;
}

// 16)
int ocorreArbin(Arbin a1, Arbin a2) {
    if (vaziaArbin(a2)) {
        return 1;
    }

    if (estaArbin(a1, raizArbin(a2))) {
        return ocorreArbin(a1, dirArbin(a2)) && ocorreArbin(a1, esqArbin(a2));
    }

    return 0;
}

