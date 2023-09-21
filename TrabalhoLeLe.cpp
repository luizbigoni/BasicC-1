#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>
#define TF 20

struct tpData
{
	int d,m,a;
};

struct tpProduto
{
	int Cod,Estoque;
	tpData Valid;
	char Descr[TF];
	float Preco;
	int CodForn;
};
 
 struct tpFornecedor
 {
 	int Cod;
 	char Nome[TF], Cid[TF];
 };
 
 struct tpCliente
 {
 	int CPF,QtdeCompras;
 	float ValorTotal;
 	char NomeCliente[30];
 };
 
 
void CadastroCliente(tpCliente TabCliente[TF], int &TLC);
void CadastroFornecedor(tpFornecedor TabForne[TF], int &TLF);
void CadastroProd(tpProduto TabProd[TF],int &TLP);
int BuscaCod(tpProduto Tab[TF], int TL, int CodProd);
char MenuPrincipal(void);
char subProdutos(void);
char subGerenciamento(void);
char EscolhaGerenciamento(void);
void Moldura (int ci, int li, int cf, int lf, int cort, int corf);
void formulario(void);
void limparTela(void);

int main(void)
{
	
	
	int TL=0;
	char op, opsub, opEscolha;
	
	formulario();
	
	gotoxy(100,30);
	tpProduto Prod[TF];
	tpFornecedor Fornecedor[TF];
	tpCliente Cliente[TF];
	
	
	do
	{
		
		op = MenuPrincipal();
		switch(op)
		{
			case 'A':	opsub=subProdutos();
						switch(opsub)
						{
							case 'A': //Produtos a venda
										break;
							case 'B': //adicionar item ao carrinho
										break;
							case 'C': //excluir item do carrinho
										break;
							case 'D': //finalizar compra
										break;
						}
						
					  break;
					  
			case 'B':	opsub = subGerenciamento();
						switch(opsub)
						{
							case 'A':	opEscolha = EscolhaGerenciamento(); //cadastro
										switch(opEscolha)
										{
											case 'A':	limparTela();
														CadastroProd(Prod, TL);//Produtos
														break;
											case 'B':   CadastroFornecedor(Fornecedor,TL);//fornecedor
														break;
											case 'C':   CadastroCliente(Cliente,TL);//cliente
														break;
										}
										break;
							case 'B': opEscolha = EscolhaGerenciamento(); //consulta
										switch(opEscolha)
										{
											case 'A': //Produtos
														break;
											case 'B': //fornecedor
														break;
											case 'C': //cliente
														break;
										}
										break;
							case 'C': opEscolha = EscolhaGerenciamento(); //exclusao
										switch(opEscolha)
										{
											case 'A': //Produtos
														break;
											case 'B': //fornecedor
														break;
											case 'C': //cliente
														break;
										}
										break;
							case 'D': opEscolha = EscolhaGerenciamento(); //alteração
										switch(opEscolha)
										{
											case 'A': //Produtos
														break;
											case 'B': //fornecedor
														break;
											case 'C': //cliente
														break;
										}
										break;
						}
					  break;
					  
			case 'C': ;
					  break;
		}
	}while(op!=27);
	
	return 0;
}

void limparTela(void) //função de limpar tela
{
	int i , j;
	
	for(i = 6;i<25;i++)
	{	for(j= 29;j<89;j++)
		{
			gotoxy(j,i);
			printf("%c",0);
		}
	}
}


int BuscaCli(tpCliente Tab[TF], int TL, int CPFCli) //busca Cliente
{
	int a=0;
	while (a<TL && CPFCli!=Tab[a].CPF)
				a++;
	
	if (a<TL)
		return a;
	else
		return -1;
}

void CadastroCliente(tpCliente TabCliente[TF], int &TLC) // cadastro Cliente
{
	int AuxCod,pos;
	
	printf("\n## Cadastro de cliente##\n");
	printf("\nCPF do Cliente: ");
	scanf("%d", &AuxCod);
	while(TLC<TF && AuxCod>0)
	{
		pos = BuscaCli(TabCliente,TLC,AuxCod);
		if(pos==-1)
		{
			TabCliente[TLC].CPF = AuxCod;
			printf("\nNome do Cliente: ");
			fflush(stdin);
			gets(TabCliente[TLC].NomeCliente);
			TLC++;
		}
		else{
		
				printf("\nCliente ja cadastrado!\n");
				printf("Cliente[%d] - Nome: [%s]\n\n",pos,TabCliente[pos].NomeCliente);
			}
		
		if(TLC<TF)
		{
			printf("\nCPF do Cliente: ");
			scanf("%d",&AuxCod);
		}
		else
			{
				printf("\nTabela Cheia!\n");
				getch();
			}
	}
	
}

int BuscaForn(tpFornecedor Tab[TF], int TL, int CodForn) //busca cadastro
{
	int a=0;
	while (a<TL && CodForn!=Tab[a].Cod)
				a++;
	
	if (a<TL)
		return a;
	else
		return -1;
}

