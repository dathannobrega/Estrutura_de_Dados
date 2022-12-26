#include "pancakesort.h"
//a funçao flip inverte os numeros de posiçao ex: 4321 ->  1 2 3 4
void flip(int vet[],int i){
    int temp, start = 0;
    while (start<1){
        temp = vet[start];
        vet[start] = vet[i];
        vet[i] = temp;
        start++;
        i--;
    }
    
}

int findMax(int vet[],int tam){ // procura o maior do vetor
    int mi,i;
    for (mi =0, i=0; i <  tam; i++)
    {
        if(vet[i] > vet[mi])
            mi = i;
    }
    return mi;
    
}

void pancakeSort(int vet[],int tam){
    for (int i = tam; i > 1; i--)
    {
        int mi = findMax(vet,i); // pega o maior valor


        if (mi != i -1){
            flip(vet,mi);
            flip(vet,i - 1);
        }
    }
    
}