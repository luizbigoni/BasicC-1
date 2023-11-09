// Arquivos Binários

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

struct TpFunc
{
	int Matricula;
	float Salario;
	char Nome[30], Status; //[A]tivo   [I]nativo
};

int BuscaFunc(FILE *Ptr, int Mat)
{
	TpFunc R;
	rewind(Ptr); //fseek(Ptr,0,0);
	int achou = 0;
	fread(&R,sizeof(TpFunc),1,Ptr);
	while (!feof(Ptr) && !(Mat!=R.Matricula && R.Status!='A'))
			fread(&R,sizeof(TpFunc),1,Ptr);
	
	if (!feof(Ptr)) //!feof(Ptr))
		return ftell(Ptr)-sizeof(TpFunc);
	else
		return -1;
}

void Cadastro(void)
{
	TpFunc R;
	
	FILE *PtrArq = fopen("func.dat","ab");
	printf("\n### Cadastro de Funcionarios ###\n");
	printf("Matricula: ");
	scanf("%d",&R.Matricula);
	while(R.Matricula>0)
	{
		printf("Nome: ");
		fflush(stdin);
		gets(R.Nome);
		printf("Salario R$: ");
		scanf("%f",&R.Salario);
		R.Status = 'A'; // A de Ativo
		fwrite(&R,sizeof(TpFunc),1,PtrArq);
		printf("\n\nMatricula: ");
		scanf("%d",&R.Matricula);
	}
	fclose(PtrArq);
}

void Exibir(void)
{
	TpFunc Reg;
	FILE *Ptr = fopen("func.dat","rb");
	if(Ptr==NULL)
		printf("\nErro de Abertura!\n");
	else
	{
		printf("\n### Conteudo do Arquivo ###\n");
		fread(&Reg,sizeof(TpFunc),1,Ptr);
		while(!feof(Ptr))
		{
			if(Reg.status==a)
			{
				printf("\nMatricula [%d] - %s",Reg.Matricula,R.Nome);
				printf("\nNome %s",Reg.Nome);
				printf("\nSalario: %.2f",Reg.Salario);
			}
			fread(&Reg,sizeof(TpFunc),1,Ptr);
		}
		fclose(Ptr);
	}
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n# # # #   M E N U   # # # #\n");
	printf("[A] - Cadastrar Funcionarios");
	printf("\n[B] - Exibir Funcionarios");
	printf("\n[C] - Consultar Funcionarios");
	printf("\n[D] - Alterar Funcionarios");
	printf("\n[E] - Ordenar Funcionarios");
	printf("\n[F] - Exclusao Fisica de Funcionarios");
	printf("\n[G] - Exclusao Logica de Funcionarios");
	printf("\n[H] - Recuperar Registro deletado Logicamente");
	printf("\n[ESC] - Finalizar");
	printf("\nOpcao desejada: \n");
	return toupper(getche());
}

void Consultar()
{
	TpFunc Reg;
	int pos;
	FILE *PtrFunc = fopen("func.dat","rb");
	printf("\n### Consultar por Matricula ###\n");
	printf("Digite a Matricula: ");
	scanf("%d",&Reg.Matricula);
	while (Reg.Matricula>0)
	{
		pos = BuscaFunc(PtrFunc,Reg.Matricula);
		if (pos==-1)
			printf("\nFuncionario nao Cadastrado!\n");
		else
			{
				fseek(PtrFunc,pos,0);
				fread(&Reg,sizeof(TpFunc),1,PtrFunc);
				printf("\n*** Detalhes do Registro ***\n");
				printf("Matricula: %d\n",Reg.Matricula);
				printf("Nome: %s\n",Reg.Nome);
				printf("Salario: R$ %.2f\n",Reg.Salario);
				getch();
			}
		
		printf("Digite a Matricula: ");
		scanf("%d",&Reg.Matricula);
	}
	fclose(PtrFunc);
}


