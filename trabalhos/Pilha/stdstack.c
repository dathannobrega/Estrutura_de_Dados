#include<pilha.h>

typedef struct stack
{
  int top;
  int vet[MAX];  
}Stack;

bool vazio(Stack *S){
    if(S->top==-1)
        return true;
    else
        return false;
}

bool cheio(Stack *S){
    if(S->top==MAX-1)
        return true;
    else    
        return false;
}

int desempilha(Stack *S){
    if(vazia(S))
        return;
    S->top = S->top-1;
    return S->vet[S->top+1];
}

bool empilhar(Stack *S,int x){
    if(cheio(S))
        return false;
    S->top = S->top+1;
    S->vet[S->top]=x;
    return true;
}

Stack* criar(Stack *S){
    Stack *P;
    P = (Stack*)malloc(sizeof(Stack));
    P->top=-1;
    return P;
}

bool destruir(Stack *S){
    free(S);
    return true;
}
