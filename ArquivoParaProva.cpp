#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
struct tp_func{
	int matricula;
	float salario;
	char nome[30];
};

int BuscaFunc(FILE *Ptr,int matricula){
	tp_func registro;
	rewind(Ptr); //volta ponteiro ao inicio		 ou 	fseek(Ptr,0,0); -> para começar do inicio
	
	fread(&registro,sizeof(tp_func),1,Ptr); //entra lido
	while(!feof(Ptr) && matricula!=registro.matricula)
		fread(&registro,sizeof(tp_func),1,Ptr); //sai lido

	if(!feof(Ptr))//verifica se nao ta no final do arquivo ou 		/// if(matricula==registro.matricula)
		return ftell(Ptr); /// retorna a posição do ponteiro atualmente (posição - tamanho do byte)

	else
		return -1;
}
void exibir (void){
	tp_func f;
	int i;
		FILE *Ptr =fopen("func.dat","rb");		
		if(Ptr==NULL) ///verifica se o arquivo existe
			printf("\nErro de abertura!\n");
		
		else{
			fread(&f,sizeof(tp_func),1,Ptr);//faz um entra lido e sai lido para nao repetir no final a mesma informação
			while(!feof(Ptr)){
					printf("\nmatricula: [%d] - %s",f.matricula,f.nome);
					printf("\nSalario: %.2f",f.salario);
				fread(&f,sizeof(tp_func),1,Ptr);
			}
		fclose(Ptr);
		}		
getch();
}
char menu(void){
clrscr();
printf("\n # # #	 M E N U 	# # #\n");
printf("\n[ A ] - Cadastro Funcionarios");
printf("\n[ B ] - Exibir Funcionarios");
printf("\n[ C ] - Consultar Funcionarios");
printf("\n[ D ] - Ordenar Funcionarios");
printf("\n[ESC] - Finalizar");
printf("\nOpcao Desejada: \n");
return toupper(getche());
}

int busca_cadastro(int matric,FILE *ptr){
	tp_func r;
	rewind(ptr);
	
	fread(&r,sizeof(tp_func),1,ptr); //entra lido
	while(!feof(ptr) && matric!=r.matricula)
		fread(&r,sizeof(tp_func),1,ptr); //sai lido
	
	if(!feof(ptr))
		return -1;
	else
	 return 1;
	
}

void Alterar()
{
	TpFunc Reg;
	int pos;
	FILE *PtrFunc= fopen("func.dat","rb+"); // Se eu quiser gravar em cima de um arquivo se usa rb+
	printf("\n### Alterar por Matricula###\n");
	printf("Digite a Matricula");
	scanf("%d",&r.matricula);
	
	while(reg.matricula>0)
	{
		pos = BuscaFunc(PtrFunc,reg.matricula);
		if(pos==-1)
			printf("\n Funcionario Não Cadastrado");
		else
		{
			fseek(PtrFunc,pos,0); // fseek volta
			fread(&r,sizeof(tp_func),i,PtrFunc)
			printf("\n*** Detalhes Do Registro***\n");
			printf("Matricula: %d\n",reg.matricula);
			printf("Nome: %s\n",reg.Nome);
			printf("Salario: R$ %.2f\n",reg.Salario);
			
			printf("\n Confirma Alteracao <S/N>\n");
			if(toupper*getche())=='S')
			{
				printf("Novo Nome: ");
				fflush(stdin);
				gets(reg.Nome);
				printf("Novo Salario R$: ");
				scanf("%f",&reg.salario);
				
				fseek(PtrFunc,pos,0);
				fwrite(&reg,sizeof(TpFunc),1,PtrFunc);
				printf("\nRegistro Alterado!\n");
			}
		}
		getch();
		printf("\n\nDigite a Matricula: ");
		scanf("%d",&reg.Matricula)
	}
	fclose(PtrFunc);
}


/*void Ordenar(void)   MUDE O CODIGO DE VETOR PARA ARQUIVO ( QUESTÃO DE PROVAAAA!!!!!! )
{
	int a,b;
	for(a=0;a<TL-1;a++)
		for(b=a+1;b<TL;b++)
		{
			if(V[a]>V[b])
			{
				aux= V[a];
				V[a]= V[b];
				V[b]=aux;
			}
		}
}*/
// EM ARQUIVO

