#include <conio2.h>
#include <stdio.h>
#inclu
de <stdlib.h>

#define tf 100

// Por valor é sem o & e referencia usa o &
void Frequencia (int vetor[tf],int tl,int &valor,int &QtdeVezes)
{
	QtdeVezes =0;
	for(int i=0;i<tl;i++)
	{
		int Qtde = 0;
		for(int j=i;j<tl;j++)
		{
			if(vetor[i]==vetor[j])
			{
				Qtde++;
			}
			
		}
	if (Qtde > QtdeVezes )
	{
		QtdeVezes = Qtde;
		valor = vetor[i];
	}	
}
}
// TODO VETOR É PASSADO POR REFERENCIA , OU SEJA NÃO PRECISA DE & , SE COLOCAR VAI DAR ERROR !!!!
void LeValor (int vet[tf],int &tl)
{
	int aux;
	printf("\nDigite um numeros no vetor: ");
	printf ("Vetor[%d]: ",tl);
	scanf("%d",&aux);
	while(tl<tf && aux > 0)
	{
		vet[tl] = aux;
		tl++;
		printf("\nDigite um numeros no vetor: ");
		printf ("Vetor[%d]: ",tl);
		scanf("%d",&aux);
	}
}
// EXERCICIO PARA PEGAR O NUMERO QUE MAIS SE REPETE USANDO FUNÇÃO E VETORES
int main (void)
{
	int v[tf], tam=0 , NrMais , Qtde;
	LeValor(v,tam);
	Frequencia(v,tam,NrMais,Qtde);
	
	printf("\nNúmero de maior frequencia: %d\nQuantidade de vezes: %d",NrMais,Qtde);
	getch;
	
	
	
	
	
	return 0;
}
