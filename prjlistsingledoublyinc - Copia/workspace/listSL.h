#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED

#ifndef LISTADE_H_INCLUDED
    #include "listDL.h"
#endif // LISTADE_H_INCLUDED


typedef struct TinfoRodovia{
    char rodovia[MAX];
    ListaDE cidades;
} InfoRodovia;

// Lista Simplesmente Encadeada de Rodovias
typedef struct ListaNoSE
{
    InfoRodovia info;
    struct ListaNoSE *prox;
} *pListaNoSE;

typedef struct TListaSE
{
    pListaNoSE primeiro, ultimo, iterador;
    int longitude;
} * ListaSE;


ListaSE inicListaSE();

void primListaSE(ListaSE lst);
void ultListaSE(ListaSE lst);

void posListaSE(ListaSE lst, int pos);

int fimListaSE(ListaSE lst);

void segListaSE(ListaSE lst);

InfoRodovia infoListaSE(ListaSE lst);

int longListaSE(ListaSE lst);

//3 casos: Lista vazia, iterador sobre o ultimo elemento, iterador sobre um elemento intermediario
void anxListaSE( ListaSE lst, InfoRodovia elem );


//3 casos: Lista vazia, iterador sobre o primeiro elemento, iterador sobre qualquer outro elemento
void insListaSE( ListaSE lst, InfoRodovia elem );


void elimListaSE( ListaSE lst );


#endif // LISTASE_H_INCLUDED
