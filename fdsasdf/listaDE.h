#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED

typedef int TipoLDE;

/* Estrutura do No */
typedef struct ListaNoDE
{
  struct ListaNo* ant; /* Ponteiro para o No anterior */
  struct ListaNo* prox; /* Ponteiro para o proximo No */
  TipoLDE info; /* Informa��o do n� */
} *NoDE;

/* Estrutura da Lista. */
typedef struct tListaDE
{
  NoDE primeiro; /* Ponteiro apontando para o primeiro N� da lista */
  int tamanho; /* Tamanho da Lista */
} *ListaDE;

/* Prototipos */
ListaDE inicListaDE();    // Cria e retorna uma Listaa vazia

void exibirListaDE(ListaDE lst); // Exibe a Lista

/* Adicionando */
void adicionaNoInicioDE(ListaDE lst, TipoLDE info);               // Adiciona Elemento no inicio da Lista
void adicionaNoFimDE(ListaDE lst, TipoLDE info);                  // Adiciona Elemento no fim da Lista
int adicionaNaPosicaoDE(ListaDE lst, TipoLDE info, int posicao); // Adiciona Elemento na posicao informada

/* Removendo */
int removeInicioDE(ListaDE lst);                              // Remove Elemento no inicio da Lista
int eliminaElemNaPosicaoDE(ListaDE lst, int posicao);         // Remove Elemento da posicao escolhida
int removeFimDE(ListaDE lst);                                 // Remove Elemento no Fim da Lista
int removeElemEscolhidoDE(ListaDE lst, const TipoLDE info);     // Remove Elemento com info escolhida
int destruirListaDE(ListaDE lst);                             // Destroi a lista

/* Retornando */
int retornaPrimeiroElemDE(ListaDE lst);                     // Retorna primeiro elemento da lista
int retornaUltimoElemDE(ListaDE lst);                       // Retorna ultimo elemento da lista
int retornaElemNaPosicaoDE(ListaDE lst, int posicao);       // Retorna elemento na posicao escolhida
int listaVaziaDE(ListaDE lst);                              // Retorna se a lista est� vazia
int tamanhoDE(ListaDE lst);                                 // Retorna o tamanho da lista

/* Procurando */
int procuraElemDE(ListaDE lst, int procurado); // Procura elemento dentro da Lista

/* Verifica */
void esvaziaListaDE(ListaDE lst); // Esvazia Lista

/* Percorre */
void percorreDE(ListaDE lst); // Percorre os elementos da Lista


#endif // LISTADE_H_INCLUDED
