#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX 10
#if !defined(LISTA_H_INCLUDED)
#include "lista.h"
#endif
typedef int TipoP;
typedef struct TPilha {
    int topo;
    TipoP info[MAX];
} *Pilha;
Pilha inicPilha();
int cheiaPilha(Pilha p);
int vaziaPilha(Pilha p);
void push(Pilha p, TipoP elem);
TipoP pop(Pilha p);
void destruirPilha(Pilha p);
TipoP infoPilha(Pilha p);
// Pilha-01)
void invLista(Lista lst);
// Pilha-02)
Pilha copiarPilha(Pilha p);
// Pilha-03)
void invPilha(Pilha p);
// Pilha-04)
int iguaisPilhas( Pilha p1, Pilha p2);
// Pilha-05)
int avaliarExpressao(ListaExp lstExp);
// Pilha-06)
void imprimePilha(Pilha p);
// Pilha-07)
void fundoPilha(Pilha p, TipoP elem);
// Pilha-08)
int longPilha(Pilha p);
// Pilha-09)
void elimTodosPilha(Pilha p, TipoP elem);
// Pilha-10)
int somaPilha(Pilha p);
// Pilha-11)
int palindromePilha(Pilha p);

#endif // PILHA_H_INCLUDED
