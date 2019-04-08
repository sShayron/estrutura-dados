#if !defined(LISTA_H_INCLUDED)
#include "lista.h"
#endif

pListaNo inicNo( TipoL elem ) {
    pListaNo novoNo = (pListaNo)malloc(sizeof(struct ListaNo));
    novoNo -> info = elem;
    novoNo -> prox = NULL;

    return novoNo;
}
// Exp
pListaNoExp inicNoExp( TipoLExp elem ) {
    pListaNoExp novoNo = (pListaNoExp)malloc(sizeof(struct ListaNoExp));
    novoNo->info = elem;
    novoNo->prox = NULL;

    return novoNo;
}
void incrementaLongitude(Lista lst) {
    lst->longitude++;;
}
// Exp
void incrementaLongitudeExp(ListaExp lst) {
    lst->longitude++;;
}
void decrementaLongitude(Lista lst) {
    lst->longitude--;
}
// Exp
void decrementaLongitudeExp(ListaExp lst) {
    lst->longitude--;
}
void setIterador(Lista lst, pListaNo no) {
    lst->iterador = no;
}
// Exp
void setIteradorExp(ListaExp lst, pListaNoExp no) {
    lst->iterador = no;
}
void setPrimeiro(Lista lst, pListaNo no) {
    lst->primeiro = no;
}
// Exp
void setPrimeiroExp(ListaExp lst, pListaNoExp no) {
    lst->primeiro = no;
}
void setUltimo(Lista lst, pListaNo no) {
    lst->ultimo = no;
}
// Exp
void setUltimoExp(ListaExp lst, pListaNoExp no) {
    lst->ultimo = no;
}
Lista inicLista(void) {
    Lista lst = (Lista)malloc(sizeof(struct Tlista));
    setPrimeiro(lst, NULL);
    setUltimo(lst, NULL);
    setIterador(lst, NULL);
    lst->longitude = 0;
    return lst;
}
// Exp
ListaExp inicListaExp(void) {
    ListaExp lst = (ListaExp)malloc(sizeof(struct TlistaExp));
    setPrimeiroExp(lst, NULL);
    setUltimoExp(lst, NULL);
    setIteradorExp(lst, NULL);
    lst->longitude = 0;
    return lst;
}

//adiciona n� depois do iterador
void anexLista(Lista lst, TipoL elem) {
    pListaNo no = inicNo(elem);
    if (lst->longitude == 0) {
        setIterador(lst, no);
        setPrimeiro(lst, no);
        setUltimo(lst, no);
        incrementaLongitude(lst);
        return;
    }
    if (lst->iterador->prox != NULL) {
        no->prox = lst->iterador->prox;
    } else {
        setUltimo(lst, no);
    }
    lst->iterador->prox = no;
    setIterador(lst, no);
    incrementaLongitude(lst);
}
// Exp
//adiciona n� depois do iterador
void anexListaExp(ListaExp lst, TipoLExp elem) {
    pListaNoExp no = inicNoExp(elem);
    if (lst->longitude == 0) {
        setIteradorExp(lst, no);
        setPrimeiroExp(lst, no);
        setUltimoExp(lst, no);
        incrementaLongitudeExp(lst);
        return;
    }
    if (lst->iterador->prox != NULL) {
        no->prox = lst->iterador->prox;
    } else {
        setUltimoExp(lst, no);
    }
    lst->iterador->prox = no;
    setIteradorExp(lst, no);
    incrementaLongitudeExp(lst);
}

//adiciona n� antes do iterador
void insLista(Lista lst, TipoL elem) {
    pListaNo no = inicNo(elem);
    if (lst->longitude == 0) {
        setIterador(lst, no);
        setPrimeiro(lst, no);
        setUltimo(lst, no);
        incrementaLongitude(lst);
        return;
    }
    if (lst->iterador == lst->primeiro) {
        setPrimeiro(lst, no);
    } else {
        pListaNo p = lst->primeiro;
        while(p->prox != lst->iterador) {
            p = p->prox;
        }
        p->prox = no;
    }
    no->prox = lst->iterador;
    setIterador(lst, no);
    incrementaLongitude(lst);
}

//coloca iterador sobre o primeiro element
void primLista(Lista lst) {
    lst->iterador = lst->primeiro;
}
// Exp
//coloca iterador sobre o primeiro element
void primListaExp(ListaExp lst) {
    lst->iterador = lst->primeiro;
}

