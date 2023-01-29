#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetorBin.h"

Vetor* cria_vetor(){
    Vetor *vet;
    vet = (Vetor*)malloc(sizeof(Vetor));
    if(vet!=NULL)
        vet->fim=0;

    return vet;
}

int vetor_vazio(Vetor *vet){
    if(vet==NULL)   
        return 0;
    if(vet->fim == 0)
        return 1;
    return 0;
}

int vetor_cheio(Vetor *vet){
    if(vet==NULL)
        return 0;
    if(vet->fim==MAX)
        return 1;
    return 0;
}

int insere_elem(Vetor *vet, char *elem){
    if(vet==NULL||vetor_cheio(vet))
        return 0;
    
    strcpy(vet->no[vet->fim],elem);
    vet->fim++;
    return 1;
}

int insere_elem_ord(Vetor *vet, char *elem){
    if(vet==NULL||vetor_cheio(vet))
        return 0;

    if(vetor_vazio(vet)||strcmp(elem,vet->no[vet->fim-1])>0){
        strcpy(vet->no[vet->fim],elem);
        vet->nOcorrencias[vet->fim]=1;
    }
        
    else if(strcmp(elem,vet->no[vet->fim-1])==0){
        vet->nOcorrencias[vet->fim-1]++;
        return 1;
    }
        
        
    else{
        int i, aux=0;
        while(strcmp(elem,vet->no[aux])>=0&&aux<vet->fim){
            if(strcmp(elem,vet->no[aux])==0){
                vet->nOcorrencias[aux]++;
                return 1;
            }
            aux++;
        }
            
        for(i=vet->fim;i>aux;i--)
            strcpy(vet->no[i],vet->no[i-1]);

        strcpy(vet->no[aux],elem);
        vet->nOcorrencias[aux]=1;
    }
    vet->fim++;
    return 1;
}

int busca_binaria(Vetor *vet, int n, char *elem){
    int meio, cont=0, esq=0, dir=vet->fim-1;
    while(esq<=dir){
        meio=(esq+dir)/2;

        if(strcmp(vet->no[meio],elem)==0){
            cont++;
            if(strcmp(vet->no[meio-1],elem)==0)
                dir=meio-1;
            else if(strcmp(vet->no[meio+1],elem)==0)
                esq=meio+1;
        }
        else{
            if(strcmp(vet->no[meio],elem)>0)
                dir=meio-1;
            else if(strcmp(vet->no[meio],elem)<0)
                esq=meio+1;
        }
    }
    return cont;

}

void imprime_vetor(Vetor *vet){
    if(vetor_vazio(vet))
        return;
    int i;
    for(i=0;i<vet->fim;i++)
        printf("%s --- %d\n",vet->no[i],vet->nOcorrencias[i]);
}