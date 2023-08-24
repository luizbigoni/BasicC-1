#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

// A FUNÇÃO SEMPRE TEM QUE ESTAR EM CIMA DO MAIN



/* SE POR ACASO EU QUISER COLOCAR AS FUNÇÕES DEPOIS DO MAIN EU TENHO QUE DECLARAR UM PROTÓTIPO

int IntToBin (int Decimal);   ESSE SERIA O PROTÓTIPO PARA O MAIN CONSEGUIR REALIZAR AS FUNÇÕES  */


//Função que não recebe parametro mas retorna sempre um valor int ( ELE LE UM NÚMERO INTEIRO ) SÓ
int LeValor(void)
{
	int Valor;
	printf("\n Digite o valor: ");
	scanf("%d",&Valor);
	return Valor;
}

// TODA VEZ QUE PRECISAR EXIBIR UM VALOR INTEIRO , CHAMA A FUNÇÃO
void ExibeValor (int N)
{
	printf("\n Valor em Binario: %d",N);
	getch();
}

// TRANSFORMAR DECIMAL PARA BINARIO ATRAVÉZ DA FUNÇÃO / PARAMETRO
int IntToBin(int decimal)
{
	int bin=0,i=1,soma;       // variavel local , só vai existir dentro da função
	
	// CONVERTER INT PARA BINÁRIO
	while(decimal!=0)
	{
		
		soma = decimal % 2;
		decimal = decimal / 2;
		bin += soma * i;
		i = i * 10;
		
		
	}
	
	return bin;            // Quando executa o return a função acaba
}




int main (void)
{
	int Numero = LeValor();
	Numero =IntToBin(Numero);   //IntToBin(Numero) Vai pegar a variavel numero e criar uma copia na Variavel Decimal da função
									
	ExibeValor(Numero);					
	
	return 0;
}
