#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// MATÉRIA SOBRE O DOS , MODIFICANDO O DOS E MEXENDO COM AS POSIÇÕES DAS PALAVRAS
	char nome[40],tecla;
	int tl=0,x=0,y=1,linha=1,coluna=1;
	//OBJETIVO É FAZER MOSTRAR A TABELA ASCII TROCANDO AS CORES
	for(tl=0;tl<257;tl++)
	{	
		if(y==x)
			y++;
		if(x==15)
			x=0;
		if(y==7)
			y=0;
		if(coluna==24)
		{
			linha=linha + 7;
			coluna = 1;
		}
		
		
		textcolor(x);
		textbackground(y);
		gotoxy(coluna,linha);
		printf("%d -- %c\n",tl,tl);
		coluna++;
		tl++;
		y++;
		x++;
	}
	
	
	
	
	
		/*gotoxy(,);
		tecla=getch();
		printf("NR.? %d \t Tecla? %c\n",tecla,tecla);
		

		textbackground(4); 
		clrscr(); 
		textcolor(GREEN); //COLOCAR COR NO TEXTO   0(BLACK)..15(WHITE)
		gotoxy(10,7); //Pega a posição da linha e coluna ( X e Y ) GO TO X Y Primeiro é coluna e depois a linha gotoxy(coluna,linha)
		printf("Digite um Nome: ");
		gotoxy(10,8);
		fflush (stdin);
		textbackground(7); //0..7 ESSE CÓDIGO SERVE PARA MARCAR , SUBLINHAR , MARCA TEXTO
		gets(nome);
		textbackground(0);
		clrscr(); // Função própria do C ele pinta a tela com a cor que eu definir
		return 0;*/
	
	
	
	
}
