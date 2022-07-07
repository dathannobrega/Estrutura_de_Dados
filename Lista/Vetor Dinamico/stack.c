#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int total;
    int *vet;
    int top;
}Stack;


bool full(Stack *S){
    if(S->top==S->total-1)
        return true;
    else
        return false;
}

bool clear(Stack *S){
    if(S->top==-1)
        return true;
    else
        return false;
}

Stack* criar(int x){
    Stack *S;
    S = (Stack*)malloc(sizeof(Stack));
    if(S!=NULL){
        S->vet = (int) malloc(x*sizeof(int));
        S->top=-1;
        S->total=x;
    }
    return S;
}

void push(Stack *S,int x){
    if(full(S))
        return;
    else{
        S->top+=1;
        S->vet[S->top]=x;
    }
}

int pop(Stack *S){
    if(clear(S)){}
    else{
        int x=S->vet[S->top];
        S->top-=1;
        return x;
    }
}
