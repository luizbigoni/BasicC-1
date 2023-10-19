#include <stdio.h>




struct TpPessoa{
	int Matricula;
	char Nome[30];
};
// EOF fim do arquivo , USADO MAIS PARA EXIBIR
// FILE Arquivo
void Cadastro(void)  // Se o arquivo fosse aberto seria (FILE *Ptr)
{
	FILE *PtrArq=fopen("Pessoas.dat","wb"); // wb = write bit
	TpPessoa R;
	printf("\n Matricula");     
	scanf("%d",&R.Matricula);
	while(R.Matricula>0)
	{
		printf("\n Nome: ");fflush(stdin);
		gets(R.Nome);
		
		fwrite(&R,sizeof(TpPessoa),1,PtrArq); //sizeof conta os bits que existe na sua estrutura E o fwrite vai enviar oq estiver na memoria
		
		//fwrite sempre precisa da ( estrutura , contador , vezes , ponteiro)
		
		printf("\n Matricula");     
		scanf("%d",&R.Matricula);	
	}
	
}

int main(void)
{
	Cadastro();
	
	
	
	return 0;
}
