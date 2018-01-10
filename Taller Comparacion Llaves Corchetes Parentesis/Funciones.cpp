#include <stdlib.h>
#include <stdio.h>
#include "listadoble.h"
#include <windows.h>


void ListaDoble::insertarInicio(char datoEntero)
{
        Nodo *aux = new Nodo(datoEntero);

        if(listaVacia()==true)
        {
            primero = ultimo = aux;
        }
        else
        {
            ultimo->siguiente=aux;
            ultimo=aux;
            ultimo->siguiente=NULL;
        }
}

void ListaDoble::acumulador()
{
    int cont=0,i=0;
    int acum=1;
    Nodo *aux=primero;
// num=(num*10)+(letra-48);
    bool seguir=true;
    acum=(aux->getValor()-'0');

    while(seguir)
    {


        if (i%2!=0)
        {

            if (aux->getValor()=='*')
            {
                acum*=aux->siguiente->getValor()-'0';

            }
            if (aux->getValor()=='/')
            {
                acum/=aux->siguiente->getValor()-'0';
            }
            if (aux->getValor()=='+')
            {
                acum+=aux->siguiente->getValor()-'0';
            }
            if (aux->getValor()=='-')
            {
                acum-=aux->siguiente->getValor()-'0';
            }
        }

        printf(" %c",aux->getValor());




        if(aux==ultimo)
        {
            seguir=false;
        }
        aux=aux->siguiente;
        i++;
    }

printf("\n*******--->%d", acum);

}

int ListaDoble :: casos()
{
    int corcheteA=0;
    int corcheteC=0;
    int llaveA=-0;
    int llaveC=0;
    int parentesisA=0;
    int parentesisC=0;
    int resp=0;
      Nodo *aux=primero;

        while(aux->siguiente!=ultimo)
        {
                if(aux->getValor()=='{')
                    {
                        llaveA+=1;
                    }
                if(aux->getValor()=='}')
                    {
                        if(llaveA==0)
                        {
                            llaveC = -1;
                        }
                        else
                        {
                            llaveC+=1;
                        }
                    }
                if(aux->getValor()=='[')
                    {
                        corcheteA+=1;
                    }
                if(aux->getValor()==']')
                    {
                        if(corcheteA==0)
                        {
                            corcheteC = -1;
                        }
                        else
                        {
                            corcheteC+=1;
                        }
                    }
                if(aux->getValor()=='(')
                    {
                        parentesisA+=1;
                    }
                if(aux->getValor()==')')
                    {
                        if(parentesisA==0)
                        {
                            parentesisC = -1;printf("\n");
                        }
                        else
                        {
                            parentesisC+=1;
                        }
                    }
                aux=aux->siguiente;
        }
        if((corcheteA==corcheteC )&&(parentesisA == parentesisC) && (llaveA== llaveC))
        {
            return -1;
        }
        else
        {
            return 1;
        }
}

void ListaDoble::imprimir()
{

        Nodo *aux=primero;

        while(aux->siguiente!=NULL)
        {
            printf("%c",aux->getValor());
            aux=aux->siguiente;
        }
}
