/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado:ARBOL BINARIO                                          *
 * Alumno:Kevin Guachagmira                                         *
 * Fecha de inicio: 10/12/2017	Fecha de modificacion: 09/01/2018   *
 * Docente: Ing. Fernando Solis                                     *
 ********************************************************************/
#include<string.h>
#include <iostream>
class Sheet
{
    private:
        int data;
    public:
        Sheet *right;
        Sheet *left;
        Sheet(int data);
        ~Sheet();
        int getValue()
        {
            return data;
        }
        void setValue(int data)
        {
            this->data=data;
        }
};

class BinaryTree
{
    private:
        Sheet *root;
        Sheet *add(Sheet*,Sheet*);
        Sheet *supr(Sheet*,int);
        int getInfo_der(Sheet*);
        void preOrden(Sheet*);
        void inOrden(Sheet*);
        void postOrden(Sheet*);
        void graph(Sheet *,int a, int b, int c, int d);
    public:
        BinaryTree();
        void createTree(Sheet*);
        void travel(int);
        void tragra(int a, int b, int c, int d);
        void suprimir(int);
        ~BinaryTree();
};

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

    void insertarInicio(int valor);
    bool buscarlos(int dato);
    bool buscar(int dato);
    bool buscar2();
    bool recorrerPrimero();
    bool recorrerUltimo();
    bool burbujaWhile();
    void vaciar();
};
