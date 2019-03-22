#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int TipoP;

typedef struct Pilha{
    int topo;
    TipoP info[MAX];
} *pPilha;

Pilha inicPilha() {
    Pilha p = (Pilha)malloc(sizeof(struct TPilha));
    p->topo = -1;
    return p;
}

int vaziaPilha(pPilha p) {
    return p->topo == -1;
}

void push(pPilha p, TipoP elem) {
    if (p->topo == MAX - 1) {
        printf("\nPilha cheia\n");
        return;
    }
    p->topo++;
    p->info[p->topo] = elem;
}

TipoP pop(pPilha p) {
    TipoP elem;

    if (vaziaPilha(p)) {
        printf("\nPilha vazia\n");
        return;
    }

    elem = p->info[p->topo];
    p->topo--;
    return elem;
}

void destruirPilha(pPilha p) {
    free(p);
}

TipoP infoPilha(pPilha p){
    if(vaziaPilha(p)) {
        printf("\nPilha vazia\n");
        return;
    }
    return p->info[p->topo];
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
