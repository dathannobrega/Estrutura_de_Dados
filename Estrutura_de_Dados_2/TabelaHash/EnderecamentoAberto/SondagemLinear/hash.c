#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"hash.h"

#define ULONG_MAX 4294967295


int geraHash(Hash *H,char *key);

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
    bin = geraHash(H,port);
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
            while(H->Termo[(bin+i)%H->tam] != NULL){
                if(strcmp(port,H->Termo[(bin+i)%H->tam]->port) == 0) {
                    //printf("Alocado: %d-- ",(bin+i)%H->tam);
                    strcpy(H->Termo[(bin+i)%H->tam]->eng,eng); // se existir um termo igual ele so copia em cima
                    return;
                }
                if(tam == H->tam){
                    printf("(ERROR):TABELA CHEIA");
                    return;
                }
                i++;tam++;
            }
        }
            //printf("Alocado: %d ",(bin+i)%H->tam);
            strcpy(NovoT->port,port);
            strcpy(NovoT->eng,eng); 
            H->Termo[(bin+i)%H->tam] = NovoT;
    }
}


int geraHash(Hash *H,char *key){ // funçao que gera o hash para alocar os valores 
    unsigned long int hash =0;
    int i =0;
    while (hash < ULONG_MAX && i < strlen(key))
    {
        hash= hash << 8;
        hash += key[i];
        i++;
    }
    return hash % H->tam; // é necessario passa ja com o resto da diferença
}

/* FUNCIONAMENTO DA FUNÇAO GERA HASH
hashval = 0
> desloca 8 bits e inclui a letra 'c' (99 01100011)
> 00000000 01100011
hashval = 99
> desloca 8 bits e inclui a letra 'a' (97 01100001)
> 00000000 01100011 01100001
hashval = 25441
> desloca 8 bits e inclui a letra 's' (115 01110011)
> 00000000 01100011 01100001 01110011
hashval = 6513011
> desloca 8 bits e inclui a letra 'a' (97 01100001)
> 00000000 01100011 01100001 01110011 01100001
hashval = 1667330913
hashval = 1667330913 mod 1029
hashval = 24
*/

char* procuraTermo(Hash *H,char *port){
    int bin;
    bin = geraHash(H,port);
    int tam=0,i=0;
    while(H->Termo[(bin+i)%H->tam] != NULL){ // o mod evita que saia do vetor
        if(tam > H->tam){
            printf("(ERROR):Not Found");
            return NULL;
        }
        if(strcmp(port,H->Termo[(bin+i)%H->tam]->port) == 0){
            return H->Termo[(bin+i)%H->tam]->eng;
        }
        i++;tam++;
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