#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED
#include <iostream>
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include"imagen.h"
using namespace std;

void imagen()
{
    hConWnd = GetConsoleWndHandle();
    if (hConWnd)
    {
    	//codifica bit a bit
        BCX_Bitmap("LOGO.bmp",hConWnd,0,0,120,0,0);

//        system("pause>nul");
//        getchar();
    }
    //system("cls");
}
char *solo_letras(char A[])
{
	char letra;
	int i=0,l=0;
	i=0;
		fflush(stdin);
		letra=getch();
		while(letra!=13 && i<50)
		{
		fflush(stdin);
		if(letra!=8)
			{
				if((letra>=65 && letra<=90)||(letra>=97 && letra<=122)||(letra==32))
				{
					if(letra!=13)
					{
						printf("%c",letra);
						fflush(stdin);
						A[i]=letra;
						i++;
					}
				}
			}
			else
			{
				l=strlen(A);
				if(l>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					A[l-1]='\0';
					i--;
				}
			}
			letra=getch();
		}
		A[i]='\0';
	return A;
}
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
inline int SetColor(const int foreground, const int background)
{

int Color = foreground + (background * 16);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, Color);

return 0;
}
DWORD WINAPI merlin(LPVOID LPARAM)
{
    system("WinAppMSAgentsManagement.exe");
}
void vaciar( char *a)
{
    int i;
    for (i=0;i<50;i++)
    {
        a[i]='\0';
    }
}
char *leerfichero(char palabraIng[70] )
{
    int i;
    FILE *f;
        f=fopen("datos.txt","r");

        for (i=0;!feof(f);i++)
        {
            vaciar(palabraIng);
            fgets(palabraIng,70,f);
        }
     fclose(f);

     return palabraIng;
}

char *opcionesRecuperar(char recuperaArc[])
{
     int i;
     int opcion;
    FILE *f;
        f=fopen("horarios.txt","r");

        for (i=0;!feof(f);i++)
        {
            vaciar(recuperaArc);
            fgets(recuperaArc,50,f);
            printf("->>%d  %s",(i+1), recuperaArc);

        }
     fclose(f);

     printf("\n ESCOJA EL ARCHIVO QUE DESEA RECUPERAR:  ");
    scanf("%d",&opcion);
    FILE *c;
        c=fopen("horarios.txt","r");

        for (i=0;i<opcion;i++)
        {
            vaciar(recuperaArc);

            fgets(recuperaArc,50,c);
            printf("->>%d  %s",(i+1), recuperaArc);

        }
     fclose(c);
    return recuperaArc;
}
int menuPrincipal2()
{
	system("color 03");
	int cont=1;
    long x=0,y=0;
    gotoxy(3, 100);
	printf("F12 AYUDA");
	const char *opciones[]={"INGRESO DE DATOS   ","TRADUCIR DATO      ","IMPRIMIR COLAS     ","BACKUP              ","SALIR             "}; //OPCIONES
	int n=5; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++){
			gotoxy(i,10);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=10;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}

		do{
                fflush(stdin);
		//imprime titulo
		gotoxy(25,0); printf("MENU TRADUCTOR DE PALABRAS\n\n");

		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);

		do{
                fflush(stdin);
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13&& tecla!=134);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
			case 134:

			    system("cls");

                break;
		}
	}while(repite==true);

	return selec;

}

int menubackip()
{
    system("color 03");
	int cont=1;
	const char *opciones[]={"    CREAR    ","     RECUPERAR     "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++)
        {
			gotoxy(i,8);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=7;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("SELECCIONE LA OPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;

		}
	}while(repite==true);

	return selec;
}


int menuSiNo()
{
    system("color 03");
	int cont=1;
	const char *opciones[]={"    SI     ","     NO     "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++)
        {
			gotoxy(i,8);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=7;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("SELECCIONE LA OPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite==true);

	return selec;
}

int menuPrincipal()
{
        system("color 03");
	int cont=1;
    long x=0,y=0;
    gotoxy(50, 20);
    printf("F12 AYUDA");
	const char *opciones[]={"INGRESO DE DATOS   ","TRADUCIR DATO      ","IMPRIMIR COLAS     ","BACKUP              ","SALIR             "}; //OPCIONES
	int n=5; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;


	for (int i=1;i<=67;i++){
			gotoxy(i,10);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=10;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("MENU TRADUCTOR DE PALABRAS\n\n");

		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);

    while((!GetAsyncKeyState(MOUSEEVENTF_MOVE)))
		{

            POINT mouse;
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {

                GetCursorPos(&mouse);
                x=mouse.x;
                y=mouse.y;
               // printf("La posicion del mouse es %d ; %d \n", mouse.x,mouse.y);
                //Sleep(3000);
            }
            fflush(stdin);
            //tecla=getch();

		}




        if((y>=60 && y<=70) && (x>=150 && x<=286))
        {
            return 1;
        }
        else if ((y>=70 && y<=80) && (x>=150 && x<=286))
        {
            return 2;
        }
        else if ((y>=80 && y<=90) && (x>=150 && x<=286))
        {
            return 3;
        }
        else if ((y>=90 && y<=100) && (x>=150 && x<=286))
        {
            return 4;
        }


}
long int  insertar (long int val, char *mensaje)
{
    int aux;
    printf ("%s",mensaje);
    do
    {
        fflush(stdin);
        printf (": [ ]\b\b");
        aux=scanf ("%d",&val);
        if (aux==1 ) {
            if (val >=0)
            {

            }
            else
            {
                printf("\n Ingreso no valido");
                aux=0;

            }

        }

        else
        {
            printf ("\n Ingreso no valido");
        }
    }while (aux==0&& val <0);

return val;

}
int verificarCantidad(int cont,int datoPosicion)
{
    if(datoPosicion> cont || datoPosicion == 0)
    {
        return 0;
    }
    else
        return 1;
}



#endif // FUNCIONES2_H_INCLUDED
