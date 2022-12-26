#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "paths/quicksort.h"
#include "paths/cocktailsort.h"
#include "paths/selectionsort.h"
#include "paths/bubblesort.h"
#include "paths/heapsort.h"
#include "paths/insertionsort.h"
#include "paths/pancakesort.h"

#define MAX 100000

//### funçeos Nao diretamente relacionadas a ordenaçoes
void geranumeros(int tam, int vet1[], int vet2[], int vet3[], int vet4[], int vet5[],int vet6[],int vet7[])
{ // usei só pra criar a lista de in.txt
	int r;
	srand(time(NULL)); // inicializaçao do rand
	for (int i = 0; i < MAX; i++)
	{
		r = rand() % MAX; // gera numeros de 0 a 9999
		vet1[i] = r;
		vet2[i] = r;
		vet3[i] = r;
		vet4[i] = r;
		vet5[i] = r;
		vet6[i] = r;
		vet7[i] = r;
	}

	return;
}


int main()
{
	// fazemos a geraçao do vetor;
	int vet1[MAX], vet2[MAX], vet3[MAX], vet4[MAX], vet5[MAX],vet6[MAX],vet7[MAX];
	geranumeros(MAX, vet1, vet2, vet3, vet4, vet5,vet6,vet7); // gera 7 vetores iguais para comparaçao
	//1###########################

	// Aqui começa os test de ordenaçao;
	clock_t begin = clock(); // Inicia o Relogio, criando uma variavel do tipo clock_t
	CocktailSort(vet1, MAX);

	clock_t end = clock();										// termina a contabilizaçao do tempo
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // cria a variavel e ja imprimimos ela
	printf("CocktailSort = %lfs\n", time_spent);
	//2######################################
	begin = clock(); // Inicia o Relogio

	QuickSort(vet2, 0 ,MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("QuickSort = %lfs\n", time_spent);
	//3######################################
	begin = clock(); // inicia o relogio

	Heap(vet3, MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("HeapSort  = %lfs\n", time_spent);
	//4######################################
	/*begin = clock(); // inicia o relogio

	QuickSort(vet4, 0, MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("QuickSort  = %lfs\n", time_spent);*/
	//5######################################
	begin = clock(); // inicia o relogio

	pancakesort(vet5,MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("PancakeSort  = %lfs\n", time_spent);
	//6############################################
	/*begin = clock(); // inicia o relogio

	bucketsort(vet6,MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("BucketSort  = %lfs\n", time_spent);*/
	//############################################
	//7############################################
	begin = clock(); // inicia o relogio

	BubbleSort(vet7,MAX);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("BubbleSort  = %lfs\n", time_spent);
	//############################################


	for (int i = 0; i < MAX - 1; i++)
		printf("%d ", vet1[i]);

	return 0;
}