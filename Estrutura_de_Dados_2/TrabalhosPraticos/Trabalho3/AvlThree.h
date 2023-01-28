#ifndef AVLTHREE_H
#define AVLTHREE_H

#define MAX 100
#include "arvoreBin.h"

typedef struct arvAvl{
    int nOcorrencia;
    int altura;
    char palavra[MAX];
    struct arvAvl *esq;   
    struct arvAvl *dir;   
}AVL;

AVL* cria_avl();
void apagaAVL(AVL *arv);
int altura_no(AVL *arv);
int balanceamento_no(AVL *arv);
void rotaciona_dir(AVL *arv);
void rotaciona_esq(AVL *arv);
void rotaciona_dir_2(AVL *arv);
void rotaciona_esq_2(AVL *arv);
int insere_avl(AVL *avl, char *palavra, int pag);
void imprime_AVL(AVL *avl, int nivel);
int frequencia_AVL(AVL *avl, char *palavra);

#endif