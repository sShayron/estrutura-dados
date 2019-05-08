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
int vaziaArbin(Arbin a);
void visitar(TipoA elem);
Arbin insereABB(Arbin a, TipoA elem);
int buscaNaArbinABB(Arbin a, TipoA elem);
int buscaNaArbin(Arbin a, TipoA elem);
void preOrdemArbin(Arbin a);
int pesoArbin(Arbin a);
int eFolha(Arbin a);
int numFolhas(Arbin a);
int existeCaminho(Arbin a, TipoA elem1, TipoA elem2);
int existeCaminhoABB(Arbin a, TipoA elem1, TipoA elem2);
int contaNivel(Arbin a, int nivel);
int iguaisArbin(Arbin a1, Arbin a2);
#endif // ARBIN_H_INCLUDED
