#include<stdlib.h>
#include<stdio.h>

typedef struct coodernadas{
    int x;
    int y;
}Cord;


int main(){
    Cord *C;
    int n;
    printf("Quantos pontos deseja digitar: ");
    scanf("%d",&n);
    C = (Cord*)malloc(n*sizeof(Cord));

    for(int i=0;i<n;i++){
        printf("Entre com a coordenada x do ponto %d: ", i+1);
        scanf("%d",&C[i].x);
        printf("Entre com a coordenada y do ponto %d: ", i+1);
        scanf("%d",&C[i].y);
    }
    printf("Pontos digitados:");
    for (int i = 0; i < n; i++)
    {
        if(i==n-1)
            printf(" (%d,%d)\n",C[i].x,C[i].y);  
        else
        printf(" (%d,%d);",C[i].x,C[i].y);
    }

    free(C);

    return 0;
}