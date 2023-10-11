#include <stdio.h>
#define TF 5

//Busca Binaria
int BuscaBinaria(intV[TF],int TL,int TL)
{
	int Inicio = 0, FIM = TL-1,Meio;
	Meio = FIM/2;
	// QUANDO O FIM SER MENOR QUE O INICIO TEM QUE PARAR
	while(FIM > Inicio&& Elem!=V[Meio])
	{
		// If Para tacar o Inicio na frente Ou Fim pra trás do meio para diminiur o tamanho da lista
		if(V[Meio]<Elem) 
			Inicio = Meio+1;
		else
			FIM = Meio-1;
		
	  Meio = (Inicio + FIM)/2;
	}
	if(Elem == V[Meio]);
		return Meio;
	else
		return -1;
}





// INSERÇÃO DIRETA PARA NAO USAR BUSCA
void InsercaoDireta(char TAB[5],int tl)
{	
	int i;
	tl--;
	while(tl>0 && TAB[tl]<TAB[tl-1])
	{
		i = TAB[tl-1];
		TAB[tl-1] = TAB[tl];
		TAB[tl] = i;
		tl--;
	}
}
int main()
{
	int aux,TL=0;
	char V[TF];
	scanf("%d",&aux);
	while(TL<TF&&aux!=0)
	{
		V[TL] = aux;
		TL++;
		InsercaoDireta(V,TL);
		scanf("%d",&aux);
	}
	for(aux=0;aux<TL;aux++)
		printf("%d \n",V[aux]);
}
