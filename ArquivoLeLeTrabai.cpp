#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include<string.h>

#define TF 40
struct tpDataP
{
	int d,m,a;
};
struct tpDataV
{
	int d,m,a;
};


struct tpProduto
{
	
	int Cod,Estoque;
	tpDataP Valid;
	char Descr[TF],status;
	float Preco;
	int CodForn;
};

struct tpFornecedor
 {
 	int Cod;
 	char Nome[TF], Cid[TF],status;
 };

 struct tpCliente
 {
 	int QtdeCompras;
 	float ValorTotal;
 	char Nome[TF],status, CPF[TF];;
 };
 

 struct tpVendas
 {
 	int CodVenda;
 	float TotVenda;
 	tpDataV Data;
 	char status,CPF[TF];
 };
 
 struct tpVendasProd
 {
 	int CodVenda,CodProd,Qtde;
 	float ValorUnitario;
	char status;
 };
 
 
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

int BuscaProduto(FILE * Ptr, int cod)
{
	tpProduto R;
	rewind(Ptr);  
	
	fread(&R,sizeof(tpProduto),1,Ptr);
	//while (!feof(Ptr) &&  (cod!=R.Cod || R.status!='A'))
	while (!feof(Ptr) &&  !(cod==R.Cod && R.status=='A'))
		fread(&R,sizeof(tpProduto),1,Ptr);
		
	if (!feof(Ptr))
		return ftell(Ptr)-sizeof(tpProduto);
	else
		return -1;
}


int validacaoData(int dia,int mes,int ano) //validação de data OK
{
 if(dia>0 && dia<=30 && mes>0 && mes<=12 && ano<=2023)
	return 1;
else
	return -1; 
}

int BuscaFornecedor(FILE * Ptr, int cod)
{
	tpFornecedor R;
	rewind(Ptr);  
	
	fread(&R,sizeof(tpFornecedor),1,Ptr);
	//while (!feof(Ptr) &&  (cod!=R.Cod || R.status!='A'))
	while (!feof(Ptr) &&  !(cod==R.Cod && R.status=='A'))
		fread(&R,sizeof(tpFornecedor),1,Ptr);
		
	if (!feof(Ptr))
		return ftell(Ptr)-sizeof(tpFornecedor);
	else
		return -1;
}

int BuscaCliente(FILE *Ptr, char cod[TF])
{
	tpCliente R;
	rewind(Ptr);  
	
	fread(&R,sizeof(tpCliente),1,Ptr);
	while (!feof(Ptr) &&  (strcmp(cod,R.CPF)!=0 || R.status!='A'))
		fread(&R,sizeof(tpCliente),1,Ptr);
		
	if (!feof(Ptr))
		return ftell(Ptr)-sizeof(tpCliente);
	else
		return -1;
}



int verificarCPF(char cpf2[12])
{
    int mult, soma, i, resto, cpf[11];
    
    for(i=0;i<=11;i++){
        cpf[i] = cpf2[i] - '0';
    }

    soma=0;
    for(i=0, mult=10; i<9 ; i++, mult--)
        soma = soma + (cpf[i]*mult);

    resto = soma%11;

    if((11-resto) == cpf[9] || ((11-resto) == 10 || 11) == (cpf[9]==0))
    {
        soma=0;
        for(i=0, mult=11; i<10 ; i++, mult--)
            soma = soma + (cpf[i]*mult);

        resto = soma%11;

        if((11-resto) == cpf[10] || ((11-resto) == 10 || 11) == (cpf[10]==0))
            return 1; // CPF CORRETO
        else
            return 0; //CPF INCORRETO
    }
    else
    	return 0;
}
     








