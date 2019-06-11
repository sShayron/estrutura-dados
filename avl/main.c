#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(AVL_H_INCLUDED)
#include "avl.h"
#endif
#include "avl.c"

int leArquivoDeEntrada(FILE *fEntrada, AVL arv){
    #define MAX 100
    char buffer[MAX]; // buffer for a line of values separated by spaces
    char value[MAX];

    //open files
    fEntrada = fopen("C:/projetos/C/avl/entrada.txt", "r");

    if (fEntrada == NULL) {
        printf("\n Nao foi possivel abrir o arquivo de entrada \n");
        return 0;
    }

    while(!feof(fEntrada)){
        memset(buffer, '\0', sizeof(buffer)); // setting '\0' for whole buffer

        fscanf(fEntrada, "%s", value);
        printf("\n ----------------------------(%s)--------------------------------- \n", value);
        insereAvl(arv, value);
        printf("\n %s \n ", buffer);
    }
    fclose(fEntrada);

    return 1; //all read successfully
}


int main()
{
    FILE *fEntrada;
    AVL arv; // = (AVL)malloc(sizeof(struct avl));


    if(leArquivoDeEntrada(fEntrada, arv)){
        printf("\n Valores carregados para arvore avl\n");
    }else{
        printf("\n Algum erro ocorreu ao carregar arquivo \n");
        exit(1); // shutdown
    }

    preOrdemAvl(arv);

    printf("Hello world!\n");
    return 0;
}
