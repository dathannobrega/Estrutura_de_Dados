#ifndef HASH_H_
#define HASH_H_

typedef struct termo{ // lista duplamente encadeada para facilitar a remoçao
    char port[30];
    char eng[30];
    struct termo *next;
    struct termo *ant;
}Termo;

typedef struct hash
{
    int num;
    Termo **tabela;
}Hash;

//Cria e aloca o vetor do tamanho da Posiçao criada
Hash *criar (int tam);
void inserirTermoTh(Hash *H, char *ptChave, char *enValor);
char *buscarTermoTh(Hash *H, char *key);
void percursoTh(Hash *H);

#endif // hash.h