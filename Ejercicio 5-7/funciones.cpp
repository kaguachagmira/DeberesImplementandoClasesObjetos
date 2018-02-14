#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
#include <windows.h>
#include <string.h>
#include <dos.h>
#include<math.h>
#include <iostream>
using namespace std;

int ListaMixta :: cantidad()
{
    Nodo *aux=primero;
    int num=0;
    while(aux!=NULL)
    {
     aux=aux->siguiente;
     num+=1;
    }
    return num;

}
ListaMixta ListaMixta :: separarpares()
{
    Nodo *aux=primero;
    ListaMixta cola;
    while(aux!=NULL)
    {
        if(aux->getValor()%2==0)
        {
            cola.puush(aux->getValor());
        }
        aux = aux->siguiente;
    }
    return cola;
}
ListaMixta ListaMixta :: separarimpares()
{
    Nodo *aux=primero;
    ListaMixta pila;
    while(aux!=NULL)
    {
        if(aux->getValor()%2!=0)
        {
            pila.push(aux->getValor());
        }
        aux = aux->siguiente;
    }
    return pila;
}
void ListaMixta::insertarInicio(int datoEntero)
{
    Nodo *aux = new Nodo(datoEntero);
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
void ListaMixta::vaciar()
{
    primero=NULL;
    ultimo=NULL;
}
int ListaMixta :: pop()
{
    Nodo *aux_imprimir = primero;
    printf("\nLa lista actualmente contiene los siguientes elementos\n");
    while(aux_imprimir!=NULL)
    {
        printf("[%d] ",aux_imprimir->getValor());
        aux_imprimir=aux_imprimir->siguiente;
    }
    printf("\n");
    system("pause");
    system ("cls");
}
int ListaMixta :: poop()
{
    Nodo *aux = primero;
    int *p;
    int D[20];
    p=D;
    int i=0;
    int j=0;
    printf("\nLa cola actualmente contiene los siguientes elementos\n");
    while(aux!=NULL)
    {
        *(p+i)=aux->getValor();
        aux=aux->siguiente;
        i+=1;
    }
    for(j=0;j<i;j++)
    {
        printf("[%d] ",*p);
        p++;
    }
    printf("\n");
}
void ListaMixta::push(int datoEntero)
{
    Nodo *aux = new Nodo(datoEntero);
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
void ListaMixta::puush(int datoEntero)
{
    Nodo *aux = new Nodo(datoEntero);
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
