#ifndef  PILHA_H
#define  PILHA_H
#define MAX 30
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct stack
    {
    int top;
    int vet[MAX];  
    }Stack;
    
    bool vazio(Stack *S);
    bool cheio(Stack *S);
    int desempilha(Stack *S);
    bool empilhar(Stack *S,int x);
    Stack* criar(Stack *S);
    bool destruir(Stack *S);

#endif  /*PILHA_H*/