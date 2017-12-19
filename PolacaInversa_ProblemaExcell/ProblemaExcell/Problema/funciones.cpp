#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void ListaSimple ::restodeClientes()
{
    int maximo;
    Nodo *aux_actual = ultimo;
    Nodo *aux_anterior = primero;
    while(aux_anterior->siguiente!=ultimo)
    {
        aux_anterior = aux_anterior->siguiente;
    }
    if(aux_anterior->getTSalida()> aux_actual->getTLlegada())
    {
        maximo=aux_anterior->getTSalida();
    }
    else if(aux_anterior->getTSalida()< aux_actual->getTLlegada())
    {
        maximo = aux_actual->getTLlegada();
    }
    else if (aux_anterior->getTSalida()== aux_actual->getTLlegada())
    {
        maximo = aux_actual->getTLlegada();
    }
    aux_actual->setTEsperaCliente(maximo-aux_actual->getTLlegada());
    aux_actual->setTDescansoCajero(maximo-aux_anterior->getTSalida());
    aux_actual->setTSalida(aux_actual->getTLlegada()+aux_actual->getTDescansoCajero()+ aux_actual->getTServicio());
    aux_actual->setTEntreLlegadas(aux_actual->getTLlegada()-aux_anterior->getTLlegada());
    ultimo=aux_actual;

}
void ListaSimple ::primerCliente()
{
    Nodo *aux = ultimo;
    aux->setTEsperaCliente(0);
    aux->setTDescansoCajero(0);
    aux->setTSalida(aux->getTLlegada()+ aux->getTEsperaCliente()+ aux->getTServicio());
    aux->setTEntreLlegadas(5);
}
int ListaSimple ::randomico(int x)
{

    if(x==1)
    {
        int num = 0;
        int base = 1;
        int tope = 25;
        srand(time(NULL));
        num = base + rand() % (tope+1 - base);
        return num;
    }
    else if(x==2)
    {
        Nodo *aux = ultimo  ;
        int num = 0;
        int base = 1;
        int tope = 25;
        //srand(time(NULL));
        num = base + rand() % (tope+1 - base);
        num = num + aux->getTLlegada();
        return num;
    }
    return 0;
}
int ListaSimple ::random(int clientes)
{
        int num = 0;
        int base = 1;
        int tope = 25;
        for(int i=0; i<25 ; i++)
        {
            num = base + rand() % (tope+1 - base);
        }
        return num;
}
void ListaSimple::ingresar(int datoLlegada, int datoServicio)
{
    Nodo *aux = new Nodo(datoLlegada, datoServicio);
    if(ListaVacia()==true)
    {
        primero=ultimo=aux;
    }
    else
    {
        ultimo->siguiente=aux;
        ultimo=aux;
    }
}
void ListaSimple::impresion()
{
    int i=1;
    int j=1;
    Nodo *aux = primero;
    printf("\nTiempo de Llegada\n");
    while(aux!=NULL)
    {

        printf("[%i]=>%d\n",i,aux->getTLlegada());
        aux=aux->siguiente;
        i+=1;
    }
    i=1;
    j=1;
    Nodo *aux1 = primero;
    printf("\nTiempo de Espera del Cliente\n");
    while(aux1!=NULL)
    {
        printf("[%i]=>%d\n",j,aux1->getTEsperaCliente());
        aux1=aux1->siguiente;
        j+=1;
    }

    i=1;
    j=1;
    Nodo *aux2 = primero;
    printf("\nTiempo de Descanso del Cajero\n");
    while(aux2!=NULL)
    {
        printf("[%i]=>%d\n",j,aux2->getTDescansoCajero());
        aux2=aux2->siguiente;
        j+=1;
    }

    i=1;
    j=1;
    Nodo *aux3 = primero;
    printf("\nTiempo de Servicio\n");
    while(aux3!=NULL)
    {
        printf("[%i]=>%d\n",j,aux3->getTServicio());
        aux3=aux3->siguiente;
        j+=1;
    }

    i=1;
    j=1;
    Nodo *aux4 = primero;
    printf("\nTiempo de Salida del Cliente\n");
    while(aux4!=NULL)
    {
        printf("[%i]=>%d\n",j,aux4->getTSalida());
        aux4=aux4->siguiente;
        j+=1;
    }

    i=1;
    j=1;
    Nodo *aux5 = primero;
    printf("\nTiempo entre llegadas de Clientes\n");
    while(aux5!=NULL)
    {
        printf("[%i]=>%d\n",j,aux5->getTEntreLlegadas());
        aux5=aux5->siguiente;
        j+=1;
    }
}
