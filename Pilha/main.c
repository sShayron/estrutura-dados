#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int TipoP;

typedef struct Pilha{
    int topo;
    TipoP info[MAX];
} *pPilha;

pPilha inicPilha() {
    pPilha p = (pPilha)malloc(sizeof(struct Pilha));
    p->topo = -1;
    return p;
}

int cheiaPilha(pPilha p) {
    return p->topo == MAX - 1;
}

int vaziaPilha(pPilha p) {
    return p->topo == -1;
}

void push(pPilha p, TipoP elem) {
    if (cheiaPilha(p)) {
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
        return -1; // error
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
        return -1; // error
    }
    return p->info[p->topo];
}

void printPilha(pPilha p) {
    if(vaziaPilha(p)) {
        printf("\nPilha vazia\n");
        return;
    }
    int i;
    for(i = p->topo; i >= 0; i--) {
        printf("[%i]: %i\n", i, p->info[i]);
    }
}

int main()
{
    printf("Hello world!\n");
    pPilha p = inicPilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);
    printPilha(p);
    return 0;
}
