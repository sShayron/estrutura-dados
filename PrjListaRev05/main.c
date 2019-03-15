#include <stdio.h>
#include <stdlib.h>

typedef int TipoL;

typedef struct ListaNo
{
    TipoL info;
    struct ListaNo *prox;
} *pListaNo;

typedef struct TLista
{
    pListaNo primeiro, ultimo, iterador;
    int longitude;
} * Lista;


Lista inicLista()
{

    Lista lst;
    lst=(Lista) malloc(sizeof(struct TLista)); // alocando a struct TLista
    lst->longitude = 0;   // zero elmentos
    lst->iterador = NULL;
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst; // retorna o endereco onde a struct Lista foi alocada
}


void primLista(Lista lst)
{
    //por o iterador sobre o primeiro No da lista
    lst->iterador = lst->primeiro;
}

void ultLista(Lista lst){
    //por o iterador sobre o ultimo No da lista
    lst->iterador = lst->ultimo;
}

void posLista(Lista lst, int pos){

    if(lst->longitude > 0 && pos >=1 && pos <= lst->longitude){

        int i;
        for(i=1, lst->iterador = lst->primeiro; i < pos; i++, lst->iterador = lst->iterador->prox)
        {}
    }
    else{
        lst->iterador = NULL; // iterador indefinido
    }
}

int fimLista(Lista lst)
{

    return (lst->iterador == NULL);

}

void segLista(Lista lst)
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

TipoL infoLista(Lista lst)
{
    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefinido \n");
        return NULL;
    }
    else
        return lst->iterador->info;
}

int longLista(Lista lst)
{
    return lst->longitude;
}


//3 casos: Lista vazia, iterador sobre o ultimo elemento, iterador sobre um elemento intermediario
void anxLista( Lista lst, TipoL elem )
{

    //tratamento de erro
    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) );
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // lista vazia
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
            lst->iterador->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}



//3 casos: Lista vazia, iterador sobre o primeiro elemento, iterador sobre qualquer outro elemento
void insLista( Lista lst, TipoL elem )
{

    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) );
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // lista vazia
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
            //usar um segundo iterador para percorrer a lista e parar uma posicao antes do iterador
            pListaNo p;
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

void anxListaOrig( Lista lst, TipoL elem )
{

    pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) );
    novoNo->info = elem;
    novoNo->prox= NULL;

    if ( lst->longitude == 0 ) // lista vazia
        lst->primeiro = lst->ultimo = novoNo; //apontar para o novoNo
    else if ( lst->iterador == lst->ultimo )  // iterador sobre o ultimo elemento
    {
        lst->iterador->prox = lst->ultimo = novoNo;
    }
    else  //iterador sobre um noh intermediario
    {
        novoNo->prox = lst->iterador->prox; // apontar para o proximo Noh depois do iterador
        lst->iterador->prox = novoNo;
    }

    lst->iterador = novoNo; // por o iterador sobre o novoNo que foi adicionado
    lst->longitude++; // incrementar a quantidade de nós

}


