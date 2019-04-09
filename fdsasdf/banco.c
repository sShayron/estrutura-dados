void banco() {
    Fila f1 = inicFila();
    Fila f2 = inicFila();
    Fila f3 = inicFila();
    int totalClientes = 0;

    while(totalClientes < 50) {
        insereClienteFila(f1, f2, f3);

        if (totalClientes % 3 == 0) {
            atenderCliente(f1, f2, f3);
        }
        totalClientes++;
    }

    printf("\nClientes restantes na Fila 1: %i", longFila(f1));
    printf("\nClientes restantes na Fila 2: %i", longFila(f2));
    printf("\nClientes restantes na Fila 3: %i", longFila(f3));
}

void insereClienteFila(Fila f1, Fila f2, Fila f3) {
    switch(rand() % 3) {
    case 0:
        if ((f1->ultimo + 1)%MAX == f1->primeiro) {
            printf("\n[--------------------]");
            printf("\n[---Fila 1: Lotada---]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        adicFila(f1, 1);
        break;
    case 1:
        if ((f2->ultimo + 1)%MAX == f2->primeiro) {
            printf("\n[--------------------]");
            printf("\n[---Fila 2: Lotada---]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        adicFila(f2, 1);
        break;
    case 2:
        if ((f3->ultimo + 1)%MAX == f3->primeiro) {
            printf("\n[--------------------]");
            printf("\n[---Fila 3: Lotada---]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        adicFila(f3, 1);
        break;
    }
}

void atenderCliente(Fila f1, Fila f2, Fila f3) {
    switch(rand() % 3) {
    case 0:
        if (vaziaFila(f1)) {
            printf("\n[--------------------]");
            printf("\n[---Fila 1: Vazia----]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        elimFila(f1);
        break;
    case 1:
        if (vaziaFila(f2)) {
            printf("\n[--------------------]");
            printf("\n[---Fila 2: Vazia----]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        elimFila(f2);
        break;
    case 2:
        if (vaziaFila(f3)) {
            printf("\n[--------------------]");
            printf("\n[---Fila 3: Vazia----]");
            printf("\n[--------------------]");
            printf("\n\n");
            return;
        }
        elimFila(f3);
        break;
    }
}
