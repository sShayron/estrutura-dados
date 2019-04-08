int progImpressao() {
    int userInput = -1;
    Fila filaImpressao = inicFila();

    while(userInput != 4) {
        printf("\n");
        userInput = menu();
        executaComando(filaImpressao, userInput);
    }

    return 0;
}

int menu() {
    int x;
    printf("\n[1]: Insere arquivo na fila de impressao");
    printf("\n[2]: Executa impressao");
    printf("\n[3]: Exibe fila de impressao");
    printf("\n[4]: Sair");
    printf("\n");

    scanf("%i", &x);
    return x;
}

void executaComando(Fila f, int comando) {
    system("cls");
    int nDoc;
    switch(comando) {
    case 1:
        printf("\nDigite a numeracao do documento: ");
        scanf("%i", &nDoc);
        adicFila(f, nDoc);
        printf("\nDocumento %i incluso para fila de impressao", nDoc);
        clearS();
        break;
    case 2:
        elimFila(f);
        printf("\nEnviando primeiro documento da fila para impressao...");
        clearS();
        break;
    case 3:
        exibeFilaFormatado(f);
        clearS();
        break;
    case 4:
        printf("\nFinalizando programa.");
        break;
    default:
        printf("Comando invalido");
    }
}

void clearS() {
    printf("\nPressione qualquer tecla para voltar ao menu");
    getch();
    system("cls");
}

void exibeFilaFormatado(Fila f) {
    int i = 1;
    if (vaziaFila(f)) {
        printf("Fila vazia");
    } else {
        Fila copia = inicFila();
        TipoF elem;

        while(!vaziaFila(f)) {
            elem = elimFila(f);
            printf("\n%i - %d ", i, elem);
            adicFila(copia, elem);
            i++;
        }
        printf("\n");

        while(!vaziaFila(copia)) {
            adicFila(f, elimFila(copia));
        }
        destruirFila(copia);
    }
}
