#ifndef ARVOREBIN_H_
#define ARVOREBIN_H_

typedef struct  arvoreBin{
    char *data;
    struct arvoreBin *esq;
    struct arvoreBin *dir;
}ArvoreBin;



ArvoreBin* criarBin(char *word);
void insertBin(ArvoreBin *A,char *word); // funçao que inserer um elemnto na arvore
void printBin(ArvoreBin *A); // funçao que printa toda a arvore
void removeElem(ArvoreBin *A,char *word); // funçao que remove 1 elemento da arvore
int searchBin(ArvoreBin *A,char *word); // funçao que procura um elemento na arvore
void eraseBin(ArvoreBin *A); // funçao que apaga todos os elementos 


#endif // arvorebin.h