void Alterar(void)
{
	TpFunc Reg;
	int pos;
	FILE *PtrFunc = fopen("func.dat","rb+");
	printf("\n### Alterar por Matricula ###\n");
	printf("Digite a Matricula: ");
	scanf("%d",&Reg.Matricula);
	while (Reg.Matricula>0)
	{
		pos = BuscaFunc(PtrFunc,Reg.Matricula);
		if (pos==-1)
			printf("\nFuncionario nao Cadastrado!\n");
		else
			{
				fseek(PtrFunc,pos,0);
				fread(&Reg,sizeof(TpFunc),1,PtrFunc);
				printf("\n*** Detalhes do Registro ***\n");
				printf("Matricula: %d\n",Reg.Matricula);
				printf("Nome: %s\n",Reg.Nome);
				printf("Salario: R$ %.2f\n",Reg.Salario);
				
				printf("\nConfirma Alteracao (S/N)? ");
				if(toupper(getche())=='S')
				{
					printf("Novo Nome: ");
					fflush(stdin);
					gets(Reg.Nome);
					printf("Novo Salario R$: ");
					scanf("%f",&Reg.Salario);
					
					fseek(PtrFunc,pos,0);
					fwrite(&Reg,sizeof(TpFunc),1,PtrFunc);
					printf("\nRegistro Alterado!\n");
				}
			}
		getch();
		printf("\n\nDigite a Matricula: ");
		scanf("%d",&Reg.Matricula);
	}
	fclose(PtrFunc);
}

