#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define tf 10

// Menuzinho com borda  CLEAN
char CriarMenu(void)
{
	clrscr();
	int li , ci , lf , cf;
	li = ci = 1;
	lf = 12;
	cf = 70;
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
	for(int aux=ci+1;aux<cf;aux++)
	{
		gotoxy(aux,li);
		printf("%c",205);
		//Sleep(150);
		gotoxy(aux,lf);
		printf("%c",205);
		//Sleep(150);
	}
	for(li=li+1;li<lf;li++)
	{
		gotoxy(ci,li);
		printf("%c",186);
		//Sleep(150);
		gotoxy(cf,li);
		printf("%c",186);
		//Sleep(150);
	}
	gotoxy(30,2);
	printf("##Opcoes##");
	gotoxy(10,3);
	printf("[A] Ler Vetor");
	gotoxy(10,4);
	printf("[B] Exibe Vetor");
	gotoxy(10,5);
	printf("[C] Frequencia -- Ex.01");
	gotoxy(10,6);
	printf("[D] ConsultarElemento");
	gotoxy(10,7);
	printf("[E] Ordenar Vetor");
	gotoxy(10,8);
	printf("[F] Excluir Elemento");
	gotoxy(10,9);
	printf("[ESC] Sair");
	gotoxy(10,10);
	printf(" OPCAO : ");
	
	
	
	return toupper(getche());
	
}
// Exibir vetor
void ExibirVetor (int vetor[tf],int tl)
{
	if(tl == 0)
		printf("\n Vetor Vazio!!!");
	else
		for(int i = 0; i < tl ; i++)
			printf("\nVetor na pos [%d]: %d ",i,vetor[i]);
	
	
	
	getch();
}


// Por valor Ã© sem o & e referencia usa o &
void Frequencia (int vetor[tf],int tl,int &valor,int &QtdeVezes)
{
	QtdeVezes =0;
	for(int i=0;i<tl;i++)
	{
		int Qtde = 0;
		for(int j=i;j<tl;j++)
		{
			if(vetor[i]==vetor[j])
			{
				Qtde++;
			}
			
		}
	if (Qtde > QtdeVezes )
	{
		QtdeVezes = Qtde;
		valor = vetor[i];
	}	
}
}
// TODO VETOR Ã‰ PASSADO POR REFERENCIA , OU SEJA NÃƒO PRECISA DE & , SE COLOCAR VAI DAR ERROR !!!!
void LeValor (int vet[tf],int &tl)
{
	int aux;
	printf("\nDigite um numeros no vetor: ");
	printf ("Vetor[%d]: ",tl);
	scanf("%d",&aux);
	while(tl<tf && aux > 0)
	{
		vet[tl] = aux;
		
		tl++;
		if(tl>=tf)
		{
			aux=0;
		}
		else
		{
			printf("\nDigite um numeros no vetor: ");
			printf ("Vetor[%d]: ",tl);
			scanf("%d",&aux);
		}
	}
}
// Consulta Exaustiva Ã© ver 1 por 1
int BuscaExaustiva(int vetor[tf],int tl,int valor)
{
		int i;
			for (i=0; i < tl && valor != vetor[i];i++);
			
			
			if ( i > tl)
			{
				return -1;
			}
			else
			{
				return i;
			}
		
}
void OrdenarVetor(int vetor[tf],int tl)
{
    int i , j,aux;
    
    printf("\nIremos ordenar o vetor em ordem crescente!!");
    for (i = 0 ; i < tl - 1 ; i++ )
        for(j=i+1;j<tl;j++)
        {
            if(vetor[i]>vetor[j])
            {
               aux = vetor[i];
               vetor[i] = vetor[j];
               vetor[j] = aux;
            }
        }
    printf("\n Vetor Ordenado com sucesso!");
    getch();
    
    
}

