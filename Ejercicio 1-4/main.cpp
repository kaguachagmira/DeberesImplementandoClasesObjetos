/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado: Ejercicios Para Realizar la Conjunta                  *
 *            usando Clases POO                                     *
 * Alumno:Kevin Guachagmira, Cristian Barragan, Jonathan Altamirano *
 * Fecha de inicio: 13/02/2018	Fecha de modificacion: 13/02/2017   *
 * Docente: Ing. Fernando Solis                                     *
 * author: Guachagmira Kevin                                        *
 ********************************************************************/

#include <iostream>
#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <dos.h>


using namespace std;
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
inline int SetColor(const int foreground, const int background)
{

    int Color = foreground + (background * 16);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Color);
    return 0;
}
int menuBorrar()
{
	const char *opciones[]={"POR PARAMETRO      ","POR EXCEPCIONES    "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++)
        {
			gotoxy(i,8);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=7;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("MENU DE BORRADO\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite==true);

	return selec;
}
int menuListas()
{
	const char *opciones[]={"PRIMERA LISTA ","SEGUNDA LISTA    "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++)
        {
			gotoxy(i,8);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=7;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("MENU DE LISTAS\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite==true);

	return selec;
}
int menuSiNo()
{
	const char *opciones[]={"   SI  "," NO  "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++)
        {
			gotoxy(i,8);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=7;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("DESEA AGREGAR UNA EXCEPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite==true);

	return selec;
}
int menuPrincipal()
{
	const char *opciones[]={"INGRESO DE DATOS      ","REPARAR               ","UNIR                  ","BORRAR                ","AGREGAR EXCEPCIONES     ","IMPRIMIR                ","SALIR                    "}; //OPCIONES
	int n=7; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++){
			gotoxy(i,10);
			printf ("-");
			gotoxy(i,0);
			printf ("-");
		}
		for (int i=0;i<=10;i++)
		{
			gotoxy(1,i);
			printf ("|");
			gotoxy(67,i);
			printf ("|");
		}
		//imprime titulo
		gotoxy(25,0); printf("MENU PROBLEMA 1-4\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		//imprime flecha de seleccion
		//gotoxy(5,5+selec); SetColor(3, 7);printf("==>");
		//imprime opciones
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,7);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=_getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla){
			case 72:
				selec--;
				if(selec<1){
					selec=n;
				}
				break;
			case 80:
				selec++;
				if(selec>n){
					selec=1;
				}
				break;
			case 13:
				repite=false;
				break;
		}
	}while(repite==true);

	return selec;
}
long int  insertar (long int val, char *mensaje)
{
    int aux;
    printf ("%s",mensaje);
    do
    {
        fflush(stdin);
        printf (": [ ]\b\b");
        aux=scanf ("%d",&val);
        if (aux==1 ) {
            if (val >=0)
            {

            }
            else
            {
                printf("\n Ingreso no valido");
                aux=0;

            }

        }

        else
        {
            printf ("\n Ingreso no valido");
        }
    }while (aux==0&& val <=0);

return val;

}
int verificarCantidad(int cont,int datoPosicion)
{
    if(datoPosicion> cont || datoPosicion < 0)
    {
        return 0;
    }
    else
        return 1;
}
int ingresoEx(int *p, int *dimension)
{
    int ex;
    int sino=1;
    int cont=0;
    int i=0;
    while(sino==1)
    {
        system ("cls");
        printf("\nIngrese un valor para el arreglo de exepciones: [ ]\b\b");
        scanf("%d",p);
        p++;
        *dimension++;
        system ("cls");
        sino=menuSiNo();
    }
    printf("\n Estas son las excepciones que se han agregado: ");
    for(i=0;i<*dimension;i++)
    {
        printf("%d",*p);
    }
}
void encerar(int *p)
{
    int i=0;
    for(i=0;i<20;i++)
    {
        *(p+i)=-1;
    }
}
int main()
{
    ListaSimple lista1;
    ListaSimple lista2;
    ListaSimple listaUnida;
    int opcion;
    int datoEntero = -1;
    int menuLista;
    int cont1=0;
    int cont2=0;
    int valor=-1;
    int correccion=-1;
    int reparar;
    int varBorrar;
    int datoPosicion=-1;
    int validacionExistencia;
    int validacionExcepcion1=0;
    int validacionExcepcion2=0;
    int *excepciones1;
    int *excepciones2;
    int A[20],dimension1=0;
    excepciones1=A;
    int B[20],dimension2=0;
    excepciones2=B;
    int D1=0;
    int D2=0;
    do
    {
        system ("cls");
        opcion=menuPrincipal();
        switch (opcion)
        {
        case 1:
            {
                system("cls");
                menuLista=menuListas();
                if(menuLista==1)
                {
                    if(lista1.listaVacia()==true)
                    {
                        system ("cls");
                        printf("\nPrimero se debe crear la Primera Lista con un dato\n");
                        datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                        lista1.insertarInicio(datoEntero);
                        printf("\nPrimera Lista creada con exito\n");
                        system("pause");
                        cont1+=1;
                        printf("\n");
                        lista1.imprimir();
                    }
                    else
                    {
                        system ("cls");
                        datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                        lista1.insertarInicio(datoEntero);
                        cont1+=1;
                        printf("\n");
                        lista1.imprimir();
                    }

                }
                else if(menuLista==2)
                {
                    if(lista2.listaVacia()==true)
                    {
                        system ("cls");
                        printf("\nPrimero se debe crear la Segunda Lista con un dato\n");
                        datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                        lista2.insertarInicio(datoEntero);
                        printf("\nSegunda Lista creada con exito\n");
                        system("pause");
                        cont2+=1;
                        printf("\n");
                        lista2.imprimir();
                    }
                    else
                    {
                        system ("cls");
                        datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                        lista2.insertarInicio(datoEntero);
                        cont2+=1;
                        printf("\n");
                        lista2.imprimir();
                    }
                }
                break;
            }
        case 2:
            {
                system("cls");
                reparar=0;
                menuLista=menuListas();
                if(menuLista==1)
                {
                    if(lista1.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Primera Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system ("cls");
                        valor=insertar(valor,"INGRESE UN VALOR PARA X");
                        correccion= insertar(correccion,"INGRESE UN VALOR PARA LA CORRECCION");
                        reparar=lista1.reparar(lista1.primero, valor, correccion);
                        if(reparar==0)
                        {
                            printf("\nEl valor de x=[%d] no se encontro en la Lista por tanto no ocurrio una Reparacion \n",valor);
                            system("pause");
                        }
                        else if(reparar==1)
                        {
                            printf("\La correcion ha sido generada en todos los elementos x=[%d] \n",valor);
                            system("pause");
                            printf("\n");
                            lista1.imprimir();
                        }
                    }

                }
                if(menuLista==2)
                {

                    if(lista2.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Segunda Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        system ("cls");
                        valor=insertar(valor,"INGRESE UN VALOR PARA X");
                        correccion= insertar(correccion,"INGRESE UN VALOR PARA LA CORRECCION");
                        reparar=lista2.reparar(lista2.primero, valor, correccion);
                        if(reparar==0)
                        {
                            system ("cls");
                            printf("\nEl valor de x=[%d] no se encontro en la Lista por tanto no ocurrio una Reparacion \n",valor);
                            system("pause");
                        }
                        else if(reparar==1)
                        {
                            system ("cls");
                            printf("\La correcion ha sido generada en todos los elementos x=[%d] \n",valor);
                            system("pause");
                            printf("\n");
                            lista2.imprimir();
                        }
                    }
                }
                break;
            }
        case 3:
            {
                system("cls");
                if(lista1.listaVacia()==true || lista2.listaVacia()==true)
                {
                    system ("cls");
                    printf("No se puede generar la Union de Listas si una de los dos estan vacias !!");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    listaUnida.unirListas(lista1.primero,lista2.primero);
                    printf("\n");
                    listaUnida.imprimir();
                }
                break;
            }
        case 4:
            {
                system("cls");
                menuLista=menuListas();
                if(menuLista==1)
                {
                    if(lista1.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Primera Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        varBorrar=menuBorrar();
                        if(varBorrar==1)
                        {
                            system ("cls");
                            datoPosicion=insertar(datoEntero,"INGRESE LA POSICION DEL NODO A ELIMINAR");
                            validacionExistencia = verificarCantidad(cont1,datoPosicion);
                            if(validacionExistencia==1)
                            {
                                lista1.eliminarPorPosicion(datoPosicion);
                                cont1-=1;
                            }
                            else if (validacionExistencia==0)
                            {
                                printf("\nEL NODO QUE SE DESEA ELIMINAR NO ES VALIDO\n");
                                system("pause");
                            }
                        }
                        else if(varBorrar==2)
                        {

                            if(validacionExcepcion1==0)
                            {
                                system ("cls");
                                printf("Aun no se ha creado el puntero de excepciones !!");
                                printf("\n");
                                system("pause");
                            }
                            else
                            {
                                // ELIMINAR POR ARREGLO DE EXCEPCIONES
                                lista1=lista1.crop(lista1.primero, excepciones1);
                            }
                        }
                    }
                }
                else if(menuLista==2)
                {
                    if(lista2.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Primera Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        varBorrar=menuBorrar();
                        if(varBorrar==1)
                        {
                            system ("cls");
                            datoPosicion=insertar(datoEntero,"INGRESE LA POSICION DEL NODO A ELIMINAR");
                            validacionExistencia = verificarCantidad(cont2,datoPosicion);
                            if(validacionExistencia==1)
                            {
                                lista2.eliminarPorPosicion(datoPosicion);
                                cont2-=1;
                            }
                            else if (validacionExistencia==0)
                            {
                                printf("\nEL NODO QUE SE DESEA ELIMINAR NO ES VALIDO\n");
                                system("pause");
                            }
                        }
                        else if(varBorrar==2)
                        {

                            if(validacionExcepcion2==0)
                            {
                                system ("cls");
                                printf("Aun no se ha creado el puntero de excepciones !!");
                                printf("\n");
                                system("pause");
                            }
                            else
                            {
                                // ELIMINAR POR ARREGLO DE EXCEPCIONES
                                lista2=lista2.crop(lista2.primero, excepciones2);
                            }
                        }
                    }
                }
                break;
            }
        case 5:
            {
                system("cls");
                printf("\nSeleccione la lista a la cual requiere ingresar exepciones \n");
                system("pause");
                system ("cls");
                menuLista= menuListas();
                if(menuLista==1)
                {
                    //system ("cls");
                    //excepciones1=excep1;
                    encerar(excepciones1);
                    ingresoEx(excepciones1,&D1);
                    validacionExcepcion1+=1;
                }
                else if(menuLista==2)
                {
                    //system ("cls");
                     //excepeciones2=excep2;
                     encerar(excepciones2);
                     ingresoEx(excepciones2,&D2);
                     validacionExcepcion2+=1;
                }
                break;
            }
        case 6:
            {
                system("cls");
                menuLista=menuListas();
                if(menuLista==1)
                {
                    if(lista1.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Primera Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        lista1.imprimir();
                    }
                }
                else if(menuLista==2)
                {
                    if(lista2.listaVacia()==true)
                    {
                        system ("cls");
                        printf("Aun no se han Ingresado datos en la Primera Lista !!");
                        printf("\n");
                        system("pause");
                    }
                    else
                    {
                        lista2.imprimir();
                    }
                }
                break;
            }
        case 7:
            {
                return 0;
                break;
            }
        }
    }while(opcion!=7);
}
