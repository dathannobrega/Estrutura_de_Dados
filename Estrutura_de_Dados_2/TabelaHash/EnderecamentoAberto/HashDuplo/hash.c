#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"hash.h"

#define ULONG_MAX 4294967295


int geraHash(Hash *H,char *key,int num);

Hash* criar(int tam){
    Hash *H;
    H = (Hash*)malloc(sizeof(Hash));
    if( H != NULL){
        H->Termo = (Termo**)malloc(sizeof(Termo)*tam);
        if(H->Termo != NULL){
            for (int i = 0; i < tam; i++)
                H->Termo[i] = NULL;
            H->tam = tam;
        }
    }
    return H;
}

void adicionaTermo(Hash *H,char *port,char *eng){
    int bin;
    int tam=0,i=0;
    bin = geraHash(H,port,0);
    Termo *NovoT;
    NovoT = (Termo*)malloc(sizeof(Termo));
    printf("\n%p ",NovoT);
    if(NovoT != NULL){
        if(H->Termo[bin] == NULL){
            strcpy(NovoT->port,port);
            strcpy(NovoT->eng,eng);
            H->Termo[bin] = NovoT;
            return;
        } else {
            while(H->Termo[bin] != NULL){
                if(strcmp(port,H->Termo[bin]->port) == 0) {
                    //printf("Alocado: %d-- ",(bin+i)%H->tam);
                    strcpy(H->Termo[bin]->eng,eng); // se existir um termo igual ele so copia em cima
                    return;
                }
                if(tam == H->tam){
                    printf("(ERROR):TABELA CHEIA");
                    return;
                }
                i++;tam++;
                bin = geraHash(H,port,i); // gera um outro hash
            }
        }
            //printf("Alocado: %d ",(bin+i)%H->tam);
            strcpy(NovoT->port,port);
            strcpy(NovoT->eng,eng); 
            H->Termo[bin] = NovoT;
    }
}


int geraHash(Hash *H,char *key,int num){ // funçao que gera o hash para alocar os valores //gera um valor quadratico
    unsigned long int hash =0;
    int i =0;
    
    while (hash < ULONG_MAX && i < strlen(key))
    {
        hash= hash << 8;
        hash += key[i];
        i++;
    }
    int value = geraHash2(H,key, num); // chama uma segunda funçao hash
    return (hash +value) % H->tam; // é necessario passa ja com o resto da diferença
}

int geraHash2(Hash *H,char *key,int num){ // funçao que gera o hash para alocar os valores //gera um valor quadratico
    unsigned long int hash =0;
    int i =0;
    
    while (hash < ULONG_MAX && i < strlen(key))
    {
        hash= hash << 8;
        hash += key[i];
        i++;
    }
    return hash; // é necessario passa ja com o resto da diferença
}



char* procuraTermo(Hash *H,char *port){
    int bin;
    bin = geraHash(H,port,0);
    int tam=0,i=0;
    while(H->Termo[bin] != NULL){ // o mod evita que saia do vetor
        if(tam > H->tam){
            printf("(ERROR):Not Found");
            return NULL;
        }
        if(strcmp(port,H->Termo[bin]->port) == 0){
            return H->Termo[bin]->eng;
        }
        i++;tam++;
        bin = geraHash(H,port,i); // gera mais 1 hash // a cada loop ele atualiza o hash
    }
}

void printTabela(Hash *H){
    printf("\nConteudo da tabela:\n");
    for (int i = 0; i <H->tam; i++)
    {
        //printf("\n(%d) %p ",i,H->Termo[i]);
        if(H->Termo[i] != NULL)
           printf("(%s,%s) \n",H->Termo[i]->port,H->Termo[i]->eng);
        else 
            printf("NULL\n");
    }
}