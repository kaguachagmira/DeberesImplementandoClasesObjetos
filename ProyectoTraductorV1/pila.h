#include<string.h>


#include <iostream>
class Nodo
{
    private:
        char valor[70];
    public:
        Nodo *siguiente;
        Nodo(char valo[70])
        {
            strcpy(valor,valo);
            siguiente = NULL;
        }
    char *getValor()
    {
        return valor;
    }
    void setValor(char valor[70])
    {
        this->valor[70]=valor[70];
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
    void insertar(char valor[]);
    void copiar(char valor[]);
    void insertarcopia(char valor[]);
    void imprimir();
    void imprimir_aux();
    void borrar();
    int buscar(char valor[]);
    void ficheroTraduccion(char palabraEsp[], char palabraIng[]);
    void FicheroCola1();
    void FicheroCola2();
    void generarPDF2();
    void generarPDF1();
    void backup(char horarios[]);
    void recuperar(char recuperarArc[]);
   void vaciar( char *a);

};




