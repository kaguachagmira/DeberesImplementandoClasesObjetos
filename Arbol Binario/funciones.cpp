/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado:ARBOL BINARIO                                          *
 * Alumno:Kevin Guachagmira                                         *
 * Fecha de inicio: 10/12/2017	Fecha de modificacion: 09/01/2018   *
 * Docente: Ing. Fernando Solis                                     *
 ********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"
#include <windows.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>
#include<math.h>
using namespace std;

Sheet::Sheet(int data)
{
    this->data=data;
    right = NULL;
    left = NULL;
}
Sheet::~Sheet()
{

}
BinaryTree::BinaryTree()
{
    root = NULL;
}
void BinaryTree::createTree(Sheet *newData)
{
    root = add(root,newData);
}
Sheet* BinaryTree::add(Sheet *root, Sheet *newData)
{
    if(root == NULL)
    {
        root = newData;
    }
    else
    {
        if(newData->getValue() < root->getValue())
        {
            root->left= add(root->left,newData);
        }
        else
        {
            root->right = add(root->right,newData);
        }
    }
    return root;
}
void BinaryTree::preOrden(Sheet *root)
{
    if(root != NULL)
    {
        printf("%d, ",root->getValue());
        preOrden(root->left);
        preOrden(root->right);
    }
}

void BinaryTree::inOrden(Sheet *root)
{
    if(root != NULL)
    {
        inOrden(root->left);
        printf("%d, ",root->getValue());
        inOrden(root->right);
    }
}
void BinaryTree::postOrden(Sheet *root)
{
    if(root != NULL)
    {
        printf("%d, ",root->getValue());
        postOrden(root->left);
        postOrden(root->right);
    }
}
void BinaryTree::graph(Sheet *root,int a , int b, int c , int d)
{
    char aux[3];
    if(root!=NULL)
    {
        itoa(root->getValue(),aux,10);
        setbkcolor(15);
        setcolor(1);
        circle(300+a,75+b,14);
        setcolor(4);
        outtextxy(295+a,75+b,aux);
        setcolor(2);
        if(d==1)
        {
        line(300+a-pow(2,c+1),b+14,300+a,61+b);
        }
        else if(d==2)
        {
        line(300+a-pow(2,c+1),b+14,300+a,61+b);
        }
        graph(root->left,a-pow(2,c)- pow(2,d-4),b+75,c-1,1);
        graph(root->right,a+pow(2,c)+pow(2,d-4),b+75,c-1,2);
    }
}
void BinaryTree::tragra(int a , int b , int c , int d)
{
    graph(root, a ,  b,  c ,  d);
}
void BinaryTree::travel(int accion)
{
    switch(accion)
    {
        case 1:
            {
                preOrden(root);
                break;
            }
        case 2:
            {
                inOrden(root);
                break;
            }
        case 3:
            {
                postOrden(root);
                break;
            }
        default:
            {
                printf("Opcion no valida\n");
                break;
            }
    }
}
int BinaryTree::getInfo_der(Sheet *q)
{
    if(q->right== NULL)
    {
        return q->getValue();
    }
    else
    {
        return getInfo_der(q->right);
    }
}

Sheet* BinaryTree::supr(Sheet *p, int info)
{
    Sheet *aux;

    if(p != NULL)
        {
        if(p->getValue() == info)
        {
            if(p->left == NULL && p->right == NULL)
            {
                delete p;
                p = NULL;
            }
            else
            {
                if(p->left == NULL && p->right != NULL)
                {
                    aux = p->right;
                    delete p;
                    p = aux;
                }
                else
                {
                    info = getInfo_der(p->left);
                    p->setValue(info);
                    p = p->left;
                    p->right = supr(p->right, info);
                }
            }
        }
        else
        {
            if(info < p->getValue())
            {
                p->left = supr(p->left, info);
            }
            else
            {
                p->right = supr(p->right, info);
            }
        }
    }
    return p;
}
void ListaDoble::insertarInicio(int datoEntero)
{
    Nodo *aux = new Nodo(datoEntero);
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
void ListaDoble::vaciar()
{
    Nodo *aux = primero;
    primero=NULL;
    ultimo=NULL;
}
bool ListaDoble::burbujaWhile()
{
    Nodo *aux=ultimo;
    Nodo *aux2=ultimo;
    aux2=aux2->anterior;
    int i=1;
    int cont=0;
    bool seguir=true;
    bool veri=true;
    while(aux->anterior!=NULL)
    {
        while(aux2->anterior!=NULL)
        {
            if(aux->getValor()== aux2->getValor())
            {
               cont+=1;
            }
            aux2=aux2->anterior;
        }
        aux = aux->anterior;
        aux2=aux;
        aux2=aux2->anterior;
    }
    if(cont==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool ListaDoble::recorrerUltimo()
{
    Nodo *aux=ultimo;
    Nodo *aux2=ultimo;
    aux2=aux2->anterior;
    int i=1;
    bool seguir=true;
    bool veri=true;
    while(aux2!=NULL)
    {
        if(aux->getValor()<aux2->getValor())
        {
           veri=true;
        }
        else
        {
            veri=false;
            return veri;
        }
        aux2=aux2->anterior;
    }
    return veri;
}
bool ListaDoble::recorrerPrimero()
{
    Nodo *aux=primero;
    Nodo *aux2=primero;
    aux2=aux2->siguiente;
    int i=1;
    bool seguir=true;
    bool veri=true;
    while(aux2!=NULL)
    {
        if(aux->getValor()>aux2->getValor())
        {
           veri=true;
        }
        else
        {
            veri=false;
            return veri;
        }
        aux2=aux2->siguiente;
    }
    return veri;
}
bool ListaDoble :: buscar2()
{
    Nodo *aux_buscar = primero;
    int posicion = 1;
    int prueba = 0;
    if(aux_buscar->siguiente==NULL && aux_buscar->getValor()==0)
    {
        return true;
    }
    else
    {
        while(aux_buscar->siguiente!=NULL)
        {
            if(aux_buscar->getValor()==0)
            {
                return true;
                prueba=1;
            }
            posicion+=1;
            aux_buscar=aux_buscar->siguiente;
        }
    }
    if(prueba==0)
    {
        return false;
    }
}
bool ListaDoble :: buscar(int dato)
{
    Nodo *aux_buscar = primero;
    int posicion = 1;
    int prueba = 0;
    if(aux_buscar->siguiente==NULL && aux_buscar->getValor()==dato)
    {
        return true;
    }
    else
    {
        while(aux_buscar->siguiente!=NULL)
        {
            if(aux_buscar->getValor()==dato)
            {
                return true;
                prueba=1;
            }
            posicion+=1;
            aux_buscar=aux_buscar->siguiente;
        }
    }
    if(prueba==0)
    {
        return false;
    }
}
bool ListaDoble :: buscarlos(int dato)
{
    Nodo *aux_buscar = primero;
    int posicion = 1;
    int prueba = 0;
    if(aux_buscar->siguiente==NULL && aux_buscar->getValor()==dato)
    {
        prueba=1;
    }
    else
    {
        while(aux_buscar->siguiente!=NULL)
        {
            if(aux_buscar->getValor()==dato)
            {
                prueba=1;
            }
            posicion+=1;
            aux_buscar=aux_buscar->siguiente;
        }
    }
    if(prueba==0)
    {
        return false;//Nunca se repitio ninguno
    }
    else
    {
        return true;
    }
}
