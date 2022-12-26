#include<stdlib.h>
#include<stdio.h>

typedef struct produto{
    int valor;
}Produto;



int main(){
    Produto *P;
    P = (Produto*)malloc(5*sizeof(Produto));
    for(int i=0;i<5;i++){
        printf("Informe o valor do vetor %d ", i+1);
        scanf("%d",&P[i].valor);
    }
    printf("\nProdutos cadastrados\n");
    for (int i = 0; i < 5; i++){
        printf("vetor %d: %d\n", i+1, P[i]);
    }


    free(P);

    return 0;
}