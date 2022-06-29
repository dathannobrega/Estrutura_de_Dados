#include<stdlib.h>
#include<stdio.h>

typedef struct produto{
    double valor;
}Produto;



int main(){
    Produto *P;
    int n;
    scanf("%d",&n);
    P = (Produto*)malloc(n*sizeof(Produto));
    for(int i=0;i<n;i++){
        printf("Informe o valor do produto %d R$: ", i+1);
        scanf("%lf",&P[i].valor);
    }
    printf("\nProdutos cadastrados\n");
    for (int i = 0; i < n; i++){
        printf("Produto %d - R$: %lf\n", i+1, P[i]);
    }


    free(P);

    return 0;
}