void elimLista( Lista lst )
{

    if(lst->iterador != NULL)
    {

        pListaNo noAserDesalocado;
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
            pListaNo p;
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



void addNoInicio(Lista lst, TipoL elem)
{
    pListaNo no = (pListaNo) malloc(sizeof(struct ListaNo));
    no->info = elem;
    no->prox = NULL;

    if(lst->longitude == 0)
    {
        lst->primeiro = no;
        lst->iterador = no;
        lst->ultimo = no;
    }
    else
    {
        no->prox = lst->primeiro;
        lst->iterador = no;
        lst->primeiro = no;
    }
    lst->longitude++;
}

void printLista(Lista lst)
{

    // primLista, segLista, fimLista, infoLista
    for(primLista(lst) ; !fimLista(lst) ; lst->iterador=lst->iterador->prox )
    {
        printf("%d ", lst->iterador->info);
    }

}

void printLista2(Lista lst)
{

    // primLista, segLista, fimLista, infoLista
    for(primLista(lst) ; !fimLista(lst) ; segLista(lst) )
    {
        printf("%d ", infoLista(lst));
    }

}

void printLista3(Lista lst)
{

    // primLista, segLista, fimLista, infoLista
    pListaNo p; // struct ListaNo *p;

    for(p=lst->primeiro; p!=NULL; p=p->prox)
        printf("%d ", p->info);


    for(lst->iterador = lst->primeiro; lst->iterador!=NULL; lst->iterador=lst->iterador->prox)
        printf("%d ", lst->iterador->info);
}

TipoL maiorElemento(Lista lst)
{
    TipoL maior;
    if(longLista(lst) == 0)
    {
        //lista vazia
        return NULL;
    }
    else   //lista cheia
    {
        primLista(lst);
        maior = infoLista(lst);
        for(primLista(lst) ; !fimLista(lst) ; segLista(lst) )
        {

            if(infoLista(lst) > maior)
                maior = infoLista(lst);
        }
        return maior;
    }

}

TipoL maiorElemento2(Lista lst)
{
    TipoL maior;
    if(lst->longitude == 0)
    {
        //lista vazia
        return NULL;
    }
    else   //lista cheia
    {
        lst->iterador = lst->primeiro;
        maior = lst->iterador->info;
        for(lst->iterador= lst->primeiro ; lst->iterador!=NULL ; lst->iterador=lst->iterador->prox )
        {

            if(lst->iterador->info > maior)
                maior = lst->iterador->info;
        }
        return maior;
    }

}


TipoL maiorElemento3(Lista lst)
{
    TipoL maior;

    if(lst->longitude == 0)
    {
        //lista vazia
        return NULL;
    }
    else   //lista cheia
    {
        lst->iterador = lst->primeiro;
        maior = lst->iterador->info;
        maior = lst->primeiro->info;
        for( lst->iterador = lst->primeiro; lst->iterador != NULL ; lst->iterador = lst->iterador->prox )
        {

            if(lst->iterador->info > maior)
                maior = lst->iterador->info ;
        }
        return maior;
    }

}


//1) Verificar se duas listas são iguais. Duas listas são iguais se ambas as estruturas têm o mesmo número de elementos, e estes são iguais um a um. Em particular, duas listas vazias são iguais.
int iguaisListas(Lista lst1, Lista lst2)
{

    //verificar se lst1 e lst2 sao vazias
    if(longLista(lst1) == 0 && longLista(lst2)== 0)
        return 1;
    //senao se long de lst1 == long lst2
    if(longLista(lst1) == longLista(lst2))
    {
        //percorrer lst1 e lst2 e comparar noh a noh
        for(primLista(lst1), primLista(lst2); !fimLista(lst1); segLista(lst1), segLista(lst2))
        {
            if(infoLista(lst1) != infoLista(lst2))
                return 0;
        }
        return 1;
    }
    else
    {
        //senao nao sao iguais
        return 0;
    }

}


int iguaisListas2(Lista lst1, Lista lst2)
{

    //verificar se lst1 e lst2 sao vazias
    if(lst1->longitude == 0 && lst2->longitude== 0)
        return 1;
    //senao se long de lst1 == long lst2
    if(lst1->longitude == lst2->longitude)
    {
        //percorrer lst1 e lst2 e comparar noh a noh
        for(lst1->iterador=lst1->primeiro, lst2->iterador=lst2->primeiro; lst1->iterador != NULL;
                lst1->iterador = lst1->iterador->prox, lst2->iterador = lst2->iterador->prox)
        {

            if(lst1->iterador->info != lst2->iterador->info)
                return 0;
        }
        return 1;
    }
    else
    {
        //senao nao sao iguais
        return 0;
    }

}

//6) Adiciona o elemento elem no final de lst:
void adicLista( Lista lst, TipoL elem){

    if(longLista(lst) == 0){ // lista vazia
        anxLista(lst, elem);
    }
    else{ // lista está cheia
        //por o iterador na ultima posicao
        ultLista(lst);
        anxLista(lst, elem);
    }
}

//7) Substitue o conteúdo atual do iterador pelo elemento elem:
void substitueLista( Lista lst, TipoL elem){

    lst->iterador->info = elem;
}

8) Indica se o elemento elem aparece na lista:
int estaNaLista( Lista lst, TipoL elem){

    if(longLista(lst) == 0)
        return 0;
    else{
        for(primLista(lst); !fimLista(lst); segLista(lst)){
            if(infoLista(lst) == elem)
                return 1; // achou o elemento
        }
        return 0; // elem nao esta na lista
    }
}

Lista copiaLista(Lista lst){
    Lista lstCopia = inicLista();
    for(primLista(lst); !fimLista(lst); segLista(lst))
        anxLista(lstCopia, infoLista(lst));

    return lstCopia;
}

10) Coloca o iterador na posição anterior à atual:
void antLista( Lista lst){

    int i;
    pListaNo p;
    if(lst->iterador != lst->primeiro){
        for( p = lst->primeiro, i=1; p->prox != lst->iterador; p=p->prox, i++)
        { }
        posLista(lst, i);
    }

}

