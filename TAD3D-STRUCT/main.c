#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float TipoP;
typedef struct ponto {
    TipoP x,y,z;
}*Ponto;
TipoP getX(Ponto pto) {
    return pto->x;
}
TipoP getY(Ponto pto) {
    return pto->y;
}
TipoP getZ(Ponto pto) {
    return pto->z;
}
void setX(Ponto pto, TipoP x) {
    pto->x = x;
}
void setY(Ponto pto, TipoP y) {
    pto->y = y;
}
void setZ(Ponto pto, TipoP z) {
    pto->z = z;
}
Ponto criaPonto(TipoP x, TipoP y, TipoP z) {
    Ponto p;
    p = (Ponto)malloc(sizeof(Ponto));
    setX(p, x);
    setY(p, y);
    setZ(p, z);

    return p;
}
float distEntrePtos(Ponto p1, Ponto p2) {
    float d;
    d = sqrt(pow(getX(p2)-getX(p1), 2)+pow(getY(p2)-getY(p1), 2));
    return d;
}
Ponto centroGeom (Ponto *vetPtos, int nPtos) {
    int i;
    Ponto p = criaPonto(0, 0, 0);
    for(i = 0;i < nPtos;i++) {
        setX(p, getX(p)+getX(vetPtos[i]));
        setY(p, getY(p)+getY(vetPtos[i]));
        setZ(p, getZ(p)+getZ(vetPtos[i]));
    }

    setX(p, getX(p)/nPtos);
    setY(p, getY(p)/nPtos);
    setZ(p, getZ(p)/nPtos);
    return p;
}

int pontosIguais(Ponto p1, Ponto p2) {
    return getX(p1) == getX(p2)
        && getY(p1) == getY(p2)
        && getZ(p1) == getZ(p2);
}

Ponto somaPontos(Ponto p1, Ponto p2) {
    Ponto p = criaPonto(0, 0, 0);
    setX(p, getX(p1)+getX(p2));
    setY(p, getY(p1)+getY(p2));
    setZ(p, getZ(p1)+getZ(p2));
    return p;
}

Ponto difPontos(Ponto p1, Ponto p2){
    Ponto p = criaPonto(0, 0, 0);
    setX(p, getX(p1)-getX(p2));
    setY(p, getY(p1)-getY(p2));
    setZ(p, getZ(p1)-getZ(p2));
    return p;
}

float calculaPerimetroQuadrilatero(Ponto *vetPtos, int nPtos) {
    int A = vetPtos[0],
        B = vetPtos[1],
        C = vetPtos[2],
        D = vetPtos[3];
    return distEntrePtos(A, B)
        + distEntrePtos(B, C)
        + distEntrePtos(C, D)
        + distEntrePtos(D, A);
}
Ponto pontoMedio(Ponto p1, Ponto p2){
    Ponto p = criaPonto(0, 0, 0);
    setX(p, (getX(p1)+getX(p2)/ 2));
    setY(p, (getY(p1)+getY(p2)/ 2));
    setZ(p, (getZ(p1)+getZ(p2)/ 2));
    return p;
}

void printPto(Ponto p) {
    printf("X: %f \nY: %f\nZ: %f\n", getX(p), getY(p), getZ(p));
}
void printAd(Ponto p) {
    printf("Endereco em memoria: %p\n", p);
}

int main()
{
    Ponto p = criaPonto(10, 20, 30);
    Ponto p2 = criaPonto(15, 2, 20);

    printPto(p);
    printAd(p);
    printPto(p2);
    printAd(p2);
    printf("\n\n3.1)Distancia entre os pontos: %f\n\n", distEntrePtos(p, p2));

    Ponto *pVet = (Ponto*)malloc(2*sizeof(Ponto));
    pVet[0] = p;
    pVet[1] = p2;
    Ponto centroGeo = centroGeom(pVet, 2);
    printf("\n\n3.2)Ponto geometrico");
    printPto(centroGeo);
    printf("\n");

    Ponto p3 = criaPonto(10, 20, 30);
    printPto(p3);
    printf("\n3.4)\n p == p3: %i", pontosIguais(p, p3));
    printf("\np == p2: %i", pontosIguais(p, p2));
    printf("\np2 == p3: %i", pontosIguais(p2, p3));

    printf("\n\n3.5)\np + p2 = \n");
    printPto(somaPontos(p, p2));

    printf("\n\n3.6)\np - p2 = \n");
    printPto(difPontos(p, p2));

    Ponto *pVet4 = (Ponto*)malloc(4*sizeof(Ponto));
    pVet4[0] = p;
    pVet4[1] = p2;
    pVet4[2] = p3;
    pVet4[3] = criaPonto(5, 6, 2);

    printf("\n\n3.7)\nPerimetro quadrilatero de 4 pontos: %f", calculaPerimetroQuadrilatero(pVet4, 4));

    printf("\n\n3.8)Ponto Medio de p e p2: \n");
    printPto(pontoMedio(p, p2));

    printf("\n\n");

    free(pVet);
    free(p);
    free(p2);
    return 0;
}
