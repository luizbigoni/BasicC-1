// Arquivos Binários

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

struct tpFunc
{
	int Matricula;
	float Salario;
	char nome[30];
};

void Cadastro(void)
{
	tpFunc R;
	
	FILE *ptrArq = fopen("func.dat","ab");
	printf("\n### Cadastro de Funcionarios ###\n");
	printf("Matricula: ");
	scanf("%d",&R.Matricula);
	while(R.Matricula>0)
	{
		printf("Nome: ");
		fflush(stdin);
		gets(R.nome);
		printf("Salario R$: ");
		scanf("%f",&R.Salario);
		fwrite(&R,sizeof(tpFunc),1,ptrArq);
		printf("\n\nMatricula: ");
		scanf("%d",&R.Matricula);
	}
	fclose(ptrArq);
}

void Exibir(void)
{
	tpFunc R;
	FILE *ptr = fopen("func.dat","rb");
	if(ptr==NULL)
		printf("\nErro de Abertura!\n");
	else
	{
		printf("\n### Conteudo do Arquivo ###\n");
		fread(&R,sizeof(tpFunc),1,ptr);
		while(!feof(ptr))
		{
			printf("\nMatricula [%d] - %s",R.Matricula,R.nome);
			printf("\nSalario: %.2f",R.Salario);
			fread(&R,sizeof(tpFunc),1,ptr);
		}
		fclose(ptr);
	}
	getch();
}

int BuscaFunc(FILE *ptr, int Mat)
{
	TpFunc R;
	rewind(ptr);
	
	fread(&R,sizeof(TpFunc),1,ptr);
	while(!feof(ptr) && Mat!R.Matricula)
			fread(&R,sizeof(TpFunc),1,ptr); // para aumentar e rodar dentro do laço , aumentar as casas , entra lido e sai lido
	
	if(!feof(ptr)) // Forma de perguntar que chegou no final do arquivo ou (Mat == R.Matricula)
	// ftell(Ptr) fala aonde está o ponteiro no momento " Retorna a posição do ponteiro no arquivo "
		return ftell(Ptr)-sizeof(TpFunc); // Retorna o ftell - os bytes de TpFunc ( 32 BYTES)
	else
		return -1;	
}

void Consultar()
{
	TpFunc Reg;
	FILE *ptrFunc = fopen("func.dat","rb");
	printf("\n### Consultar por Matricula###\n");
	printf("Digite a Matricula: ");
	scanf("%d",&Reg.Matricula);
	while(Reg.Matricula>0)
	{
		pos = BuscaFunc(ptrFunc,Reg.Matricula);
		if(pos==-1)
			printf("\nFuncionario nao cadastrado");
		else
		{	
			//fseek (Ponteiro,desl Bytes , modo ( inicio(SEEK_SET) , fim(SEEK_END) , POSIÇÃO CORRENTE(SEEK_CUR) )
			fseek(PtrFunc,pos,SEEK_SET) // o pos é a quantidade de bytes que a gente precisa , SEEK_SET = 0
			
			fread(&Reg,sizeof(TpFunc),1,ptrFunc);
			printf("\n*** Detalhes do Registro ###\n");
			printf("Matricula: %d\n",Reg.Matricula);
			printf("Nome: %s\n",Reg.nome);
			printf("Salario: R$ %.2f\n",Reg.Salario);
			getch();
		}
	}
	fclose(ptrFunc);
}

char Menu(void)
{
	clrscr();
	printf("\n# # # #   M E N U   # # # #\n");
	printf("[A] - Cadastrar de Funcionarios");
	printf("\n[B] - Exibir Funcionarios");
	printf("\n[C] - Consultar Funcionarios");
	printf("\n[D] - Alterar Funcionarios");
	printf("\n[E] - Ordenar Funcionarios");
	printf("\n[ESC] - Finalizar");
	printf("\nOpcao desejada: \n");
	return toupper(getche());
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
		}
	}while (op!=27);
	return 0;
}
