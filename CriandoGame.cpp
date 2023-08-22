#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <windows.h>

int main()
{	//char 
	int ci,cf,li,lf,aux,x,aux2;
	
	printf("Digite a coluna inicial[1...80]\n");
	printf("Digite a linha inicial[1...25]\n");
	printf("Digite a coluna final[1...80]\n");
	printf("Digite a linha final[1...25]\n");
	scanf("%d%d%d%d",&ci,&li,&cf,&lf);
	clrscr();
	
	//Sleep serve como um delay
	//textcolor(2);
	//textbackground(2);
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
	//textcolor(2);
	//textbackground(2);
	
	
	for(aux=ci+1;aux<cf;aux++)
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
	aux=cf/2;
	aux2=lf/2;
	gotoxy(aux,aux2);
	printf("%c",4);
	do
	{
		fflush(stdin);
		x = getch();
		
		//if(x==24)//cima
		if(x==72)
		{	
			aux2-=1;
			if(aux2==li)
			{
				printf("%c",205);
				gotoxy(aux,aux2+1);
				printf("%c",0);
				aux2=aux2+lf-2;
				gotoxy(aux,aux2);
				printf("%c",4);
				
			}
			else{
			
			//aux2-=1;
			gotoxy(aux,aux2+1);
			printf("%c",0);
			gotoxy(aux,aux2);
			printf("%c",4);
		}
		}
		
		//if(x==25)//baixo
		if(x==80)
		{
			aux2+=1;
			if(aux2==lf)
			{
				printf("%c",205);
				gotoxy(aux,aux2-1);
				printf("%c",0);
				aux2=aux2-lf+2;
				gotoxy(aux,aux2);
				printf("%c",4);
				
			}
			else{
			
			gotoxy(aux,aux2-1);
			printf("%c",0);
			gotoxy(aux,aux2);
			printf("%c",4);
			}
		}
		
		//if(x==26)//esquerda
		if(x==75)
		{
			aux-=1;
			if(aux==ci)
			{
				
				printf("%c",186);
				gotoxy(aux+1,aux2);
				printf("%c",0);
				aux=aux+cf-2;
				gotoxy(aux,aux2);
				printf("%c",4);
				
			}
			else{
			
			gotoxy(aux+1,aux2);
			printf("%c",0);
			
			gotoxy(aux,aux2);
			printf("%c",4);
		}
		}
		//if(x==27)//direita
		if(x==77)
		{
			aux+=1;
			if(aux==cf)
			{
				printf("%c",186);
				gotoxy(aux-1,aux2);
				printf("%c",0);
				aux=aux-cf+2;
				gotoxy(aux,aux2);
				printf("%c",4);
				
			}
			else
			{
			
			gotoxy(aux-1,aux2);
			printf("%c",0);
			gotoxy(aux,aux2);
			printf("%c",4);
		}
		
			
		}
		
		
	}while(x!=27);
	
	
	x = getch();
	return 0;
}
