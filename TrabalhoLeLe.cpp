#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>
#define TF 20

void MenuPrincipal(void);
void Moldura (int ci, int li, int cf, int lf, int cort, int corf);
void formulario(void);

int main(void)
{
	formulario();
}


void Moldura (int ci, int li, int cf, int lf, int cort, int corf){
	
	textcolor(cort);
	textbackground(corf);
	
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
int i;
	for(i=ci+1;i<cf;i++){
		gotoxy(i,li);
		printf("%c",205);
		gotoxy(i,lf);
		printf("%c",205);
	}
	
	for(i=li+1;i<lf;i++){
		gotoxy(ci,i);
		printf("%c",186);
		gotoxy(cf,i);
		printf("%c",186);		
	}
	
	textcolor(7);
	textbackground(0);	
}

void formulario(void){
	
	system("cls");
	Moldura(1,2,90,29,10,5); // BORDA
		gotoxy(27,3);
		textcolor(15);
		printf("[#  # # MERCEARIA DO SR.ZE # # #]");
	Moldura(2,3,89,5,14,0); // Titulo
	Moldura(2,6,28,28,12,7);  // Menu Principal
	MenuPrincipal();
	Moldura(29,26,89,28,11,4); // Mensagem
		gotoxy(30,27);
		textcolor(4);
		printf("Mensagem: ");
	Moldura(29,6,89,25,9,6); // Sub Menu
}

void MenuPrincipal(void){
	textcolor(15);
	gotoxy(3,7);
	printf("[# # M E N U # #]");
	gotoxy(3,9);
	printf(" [ A ] Produtos ");
	gotoxy(3,11);
	printf(" [ B ] Gerenciamento ");
	gotoxy(3,13);
	printf(" [ C ] Emitir Relatório ");
	gotoxy(3,19);
	printf("[ESC] S A I R");

}

