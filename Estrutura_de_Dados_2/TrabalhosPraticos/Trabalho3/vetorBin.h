#ifndef VETORBIN_H
#define VETORBIN_H

#define MAX 100

typedef struct vetor{
    char no[MAX][MAX];
    int nOcorrencias[MAX];
    int fim;
}Vetor;

Vetor* cria_vetor();
int vetor_vazio(Vetor *vet);
int vetor_cheio(Vetor *vet);
int insere_elem(Vetor *vet, char *elem);
int insere_elem_ord(Vetor *vet, char *elem);
int busca_binaria(Vetor *vet, int n, char *elem);
void imprime_vetor(Vetor *vet);

#endif