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
class ListaSimple
{
    public:
        Nodo *primero;
        Nodo *ultimo;
    public:
        ListaSimple()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }
    void vaciar();
    void copiar(Nodo*);
    void insertarInicio(int valor);
    void eliminarPorPosicion(int );
    int  recorrerPrimero();
    void imprimir();
    int reparar(Nodo *, int x , int correccion);
    void unirListas(Nodo *, Nodo *);
    ListaSimple crop(Nodo *, int *);
};

