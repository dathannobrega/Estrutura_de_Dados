#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

TipoGrafo* CriarGrafo(int numVerti){
    TipoGrafo *G;
    if(numVerti == 0)
        return NULL;

    G = (TipoGrafo*)malloc(sizeof(TipoGrafo));
    if(G == NULL)
        return NULL;
    else{
        G->Mat = (int **)malloc(numVerti * sizeof(int*));

        if (G->Mat == NULL){// se der erro ele libera o Grafo e retorna Nulo
            free(G);
            return NULL;
        }


        for (int i = 0; i < numVerti; i++)
        {
            G->Mat[i] = (int*)calloc(numVerti ,sizeof(int)); //aloca memoria e inicializa com zero
            if (G->Mat[i] == NULL) {
                for (int k = 0; k < i; k++) // se dar erro  ele libera toto o vetor e retorna NULL;
                    free(G->Mat[k]);
                free(G);
                return NULL;
            }
        }
        G->numVerti = numVerti;
        G->numArest = 0;
        return G;
    }
}

int inserirAresta(TipoGrafo *G,int v1, int v2){
    if(G==NULL)
        return -1; // nao está alocado
    if(v1 > G->numVerti || v2 > G->numVerti || v2 <= 0 || v1 <= 0)
        return -1; // coloco intervalos invalidos

    G->Mat[v1-1][v2-1] = 1;
    G->numArest++;

    return 0;
}

int retirarAresta(TipoGrafo *G, int v1, int v2){
    if(G == NULL)
        return -1;
    if(G->numVerti == 0)
        return -1;

    if(v1 > G->numVerti || v2 > G->numVerti || v2 <= 0 || v1 <= 0)
        return -1;

    G->Mat[v1][v2] == 0;
    return 0; // Retorna 0 se tudo da certo.
}

void exibirGrafo(TipoGrafo *G){
    for (int i = 0; i < G->numVerti; i++)
    {
        printf("%d:",i+1);
        for (int k = 0; k < G->numVerti; k++)
        {
            if(G->Mat[i][k] == 1)
                printf(" %d", k+1);
        }            
        printf("\n");
    }       
}

void exibirMatriz(TipoGrafo *G) {
    printf("  ");
    for (int j = 0; j < G->numVerti; j++)
            printf("_%d",j+1); 

    printf("\n");
    for (int i = 0; i < G->numVerti; i++)
    {
        printf("%d|",i+1);
        for (int j = 0; j < G->numVerti; j++)
        {
            printf(" %d",G->Mat[i][j]);
        }   
        printf("\n");

    }
}
