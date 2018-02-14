/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado:ARBOL BINARIO                                          *
 * Alumno:Kevin Guachagmira                                         *
 * Fecha de inicio: 10/12/2017	Fecha de modificacion: 09/01/2018   *
 * Docente: Ing. Fernando Solis                                     *
 ********************************************************************/
#include <iostream>
#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <pthread.h>
#include <dos.h>
#include <graphics.h>
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
int menuImpresion()
{
    system("color 03");
	const char *opciones[]={"    IMPRIMIR ARBOL DE INGRESO DATO     ","     IMPRIMIR ARBOL DE INGRESO CADENA    "}; //OPCIONES
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
		gotoxy(25,0); printf("SELECCIONE LA OPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla)
		{
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
int menuOrden()
{
    system("color 03");
	const char *opciones[]={"    PREORDEN     ","     INORDEN     ","     POSORDEN     "}; //OPCIONES
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
		gotoxy(25,0); printf("SELECCIONE LA OPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla)
		{
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
int menu()
{
    system("color 03");
	const char *opciones[]={"    INGRESO UNO A UNO     ","     INGRESO POR CADENA     ","     IMPRESION     ","     SALIR     "}; //OPCIONES
	int n=4; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("SELECCIONE LA OPCION\n\n");
	do{
		//system("cls");
		gotoxy(25,2); printf("    ");
		gotoxy(25,3); printf("    ");
		gotoxy(25,4); printf("    ");
		gotoxy(25,5); printf("    ");
		gotoxy(25,6); printf("    ");
		gotoxy(25,7); printf("    ");
		gotoxy(25,8); printf("    ");
		for(int i=0;i<n;i++){
			gotoxy(30,2+i);
			printf("                                         ");
		}
		for(int i=0;i<n;i++){
			gotoxy(29,3+i);
			printf("%s ",*(opciones+i));
		}
		printf ("\n");
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
		SetColor(7,0);
		do{
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13);
		switch(tecla)
		{
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
int separarDatos(string lista, int &cont)
{
	string dato;
	char c;
	int num;
	do {
		//strcat(dato.c_str(),lista[i]);
		if (lista[cont] == ',')cont++;
		dato = dato + lista[cont];
		cont++;
	} while ((c = lista[cont]) != ',' && (c = lista[cont]) != '\0');
	//cout << "dato: " << dato << endl;
	num = atof(dato.c_str());
	return num;
}
char *solo_letras(char A[])
{
	char letra;
	int i=0,l=0;
	i=0;
		fflush(stdin);
		letra=getch();
		while(letra!=13 && i<50)
		{
		fflush(stdin);
		if(letra!=8)
			{
				if((letra>=48 && letra<=57)||(letra==','))
				{
					if(letra!=13)
					{
						printf("%c",letra);
						fflush(stdin);
						A[i]=letra;
						i++;
					}
				}
			}
			else
			{
				l=strlen(A);
				if(l>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					A[l-1]='\0';
					i--;
				}
			}
			letra=getch();
		}
		A[i]='\0';
	return A;
}
long int  ingreso (long int val)
{
    int aux;
    do
    {
         fflush(stdin);
        printf ("\n INGRESE EL VALOR ENTERO POSITIVO:");
    aux=scanf ("%d",&val);
    if (aux==1 ) {
        if (val >0)
        {
            printf ("\n INGRESO SATISFACTORIO...\n");
            system("color B");


        }
        else {
            printf("\n ingreso no valido");
            aux=0;
            system("color C");
        }

    }

    else
    {
        printf ("\n\n INCORRECTO \n ");
        system("color C");
    }


    }while (aux==0&& val <=0);

return val;

}

int main()
{
    int gdriver=DETECT, gmode, contador=0;
    initgraph(&gdriver,&gmode,"C:\BORLANDC\BGI");  //Iniciamos el modo gráfico.
    BinaryTree *lTree = new BinaryTree();
    Sheet *lSheet;
    BinaryTree *l2Tree = new BinaryTree();
    Sheet *l2Sheet;
    int aux=0;
    int option;
    int data;
    int i=0;
    int cont=0;
    int validar1=0,validar2=0;
    int retorno=0;
    int mainprintf;
    char stri[100];
    bool ver;
    bool ver2;
    bool repite;
    bool repites;
    bool ceros;
    string cade;
    ListaDoble listadoble;
    ListaDoble listadoble2;
    do
    {
        system("cls");
        option=menu();
       // scanf("%d",&option);
        switch(option)
        {
        case 1:
            {
                data=-1;
                if(listadoble.listaVacia()==true)
                {
                    system("cls");
                    printf("****************HA ELEGIDO INGRESO POR DATO**************\n\n");
                    printf("\nIngrese un valor: ");
                    data=ingreso(data);
                    listadoble.insertarInicio(data);
                    lSheet = new Sheet(data);
                    lTree->createTree(lSheet);
                }
                else
                {
                    do
                    {
                        system("cls");
                        printf("****************HA ELEGIDO INGRESO POR DATO**************\n\n");
                        printf("\nIngrese un valor: ");
                        data=ingreso(data);
                        repite=listadoble.buscar(data);
                        if(repite==true)
                        {
                            printf("\nNo valido porfavor vuelva a ingresar\n");
                            system("pause");
                        }
                    }while(repite==true);
                    lSheet = new Sheet(data);
                    lTree->createTree(lSheet);
                    listadoble.insertarInicio(data);
                }
                validar1=1;
                break;
            }
        case 2:
            {
                do
                {
                    system("cls");
                    printf("****************HA ELEGIDO INGRESO POR CADENA**************\n\n");
                    printf("Ingrese la cadena de numeros separados por una coma: \n");
                    //solo_letras(stri);
                    cin>>cade;
                    //cade=stri;
                    aux=cade.size();
                    cont=0;
                    for(i=0 ; i<aux;i++)
                    {
                        retorno=separarDatos(cade,cont);
                        listadoble2.insertarInicio(retorno);
                        if(cont+1>aux)
                        {
                            break;
                        }
                    }
                    repites=listadoble2.burbujaWhile();
                    if(repites==true)
                    {
                        printf("\nLa Cadena que ingreso contiene Elementos repetidos vuelva a ingresar\n");
                        system("pause");
                        listadoble2.vaciar();
                        cade.clear();
                        stri[0]='\0';
                    }
                }while(repites==true);
                aux=cade.size();
                cont=0;
                for(i=0 ; i<aux;i++)
                {
                    retorno=separarDatos(cade,cont);
                    l2Sheet = new Sheet(retorno);
                    l2Tree->createTree(l2Sheet);
                    if(cont+1>aux)
                    {
                        break;
                    }
                }
                ver=listadoble2.recorrerPrimero();
                ver2=listadoble2.recorrerUltimo();
                if(ver==true&&ver2==true)
                {
                    printf("\nLA CADENA INGRESADA CORRESPONDE A UN RECORRIDO INORDEN\n");
                    printf("\nIMPRESION POR PREORDEN: ");
                    l2Tree->travel(1);
                    printf("\n");
                    system("pause");
                    printf("\nIMPRESION POR POSTORDEN: ");
                    l2Tree->travel(3);
                    printf("\n");
                    system("pause");
                }
                else if(ver2==true)
                {
                    printf("\nLA CADENA INGRESADA CORRESPONDE A UN RECORRIDO PREORDEN\n");
                    printf("\nIMPRESION POR INORDEN: ");
                    l2Tree->travel(2);
                    printf("\n");
                    system("pause");
                    printf("\nIMPRESION POR POSTORDEN: ");
                    l2Tree->travel(3);
                    printf("\n");
                    system("pause");
                }
                else
                {
                    printf("\nLA CADENA INGRESADA CORRESPONDE A UN RECORRIDO POSTORDEN\n");
                    printf("\nIMPRESION POR INORDEN: ");
                    l2Tree->travel(2);
                    printf("\n");
                    system("pause");
                    printf("\nIMPRESION POR PREORDEN: ");
                    l2Tree->travel(1);
                    printf("\n");
                    system("pause");
                }
                validar2=1;
                break;
            }
        case 3:
            {
                if(validar1==0 && validar2==0)
                {
                    system("cls");
                    printf("\nAun no se ha ingresado valores al ARBOL\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    mainprintf=menuImpresion();
                    if(mainprintf==1)
                    {
                        if(validar1==1)
                        {
                            system("cls");
                            data=menuOrden();
                            gotoxy(0,10);
                            lTree->travel(data);
                            printf("\n");
                            system("pause");
                            system("cls");
                            cleardevice();
                            lTree->tragra(15,3,7,0);
                        }
                        else
                        {
                            system("cls");
                            printf("\nAun no se ha ingresado valores al ARBOL DE DATO A DATO\n");
                            system("pause");
                        }
                    }
                    else if(mainprintf==2)
                    {
                        if(validar2==1)
                        {
                            system("cls");
                            data=menuOrden();
                            gotoxy(0,10);
                            l2Tree->travel(data);
                            printf("\n");
                            system("pause");
                            system("cls");
                            cleardevice();
                            l2Tree->tragra(15,3,7,0);
                        }
                        else
                        {
                            system("cls");
                            printf("\nAun no se ha ingresado valores al ARBOL DE DATO A DATO\n");
                            system("pause");
                        }
                    }
                }
                break;
            }
        case 4:
            {
                return 0;
            }
        }

} while(option!=4);
}