void CadastroProduto(void) //cadastro produto OK
{
	tpProduto Prod;
	int auxCod, x, auxCodF, y, i, j, auxDia, auxMes, auxAno, z;
	FILE *PtrProd = fopen("Produto.dat","ab+");
	FILE *PtrForn = fopen("Fornecedor.dat", "rb");
	gotoxy(39 ,9);
	printf("## Cadastro de Produtos ##");
	gotoxy(60,11);
	printf("Sair: '0'");
	gotoxy(34, 12);
	printf("Codigo: "); 
	scanf("%d",&auxCod);
	while (auxCod>0)
	{	
		//x = -1; 
		x=BuscaProduto(PtrProd, auxCod);
		if(x == -1)
		{
			gotoxy(34,13);
			printf("Codigo fornecedor: ");
			scanf("%d", &auxCodF);
			
			
			y=BuscaFornecedor(PtrForn,auxCodF);
			if(y != -1)
				{
					Prod.CodForn=auxCodF;	
					Prod.Cod=auxCod;
					gotoxy(34,14);
					printf("Descricao: "); 
					fflush(stdin);
					gets(Prod.Descr);
					gotoxy(34,15);
					printf("Estoque: ");
					scanf("%d",&Prod.Estoque);
					gotoxy(34,16);
					printf("Preco: ");
					scanf("%f",&Prod.Preco);
					gotoxy(34,17);
					printf("Data de validade: ");
					scanf("%d/%d/%d", &auxDia,&auxMes,&auxAno );
					z=validacaoData(auxDia, auxMes, auxAno);
					if(z==1)
					{
						Prod.Valid.d=auxDia;
						Prod.Valid.m=auxMes;
						Prod.Valid.a=auxAno;
						fclose(PtrForn);
						Prod.status='A';
						fwrite(&Prod,sizeof(tpProduto),1,PtrProd);
						gotoxy(34,19);
						printf("Produto cadastrado!");
						getch();
					}
					else
					{
						gotoxy(34,19);
						printf("Data invalida! Produto nao cadastrado.");
						getch();
					}
						
					
				}
			else
			{
				gotoxy(34,14);
				printf("Fornecedor inexistente! ");
				getch();
			}
				
		}
		else
		{
			gotoxy(34, 12);
			printf("Produto ja cadastrado!");
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
		gotoxy(60,11);
		printf("Sair: '0'");
		gotoxy(34, 12);
		printf("Codigo: "); 
		scanf("%d",&auxCod);
	}	
	fclose(PtrProd);
	fclose(PtrForn);
	
	
}

void CadastroFornecedor(void) //cadastro fornecedor OK
{
	tpFornecedor Forn;
	int auxCod, x, i, j;
	FILE *PtrForn = fopen("Fornecedor.dat","ab+");
	
	gotoxy(40 ,9);
	printf("## Cadastro de fornecedor ##");
	gotoxy(60,11);
	printf("Sair '0' ");
	gotoxy(34, 12);	
	printf("Codigo: "); 
	scanf("%d",&auxCod);
	while (auxCod>0)
	{	
	
		x=BuscaFornecedor(PtrForn, auxCod);
		if(x==-1)
		{
			Forn.Cod=auxCod;
			gotoxy(34, 13);	
			printf("Nome do fornecedor: "); 
			fflush(stdin);
			gets(Forn.Nome);
			gotoxy(34, 14);	
			printf("Cidade do fornecedor: ");
			fflush(stdin);
			gets(Forn.Cid);	
			Forn.status='A';
			fwrite(&Forn,sizeof(tpFornecedor),1,PtrForn);
			gotoxy(34,16);
			printf("Fornecedor Cadastrado!");
			getch();
		}
		else
		{
			gotoxy(34, 14);
			printf("Fornecedor ja cadastrado!");
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
		gotoxy(60,11);
		printf("Sair '0' ");
		gotoxy(34, 12);	
		printf("Codigo: "); 
		scanf("%d",&auxCod);
	}	
	
	fclose(PtrForn);
}





void CadastroCliente() // cadastro Cliente
{
	tpCliente Cli;
	int pos, i, j, x;
	char AuxCPF[TF];
	FILE *PtrCli = fopen("cliente.dat","ab+");
	
	gotoxy(40 ,9);
	printf("## Cadastro de cliente ##");
	gotoxy(34, 12);
	printf("CPF do Cliente: ");
	fflush(stdin);
	scanf("%s", &AuxCPF);
	while(strlen(AuxCPF) == 11)
	{
		
		x=verificarCPF(AuxCPF);
		if(x==1)
		{
			pos = BuscaCliente(PtrCli, AuxCPF);
			if(pos==-1)
			{
				strcpy(Cli.CPF,AuxCPF);
				gotoxy(34, 13);
				printf("Nome do Cliente: ");
				fflush(stdin);
				gets(Cli.Nome);
				Cli.status='A';
				fwrite(&Cli,sizeof(tpCliente),1,PtrCli);
				gotoxy(34,15);
				printf("Cliente cadastrado!");
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
				printf("Cliente ja cadastrado! digite outro.");
				getch();
				//limpar a tela para continuar cadastrando
				for(i = 10;i<23;i++)
				{	for(j = 29;j<79;j++)
					{
						gotoxy(j,i);
						printf(" ");
					}
				}
			}
			
			gotoxy(34, 12);
			printf("CPF do Cliente: ");
			scanf("%d",&AuxCPF);
		}
		else
		{
			gotoxy(34,14);
			printf("CPF invalido!");
			getch();
			
		}
		
	}
	
}

void ExcluirFisCliente(void)
{
	FILE *PtrCli = fopen("cliente.dat","rb");
	int pos;
	char AuxCPF;
	tpCliente Reg;
	tpVendas RegV;
	tpVendasProduto RegVP;
	gotoxy(40,9);
	printf("### EXCLUSAO FISICA DE CLIENTE ###"); 
	if (PtrCli == NULL) //O Arquivo não existe!
	{
		gotoxy(40,12);
		printf("Erro de abertura!");
	}
	else
		{
			gotoxy(34,12);
			printf("CLIENTE a excluir: ");
			fflush(stdin); gets(AuxCPF);
			if (strlen(AuxCPF)==11)
			{
				pos = BuscaCliente(PtrCli,AuxCPF);
				if (pos==-1)
				{
					gotoxy(34,14);
					printf("CLIENTE nao encontrado!");
					getch();
					fclose(PtrCli);
				}
				else
					{
						gotoxy(40,13);
						printf("*** Detalhes do Registro ***");
						//fseek(Ptr,deslocamento Bytes,a partir de);
						fseek(PtrCli,pos,0);
						fread(&Reg,sizeof(tpCliente),1,PtrCli);
						gotoxy(34,15);
						printf("CPF: %d",Reg.CPF);	
						gotoxy(34,16);
						printf("Nome: %s",Reg.Nome);
						gotoxy(34,17);
						printf("QtdCompras: %d",Reg.QtdeCompras);
						gotoxy(34,18);
						printf("ValorTotal: %.2f",Reg.ValorTotal);	
						gotoxy(40,20);
						printf("Confirma Exclusao (S/N)? ");
						if (toupper(getche())=='S')
						{
							FILE *PtrVendas = fopen("vendas.dat","rb");
							FILE *PtrTemp = fopen("Temp.dat","wb");
							rewind(PtrCli); //fseek(PtrFunc,0,0);
							fread(&Reg,sizeof(tpCliente),1,PtrCli);
							while (!feof(PtrCli))
							{
								if(stricmp(AuxCPF,Reg.CPF)!= 0)
									fwrite(&Reg,sizeof(tpCliente),1,PtrTemp);
									
								fread(&Reg,sizeof(tpCliente),1,PtrCli);
							}
							fclose(PtrCli);
							fclose(PtrTemp);
							remove("Cliente.dat");
							rename("Temp.dat","Cliente.dat");
					
							
							FILE *PtrTempo = fopen("Tempo.dat","wb");
							
							rewind(PtrProd); //fseek(PtrFunc,0,0);
							fread(&RegP,sizeof(tpProduto),1,PtrProd);
							while (!feof(PtrProd))
							{
								if(Cod != RegP.CodForn)
									fwrite(&RegP,sizeof(tpProduto),1,PtrTempo);
									
								fread(&RegP,sizeof(tpProduto),1,PtrProd);
							}
							
							fclose(PtrProd);
							fclose(PtrTempo);
							remove("Produto.dat");
							rename("Tempo.dat","Produto.dat");
							limparTela();
							gotoxy(40,14);
							printf("Registro Excluido!");
							getch();	
						}
						else fclose(PtrForn);
					}
			}
		}
}

void ExcluirFisFornecedor(void)
{
	FILE *PtrForn = fopen("Fornecedor.dat","rb");
	int pos, Cod;
	tpFornecedor Reg;
	tpProduto RegP;
	gotoxy(40,9);
	printf("### EXCLUSAO FISICA DE FORNECEDOR ###"); 
	if (PtrForn == NULL) //O Arquivo não existe!
	{
		gotoxy(40,12);
		printf("Erro de abertura!");
	}
	else
		{
			gotoxy(34,12);
			printf("FORNECEDOR a excluir: ");
			scanf("%d",&Cod);
			if (Cod>0)
			{
				pos = BuscaFornecedor(PtrForn,Cod);
				if (pos==-1)
				{
					gotoxy(34,14);
					printf("Fornecedor nao encontrado!");
					getch();
					fclose(PtrForn);
				}
				else
					{
						gotoxy(40,13);
						printf("*** Detalhes do Registro ***");
						//fseek(Ptr,deslocamento Bytes,a partir de);
						fseek(PtrForn,pos,0);
						fread(&Reg,sizeof(tpFornecedor),1,PtrForn);
						gotoxy(34,15);
						printf("CodForn: %d",Reg.Cod);	
						gotoxy(34,16);
						printf("Cid: %s",Reg.Cid);
						gotoxy(34,17);
						printf("Nome: %s",Reg.Nome);	
						gotoxy(40,19);
						printf("Confirma Exclusao (S/N)? ");
						if (toupper(getche())=='S')
						{
							FILE *PtrProd = fopen("Produto.dat","rb");
							FILE *PtrTemp = fopen("Temp.dat","wb");
							rewind(PtrForn); //fseek(PtrFunc,0,0);
							fread(&Reg,sizeof(tpFornecedor),1,PtrForn);
							while (!feof(PtrForn))
							{
								if(Cod != Reg.Cod)
									fwrite(&Reg,sizeof(tpFornecedor),1,PtrTemp);
									
								fread(&Reg,sizeof(tpFornecedor),1,PtrForn);
							}
							fclose(PtrForn);
							fclose(PtrTemp);
							remove("Fornecedor.dat");
							rename("Temp.dat","Fornecedor.dat");
					//   ARRUMAR , ESTA EM LOOP INFINITO NO TEMPO.DAT
						//	printf("PAROU");
						//	getch();
							
							FILE *PtrTempo = fopen("Tempo.dat","wb");
							
							rewind(PtrProd); //fseek(PtrFunc,0,0);
							fread(&RegP,sizeof(tpProduto),1,PtrProd);
							while (!feof(PtrProd))
							{
								if(Cod != RegP.CodForn)
									fwrite(&RegP,sizeof(tpProduto),1,PtrTempo);
									
								fread(&RegP,sizeof(tpProduto),1,PtrProd);
							}
							
							fclose(PtrProd);
							fclose(PtrTempo);
							remove("Produto.dat");
							rename("Tempo.dat","Produto.dat");
							limparTela();
							gotoxy(40,14);
							printf("Registro Excluido!");
							getch();	
						}
						else fclose(PtrForn);
					}
			}
		}
}

void ExcluirFisProduto(void)
{
	FILE *PtrProd = fopen("Produto.dat","rb");
	int pos, Cod;
	tpProduto Reg;
	gotoxy(40,9);
	printf("### EXCLUSAO FISICA DE PRODUTO ###"); 
	if (PtrProd == NULL) //O Arquivo não existe!
	{
		gotoxy(34,12);
		printf("Erro de abertura!");
	}
				
	else
		{
			gotoxy(34,12);
			printf("PRODUTOr a excluir: ");
			scanf("%d",&Cod);
			if (Cod>0)
			{
				pos = BuscaProduto(PtrProd,Cod);
				if (pos==-1)
				{	gotoxy(34,14);
					printf("Produto nao encontrada!");
					getch();
					fclose(PtrProd);
				}
				else
					{
						gotoxy(34,14);
						printf("*** Detalhes do Registro ***");
						//fseek(Ptr,deslocamento Bytes,a partir de);
						fseek(PtrProd,pos,0);
						fread(&Reg,sizeof(tpProduto),1,PtrProd);
						gotoxy(34,15);
						printf("Cod: %d",Reg.Cod);
						gotoxy(34,16);
						printf("Nome: %s",Reg.Descr);
						gotoxy(34,17);
						printf("Preco: R$ %.2f",Reg.Preco);
						gotoxy(34,18);
						printf("Estoque: %d",Reg.Estoque);
						gotoxy(34,19);
						printf("Validade; %d/%d/%d",Reg.Valid.d,Reg.Valid.m,Reg.Valid.a);
						gotoxy(34,20);
						printf("CodForn: %d",Reg.CodForn);	
						
						gotoxy(40,22);
						printf("Confirma Exclusao (S/N)? ");
						if (toupper(getche())=='S')
						{
							FILE *PtrTemp = fopen("Temp.dat","wb");
							rewind(PtrProd); //fseek(PtrFunc,0,0);
							fread(&Reg,sizeof(tpProduto),1,PtrProd);
							while (!feof(PtrProd))
							{
								if(Cod != Reg.Cod)
									fwrite(&Reg,sizeof(tpProduto),1,PtrTemp);
									
								fread(&Reg,sizeof(tpProduto),1,PtrProd);
							}
							fclose(PtrProd);
							fclose(PtrTemp);
							remove("Produto.dat");
							rename("Temp.dat","Produto.dat");
							
							limparTela();
							gotoxy(40,16);
							printf("Registro Excluido!");
							getch();	
						}
						else fclose(PtrProd);
					}
			}
		}
}

void ExcluirProdutoEstoque(void)
{
	tpProduto Reg;
	FILE *PtrProd = fopen("Produto.dat","rb+");
	FILE *PtrTemp = fopen("Temp.dat","wb");
	rewind(PtrProd); //fseek(PtrFunc,0,0);
	fread(&Reg,sizeof(tpProduto),1,PtrProd);
	while (!feof(PtrProd))
	{
		if(0 != Reg.Estoque)
			fwrite(&Reg,sizeof(tpProduto),1,PtrTemp);
			
		fread(&Reg,sizeof(tpProduto),1,PtrProd);
	}
	fclose(PtrProd);
	fclose(PtrTemp);
	remove("Produto.dat");
	rename("Temp.dat","Produto.dat");
	getch();	
					
}

void RealizarVendas(int &cont) //vendas
{
 	 tpVendas TabVendas;
 	 tpVendasProd TabVendasProd;
 	 tpProduto TabProd;
 	 tpCliente TabCli;
	 
	 int i=0, x=12,j, AuxCodProd,pos,posP,Qtde,CodVenda,CodProd,ValorTotal = 0;
		char AuxCPF[TF],op,OP;;
	

	

	
	gotoxy(43,9);
	printf("## Realizar Venda ##");
	
	gotoxy(38 ,12);
	printf("Deseja Efetuar uma compra? S/N: ");
	//toupper(getch(op));
	//scanf("%c",&op);
	op = toupper(getche());
	if(op == 'S')
	{
		
		
		
		limparTela();
		
		
		gotoxy(43,9);
		printf("## Realizar Venda ##");
		gotoxy(32, 12);
		printf("Digite o seu CPF: ");
		gets(AuxCPF);
		FILE * PtrCli = fopen ("cliente.dat","rb+");
		FILE *PtrVendasProd = fopen ("VendProdutos.dat","ab+");
		FILE * PtrVendas=fopen ("Vendas.dat","ab+");
		FILE * PtrProd=fopen ("Produto.dat","rb+");
		pos = BuscaCliente(PtrCli,AuxCPF);
		
			while(pos != -1)//achou
			{
				
				if(PtrProd!=NULL) //PtrProd == NULL significa que nao tem nd dentro do arquivo
				{
					
				   gotoxy(34,13);
				   printf("Qual produto deseja comprar(CodProd): ");
				   scanf("%d",& AuxCodProd);
				  
				   posP=BuscaProduto(PtrProd,AuxCodProd);
				   if(posP!=-1) //achou
				   {	
				   		fseek(PtrProd,posP,0);
				   
				   		
				   		
						gotoxy(34,14);
					   	printf("Quantos deseja comprar: ");
					   	scanf("%d",&Qtde);
					   	if(Qtde <= TabProd.Estoque) // Menor que o estoque
	                        {
	                        	cont++;
							 	TabVendas.CodVenda = cont;
				   		        strcpy(TabVendas.CPF,AuxCPF);
				   		        gotoxy(32,15);
				   		        printf("Digite a data do dia da compra:");
				   		        scanf("%d %d %d",&TabVendas.Data.d,&TabVendas.Data.m,&TabVendas.Data.a);
					   			TabVendasProd.CodProd = AuxCodProd;
					   			TabVendasProd.CodVenda = TabVendas.CodVenda;
					   			TabVendasProd.Qtde = Qtde;
					   			TabVendasProd.ValorUnitario = TabProd.Preco;
					   			ValorTotal = TabVendasProd.Qtde * TabVendasProd.ValorUnitario;
					   			
						        fwrite(&TabVendas,sizeof(tpVendas),1,PtrVendas);
						       
						       fwrite(&TabVendasProd,sizeof(tpVendasProd),1,PtrVendasProd);
						       
							    TabProd.Estoque -= Qtde;
						        if(TabProd.Estoque == 0)
       						         ExcluirProdutoEstoque();
					   			TabCli.QtdeCompras++;
					   			fwrite(&TabProd,sizeof(tpProduto),1,PtrProd);
					   			gotoxy(34,16);
					   			printf("Deseja Realizar mais compras?");
					   			scanf("%c",&op);
					   			op = toupper(getche());;
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
												  	if(TabProd.Cod!=NULL)
														{
														   gotoxy(34,13);
														   printf("Qual produto deseja comprar(CodProd): ");
														   scanf("%d",&AuxCodProd);
														   posP=BuscaProduto(PtrProd,AuxCodProd);
															   if(posP!=-1) //achou
															   {
																   	gotoxy(34,14);
																   	printf("Quantos deseja comprar: ");
																   	scanf("%d",&Qtde);
																   	if(Qtde <= TabProd.Estoque) // Menor que o estoque
												                        {
												                        	
															   		        gotoxy(34,15);
															   		        printf("Digite a data do dia da compra");
															   		        scanf("%d %d %d",&TabVendas.Data.d,&TabVendas.Data.m,&TabVendas.Data.a);
																   			TabVendasProd.CodProd = AuxCodProd;
																   			TabVendasProd.CodVenda = cont;
																   			TabVendasProd.Qtde = Qtde;
																   			TabVendasProd.ValorUnitario = TabProd.Preco;
																   			ValorTotal = TabVendasProd.Qtde * TabVendasProd.ValorUnitario;
																   			
																   			fwrite(&TabVendas,sizeof(tpVendas),1,PtrVendas);
																   			fwrite(&TabVendasProd,sizeof(tpVendasProd),1,PtrVendasProd);
																		        
																		        TabProd.Estoque-= Qtde;
																			        if(TabProd.Estoque == 0)
													       						         ExcluirProdutoEstoque();
																	   			TabCli.QtdeCompras++;
																   			gotoxy(34,16);
																   			printf("Deseja Realizar mais compras?");
																   			fwrite(&TabProd,sizeof(tpProduto),1,PtrProd);
																   			op = toupper(getche());
																   			if(op == 'N')
																   				  {
																   				  	   	 
														   			            		for(i = 10;i<23;i++)
																							for(j = 29;j<79;j++)
																								{
																									gotoxy(j,i);
																									printf(" ");
																								}
																						gotoxy(34,12);
																						printf("Compra efetuada com sucesso!");
																			   			TabVendas.TotVenda = ValorTotal;
																			   			gotoxy(34,13);
																			   			printf("CodVenda: %d   Valor da Compra: %.2f",TabVendas.CodVenda,TabVendas.TotVenda);
																			   			 
																			   			TabCli.ValorTotal += ValorTotal;
																			   			fwrite(&TabCli,sizeof(tpCliente),1,PtrCli);
																			   			getch();
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
														  				  printf("Estoque: %d",TabProd.Estoque);
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
												  				  printf("Produto não encontrado!");
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
												  			  printf("Sem Produtos para vender!");
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
											printf("Compra efetuada com sucesso!");
											TabVendas.TotVenda = ValorTotal;
											gotoxy(34,13);
											printf("CodVenda: %d   Valor da Compra: %.2f",TabVendas.CodVenda,TabVendas.TotVenda);
					   			             
				   			            	TabCli.ValorTotal += ValorTotal;
				   			            	fwrite(&TabCli,sizeof(tpCliente),1,PtrCli);
				   			            	gotoxy(34,13);
											ValorTotal = 0;
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
			  				  printf("Quantidade maior que estoque");
			  				  gotoxy(34,15);
			  				  printf("Estoque: %d",TabProd.Estoque);
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
			   limparTela();
			   gotoxy (34,14);
			    printf("Digite CPF para comprar !!!!");
			    fflush(stdin);
			    gets(AuxCPF);
			    pos = BuscaCliente(PtrCli,AuxCPF);
	        }
	        fclose(PtrProd);
		   fclose(PtrVendas);
		   fclose(PtrVendasProd);
		   fclose(PtrCli);
		
		if(pos == -1)
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













void ConsultarProduto(void)
{
	tpProduto Prod;
	int pos, i, j;
	FILE *PtrProd = fopen("Produto.dat","rb");
	
	gotoxy(40 ,9);
	printf("## Consulta de produtos ##"); 
	if (PtrProd == NULL) //O Arquivo não existe!
	{
		gotoxy(34,12);
		printf("Erro de abertura! Arquivo inexistente");
	}	
	else
		{
			gotoxy(34,12);
			printf("Codigo do produto: ");
			scanf("%d",&Prod.Cod);
			while (Prod.Cod>0)
			{
				pos = BuscaProduto(PtrProd,Prod.Cod);
				if (pos==-1)
				{
					gotoxy(34,13);
					printf("Produto nao encontrada!");
				}
				else
					{
						gotoxy(34,14);
						printf("*** Detalhes do Registro ***");
						//fseek(Ptr,deslocamento Bytes,a partir de);
						fseek(PtrProd,pos,0);
						fread(&Prod,sizeof(tpProduto),1,PtrProd);
						gotoxy(34,15);
						printf("Codigo: %d", Prod.Cod);
						gotoxy(34,16);
						printf("Descricao: %s", Prod.Descr);
						gotoxy(34,17);
						printf("Estoque: ",Prod.Estoque);	
						gotoxy(34,18);
						printf("Preco: %f", Prod.Preco );
						gotoxy(34,19);
						printf("Validade: %d%d%d", Prod.Valid.d,Prod.Valid.m,Prod.Valid.a );
					}
				getch();
				for(i = 10;i<23;i++)
				{
					for(j = 29;j<79;j++)
						{
							gotoxy(j,i);
							printf(" ");
						}	
				}	
					
				gotoxy(34,12);
				printf("Codigo do produto: ");
				scanf("%d",&Prod.Cod);
			}
			fclose(PtrProd);
		}
}

void ConsultarFornecedor(void)
{
	tpFornecedor Forn;
	int pos, i, j;
	FILE *PtrForn = fopen("Fornecedor.dat","rb");
	
	gotoxy(40 ,9);
	printf("## Consulta de fornecedor ##"); 
	if (PtrForn == NULL) //O Arquivo não existe!
	{
		gotoxy(34,12);
		printf("Erro de abertura! Arquivo inexistente");
	}	
	else
		{
			gotoxy(34,12);
			printf("Codigo do fornecedor: ");
			scanf("%d",&Forn.Cod);
			while (Forn.Cod>0)
			{
				pos = BuscaFornecedor(PtrForn,Forn.Cod);
				if (pos==-1)
				{
					gotoxy(34,13);
					printf("Fornecedor nao encontrada!");
				}
				else
					{
						gotoxy(34,14);
						printf("*** Detalhes do fornecedor ***");
						//fseek(Ptr,deslocamento Bytes,a partir de);
						fseek(PtrForn,pos,0);
						fread(&Forn,sizeof(tpFornecedor),1,PtrForn);
						gotoxy(34,15);
						printf("Codigo: %d", Forn.Cod);
						gotoxy(34,16);
						printf("Nome: %s", Forn.Nome);
						gotoxy(34,17);
						printf("Cdade: %s",Forn.Cid);	
					}
				getch();
				for(i = 10;i<23;i++)
				{
					for(j = 29;j<79;j++)
						{
							gotoxy(j,i);
							printf(" ");
						}	
				}
				gotoxy(34,12);
				printf("Codigo do fornecedor: ");
				scanf("%d",&Forn.Cod);
			}
			fclose(PtrForn);
		}
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

 void formulario(void) // formulario
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

char MenuPrincipal(void) //  menu principal
{
	textcolor(15);
	gotoxy(8,8);
	printf("# # M E N U # #");
	gotoxy(3,12);
	printf(" [ A ]-Produtos a venda ");
	gotoxy(3,14);
	printf(" [ B ]-Gerenciamento ");
	gotoxy(3,16);
	printf(" [ C ]-Emitir Relatorio ");
	gotoxy(3,18);
	printf(" [ESC]-S A I R");
	gotoxy(40,25);
	return toupper(getche());

}

char subProdutos(void) //sub menu de produtos 
{
	textcolor(15);
	gotoxy(40,9);
	printf("## SUB MENU PRODUTOS ##");
	gotoxy(35,12);
	printf(" [ A ]-Consulta de produtos");
	gotoxy(35,14);
	printf(" [ B ]-Realizar compra");
	gotoxy(35,16);
	printf(" [ C ]-Excluir compra");
	gotoxy(35,18);
	printf(" [ D ]-Gerar Cupom");
	gotoxy(40,25);
	return toupper(getche());
}

char subGerenciamento(void) //sub menu de gerenciamento
{
	textcolor(15);
	gotoxy(40,8);
	printf("## SUB MENU GERENCIAMENTO ##");
	gotoxy(35,10);
	printf(" [ A ]-Cadastro de item");
	gotoxy(35,12);
	printf(" [ B ]-Consulta de itens");
	gotoxy(35,14);
	printf(" [ C ]-Exclusao Fisica de item");
	gotoxy(35,16);
	printf(" [ D ]-Exclusao Logica de Item");
	gotoxy(35,18);
	printf(" [ E ]-Alteracao de itens");
	gotoxy(35,20);
	printf(" [ F ]-Relatorio simples");
	gotoxy(35,22);
	printf(" [ G ]-Aumentar preco");
	gotoxy(40,24);
	return toupper(getche());
}

char EscolhaGerenciamentoCadastro(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("## QUAL DESEJA CADASTRAR? ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(40,25);
	return toupper(getche());
}

char EscolhaGerenciamentoConsulta(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("## QUAL DESEJA CONSULTAR? ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(40,25);
	return toupper(getche());
}
char EscolhaGerenciamentoExclusao(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("## QUAL DESEJA EXCLUIR? ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(40,25);
	return toupper(getche());
}

char EscolhaGerenciamentoAlterar(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("## QUAL DESEJA ALTERAR? ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(40,25);
	return toupper(getche());
}

char EscolhaGerenciamentoRelatorioS(void)  //menu de escolha do sub menu gerenciamento
{
	
	textcolor(15);
	gotoxy(45,9);
	printf("## QUAL DESEJA ALTERAR? ##");
	gotoxy(35,12);
	printf(" [ A ]-Produtos");
	gotoxy(35,14);
	printf(" [ B ]-Fornecedor");
	gotoxy(35,16);
	printf(" [ C ]-Clientes");
	gotoxy(40,25);
	return toupper(getche());
}
int main(void)
{
	
	int vendas=0;
	char op, opsub, opEscolha;
	FILE *PtrProd = fopen ("Produto.dat","ab");
	FILE *PtrForn = fopen ("Fornecedor.dat","ab");
	FILE *PtrCli = fopen ("cliente.dat","ab");
	FILE *PtrVendas = fopen ("vendas.dat","ab");
	FILE *PtrVendasProd = fopen ("VendProdutos.dat","ab");
	fclose(PtrProd);
	fclose(PtrForn);
	fclose(PtrCli);
	fclose(PtrVendas);
	fclose(PtrVendasProd);
	formulario();
	
	gotoxy(100,30);
	
	do
	{
		
		op = MenuPrincipal();
		switch(op)
		{
			case 'A':	opsub=subProdutos();//VENDAS
						switch(opsub)
						{
							case 'A':	limparTela();
										//Consultar produtos
										break;
										
							case 'B': 	limparTela(); 
								 		RealizarVendas(vendas);//Realizar Venda
										break;
										
							case 'C':	limparTela();
										//exclusao
										break;
										
							case 'D':	limparTela();
										//gerar cupom
										break;
						}
						break;
					  
			case 'B':	opsub=subGerenciamento();//GERENCIAMENTO
						switch(opsub)
						{
							case 'A':	limparTela();
										opEscolha=EscolhaGerenciamentoCadastro();//CADASTRO
										switch(opEscolha)
										{
											case 'A':	limparTela();
														CadastroProduto();//Produtos
														break;
														
											case 'B':   limparTela();
														CadastroFornecedor();//fornecedor
														break;
														
											case 'C':   limparTela();
														CadastroCliente();//cliente
														break;
										}
										break;
										
							case 'B': 	limparTela();
										opEscolha=EscolhaGerenciamentoConsulta(); //CONSULTA
										switch(opEscolha)
										{
											case 'A':	limparTela();
														ConsultarProduto();//Produtos
														break;
														
											case 'B':	limparTela();
														//fornecedor
														break;
														
											case 'C':	limparTela();
														//cliente
														break;
										}
										break;
										
							case 'C':	limparTela();
										opEscolha=EscolhaGerenciamentoExclusao(); //EXCLUSAO
										switch(opEscolha)
										{
											case 'A':	limparTela();
														ExcluirFisProduto();//Produtos
														break;
														
											case 'B':	limparTela();
														ExcluirFisFornecedor();//fornecedoR
														break;
														
											case 'C':	limparTela();
														//cliente
														break;
										}
										break;
										
							case 'D':	limparTela();
										opEscolha=EscolhaGerenciamentoAlterar();//alteração
										switch(opEscolha)
										{
											case 'A':	limparTela();
														//Produtos
														break;
														
											case 'B':	limparTela();	
														//fornecedor
														break;
														
											case 'C':	limparTela();
														//cliente
														break;
										}
										break;
										
							case 'E':	limparTela();
										opEscolha=EscolhaGerenciamentoRelatorioS();//RELATORIO SIMPLES
										switch(opEscolha)
										{
											case 'A':	limparTela();
														//produtos
														break;
											
											case 'B':	limparTela();
														//fornecedor
														break;
														
											case 'C':	limparTela();
														//cliente
														break;
											
														
										}				
										break;
										
							case 'F':	limparTela();
										//aumentar preço fornecedor
										break;
						}
						break;
					  
			case 'C':	limparTela(); 
						//RELATORIO
						break;
			
				
		}
		limparTela();
	}while(op!=27);
	return 0;
}
