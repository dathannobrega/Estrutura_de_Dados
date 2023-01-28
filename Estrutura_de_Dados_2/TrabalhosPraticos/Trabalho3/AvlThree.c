#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "AvlThree.h"

AVL* cria_avl(){
    return NULL;
}

void apagaAVL(AVL *arv){
    if(arv==NULL)
        return;
    
    apagaAVL(arv->esq);
    apagaAVL(arv->dir);
    free(arv);
    arv=NULL;
}

int altura_no(AVL *arv){
    if(arv==NULL)
        return -1;
    return arv->altura;
}

int balanceamento_no(AVL *arv){
    return labs((altura_no(arv->esq))-(altura_no(arv->dir)));
}

void rotaciona_dir(AVL *arv){
    AVL *sub_esq = arv->esq;
    arv->esq = sub_esq->dir;
    sub_esq->dir = arv;

    arv->altura=maior(altura_no(arv->esq),altura_no(arv->dir))+1;
    sub_esq->altura=maior(altura_no(sub_esq->esq),arv->altura)+1;

    arv=sub_esq;
}

void rotaciona_esq(AVL *arv){
    AVL *sub_dir = arv->dir;
    arv->dir = sub_dir->esq;
    sub_dir->esq = arv;

    arv->altura = maior(altura_no(arv->esq),altura_no(arv->dir))+1;

    sub_dir->altura = maior(altura_no(sub_dir->dir),arv->altura)+1;

    arv = sub_dir;
}

void rotaciona_dir_2(AVL *arv){
    rotaciona_esq(&arv->esq);
    rotaciona_dir(arv);
}

void rotaciona_esq_2(AVL *arv){
    rotaciona_dir(&arv->dir);
    rotaciona_esq(arv);
}

int insere_avl(AVL *avl, char *palavra, int pag){
    int r;
    if(avl==NULL){
        AVL *N;
        N=(AVL*)malloc(sizeof(struct arvAvl));
        if(N==NULL)
            return 0;
        
        strcpy(N->palavra,palavra);
        N->nOcorrencia=1;
        N->altura=0;
        N->esq=NULL;
        N->dir=NULL;
        avl=N;
        return 1;
    }

    AVL *aux=avl;

    if(strcmp(palavra, aux->palavra)<0){
        r=insere_avl(&(aux->esq),palavra, pag);
        if(r==1){
            if(balanceamento_no(aux)>=2){
                if(strcmp(palavra,avl->esq->palavra)<0)
                    rotaciona_dir(avl);
                else
                    rotaciona_dir_2(avl);
            }
        }
    }
    else if(strcmp(palavra, aux->palavra)>0){
        r=insere_avl(&(aux->dir),palavra,pag);
        if(r==1){
            if(balanceamento_no(aux)>=2){
                if(strcmp(avl->dir->palavra,palavra)<0)
                    rotaciona_esq(avl);
                else
                    rotaciona_esq_2(avl);
            }
        }
    }
    else{
        aux->nOcorrencia++;
        return 1;
    }

    aux->altura=maior(altura_no(aux->esq),altura_no(aux->dir))+1;

    return r;
}

void imprime_AVL(AVL *avl, int nivel){
    if(avl!=NULL){
        imprime_AVL(avl->esq, nivel+1);
        printf("\n%s --- %d",avl->palavra, avl->nOcorrencia);
        imprime_AVL(avl->dir,nivel+1);
    }
}

int frequencia_AVL(AVL *avl, char *palavra){
    if(avl==NULL)
        return 0;

    int freq=0;
    AVL *aux=avl;

    while(aux!=NULL){
        if(strcmp(aux->palavra, palavra)==0)
            freq=aux->nOcorrencia;
        if(strcmp(aux->palavra,palavra)<0)
            aux=aux->dir;
        else
            aux=aux->esq;
    }
    return freq;
}