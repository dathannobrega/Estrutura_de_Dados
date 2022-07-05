#include <stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#define MAX 30

struct deque
{
    int qtd;
    int ini;
    int end;
    int vet[MAX];
};

typedef struct deque Deque;

bool cheio(Deque *D){
    if(D->qtd==MAX){
        return true;
    }else
        return false;
}

bool vazio(Deque *D){
    if(D->qtd==-1){
        return true;
    }else
        return false;
}

Deque* criar(){
    Deque *D;
    D = (Deque*)malloc(sizeof(Deque));
    if(D==NULL)
        return NULL;
    D->end=-1;
    D->ini=-1;
    D->qtd=0;
    return D;
}

void push_front(Deque *D,int x){
    if(cheio(D)){
        return;
    }else {
        D->qtd +=1;
        D->ini -=1;
        D->vet[D->ini]=x;
    }
}

void push_back(Deque *D,int x){
    if(cheio(D)){
        return;
    }else {
        D->qtd +=1;
        D->end +=1;
        D->vet[D->end]=x;
    }
}

int pop_back(Deque *D){
    int x;
    if(vazio(D)){
        //nao faz nada
    } else {
        D->qtd-=1;
        x = D->vet[D->end];
        D->end -=1;
        return x;
    } 
}

int pop_front(Deque *D){
    int x;
    if(vazio(D)){
        //nao faz nada
    } else {
        D->qtd-=1;
        x = D->vet[D->ini];
        D->ini +=1;
        return x;
    } 
}

int main(void)
{
    Deque *D;
    D = criar();
    // A Partir daqui a minha pilha começa a existir
    while (1)
    {
        int opcao;
        int x;
        system("cls");
  
        for (int i = 0; i < D->qtd; i++)
            printf("|X=%d|\n", D->vet[i]);

        printf("\nMEU DEQUE\n");
        printf("1 - Push Back\n");
        printf("2 - Pop Back\n");
        printf("3 - Push front\n");
        printf("4 - Pop front\n");
        printf("5 - sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("digite o valor: ");
            scanf("%d", &x);
            push_back(D, x);
            break;
        case 2:
            x = pop_back(D);
            printf("valor retirado x=%d\n\n", x);
            system("pause");
            break;
        case 3:
            printf("digite o valor: ");
            scanf("%d", &x);
            push_front(D, x);
            break;
        case 4:
            x = pop_front(D);
            printf("valor retirado x=%d\n\n", x);
            system("pause");
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}