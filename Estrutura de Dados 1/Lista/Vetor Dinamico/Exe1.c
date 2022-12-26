#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct vetor
{
    float *elem;
    int total;
    int max;
};

typedef struct vetor Vetor;


bool cheio(Vetor *v){
    if(v->max==v->total)
        return true;
    else
        return false;
}

bool vazio(Vetor *v){
    if(v->total==0)
        return true;
    else
        return false;
}

void push(Vetor *v,float x){
    if(cheio(v)){

    } else {
        v->elem[v->total]=x;
        v->total+=1;
    }
}

Vetor *criar(int n, bool *deuCerto)
{
    Vetor *v;
    v = (Vetor *)malloc(sizeof(Vetor));
    if (v == NULL)
        *deuCerto = false;
    else
    {
        v->elem = (float *)malloc(n * sizeof(float));
        if (v->elem == NULL)
            *deuCerto = false;
        else
        {
            *deuCerto = true;
            v->total = 0;
            v->max = n;
        }
    }
    return v;
}

void destruir(Vetor *v)
{
    free(v->elem);
    free(v);
}




int main(){
    Vetor *v;
    int x,n;
    bool deuCerto;
    printf("Digite o tamnho do Vetor: ");
    scanf("%d",&n);
    v = criar(n,&deuCerto);

    if(!deuCerto){
        printf("ERROR! - Impossivel Criar o  vetor");  
    }

    destruir(v);

    return 0;
}