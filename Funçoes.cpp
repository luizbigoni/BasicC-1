#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
//uma função que que usa outra função precisas enxergar ela...
//declaraçoão de funções
int inttobin(int decimal);//tenho que declarar esse int se ele estiver antes do int main, para o programa saber que ele esta em algum lugar. para isso usa o ";"
int levalor(void);
void exibevalor(int n);
int inttodec(int bin);

/* Converter decimal para binario
int main(void)
{
	int num=levalor();
	num=inttobin(num);
	exibevalor(num);
	
	return 0;
}
*/

int main(void){
	int num=levalor();
	num=inttodec(num);
	exibevalor(num);
}

int levalor(void)//quando n é void precisa do return-alguma coisa
{
	int valor;
	//printf("digite o numero inteiro em decimal: ");
	printf("digite o numero inteiro em binario: ");
	scanf("%d", &valor);
	return valor;
	
}

void exibevalor(int n)//quando é void n precisa de return
{
	printf("\nvalor em binario: %d", n);
	getch();
}


int inttobin(int decimal)
{
	int binario=0, soma;
	for(int i=1; decimal!=0; i=i*10)
	{
		soma=decimal%2;
		binario+=soma*i;
		decimal=decimal/2;
	}	
	return binario;
}
int inttodec (int bin)
{
	int dec=0, resto,soma;
	for(int cont=0; bin>=1; cont++)
	{
		resto=bin%10;
		bin = bin/10;
		dec+=resto*pow(2,cont);
	
	}	
	
	
	return dec;
}
