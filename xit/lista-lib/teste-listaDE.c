#include "stdio.h"
#include "stdlib.h"
#include "menu-listaDE.c"
#include "listaDE.c"

int MENU; // Op��o do menu

/**
 * Fun��o de apoio que inicia lista caso nao tenha sido iniciada
 */
ListaDE listaExist(ListaDE lst) {
    if (!lst) {
        lst  = inicListaDE();
        printf("Lista vazia iniciada\n");
    }
    return lst;
}

/**
 * Fun��o de apoia que retorna elemento escolhido pelo usuario
 */
int escolha_elem() {
    int elem;
    printf("Digite o elemento que deseja incluir: ");
    scanf("%i", &elem);
    return elem;
}
/**
 * Fun��o de apoia que retorna posicao escolhido pelo usuario
 */
int escolha_pos() {
    int pos;
    printf("Digite a posicao que deseja: ");
    scanf("%i", &pos);
    return pos;
}

int testeListaDE() {
    do
    {
        int elem, pos;

        //exibe opcoes do menu e atribui o numero da opcao na variavel MENU
        escolha_menu();
        //executa a a��o do menu
        switch (MENU)
        {
            case 0:
                printf("Sistema finalizado!");
                system("exit");
                break;
            case 1:
                system("cls");
                ListaDE lst = inicListaDE();
                printf("Lista iniciada vazia");
                break;
            case 2:
                system("cls");
                lst = listaExist(lst);
                elem = escolha_elem();
                adicionaNoInicioDE(lst, elem);
                printf("Elemento %i inseriodo no inicio da lista", elem);
                break;
            case 3:
                system("cls");
                system("cls");
                lst = listaExist(lst);
                elem = escolha_elem();
                adicionaNoFimDE(lst, elem);
                printf("Elemento %i inseriodo no fim da lista", elem);
                break;
            case 4:
                lst = listaExist(lst);
                pos = escolha_pos();
                elem = escolha_elem();
                int adc = adicionaNaPosicaoDE(lst, elem, pos);
                if ( adc == 0) {
                    printf("Elemento %i inseriodo na posicao %i", elem, pos);
                }else if (adc == -1){
                    printf("Posicao informada maior que a lista, tamanho da lista: %i", tamanhoDE(lst));
                }
                break;
            case 5:
                lst = listaExist(lst);
                pos = escolha_pos();
                printf("Lista[%i]: %i", pos, retornaElemNaPosicaoDE(lst, pos) );
                break;
            case 6:
                lst = listaExist(lst);
                pos = escolha_pos();
                int elim = eliminaElemNaPosicaoDE(lst, pos);
                if(elim == 0) {
                    printf("Elemento da posicao %i eliminado;", pos);
                }else if(elim == -1) {
                    printf("Posicao inv�lida, lista tem %i posicoes", tamanhoDE(lst));
                }
                break;
            case 7:
                if(!lst) {
                    printf("Nenhuma lista iniciada");
                }else {
                    esvaziaListaDE(lst);
                    printf("Lista destruida");
                }
            case 8:
                lst = listaExist(lst);
                exibirListaDE(lst);
                break;
            case 9:
                lst = listaExist(lst);
                printf("Tamanho: %i", tamanhoDE(lst));
            default:
             system("exit");
        }
    }
    while (MENU!=0);
}
