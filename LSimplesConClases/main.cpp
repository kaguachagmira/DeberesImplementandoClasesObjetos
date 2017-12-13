
/************************************************************************
 *          Universidad de las Fuerzas Armadas ESPE                     *
 * Tema de Proyecto: Listas simples con clases             *
 * Autores: Kevin Guachagmira, Cristian Barragan,  Jonathan Altamirano  *
 * Fecha de inicio: 10/12/2017	Fecha de modificacion: 13/12/2017       *
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
int solo_numeros(int l);
int  ingreso (int val);
void gotoxy(int x,int y);
void cambiarcolor(int X);
int menu_seleccion(const char menu[],  int n_opciones);
int solo_numeros(int l)
{
	char caracter;
	int i=0;
		i=0;
		fflush(stdin);
		caracter=getch();
		while(caracter!=13)
		{
		fflush(stdin);
		if(caracter!=8)
			{
				if((caracter>=48)&&(caracter<=57))
				{
					if(caracter!=13)
					{
						printf("%c",caracter);
						fflush(stdin);
						l=(l*10)+(caracter-48);
						i++;
					}
				}
			}
			else
			{
				if(i>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					l=(l/10);
					i--;
				}
			}
			caracter=getch();
		}
	return l;
}

int  ingreso (int val)
{
    int aux;
    do
    {
         fflush(stdin);

    aux=scanf ("%d",&val);
    if (aux==1 ) {
        if (val >=0)
        {
            printf ("\n INGRESO SATISFACTORIO...\n");
            system("color B");


        }
        else {
            printf("\n ingreso no valido");
            aux=0;
            system("color C");
        }

    }

    else
    {
        printf ("\n\n INCORRECTO \n ");
        system("color C");
    }


    }while (aux==0&& val <-1);

return val;

}

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
		  printf("INGRESO DE LISTA          ");
		  cambiarcolor(9);
		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		  printf("BORRAR PRIMER ELEMENTO     ");
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");

		  gotoxy(15,10);
		  printf("SALIR");
        }
        if (seleccion==2)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");
		  cambiarcolor(240);
		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		  cambiarcolor(9);
		   gotoxy(15,6);
		  printf("BORRAR PRIMER ELEMENTO    ");
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");

		  gotoxy(15,10);
		  printf("SALIR");
        }
        if (seleccion==3)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");

		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		   cambiarcolor(240);
		  printf("BORRAR PRIMER ELEMENTO    ");
		  cambiarcolor(9);
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		 gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");

		  gotoxy(15,10);
		  printf("SALIR");
        }
        if (seleccion==4)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");

		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		   cambiarcolor(9);
		  printf("BORRAR PRIMER ELEMENTO    ");
		  cambiarcolor(240);
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  cambiarcolor(9);
		 gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");

		  gotoxy(15,10);
		  printf("SALIR");
        }


        if (seleccion==5)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");
		  cambiarcolor(9);
		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		  printf("BORRAR PRIMER ELEMENTO    ");
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  gotoxy(15,8);
		  cambiarcolor(240);
		  printf("MODIFICAR DATOS           ");
		  cambiarcolor(9);
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");

		  gotoxy(15,10);
		  printf("SALIR");
        }
        if (seleccion==6)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");
		  cambiarcolor(9);
		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		  printf("BORRAR PRIMER ELEMENTO    ");
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  cambiarcolor(240);
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");
          cambiarcolor(9);
		  gotoxy(15,10);
		  printf("SALIR                     ");
        }
        if (seleccion==7)
        {
             cambiarcolor(9);
             gotoxy(15,4);
		  printf("INGRESO DE LISTA          ");
		  cambiarcolor(9);
		   gotoxy(15,5);
		  printf("BUSCAR POSICION           ");
		   gotoxy(15,6);
		  printf("BORRAR PRIMER ELEMENTO    ");
		   gotoxy(15,7);
		  printf("IMPRIMIR LISTA            ");
		  gotoxy(15,8);
		  printf("MODIFICAR DATOS           ");
		  gotoxy(15,9);
		  printf("MODIFICAR PRIMER DATO     ");
          cambiarcolor(240);
		  gotoxy(15,10);
		  printf("SALIR                     ");
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
	bool repite=true;
	const char *menu="Menu principal";
	int opcion;
	int n_opciones=7,dato;
	int datoEntero=0,posicion=-1;;
	ListaSimple lista;



    do
    {
        opcion=menu_seleccion(menu,n_opciones);

        switch (opcion)
        {
        case 1:
            {
                system("cls");
                printf("*********HA ELEGIDO EL IGRESO A LA LISTA**************\n\n");
                printf ("\n INGRESE EL VALOR ENTERO POSITIVO:");
                datoEntero=0;
                datoEntero=solo_numeros(datoEntero);
               lista.insertar(datoEntero);


                break;
            }
        case 2:
            {
                printf("********HA ELEGIDO BUSCAR EN LA LISTA*************\n\n");
                printf("\n INGRESE LA POSICION QUE DEESEA BUSCAR :  ");
                posicion=ingreso(posicion);
                lista.buscarPosicion(posicion);

                getch();
                break;
            }
        case 3:
            {
                printf("\n\n*******HA ELEGIDO BORRAR PRIMERA POSICION******\n\n");
                lista.borrarprimero();
                break;
            }
        case 4:
            {system("cls");
                printf("**********HA ELEGIDO IMPRIMIR LA LISTA**********\n\n");

            printf("******LA LISTA ES******* \n \n");
            lista.imprmir();
            getch();
                break;
            }


        case 5:
            {
                system("cls");
                printf("**********HA ELEGIDO MODIFICAR LISTA**********\n\n");
                printf("\n INGRESE EL DATO A MODIFICAR:  ");
                dato=0;
                dato=solo_numeros(dato);
                printf("\n INGRESE EL DATO POR EL CUAL MODIFICAR:  ");
                datoEntero=0;
                datoEntero=solo_numeros(datoEntero);
                lista.modificarCualquiera(dato,datoEntero);
                break;
            }
        case 6:
            {
                system("cls");
                printf("\n\n**********HA ELEGIDO MODIFICAR PRIMER ELEMENTO**********\n\n");
                printf("\n INGRESE EL DATO POR EL CULA MODIFICAR:  ");
                datoEntero=0;
                datoEntero=solo_numeros(datoEntero);
                lista.modificarPimero(datoEntero);
                break;
            }
        case 7:
            {
                repite=FALSE;
                break;
            }
        }

    }
    while(repite);

}
