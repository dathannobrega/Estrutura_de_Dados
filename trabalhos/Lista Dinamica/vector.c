#include<vector.h>


//Retorna um poteiro do Vector
Vector_head* criar (){
    Vector_head *V;
    V = (Vector_head*)malloc(sizeof(Vector_head));
    //O proximo termo de uma lista e sempre Null;
    if(V!=NULL)
        V->Head = NULL;
    return V;
}


//Armazena um int no final do Vetor
void push_back(Vector_head *V,int X){
    Vector *NEW;
    NEW = (Vector*)malloc(sizeof(Vector));
    NEW->data = X;
    NEW->next=NULL;

     if(V->Head == NULL)
        V->Head = NEW;
    else{
        Vector *aux;
        aux = V->Head;

        while(aux->next != NULL)
            aux = aux->next;

        aux->next = NEW;
    }

}

//Armazena um int no final do Vetor
//int pop_back(Vector *V);