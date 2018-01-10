#include <iostream>
class Nodo
{
    private:
        char  valor;
    public:
        Nodo *siguiente;
        Nodo *anterior;
        Nodo(char valor)
        {
            this->valor = valor;
            siguiente = NULL;
            anterior = NULL;
        }
    char getValor()
    {
        return valor;
    }
};


class ListaDoble
{
    private:
        Nodo *primero;
        Nodo *ultimo;
    public:
        ListaDoble()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }

    void insertarInicio(char valor);

     void acumulador();
     void imprimir();
     int casos();
};