// Realizar uma consulta para saber se o numero que deseja esta la
void Consultar (int Vet[tf],int tl)
{
	int  pos , elemento;
	printf("\n ## Consultar no Vetor ##");
	if (tl == 0) printf("\nVetor Vazio!\n");
	else{
		printf("\nConsultar por: ");
		scanf ("%d",&elemento);
		while(elemento>0)
		{
			pos = BuscaExaustiva(Vet,tl,elemento);
			if(pos == -1)
				printf("\n O numero digitado nao foi encontrado");
			else
				printf("\nElemento [%d] encontrado na pos [%d]");
				
			
		getch();
		printf("\n\nConsultar por: ");
		scanf("%d",&elemento);
		}
	}
}
// Essa funÃ§Ã£o ira excluir o item que vocÃª buscou em consulta
void ExcluirItem(int vetor[tf],int &tam)
{
    int pos , elemento;
    printf("\n ## Excluir item ##\n");
    
    printf("\nConsultar por: ");
	scanf ("%d",&elemento);
	while(elemento>0)
		{
			pos = BuscaExaustiva(vetor,tam,elemento);
			if(pos == -1)
				printf("\n O numero digitado nao foi encontrado");
			else{
			    while(pos < tam)
				    {
				        vetor[pos] = vetor[pos+1];
				        pos++;
				    }
				tam--;
			}
		getch();
		printf("\n\nConsultar por: ");
		scanf("%d",&elemento);
		}
    
}
void SubConj(int va[tf],int tla,int vb[tf],int tlb,int vc[tf*2],int &tlc)
{
	int i;
	tlc=0;
	for(i=0;i<tla;i++)
		if(BuscaExaustiva(vb,tlb,va[i])==-1)
			if(BuscaExaustiva(vc,tlc,va[i])==-1)
			{
				vc[tlc]=va[i];
				tlc++;
			}
		printf("\n Subtração Efetuada!\n");
		getch();
}
void InterConj(int va[tf],int tla,int vb[tf],int tlb,int vc[tf*2],int &tlc)
{
	int i;
	tlc=0;
	for(i=0;i<tla;i++)
		if(BuscaExaustiva(vb,tlb,va[i])!=-1) // Se achou!
			if(BuscaExaustiva(vc,tlc,va[i])==-1)  // Se não achou!
			{
				vc[tlc]=va[i];
				tlc++;
			}
		printf("\n Subtração Efetuada!\n");
		getch();
}
// Fazer um executavel para fazer tudo para o main
void Executar(void)
{
	int V1[tf],V2[tf] ,tam1=0,tam2=0 ,Qtde,NrMais,num,tam3=0,V3[tf*2];
	char op;
	do
	{
		op = CriarMenu();
		switch(op)
		{
			case 'A': if(tam1==tf) printf("\nVetor Cheio\n");
						else
						{  clrscr();
							LeValor(V1,tam1);
							printf("\nElementos Inseridos\n");
						}
					getch();
					break;
			
			case 'B': clrscr();ExibirVetor(V1,tam1);
					  break;
			
			
			case 'C': clrscr();if (tam1 == 0) printf("\nVetor Vazio , nao sera possivel calcular a frequencia");
					  else
					  {
					  	Frequencia(V1,tam1,NrMais,Qtde);
					  	printf("\nNÃºmero de maior frequencia: %d\nQuantidade de vezes: %d",NrMais,Qtde);
					  }
					getch();
					break;
			case 'D': clrscr(); if (tam1 == 0) printf("\nVetor Vazio");
						else
							Consultar(V1,tam1);
							break;
			case 'E': clrscr(); if (tam1 == 0) printf("\nVetor Vazio");
								else
								{
									OrdenarVetor(V1,tam1);
								}
			case 'F': clrscr(); if (tam1 == 0) printf("\nVetor Vazio");
								else
								{
									ExcluirItem(V1,tam1);
								}
			case 'G': clrscr(); printf("\nExec.5a\n");
								printf("\n Vetor 1:\n");
								LeValor(V1,tam1);
								printf("\n Vetor 1:\n");
								LeValor(V2,tam2);
								SubConj(V1,tam1,V2,tam2,V3,tam3);
								clrscr();
								printf("\n Resultado Subtração:\n");
								ExibirVetor(V3,tam3);
								break;
			case 'H': clrscr();printf("\nExec.5b\n");
								printf("\n Vetor 1:\n");
								LeValor(V1,tam1);
								printf("\n Vetor 1:\n");
								LeValor(V2,tam2);
								SubConj(V1,tam1,V2,tam2,V3,tam3);
								clrscr();
								printf("\n Resultado Intersecção:\n");
								ExibirVetor(V3,tam3);
								break;
			
		}
		
	}while (op!=27);
}
int main (void)
{
	Executar();
	return 0;
}
