#include <stdio.h>
#include <stdlib.h>
#include "src/grafo.h"


int main(int argc, char **args){
    TipoGrafo *G;
    G = CriarGrafo(6);

    inserirAresta(G,1,2);
    inserirAresta(G,1,3);
    inserirAresta(G,2,4);
    inserirAresta(G,3,5);
    inserirAresta(G,5,6);
    inserirAresta(G,5,6);
    inserirAresta(G,4,2);
    inserirAresta(G,6,2);


    exibirGrafo(G);
    printf("\n\n");
    exibirMatriz(G);

    return 0;

}