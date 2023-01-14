#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

#define ULONG_MAX 0xFFFFFFFFUL

int GeraHash(Hash *H,char *palavra);

Hash *criar (int tam){
    Hash *H;
    H = (Hash*)malloc(sizeof(Hash));
    if(H != NULL) {
        H->num = tam; // defino o tamanho da tabela, sera utilizado para fazer o Mod
        H->tabela = (Termo**)malloc(sizeof(Termo)*tam); // aloca o tanto de vetores para essa pos;
        if(H->tabela != NULL){
            for (int i = 0; i < tam; i++)
            {
                H->tabela[i] = NULL; // começa tudo zerado
            }
        }
    }
    return H;
}

void inserirTermoTh(Hash *H, char *ptChave, char *enValor) {
    int bin; // variavel que vai guardar a posiçao de espalhamento
    Termo *NovoT;
    NovoT = (Termo*)malloc(sizeof(Termo));

    if(NovoT == NULL) // se der erro sai do programa
        return ;
    
    bin = GeraHash(H,ptChave);

    if(H->tabela[bin] == NULL) { // caso seja o primeiro termo da chave sera adicionada no inicio
        strcpy(NovoT->eng,enValor);
        strcpy(NovoT->port,ptChave);
        NovoT->next = H->tabela[bin];
        NovoT->ant = NULL;
        H->tabela[bin] = NovoT; // adiciona no começo
    } else {
        for (Termo *aux = H->tabela[bin]; aux!= NULL; aux = aux->next)
        {
            if(strcmp(aux->port,ptChave) == 0){ // se ja existir apenas substitui
                strcpy(aux->eng,enValor);
                break;
            }else if (aux->next == NULL) {
                strcpy(NovoT->eng,enValor);
                strcpy(NovoT->port,ptChave);
                NovoT->next = NULL;
                NovoT->ant = aux;
                aux->next = NovoT; // adiciona no final da lista
                break;
            }
        }
    }
}


//Espalhamento das chaves. funçao usada apenas nesse codigo , por isso nao está no .h
int GeraHash(Hash *H,char *palavra){
    unsigned long int hash = 0;
    int i=0;
    while (hash < ULONG_MAX && i < strlen(palavra))
    {
        hash = hash << 8; //deslocamento de 8 bits
        hash += palavra[i];
        i++;
    }
    return hash % H->num; // retorna a posiçao propria para fazer a inserçao 
}
//Funcionamento do GERADOR
/*
hash = 0
> desloca 8 bits e inclui a letra 'c' (99 01100011)
> 00000000 01100011
hash = 99
> desloca 8 bits e inclui a letra 'a' (97 01100001)
> 00000000 01100011 01100001
hash = 25441
> desloca 8 bits e inclui a letra 's' (115 01110011)
> 00000000 01100011 01100001 01110011
hash = 6513011
> desloca 8 bits e inclui a letra 'a' (97 01100001)
> 00000000 01100011 01100001 01110011 01100001
hash = 1667330913
hash = 1667330913 mod 1029
hash = 24
*/

char *buscarTermoTh(Hash *H, char *key){
    int bin;
    bin = GeraHash(H,key);
    if(H->tabela[bin] != NULL) {
        for (Termo *aux = H->tabela[bin]->next; aux!= NULL; aux = aux->next)
            {
                if(strcmp(key,aux->port) == 0){
                    return aux->eng;
                }
            }
    }
    return NULL; // se nao achar retorna NULO
}


void percursoTh(Hash *H){
    printf("\nConteudo da tabela:\n");
    for (int i = 0; i < H->num; i++)
    {
        printf("\n(%d)",i);
        for (Termo *aux = H->tabela[i]; aux!= NULL; aux = aux->next)
        {
            printf("(%s,%s) ",aux->port,aux->eng);
        }
    }
}