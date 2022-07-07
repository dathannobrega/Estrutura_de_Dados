#include <stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#define MAX 30

typedef struct deque_no Deque_no;
typedef struct list List;

struct list{
    Deque_no *head;
};

struct lista
{
    int ini;
    int end;
    int value;
};

struct deque_no
{
    struct lista value;
    Deque_no *next;
};





// bool cheio(Deque *D){
//     if(D->qtd==MAX){
//         return true;
//     }else
//         return false;
// }

// bool vazio(Deque *D){
//     if(D->qtd==-1){
//         return true;
//     }else
//         return false;
// }

List* criar(){
    List *L;
    L = (List*)malloc(sizeof(List));
    if(L!=NULL)
        L->head = L;
    return L;
}

void push_front(List *L,struct lista a,int X){
    Deque_no *node;
    node = (Deque_no*)malloc(sizeof(Deque_no));
    //Pega a ultima Cabeça e joga no node.
    node->next=L->head;
    node->value.value=X;
    //Isso faz com que a cabeça da lista vire o node
    L->head=node;
    }

// int pop_front(Deque *D){
//     int x;
//     if(vazio(D)){
//         //nao faz nada
//     } else {
//         D->qtd-=1;
//         x = D->vet[D->ini];
//         D->ini +=1;
//         return x;
//     } 
// }
// void push_back(Deque *D,int x){
//     if(cheio(D)){
//         return;
//     }else {
//         D->qtd +=1;
//         D->end +=1;
//         D->vet[D->end]=x;
//     }
// }

// int pop_back(Deque *D){
//     int x;
//     if(vazio(D)){
//         //nao faz nada
//     } else {
//         D->qtd-=1;
//         x = D->vet[D->end];
//         D->end -=1;
//         return x;
//     } 
// }


int main(void)
{
    List *L;
    L = criar();
    // A Partir daqui a minha pilha começa a existir
    while (1)
    {
        int opcao;
        int x;
        system("cls");
  
        // for (int i = 0; i < D->qtd; i++)
        //     printf("|X=%d|\n", D->vet[i]);

        printf("\nMEU DEQUE\n");
        printf("1 - Push Back\n");
        printf("2 - Pop Back\n");
        printf("3 - Push front\n");
        printf("4 - Pop front\n");
        printf("5 - sair\n");
        scanf("%d", &opcao);
        // switch (opcao)
        // {
        // case 1:
        //     printf("digite o valor: ");
        //     scanf("%d", &x);
        //     push_back(D, x);
        //     break;
        // case 2:
        //     x = pop_back(D);
        //     printf("valor retirado x=%d\n\n", x);
        //     system("pause");
        //     break;
        // case 3:
        //     printf("digite o valor: ");
        //     scanf("%d", &x);
        //     push_front(D, x);
        //     break;
        // case 4:
        //     x = pop_front(D);
        //     printf("valor retirado x=%d\n\n", x);
        //     system("pause");
        //     break;
        // case 5:
        //     return 0;
        // }
    }
    return 0;
}