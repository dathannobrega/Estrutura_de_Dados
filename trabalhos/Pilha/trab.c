#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 30
#include "pilha.h"

//cria e coloca os valores na matriz
void armazenamento(int vertice, int arestas, int matriz[vertice][vertice]){

    for (int i = 0; i < vertice; i++){
        for (int j = 0; j < vertice; j++){
            matriz[i][j] = 0;
        }
    }

    //(a =1,b = 2, c = 3, etc.)
    for (int k = 0; k < arestas; k++){
        int i,j,x;
        scanf("%d %d %d",&i,&j,&x);
        matriz[i-1][j-1]=x;
    }
}

int procura(int vertice, int matriz[vertice][vertice], Stack *S,int ini, int fim){
    bool deuCerto;
    for (int i = ini-1,j=1;j<=vertice; j++)
    {
         if(matriz[i][j]==0 && j == vertice-1){
            deuCerto = desempilha(S,&i,&j);
            if(!deuCerto)
                return-1;
            else
                continue;
        }if(matriz[i][j]!=0 && j == fim-1){
            int soma=matriz[i][j];
            //Desempilha tudo e retorna o valor
            while (desempilha(S,&i,&j))
            {
                soma+=matriz[i][j];
            }
            return soma;
        }

        if(matriz[i][j]==0){
            continue;
        }else{
            empilhar(S,i,j);
            i=j;
            j=-1;
        }
       
    }
}


int main(){
    Stack *S;
    S = criar();
    int valor;
    int vertice,arestas;
    scanf("%d %d", &vertice, &arestas);
    int matriz[vertice][vertice];

    armazenamento(vertice, arestas, matriz);

    int ini,fim;
    scanf("%d %d",&ini,&fim);

    valor = procura(vertice, matriz, S,ini,fim);
    printf("%d",valor);

}