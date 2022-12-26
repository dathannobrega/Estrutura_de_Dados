#include "bubblesort.h"
void BubbleSort(int vet[], int tam)
{ // BUBBLE SORT aqui fazemos o rdenaçao por bubble
	int aux, trocas;
	for (int i = 0; i < tam; i++)
	{
		trocas = 0;
		for (int j = 0; j < tam - i; j++)
		{
			if (vet[j] > vet[j + 1])
			{ // fazemos a comparaçao e depois a troca;
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
				trocas++;
			}
		}
		if (trocas == 0)
			break;
	}
}
