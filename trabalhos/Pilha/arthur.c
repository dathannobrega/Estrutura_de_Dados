#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int elements[100];
};

typedef struct stack Stack; // tipo pilha

Stack *create(int *ok)
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));

    if (stack == NULL)
    {
        *ok = 0; // nao foi possivel criar a pilha
    }
    else
    {
        *ok = 1; // pilha criada com sucesso
        stack->top -= 1;
    }

    return stack;
}

int isEmpty(Stack *stack)
{

    int firstStackPosition = -1;
    return (stack->top == firstStackPosition);
}

int isFull(Stack *stack) // emcapsulamento da checagem da condicao da pilha "se cheia"
{

    return (stack->top == 100);
}

int push(Stack *stack, int element) // incrementar elemento na pilha
{

    if (isFull(stack))
    {

        return 0;
    }
    else
    {
        stack->top += 1;
        stack->elements[stack->top] = element;
    }
    return 1;
}

int pop(Stack *stack) // remover elemento da pilha
{

    int poppedElement;

    if (isEmpty(stack))
    {

        return 0;
    }
    else
    {

        poppedElement = stack->elements[stack->top];
        stack->top -= 1;
    }
    return poppedElement;
}

void destroy(Stack *stack) // liberar espaco alocado anteriormente para a pilha
{

    if (stack != NULL) // se a pilha existir
    {
        free(stack);
    }

}

void stack_top(Stack *stack, int *line)
{
    *line = stack->elements[stack->top];
    return;
}

int main(void) {
    int deuCerto;

    Stack *lineStack;
    Stack *columnStack;
    // lineStack = create(&deuCerto);
    // columnStack = create(&deuCerto);

    int vertices;
    int arestas;
    scanf("%d %d",&vertices,&arestas);
    
    int matriz[vertices][vertices];

    // preencher matriz com valores nulos
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < arestas; i++) {
        int ponto1, ponto2, peso;
        scanf("%d %d %d", &ponto1, &ponto2, &peso);
        matriz[ponto1-1][ponto2-1] = peso;
    }


    int inicio, fim;
    scanf("%d %d", &inicio, &fim);

    int custo = 0;
    int column, line = inicio - 1;
    int achou;

    while(1) {
        for (column = 0; column < vertices; column++) {
            if(column==fim-1 && matriz[line][column]!=0) {
                custo += matriz[line][column];
                break;
            }
            if (matriz[line][column] != 0) {
                custo += matriz[line][column];
                push(columnStack, column);
                push(lineStack, line);
                stack_top(columnStack, &line);
                //se ficar zero ele entrar volta no for dnv com 1 ( linha 127)
                column = -1;
            }
            if(column==fim-1 && matriz[line][column]!=0) {
                break;
            }
            if (column == vertices-1) {
                int columnAux;
                int lineAux;
                if (isEmpty(lineStack)) {
                    custo = -1;
                    break;
                }
                stack_top(lineStack, &lineAux);
                stack_top(columnStack, &columnAux);

                custo -= matriz[lineAux][columnAux];
                // nao adiciona pois o for adiciona mais 1 na coluna
                column = pop(columnStack);
                line = pop(lineStack);
                
            }
        }
        break;

    }
    printf("chegou");

    

    printf("Custo = %d\n", custo);

    destroy(columnStack);
    destroy(lineStack);
    return 0;
}
/*
6
8
1 2 30
1 3 40
1 4 50
2 4 20
3 4 40
3 6 0
4 5 20
6 5 20
1 6
*/
