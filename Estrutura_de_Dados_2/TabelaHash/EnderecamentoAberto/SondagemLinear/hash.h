#ifndef HASH_H_
#define HASH_H_

typedef struct hash
{
    int tam;
    struct termo **Termo;
}Hash;

typedef struct termo{ // nao precisa de ponteiro pos vamos amarzenar nos vetores
    char port[30];
    char eng[30];
}Termo;


Hash* criar(int tam);
void adicionaTermo(Hash *H,char *port,char *eng);
char* procuraTermo(Hash *H,char *port);
void printTabela(Hash *H);


#endif //hash.h