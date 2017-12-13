#include <iostream>
#include "listadoble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define ASCENDENTE 1
#define DESCENDENTE 0


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
int menuBuscar()
{
	int cont=1;
	const char *opciones[]={"BUSCAR POR POSICION","BUSCAR POR DATO    "}; //OPCIONES
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
		gotoxy(25,0); printf("MENU DE BUSCAR\n\n");
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
			tecla=getch();
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
int menuEliminar()
{
	int cont=1;
	const char *opciones[]={"ELIMINAR AL INICIO          ","ELIMINAR CUALQUIERA         ","ELIMINAR AL FINAL           "}; //OPCIONES
	int n=3; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU DE ELIMINAR\n\n");
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
			tecla=getch();
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
int menuIngreso()
{
	int cont=1;
	const char *opciones[]={"INGRESAR AL INICIO","INGRESAR EN MEDIO ","INGRESAR AL FINAL "}; //OPCIONES
	int n=3; //NUMERO OPCIONES
	int selec=1;
	int tecla;
	bool repite=true;

	for (int i=1;i<=67;i++){
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
		gotoxy(25,0); printf("MENU DE INGRESO\n\n");
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
			tecla=getch();
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
	int cont=1;
	const char *opciones[]={"INGRESO DE DATOS   ","BUSCAR DATO       ","IMPRIMIR          ","BORRAR            ","SALIR             "}; //OPCIONES
	int n=5; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU COMPLETO LISTAS DOBLES\n\n");
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
			tecla=getch();
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
    }while (aux==0&& val <0);

return val;

}
int verificarCantidad(int cont,int datoPosicion)
{
    if(datoPosicion> cont || datoPosicion == 0)
    {
        return 0;
    }
    else
        return 1;
}
int main()
{
    ListaDoble listadoble;
	int datoEntero = -1;
	int opc;
	int variableIngreso = 0;
    int variableEliminar = 0;
    int variableBuscar = 0;
	int datoPosicion = -1;
	int cont=0;
    int validacionExistencia;
	system ("cls");
	do{
    system ("cls");
    opc=menuPrincipal();
			switch(opc)
			{
			case 1:
			    {
                    system ("cls");
                    if(listadoble.listaVacia()==true)
                    {
                        printf("\nPrimero se debe crear la lista con un dato\n");
                        datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                        //crearLista(lista,datoEntero);
                        listadoble.insertarInicio(datoEntero);
                        printf("\nLista creada con exito\n");
                        system("pause");
                        cont+=1;
                    }
                    else
                    {
                            variableIngreso=menuIngreso();
                            //retorna una de las 3 opciones

                            if(variableIngreso==1)
                            {
                                system ("cls");
                                datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                                listadoble.insertarInicio(datoEntero);
                                //Ingresar al inicio
                                cont+=1;
                            }
                            else if (variableIngreso==2)
                            {
                                system ("cls");
                                datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO PARA EL DATO");
                                printf("\n");
                                datoPosicion=insertar(datoPosicion,"INGRESE UN VALOR ENTERO PARA LA POSICION");
                                validacionExistencia = verificarCantidad(cont,datoPosicion);
                                if(validacionExistencia==1)
                                {
                                    //Crear para ingresar al medio de donde quiera
                                    listadoble.insertarCualquiera(datoEntero,datoPosicion);
                                    cont+=1;
                                }
                                else if (validacionExistencia==0)
                                {
                                    printf("\nEL NODO AL QUE SE DESEA INGRESAR NO ES VALIDO\n");
                                    system("pause");
                                }
                                //Ingreso al medio
                            }
                            else if(variableIngreso==3)
                            {
                                system ("cls");
                                datoEntero=insertar(datoEntero,"INGRESE UN VALOR ENTERO");
                                listadoble.insertarFinal(datoEntero);
                                //Ingreso al final
                                cont+=1;
                            }
                    }
                    break;
			    }
			case 2:
			    {

			    if(listadoble.listaVacia()==true)
                {
                    system ("cls");
                    printf("Aun no se han Ingresado datos !!");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    system ("cls");
                    variableBuscar=menuBuscar();
                    if(variableBuscar==1)
                    {
                        system ("cls");
                        //Buscar por posicion
                        datoPosicion=insertar(datoEntero,"INGRESE LA POSICION DEL NODO");
                        validacionExistencia = verificarCantidad(cont,datoPosicion);
                        if(validacionExistencia==1)
                        {
                            //Crear funcion para la clase lista para poder buscar dato por posicion
                            listadoble.buscarPorPosicion(datoPosicion);
                        }
                        else if (validacionExistencia==0)
                        {
                            printf("\nEL NODO QUE SE DESEA BUSCAR NO ES VALIDO\n");
                            system("pause");
                        }
                    }
                    else if(variableBuscar==2)
                    {
                        system ("cls");
                        //Buscar por dato por valor entero que envio
                        datoEntero = insertar(datoEntero,"INGRESE EL DATO QUE DESEA BUSCAR");
                        listadoble.buscarPorValor(datoEntero);
                    }
                }
				break;
			    }
			case 3:
			    {
			    if(listadoble.listaVacia()==true)
                {
                    system ("cls");
                    printf("Aun no se han Ingresado datos !!");
                    printf("\n");
                    system("pause");
                }
                else
                {
                    //Imprimir la Lista
                    system ("cls");
                    printf("Actualmente se encuentran estos datos en la Lista: ");
                    //listadoble.mostrar(ASCENDENTE);
                    listadoble.imprimir();
                    printf("\n");
                    system("pause");
                }
                break;
			    }
			case 4:
			    {
                system ("cls");
                if(listadoble.listaVacia()==true)
                {
                    system ("cls");
                    printf("Aun no se han Ingresado datos !!");
                    printf("\n");
                    system("pause");
                }
                else
                {
                            variableEliminar=menuEliminar();
                            //retorna una de las 3 opciones

                            if(variableEliminar==1)
                            {
                                //Eliminar al inicio
                                system ("cls");
                                listadoble.borrarInicio();
                            }
                            else if (variableEliminar==2)
                            {
                                 //Eliminar al medio
                                system ("cls");
                                datoEntero=insertar(datoEntero,"INGRESE EL VALOR ENTERO QUE DESEA ELIMINAR");
                                listadoble.borrarCualquiera(datoEntero);

                            }
                            else if(variableEliminar==3)
                            {
                                //Eliminar al final
                                system ("cls");
                                listadoble.borrarFinal();
                            }
                }
				break;
			    }
			case 5:
			    {
				system ("cls");
				printf("GRACIAS POR USAR EL PROGRAMA !! ;D");
				break;
			    }
			}
	}while(opc!=5);
	gotoxy(3,17);
	return (0);
}
