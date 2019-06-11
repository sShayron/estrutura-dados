#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <string.h>
#define MAX 100

typedef struct avl {
  char info[MAX];
  int altura;
  struct avl *esq;
  struct avl *dir;
} Tavl, *AVL;

AVL novoNo(char value[MAX]);

int altura(AVL a);

int fatorBalanceamento(AVL arv);

int maior(int x, int y);

void rotateEsq(AVL arv);

void rotateDir(AVL arv);

void rotateRL(AVL arv);

void rotateLR(AVL arv);

int insereAvl(AVL arv, char val[MAX]);

AVL menorValorAvl(AVL arv);

int removeAvl(AVL arv, char val[MAX]);

void preOrdemAvl(AVL arv);

void destroiAvl(AVL a);


#endif
