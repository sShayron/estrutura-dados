#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

typedef float TipoP;

typedef struct ponto{
    TipoP x,y,z;
}*Ponto;

Ponto criaPonto(TipoP x, TipoP y, TipoP z){
    Ponto p = NULL;
    p = (Ponto) malloc(sizeof( Ponto));
    if(p==NULL){
        printf("nao foi possivel alocar o ponto \n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

void setX(Ponto p, TipoP x){
    p->x = x;
}
void setY(Ponto p, TipoP y){
    p->y = y;
}
void setZ(Ponto p, TipoP z){
    p->z = z;
}

TipoP getX(Ponto p){
    return p->x;
}
TipoP getY(Ponto p){
    return p->y;
}
TipoP getZ(Ponto p){
    return p->z;
}

int main(){
    int i;
    Ponto *vetPtos2 = NULL;

    vetPtos2 = (Ponto*) malloc(5*sizeof(Ponto));

    // 1) O QUE SIGNIFICA vetPos2?
    //    R: Um vetor de pontos.
    // 2) O que está armazenado em vetPos2?
    //    R: O endereco de memoria do primeiro ponto armazenado no vetor.
    // 3) O que está armazenado em (vetPos2+3)
    //    R: O endereco de memoria do ponto na posicao 3 do vetor.
    // 4) O que está armazenado em *(vetPos2+3)
    //    R: os valores de X, Y e Z do ponto

    // 5) complete o for para exibir os pontos com seus respectivos endereços
    //    não usar a notação [i]
    for(i=0; i<5; i++) {
        printf("\n\n vetPos[%i]", i);
        setX(vetPtos2+i, i);
        setY(vetPtos2+i, i);
        setZ(vetPtos2+i, i);
        printf("\nX: %f", getX(vetPtos2+i));
        printf("\nY: %f", getX(vetPtos2+i));
        printf("\nZ: %f", getX(vetPtos2+i));
    }


    return 0;
}
