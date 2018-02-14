#include<string.h>
#include <iostream>

class Nodo
{
    private:
        int  valor;
    public:
        Nodo *siguiente;
        Nodo(int valor)
        {
            this->valor = valor;
            siguiente = NULL;
        }
        int getValor()
        {
            return valor;
        }
        void setValor(int newvalue)
        {
            this->valor=newvalue;
        }
};

class Pila
{
    public:
        Nodo *primero;
        Nodo *ultimo;
    public:
        Pila()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }
    int pop();
    void push(int dato);
    bool vacia();
    void vaciar();
    void copiar(Nodo*);
    void insertarInicio(int valor);
};

class Cola
{
    public:
        Nodo *primero;
        Nodo *ultimo;
    public:
        Cola()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }
    int pop();
    void push(int dato);
    bool vacia();
    void vaciar();
    void copiar(Nodo*);
    void insertarInicio(int valor);
};

class ListaMixta
{
    public:
        Nodo *primero;
        Nodo *ultimo;
    public:
        ListaMixta()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }
    int pop();
    int poop();
    void push(int dato);
    void puush(int dato);
    int cantidad();
    bool vacia();
    void vaciar();
    void insertarInicio(int valor);
    ListaMixta separarpares();
    ListaMixta separarimpares();
};
