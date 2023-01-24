#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"



int main(int argc, char *args){
    ArvoreBin *A;
    A = criarBin("Hoje");
    FILE *arq;
    char *arquivo;
    char palavra[30];
    printf("Digite o Nome do arquivo: \n");
    scanf("%s", arquivo);

    arq = fopen(arquivo,"r"); // o arquivo deve exitir previamente


    while (fgets(palavra,30,arq))
    {
        insertBin(A,palavra);
    }
    

    printBin(A);


    fclose(arq);


    return 0;
}