#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int TipoL;
typedef struct ListaNo {
    TipoL info;
    struct ListaNo *prox;
    struct ListaNo *ant;
} *pListaNo;
typedef struct Tlista {
    pListaNo
        primeiro,
        ultimo,
        iterador;
    int longitude;
} *Lista;

// Lista expressao
typedef char* TipoLExp;
typedef struct ListaNoExp {
    TipoLExp info;
    struct ListaNoExp *prox;
    struct ListaNoExp *ant;
} *pListaNoExp;
typedef struct TlistaExp {
    pListaNoExp
        primeiro,
        ultimo,
        iterador;
    int longitude;
} *ListaExp;


pListaNo inicNo( TipoL elem );
// Exp
pListaNoExp inicNoExp(TipoLExp elem);
void incrementaLongitude(Lista lst);
// Exp
void incrementaLongitudeExp(ListaExp lst);
void decrementaLongitude(Lista lst);
// Exp
void decrementaLongitudeExp(ListaExp lst);
void setIterador(Lista lst, pListaNo no);
// Exp
void setIteradorExp(ListaExp lst, pListaNoExp no);
void setPrimeiro(Lista lst, pListaNo no);
// Exp
void setPrimeiroExp(ListaExp lst, pListaNoExp no);
void setUltimo(Lista lst, pListaNo no);
// Exp
void setUltimoExp(ListaExp lst, pListaNoExp no);
Lista inicLista(void);
// Exp
ListaExp inicListaExp(void);
//adiciona nó depois do iterador
void anexLista(Lista lst, TipoL elem);
// Exp
//adiciona nó depois do iterador
void anexListaExp(ListaExp lst, TipoLExp elem);
//adiciona nó antes do iterador
void insLista(Lista lst, TipoL elem);
//coloca iterador sobre o primeiro element
void primLista(Lista lst);
// Exp
//coloca iterador sobre o primeiro element
void primListaExp(ListaExp lst);
//coloca iterador sobre o ultimo element
void ultLista(Lista lst);
// avança o iterador uma posicao
void segLista(Lista lst);
// Exp
// avança o iterador uma posicao
void segListaExp(ListaExp lst);
//coloca o iterador sobre a posicao pos
void posLista( Lista lst, int pos );
// retorna o elemento sob o iterador
TipoL infoLista(Lista lst);
// retorna a quantidade de elementos na lista
TipoL longLista(Lista lst);
// retorna verdadeiro se o iterador estiver indefinido
int fimLista(Lista lst);
// Exp
// retorna verdadeiro se o iterador estiver indefinido
int fimListaExp(ListaExp lst);

void printLista(Lista lst);
// Exp
void printListaExp(ListaExp lst) ;

TipoL maiorElemento(Lista lst);
// Lista-8)
int estaNaLista(Lista lst, TipoL elem);
// Lista-14)
int numOcorrenciasLista(Lista lst, TipoL elem);
// Lista-1)
int iguaisListas(Lista lst1, Lista lst2);
// Lista-2)
int semelhantesListas(Lista lst1, Lista lst2);
// Lista-3)
int subLista(Lista lst1, Lista lst2);
// Lista-4)
int contidaLista(Lista lst1, Lista lst2);
// Lista-5)
int ordernadaLista(Lista lst);
// Lista-6)
void adicLista(Lista lst, TipoL elem);
// Lista-7)
void substitueLista(Lista lst, TipoL elem);
// Lista-9)
void exibeLista(Lista lst);
// 10)
void antLista(Lista lst);
// Lista-11)
int posIteradorLista(Lista lst);
pListaNo noNaPosicao(Lista lst, int pos);
void removeNo(Lista lst, pListaNo no);
int posicaoNo(Lista lst, pListaNo no);
// Lista-12)
void simplificarLista(Lista lst);
int estaNoArray(TipoL array[], int arraySize, TipoL value);
// Lista-13)
int numDiferentesLista(Lista lst);
// Lista-15)
TipoL maxOcorrenciaLista(Lista lst);
// Lista-16) Retorna a posição da última ocorrência do elemento elem. Se não ocorre, retorna zero:
int ultOcorrenciaLista(Lista lst, TipoL elem);
// Lista-17) Elimina da lista lst todos os elementos compreendidos entre a posição p1 e p2, inclusive:
void eliminarLista(Lista lst, int p1, int p2);
// Lista-18) Ordena em ordem crescente a lista lst:
void ordenarLista(Lista lst);
// Lista-19) Elimina da lista lst1 todos os elementos que aparecem na lista lst2:
void diferencaLista( Lista lst1, Lista lst2);
// destroi lista
void elimLista(Lista lst);

#endif // LISTA_H_INCLUDED
