#include <stdio.h>
#include "vector.h"

int main(){
    Vector_head *V;
    V = criar();
    for (int i = 0; i < 2; i++)
    {
        push_back(V,i);
    }


    free(V);
    return 0;
}