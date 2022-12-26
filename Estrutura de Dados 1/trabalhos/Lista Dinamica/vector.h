//AQUI COMEÇA A NOSSA VECTOR
#ifndef VECTOR_INCLUDE
#define VECTOR_INCLUDE

#include<stdlib.h>
#include<stdbool.h>

struct vector{
    int data;
    int tam;
    struct vector *next;
};

typedef struct vector Vector;

typedef struct vector_head{
    Vector *Head;
}Vector_head;




//Retorna um poteiro do Vector
Vector_head* criar ();

//Armazena um int no final do Vetor
void push_back(Vector_head *V,int X);

//Armazena um int no final do Vetor
//int pop_back(Vector *V);

#endif