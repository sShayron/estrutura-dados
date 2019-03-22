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

void push(pPilha p, TipoP elem) {
    p->topo++;
    p->info[p->topo] = elem;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
