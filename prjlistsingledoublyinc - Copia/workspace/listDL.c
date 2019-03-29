#ifndef LISTADE_H_INCLUDED
    #include "listDL.h"
#endif // LISTADE_H_INCLUDED

#include "string.h"

ListaDE inicListaDE()
{

    ListaDE lst;
    lst=(ListaDE) malloc(sizeof(struct TListaDE)); // alocando a struct TListaDE
    lst->longitude = 0;   // zero elmentos
    lst->iterador = NULL;
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst; // retorna o endereco onde a struct ListaDE foi alocada
}


void primListaDE(ListaDE lst)
{
    //por o iterador sobre o primeiro No da ListaDE
    lst->iterador = lst->primeiro;
}

void ultListaDE(ListaDE lst){
    //por o iterador sobre o ultimo No da ListaDE
    lst->iterador = lst->ultimo;
}

void posListaDE(ListaDE lst, int pos){

    if(lst->longitude > 0 && pos >=1 && pos <= lst->longitude){

        int i;
        for(i=1, lst->iterador = lst->primeiro; i < pos; i++, lst->iterador = lst->iterador->prox)
        {}
    }
    else{
        lst->iterador = NULL; // iterador indefinido
    }
}

int fimListaDE(ListaDE lst)
{

    return (lst->iterador == NULL);

}

void segListaDE(ListaDE lst)
{

    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefindio \n");
    }
    else
    {
        lst->iterador = lst->iterador->prox;
    }
}

char* infoListaDE(ListaDE lst)
{
    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
        //return NULL;
    }
    else
        return lst->iterador->info;
}

int longListaDE(ListaDE lst)
{
    return lst->longitude;
}


//3 casos: ListaDE vazia, iterador sobre o ultimo elemento, iterador sobre um elemento intermediario
void anxListaDE( ListaDE lst, TipoLDE elem )
{

    //tratamento de erro
    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e ListaDE cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNoDE novoNo = ( pListaNoDE )malloc( sizeof( struct ListaNoDE ) );
        //novoNo->info = elem; // atribuir o elemento a ser armazenado
        strcpy(novoNo->info, elem);
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado
        novoNo->ant = NULL;

        if (lst->longitude == 0)  // ListaDE vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->ultimo )  // iterador sobre o ultimo elemento
        {
            //por no campo prox do ultimo no o endereco do novoNo
            lst->iterador->prox = novoNo;
            //lst->ultimo->prox = novoNo;
            //atualizar o campo ultimo com o endereco do novoNo
            lst->ultimo = novoNo;
            //acertar o apontamento do campo ant do novoNO
            lst->iterador->prox->ant = lst->iterador;
            //atualizar o campo iterador com o endereco do novoNo
            lst->iterador = novoNo;
            //incrementar a quantidade de nos
            lst->longitude++;
        }
        else  //iterador sobre um noh intermediario
        {
            // o prox do novoNo aponta para o proximo Noh depois do iterador
            // fazer o prox do iterador apontar para o novoNo
            novoNo->prox = lst->iterador->prox;
            novoNo->ant = lst->iterador;
            lst->iterador->prox->ant = novoNo;
            lst->iterador->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}



//3 casos: ListaDE vazia, iterador sobre o primeiro elemento, iterador sobre qualquer outro elemento
void insListaDE( ListaDE lst, TipoLDE elem )
{

    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e ListaDE cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNoDE novoNo = ( pListaNoDE )malloc( sizeof( struct ListaNoDE ) );
        //novoNo->info = elem; // atribuir o elemento a ser armazenado
        strcpy(novoNo, elem);
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // ListaDE vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if ( lst->iterador == lst->primeiro)  // iterador sobre o primeiro elemento
        {
            //novoNo->prox = lst->iterador;
            novoNo->prox = lst->primeiro;
            lst->primeiro = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else  //iterador sobre qualquer outro noh
        {
            //usar um segundo iterador para percorrer a ListaDE e parar uma posicao antes do iterador
            pListaNoDE p;
            for(p = lst->primeiro; p->prox != lst->iterador ; p = p->prox )
            {

            }
            //ao sair do for, p esta um noh antes do iterador
            //acertar os ponteiros
            novoNo->prox = lst->iterador;
            p->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}


void elimListaDE( ListaDE lst )
{

    if(lst->iterador != NULL)
    {

        pListaNoDE noAserDesalocado;
        if (lst->iterador == lst->primeiro)  // se o iterador estiver sobre o primeiro elemento
        {
            if (lst->longitude == 1){

                noAserDesalocado = lst->iterador;
                lst->iterador = NULL;
                lst->primeiro = NULL;
                lst->ultimo = NULL;
                lst->longitude--;
                free(noAserDesalocado);

            }
            else{

                noAserDesalocado = lst->iterador;
                lst->iterador = lst->iterador->prox;
                //lst->primeiro = lst->primeiro->prox;
                lst->primeiro = lst->iterador;
                lst->longitude--;
                free(noAserDesalocado);
            }
        }
        else  // iterador esta sobre qualquer outro no que nao o primeiro no
        {
            //iterador sobre no intermediario ou o ultimo no
            pListaNoDE p;
            for(p = lst->primeiro; p->prox != lst->iterador; p = p->prox)
            {
            }
            noAserDesalocado = lst->iterador;
            p->prox = lst->iterador->prox;

            if( lst->iterador == lst->ultimo) // se o iterador estiver sobre o utlimo no
                lst->ultimo = p;

            lst->iterador = lst->iterador->prox;
            free(noAserDesalocado);
            lst->longitude--;
        }
    }
    else
    {
        printf("\n erro: iterador indefinido \n");
    }
}

void printListaDE(ListaDE lst){

    if(longListaDE(lst) == 0){
        printf("\n listaDE vazia\n");
    }else{
        printf("\n ListaDE: ");
        for(primListaDE(lst); !fimListaDE(lst); segListaDE(lst)){

            TipoLDE elemDE;
            strcpy(elemDE, infoListaDE(lst));
            printf("%s ", elemDE);
        }
        printf("\n");
    }
}