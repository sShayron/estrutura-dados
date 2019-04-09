#if !defined(LISTADE_H_INCLUDED)
#include "./listaDE.h"
#endif


NoDE criaNoDE(TipoLDE info);

/** inicLista
  *
  * Cria uma lista vazia
  *
  * @return uma lista Vazia
  */
ListaDE inicListaDE()
{
  ListaDE l = (ListaDE)malloc(sizeof(struct tListaDE));
  l->primeiro = NULL;
  l->tamanho = 0;
  return l;
}

/** criaNo
  *
  * Fun��o auxiliar para criar um n� com um elemento
  *
  * @param info um elemento inteiro que deseja armazenar
  * @return um N� com o elemento armazenado
  */
NoDE criaNoDE(TipoLDE info)
{
  NoDE n = (NoDE)malloc(sizeof(struct ListaNoDE));
  n->info = info;
  n->ant = NULL;
  n->prox = NULL;
  return n;
}

/** exibirLista
  *
  * Fun��o que printa os valores da lista
  * @return 0
  */
void exibirListaDE(ListaDE lst)
{

  if(lst) {
      NoDE atual = lst->primeiro;
      printf("Exibindo Lista: \n\n");
      int i;
      // percorre a lista
      for (i=0; i<lst->tamanho; i++) {
        printf("Lista[%i]: %i \n", i+1, atual->info);
        atual = atual->prox;
      }
  } else {
      printf("Lista vazia!");
  }
}

/** adicionaNoInicio
  *
  * Adiciona elemento info no inicio na Lista
  *
  * @param lst um ponteiro para a Lista.
  * @param info elemento inteiro que deseja armazenar na Lista.
  */
void adicionaNoInicioDE(ListaDE lst, TipoLDE info)
{
  NoDE n = criaNoDE(info);

  // Se o tamanho for 0
  if (!lst->tamanho) {
    // Entao o proximo e o anterior sao o mesmo
    n->prox = n;
    n->ant = n;
  } else {
    NoDE primeiro = lst->primeiro;
    NoDE ant = primeiro->ant;

    // Atribui o ponteiro proximo e anterior do novo n�
    n->prox = primeiro;
    n->ant = primeiro->ant;

    // Atribui  o ponteiro proximo e anterior da n� da lista para o novo n�
    primeiro->ant = n;
    ant->prox = n;
  }

  // Aponta o ponteiro primeiro da lista para o novo n�
  lst->primeiro = n;
  // Incrementa tamanho da lista
  lst->tamanho++;
}

/** adicionaNoFim
  *
  * Adiciona elemento info no fim na Lista
  *
  * @param lst um ponteiro para a Lista.
  * @param info elemento inteiro que deseja armazenar na Lista.
  */
void adicionaNoFimDE(ListaDE lst, TipoLDE info)
{
  NoDE n = criaNoDE(info);

  // Se o tamanho for 0
  if (!lst->tamanho) {
    // Atribui o ponteiro proximo e anterior do novo n�
    n->prox = n;
    n->ant = n;

    // Como nao nao h� outros n�s na lista o novo n� sera o primeiro
    lst->primeiro = n;
  } else {
    NoDE primeiro = lst->primeiro;
    NoDE ant = primeiro->ant;

    // Insere no fim atribuindo o proximo para o primeiro
    n->prox = primeiro;
    n->ant = primeiro->ant;

    // Atribui o ponteiro proximo e anterior para o novo n�
    primeiro->ant = n;
    ant->prox = n;
  }
  lst->tamanho++;
}

int adicionaNaPosicaoDE(ListaDE lst, TipoLDE info, int posicao) {
    NoDE n = criaNoDE(info);
    // Se a lista tiver vazia ou a posicao maior que a lista
    if (lst->tamanho == 0 || posicao >= lst->tamanho) {
        return -1;
    }

    // Percorre a lista enquanto nao chegar na posicao
    NoDE atual = lst->primeiro; // posicao = 0
    int i;
    for (i=0; i<posicao-1; i++) {
        atual = atual->prox;
    }
    NoDE prox = atual->prox;
    NoDE ant = atual->ant;
    n->prox = atual;
    n->ant = ant;

    atual->ant = n;
    if(posicao == 1) lst->primeiro = n;
    lst->tamanho++;
    return 0;
}