//coloca iterador sobre o ultimo element
void ultLista(Lista lst) {
    lst->iterador = lst->ultimo;
}

// avan�a o iterador uma posicao
void segLista(Lista lst){
    if (lst->iterador == NULL)
        return;
    lst->iterador = lst->iterador->prox;
}
// Exp
// avan�a o iterador uma posicao
void segListaExp(ListaExp lst){
    if (lst->iterador == NULL)
        return;
    lst->iterador = lst->iterador->prox;
}

//coloca o iterador sobre a posicao pos
void posLista( Lista lst, int pos ) {
    int i = 1;
    if (pos > lst->longitude) {
        printf("posLista: Error Lista s� tem %i posi��es", lst->longitude);
        return;
    }
    for(primLista(lst); i != pos; i++ ){
        segLista(lst);
    }
}

// retorna o elemento sob o iterador
TipoL infoLista(Lista lst) {
    if (lst->iterador == NULL)
        return NULL;
    return lst->iterador->info;
}

// retorna a quantidade de elementos na lista
TipoL longLista(Lista lst) {
    return lst->longitude;
}

// retorna verdadeiro se o iterador estiver indefinido
int fimLista(Lista lst) {
    return lst->iterador == NULL;
}
// Exp
// retorna verdadeiro se o iterador estiver indefinido
int fimListaExp(ListaExp lst) {
    return lst->iterador == NULL;
}

void printLista(Lista lst) {
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        printf("[%i]", infoLista(lst));
    }
}
// Exp
void printListaExp(ListaExp lst) {
    for(primListaExp(lst); !fimListaExp(lst); segListaExp(lst)) {
        printf("[%s]", lst->iterador->info);
    }
}

TipoL maiorElemento(Lista lst) {
    TipoL maior;
    if (longLista(lst) == 0) {
        return 0;
    } else {
        primLista(lst);
        maior = infoLista(lst);

        for(primLista(lst); !fimLista(lst); segLista(lst)) {
            if (infoLista(lst) > maior) {
                maior = infoLista(lst);
            }
        }
    }
    return maior;
}

