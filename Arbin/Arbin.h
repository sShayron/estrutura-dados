#ifndef ARBIN_H_INCLUDED
#define ARBIN_H_INCLUDED

//TAD Arbin
/*
Funções do TAD Arbin
•Arbin inicArbin( void ) : cria e retorna uma arvore binaria vazia
•Arbin esqArbin( Arbin a): retorna a subarvore esquerda
• Pre: a!=arvore vazia
• Pos: esqArbin = subarvore esquerda
•Arbin dirArbin( Arbin a): retorna a subarvore direita
• Pre: a!=arvore vazia
• Pos: dirArbin = subarvore direita
•TipoA raizArbin( Arbin a): retorna a raiz
• Pre: a!=arvore vazia
• Pos: raizArbin = elem
void destruirArbin( Arbin a): destrói a arvore binária, retornando toda
a memória ocupada.
int vaziaArbin(Arbin a): retorna 1 se arbin vazia e 0 caso contrario
*/

typedef int TipoA;

typedef struct NodoArbin{
TipoA info;
struct NodoArbin *esq, *dir;
} Tarbin, *Arbin;

// cria e retorna uma arvore binaria vazia
Arbin inicArbin(void);

//retorna a subarvore esquerda
Arbin esqArbin(Arbin a);

//retorna a subarvore direita
Arbin dirArbin(Arbin a);

//retorna a raiz
TipoA raizArbin(Arbin a);

//destrói a arvore binária, retornando toda a memória ocupada.
void destruirArbin(Arbin a);
void visitar(TipoA elem);
Arbin insereABB(Arbin a, TipoA elem);
int buscaNaArbinB(Arbin a, TipoA elem);
int buscaNaArbin(Arbin a, TipoA elem);
void preOrdemArbin(Arbin a);
#endif // ARBIN_H_INCLUDED
