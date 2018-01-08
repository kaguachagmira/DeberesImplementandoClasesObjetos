

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
    char dato;
    struct Nodo *siguiente;
    struct Nodo *atras;
};

typedef struct Nodo *lista;

void gotoxy(int ,int );
void insertar(lista &primero,lista &ultimo,char datoAle);
void insertarMedio(lista &lista, char letra, int posicion);
void impresion(lista &primero);



void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


 void insertar(lista &primero,lista &ultimo,char datoAle)
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

}
void eliminarCualquiera(lista lis, char letra, int posicion)
{
    lista aux_borrar = new Nodo();
    lista antes = new Nodo();
    antes = NULL;
    aux_borrar = lis;
    if(aux_borrar->siguiente==NULL)
    {
        printf("\nLa lista unicamente contiene un elemento y ahora quedara vacia\n");
        system("pause");
    }
    if(lis!=NULL)
    {

        while((aux_borrar != NULL)&& (aux_borrar->dato !=letra))
        {
            antes = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL)
        {
            printf("\n El elemento que se desea eliminar no existe en la lista\n");
            system("pause");
        }
        else if(antes == NULL)
        {
            lis=lis->siguiente;
            delete aux_borrar;
        }
        else
        {
            antes->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}

void insertarM(lista lis, char letra, int posicion)
{


	 lista aux = new Nodo();
    lista aux1 = lis;

    	for(int i = 2; i < posicion; i++)
		{
    		aux1 = aux1->siguiente;
		}

    	aux->dato = letra;
		aux->siguiente = aux1->siguiente;
		aux1->siguiente = aux;
		aux->atras = aux1;
		aux->siguiente->atras = aux;
}


void impresion(lista &primero)
{
	int i=0;
    lista actual = new Nodo();
    actual = primero;
    if(primero!=NULL){
        do{
                gotoxy(i,25);
            printf("%c",actual->dato);
            actual=actual->siguiente;
        i+=5;
        }while(actual!=primero);
    }
    else{
        printf("Lista Vacia");
    }
}

int comparar (lista &primero,char letra , int posicion)
{

	int i=0,dos=0;
	int aux2=0;
    lista actual = new Nodo();
    actual = primero;
    if(primero!=NULL){
        do{


            actual=actual->siguiente;
          i++;
        }while(i<=posicion);

         if (actual->dato==letra)
            {


                dos=1;

            }
    }
    else{
        printf("Lista Vacia");
    }
     return dos;

}

int main()
{
	//Nodo *lista;
	char letra;
	char aleatorio;
	lista primero;
	lista ultimo;
	primero=NULL;
	ultimo=NULL;
	 time_t t;
    char cTecla;
  int posicion;
    int x,y,j;
    int aux=0,aux1=0,aux2=0,aux3=0;
     srand((unsigned) time(&t));
     printf("\n Ingrese una letra:   ");
	        scanf("%c",&letra);

     while((!kbhit()))
        {


	        aleatorio=rand()%(122-97+1)+97;
            insertar(primero,ultimo,aleatorio);
            Sleep(100);

        }

   getch();
   //while((!kbhit()))
	{




do
    {
       cTecla = getch();
       if(cTecla == 0)
           cTecla = getch();
       else
           switch(cTecla)
           {
            case 13:

                 impresion(primero);
                 aux=0;aux1=0;aux2=0;aux3=0;
            	return 0;
				break;

            case 9:
                 printf("\r\n Presiono TAB");
            break;

            case 72:

                system("color B");
                 gotoxy(aux,aux1--);
                 printf("%c", letra);
                 impresion( primero);






            break;

            case 80://abajo


                    system("color A");
                    gotoxy(aux,aux1-1);
                    printf(" ");
                     gotoxy(aux+1,aux1-1);
                    printf(" ");
                     gotoxy(aux+1,aux1);
                    printf(" ");
                 gotoxy(aux,aux1++);
                 printf("%c", letra);
                 system("cls");
                 gotoxy(aux,aux1);
                 printf("%c", letra);
                 impresion( primero);
                posicion=0;
                posicion=(aux/5)+2;
                 if(aux1==25)
                 {

                     x=comparar(primero, letra,posicion);
                                if (x==0)
                                {
                                    insertarM(primero,letra,posicion);
                                }
                                else eliminarCualquiera(primero,letra,posicion);


                     gotoxy(aux,aux1+1);
                     printf(" ");
                     aux=0;aux1=0;

                 }




            break;

            case 75:

                system("color C");
                 gotoxy(aux--,aux1);
                 printf("%c", letra);

            break;

            case 77:

                system("color D");
                 gotoxy(aux++,aux1);
                 printf("%c", letra);

            break;
            }
    }while(aux!=x || aux1!=y);

    	insertar(primero,ultimo,j);

    	system("pause");

	}
	printf("salida");
    return 0;
}

