    #include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct vetor
{
    int **elem;
};

typedef struct vetor Vetor;

Vetor *criar(int i,int j)
{
    Vetor *v;
    v = (Vetor *)malloc(sizeof(Vetor));

        v->elem = (int *)malloc(i * sizeof(int*));
        for (int k = 0; k < i; k++)
            v->elem[k]= (int*)malloc(j*sizeof(int));
        
    return v;
}

void destruir(Vetor *v,int i)
{
    for (int j = 0; j<i; j++)
        free(v->elem[j]);
    free(v->elem);
}

int main(){
    Vetor *M1,*M2;
    int i1,j1;
    printf("Digite o Tamanho das Matrizes 1:");
    scanf("%d %d",&i1,&j1);
    M1 = criar(i1,j1);

    M2 = criar(j1,i1);


    int num;
//Leitura das matrizes
    for (int i = 0; i < i1; i++)
        for (int j = 0; j < j1; j++){
            printf("Numero da Pos M1[%d][%d]= ",i,j);
            scanf("%d",&num);
            M1->elem[i][j] = num;
        }

//FAZ A TRASPOSIÇAO
    for (int i = 0; i < i1; i++)
        for (int j = 0; j < j1; j++){
            M2->elem[j][i] = M1->elem[i][j] ;
        }
//PRINTA
    for (int i = 0; i < i1; i++){
        for (int j = 0; j < j1; j++){
            printf("%d ",M1->elem[i][j]);
        }
        printf("\n");
    } 
        printf("\n\n");
/////////////////////////////////////////////////
    for (int i = 0; i < i1; i++){
        for (int j = 0; j < j1; j++){
            printf("%d ",M2->elem[i][j]);
        }
        printf("\n");
    } 
    return 0;
}