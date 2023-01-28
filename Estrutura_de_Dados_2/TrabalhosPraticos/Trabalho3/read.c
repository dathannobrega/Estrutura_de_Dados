#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "read.h"

Vetor* readVetorBin(char *file){

    Vetor *vet=cria_vetor();
    FILE *arq;
    clock_t fim,ini=clock();
    double tempo;
    char *palavra=malloc(MAX);
    char *linha=malloc(MAX_LINHA);
    
    arq=fopen(file,"r");
    if(arq==NULL){
        printf("\nArquivo nao encontrado.");
        return NULL;
    }
    else{
        int num_linha=1;
        while(fscanf(arq,"%[^\n] ",linha)!=EOF){
            palavra=strtok(linha," ,.!;/?");
            while(palavra!=NULL){
                int i;
                for(i=0;palavra[i];i++)
                    palavra[i]=tolower(palavra[i]);
                
                palavra[i++]='\0';
                insere_elem_ord(vet,palavra);
                palavra=strtok(NULL," ,.!;/?");
            }
            num_linha++;
        }
        fim=clock();
        tempo=((double)(fim-ini))/CLOCKS_PER_SEC;
        fclose(arq);
        readBuscaBinaria(file);
        return vet;
    }
}

Arv* readBuscaBinaria(char *file){
    Arv *raiz=NULL;
    FILE *arq;
    clock_t ini, fim;
    double tempo;
    ini=clock();

    char *palavra=malloc(MAX);
    char *linha=malloc(MAX_LINHA);

    arq=fopen(file, "r");

    if(arq==NULL){
        printf("\nArquivo nao encontrado!\n");
        return NULL;
    }

    else{
        while(fscanf(arq, "%[^\n] ",linha)!=EOF){
            palavra=strtok(linha," ,.!?;/");
            while(palavra!=NULL){
                int i;
                for(i=0;palavra[i];i++)
                    palavra[i]=tolower(palavra[i]);

                palavra[i++]='\0';
                raiz=insere_elem_arv(raiz,palavra);
                palavra=strtok(NULL, " ,.!?;/");
            }
        }
        fim=clock();
        tempo=((double)(fim-ini))/CLOCKS_PER_SEC;
        fclose(arq);

        
        imprime_arv_ordem(raiz);
        printf("\nTempo gasto: %f",tempo);
        return raiz;
    }
}

AVL* readAVL(char *file){
    AVL *avl=cria_avl();
    FILE *arq;
    clock_t ini, fim;
    double tempo;
    char *palavra=malloc(MAX);
    char *linha=malloc(MAX_LINHA);

    ini=clock();
    arq=fopen(file,"r");

    if(arq==NULL){
        printf("\nArquivo nao encontrado.\n");
        return NULL;
    }

    else{
        int num_linha=1;
        while(fscanf(arq,"%[^\n] ",linha)!=EOF){
            palavra=strtok(linha, " ,.;?/!");
            while(palavra!=NULL){
                int i;
                for(i=0;palavra[i];i++)
                    palavra[i]=tolower(palavra[i]);

                palavra[i++]='\0';
                insere_avl(&avl,palavra,num_linha);
                palavra=strtok(NULL, " ,.!;?/");
            }
            num_linha++;
        }
        fim=clock();
        tempo=((double)(fim-ini))/CLOCKS_PER_SEC;
        fclose(arq);
        imprime_AVL(avl, 0);
        printf("\nTempo gasto: %f",tempo);
        return avl;
    }
}

