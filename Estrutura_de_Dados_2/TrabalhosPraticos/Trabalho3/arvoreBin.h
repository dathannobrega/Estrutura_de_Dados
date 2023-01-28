#ifndef ARVOREBIN_H
#define ARVOREBIN_H
#define MAX 100

struct arv{
    char palavra[MAX];
    int nOcorrencia;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

int arv_vazia(Arv *arv);
int maior(int m1, int m2);
int altura(Arv *arv);
int fator_Balanceamento(Arv *arv);
Arv* insere_elem_arv(Arv* raiz, char *palavra);
void imprime_arv_ordem(Arv* arv);
int arv_busca(Arv* arv, char *palavra);
void arv_pesquisa_frequencia(Arv* arv, int frequencia);

#endif