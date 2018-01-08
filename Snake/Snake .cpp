/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado: Utilizando listas circulares doblemente enlazadas     *
 * Tema: Snake                                                      *
 * Alumno:Kevin Guachagmira,Jonathan Altamirano, Cristian Barraga   *
 * Fecha de inicio: 20/11/2017	Fecha de modificacion: 20/11/2017   *
 * Docente: Ing. Fernando Solis                                     *
 *                                    							    *
 ********************************************************************/

//Librerias
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ESC 27



 struct Nodo
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *atras;
};

typedef struct Nodo *lista;

void gotoxy(int ,int );
void insertar(lista &primero,lista &ultimo,int datoAle);
void impresion(lista &primero);
int numRanX();
int numRanY();
int numRan();


void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 
 
 void insertar(lista &primero,lista &ultimo,int datoAle)
 {
    lista nuevo = new Nodo();
    nuevo->dato = datoAle;
    if(primero==NULL){
        primero = nuevo;
        primero->siguiente=primero;
        ultimo=primero;
        primero->atras=ultimo;
    }
    else{
        ultimo->siguiente=nuevo;
        nuevo->siguiente=primero;
        nuevo->atras=ultimo;
        ultimo=nuevo;
        primero->atras=ultimo;
    }
    gotoxy(0,22);
    printf("Nodo ingresado \n");
}



void impresion(lista &primero)
{
	int i;
    lista actual = new Nodo();
    actual = primero;
    if(primero!=NULL){
        do{
            printf("%d->",actual->dato);
            actual=actual->siguiente;
        }while(actual!=primero);
    }
    else{
        printf("Lista Vacia");
    }
}


int numRanX()
{
	int datoEntero;
   	int inicioRand=0;
   	time_t t;
    int finalRand=50;
   	srand((unsigned) time(&t));

	datoEntero=rand()%(finalRand-inicioRand+1)+inicioRand;
	return datoEntero;
}
int numRanY()
{
	int datoEntero;
   	int inicioRand=0;
   	time_t t;
    int finalRand=20;
   	srand((unsigned) time(&t));

	datoEntero=rand()%(finalRand-inicioRand+1)+inicioRand;
	return datoEntero;
}
int numRan()
{
	int datoEntero;
   	int inicioRand=1;
   	time_t t;
    int finalRand=10;
   	srand((unsigned) time(&t));

	datoEntero=rand()%(finalRand-inicioRand+1)+inicioRand;
	return datoEntero;
}
int main()
{
	//Nodo *lista;
	lista primero;
	lista ultimo;
	primero=NULL;
	ultimo=NULL;
    char cTecla;
    int x,y,j;
    int aux=0,aux1=0,aux2=0,aux3=0;
    while((!kbhit()))
	{

   		j=numRan();
   		x=numRanX();
   		y=numRanY();
		gotoxy(x,y);
		printf("%d",j);
		
	do
    {
       cTecla = getch();
       if(cTecla == 0)
           cTecla = getch();
       else
           switch(cTecla)
           {
            case 13:
                 system("cls");
                 impresion(primero);
                 aux=0;aux1=0;aux2=0;aux3=0;
            	return 0;
				break;

            case 9:
                 printf("\r\n Presiono TAB");
            break;

            case 72:
            	system ("cls");
                system("color B");
                 gotoxy(aux,aux1--);
                 printf("*");
                 
                 gotoxy(x,y);
                 printf ("%d",j);
                
                 

            break;

            case 80:
            	system ("cls");
                    system("color A");
                 gotoxy(aux,aux1++);
                 printf("*");
                 
                 gotoxy(x,y);
                 printf ("%d",j);

            break;

            case 75:
            	system ("cls");
                system("color C");
                 gotoxy(aux--,aux1);
                 printf("*");
                 
                 gotoxy(x,y);
                 printf ("%d",j);

            break;

            case 77:
            	system ("cls");
                system("color D");
                 gotoxy(aux++,aux1);
                 printf("*");
                 gotoxy(x,y);
                 printf ("%d",j);

            break;
            }
    }while(aux!=x || aux1!=y);
    	
    	insertar(primero,ultimo,j);
    	
    	system("pause");
    	
	} 
	printf("salida");
    return 0;
}
