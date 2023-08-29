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
void NumPerfeitos(int num);

/* Converter decimal para binario
int main(void)
{
	int num=levalor();
	num=inttobin(num);
	exibevalor(num);
	
	return 0;
}
*/
/* Converter Binario Para decimal
int main(void){
	int num=levalor();
	num=inttodec(num);
	exibevalor(num);
}
*/
int main(void){
	int num=levalor();
	NumPerfeitos(num);
}

int levalor(void)//quando n é void precisa do return-alguma coisa
{
	int valor;
	//printf("digite o numero inteiro em decimal: ");
	printf("\ndigite o numero inteiro: ");
	scanf("%d", &valor);
	return valor;
	
}

void exibevalor(int n)//quando é void n precisa de return
{
	printf("\nvalor em binario: %d", n);
	getch();
}

//Decimal em binario
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
//Binario em decimal
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

//Numeros perfeitos
void NumPerfeitos(int num)
{
 int soma=0,i,aux = num;
 
 for (i=1;i!=aux/2+1;i++)
 {
    if(num%i==0)
    {
        soma+= i;
    }
    
 }
    if(soma == aux)
    {
        printf("\nO numero é perfeito!");
    }
    else{
        printf("\nO numero é imperfeito");
    }
    
}
