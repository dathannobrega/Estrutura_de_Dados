#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "arvoreBin.h"





ArvoreBin* criarBin(char *word){
    ArvoreBin *A;
    A = (ArvoreBin*)malloc(sizeof(ArvoreBin));
    if(A!= NULL){
        A->dir = NULL;
        A->esq = NULL;
        strcpy(A->data,word);
    }

    return A;
}

void insertBin(ArvoreBin *A, char *word) {
    ArvoreBin *NEW;
    NEW = (ArvoreBin*)malloc(sizeof(ArvoreBin));

    if(NEW == NULL)
        return; // se nao conseguiu alocar ele retorna

    strcpy(NEW->data,word);
    NEW->dir = NULL;
    NEW->esq = NULL;

    ArvoreBin *aux,*ant;
    int pos; // um marcador pra saber se adiciono na esquerda ou direita.
    aux = A;

    while (aux != NULL) // vai fazer esse while ate achar a posiçao nula
    {
        if(strcmp(word, aux->data > 0)){//>0 se o primeiro é maior(in ASCII)que o str 2,
            ant = aux;
            aux = aux->dir;
            pos = 0;
        }else {
            ant = aux;
            aux = aux->esq;
            pos = 1;
        }
    }
    
    if(pos == 0){ // adicionar na direita
        ant->dir = NEW;
    } else {
        ant->esq = NEW;
    }
}


void printBin(ArvoreBin *A) {
    if(A != NULL){
        printBin(A->esq);
        printf("%s ",A->data);
        printBin(A->dir);
    }
}


char* removeElem(ArvoreBin *A,char *word) // funçao que remove 1 elemento da arvore
{
    
}
int searchBin(ArvoreBin *A,char *word); // funçao que procura um elemento na arvore
void eraseBin(ArvoreBin *A); // funçao que apaga todos os elementos 