// Lista-8)
int estaNaLista(Lista lst, TipoL elem) {
    if (longLista(lst) == 0) {
        return 0;
    }
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        if (infoLista(lst) == elem) {
            return 1;
        }
    }
    return 0;
}
// Lista-14)
int numOcorrenciasLista(Lista lst, TipoL elem) {
    int qtd = 0;
    if (longLista(lst) == 0) {
        return 0;
    }
    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        if (infoLista(lst) == elem)
            qtd++;
    }
    return qtd;
}
// Lista-1)
int iguaisListas(Lista lst1, Lista lst2) {
    //verificar se lst1 e lst2 sao vazias
    if(longLista(lst1) == 0 && longLista(lst2) == 0)
        return 1;
    //senao se long de lst1 == long lst2
    if(longLista(lst1) == longLista(lst2)){
        //percorrer lst1 e lst2 e comparar noh a noh
        for(primLista(lst1), primLista(lst2); !fimLista(lst1); segLista(lst1), segLista(lst2)){
            if(infoLista(lst1) != infoLista(lst2))
                return 0;
        }
        return 1;
    }
    //senao nao sao iguais
    return 0;

}
// Lista-2)
int semelhantesListas(Lista lst1, Lista lst2) {
    if(longLista(lst1) != longLista(lst2))
        return 0;
    if(longLista(lst1) == 0 && longLista(lst2) == 0)
        return 1;

    for(primLista(lst1); !fimLista(lst1); segLista(lst1)) {
        if (
            !estaNaLista(lst2, infoLista(lst1)) ||
            numOcorrenciasLista(lst1, infoLista(lst1)) != numOcorrenciasLista(lst2, infoLista(lst1))
        ) {
            return 0;
        }
    }
    return 1;
}
// Lista-3)
int subLista(Lista lst1, Lista lst2) {
    if(longLista(lst2) == 0)
        return 1;

    if(longLista(lst2) != longLista(lst1))
        return 0;

    for(
        primLista(lst2), primLista(lst1);
        !fimLista(lst2);
        segLista(lst2), segLista(lst1)
    ) {
        if(infoLista(lst2) != infoLista(lst1)) {
            return 0;
        }
    }

    return 1;
}
// Lista-4)
int contidaLista(Lista lst1, Lista lst2) {
    if(longLista(lst2) == 0)
        return 1;
    if(longLista(lst2) > longLista(lst1))
        return 0;

    for(primLista(lst2); !fimLista(lst2); segLista(lst2)) {
        if(!estaNaLista(lst1, infoLista(lst2)))
            return 0;
    }
    return 1;
}
// Lista-5)
int ordernadaLista(Lista lst) {
    if(longLista(lst) == 0)
        return 1;

    for(primLista(lst); !fimLista(lst); segLista(lst)) {
        if (lst->iterador->prox != NULL && infoLista(lst) < lst->iterador->prox->info) {
            return 0;
        }
    }
    return 1;
}
// Lista-6)
void adicLista(Lista lst, TipoL elem) {
    pListaNo no = inicNo(elem);
    no->info = elem;

    if (longLista(lst) == 0) {
        setIterador(lst, no);
        setPrimeiro(lst, no);
        setUltimo(lst, no);
        incrementaLongitude(lst);
        return;
    }

    ultLista(lst);
    lst->iterador->prox->prox = no;
    setUltimo(lst, no);
    setIterador(lst, no);
    incrementaLongitude(lst);
}
// Lista-7)
void substitueLista(Lista lst, TipoL elem) {
    if (longLista(lst) == 0)
        return;

    lst->iterador->info = elem;
}
// Lista-9)
void exibeLista(Lista lst) {
    printLista(lst);
}
// Lista-10)
void antLista(Lista lst) {
    if (longLista(lst) < 2 || lst->iterador == lst->primeiro)
        return;

    pListaNo noTemp = malloc(sizeof(struct ListaNo));
    noTemp = lst->primeiro;

    while(noTemp->prox->info != infoLista(lst)){
        noTemp = noTemp->prox;
    }
    setIterador(lst, noTemp);
}
// Lista-11)
int posIteradorLista(Lista lst) {
    int i = 1;
    if (longLista(lst) == 0)
        return 0;
    if(lst->iterador == lst->primeiro)
        return 1;
    if(lst->iterador == lst->ultimo)
        return longLista(lst);

    pListaNo noTemp = malloc(sizeof(struct ListaNo));
    noTemp = lst->primeiro;

    while(noTemp->info != infoLista(lst)) {
        i++;
    }

    return i;
}
pListaNo noNaPosicao(Lista lst, int pos) {
    int i = 1;
    if (pos > longLista(lst)) {
        printf("noNaPosicao: Error Lista s� tem %i posi��es", lst->longitude);
        return NULL;
    }
    pListaNo noTemp;
    noTemp = lst->primeiro;
    if (pos == 1) {
        return noTemp;
    }
    while(i != pos) {
        noTemp = noTemp->prox;
        i++;
    }
    return noTemp;
}
void removeNo(Lista lst, pListaNo no) {
    if(!estaNaLista(lst, no->info)) {
        printf("removeNo: Error No nao esta na lista");
        return;
    }

    if (longLista(lst) == 1) {
        setIterador(lst, NULL);
        setPrimeiro(lst, NULL);
        setUltimo(lst, NULL);
        decrementaLongitude(lst);
        free(no);
        return;
    }

    if (no == lst->primeiro) {
        setPrimeiro(lst, no->prox);
        decrementaLongitude(lst);
        free(no);
        return;
    }

    pListaNo noAux;
    int i;
    int finded = 0;

    for(i = 1; finded == 0; i++) {
        noAux = noNaPosicao(lst, i);

        if (noAux->prox == no) {
            noAux->prox = no->prox;

            if (no == lst->ultimo) {
                setUltimo(lst, noAux);
            }
            finded = 1;
        }
    }
    free(no);
    decrementaLongitude(lst);
}
int posicaoNo(Lista lst, pListaNo no) {
    if(!estaNaLista(lst, no->info)) {
        printf("posicaoNo: Error No nao esta na lista");
        return 0;
    }
    int i = 1;
    pListaNo noTemp = malloc(sizeof(struct ListaNo));
    noTemp = lst->primeiro;
    while(noTemp != no) {
        noTemp = noTemp->prox;
        i++;
    }
    return i;
}
// Lista-12)
void simplificarLista(Lista lst) {
    pListaNo noTemp = malloc(sizeof(struct ListaNo));
    int i;
    for(i = 1; i <= longLista(lst); i++) {
        noTemp = noNaPosicao(lst, i);

        if (numOcorrenciasLista(lst, noTemp->info) > 1) {
            removeNo(lst, noTemp);
        }
    }
}
int estaNoArray(TipoL array[], int arraySize, TipoL value) {
    int i;
    for(i = 0; i < arraySize; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}
// Lista-13)
int numDiferentesLista(Lista lst) {
    if (longLista(lst) == 0)
        return 0;
    int diferentes = 1;
    TipoL comparados[longLista(lst)];
    pListaNo noTemp1 = malloc(sizeof(struct ListaNo));
    pListaNo noTemp2 = malloc(sizeof(struct ListaNo));
    int i;
    int x;
    for(i = 1; i <= longLista(lst); i++) {
        noTemp1 = noNaPosicao(lst, i);
        for(x = i + 1; x <= longLista(lst); x++) {
            noTemp2 = noNaPosicao(lst, x);
            comparados[i] = noTemp2->info;
            if (
                noTemp1->info != noTemp2->info &&
                !estaNoArray(comparados, i, noTemp2->info)
            ) {
                diferentes++;
            }
        }
    }
    return diferentes;
}

// Lista-15)
TipoL maxOcorrenciaLista(Lista lst) {
    if(longLista(lst) == 0) {
        printf("maxOcorrenciaLista: Error lista vazia");
        return 0;
    }

    TipoL elem;
    TipoL maisOcorrencia;
    int elemQtds = 0;
    int i;
    for(i = 1; i <= longLista(lst); i++) {
        elem = noNaPosicao(lst, i)->info;
        int elemNumeroOcorrencias = numOcorrenciasLista(lst, elem);
        if (elemNumeroOcorrencias > elemQtds) {
            maisOcorrencia = elem;
            elemQtds = elemNumeroOcorrencias;
        }
    }
    return maisOcorrencia;
}
// Lista-16) Retorna a posi��o da �ltima ocorr�ncia do elemento elem. Se n�o ocorre, retorna zero:
int ultOcorrenciaLista(Lista lst, TipoL elem){
    int numOc = numOcorrenciasLista(lst, elem);
    if (numOc == 0)
        return 0;
    int pos = 1;
    int i;
    for (i = 1; i <= longLista(lst); i++) {
        if (noNaPosicao(lst, i)->info == elem) {
            pos = i;

            if (numOc == 1)
                return pos;
        }
    }
    return pos;
}
// Lista-17) Elimina da lista lst todos os elementos compreendidos entre a posi��o p1 e p2, inclusive:
void eliminarLista(Lista lst, int p1, int p2) {
    int i;
    for (i = 1; i <= longLista(lst); i++) {
        if (i >= p1 && i <= p2) {
            removeNo(lst, noNaPosicao(lst, i));
        }
    }
}

// Lista-18) Ordena em ordem crescente a lista lst:
void ordenarLista(Lista lst) {
    if (longLista(lst) <= 1)
        return;

    pListaNo noTemp1;
    pListaNo noTemp2;
    int i;
    int x;
    for(i = 1; i <= longLista(lst); i++) {
        noTemp1 = noNaPosicao(lst, i);
        for(x = i + 1; x <= longLista(lst); x++) {
            noTemp2 = noNaPosicao(lst, x);
            if (noTemp1->info > noTemp2->info) {
                TipoL salva = noTemp1->info;
                noTemp1->info = noTemp2->info;
                noTemp2->info = salva;
            }
        }
    }
}
// Lista-19) Elimina da lista lst1 todos os elementos que aparecem na lista lst2:
void diferencaLista( Lista lst1, Lista lst2) {
    if (longLista(lst1) == 0 || longLista(lst2) == 0)
        return;

    pListaNo noTemp1;
    pListaNo noTemp2;
    int i;
    int x;
    for(i = 1; i <= longLista(lst1); i++) {
        noTemp1 = noNaPosicao(lst1, i);
        for(x = i + 1; x <= longLista(lst2); x++) {
            noTemp2 = noNaPosicao(lst2, x);
            if (noTemp1->info == noTemp2->info) {
                removeNo(lst1, noTemp1);
            }
        }
    }
}
// destroi lista
void elimLista(Lista lst) {
    int i;

    for(i = longLista(lst); i > 0; i--) {
        removeNo(lst, noNaPosicao(lst, i));
    }
}
