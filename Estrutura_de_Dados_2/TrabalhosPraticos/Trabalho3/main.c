#ifdef _WIN32
    #define clean "cls"
#elif __linux__
    #define clean "clear"
#endif
//CORRIGIR LINHAS  29, 32, 55 E 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "AvlThree.h"
#include "arvoreBin.h"
#include "read.h"
#include "vetorBin.h"

int main(){
    Vetor *vet;
    vet = cria_vetor();
    Arv *raiz = NULL;
    AVL *avl;
    avl = cria_avl();
    int op,frequencia, ocorrencias=0;
    char arq[MAX];
    char palavra[MAX];
    clock_t ini,fim;
    double tempo;
    
    printf("\nDigite o nome do arquivo que deseja abrir: ");
    scanf("%s",arq);
    
    printf("\n-----------------------Pesquisa Binaria(Vetor)----------------------\n");
    vet=readVetorBin(arq);
    printf("\n-------------Arvore Binaria de Busca sem Balanceamento-------------\n");
    raiz=readBuscaBinaria(arq);
    printf("\n-----------------------------Arvore AVL----------------------------\n");
    avl=readAVL(arq);

    if(vet==NULL||raiz==NULL||avl==NULL){
        printf("\nNao foi possivel realizar o armazenamento nas arvores.\n");
        return 0;
    }
    while(1){
        printf("\n--------------------------------Menu--------------------------------\n");
        printf("[1]-> Visualizar a frequencia de uma determinada palavra;\n");
        printf("[2]-> Buscar palavras que apareceram X vezes, dado um numero inteiro;\n");
        printf("[3]-> Encerrar o programa :(\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d",&op);
        if(op==3)
            break;
            
        switch(op){
            case 1:
                printf("\nDigite a palavra desejada: ");
                getchar();
                scanf("%[^\n]%*c",palavra);
                system(clean);
                printf("\n-----------------------Pesquisa Binaria(Vetor)----------------------\n");

                ini=clock();
                ocorrencias=arv_busca(raiz,palavra);
                fim=clock();
                tempo=((double)(fim-ini))/CLOCKS_PER_SEC;

                if(ocorrencias!=0)
                    printf("\nOcorrencias de %s -> %d",palavra, ocorrencias);
                else
                    printf("\nNenhuma ocorrencia para %s.",palavra);
                printf("\nTempo gasto: %f\n",tempo);

                printf("\n-------------Arvore Binaria de Busca sem Balanceamento-------------\n");

                ini=clock();
                ocorrencias=arv_busca(raiz,palavra);
                fim=clock();
                tempo=((double)(fim-ini))/CLOCKS_PER_SEC;

                if(ocorrencias!=0)
                    printf("\nOcorrencias de %s -> %d",palavra, ocorrencias);
                else
                    printf("\nNenhuma ocorrencia para %s.",palavra);
                printf("\nTempo gasto: %f\n",tempo);

                printf("\n-----------------------------Arvore AVL----------------------------\n");

                ini=clock();
                ocorrencias=frequencia_AVL(avl,palavra);
                fim=clock();
                tempo=((double)(fim-ini))/CLOCKS_PER_SEC;

                if(ocorrencias!=0)
                    printf("\nOcorrencias de %s -> %d",palavra, ocorrencias);
                else
                    printf("\nNenhuma ocorrencia para %s.",palavra);
                printf("\n\nTempo gasto: %f\n",tempo);

                break;
            
            case 2:
                printf("\nDigite a frequencia que deseja: ");
                scanf("%d",&frequencia);
                system(clean);

                ini=clock();
                printf("\nPalavras que apareceram %d vezes no poema: \n",frequencia);
                arv_pesquisa_frequencia(raiz,frequencia);
                fim=clock();

                tempo=((double)(fim-ini))/CLOCKS_PER_SEC;
                printf("\nTempo gasto: %f.\n",tempo);

                break;
            default: 
                system(clean);
                printf("\nInsira opcoes validas([1], [2] ou [3])\n");
                break;
        }
    }
    system(clean);
    printf("\nObrigado por usar!\n");
}