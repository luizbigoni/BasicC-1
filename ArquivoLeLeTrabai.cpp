#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

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
 	tpDataV Data;
 };
 
 struct tpVendasProd
 {
 	int CodVenda,CodProd,Qtde;
 	float ValorUnitario;
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
	printf(" [ D ]-Inserir dados ");
	gotoxy(8,24);
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
			case 'A':	opsub=subProdutos();//VENDAS
						switch(opsub)
						{
							case 'A':	limparTela();
										//Consultar produtos
										break;
										
							case 'B': 	limparTela(); 
								 		//Realizar Venda
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
														//Produtos
														break;
														
											case 'B':   limparTela();
														//fornecedor
														break;
														
											case 'C':   limparTela();
														//cliente
														break;
										}
										break;
										
							case 'B': 	limparTela();
										opEscolha=EscolhaGerenciamentoConsulta(); //CONSULTA
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
										
							case 'C':	limparTela();
										opEscolha=EscolhaGerenciamentoExclusao(); //EXCLUSAO
										switch(opEscolha)
										{
											case 'A':	limparTela();
														//Produtos
														break;
														
											case 'B':	limparTela();
														//fornecedoR
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
			
			case 'D':	limparTela();
						//inserir dados
						break;
				
		}
		limparTela();
	}while(op!=27);
	return 0;
}
