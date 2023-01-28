#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvoreBin.h"

int arv_vazia(Arv *arv){
    if(arv==NULL)
        return 1;
    return 0;
}

int maior(int m1, int m2){
    if(m1>m2)
        return m1;
    return m2;
}

int altura(Arv *arv){
    if(arv_vazia(arv))
        return -1;
    return maior(altura(arv->esq),altura(arv->dir))+1;
}

int fator_Balanceamento(Arv *arv){
    return ((altura(arv->esq))-(altura(arv->dir)));
}

Arv* insere_elem_arv(Arv* raiz, char *palavra){
    Arv* p;
    if(arv_vazia(raiz)){
        p=(Arv*)malloc(sizeof(Arv));
        strcpy(p->palavra, palavra);
        p->nOcorrencia=1;
        p->esq=NULL;
        p->dir=NULL;
        return p;
    }
    else{
        int i=strcmp(raiz->palavra,palavra);
        if(i==0)
            raiz->nOcorrencia++;
        else{
            if(i>0)
                raiz->esq=insere_elem_arv(raiz->esq,palavra);
            else    
                raiz->dir=insere_elem_arv(raiz->dir,palavra);
        }
    }
    return raiz;
}

void imprime_arv_ordem(Arv* arv){
    if(!arv_vazia(arv)){
        imprime_arv_ordem(arv->esq);
        printf("%s ---%d\n",arv->palavra,arv->nOcorrencia);
        imprime_arv_ordem(arv->dir);
    }
}

int arv_busca(Arv* arv, char *palavra){
    int i, ret=0;

    if(!arv_vazia(arv)){
        int i=strcmp(arv->palavra,palavra);
        if(i==0)
            ret=arv->nOcorrencia;
        else{
            if(i>0)
                ret=arv_busca(arv->esq,palavra);
            else
                ret=arv_busca(arv->dir,palavra);
        }
    }
    return ret;
}

void arv_pesquisa_frequencia(Arv* arv, int frequencia){
    if(!arv_vazia(arv)){
        arv_pesquisa_frequencia(arv->esq,frequencia);
        if(frequencia==arv->nOcorrencia)
            printf("%s \n",arv->palavra);
        
        arv_pesquisa_frequencia(arv->dir, frequencia);
    }
}