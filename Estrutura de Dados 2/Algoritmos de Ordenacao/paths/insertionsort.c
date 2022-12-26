#include "insertionsort.h"
void InsertionSort(int vet[], int tam)
{
	int aux;
	for (int i = 1; i < tam; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (vet[j] < vet[j - 1])
			{
				aux = vet[j - 1];
				vet[j - 1] = vet[j];
				vet[j] = aux;
			}
			else
				break;
		}
	}
}