/** removeInicio
  *
  * Remove o n� no inicio da Lista
  *
  * @param lst um ponteiro para a Lista.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int removeInicioDE(ListaDE lst)
{
  if (!lst->tamanho) return -1;

  NoDE primeiro = lst->primeiro;

  if (lst->tamanho == 1) {
    // Se tiver s� um elemento na lista, atribui NULL para o primeiro
    lst->primeiro = NULL;
  } else {
    NoDE prox = primeiro->prox;
    NoDE ant = primeiro->ant;

    // Atribui o proximo ao primeiro
    lst->primeiro = prox;

    // Ajusta os ponteiros
    prox->ant = ant;
    ant->prox = prox;
  }

  // Libera espa�o de memoria
  free(primeiro);

  // Decrementa tamanho da lista
  lst->tamanho--;

  return 0;
}

/** eliminaElemNaPosicao
  *
  * Remove o elemento sob a posicao
  *
  * @param lst um ponteiro para a Lista.
  * @param posicao do no para remover.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int eliminaElemNaPosicaoDE(ListaDE lst, int posicao)
{
  if (!lst->tamanho || posicao > lst->tamanho) return -1;

  NoDE atual = lst->primeiro;
  int i;

  // percorre a lista at� a posicao
  for (i=0; i<posicao; i++) {
    atual = atual->prox;
  }

  // Se a lista tiver s� um elemento
  if (lst->tamanho == 1) {
    lst->primeiro = NULL;
  } else {
    NoDE prox = atual->prox;
    NoDE ant = atual->ant;

    // Ajusta os ponteiros
    ant->prox = prox;
    prox->ant = ant;
  }

  // Libera espa�o de memoria
  free(atual);

  // Decrementa tamanho da lista
  lst->tamanho--;

  return 0;
}

/** removeFim
  *
  * Remove o ultimo elemento da Lista
  *
  * @param lst um ponteiro para a Lista.
  * @return -1 se falhar ou 0 se conseguir remover
  */
int removeFimDE(ListaDE lst)
{
  if (!lst->tamanho) return -1;

  NoDE primeiro = lst->primeiro;
  NoDE tbr = primeiro->ant; // Elemento a ser removido
  NoDE nb = tbr->ant; // new back

  // if Lista if of tamanho 1
  if (lst->tamanho == 1) {
    // o primeiro aponta para NULL
    lst->primeiro = NULL;
  } else {
    // Ajusta os ponteiros
    primeiro->ant = nb;
    nb->prox = primeiro;
  }

  // Libera espa�o de memoria
  free(tbr);

  // Decrementa tamanho da lista
  lst->tamanho--;

  return 0;
}

/** removeElemEscolhido
  *
  * Remove todos os n� da lista que tem info igual a passada
  *
  * @param lst um ponteiro para Lista
  * @param info que deseja eliminar
  * @return o numero de elementos removidos
  */
int removeElemEscolhidoDE(ListaDE lst, const TipoLDE info)
{
  int removido = 0;

  if (!lst->tamanho) return removido;

  NoDE atual = lst->primeiro;
  NoDE prox = atual->prox;
  NoDE ant = atual->ant;
  int is_primeiro = 1;
  int i;

  for (i=0; i<lst->tamanho; i++) {
    if (info == atual->info) {
      // Atribui o proximo caso ainda seja o primeiro
      if (is_primeiro) lst->primeiro = prox;

      // Ajusta os ponteiros
      prox->ant = ant;
      ant->prox = prox;

      // Libera espa�o de memoria
      free(atual);

      // aponta o atual para o proximo N�
      atual = prox;

      removido++;
    } else {
      is_primeiro = 0;

      // Atribui o proximo para atual
      atual = atual->prox;
    }

    // Ajusta os ponteiros prox e ant
    if (lst->tamanho > 1) {
      prox = atual->prox;
      ant = atual->ant;
    }
  }

  // Decrementa o tamanho da lista
  lst->tamanho-=removido;

  // Se remover todos elementos atribui NULL para primeiro
  if (!lst->tamanho) lst->primeiro = NULL;

  return removido;
}

/** destruirLista
  *
  * Remove todos N�s da Lista
  *
  * @param lst um ponteiro para Lista
  * @return numero de N�s que foram removidos
  */
