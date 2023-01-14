#include"cocktailsort.h"

void CocktailSort(int vet[],int tam){ // é um Buuble sort pra frente e pra tras
	int trocas=0,inicio = 0,fim = tam -1,aux;
	do
	{
		trocas = 0;
		for (int i = inicio ; i < fim;i++ )
		{
			if(vet[i] > vet[i+1]){
				aux = vet[i];
			    vet[i] = vet[i+1];
			    vet[i+1] = aux;
				trocas++;
			}
		}
		fim--;

		for (int i = fim; i >= inicio+1; i--)
		{
			if (vet[i]< vet[i-1])
			{
				aux = vet[i];
			    vet[i] = vet[i-1];
			    vet[i-1] = aux;
				trocas++;
			}
			
		}
		inicio++;
		
		

	} while (trocas != 0);
	
}
//###############################