#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>

struct TpFunc
{
	int Matricula;
	Float Salario;
	char Name[30];
};

void Gravar(void)
{
	TpFunc F;
	FILE *Ptr=fopen("Func.dat","wb");
	printf("\n Matrícula: ");
	scanf("%d",&F.Matricula);
	while(F.Matricula>0)
	{
		printf("Nome: ");fflush(stdin);
		gets(F.Nome);
		printf("Salario R$: ");
		scanf("%f",F.Salario);
		fwrite(&F,sizeof(TpFunc),1,Ptr);  //ARQUIVO BINARIO OS DADOS FICA UM NA FRENTE DO OUTRO!
		printf("\nMatricula: ");
		scanf("%d",&F.Matricula);
	}
	fclose(Ptr);// SEMPRE TEM QUE FECHAR UM ARQUIVO!!
}

void Exibir(void)
{
	TpFunc F;
	FILE *Ptr = fopen("Func.dat","rb");
	if(Ptr==NULL)
		printf("\nErro de Abertura!\n");
	else
	{  //Com entra lido e sai lido ele não vai ler 2 vezes o final para saber
		fread(&F,sizeof(TpFunc),1,Ptr);
		while(!feof(Ptr))    // feof retorna em 0 e 1 , primeiro le e depois ve se é final de arquivo , feof pega o valor da ultima leitura ( o 0 e 1 significa que se leu a ultima vez um arquivo que não é final ele continua , até ler de fato o final de arquivo ( EOF )
		{
			printf("&F,sizeof(TpFunc),1,Ptr");
			printf("\n Nome: %s",F.Nome);
			printf("\n Salario: %.2f\n"F.Salario);
			fread(&F,sizeof(TpFunc),1,Ptr);
		}
	}
	fclose(Ptr);
}
