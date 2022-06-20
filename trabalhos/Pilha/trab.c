#include<stdio.h>
#include<C:\Users\Datha\Documents\DATHAN\GSI006- Estruturas de Dados\Trab\pilha.h>


int main(){
    Stack *S;
    S = criar(S);
    while (1)
    {
        int opcao;
        system("cls");
        printf("TOPO: %d", S->top);
        printf("Meu Teste Pilha");
        printf("empilhar[1]");
        printf("Desempilhar[2]");
        printf("Digite uma Opcao: ");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            int num;
            printf("digite um Numero: ");
            scanf("%d",&num);
            empilha(S,num);
            break;
        case 2:
            desempilha(S);
            break;
        default:
            continue;
        }
    }