
/************************************************************************
 *          Universidad de las Fuerzas Armadas ESPE                     *
 * Tema de Proyecto: Listas simples con clases             *
 * Autores:  Cristian Barragan *
 * Fecha de inicio: 17/12/2017	Fecha de modificacion: 1/12/2017       *
 * Docente: Ing. Fernando Solis                                         *
 *                                                                      *
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "listasSimples.h"
void gotoxy(int x,int y);
void cambiarcolor(int X);
int menu_seleccion(const char menu[],  int n_opciones);
int pasaCadenaAEntero( char *cadena );
int pasaCadenaAEntero( char *cadena )
{

 int longCadena=strlen(cadena), numero=0, i;

     for( i=0; i<longCadena; i++ )
     {
     numero *= 10;
     numero += *(cadena+i)-48;
     };

     return numero;
};


void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


void cambiarcolor(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

int menu_seleccion(const char menu[],  int n_opciones)
{
	int seleccion=1,tecla=0;
	bool repite=true;

	char caracter;
	do
	{
	    cambiarcolor(8);
		system("cls");
		//system("color 3F");
		gotoxy(8,3+seleccion);
		cambiarcolor(7);


		if (seleccion==1)
        {   cambiarcolor(240);
             gotoxy(15,4);
		  printf("INGRESO POLACA         ");
		  cambiarcolor(9);
		  gotoxy(15,5);
		  printf("SALIR                  ");
        }
        if (seleccion==2)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO POLACA         ");
		  cambiarcolor(240);
		  gotoxy(15,5);
		  printf("SALIR                  ");
        }

		do
		{
			tecla=getch();
		}while((tecla!=72)&&(tecla!=80)&&(tecla!=13)&&(tecla!=42)&&(tecla!=59));
		switch(tecla)
		{
			case 72:{
				seleccion--;
				if(seleccion<1)
				{

					seleccion=n_opciones;
				}
				break;
				}
			case 80:{
				seleccion++;
				if(seleccion>n_opciones)
			 	{

					seleccion=1;
				}
				break;
				}
			case 13:{
				repite=false;
				break;
				}
			case 59:
				{
					system("cls");
					FILE *datos=fopen("Ayuda.txt","rb");
					while(feof(datos)==0)
					{
						caracter=fgetc(datos);
						printf("%c",caracter);
					}
					getch();
					fclose(datos);
					break;
				}
		}
	}while(repite);
	return seleccion;
}


int main()
{
    ListaSimple cola;
	bool repite=true;
	const char *menu="Menu principal";
	int opcion;
	int n_opciones=2;
	char *cad;
    int val1, val2;
    cad= (char *)calloc(20,sizeof(char));

    do
    {
        opcion=menu_seleccion(menu,n_opciones);

        switch (opcion)
        {
        case 1:
            {
                system("cls");
                printf("*********HA ELEGIDO INGRESO **************\n\n");

                        do{
                                 scanf( "%s", cad );
                                 switch( *(cad+0) )
                                 {
                                     case '+':
                                         {
                                             val1=cola.borrarprimero();
                                             val2=cola.borrarprimero();
                                             cola.insertar((val1 + val2));
                                             break;
                                         }

                                     case '-':
                                         {
                                             val1=cola.borrarprimero();
                                             val2=cola.borrarprimero();
                                             cola.insertar((val1 - val2));
                                             break;
                                         }

                                     case '*':
                                         {
                                             val1=cola.borrarprimero();
                                             val2=cola.borrarprimero();
                                             cola.insertar((val1 * val2));
                                             break;
                                         }



                                     case '/':
                                         {
                                             val1=cola.borrarprimero();
                                             val2=cola.borrarprimero();
                                             cola.insertar((val1 / val2));
                                             break;
                                         }

                                     case '=':
                                         {
                                             printf( "\nEl resultado es: %i\n\n", cola.borrarprimero()  );
                                             cola.listaLiberaRam();
                                             getch();
                                             break;
                                         }

                                     default:
                                         {
                                             cola.insertar( pasaCadenaAEntero(cad) );
                                             break;
                                         }


                                     };

                           } while( cad[0] != '=' &&cad[0]!=32 );

                break;
            }


        case 2:
            {
                repite=FALSE;
                break;
            }
        }

    }
    while(repite);


}

