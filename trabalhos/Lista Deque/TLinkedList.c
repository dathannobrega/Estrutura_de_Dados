#include <stdio.h>
#include <stdlib.h>
#include "TLinkedList.h"


typedef struct list_node List_node;


struct list{
    List_node *head;
};


struct list_node{
    struct aluno data;
    List_node *next;
};


List* list_create(){
    List *li;
    li = malloc(sizeof(List));

    if(li != NULL)
        li->head = NULL;

    return li;
}


int list_push_front(List *li, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_node *node;
    node = malloc(sizeof(List_node));
    if(node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;
    node->next = li->head;
    li->head = node;

    return SUCCESS;
}



int list_push_back(List *li, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_node *node;
    node = malloc(sizeof(List_node));
    if(node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;
    node->next = NULL;

    if(li->head == NULL)
        li->head = node;
    else{
        List_node *aux;
        aux = li->head;

        while(aux->next != NULL)
            aux = aux->next;

        aux->next = node;
    }

    return SUCCESS;
}


int list_insert(List *li, int pos, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(pos < 1)
        return OUT_OF_RANGE;

    List_node *node;
    node = malloc(sizeof(List_node));
    if(node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;

    if(pos == 1 || li->head == NULL){
        node->next = li->head;
        li->head = node;
    }else{
        List_node *aux;
        aux = li->head;
        int i;
        for(i=2; aux->next != NULL; i++)
            aux = aux->next;

        if(pos>i)
            return OUT_OF_RANGE;
        else{
            aux = li->head;
            for(int k=2; k<pos; k++)
                aux = aux->next;

            node->next = aux->next;
            aux->next = node;
        }
    }

    return SUCCESS;
}


int list_insert_sorted(List *li, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_node *node;
    node = malloc(sizeof(List_node));
    if(node == NULL)
        return OUT_OF_MEMORY;

    node->data = al;

    List_node *aux, *aux2;
    aux = li->head;

    if(li->head == NULL || aux->data.matricula > node->data.matricula){
        node->next = li->head;
        li->head = node;
    }else{
        while(aux != NULL && aux->data.matricula < node->data.matricula){
            aux2 = aux;
            aux = aux->next;
        }

        aux2->next = node;
        node->next = aux;
    }

    return SUCCESS;
}


int list_size(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_node *aux;
    aux = li->head;

    if(li->head == NULL)
        return SUCCESS;

    int i;
    for(i=1; aux->next != NULL; i++)
        aux = aux-> next;

    return i;
}

int list_pop_front(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux;
        aux = li->head;
        li->head = aux->next;
        free(aux);
    }

    return SUCCESS;
}


int list_pop_back(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux, *aux2;
        aux = li->head;

        if(aux->next == NULL)
            li->head = NULL;
        else{
            while(aux->next != NULL){
                aux2 = aux;
                aux = aux->next;
            }

            aux2->next = aux->next;
        }

        free(aux);
    }

    return SUCCESS;
}


int list_erase_data(List *li, int nmat){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux, *aux2;
        aux = li->head;

        if(aux->data.matricula == nmat)
            li->head = aux->next;
        else{
            while(aux != NULL && aux->data.matricula != nmat){
                aux2 = aux;
                aux = aux->next;
            }
            if(aux == NULL)
                return ELEM_NOT_FOUND;
            else
                aux2->next = aux->next;
        }

        free(aux);
    }

    return SUCCESS;
}


int list_erase_pos(List *li, int pos){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;

    if(pos < 1)
        return OUT_OF_RANGE;

    int tam;
    tam = list_size(li);

    if(pos > tam)
        return OUT_OF_RANGE;
    else{
        List_node *aux, *aux2;
        aux = li->head;

        if(pos == 1)
            li->head = aux->next;
        else{
            for(int i=1; i<pos; i++){
                aux2 = aux;
                aux = aux->next;
            }

            aux2->next = aux->next;
        }

        free(aux);
    }

    return SUCCESS;
}


int list_find_pos(List *li, int pos, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;

    if(pos < 1)
        return OUT_OF_RANGE;

    int tam;
    tam = list_size(li);

    if(pos > tam)
        return OUT_OF_RANGE;
    else{
        List_node *aux;
        aux = li->head;

        for(int i=1; i<pos; i++)
            aux = aux->next;

        *al = aux->data;

    }

    return SUCCESS;
}


int list_find_mat(List *li, int nmat, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux;
        aux = li->head;

        while(aux != NULL && aux->data.matricula != nmat)
            aux = aux->next;

        if(aux == NULL)
            return ELEM_NOT_FOUND;
        else
            *al = aux->data;
    }

    return SUCCESS;
}


int list_front(List *li, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else
        *al = li->head->data;

    return SUCCESS;
}


int list_back(List *li, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux;
        aux = li->head;

        while(aux->next != NULL)
            aux = aux->next;

        *al = aux-> data;
    }

    return SUCCESS;
}


// pos = 0 ==> elemento com tal numero de matricula não foi encontrado.
int list_get_pos(List *li, int nmat, int *pos){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        int i;
        List_node *aux;
        aux = li->head;

        for(i=1; aux != NULL && aux->data.matricula != nmat; i++)
            aux = aux->next;

        if(aux == NULL){
            *pos = 0;
            return ELEM_NOT_FOUND;
        }else
            *pos = i;
    }

    return SUCCESS;
}


int list_print(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux;
        aux = li->head;

        while(aux != NULL){
            printf("----------------------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Nota 1: %.2f / Nota 2: %.2f / Nota 3: %.2f\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }

        printf("----------------------------------\n");
    }

    return SUCCESS;
}


int list_free(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->head == NULL)
        return ELEM_NOT_FOUND;
    else{
        List_node *aux, *aux2;
        aux = li->head;

        while(aux != NULL){
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }

        free(li);
    }

    return SUCCESS;
}