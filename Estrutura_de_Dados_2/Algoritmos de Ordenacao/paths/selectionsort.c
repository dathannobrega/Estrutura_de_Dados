#include"selectionsort.h"

void SelectionSort(int vet[], int tam)
{
	int aux, menor;
	for (int i = 0; i < tam; i++)
	{
		menor = i;
		for (int j = i; j < tam; j++)
		{
			if (vet[j] < vet[menor])
				menor = j;
		}
		aux = vet[i];
		vet[i] = vet[menor];
		vet[menor] = aux;
	}
}

	