void Ordenar(void)
{
	int a, b;
	TpFunc RA, RB;
	FILE * PtrFunc=fopepn("Func.dat","rb+");
	if(PtrFunc==NULL)
		printf("\nErro de Avertyra!\n");
	else
	{
		fseek(PtrFunc,0,2);
		QtdeReg = ftell(PtrFunc)/sizeof(TpFunc);
		for(a=0;a<QtdeReg-1;a++)
			for(b=a+1;b<QtdeReg;b++)
			{
				fseek(PtrFunc,a*sizeof(TpFunc),0);
				fread(&RA,sizeof(TpFunc),1,PtrFunc);
				
				fseek(PtrFunc,b*sizeof(TpFunc),0);
				fread(&RB,sizeof(TpFunc),1,PtrFunc);
				if(RA.matricula > RB.matricula)
				{
					fseek(PtrFunc,a*sizeof(TpFunc),0);
					fwrite(&RB,sizeof(TpFunc),1,PtrFunc);
					
					fseek(PtrFunc,b*sizeof(TpFunc),0);
					fwrite(&RA,sizeof(TpFunc),1,PtrFunc);
					
				}
			}
	}
}
void cadastro(void){
	tp_func r;
	int pos;

	
	printf("\n*** cadastro de Funcionario ***\n");
	FILE *Ptr=fopen("func.dat","wb");	
	printf("\n Matricula: ");
	scanf("%d",&r.matricula);

pos=busca_cadastro(r.matricula,Ptr);

if(pos==-1)
	printf("Matricula ja existente!");	

 else{
	while(r.matricula>0){
			printf("Nome: ");
			fflush(stdin);
			gets(r.nome);
			
			printf("salario: ");
			scanf("%f",&r.salario);
			fwrite(&r,sizeof(tp_func),1,Ptr);
				
			printf("\n Matricula: ");
			scanf("%d",&r.matricula);
	}		
 }
 fclose(Ptr);
}




/*
void busc_lugar(){
	tp_func r;
	FILE *ptr=fopen("func.dat","wb");
	rewind(ptr);
	int aux;
	
	int matric =r.matricula;
		fread(&r,sizeof(tp_func),1,ptr); //entra lido
	while(!feof(ptr) && r.matricula<=matric){
		
		
		
		aux=registro.matricula;
		registro.matricula=matricula;
		matricula=aux;
		
		
		
		fread(&r,sizeof(tp_func),1,ptr); //sai lido	++
	}
	fclose(ptr);
}
*/

void ordenar(void){
	int pos;
	tp_func aux;
	FILE *ptr=fopen("func.dat","wb");
	rewind(ptr);

	printf("### Ordenação de Funcionarios ###\n");
	///	pos = busca_lugar();
	printf("Ordenacao Completa!");
	getch();
	fclose(ptr);
}


void consultar(void){
	int pos;
	tp_func registro;
	FILE *PtrFuncionario = fopen("func.dat","rb");

	printf("\n ###	Consultar por Matricula	###\n\n");
	printf("digite a matricula desejada: ");
	scanf("%d",&registro.matricula);	///AUXiliar
	while(registro.matricula>0){
		
		pos=BuscaFunc(PtrFuncionario,registro.matricula);
		
		if(pos==-1)
			printf("\nFuncionario nao Cadastrado!\n");
		else{
			
			fseek(PtrFuncionario,pos,0 /*ou SEEK_SET*/);///voltar o ponteiro (reposiciona o ponteiro) parametros: fseek(Ponteiro,deslocamento em bytes, a partir de onde o deslocamento)
			fread(&registro,sizeof(tp_func),1,PtrFuncionario);//sempre usar para ajustar o ponteiro para leitura
			printf("\n*** Detalhes do Registro ***\n\n");
			printf("Matricula: [ %d ]\n",registro.matricula);
			printf("Nome: %s \n",registro.nome);
			printf("Salario: R$ %.2f\n\n",registro.salario);
			
		}
		getch();
		printf("digite outra matricula desejada: \n");
		scanf("%d",&registro.matricula);
	}
	fclose(PtrFuncionario);
}

int main(void){
	char resp;
	do{
		switch(resp){
			case 'A':cadastro();
					 break;
			case 'B':exibir();
					 break;
			case 'C':consultar();
					 break;
			case 'D':ordenar();
					 break;			
		}
		
		resp=menu();
	}while(resp!=27);
return 0;
}
