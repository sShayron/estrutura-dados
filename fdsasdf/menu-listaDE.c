int MENU = 0; // Opção do menu

// Opções do menu
int escolha_menu()
{
    printf("\n\n");
    printf(" Lista Duplamente \n");
    printf("--------------------------\n");
    printf(" 1 - Iniciar nova Lista \n");
    printf(" 2 - Adicionar elemento no inicio \n");
    printf(" 3 - Adicionar elemento no final \n");
    printf(" 4 - Adicionar elemento na posicao informada \n");
    printf(" 5 - Exibir elemento na posicao informada \n");
    printf(" 6 - Eliminar elemento na posicao informada \n");
    printf(" 7 - Esvaziar Lista \n");
    printf(" 8 - Exibir Lista \n");
    printf(" 9 - Tamanho da Lista \n");
    printf("--------------------------\n");
    printf(" 0 - Sair \n");
    printf("\n");
    printf(" Digite uma opcao do menu: ");
    scanf("%i",&MENU);
}
