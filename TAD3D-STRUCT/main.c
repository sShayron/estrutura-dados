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
        p->x = p->x + vetPtos[i]->x;
        p->y = p->y + vetPtos[i]->y;
        p->z = p->z + vetPtos[i]->z;
    }
    p->x = p->x/nPtos;
    p->y = p->y/nPtos;
    p->z = p->z/nPtos;
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
    printf("\n\nDistancia entre os pontos: %f\n\n", distEntrePtos(p, p2));

    Ponto *pVet = (Ponto*)malloc(2*sizeof(Ponto));
    pVet[0] = p;
    pVet[1] = p2;
    Ponto centroGeo = centroGeom(pVet, 2);
    printPto(centroGeo);

    free(pVet);
    free(p);
    free(p2);
    return 0;
}
