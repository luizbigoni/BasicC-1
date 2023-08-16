#include <stdio.h>
#include <string.h>
#include <conio2.h> //Conio2.h ele contem o getch 
#include <ctype.h>
#include <stdlib.h>

int main ()
{
	int i=0,j,tl=0,x,opi,tl2=0,tl3=0;
	char vet[10][100],vet2[10][100],vet3[20][100],Op,copyname[100],AuxNome[100],Letra;

	do
	{
		system("cls"); // esse comando limpa a tela , reformata a tela

        printf("# # # Menu # # #\n");
		printf("[A] Inserir Nomes em uma Lista\n");
		printf ("[B] Exibir a Lista\n[C] Ordenar a Lista\n[D] Excluir Nomes da Lista ate se pressionar <ENTER>\n[ESC] Sair\n");
		printf ("[E] Inserir Nomes na Lista 2\n");
		printf ("[F] Fazer a inserção na lista3\n");

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
			if(tl<10)
			{
				printf("\nDigite o nome da pessoa que deseja na lista\n");
				gets(AuxNome);

				// strlen é usado para contar até o \0 no vetor , se der 0 é pq não tem nada ou seja apertei <ENTER>
				while(strlen(AuxNome)>0)
				{   
                	for(i=0;i<tl&&stricmp(AuxNome,vet[i])!=0;i++);

    				while(tl<10&&stricmp(AuxNome,vet[i])==0)
                		{
                		printf("Nome ja existente , por favor digitar outro nome\n");
                		gets(vet[i]);
                		
                		}
                	if(stricmp(AuxNome,vet[i])!=0)
                	{
				    	
				    	fflush(stdin);
				    	strcpy(vet[tl],AuxNome);
						i++;
                    	tl++;
				    	
                	}
                	printf("\nDigite o nome da pessoa que deseja na lista\n");
					gets(AuxNome);

			    }
			}else
				if(tl==10||tl>10)
				{
					printf("A lista de nomes ja está cheia!!");
					getch();
				
				}
		}
			if(Op =='E'||Op =='e')
		{	
			if(tl2<10)
			{
				printf("\nDigite o nome da pessoa que deseja na lista\n");
				gets(AuxNome);

				// strlen é usado para contar até o \0 no vetor , se der 0 é pq não tem nada ou seja apertei <ENTER>
				while(strlen(AuxNome)>0)
				{   
                	for(i=0;i<tl&&stricmp(AuxNome,vet2[i])!=0;i++);

    				while(tl<10&&stricmp(AuxNome,vet2[i])==0)
                		{
                		printf("Nome ja existente , por favor digitar outro nome\n");
                		gets(vet2[i]);
                		
                		}
                	if(stricmp(AuxNome,vet2[i])!=0)
                	{
				    	
				    	fflush(stdin);
				    	strcpy(vet2[tl],AuxNome);
						i++;
                    	tl2++;
				    	
                	}
                	printf("\nDigite o nome da pessoa que deseja na lista\n");
					gets(AuxNome);

			    }
			}else
				if(tl==10||tl>10)
				{
					printf("A lista de nomes ja está cheia!!");
					getch();
				
				}
			
		}
		if(Op=='b'||Op=='B')
		{	if(tl==0)
				printf("A lista está vazia");
			else
			{
				for(i=0;i<tl&&strlen(vet[i])>0;i++)
					printf("\nNome[%d]: %s\n",i,vet[i]);
				getch(); // aqui ele serve como uma parada para não resetar a tela
			}
		}
		if(Op=='c'||Op=='C')
		{
            for(i=0;i<tl && strlen(vet[i])>0;i++)
               for(j= i + 1;j<tl && strlen(vet[j])>0;j++)
            	{ 
                    if(stricmp(vet[i],vet[j])>0)
                    {
                        strcpy(copyname,vet[i]);
                        strcpy(vet[i],vet[j]);
                        strcpy(vet[j],copyname);
                    }

                }        
            
			printf("Ordenado de forma crescente com sucesso ! \n");
            getch();

		}
		if(Op=='d'||Op=='D')
		{	while(tl>0)
			{
				for(i=0;i<tl&&strlen(vet[i])>0;i++)
					printf("\nNome[%d]: %s\n",i,vet[i]);
				printf ("Qual nome da lista voce deseja excluir?\n");
            	scanf ("%d",&x);
            	printf("Tem certeza que deseja excluir esse nome da lista?(1-Sim/2-Nao)\n");
            	scanf("%d",&opi);
            	if(opi==1&&x<tl&&strlen(vet[x+1])>0)
            	{
                	for(;x<tl-1&&strlen(vet[x+1])>0;x++)
                	{
                    	strcpy(vet[x],vet[x+1]);
                	}
                	printf("Item excluido com sucesso\n");
                	tl--;
                	vet[x+1][0]='\0';
            	}
            	else
            	if (x<tl&&strlen(vet[x+1])==0)
            	{
               
                    vet[x][0]='\0';
                
                	printf("Item excluido com sucesso\n");
                	tl--;
                
        		}
        		else
        			if(opi==2)
        				printf("Exclusao cancelada!\n");
				else
                	printf("Não foi possível deletar poís o número do item não existe\n");
        	}
        	

            getch();
		}
		//Inserção , Buscando atravez da letra    OBS: PRECISA ARRUMAR AINDA
		if(Op == 'f' || Op == 'F')
		{
			if(tl3<20)
			{
				printf("\nDigite a letra que deseja realizar inserção\n")	;
				fflush(stdin);
				Letra= toupper(getche());
				i=0;
				j=0;
				//Lista 1
					while(i<tl&&Letra != vet[i][0])
						i++;
					
					if(Letra == vet[i][0])
					{
						while(j<tl3&&stricmp(vet[i],vet3[j])!=0)
							j++;
						if(j<tl3&&stricmp(vet[i],vet3[j])==0)
						{
							strcpy(vet[i],vet3[j]);
							tl3++;
						}
						
					}
					else
					{
						printf("\nNenhum nome com essa Letra na Lista 1\n");
						getch();
					}
					i=0;
					j=0;
					//Lista 2
					while(i<tl&&Letra != vet2[i][0])
						i++;
					if(Letra == vet2[i][0])
					{
						while(j<tl3&&stricmp(vet2[i],vet3[j])!=0)
							j++;
						if(j<tl3&&stricmp(vet2[i],vet3[j])==0)
						{
							strcpy(vet2[i],vet3[j]);
							tl3++;
						}
						
					}
					else
					{
						printf("\nNome nao encontrado na Lista 2\n");
						getch();
					}
				
			}
		}



	}while(Op != 27);






	return 0;
}