void Ordenar(void)
{
	int a, b, QtdeReg;
	TpFunc RA, RB;
	FILE *PtrFunc = fopen("Func.dat","rb+");
	if (PtrFunc==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			fseek(PtrFunc,0,2);
			QtdeReg = ftell(PtrFunc)/sizeof(TpFunc);
			for(a=0; a<QtdeReg-1; a++)
				for(b=a+1; b<QtdeReg; b++)
				{
					fseek(PtrFunc,a*sizeof(TpFunc),0);
					fread(&RA,sizeof(TpFunc),1,PtrFunc);
					
					fseek(PtrFunc,b*sizeof(TpFunc),0);
					fread(&RB,sizeof(TpFunc),1,PtrFunc);
					
					if(RA.Matricula > RB.Matricula)
					{
						fseek(PtrFunc,a*sizeof(TpFunc),0);
						fwrite(&RB,sizeof(TpFunc),1,PtrFunc);
						
						fseek(PtrFunc,b*sizeof(TpFunc),0);
						fwrite(&RA,sizeof(TpFunc),1,PtrFunc);
					}
				}	
			printf("\nArquivo Ordenado!\n");
			fclose(PtrFunc);
		}		
		getch();
}
// EXCLUSAO LOGICA É DESATIVAR UM REGISTRO PARA ELE NÃO SER EXIBIDO
void ExclusaoLog(void)
{
	TpFunc Reg;
	int pos;
	FILE *PtrFunc = fopen("func.dat","rb+");
	printf("\n### Exclusao Logica De Funcionarios ###\n");
	printf("Digite a Matricula: ");
	scanf("%d",&Reg.Matricula);
	while (Reg.Matricula>0)
	{
		pos = BuscaFunc(PtrFunc,Reg.Matricula);
		if (pos==-1)
			printf("\nFuncionario nao Cadastrado!\n");
		else
			{
				fseek(PtrFunc,pos,0);
				fread(&Reg,sizeof(TpFunc),1,PtrFunc);
				printf("\n*** Detalhes do Registro ***\n");
				printf("Matricula: %d\n",Reg.Matricula);
				printf("Nome: %s\n",Reg.Nome);
				printf("Salario: R$ %.2f\n",Reg.Salario);
				
				printf("\nConfirma Exclusao (S/N)? ");
				if(toupper(getche())=='S')
				{
					Reg.Status = 'I'; // Inativo
					fseek(PtrFunc,pos,0);
					fwrite(&Reg,sizeof(TpFun),1,PtrFunc);
					printf("\n Registro Deletado Logicamente\n");
				}
			}
		getch();
		printf("\nDigite a Matricula: ");
		scanf("%d",&Reg.Matricula);
	}
	fclose(PtrFunc);
}
void RecuperarLog(void) 
{
	TpFunc Reg;
	int pos;
	FILE *PtrFunc = fopen("func.dat","rb+");
	printf("\n### Recuperação Logica De Funcionarios ###\n");
	printf("Digite a Matricula: ");
	scanf("%d",&Reg.Matricula);
	while (Reg.Matricula>0)
	{
		pos = BuscaFunc(PtrFunc,Reg.Matricula);
		if (pos==-1)
			printf("\nFuncionario nao Cadastrado!\n");
		else
			{
				fseek(PtrFunc,pos,0);
				fread(&Reg,sizeof(TpFunc),1,PtrFunc);
				printf("\n*** Detalhes do Registro ***\n");
				printf("Matricula: %d\n",Reg.Matricula);
				printf("Nome: %s\n",Reg.Nome);
				printf("Salario: R$ %.2f\n",Reg.Salario);
				
				printf("\nConfirma para Recuperar (S/N)? ");
				if(toupper(getche())=='S')
				{
					Reg.Status = 'A'; // Ativo
					fseek(PtrFunc,pos,0);
					fwrite(&Reg,sizeof(TpFun),1,PtrFunc);
					printf("\n Registro Recuperado Logicamente\n");
				}
			}
		getch();
		printf("\nDigite a Matricula: ");
		scanf("%d",&Reg.Matricula);
	}
	fclose(PtrFunc);
}
}
void Exclusao (void)
{
	TpFunc Reg;
	int pos,Mat;
	FILE *PtrFunc = fopen("func.dat","rb");
	printf("\n### EXCLUSAO por FUNCIONARIO ###\n");
	printf("Matricula a excluir: ");
	scanf("%d",&Mat);
	while (Mat>0)
	{
		pos = BuscaFunc(PtrFunc,Mat);
		if (pos==-1)
		{
			printf("\nFuncionario nao Cadastrado!\n");
			fclose(PtrFunc);
		}
		else
			{
				fseek(PtrFunc,pos,0);
				fread(&Reg,sizeof(TpFunc),1,PtrFunc);
				printf("\n*** Detalhes do Registro ***\n");
				printf("Matricula: %d\n",Mat);
				printf("Nome: %s\n",Reg.Nome);
				printf("Salario: R$ %.2f\n",Reg.Salario);
				
				printf("\nConfirma Alteracao (S/N)? ");
				if(toupper(getche())=='S')
				{
					FILE *PtrTemp = fopen("Temp.dat","wb")//CRIA UM NOVO ARQUIVO PARA REPASSAR OS DADOS DO ORIGINAL PARA REALIZAR A EXCLUSAO
					fseek(PtrFunc,0,0);
					fread(&Reg,sizeof(TpFunc),1,PtrFunc);
					while (!feof(PtrFunc))
					{
						if(Reg.Matricula != Mat)
							fwrite(&Reg,sizeof(TpFunc),1,PtrTemp)	// Vou gravar o arquivo original no novo para poder excluir ele ( Gravar menos o que n quer )
							
						fread(&Reg,sizeof(Tpfunc,1,PtrFunc));
					}
					// Tem que fechar ambos arquivos para conseguir excluir e renomear , se n não vai excluir e nem renomear
					fclose(PtrFunc);
					fclose(PtrTemp);
					remove("func.dat"); // ESSE REMOVE ELE VAI EXCLUIR UM ARQUIVO INTEIRO
					rename("Temp.dat","Func.dat"); // Esse rename é o nome atual e o nome que eu quero
					printf("\nRegistro excluido com sucesso!");
					getch();
				}
				else fclose(PtrFunc);
			}
		getch();
		printf("\nMatricula a excluir: ");
		scanf("%d",&Mat);
		FILE * PtrFunc = fopen("Func.dat","rb");
	}
}
	

int main(void)
{
	char op;
	do
	{
		op = Menu();
		switch(op)
		{
			case 'A': Cadastro();
					  break;
					  
			case 'B': Exibir();
					  break;
					  
			case 'C': Consultar();
					  break;
					  
			case 'D': Alterar();
					  break;
					  
			case 'E': Ordenar();
					  break;
		}
	}while (op!=27);
	return 0;
}

// TEM QUE FAZER PARA EXCLUIR TODOS QUE ESTÃO INATIVOS
