#include <iostream>
class Nodo
{
    private:
        int  valor;
    public:
        Nodo *siguiente;
        Nodo *anterior;
        Nodo(int valor)
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


class ListaCircular
{
    private:
        Nodo *primero;
        Nodo *ultimo;
    public:
        ListaCircular()
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

