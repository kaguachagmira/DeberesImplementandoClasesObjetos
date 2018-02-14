/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado: Ejercicios Para Realizar la Conjunta                  *
 *            usando Clases POO                                     *
 * Alumno:Kevin Guachagmira, Cristian Barragan, Jonathan Altamirano *
 * Fecha de inicio: 13/02/2018	Fecha de modificacion: 13/02/2017   *
 * Docente: Ing. Fernando Solis                                     *
 * author: Guachagmira Kevin                                        *
 ********************************************************************/

#include <iostream>
#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <dos.h>


using namespace std;
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
int menuPreguntas()
{
	const char *opciones[]={"PREGUNTA A","PREGUNTA B"}; //OPCIONES
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
		gotoxy(25,0); printf("MENU DE LISTAS\n\n");
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
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
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
int menuBorrar()
{
	const char *opciones[]={"PILA PRINCIPAL      ","COLA PARES          ","PILA IMPARES       "}; //OPCIONES
	int n=3; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU DE LISTAS\n\n");
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
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
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
	const char *opciones[]={"INGRESO DE DATOS       ","EXTRACCION DE DATOS    ","CANTIDAD DE DATOS      ","PREGUNTAS              ","SALIR                   "}; //OPCIONES
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
		gotoxy(25,0); printf("MENU PROBLEMA 1-4\n\n");
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
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
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
    }while (aux==0&& val <=0);

return val;

}
int main()
{
    ListaMixta pila;
    ListaMixta cola_pares;
    ListaMixta pila_impares;
    int opcion=0;
    int tipo=0;
    int pre=0;
    int cont1=0;
    int datoEntero=-1;
    do
    {
        system ("cls");
        opcion=menuPrincipal();
        switch (opcion)
        {
        system ("cls");
        case 1 :
            {
                if(pila.listaVacia()==true)
                {
                    system ("cls");
                    printf("\nPrimero se debe crear la Pila con un dato\n");
                    datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                    pila.push(datoEntero);
                    printf("\nPila creada con exito\n");
                    system("pause");
                    cont1+=1;
                    printf("\n");
                    pila.pop();
                }
                else
                {
                    system ("cls");
                    datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                    pila.push(datoEntero);
                    cont1+=1;
                    printf("\n");
                    pila.pop();
                }
                break;
            }
        case 2:
            {
                system ("cls");
                printf("\nSe procedera a vaciar la Pila los elementos pares se guardaran en una Cola \n");
                printf("\nY los elementos impares en otra Pila");
                cola_pares=pila.separarpares();
                pila_impares=pila.separarimpares();
                system("pause");
                printf("\nImpresion de Cola(Numeros Pares)\n");
                cola_pares.poop();
                system("pause");
                printf("\nImpresion de Cola(Numeros Pares)\n");
                pila_impares.pop();
                system("pause");
                break;
            }
        case 3:
            {
                system ("cls");
                tipo=menuBorrar();
                if(tipo==1)
                {
                    if(pila.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Pila !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        printf("En la Pila existen exactamente [%d] elementos",pila.cantidad());
                        system("pause");
                    }
                }
                else if(tipo==2)
                {
                    if(cola_pares.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Cola de Pares !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system ("cls");
                        printf("En la Cola de Pares existen exactamente [%d] elementos",cola_pares.cantidad());
                        system("pause");
                    }
                }
                else if(tipo==3)
                {
                    if(pila_impares.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Cola de Pares !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system ("cls");
                        printf("En la Pila de Impares existen exactamente [%d] elementos",pila_impares.cantidad());
                        system("pause");
                    }
                }
                break;
            }
        case 4:
            {
                system ("cls");
                if(pila.listaVacia()==true && cola_pares.listaVacia()==true && pila_impares.listaVacia()==true)
                {
                    system ("cls");
                    printf("Para responder la preguntas primero se debe EXTRAER LOS DATOS !!");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    pre=menuPreguntas();
                    system ("cls");
                    if(pre==1)
                    {
                        system ("cls");
                        printf("\nPREGUNTA A: En que orden se extraeran los elementos de la pila de impares\n");
                        printf("\nRESPUESTA A: ");
                        pila_impares.pop();
                        system("pause");
                    }
                    else if(pre==2)
                    {
                        system ("cls");
                        printf("\nPREGUNTA B: En que orden se extraeran los elementos de la cola de pares\n");
                        printf("\nRESPUESTA B: ");
                        cola_pares.poop();
                        system("pause");
                    }
                    else if(pre==3)
                    {
                        //5,19,21,65,33,45,3,1,40,2,60,4
                    }
                    system ("cls");

                }
                break;
            }
        case 5:
            {
                return 0;
                break;
            }
        }

    }while(opcion!=5);
}
