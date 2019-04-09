#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.c"
#include "pilha.c"
#include "fila.c"
#include "banco.c"
#include "programa-impressao.c"
#include "teste-listaDE.c"

int main()
{
    srand((unsigned) time(NULL));
    int i;
    printf("!!!!!!!Lista!!!!!!!\n\n");
    // COM STRUCT
//    struct ListaNo p;
//    printf("Digita valor q vai ser info do no: ");
//    scanf("%i", &i);
//    p.info = i;
//    p.prox = NULL;
//    printf("Valor escolhido: %i", p.info);
//
//    // COM PONTEIRO
//    pListaNo pp = malloc(sizeof(struct ListaNo));
//    printf("\n\nDigita valor q vai ser info do no: ");
//    scanf("%i", &i);
//    pp->info = i;
//    pp->prox = NULL;
//    printf("Valor escolhido: %i", pp->info);
//    return 0;
    Lista lst1 = inicLista();
    anexLista(lst1, 1);
    insLista(lst1, 2);
    anexLista(lst1, 3);
    anexLista(lst1, 4);
    insLista(lst1, 5);
    anexLista(lst1, 6);
    anexLista(lst1, 7);

    Lista lst2 = inicLista();
    anexLista(lst2, 7);
    insLista(lst2, 8);
    anexLista(lst2, 9);
    anexLista(lst2, 10);
    insLista(lst2, 11);
    anexLista(lst2, 12);
    anexLista(lst2, 13);
    anexLista(lst2, 13);

    printf("Lista 1:");
    printLista(lst1);
    printf("\n\n");
    printf("Lista 2: ");
    printLista(lst2);

    if (iguaisListas(lst1, lst2)) {
        printf("SAO IGUAIS");
    } else {
        printf("NAO SAO IGUAIS");
    }

    printf("\n\n Maior elemento Lista 1: %i", maiorElemento(lst1));

    diferencaLista(lst1, lst2);
    printf("\n\n");
    printf("Lista 1 apos aplicar diferenca lista com lista 2: ");
    printLista(lst1);

    printf("\n\nmaxOcorrencia lista 2: %i", maxOcorrenciaLista(lst2));

    Lista lst3 = inicLista();
    anexLista(lst3, 3);
    anexLista(lst3, 2);
    anexLista(lst3, 1);
    anexLista(lst3, 5);
    anexLista(lst3, 4);

    printf("\n\n");

    printf("Lista 3: ");
    printLista(lst3);

    ordenarLista(lst3); // CORRIGIR

    printf("\n\nLista 3 ordenada: ");

    printLista(lst3);

    elimLista(lst3);
    printf("\n\nLista 3 apos elimLista: ");
    printLista(lst3);


    printf("\n\n\n\n!!!!!!!Pilha!!!!!!!\n\n");
    Pilha p = inicPilha();
    push(p, 10);
    push(p, 20);
    push(p, 30);
    push(p, 40);
    push(p, 50);
    push(p, 60);
    printf("Pilha 1:\n");
    printPilha(p);

    printf("\n\nLista 1 invertida com auxilio da pilha: \n");
    invLista(lst1);
    printLista(lst1);

    printf("\n\nCopia da pilha 1:\n");
    Pilha pCopy = copiarPilha(p);
    printPilha(pCopy);
    printf("Endereco copia pilha 1: %i\n", pCopy);

    printf("\nPilha 1:\n");
    printPilha(p);
    printf("Endereco pilha 1: %i\n", p);

    printf("\nPilha 1 e igual sua copia: ");
    if (iguaisPilhas(p, pCopy)) {
        printf("Sao iguais");
    } else {
        printf("Nao sao iguais");
    }

    printf("\nPilha 1 invertida:\n");
    invPilha(p);
    printPilha(p);
    printf("\nPilha 1 invertida e igual sua copia antes de inverter: ");
    if (iguaisPilhas(p, pCopy)) {
        printf("Sao iguais");
    } else {
        printf("Nao sao iguais");
    }

    printf("\n\n\nLista para analizar expressao\n");
    ListaExp lstExp = inicListaExp();
    anexListaExp(lstExp, "3");
    anexListaExp(lstExp, "5");
    anexListaExp(lstExp, "+");
    anexListaExp(lstExp, "10");
    anexListaExp(lstExp, "*");
    printListaExp(lstExp);
    int x = avaliarExpressao(lstExp);
    printf("\nValor avaliar expressao: %i", x);

    printf("\n\nInserir elemento no fundo da pilha:\n");
    printPilha(p);
    printf("\nInserir 7 no fundo da pilha:\n");
    fundoPilha(p, 7);
    printPilha(p);

    printf("\nLongpilha: %i", longPilha(p));

    printf("\nEliminar o 7 da pilha: \n");
    elimTodosPilha(p, 7);
    printPilha(p);

    printf("\nAdicionar outro 10 na pilha: \n");
    push(p, 10);
    printPilha(p);

    printf("Eliminar todos 10 da pilha: \n");
    elimTodosPilha(p, 10);
    printPilha(p);

    printf("\nSoma da pilha: %i", somaPilha(p));

    printf("\nCriar pilha pra testar palindromo: \n");
    Pilha pPalindromo = inicPilha();
    push(pPalindromo, 10);
    push(pPalindromo, 20);
    push(pPalindromo, 10);
    printPilha(pPalindromo);

    if (palindromePilha(pPalindromo)) {
        printf("Pilha e palindromo");
    } else {
        printf("Pilha nao e palindromo");
    }

    printf("\n\n\n\n!!!!!!!Fila!!!!!!!\n\n");
    Fila f = inicFila();
    adicFila(f, 12);
    adicFila(f, 1);
    adicFila(f, 2);
    adicFila(f, 4);
    adicFila(f, 6);
    adicFila(f, 21);
    adicFila(f, 5);
    adicFila(f, 9);
    printf("Fila 1:\n");
    printFila(f);
    printf("Endereco da fila 1: %i", f);

    printf("\nCopia da fila 1:\n");
    Fila fCopy = copiarFila(f);
    printFila(fCopy);
    printf("Endereco da copia da fila 1: %i", fCopy);

    printf("\nLong fila copy: %i", longFila(fCopy));
    printf("\nFila copia apos executar longFila: \n");
    printFila(fCopy);

    printf("\nFilas para concatenar: ");
    Fila f1 = inicFila();
    adicFila(f1, 1);
    adicFila(f1, 2);
    adicFila(f1, 3);
    Fila f2 = inicFila();
    adicFila(f2, 4);
    adicFila(f2, 5);
    adicFila(f2, 6);
    Fila f3 = inicFila();
    adicFila(f3, 1);
    adicFila(f3, 2);
    adicFila(f3, 3);
    printf("\nFila 1: ");
    printFila(f1);
    printf("\nFila 2: ");
    printFila(f2);
    printf("\nFila 3:");
    printFila(f3);

    printf("\nFila 3 e igual a fila 1?");
    if (iguaisFilas(f1, f3))
        printf("Sao iguais");
    else
        printf("Nao sao iguais");
    printf("\nFila 2 e igual a fila 1?");
    if (iguaisFilas(f1, f2))
        printf("Sao iguais");
    else
        printf("Nao sao iguais");

    printf("\n\nFila 1 apos concatenar a fila 2: ");
    concatFilas(f1, f2);
    printFila(f1);

    printf("\nFila invertida: ");
    invFila(f1);
    printFila(f1);

    printf("\nExiste 5 na fila?");
    if (existeElemento(f1, 5)) {
        printf("Existe");
    } else { printf("Nao existe 5 nesta fila"); }
    printf("\nExiste 15 na fila?");
    if (existeElemento(f1, 15)) {
        printf("Existe");
    } else { printf("Nao existe 15 nesta fila"); }

    printf("\n\nAdicionar 15 na posicao [2]: ");
    adicFilaPos(f1, 15, 2);
    printFila(f1);

    printf("\nEliminar elemento 15 da fila: ");
    elimElemento(f1, 15);
    printFila(f1);

    printf("\n\npartirFila no 2: \n");
    Fila fx = inicFila();
    Fila fz = inicFila();
    partirFila(f1, fx, fz, 2);
    printFila(fx);
    printf("\n");
    printFila(fz);

    printf("\nAdicionar 77 no inicio da fila: \n");
    primeiroDaFila(f1, 77);
    printFila(f1);

    printf("\n\n!!!!!!!!!!!!Simulacao banco com fila!!!!!!!!!!!!!!");
    banco();

    int a = 0;

    printf("\n------------------------------------------------------------\n");
    printf("[1] Executar programa de impressao \n[2] Testar lista DE");
    printf("\n------------------------------------------------------------\n");
    scanf("%i", &a);

    switch(a) {
    case 1:
        printf("\n\n!!!!!!!!!!!!Simulacao programa de impressao!!!!!!!!!!!!!!");
        progImpressao();
        break;
    case 2:
        system("cls");
        printf("\n\n!!!!!!!!!!!!Teste Lista duplamente!!!!!!!!!!!!!!");
        testeListaDE();
        break;
    }
    return 0;
}
