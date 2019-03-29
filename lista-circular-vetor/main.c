#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef int TipoF;

typedef struct TFila {
    int primeiro, ultimo;
    TipoF info[MAX];
} *Fila;

Fila inicFila(void) {
  Fila f = (Fila) malloc(sizeof(struct TFila));
  f->primeiro = -1;
  f->ultimo = -1;

  return f;
}
void adicFila(Fila f, TipoF elem) {
    if(f->primeiro == -1) {
        f->primeiro = 0;
        f->ultimo = 0;
        f->info[0] = elem;
    } else if((f->ultimo + 1)%MAX == f->primeiro){
        printf("Fila cheia");
    } else {
        f->ultimo = (f->ultimo + 1) % MAX;
        f->info[f->ultimo] = elem;
    }
}
TipoF elimFila(Fila f) {
    TipoF aux;

    if (f->primeiro == -1) {
        printf("Fila vazia");
    } else if (f->primeiro == f->ultimo) {
        aux = f->info[f->primeiro];
        f->primeiro = -1;
        f->ultimo = -1;
        return aux;
    } else {
        aux = f->info[f->primeiro];
        f->primeiro = (f->primeiro + 1)%MAX;
        return aux;
    }
}
TipoF infoFila(Fila f) {
    if(f->primeiro == -1) {
        printf("Fila vazia");
    } else {
        return f->info[f->primeiro];
    }
}
int vaziaFila(Fila f) {
    return (f->primeiro == -1);
}
void destruirFila(Fila f) {
    free(f);
}

void printFila(Fila f) {
    if (vaziaFila(f)) {
        printf("Fila vazia");
    } else {
        Fila copia = inicFila();
        TipoF elem;

        while(!vaziaFila(f)) {
            elem = elimFila(f);
            printf(" %d ", elem);
            adicFila(copia, elem);
        }
        printf("\n");

        while(!vaziaFila(copia)) {
            adicFila(f, elimFila(copia));
        }
        destruirFila(copia);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
