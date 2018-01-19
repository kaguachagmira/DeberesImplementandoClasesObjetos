#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include <windows.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <ctype.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include<conio.h>
using namespace std;
ListaSimple listita2;
void ListaSimple::insertar(char dato[70])
{
    Nodo *aux = new Nodo(dato);
    if(listaVacia()==true)
    {
        primero=ultimo=aux;
    }
    else
    {
        aux->siguiente=primero;
        primero=aux;
    }
}
void ListaSimple::insertarcopia(char dato[70])
{
    Nodo *aux = new Nodo(dato);
    if(listaVacia()==true)
    {
        primero=ultimo=aux;
    }
    else
    {
        ultimo->siguiente=aux;
        ultimo=aux;
    }
}
void ListaSimple::borrar()
{

    primero=NULL;
    ultimo=NULL;
}
void ListaSimple::copiar(char dato[70])
{

    int aux2=1;
    listita2.borrar();
    listita2.insertarcopia(dato);
    Nodo *aux=primero;
    while(aux!=NULL)
    {
        aux2=strcmp(aux->getValor(),dato);
        if (aux2!=0)
        {
            listita2.insertarcopia(aux->getValor());
        }
        aux=aux->siguiente;
    }
}
void ListaSimple::imprimir()
{
    Nodo *aux=primero;
    printf("\n\tLISTA DE PALABRAS EN COLA\n");
    while(aux!=NULL)
    {
        printf("\t");
        puts(aux->getValor());
        aux=aux->siguiente;
    }
    printf("\n\tLISTA PASO A TRADUCCION\n");
    listita2.imprimir_aux();

}
void ListaSimple::imprimir_aux()
{
    Nodo *aux=primero;
    while(aux!=NULL)
    {
        printf("\t");
        puts(aux->getValor());
        aux=aux->siguiente;
    }
}

int ListaSimple::buscar(char esp [70])
{
    Nodo *aux=primero;
    int resp=0;
    int aux2=1;
    if(listaVacia()==true)
    {
        return 0;
    }
    else
    {
        while(aux!=NULL)
        {
            aux2=strcmp(aux->getValor(),esp);
            if (aux2==0)
            {
                resp=1;
            }
            aux->getValor();
            aux=aux->siguiente;
        }
    }
    return resp;
}
void ListaSimple::ficheroTraduccion(char palabraEsp[70],char palabraIng[70])
{

    FILE *archivo=NULL;
		char Direccion1 []="D:/Registro_factura.txt";
		archivo=fopen(Direccion1,"w");
       fprintf(archivo,"**DICCIONARIO ESPAÑOL-INGLES**\n\n");
        fprintf(archivo,"***ESPAÑOL---------INGLES***\n");
        fprintf(archivo,"*      %s              %s   *" ,palabraEsp,palabraIng);
        fprintf(archivo,"\n***************************\n\n");

    fclose(archivo);
    system("start D:/QR.jar");
}
void ListaSimple::FicheroCola1()
{
    FILE *archiv=NULL;
		char Direccion []="D:/Registro_factura.txt";
		archiv=fopen(Direccion,"w");
		fclose(archiv);

    Nodo *aux=primero;
    FILE *archivo=NULL;
		char Direccion1 []="D:/Registro_factura.txt";
		archivo=fopen(Direccion1,"a");
    fprintf(archivo,"\n\tLISTA DE PALABRAS EN COLA\n");
    while(aux!=NULL)
    {
        fprintf(archivo,"*      %s     *\n" ,aux->getValor());
        aux=aux->siguiente;
    }

    listita2.FicheroCola2();
fclose(archivo);

}
void ListaSimple::FicheroCola2()
{
    Nodo *aux=primero;
    FILE *archivo=NULL;
		char Direccion1 []="D:/Registro_factura.txt";
		archivo=fopen(Direccion1,"a+");
		fprintf(archivo,"\n\tLISTA PASO A TRADUCCION\n");
    while(aux!=NULL)
    {
        printf("\t");
        fprintf(archivo,"*      %s     *\n" ,aux->getValor());
        aux=aux->siguiente;
    }
   fclose(archivo);
    system("start D:/QR.jar");
}


void ListaSimple::generarPDF1()
{
    FILE *archiv=NULL;
		char Direccion []="D:/PARQUEADERO.txt";
		archiv=fopen(Direccion,"w");
		fclose(archiv);

    Nodo *aux=primero;
    FILE *archivo=NULL;
		char Direccion1 []="D:/PARQUEADERO.txt";
		archivo=fopen(Direccion1,"a");
    fprintf(archivo,"\n\tLISTA DE PALABRAS EN COLA\n");
    while(aux!=NULL)
    {
        fprintf(archivo,"*      %s     *\n" ,aux->getValor());
        aux=aux->siguiente;
    }

    listita2.generarPDF2();
fclose(archivo);

}
void ListaSimple::generarPDF2()
{
    Nodo *aux=primero;
    FILE *archivo=NULL;
		char Direccion1 []="D:/PARQUEADERO.txt";
		archivo=fopen(Direccion1,"a+");
		fprintf(archivo,"\n\tLISTA PASO A TRADUCCION\n");
    while(aux!=NULL)
    {
        printf("\t");
        fprintf(archivo,"*      %s     *\n" ,aux->getValor());
        aux=aux->siguiente;
    }
   fclose(archivo);
    system("start D:/GENERADORPDF.jar");
}
void ListaSimple::backup(char horarios[50])
{
    Nodo *aux=primero;
    int i=1;
    bool seguir=true;


    char var[50],dat[50];
    int opc,opc1,cont=0,cont1=0;
    FILE *a;
    char separador[2]={"\n"};
    //do{
    time_t fsistema = time(0);
	struct tm *tlocal = localtime(&fsistema);
	char h[128];
	strftime(h, 128, "hora(%H\%M\%S)fecha(%d\%m\%Y).txt", tlocal);
	strftime(horarios, 128, "hora(%H\%M\%S)fecha(%d\%m\%Y).txt", tlocal);
	ofstream f;
	string nombreArchivo,frase;
	string h1(h);
	fflush(stdin);
	f.open(h1.c_str(),ios::out);
	while(aux!=NULL)
    {
        f<<aux->getValor();
        f<<separador;
        aux=aux->siguiente;
    }
	printf("\ndesea otro backup");
	//scanf("%d",&opc);
	cont+=1;
	//}while(opc!=0);
	system("cls");
	printf("\n");
    a=fopen("horarios.txt","a");
    for(int i=0;i<cont;i++)
    {
        fprintf(a,"%s\n",horarios);
    }
    fclose(a);

}
void ListaSimple::vaciar( char *a)
{
    int i;
    for (i=0;i<50;i++)
    {
        a[i]='\0';
    }
}
void ListaSimple::recuperar(char recuperarArc[50])
{

 char rePalabra[70];
 char b[50],*p;
 puts(recuperarArc);
 int i=0;
 p=recuperarArc;
 while(*p!='x')
 {
     b[i]=*p;
     p++;
     i++;
 }
 b[i]='x';
 b[i+1]='t';
 b[i+2]='\0';

puts(b);
getch();
    FILE *f=NULL;

        f=fopen(b,"r");

        if (f == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
        for (int i=0;!feof(f);i++)
        {
            int j=0;
            vaciar(rePalabra);
            fgets(rePalabra,70,f);
//            while(rePalabra[j]!=';')
//            {
//                j++;
//            }
//            rePalabra[j]='\0';
//            puts(rePalabra);

            insertar(rePalabra);
        }
        }
     fclose(f);



}
