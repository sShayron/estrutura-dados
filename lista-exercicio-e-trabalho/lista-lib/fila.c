#if !defined(FILA_H_INCLUDED)
#include "fila.h"
#endif
#if !defined(LISTA_H_INCLUDED)
#include "lista.h"
#endif

Fila inicFila(void) {
  Fila f = (Fila) malloc(sizeof(struct TFila));
  f->primeiro = -1;
  f->ultimo = -1;

  return f;
}
void adicFila(Fila f, TipoF elem) {
    if(f->primeiro == -1) {
        f->primeiro = 0;
        f->ultimo = 0;
        f->info[0] = elem;
    } else if((f->ultimo + 1)%MAX == f->primeiro){
        printf("Fila cheia");
    } else {
        f->ultimo = (f->ultimo + 1) % MAX;
        f->info[f->ultimo] = elem;
    }
}
TipoF elimFila(Fila f) {
    TipoF aux;

    if (f->primeiro == -1) {
        printf("Fila vazia");
    } else if (f->primeiro == f->ultimo) {
        aux = f->info[f->primeiro];
        f->primeiro = -1;
        f->ultimo = -1;
        return aux;
    } else {
        aux = f->info[f->primeiro];
        f->primeiro = (f->primeiro + 1)%MAX;
        return aux;
    }
}
TipoF infoFila(Fila f) {
    if(f->primeiro == -1) {
        printf("Fila vazia");
    } else {
        return f->info[f->primeiro];
    }
}
int vaziaFila(Fila f) {
    return (f->primeiro == -1);
}
void destruirFila(Fila f) {
    free(f);
}

void printFila(Fila f) {
    if (vaziaFila(f)) {
        printf("Fila vazia");
    } else {
        Fila copia = inicFila();
        TipoF elem;

        while(!vaziaFila(f)) {
            elem = elimFila(f);
            printf(" %d ", elem);
            adicFila(copia, elem);
        }
        printf("\n");

        while(!vaziaFila(copia)) {
            adicFila(f, elimFila(copia));
        }
        destruirFila(copia);
    }
}
// Fila-01)
Fila copiarFila(Fila f) {
    Fila copyFila = inicFila();
    Lista lstAux = inicLista();

    if (f->primeiro == -1) {
        printf("\ncopiarFila: Fila vazia");
    }

    while(!vaziaFila(f)) {
        anexLista(lstAux, elimFila(f));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f, infoLista(lstAux));
        adicFila(copyFila, infoLista(lstAux));
    }

    free(lstAux);
    return copyFila;
}
// Pilha-02)
int longFila(Fila f) {
    int sum = 0;

    if (vaziaFila(f)) {
        return sum;
    } else {
        Fila copia = inicFila();

        while(!vaziaFila(f)) {
            adicFila(copia, elimFila(f));
            sum++;
        }

        while(!vaziaFila(copia)) {
            adicFila(f, elimFila(copia));
        }
        destruirFila(copia);
    }
    return sum;
}
// Pilha-03)
void concatFilas(Fila f1, Fila f2) {
    if (vaziaFila(f2)) {
        printf("concatFilas: Fila 2 vazia");
        return;
    }
    Lista lstAux = inicLista();

    while(!vaziaFila(f2)) {
        anexLista(lstAux, elimFila(f2));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f1, infoLista(lstAux));
        adicFila(f2, infoLista(lstAux));
    }
}
// Fila-04)
void invFila(Fila f) {
    if (vaziaFila(f)) {
        printf("invFila: Fila vazia");
        return;
    }

    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        insLista(lstAux, elimFila(f));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f, infoLista(lstAux));
    }
}
// Fila-05)
int existeElemento(Fila f, TipoF elem) {
    int found = 0;
    if (vaziaFila(f)) {
        printf("existeElemento: Fila vazia");
        return;
    }

    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        TipoF elemAux = elimFila(f);
        insLista(lstAux, elemAux);
        if (elemAux == elem) {
            found = 1;
        }
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f, infoLista(lstAux));
    }
    return found;
}
// Fila-06)
int iguaisFilas(Fila f1, Fila f2) {
    if (vaziaFila(f1) && vaziaFila(f2)) {
        return 1;
    }
    if (longFila(f1) != longFila(f2)) {
        return 0;
    }
    int equals = 1;
    Lista lstAux1 = inicLista();
    Lista lstAux2 = inicLista();

    while(!vaziaFila(f1)) {
        TipoF tfAux1 = elimFila(f1);
        TipoF tfAux2 = elimFila(f2);
        if(tfAux1 != tfAux2) {
            equals = 0;
        }
        insLista(lstAux1, tfAux1);
        insLista(lstAux2, tfAux2);
    }

    primLista(lstAux1);
    primLista(lstAux2);
    while(!fimLista(lstAux1)) {
        adicFila(f1, infoLista(lstAux1));
        adicFila(f2, infoLista(lstAux2));
        segLista(lstAux1);
        segLista(lstAux2);
    }

    return equals;
}
// Fila-07)
void adicFilaPos(Fila f, TipoF elem, int pos) {
    if (vaziaFila(f)) {
        printf("adicFilaPos: Fila vazia, elmento sera adicionado na primeira posicao");
        adicFila(f, elem);
        return;
    }
    if (pos > longFila(f) + 1) {
        printf("adicFilaPos: offset nao e permitido, escolha uma posicao menor ou apenas 1 vez maior que a quantidade de elementos na fila");
        return;
    }

    int i = 0;
    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        anexLista(lstAux, elimFila(f));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        if (i == pos) {
            adicFila(f, elem);
        }
        adicFila(f, infoLista(lstAux));
        i++;
    }
}
// Fila-08)
void elimElemento( Fila f, TipoF elem) {
    if(vaziaFila(f)) {
        printf("elimElemento: Fila vazia");
        return;
    }
    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        anexLista(lstAux, elimFila(f));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        if (infoLista(lstAux) != elem) {
            adicFila(f, infoLista(lstAux));
        }
    }

}
// Fila-09)
void partirFila(Fila f, Fila f1, Fila f2, TipoF elem) {
    if (vaziaFila(f)) {
        printf("partirFila: Fila alvo vazia");
        return;
    }

    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        anexLista(lstAux, elimFila(f));
    }

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f, infoLista(lstAux));
        if (infoLista(lstAux) > elem) {
            adicFila(f2, infoLista(lstAux));
        } else {
            adicFila(f1, infoLista(lstAux));
        }
    }
}
// Fila-10)
void primeiroDaFila(Fila f, TipoF elem) {
    if(vaziaFila(f)) {
        adicFila(f, elem);
        return;
    }

    Lista lstAux = inicLista();

    while(!vaziaFila(f)) {
        anexLista(lstAux, elimFila(f));
    }

    adicFila(f, elem);

    for(primLista(lstAux); !fimLista(lstAux); segLista(lstAux)) {
        adicFila(f, infoLista(lstAux));
    }
}
