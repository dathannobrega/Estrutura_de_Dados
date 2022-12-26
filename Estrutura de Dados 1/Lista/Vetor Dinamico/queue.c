#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
    int tam;
    int max;
    int *vet;
    int ini;
    int end;
}Queue;


bool cheio(Queue *Q){
    return Q->end==Q->ini;
}

bool vazia(Queue *Q){
    return (Q->end+1)%Q->max==Q->ini;
}

Queue* criar(int x){
    Queue *Q;
    Q= (Queue*)malloc(sizeof(Queue));
    if(Q!=NULL){
        Q->max=x;
        Q->vet = (int*)malloc(x*sizeof(int));
        Q->ini=0;
        Q->end=0;
    }
}

void enqueue(Queue *Q,int x){
    if(cheio(Q)){}
    else{
        Q->vet[Q->tam%Q->max]=x;
        Q->end+=1;
        Q->tam+=1;
    }
}

int dequeue(Queue *Q){
    if(vazia(Q)){}
    else{
        if(Q->ini>=Q->max)//Lista circular
            Q->ini=(Q->tam%Q->max);
        int x;
        x=Q->vet[Q->ini];
        Q->ini+=1;
        return x;
    }
}



