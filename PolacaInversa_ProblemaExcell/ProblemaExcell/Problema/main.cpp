/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado: Utilizando unicamente Colas realizar el problema      *
 *            planteado en Excell                                  *
 * Alumno:Kevin Guachagmira                                         *
 * Fecha de inicio: 16/12/2017	Fecha de modificacion: 17/12/2017   *
 * Docente: Ing. Fernando Solis                                     *
 * author: Guachagmira Kevin                                        *
 ********************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include <string.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
int main()
{
    ListaSimple lista;
    int clientes;
    int tLlegada;
    int tServicio;
    printf("Ingrese el numero de clientes: ");
    scanf("%d",&clientes);

    tLlegada = lista.randomico(1);
    tServicio = lista.randomico(1);
    lista.ingresar(tLlegada,tServicio);
    lista.primerCliente();
    for(int i=1;i<clientes;i++)
    {
        tLlegada=lista.randomico(2);
        tServicio=lista.random(clientes);
        lista.ingresar(tLlegada,tServicio);
        lista.restodeClientes();
    }
    lista.impresion();
}
