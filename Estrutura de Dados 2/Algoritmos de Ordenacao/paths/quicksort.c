#include "quicksort.h"

int partition(int v[], int esq, int dir)
{
	int fim = esq,aux;
	for (int i = esq + 1; i <= dir; i++)
	{
		if (v[i] < v[esq])
		{
			fim++;
			aux = v[i];
			v[i] = v[fim];
			v[fim] = aux;
		}
	}
	aux = v[esq];
	v[esq] = v[fim];
	v[fim] = aux;
	return fim;
}

void QuickSort(int vet[], int esq, int dir)
{
	if (esq >= dir)
		return;
	int index = partition(vet, esq, dir);
	QuickSort(vet, esq, index - 1);
	QuickSort(vet, index + 1, dir);
}
