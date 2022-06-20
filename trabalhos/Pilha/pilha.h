

typedef struct pair{
    int i;
    int j;
}Pair;

typedef struct stack {
    int top;
    Pair *vet;
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

//retorna zero quando da erro
bool desempilha(Stack *S, int *i, int *j){
    if(vazio(S)){
        return false;
    }
    else {
        *i=S->vet[S->top].i;
        *j=S->vet[S->top].j;
        S->top = S->top-1;
        return true;
    }
}

bool empilhar(Stack *S,int i,int j){
    if(cheio(S))
        return false;
    S->top = S->top+1;
    S->vet[S->top].i= i;
    S->vet[S->top].j= j;
    return true;
}

Stack* criar(){
    Stack *P;

    P = (Stack*)malloc(sizeof(Stack));
    P->vet = (Pair*)malloc(MAX*sizeof(Pair));
    if(P!=NULL)
        P->top=-1;
    return P;
}

bool destruir(Stack *S){
    free(S);
    return true;
}