int destruirListaDE(ListaDE lst)
{
  if (!lst->tamanho) return 0;

  int removido = 0;
  NoDE atual = lst->primeiro;
  NoDE prox = atual->prox;
  NoDE ant = atual->ant;
  int is_primeiro = 1;
  int i;

  for (i=0; i<lst->tamanho; i++) {
    if (atual->info) {
      // Atribui o proximo caso ainda seja o primeiro
      if (is_primeiro) lst->primeiro = prox;

      // Ajusta os ponteiros
      prox->ant = ant;
      ant->prox = prox;

      // Libera espa�o de memoria
      free(atual);

      // update the atual
      atual = prox;

      removido++;
    } else {
      // we're no longer on the primeiro
      is_primeiro = 0;

      // Atribui o proximo para atual
      atual = atual->prox;
    }

    // Ajusta os ponteiros prox e ant
    if (lst->tamanho > 0) {
      prox = atual->prox;
      ant = atual->ant;
    }
  }

  // Decrementa o tamanho da lista
  lst->tamanho-=removido;

  // Se remover todos elementos atribui NULL para primeiro
  if (!lst->tamanho) lst->primeiro = NULL;

  return removido;
}

/** retornaPrimeiroElem
  *
  * Retorna info do primeiro elemento da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info do primeiro No da Lista ou -1
  */
int retornaPrimeiroElemDE(ListaDE lst)
{
  if (lst->tamanho) {
    return lst->primeiro->info;
  } else {
    return -1;
  }
}

/** retornaElemNaPosicao
  *
  * Retorna info do elemento da posicao da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info da posicao No da Lista ou -1
  */
int retornaElemNaPosicaoDE(ListaDE lst, int posicao)
{
  // Se a lista tiver vazia ou a posicao maior que a lista
  if (!lst->tamanho || posicao >= lst->tamanho) {
    return -1;
  }

  // Percorre a lista enquanto nao chegar na posicao
  NoDE atual = lst->primeiro; // posicao = 0
  int i;
  for (i=0; i<posicao-1; i++) {
    atual = atual->prox;
  }

  return atual->info;
}

/** retornaUltimoElem
  *
  * Retorna info do ultimo elemento da Lista
  *
  * @param lst um ponteiro para Lista
  * @return o info do ultimo No da Lista ou -1
  */
int retornaUltimoElemDE(ListaDE lst)
{
  // Se a lista tiver vazia retorna NULL
  if (!lst->tamanho) return -1;

  // Retorna o anterior do primeiro
  NoDE end = lst->primeiro->ant;
  return end->info;
}

/** listaVazia
  *
  * Verifica se a lista ta vazia
  *
  * @param lst um ponteiro para Lista
  * @return 1 if the Lista is indeed empty 0 otherwise.
  */
int listaVaziaDE(ListaDE lst)
{
  if (lst->tamanho == 0 && lst->primeiro == NULL) {
    return 1;
  } else {
    return 0;
  }
}

/** tamanho
  *
  * Gets the tamanho of the linked Lista
  *
  * @param lst um ponteiro para Lista
  * @return o tamanho da lista
  */
int tamanhoDE(ListaDE lst)
{
  return lst->tamanho;
}

/** procuraElem
  *
  * Procura um elemento na lista
  *
  * @param lst a ponteiro para Lista.
  * @param search info para procura
  * @return 1 se encontrar ou 0 se n�o
  */
int procuraElemDE(ListaDE lst, int procurado)
{
  // percorre a lista
  NoDE atual = lst->primeiro;
  int i;
  for (i=0; i<lst->tamanho; i++) {
    // compara o info com o procurado
    if (procurado == atual->info) return 1;
    atual = atual->prox;
  }

  // nao encontrado
  return 0;
}

/** esvaziaLista
  *
  * Esvazia a lista
  *
  * @param lst a ponteiro para Lista.
  *
  */
void esvaziaListaDE(ListaDE lst)
{
  // Se tamanho for 0
  if (!lst->tamanho) return;

  NoDE atual = lst->primeiro;
  NoDE prox = atual->prox;
  int i;

  // Percorre a lista e libera espa�o de memoria de todos n�s e info
  for (i=0; i<lst->tamanho; i++) {
    free(atual);
    atual = prox;

    // Se nao for o final da lista atribui o proximo n�
    if (i < lst->tamanho-1) prox = atual->prox;
  }

  // Reseta primeiro e tamanho da lista
  lst->primeiro=NULL;
  lst->tamanho=0;
}

/** percorre
  *
  * Percorre os n�s da lista
  *
  * @param lst a ponteiro to a linked Lista.
  */
void percorreDE(ListaDE lst)
{
  NoDE atual = lst->primeiro;
  int i;
  for (i=0; i<lst->tamanho; i++) {
    printf("Lista[%i]: %i", i+1, atual->info);
    atual = atual->prox;
  }
}
