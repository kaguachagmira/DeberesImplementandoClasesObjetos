#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

class Nodo1
{
    private:
        int  valor;
    public:
        Nodo1 *siguiente;
        Nodo1 *anterior;
        Nodo1(int valor)
        {
            this->valor = valor;
            siguiente = NULL;
            anterior = NULL;
        }
    int getValor()
    {
        return valor;
    }
};


class ListaDoble
{
    private:
        Nodo1 *primero;
        Nodo1 *ultimo;
    public:
        ListaDoble()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }

    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void insertarCualquiera(int valor,int posicion);
    void borrarInicio();
    void borrarFinal();
    void borrarCualquiera(int valor);
    void buscarPorPosicion(int posicion);
    void buscarPorValor(int valor);
    void imprimir();
};

void ListaDoble::insertarInicio(int datoEntero)
{
    Nodo1 *aux = new Nodo1(datoEntero);
    if(listaVacia()==true)
    {
        primero=ultimo=aux;
    }
    else
    {
        aux->siguiente=primero;
        primero->anterior=aux;
        primero=aux;
    }
}
void ListaDoble::insertarFinal(int datoEntero)
{
    Nodo1 *aux = new Nodo1(datoEntero);
    if(listaVacia()==true)
    {
        primero=ultimo=aux;
    }
    else
    {
        ultimo->siguiente=aux;
        aux->anterior=ultimo;
        ultimo=aux;
    }
}
void ListaDoble :: insertarCualquiera(int datoEntero, int posicion)
{
        Nodo1 *aux1 = primero;
        Nodo1 *aux2 = primero;
        Nodo1 *aux = new Nodo1(datoEntero);
        if(posicion==1)
        {
            aux2->anterior=aux;
            aux->siguiente=aux2;
            primero=aux;
        }
        else
        {
            for(int i = 2; i < posicion; i++)
            {
                aux1 = aux1->siguiente;
            }

            aux->siguiente = aux1->siguiente;
            aux1->siguiente = aux;
            aux->anterior = aux1;
            aux->siguiente->anterior = aux;
        }
}
void ListaDoble::borrarInicio()
{
    if(primero==ultimo)
    {
        printf("\nLa lista unicamente contiene un nodo y ahora quedo VACIA! \n");
        system("pause");
        primero=ultimo=NULL;
    }
    else
    {
        Nodo1 *aux = primero;
        primero = primero->siguiente;
        primero->anterior=NULL;
        delete aux;
        printf("\nEl Elemento que se encontraba en la primera posicion fue eliminado con EXITO \n");
        system("pause");
    }
}
void ListaDoble::borrarFinal()
{

    if(primero==ultimo)
    {
        printf("\nLa lista unicamente contiene un nodo y ahora quedo VACIA! \n");
        system("pause");
        primero=ultimo=NULL;
    }
    else
    {
        Nodo1 *aux =ultimo;
        ultimo =ultimo->anterior;
        ultimo->siguiente=NULL;
        delete aux;
        printf("\nEl Elemento que se encontraba en la ultima posicion fue eliminado con EXITO \n");
        system("pause");
    }
}
void ListaDoble::borrarCualquiera(int datoEliminar)
{
    Nodo1 *aux_borrar = primero;
    Nodo1 *antes;
    antes = NULL;

    if(aux_borrar->siguiente==NULL)
    {
        printf("\nLa lista unicamente contiene un elemento y ahora quedara vacia\n");
        system("pause");
    }
    if(listaVacia()==false)
    {

        while((aux_borrar != ultimo)&& (aux_borrar->getValor() !=datoEliminar))
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
            primero=primero->siguiente;
            delete aux_borrar;
        }
        else
        {
            antes->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}
void ListaDoble::imprimir()
{
    Nodo1 *aux=primero;
    int i=1;
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
void ListaDoble :: buscarPorPosicion(int posicion)
{
    Nodo1 *aux_buscar = primero;
    int contador = 1;
    if(aux_buscar->siguiente==NULL && contador==posicion)
    {
        printf("\n En la posicion [ %d ] se encuentra el dato [ %d ]\n",posicion,aux_buscar->getValor());
        system("pause");
    }
    else
    {
        while(aux_buscar->siguiente!=NULL)
        {
            if(contador == posicion)
            {
                printf("\n En la posicion [ %d ] se encuentra el dato [ %d ]\n",posicion,aux_buscar->getValor());
                system("pause");
            }
            contador+=1;
            aux_buscar=aux_buscar->siguiente;
        }
    }
}
void ListaDoble :: buscarPorValor(int dato)
{
    Nodo1 *aux_buscar = primero;
    int posicion = 1;
    int prueba = 0;
    if(aux_buscar->siguiente==NULL && aux_buscar->getValor()==dato)
    {
        printf("\nEn la posicion [ %d ] se encuentra el dato [ %d ]\n",posicion,aux_buscar->getValor());
        system("pause");
    }
    else
    {
        while(aux_buscar->siguiente!=NULL)
        {
            if(aux_buscar->getValor()==dato)
            {
                printf("\nEL dato [ %d ] si existe en la lista y se encuentra en la posicion [ %d ]\n",dato,posicion);
                system("pause");
                prueba=1;
            }
            posicion+=1;
            aux_buscar=aux_buscar->siguiente;
        }
    }
    if(prueba==0)
    {
        printf("\nEl valor que se busco no se encuentra en ningun posicion de la lista\n");
        system("pause");
    }
}