void CadastroFornecedor(tpFornecedor TabForne[TF], int &TLF) // cadastro de fornecedor
{
	int AuxCod, pos;
	
	printf("\n## Cadastro de fornecedor##\n");
	printf("\nCodigo do fornecedor: ");
	scanf("%d", &AuxCod);
	while(TLF<TF && AuxCod>0)
	{
		pos = BuscaForn(TabForne,TLF,AuxCod);
		if (pos==-1)
		{
			TabForne[TLF].Cod=AuxCod;
			printf("\nNome do fornecedor: ");
			fflush(stdin);
			gets(TabForne[TLF].Nome);
			printf("\nCidade do fornecedor: ");
			scanf("%d",&TabForne[TLF].Cid);
			TLF++;
		}
		else
			{
				printf("\nFornecedor ja cadastrado!\n");
				printf("Fornecedor[%d] - Nome: [%s]\n\n",pos,TabForne[pos].Nome);
			}
		
		if(TLF<TF)
		{
			printf("\nCodigo do Fornecedor: ");
			scanf("%d",&AuxCod);
		}
		else
			{
				printf("\nTabela Cheia!\n");
				getch();
			}
	}
		
}
	
int BuscaCod(tpProduto Tab[TF], int TL, int CodProd) //busca produt
{
	int a=0;
	while (a<TL && CodProd!=Tab[a].Cod)
				a++;
	
	if (a<TL)
		return a;
	else
		return -1;
}

void CadastroProd(tpProduto TabProd[TF],int &TLP) //cadastro do produto
{
	int AuxCod, pos;
	
	printf("\n** Cadastro de Produtos **\n");
	printf("\nCodigo do Produto: ");
	scanf("%d",&AuxCod);
	while(TLP <TF && AuxCod>0)
	{
		pos = BuscaCod(TabProd, TLP, AuxCod);
		if (pos==-1)
		{
			TabProd[TLP].Cod=AuxCod;
			printf("\nDescricao do Produto: ");
			fflush(stdin);
			gets(TabProd[TLP].Descr);
			printf("\nQuantidade em Estoque: ");
			scanf("%d",&TabProd[TLP].Estoque);
			printf("\nPreco: ");
			scanf("%f",&TabProd[TLP].Preco);
			printf("\nData de Validade[dd mm aa]: ");
			scanf("%d %d %d",&TabProd[TLP].Valid.d,&TabProd[TLP].Valid.m,&TabProd[TLP].Valid.a);
			TLP++;
		}
		else
			{
				printf("\nProduto Cadastrado!\n");
				printf("Produto[%d] - Descricao: [%s]\n\n",pos,TabProd[pos].Descr);
			}
		
		if(TLP<TF)
		{
			printf("\nCodigo do Produto: ");
			scanf("%d",&AuxCod);
		}
		else
			{
				printf("\nTabela Cheia!\n");
				getch();
			}
	}
}
	
char MenuPrincipal(void) //  menu principal
{
	textcolor(15);
	gotoxy(8,9);
	printf("# # M E N U # #");
	gotoxy(3,13);
	printf(" [ A ]-Produtos ");
	gotoxy(3,15);
	printf(" [ B ]-Gerenciamento ");
	gotoxy(3,17);
	printf(" [ C ]-Emitir Relatorio ");
	gotoxy(8,27);
	printf("[ESC]-S A I R");
	gotoxy(40,27);
	return toupper(getche());

}

char subProdutos(void) //sub menu de produtos 
{
	textcolor(15);
	gotoxy(47,9);
	printf("## SUB MENU PRODUTOS ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos a venda");
	gotoxy(35,14);
	printf(" [ B ]-Adicionar item ao carrinho");
	gotoxy(35,16);
	printf(" [ C ]-Excluir item do carrinho");
	gotoxy(35,18);
	printf(" [ D ]-Finalizar compra");
	gotoxy(36,22);
	printf("[ F2 ]-VOLTAR");
	gotoxy(40,27);
	return toupper(getche());
}

char subGerenciamento(void) //sub menu de gerenciamento
{
	textcolor(15);
	gotoxy(45,9);
	printf("## SUB MENU GERENCIAMENTO ##");
	gotoxy(35,12);
	printf(" [ A ]-Cadastro de item");
	gotoxy(35,14);
	printf(" [ B ]-Consulta de itens");
	gotoxy(35,16);
	printf(" [ C ]-Exclusao de item");
	gotoxy(35,18);
	printf(" [ D ]-Alteracao de itens");
	gotoxy(36,22);
	printf("[ F2 ]-VOLTAR");
	gotoxy(40,27);
	return toupper(getche());
}

char EscolhaGerenciamento(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("QUAL DESEJA CADASTRAR?");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(35,18);
	printf("[ F2 ]-VOLTAR");
	gotoxy(40,27);
	return toupper(getche());
}

void Moldura (int ci, int li, int cf, int lf, int cort) //moldura
{ 
	
	textcolor(cort);
	
	
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
int i;
	for(i=ci+1;i<cf;i++){
		gotoxy(i,li);
		printf("%c",205);
		gotoxy(i,lf);
		printf("%c",205);
	}
	
	for(i=li+1;i<lf;i++){
		gotoxy(ci,i);
		printf("%c",186);
		gotoxy(cf,i);
		printf("%c",186);		
	}
	
	textcolor(7);
	textbackground(0);	
}

void formulario(void) // formula
{
	
	system("cls");
	Moldura(1,2,90,29,7); // BORDA
		gotoxy(30,4);
		textcolor(7);
		printf("# # # MERCEARIA DO SR.ZE # # #");
	Moldura(2,3,89,5,7); // Titulo
	Moldura(2,6,28,28,7);  // Menu Principal
	Moldura(29,26,89,28,7); // Mensagem
		gotoxy(30,27);
		textcolor(6);
		printf("Mensagem: ");
	Moldura(29,6,89,25,7); // Sub Menu
}

