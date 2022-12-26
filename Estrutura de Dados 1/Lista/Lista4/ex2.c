#include<stdlib.h>
#include<stdio.h>

typedef struct produto{
    int valor;
}Produto;


int main(){
    Produto *P;
    int n,im=0,par=0;
    printf("Quantos inteiros serao lidos: ");
    scanf("%d",&n);
    P = (Produto*)malloc(n*sizeof(Produto));

    for(int i=0;i<n;i++){
        printf("%d inteiro: ", i+1);
        scanf("%d",&P[i].valor);
        if(P[i].valor%2==0)
            par++;
        else
            im++;
    }
    printf("Sao pares: %d dos %d inteiros lidos.\n",par,n);
    printf("Sao impares: %d dos %d inteiros lidos.",im,n);


    free(P);

    return 0;
}