#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
#include <windows.h>
#include <string.h>
#include <dos.h>
#include<math.h>
#include <iostream>
using namespace std;


void ListaSimple::insertarInicio(int datoEntero)
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
void ListaSimple::vaciar()
{
    primero=NULL;
    ultimo=NULL;
}
void ListaSimple::unirListas(Nodo *X, Nodo *Y)//X representa la primera lista y Y la segunda
{
    Nodo *aux1 = X;
    Nodo *aux2 = Y;
    this->vaciar();
    while(aux1!=NULL)
    {
        this->insertarInicio(aux1->getValor());
        aux1=aux1->siguiente;
    }
    while(aux2!=NULL)
    {
        this->insertarInicio(aux2->getValor());
        aux2=aux2->siguiente;
    }
}
void ListaSimple :: imprimir()
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
}
ListaSimple ListaSimple :: crop(Nodo *cabeza , int *excepciones)
{
    ListaSimple lista_aux;
    Nodo *aux_borrar=cabeza;
    Nodo *aux_pro;
    int i=0;
    int contador=0;
    system("cls");
    printf("\n Estas son las Excepciones (posiciones) que permaneceran\n");
    while((*(excepciones+i))!=-1)
    {
        printf("Permanecera la posicion: [%d]\n",*(excepciones+i));
        i++;
    }
    i=0;
    while((*(excepciones+i))!=-1)
    {
        aux_borrar=cabeza;
        contador=0;
        while(aux_borrar!=NULL)
        {
            if((*(excepciones+i))==contador)
            {
                lista_aux.insertarInicio(aux_borrar->getValor());
            }
            aux_borrar= aux_borrar->siguiente;
            contador+=1;
        }
        i+=1;
    }
    system("pause");
    this->vaciar();
    lista_aux.imprimir();
    return lista_aux;
}
void ListaSimple :: eliminarPorPosicion(int posicion)
{
    Nodo *aux_borrar = primero;
    Nodo *aux_anterior;

    int contador = 0;
    if(aux_borrar->siguiente==NULL && contador==posicion)
    {
        printf("\nLa lista unicamente contiene un elemento y ahora quedara vacia\n");
        primero=primero->siguiente;
        delete aux_borrar;
        system("pause");
    }
    else
    {
        while((aux_borrar != ultimo)&& (contador!=posicion))
        {
            aux_anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
            contador+=1;
        }
        if(aux_borrar->siguiente == NULL)
        {
            printf("\n La posicion que ingreso no correpsponde a ningun elemento de la Lista\n");
            system("pause");
        }
        if(aux_anterior==NULL)
        {
            primero=primero->siguiente;
            delete aux_borrar;
        }
        else
        {
            aux_anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}
int ListaSimple::reparar(Nodo *cabeza , int x , int correccion)
{
    int valor_aux=0;
    int existencia=0;

    Nodo *aux = cabeza;

    while(aux->siguiente!=NULL)
    {
        if(aux->getValor()==x)
        {
            printf("\nEl valor de x=[%d] si se encontro en la Lista en la posicion [%d] \n",x,existencia);
            printf("\nPor tanto el valor [%d] sera sumado al valor de correcion [%d] \n",x,correccion);
            system("pause");
            valor_aux=aux->getValor()+correccion;
            aux->setValor(valor_aux);
            existencia+=1;
        }
        aux = aux->siguiente;
    }
    if(existencia==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
