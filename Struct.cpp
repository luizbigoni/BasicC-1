/* Vamos começar a ver váriaveis HETEROGÊNEAS ou seja começar a fazer variaveis capazes de armazenar int , chat , float ( O que eu quiser )
 E nós chamamos isso de STRUCT


 COMO FUNCIONA ?

Nós declaramos partes dos vetores de que tipo tem que ser | int |    CHAR    |     FLOAT       |  Declarar os tamanhos
Ai obrigatóriamente aquela parte tem que ser o que eu marquei ( int , char , float )

NOME STRUCT SEGNIFICA REGISTROS DE DADOS!


Como definir uma struct?

nome do tipo de dado que estou definindo agora
		|
struct TpProduto
{
	tipo variavel(
					int Codigo;
					float preco;
					char descricao;
				)
	... } membros da estrutura
	
};  PRECISA COLOCAR PONTO E VÍRGULA PARA TERMINAR A STRUCT

struct TpProduto TpProdx; -> declaração da variável Codigo do tipo "TpProduto"

Precisa colocar struct em C , mas usaremos sem pq estamos em C++

Vamos para um exemplo:

struct livro
{
int registro;
char titulo[30]
char autor [30]                                COMO EU FARIA PRA ARMARZENAR ALGO ?
};                                                    scanf("%d",&livrox.registro);
struct livro livrox;                                  gets(livrox.titulo);
                                                      gets(livrox.autor);            
o livrox seria a variavel                      Com esse codigo estou tacando as variaveis nos lugares certos de acordo com o seu tipo
						
						
							
																COMO EU EXIBO MINHA STRUCT?
                                                            printf("Nome: %s Reg: %d Titulo: %s",livrox.autos,livrox.registro,livrox.titulo);


struct livro livrox [10];   Se eu colocar o " [10] " na frente acaba virando uma matriz com as colunas com os nomes " registro , titulo e autor " e as linhas normais " 1, 2 ,3 ,4 , ..." 

O scanf ficaria assim
scanf("%d",&livrox[0].registro);

Inicializando uma Estrutura

struct data{
char nome[80];
int mes;
int dia;
int ano;
};
struct data aniversario[]= { "Ana",12,30,73,
							"Carlos,5,13,66,
							"Mara",11,29,70};   COM ISSO EU JÁ COLOCO OS DADOS NOS SEUS DEVIDOS LUGARES
*/
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define tf 20



struct	TpData
{
	int d,m,a;
};




struct TpProduto
{
	int cod,Estoque;
	TpData Valid; // Declarando o TpData Como variavel Valid
	char Descr[tf];  // Descricao
	float Preco;
};

char Menu(void)
{
	printf("\n[A] Cadastrar Produtos");
	printf("\n[B] Relatorio de produtos");
	printf("\n[C] Ordenar Produtor");
	printf("\n[D] Excluir Produtos");
	printf("\n[ESC] Sair");
	printf("\n\nOpcao Desejada: ");
	return toupper(getche());
	
}



int BuscaCodExaust(tpProduto Tab[tf], int tl , int CodProd)
{
	int i=0;
	while(i<tl && CodProd !=Tab[i].)
		i++;
	
	
	if (i<tl)
		return i;
	else
		return -1;
}




void CadProd(TpProduto TABProd[tf], int &tlp)
{
	int AuxCod;
	clrscr(); printf("\n Cadastro de produtos \n");
	printf("Cod do produto: ");scanf("%d",AuxCod);
	while(tlp<tf && AuxCod>0)
	{
		pos = BuscaCodExaust(TABProd,tlp,AuxCod);
		if (pos==-1)
		{
	
			TABProd[tlp].cod = AuxCod;
			printf("\nDescricao: "); fflush(stdin);
			gets(TABProd[tlp].Descr);
			printf("\nQtde em Estoque: ");
			scanf("%d",&TABProd[tlp].Estoque);
			printf("\nPreco: R$");
			scanf("%f",&TABProd[tlp].Preco);
			printf("\nData de Validade[dd mm aaaa]");
			scanf("%d%d%d",&TABProp[tlp].Valid.d,
						   &TABProp[tlp].Valid.m,
						   &TABProp[tlp].Valid.a);
			tlp++;
			printf("\n Cadastro de produtos \n");
			printf("Cod do produto: ");scanf("%d",AuxCod);
		}
		else
		{
			printf("\nProdto Cadastrado!\n");
			printf(" Produto [%d] - Descricao: [%s] \n\n",pos,TABProd[pos].Descr)
		}
	}
}


void OrdenarProduto (tpProduto TAB[TF], int tl)
{
	tpProduto RegAux; // Não Coloca () ou [] por que vai armazenar somente uma linha, nesse caso a linha de descrição
	if(tl == 0)
	{
		printf("\nNao ha dados para ordenar");
	}
	else
	{
	
		for(i=0; i<tl-1;i++)
			for(j=i+1;j<tl;j++)
				if(stricmp(TAB[i].Descr,TAB[j].Descr)>0)
				{
					RegAux = TAB[i];
					TAB[i] = TAB[j];
					TAB[j] = RegAux;
							
				}
			printf("\nProdutor ordenados");
	}
}




void Relatorio(TpProduto TABProd[tf],int tl)
{
	int i;
	for(i=0;i<tl;i++)
	{
		printf("Cod: %d \n Estoque: %d \n Valid: %d/%d/%d \n Descricao: %s \n Preço: %.2f\n",&TABProp[i].Cod
		,&TABProp[i].Estoque,
		&TABProp[i].Valid.d,
		&TABProp[i].Valid.m,
		&TABProp[i].Valid.a
		&TABProp[i].descr,
		&TABProp[i].preco);
	}
}






int main(void)
{
	TpProduto Prod[tf];
	int tam=0;
	char opcao;
	
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A': CadProd(Prod,tam);.
					   break;
			case 'B':Relatorio(Prod,tam);
					 break;
			case 'C': OrdenarProduto(Prod,tam);
						break;
				
			case 'D':
		}
	}
	return 0;
}
