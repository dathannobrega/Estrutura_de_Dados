#include "grafo.h"
#include<stdlib.h>
#include <stdio.h>


Grafo* criarGrafo(int nVert){
    Grafo *G;
    G = (Grafo*)malloc(sizeof(Grafo));
    if(G == NULL){
        return NULL;
    } else {
        G->NumArco = 0;
        G->NumVert = 0;
        G->vertices = NULL;
        
        for (int i = 0; i < nVert; i++)
        {
            G->vertices = inserirVertice(G->vertices,i);
            G->NumVert++;
        }
        return G;
    }
}

NoVert* inserirVertice(NoVert *ini, int num){
    NoVert *aux; // Vai inserri no inicio da lista
    aux = (NoVert*)malloc(sizeof(NoVert));
    aux->vert = num;
    aux->prox = ini;
    aux->ladj = NULL;
    return aux;
}

void inserirArco(Grafo *G, int v1, int v2){
    NoVert *V;
    NoAdj *Z;
    if(G == NULL)
        return;

    for (V = G->vertices; V != NULL; V =  V->prox)
    {
        if(V->vert == v1)//Achou o vertice para inseriri a adjacencia
        {
            for (Z = V->ladj; Z != NULL; Z = Z->prox)
            {
                if(Z->vert == v2) // o arco ja existe, Retorna!
                    return;
            }
            V->ladj = inserirAdjacencia(v2,V->ladj); // insere no inicio
            G->NumArco++;
            break;
        }
    }
}

NoAdj* inserirAdjacencia(int v2,NoAdj *Adj){
    NoAdj *aux;
    aux = (NoAdj*)malloc(sizeof(NoAdj));
    aux->prox = Adj;
    aux->vert = v2;
    return aux;
}

void inserirNovoVertice(Grafo *G, int nv){
    
}

void imprimirListaAdj(Grafo *G){
    NoAdj *X;
    NoVert *Z;
    for (Z = G->vertices ; Z != NULL; Z = Z->prox)
    {
        printf("Vertice %d:",Z->vert);
        for (X = Z->ladj; X != NULL; X =X->prox)
        {
            printf("(%d)",X->vert);
        }
        printf("\n");
    }
}

int RemoveArco(Grafo *G,int v1,int v2){ //!! FAZER RETONRAR O PONTEIRO ALTERADO JÀ
    NoVert *X;
    NoAdj *Z;
    NoAdj *aux;

    for (X = G->vertices; X != NULL; X = X->prox)
    {
        if(X->vert == v1)
            for (Z = X->ladj; Z != NULL; Z = Z->prox)
            {
                if(Z->prox == NULL) // nao exite
                    return -1;
                
                if(Z->prox->vert == v2){
                    aux = Z->prox;
                    Z->prox = aux->prox;
                    free(aux);
                    return 0;
                }if(Z->vert == v2){
                    aux = Z;
                    X->ladj = aux->prox;
                    free(aux);
                    return 0;
                }
            }
    }
    return -1;//Nao encontrado
}

int RemoveVertice(Grafo *G,int v1){ // temos de remover todas as referencias a ela
    NoVert *X,*antVert;
    NoAdj *Z,*antAd;
    X = G->vertices;

    if(X->vert == v1){ // se fort o primeio elemento ele move pro proximo e libera memoria
        antVert = X;
        G->vertices = X->prox;
        free(antVert);
        X = G->vertices;
    }
        while(X != NULL){
            if(X->vert == v1){
                antVert->prox = X->prox;
                free(X); // desaloca da memoria
                X = antVert;
            }
            Z = X->ladj;
            if(Z->vert == v1){ // se a adjacencia for a primeira ele libera e vai pro proximo.
                antAd = Z;
                X->ladj = Z->prox;
                free(antAd);
                continue;
            } else {
                for (Z = X->ladj ; Z!= NULL;)
                {
                    if(Z->vert == v1){ // se for um vertice salva ele
                        antAd->prox = Z->prox;
                        free(Z);
                        Z = antAd;
                    }
                    antAd = Z; // salva o anterior
                    Z = Z->prox; // Avança pro proximo Nó
                }
            }
            antVert = X; // salva o anterior
            X = X->prox; // Avança pro proximo Nó
        }
    return 0;
}

