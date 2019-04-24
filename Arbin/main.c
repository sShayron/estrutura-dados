#include <stdio.h>
#include <stdlib.h>

typedef int TipoA;

typedef struct NoDoArbin {
    TipoA info;
    struct NoDoArbin *esq, *dir;
} Tarbin, *Arbin;

Arbin inicArbin() {
}

Arbin esqArbin(Arbin a) {
}

Arbin dirArbin(Arbin a) {
}

int vaziaArbin(Arbin a) {
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

int main()
{
    printf("Hello world!\n");
    return 0;
}
