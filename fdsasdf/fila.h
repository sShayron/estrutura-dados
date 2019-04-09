#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#define MAX 10
#if !defined(LISTA_H_INCLUDED)
#include "lista.h"
#endif

typedef int TipoF;

typedef struct TFila {
    int primeiro, ultimo;
    TipoF info[MAX];
} *Fila;

Fila inicFila(void);
void adicFila(Fila f, TipoF elem);
TipoF elimFila(Fila f);
TipoF infoFila(Fila f);
int vaziaFila(Fila f);
void destruirFila(Fila f);
void printFila(Fila f);
// Fila-01)
Fila copiarFila(Fila f);
// Fila-02)
int longFila(Fila f);
// Fila-03)
void concatFilas(Fila f1, Fila f2);
// Fila-04)
void invFila(Fila f);
// Fila-05)
int existeElemento(Fila f, TipoF elem);
// Fila-06)
int iguaisFilas(Fila f1, Fila f2);
// Fila-07)
void adicFilaPos(Fila f, TipoF elem, int pos);
// Fila-08)
void elimElemento( Fila f, TipoF elem);
// Fila-09)
void partirFila( Fila f, Fila f1, Fila f2, TipoF elem);


#endif // FILA_H_INCLUDED
