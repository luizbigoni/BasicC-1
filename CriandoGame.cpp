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
		if(x=='w')
		{
			gotoxy(cf,lf--);
			printf("%c",4);
			lf++;
			gotoxy(cf,lf);
			printf("%c",0);
			gotoxy(cf,lf++);
		}
		
		//if(x==25)//baixo
		if(x=='s')
		{
			gotoxy(cf,lf++);
			printf("%c",4);
			lf--;
			gotoxy(cf,lf);
			printf("%c",0);
			gotoxy(cf,lf--);
		}
		
		//if(x==26)//esquerda
		if(x=='a')
		{
			gotoxy(cf--,lf);
			printf("%c",4);
			cf--;
			gotoxy(cf,lf);
			printf("%c",0);
			gotoxy(cf--,lf);
		}
		//if(x==27)//direita
		if(x=='d')
		{
			gotoxy(cf++,lf);
			printf("%c",4);
			cf++;
			gotoxy(cf,lf);
			printf("%c",0);
			gotoxy(cf++,lf);
			
		}
		
		
	}while(x!=27);
	
	
	x = getch();
	return 0;
}
