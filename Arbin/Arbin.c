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

    return estaArbin(esqArbin(a)) || estaArbin(dirArbin(a));
}
