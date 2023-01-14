#include <stdio.h>
#include <stdlib.h>
#include "src/grafo.h"

int main(){
    Grafo *G;

    G = criarGrafo(5);
    printf("Criado!!\n");

    inserirArco(G, 4, 1);
    inserirArco(G, 0, 1);
    inserirArco(G, 1, 3);
    inserirArco(G, 2, 4);
    inserirArco(G, 2, 3);
    inserirArco(G, 3, 2);
    inserirArco(G, 4, 3);
    inserirArco(G, 0, 3);
    inserirArco(G, 1, 0);
    inserirArco(G, 3, 1);
    inserirArco(G, 4, 2);


    printf("Lista de Adjacencias\n");
    imprimirListaAdj(G);

    printf("\nRemovendo o 0 -> 1\n");
    int Confirm = RemoveArco(G,0,1);
    imprimirListaAdj(G);

    printf("\nRemovendo o vertice 4\n");
    Confirm = RemoveVertice(G,4);
    imprimirListaAdj(G);

    return 0;
}