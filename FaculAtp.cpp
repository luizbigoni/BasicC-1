#include <stdio.h>
#include <string.h>
#include <conio2.h> //Conio2.h ele contem o getch 
#include <ctype.h>
#include <stdlib.h>

int main ()
{
	int i=0,j,tl=0,x;
	char vet[10][100],Op,copyname[100];
	
	do
	{
		system("cls"); // esse comando limpa a tela , reformata a tela
		
        printf("# # # Menu # # #\n");
		printf("[A] Inserir Nomes em uma Lista\n");
		printf ("[B] Exibir a Lista\n[C] Ordenar a Lista\n[D] Excluir Nomes da Lista até se pressionar <ENTER>\n[ESC] Sair\n");

		//scanf("%c",&Op); //SCANF NÃO PEGA SIMBOLO PARA ISSO USAMOS O getch
        //getche mostra na tela a letra pressionada e o getch não
		//Op = toupper(getch()); posso fazer desta maneira também para pegar maiúsculo
		Op = getche();
		
		/*
		switch (toupper(Op)  >>>> toupper vai tacar o que receber no " Op = getch()
								  e vai tacar para maiúsculo
		{
			case ' A ':
							break;
			case ' B ': 
							break;
		}
		*/
		
		
		if(Op =='A'||Op =='a')
		{	
			printf("\nDigite o nome da pessoa que deseja na lista\n");
			gets(vet[i]);
			
			// strlen é usado para contar até o \0 no vetor , se der 0 é pq não tem nada ou seja apertei <ENTER>
			while(strlen(vet[i])>0&&i<10)
			{   
                for(j=0;strlen(vet[i])>0&&stricmp(vet[i],vet[j])!=0&&j<i;j++);
                
                if(stricmp(vet[i],vet[j])==0)
                {
                    printf("Nome já existente , por favor digitar outro nome\n");
                }
                else
                {
				    printf("\nDigite o nome da pessoa que deseja na lista\n");
				    i++;
                    tl++;
				    fflush(stdin);
				    gets(vet[i]);
                }
			
			}
			
			
		}
		if(Op=='b'||Op=='B')
		{
			for(i=0;strlen(vet[i])>0;i++)
				printf("\nNome: %s\n",vet[i]);
			getch(); // aqui ele serve como uma parada para não resetar a tela
		}
		if(Op=='c'||Op=='C')
		{
            for(i=0;i<tl && strlen(vet[i])>0;i++)
            { 
                for(j= i + 1;j<tl && strlen(vet[j])>0;j++)
                { 
                    x = stricmp(vet[i],vet[j])
                    if(x>0)
                    {
                        strcpy(copyname,vet[i]);
                        vet[i]== vet[j];
                        vet[i++] == copyname;
                    }
                        
                }        
            }
			printf("Ordenado de forma crescente com sucesso ! \n")
            getch();
			
		}
		if(Op=='d'||Op=='D')
		{
			printf ("Qual item você deseja excluir");
            scanf ("%d",&x);
            if(x<tl&&strlen(vet[x+1])>0)
            {
                for(x=x;x<tl-1&&strlen[x+1];x++)
                {
                    vet[x]=vet[x+1];
                }
                printf("Item excluído com sucesso\n");
                tl--;
            }
            else
            if (strlen(vet[x+1])>0)
                {
                    vet[x]=vet[x+1];
                }
                printf("Item excluído com sucesso\n");
                tl--;
			else{
                printf("Não foi possível deletar poís o número do item não existe\n");
            }

            getch();
		}
		
		
		
	}while(Op != 27);
	
	
	
	
	
	
	return 0;
}
