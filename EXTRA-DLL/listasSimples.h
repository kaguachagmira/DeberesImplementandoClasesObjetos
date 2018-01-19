#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

class Nodo2
{
    private:
        int  valor;
    public:
        Nodo2 *siguiente;
        Nodo2(int valor)
        {
            this->valor = valor;
            siguiente = NULL;


        }
    int getValor()
    {
        return valor;
    }
    void setValor(int valor)
    {
        this->valor=valor;
    }
};


class ListaSimple
{
    private:
        Nodo2 *primero;
        Nodo2 *ultimo;
    public:
        ListaSimple()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }

     void insertar(int valor)
     {
             Nodo2 *aux = new Nodo2(valor);
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

     void imprmir ( )
  {
           Nodo2 *aux=primero;

        bool seguir=true;
        while(seguir)
        {
            printf("%d-> ",aux->getValor());
            if(aux==ultimo)
            {
                seguir=false;
            }
            aux=aux->siguiente;
        }

  }

    void buscarPosicion (int posicion)
  {
           Nodo2 *aux=primero;
        int i=0;
        bool seguir=true;
        while(seguir)
        {
            if (i==posicion)
            {
                printf("%d-> ",aux->getValor());

            }

            i++;
            if(aux==ultimo)
            {
                seguir=false;
            }
            aux=aux->siguiente;
        }

  }
  void borrarprimero( )
  {

        if(listaVacia()==true)
        {
            printf("\n lista esta vacia");
        }
        else
        {

            primero=primero->siguiente;
        }

  }
void modificarPimero(int valor )
  {
       Nodo2 *aux=new Nodo2 (valor) ;
       Nodo2 *aux2 = primero;

       aux->siguiente=aux2->siguiente;
        primero=aux;
  }

  void modificarCualquiera(int valor,int cambio)
  {

      Nodo2 *aux2=primero;

        bool seguir=true;
        while(seguir)
        {
            if (aux2->getValor()==valor)
            {
                aux2->setValor(cambio);

            }

            if(aux2==ultimo)
            {
                seguir=false;
            }
            aux2=aux2->siguiente;
        }


  }


};



