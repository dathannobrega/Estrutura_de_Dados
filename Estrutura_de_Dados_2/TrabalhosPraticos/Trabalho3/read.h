#ifndef READ_H
#define READ_H

#include "arvoreBin.h"
#include "AvlThree.h"
#include "vetorBin.h"
#define MAX 100
#define MAX_LINHA 1000

Arv* readBuscaBinaria(char *file);
AVL* readAVL(char *file);
Vetor* readVetorBin(char *file);

#endif