

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
    void setValor(int valor)
    {
        this->valor=valor;
    }
};


class ListaSimple
{
    private:
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

    void insertar(int valor);
    void listaLiberaRam ( );
    int borrarprimero( );




};



