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
 	char Nome[TF];
 };
 

 struct tpVendas
 {
 	int CodVenda,CPF;
 	float TotVenda;
 	tpData Data;
 };
 
 struct tpVendasProd
 {
 	int CodVenda,CodProd,Qtde;
 	float ValorUnitario;
 };
 
void RealizarVendas(tpVendas TabVendas[1000], int &TLV, tpCliente TabCli[TF],int TLC, tpProduto TabProd[TF],int TLP, tpVendasProd TabVendasProd[1000],int &TLVP);
void ConsultaCliente(tpCliente tab[TF], int TLC);
void ConsultaForncedor(tpFornecedor tab[TF], int TLF);
void ConsultaProd(tpProduto tab[TF], int TLP);
void ConsultaCliente(tpCliente tab[TF], int TLC);
void CadastroCliente(tpCliente TabCliente[TF], int &TLC);
void CadastroFornecedor(tpFornecedor TabForne[TF], int &TLF);
void CadastroProd(tpProduto TabProd[TF],int &TLP,tpFornecedor TabForn[TF],int TLF);
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
	
	
	int TLF,TLC,TLP,TLVP,TLV;
	char op, opsub, opEscolha;
	TLF=TLC=TLP=TLVP=TLV=0;
	formulario();
	
	gotoxy(100,30);
	tpProduto Prod[TF];
	tpFornecedor Fornecedor[TF];
	tpCliente Cliente[TF];
	tpVendas Vendas[1000];
	tpVendasProd VendasProd[1000];
	
	
	do
	{
		
		op = MenuPrincipal();
		switch(op)
		{
			case 'A':	opsub=subProdutos();
						switch(opsub)
						{
							case 'A': limparTela(); //Produtos a venda
								 	  RealizarVendas(Vendas,TLV,Cliente,TLC,Prod,TLP,VendasProd,TLVP);
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
							case 'A':	limparTela();
										opEscolha = EscolhaGerenciamento(); //CADASTRO
										switch(opEscolha)
										{
											case 'A':	limparTela();
														CadastroProd(Prod,TLP,Fornecedor,TLF);//Produtos
														break;
														
											case 'B':   limparTela();
														CadastroFornecedor(Fornecedor,TLF);//fornecedor
														break;
														
											case 'C':   limparTela();
														CadastroCliente(Cliente,TLC);//cliente
														break;
										}
										break;
										
							case 'B': 	limparTela();
										opEscolha = EscolhaGerenciamento(); //CONSULTA
										switch(opEscolha)
										{
											case 'A':	limparTela();
														ConsultaProd(Prod, TLP);//Produtos
														break;
														
											case 'B':	limparTela();
														ConsultaForncedor(Fornecedor,TLF);//fornecedor
														break;
														
											case 'C':	limparTela();
														ConsultaCliente(Cliente,TLC);//cliente
														break;
										}
										break;
							case 'C': opEscolha = EscolhaGerenciamento(); //EXCLUSAO
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
	
	for(i = 7;i<23;i++)
	{	for(j= 29;j<79;j++)
		{
			gotoxy(j,i);
			printf(" ");
		}
	}
}



void ConsultaCliente(tpCliente tab[TF], int TLC) //consulta liente
{
	int x=0, aux=0, i, j;
	
	
	gotoxy(40 ,9);
	printf("## Consulta de clientes ##");
	while(x<TLC && TLC>0)
	{		
		
		if(aux==39)
		{
			//limpar a tela para continuar a consulta
			for(i = 10;i<23;i++)
			{	
				for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
		}
		gotoxy(71,11);
		printf("pag: %d", x+1);
		gotoxy(34, 12);
		printf("CPF: %d",tab[x].CPF);
		gotoxy(34, 13);
		printf("Nome: %s", tab[x].Nome);
		gotoxy(34, 14);
		printf("Qtde De Compras: %s", tab[x].QtdeCompras);
		gotoxy(34,15);
		printf("ValorTotal: %.2f",tab[x].ValorTotal);
	x++;
	gotoxy(40, 20);
	printf("[-->]-proximo produto.");
	scanf("%d", &aux);			
	}
	if(TLC<0)
	{
			 gotoxy(35, 12);
		 	printf("Nao ha clientes a serem consultados!");
	}
}
	
void ConsultaForncedor(tpFornecedor tab[TF], int TLF) //consulta fornecedor
{
	int x=0, aux=0, i, j;
	
	
	gotoxy(40 ,9);
	printf("## Consulta de Fornecedores ##");
	while(x<TLF && TLF>0)
	{		
		
		if(aux==39)
		{
			//limpar a tela para continuar a consulta
			for(i = 10;i<23;i++)
			{	
				for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
		}
		gotoxy(71,11);
		printf("pag: %d", x+1);
		gotoxy(34, 12);
		printf("Codigo fornecedor: %d", tab[x].Cod);
		gotoxy(34, 13);
		printf("Nome: %s", tab[x].Nome);
		gotoxy(34, 14);
		printf("Cidade: %s", tab[x].Cid);
		x++;
		gotoxy(40, 20);
		printf("[-->]-proximo produto.");
		scanf("%d", &aux);			
	}
	if(TLF<0)
	{
		gotoxy(35, 12);
		printf("Nao ha fornecedores a serem consultados!");
	}
}

void ConsultaProd(tpProduto tab[TF], int TLP) //consulta produtos
{
	int x=0, aux=0, i, j;
	
	
	gotoxy(40 ,9);
	printf("## Consulta de produtos ##");
	while(x<TLP && TLP>0)
	{		
		
		if(aux==39)
		{
			//limpar a tela para continuar a consulta
			for(i = 10;i<23;i++)
			{	
				for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
			
		}
		gotoxy(71,11);
		printf("pag: %d", x+1);
		gotoxy(34, 12);
		printf("Codigo produto: %d", tab[x].Cod);
		gotoxy(34, 13);
		printf("Descricao: %s", tab[x].Descr);
		gotoxy(34, 14);
		printf("Quantidade em estoque: %d", tab[x].Estoque);
		gotoxy(34, 15);
		printf("Preco: %.2f", tab[x].Preco);
		gotoxy(34, 16);
		printf("Data de validade:%d/%d/%d", tab[x].Valid.d, tab[x].Valid.m, tab[x].Valid.a);
		x++;
	gotoxy(40, 20);
	printf("[-->]-proximo produto.");
	scanf("%d", &aux);			
	}
	if(TLP<0)
	{
		gotoxy(35, 12);
		printf("Nao ha produtos a serem consultados!");
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
	int AuxCod,pos, i, j;
	
	gotoxy(40 ,9);
	printf("## Cadastro de cliente##");
	gotoxy(34, 12);
	printf("CPF do Cliente: ");
	scanf("%d", &AuxCod);
	while(TLC<TF && AuxCod>0)
	{
		pos = BuscaCli(TabCliente,TLC,AuxCod);
		if(pos==-1)
		{
			TabCliente[TLC].CPF = AuxCod;
			gotoxy(34, 14);
			printf("Nome do Cliente: ");
			fflush(stdin);
			gets(TabCliente[TLC].Nome);
			TLC++;
			//limpar a tela para continuar cadastrando
			for(i = 10;i<23;i++)
			{	for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
		}
		else{
				gotoxy(34, 13);
				printf("Cliente ja cadastrado!");
				
			}
		
		if(TLC<TF)
		{
			gotoxy(34, 12);
			printf("CPF do Cliente: ");
			scanf("%d",&AuxCod);
		}
		else
			{   
				gotoxy(34, 12);
				printf("Tabela Cheia!");
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

/*int BuscaVendasProd(tpVendasProd Tab[TF], int TLVP ,int CodVenda) //Busca VendasProd Para exclusão
{
	int a=0;
	while (a<TLVP && CodVenda != Tab[a].CodVenda)
				a++;
	
	if (a<TLVP)
		return a;
	else
		return -1;
}*/

void CadastroFornecedor(tpFornecedor TabForne[TF], int &TLF) // cadastro de fornecedor
{
	int AuxCod, pos, i, j;
	
	gotoxy(40 ,9);
	printf("## Cadastro de fornecedor ##");
	gotoxy(34, 12);
	printf("Codigo do fornecedor: ");
	scanf("%d", &AuxCod);
	while(TLF<TF && AuxCod>0)
	{
		pos = BuscaForn(TabForne,TLF,AuxCod);
		if (pos==-1)
		{
			TabForne[TLF].Cod=AuxCod;
			gotoxy(34,14);
			printf("Nome do fornecedor: ");
			fflush(stdin);
			gets(TabForne[TLF].Nome);
			gotoxy(34,16);
			printf("Cidade do fornecedor: ");
			fflush(stdin);
			gets(TabForne[TLF].Cid);
			TLF++;
			//limpar a tela para continuar cadastrando
			for(i = 10;i<23;i++)
			{	for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
		}
		else
			{
				gotoxy(34, 13);
				printf("Fornecedor ja cadastrado!");
			}
		
		if(TLF<TF)
		{
			gotoxy(34, 12);
			printf("Codigo do Fornecedor: ");
			scanf("%d",&AuxCod);
		}
		else
			{
				gotoxy(34, 12);
				printf("Tabela Cheia!");
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

void CadastroProd(tpProduto TabProd[TF],int &TLP,tpFornecedor TabForn[TF],int TLF) //cadastro do produto
{
	int AuxCod, pos, i, j,CodForn,posF;
	
	gotoxy(40 ,9);
	printf("## Cadastro de Produtos ##");
	gotoxy(34, 12);
	printf("Codigo do Produto: ");
	scanf("%d",&AuxCod);
	while(TLP <TF && AuxCod>0)
	{
		pos = BuscaCod(TabProd, TLP, AuxCod);
		if (pos==-1)
		{
			TabProd[TLP].Cod=AuxCod;
			gotoxy(34,14);
			printf("Descricao do Produto: ");
			fflush(stdin);
			gets(TabProd[TLP].Descr);
			gotoxy(34,16);
			printf("Quantidade em Estoque: ");
			scanf("%d",&TabProd[TLP].Estoque);
			gotoxy(34, 18);
			printf("Preco: ");
			scanf("%f",&TabProd[TLP].Preco);
			gotoxy(34,20);
			printf("Data de Validade[dd mm aa]: ");
			scanf("%d ",&TabProd[TLP].Valid.d);
			scanf("%d ",&TabProd[TLP].Valid.m);
			scanf("%d",&TabProd[TLP].Valid.a);
			gotoxy(34,21);
			printf("Cod Do fornecedor: ");
			scanf("%d",&CodForn);
			posF = BuscaForn(TabForn,TLF,CodForn);
			if(posF<TLF)//Achou
	            {
	               TabProd[TLP].CodForn = TabForn[posF].Cod;
	               	TLP++;
               }
            else
            {
            	//limpar a tela para continuar cadastrando
				for(i = 10;i<23;i++)
				{	for(j = 29;j<79;j++)
					{
						gotoxy(j,i);
						printf(" ");
					}
				}
				gotoxy(34, 13);
            	printf("Produto não Cadastrado pois não ha um FORNECEDOR");
            	getch();
			}
			//limpar a tela para continuar cadastrando
			for(i = 10;i<23;i++)
			{	for(j = 29;j<79;j++)
				{
					gotoxy(j,i);
					printf(" ");
				}
			}
		}
		else
			{
				gotoxy(34, 13);
				printf("Produto ja cadastrado!");
			}
		
		if(TLP<TF)
		{
			gotoxy(34, 12);
			printf("Codigo do Produto: ");
			scanf("%d",&AuxCod);
		}
		else
			{
				gotoxy(34, 12);
				printf("Tabela Cheia!");
				getch();
			}
	}
}





void RealizarVendas(tpVendas TabVendas[1000], int &TLV, tpCliente TabCli[TF],int TLC, tpProduto TabProd[TF],int TLP, tpVendasProd TabVendasProd[1000],int &TLVP) //vendas
{
 	
	 
	int i=0, x=12,j;
	char op,OP;
	gotoxy(40 ,9);
	//printf("## Produtos a venda ##");
	/*while(i<TLP)
	{
		if(x<16)
		{
			gotoxy(34,x);
			printf("Codigo: %d Descr: %s Preco: %.2f ", TabProd[i].Cod, TabProd[i].Descr, TabProd[i]. Preco);
			
			if(i+1<TLP && x<16)
			{
				i++;
				x++;
				printf("Codigo:%d Descr:%s Preco:%.2f", TabProd[i].Cod, TabProd[i].Descr, TabProd[i]. Preco);
			}
			i++;
			x++;	
		}
	}*/
	
	gotoxy(40 ,12);
	printf("Deseja Efetuar a compra? S/N: ");
	//toupper(getch(op));
	scanf("%c",&op);
	toupper(op);
	if(op == 'S')
	{
		int AuxCPF,AuxCodProd,pos,posP,Qtde,CodVenda,CodProd,ValorTotal = 0;
		limparTela();
		
		
		
		CodVenda=TLV+1;
		gotoxy(34, 12);
		printf("Digite o seu CPF: ");
		scanf("%d",&AuxCPF);
		pos = BuscaCli(TabCli,TLC,AuxCPF);
		if(pos<TLC)//achou
		{
			while(TLP !=0 && CodProd!=0)
			{
				if(TLP>0)
				{
				   gotoxy(34,13);
				   printf("Qual produto deseja comprar(CodProd): ");
				   scanf("%d",&AuxCodProd);
				   posP=BuscaCod(TabProd,TLP,AuxCodProd);
				   if(posP<TLP) //achou
				   {
					   	gotoxy(34,14);
					   	printf("Quantos deseja comprar: ");
					   	scanf("%d",&Qtde);
					   	if(Qtde < TabProd[posP].Estoque) // Menor que o estoque
	                        {
							 	TabVendas[TLV].CodVenda = TabVendas[TLV - 1].CodVenda + 1;
				   		        TabVendas[TLV].CPF = AuxCPF;
				   		        gotoxy(34,15);
				   		        printf("Digite a data do dia da compra");
				   		        scanf("%d %d %d",&TabVendas[TLV].Data.d,&TabVendas[TLV].Data.m,&TabVendas[TLV].Data.a);
					   			TabVendasProd[TLVP].CodProd = AuxCodProd;
					   			TabVendasProd[TLVP].CodVenda = TabVendas[TLV-1].CodVenda + 1;
					   			TabVendasProd[TLVP].Qtde = Qtde;
					   			TabVendasProd[TLVP].ValorUnitario = TabProd[posP].Preco;
					   			ValorTotal = TabVendasProd[TLVP].Qtde * TabVendasProd[TLVP].ValorUnitario;
						        TLVP++;
					   			TabCli[pos].QtdeCompras++;
					   			gotoxy(34,16);
					   			printf("Deseja Realizar mais compras?");
					   			scanf("%c",&op);
					   			toupper(op);
					   			if(op=='S')
					   			  {
					   			   		   while(op == 'S')
								   			{
									   				for(i = 10;i<23;i++)
														for(j = 29;j<79;j++)
															{
																gotoxy(j,i);
																printf(" ");
															}
												  	if(TLP>0)
														{
														   gotoxy(34,13);
														   printf("Qual produto deseja comprar(CodProd): ");
														   scanf("%d",&AuxCodProd);
														   posP=BuscaCod(TabProd,TLP,AuxCodProd);
															   if(posP<TLP) //achou
															   {
																   	gotoxy(34,14);
																   	printf("Quantos deseja comprar: ");
																   	scanf("%d",&Qtde);
																   	if(Qtde < TabProd[posP].Estoque) // Menor que o estoque
												                        {
																		 	TabVendas[TLV].CodVenda = TabVendas[TLV - 1].CodVenda;
															   		        TabVendas[TLV].CPF = AuxCPF;
															   		        gotoxy(34,15);
															   		        printf("Digite a data do dia da compra");
															   		        scanf("%d %d %d",&TabVendas[TLV].Data.d,&TabVendas[TLV].Data.m,&TabVendas[TLV].Data.a);
																   			TabVendasProd[TLVP].CodProd = AuxCodProd;
																   			TabVendasProd[TLVP].CodVenda = TabVendas[TLV-1].CodVenda;
																   			TabVendasProd[TLVP].Qtde = Qtde;
																   			TabVendasProd[TLVP].ValorUnitario = TabProd[posP].Preco;
																   			ValorTotal = TabVendasProd[TLVP].Qtde * TabVendasProd[TLVP].ValorUnitario;
																		        TLVP++;
																	   			TabCli[pos].QtdeCompras++;
																   			gotoxy(34,16);
																   			printf("Deseja Realizar mais compras?");
																   			scanf("%c",&OP);
																   			toupper(OP);
																   			if(op == ' N ')
																   				  {
																   				  	   	 {
																	   			            		for(i = 10;i<23;i++)
																										for(j = 29;j<79;j++)
																											{
																												gotoxy(j,i);
																												printf(" ");
																											}
																									gotoxy(34,12);
																									printf("Compra efetuada com sucesso");
																						   			TabVendas[TLV].TotVenda = ValorTotal;
																						   			TLV++;
																						   			TabCli[pos].ValorTotal += ValorTotal;
																									ValorTotal = 0;
						  					                                             }
																   				  }
																   		}
																   		else
															            {
																		   	for(i = 10;i<23;i++)
																				for(j = 29;j<79;j++)
																				{
																					gotoxy(j,i);
																					printf(" ");
																				}
																          gotoxy(34, 13);
														  				  printf("Quantidade maior que estoque");
														  				  gotoxy(34,15);
														  				  printf("Estoque: %d",TabProd[posP].Estoque);
														     			  getch();
															            }
																   		
															   }
															   else
															   {
																   	for(i = 10;i<23;i++)
																		for(j = 29;j<79;j++)
																		{
																			gotoxy(j,i);
																			printf(" ");
																		}
														          gotoxy(34, 13);
												  				  printf("Produto não encontrado");
												     			  getch();
															   }
												   	   
												   		    
													   }
													   else
														  {
															   	for(i = 10;i<23;i++)
																	for(j = 29;j<79;j++)
																	{
																		gotoxy(j,i);
																		printf(" ");
																	}
								                              gotoxy(34, 13);
												  			  printf("Sem Produtos para vender");
												     		  getch();
														  }
											  }						
			   			            }
			   			            else
			   			            {
			   			            		for(i = 10;i<23;i++)
												for(j = 29;j<79;j++)
													{
														gotoxy(j,i);
														printf(" ");
													}
											gotoxy(34,12);
											printf("Compra efetuada com sucesso");
											TabVendas[TLV].TotVenda = ValorTotal;
					   			            TLV++;
				   			            	TabCli[pos].ValorTotal += ValorTotal;
											ValorTotal = 0;
			   			            }
					   		}
					   		else
				            {
							   	for(i = 10;i<23;i++)
									for(j = 29;j<79;j++)
									{
										gotoxy(j,i);
										printf(" ");
									}
					          gotoxy(34, 13);
			  				  printf("Quantidade maior que estoque");
			  				  gotoxy(34,15);
			  				  printf("Estoque: %d",TabProd[posP].Estoque);
			     			  getch();
				            }
					   		
				   }
				   else
				   {
					   	for(i = 10;i<23;i++)
							for(j = 29;j<79;j++)
							{
								gotoxy(j,i);
								printf(" ");
							}
			          gotoxy(34, 13);
	  				  printf("Produto não encontrado");
	     			  getch();
				   }
	   		    }
	   		    else
				   {
					   	for(i = 10;i<23;i++)
							for(j = 29;j<79;j++)
							{
								gotoxy(j,i);
								printf(" ");
							}
			          gotoxy(34, 13);
	  				  printf("Sem Produtos para vender");
	     			  getch();
				   }
	        }
		}
		 else
			   {
				   	for(i = 10;i<23;i++)
						for(j = 29;j<79;j++)
						{
							gotoxy(j,i);
							printf(" ");
						}
	              gotoxy(34, 12);
	  			  printf("Cliente não encontrado");
	     		  getch();
			   }
   }
}

void ExclusaoVendas(tpVendas Vendas[TF],int TLV,tpCliente Cli[TF],int TLC,tpVendasProd VendasProd[TF],int TLVP)
{
	
}

char MenuPrincipal(void) //  menu principal
{
	textcolor(15);
	gotoxy(8,10);
	printf("# # M E N U # #");
	gotoxy(3,14);
	printf(" [ A ]-Produtos ");
	gotoxy(3,16);
	printf(" [ B ]-Gerenciamento ");
	gotoxy(3,18);
	printf(" [ C ]-Emitir Relatorio ");
	gotoxy(8,24);
	printf(" [ESC]-S A I R");
	gotoxy(40,25);
	return toupper(getche());

}

char subProdutos(void) //sub menu de produtos 
{
	textcolor(15);
	gotoxy(47,9);
	printf("## SUB MENU PRODUTOS ##");
	gotoxy(35,12);
	printf(" [ A ]-Comprar produto");
	gotoxy(35,14);
	printf(" [ B ]-Excluir vendas");
	//gotoxy(35,16);
	//printf(" [ C ]-Excluir item do carrinho");
	//gotoxy(35,18);
	//printf(" [ D ]-Finalizar compra");
	gotoxy(36,22);
	printf("[ CRTL ]-VOLTAR");
	gotoxy(40,25);
	return toupper(getche());
}
//void ExclusãoProd(tpProduto)

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
	gotoxy(40,25);
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
	gotoxy(40,25);
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
	Moldura(1,2,80,27,7); // BORDA
		gotoxy(27,4);
		textcolor(7);
		printf("# # # MERCEARIA DO SR.ZE # # #");
	Moldura(2,3,79,5,7); // Titulo
	Moldura(2,6,27,26,7);  // Menu Principal
	Moldura(28,24,79,26,7); // Mensagem
		gotoxy(30,25);
		textcolor(6);
		printf("Mensagem: ");
	Moldura(28,6,79,23,7); // sub menu
	
	
}
