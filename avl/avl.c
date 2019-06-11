#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(AVL_H_INCLUDED)
#include "avl.h"
#endif

AVL novoNo(char value[MAX]) {
    AVL a = (AVL)malloc(sizeof(struct avl));
    strcpy(a->info, value);
    a->esq = NULL;
    a->dir = NULL;
    a->altura = 0;
    printf("VAL CRIADO: %s", a->info);
    return a;
}

// retorna a altura da arvore, armazenada no no:
int altura(AVL a)
{
  if (a != NULL)
  {
    return a->altura;
  }
  return -1;
}

// retorna o fator de balanceamento do no, checando se ha diferenca nas alturas dos seus filhos da direita e da esquerda:
int fatorBalanceamento(AVL arv)
{
  return labs(altura(arv->esq) - altura(arv->dir));
}

// funcao auxiliar que retorna o maior de dois inteiros:
int maior(int x, int y)
{
  if (x > y)
  {
    return x;
  }
  return y;
}

// funcao que realiza a rotacao para a esquerda, usada para o balanceamento:
void rotateEsq(AVL arv)
{
  AVL temp = arv->esq;
  arv->esq = temp->dir;
  temp->dir = arv;
  arv->altura = maior(altura(arv->esq), altura(arv->dir)) + 1;
  temp->altura = maior(altura(temp->esq), arv->altura) + 1;
  arv = temp;
}

// funcao que realiza a rotacao para a direita, usada para o balanceamento:
void rotateDir(AVL arv)
{
  AVL temp = arv->dir;
  arv->dir = temp->esq;
  temp->esq = arv;
  arv->altura = maior(altura(arv->esq), altura(arv->dir)) + 1;
  temp->altura = maior(altura(temp->dir), arv->altura) + 1;
  arv = temp;
}

// funcao que realiza a rotacao dupla direita/esquerda:
void rotateRL(AVL arv)
{
  rotateEsq(arv->dir);
  rotateDir(arv);
}

// funcao que realiza a rotacao dupla esquerda/direita:
void rotateLR(AVL arv)
{
  rotateDir(arv->esq);
  rotateEsq(arv);
}

// funcao que realiza a insercao na arvore e realiza o balanceamento automatico se necessario:
int insereAvl(AVL arv, char val[MAX])
{
    printf("Entro na fc");
  int res;
  AVL temp;

    printf("\n\n**********%s******************\n\n", val);
  if (!arv)
  {
      printf("%s", arv);
    printf("IF : 1");
    arv = novoNo(val);
    printf("test");
//    strcpy(arv->info, val); // TRAVA AQUI
//    arv->altura = 0;
//    arv->esq = NULL;
//    arv->dir = NULL;
    return 1;
  }

  temp = arv;
  if (strcmp(val, temp->info) < 0)
  {
    printf("IF : 2");
    res = insereAvl(temp->esq, val);
    if (res == 1)
    {
      printf("IF : 3");
      if (fatorBalanceamento(temp) >= 2)
      {
        printf("IF : 4");
        if (strcmp(val, arv->esq->info) < 0)
        {
          printf("IF : 6");
          rotateEsq(arv);
        }
        else
        {
          printf("IF : 6 ELSE");
          rotateLR(arv);
        }
      }
    }
  }
  else
  {
    printf("IF : 2 ELSE");
    if ((res = insereAvl(temp->dir, val)) == 1)
    {
      printf("IF : 7");
      if (fatorBalanceamento(temp) >= 2)
      {
        printf("IF : 8");
        if (strcmp(val, arv->dir->info) >= 0)
        {
          printf("IF : 9");
          rotateDir(arv);
        }
        else
        {
          printf("IF : 9 ELSE");
          rotateRL(arv);
        }
      }
    }
  }

  temp->altura = maior(altura(temp->esq), altura(temp->dir)) + 1;

  return res;
}

// funcao que retorna o menor valor da arvore:
AVL menorValorAvl(AVL arv)
{
  AVL aux = arv;
  AVL temp = arv->esq;
  while (temp)
  {
    aux = temp;
    temp = temp->esq;
  }
  return aux;
}

// funcao que remove o valor do parametro num da arvore, se existir, e realiza o balanceamento automatico se necessario:
int removeAvl(AVL arv, char val[MAX])
{
  if (arv == NULL)
  {
    printf("Arvore vazia!\n");
    return 0;
  }

  int res;
  if (strcmp(val, arv->info) < 0)
    if ((res = removeAvl(arv->esq, val)) == 1)
      if (fatorBalanceamento(arv) >= 2)
      {
        if (altura(arv->dir->esq) <= altura(arv->dir->dir))
          rotateDir(arv);
        else
          rotateRL(arv);
      }
  if (strcmp(val, arv->info) > 0)
    if ((res = removeAvl(arv->dir, val)) == 1)
      if (fatorBalanceamento(arv) >= 2)
      {
        if (altura(arv->esq->dir) <= altura(arv->esq->esq))
          rotateEsq(arv);
        else
          rotateLR(arv);
      }

  if (strcmp(arv->info, val) == 0)
  {
    if ((!arv->esq) || (!arv->dir))
    {
      AVL aux = arv;
      if (arv->esq)
        arv = arv->esq;
      else
        arv = arv->dir;
      free(aux);
    }
    else
    {
      AVL temp = menorValorAvl(arv->dir);
      strcpy(arv->info, temp->info);
      removeAvl(arv->dir, arv->info);
      if (fatorBalanceamento(arv) >= 2)
      {
        if (altura(arv->esq->dir) <= altura(arv->esq->esq))
          rotateEsq(arv);
        else
          rotateLR(arv);
      }
    }
    if (arv != NULL)
      arv->altura = maior(altura(arv->esq), altura(arv->dir)) + 1;
    return 1;
  }

  arv->altura = maior(altura(arv->esq), altura(arv->dir)) + 1;

  return res;
}

// funcao para impressao da arvore:
void preOrdemAvl(AVL arv)
{
  printf("(");
  if (arv)
  {
    printf("%s ", arv->info);
    preOrdemAvl(arv->esq);
    preOrdemAvl(arv->dir);
  }
  printf(")");
}

// funcao recursiva para liberacao de toda a arvore:
void destroiAvl(AVL a)
{
  if (a == NULL)
    return;
  destroiAvl(a->esq);
  destroiAvl(a->dir);
  free(a);
  return;
}