12) Deixar na lista somente uma ocorrência de cada um dos elementos:
void simplificarLista( Lista lst){

    Lista lst2 = inicLista();
    for(primLista(lst); !fimLista(lst); segLista(lst)){
        if(!estaNaLista(lst2, infoLista(lst))){
            anxLista(lst2, infoLista(lst));
        }
    }

    //vou apagar todos da lista original
    for(primLista(lst); !fimLista(lst); )
        elimLista(lst);

    //fazer uma copia
    for(primLista(lst2); !fimLista(lst2); ){
        anxLista(lst, infoLista(lst2));
        elimLista(lst2);
    }



}

int contaElmento(Lista lst, TipoL elem){

    int cont=0;
    for(primLista(lst); !fimLista(lst); segLista(lst)){
        if(infoLista(lst) == elem)
            cont++;
    }
    return cont;
}

int semelhantesListas(Lista lst1, Lista lst2){

    //as duas lista estao vazias
    if( longLista(lst1)==0 && longLista(lst2)==0 ){
        return 1;
    }
    else if(longLista(lst1) != longLista(lst2)){
        return 0;
    }
    else{ // as duas listas tem o mesmo tamanho
        TipoL elem;
        int cont1, cont2;


        for(primLista(lst1); !fimLista(lst1); segLista(lst1)){

            elem = infoLista(lst1);
            cont1 = contaElmento(lst1, elem);
            cont2 = 0;

            for(primLista(lst2); !fimLista(lst2); ){
                if(infoLista(lst2) != elem)
                    segLista(lst2);
                else
                    break;
            }
            if(fimLista(lst2)) //elem nao esta na lista lst2
                return 0;
        }
        return 1;
    }

}

int main()
{
    printf("Hello world!\n");
    Lista lst = inicLista();
    anxLista(lst, 10); // primeiro no
    anxLista(lst, 20); // segundo no
    anxLista(lst, 30); // terceiro no
    anxLista(lst, 40); // terceiro no
    anxLista(lst, 50); // terceiro no

    posLista(lst, 3);
    printf(" \n %d \n", infoLista(lst));


    Lista lst2 = inicLista();
    anxLista(lst2, 10); // primeiro no
    anxLista(lst2, 20); // segundo no
    anxLista(lst2, 30); // terceiro no
    anxLista(lst2, 40); // terceiro no
    anxLista(lst2, 50); // terceiro no

    int ehIgual = iguaisListas(lst, lst2);
    if(ehIgual){
        printf("\n lst e lst2 sao iguais \n");
    }
    else{
        printf("\n lst e lst2 NAO sao iguais \n");
    }

    int maior = maiorElemento(lst);
    printf("\n maior = %d\n", maior);

    printf("\n");
    printLista(lst);

    primLista(lst);
    //insLista(lst, 5);
    elimLista(lst); // eliminou o primeiro (10): 20,30,40,50
    printf("\n");
    printLista(lst);

    ultLista(lst);
    elimLista(lst); //eliminou o ultimo 50: 20,30,40

    printf("\n");
    printLista(lst);

    //eliminar o 30
    primLista(lst);
    segLista(lst); // iterador sobre o 30
    elimLista(lst); // 20, 40
    printf("\n");
    printLista(lst);


    ehIgual = iguaisListas(lst, lst2);
    if(ehIgual){
        printf("\n lst e lst2 sao iguais \n");
    }
    else{
        printf("\n lst e lst2 NAO sao iguais \n");
    }

    //printf("info do iterador = %d \n",infoLista(lst));
    //printLista(lst);
    return 0;
}
