
#include <stdlib.h>
#include <stdio.h>
#include "listasSimples.h"
#include <windows.h>
void ListaSimple::insertar(int valor)
{
    Nodo *aux = new Nodo(valor);
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

void ListaSimple::listaLiberaRam ( )
    {
           Nodo *actual=primero;
           Nodo *siguient;


        while(actual != NULL)
        {
            siguient = actual->siguiente;
             free(actual);
             actual = siguient;

        }
        primero=NULL;

    }

int  ListaSimple::borrarprimero( )
    {
      int resp;

        if(listaVacia()==true)
        {
            printf("\n lista esta vacia");
        }
        else
        {
            resp=primero->getValor();

            primero=primero->siguiente;
        }
       return resp;
     }
