/********************************************************************
 *          Universidad de las Fuerzas Armadas Espe                 *
 * Enunciado:Proyecto Segundo Parcial Traductor de Español a Ingles *
 * Alumno:Kevin Guachagmira, Cristian Barragan, Jonathan Altamirano *
 * Fecha de inicio: 10/12/2017	Fecha de modificacion: 09/01/2018   *
 * Docente: Ing. Fernando Solis                                     *
 ********************************************************************/
#include <iostream>
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include"imagen.h"
using namespace std;
long int solo_numeros_1(unsigned long int b);
int solo_numeros(int l);
void imagen();
char *solo_letras(char A[]);
void gotoxy(int x,int y);
inline int SetColor(const int foreground, const int background);
void vaciar( char *a);
char *leerfichero(char palabraIng[70] );
char *opcionesRecuperar(char recuperaArc[]);
int menuPrincipal2();
int menubackip();
int menumot();
int menuSiNo();
int menuPrincipal();
long int  insertar (long int val, char *mensaje);
int verificarCantidad(int cont,int datoPosicion);


long int solo_numeros_1(unsigned long int b)
{
    unsigned long int a;
	char caracter;
	int i=0;
		a=b;
		fflush(stdin);
		caracter=getch();
		while(caracter!=13)
		{
		fflush(stdin);
		if(caracter!=8)//borrar
			{
				if((caracter>=48)&&(caracter<=57))//entre 0 y 9
				{
					if(caracter!=13)//enter
					{
						printf("%c",caracter);
						fflush(stdin);
						a=(a*10)+(caracter-48);
						i++;
					}
				}
			}
			else
			{
				if(i>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					a=(a/10);
					i--;
				}
			}
			caracter=getch();
		}
	return a;
}

int solo_numeros(int l)
{
	char caracter;
	int i=0;
		i=0;
		fflush(stdin);
		caracter=getch();
		while(caracter!=13)
		{
		fflush(stdin);
		if(caracter!=8)
			{
				if((caracter>=48)&&(caracter<=57))
				{
					if(caracter!=13)
					{
						printf("%c",caracter);
						fflush(stdin);
						l=(l*10)+(caracter-48);
						i++;
					}
				}
			}
			else
			{
				if(i>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					l=(l/10);
					i--;
				}
			}
			caracter=getch();
		}
	return l;
}

void imagen()
{
    hConWnd = GetConsoleWndHandle();
    if (hConWnd)
    {
    	//codifica bit a bit
        BCX_Bitmap("LOGO.bmp",hConWnd,0,0,120,0,0);

//        system("pause>nul");
//        getchar();
    }
    //system("cls");
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
				if((letra>=65 && letra<=90)||(letra>=97 && letra<=122)||(letra==32))
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

DWORD WINAPI merlin(LPVOID LPARAM)
{
    system("WinAppMSAgentsManagement.exe");
}

void vaciar( char *a)
{
    int i;
    for (i=0;i<50;i++)
    {
        a[i]='\0';
    }
}

char *leerfichero(char palabraIng[70] )
{
    int i;
    FILE *f;
        f=fopen("datos.txt","r");

        for (i=0;!feof(f);i++)
        {
            vaciar(palabraIng);
            fgets(palabraIng,70,f);
        }
     fclose(f);

     return palabraIng;
}

char *opcionesRecuperar(char recuperaArc[])
{
     int i;
     int opcion;
    FILE *f;
        f=fopen("horarios.txt","r");

        for (i=0;!feof(f);i++)
        {
            vaciar(recuperaArc);
            fgets(recuperaArc,50,f);
            printf("->>%d  %s",(i+1), recuperaArc);

        }
     fclose(f);

     printf("\n ESCOJA EL ARCHIVO QUE DESEA RECUPERAR:  ");

    scanf("%d",&opcion);
    FILE *c;
        c=fopen("horarios.txt","r");

        for (i=0;i<opcion;i++)
        {
            vaciar(recuperaArc);

            fgets(recuperaArc,50,c);
            printf("->>%d  %s",(i+1), recuperaArc);

        }
     fclose(c);
    return recuperaArc;
}

int menuPrincipal2()
{
	system("color 03");
	int cont=1;
    long x=0,y=0;
    gotoxy(3, 100);
	printf("F12 AYUDA");
	const char *opciones[]={"INGRESO DE DATOS   ","TRADUCIR DATO      ","IMPRIMIR COLAS     ","BACKUP              ","SALIR             "}; //OPCIONES
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

		do{
                fflush(stdin);
		//imprime titulo
		gotoxy(25,0); printf("MENU TRADUCTOR DE PALABRAS\n\n");

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
                fflush(stdin);
			tecla=getch();
		}while(tecla!=72 && tecla!=80 && tecla!=13&& tecla!=134);
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
			case 134:

			    system("cls");

                break;
		}
	}while(repite==true);

	return selec;

}

int menubackip()
{
    system("color 03");
	int cont=1;
	const char *opciones[]={"    CREAR    ","     RECUPERAR     "}; //OPCIONES
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
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
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

int menumot()
{
    system("color 03");
	int cont=1;
	const char *opciones[]={"    MENU TECLADO    ","     MENU MOUSE     "}; //OPCIONES
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
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
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

int menuSiNo()
{
    system("color 03");
	int cont=1;
	const char *opciones[]={"    SI     ","     NO     "}; //OPCIONES
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
		gotoxy(25,2+selec);SetColor(240,4);printf("    %s",*(opciones+selec-1));
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
        system("color 03");
	int cont=1;
    long x=0,y=0;
	const char *opciones[]={"INGRESO DE DATOS   ","TRADUCIR DATO      ","IMPRIMIR COLAS     ","BACKUP              ","SALIR             "};  //OPCIONES
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
		gotoxy(25,0); printf("MENU TRADUCTOR DE PALABRAS\n\n");
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
		while(!GetAsyncKeyState(MOUSEEVENTF_MOVE&&MOUSEEVENTF_WHEEL))
		{

            POINT mouse;
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {

                GetCursorPos(&mouse);
                x=mouse.x;
                y=mouse.y;
                //printf("La posicion del mouse es %d ; %d \n", mouse.x,mouse.y);
                //Sleep(3000);
            }
            fflush(stdin);
            //tecla=getch();

		}
        if((y>=60 && y<=70) && (x>=150 && x<=286))
        {
            return 1;
        }
        else if ((y>=70 && y<=80) && (x>=150 && x<=286))
        {
            return 2;
        }
        else if ((y>=80 && y<=90) && (x>=150 && x<=286))
        {
            return 3;
        }
        else if ((y>=90 && y<=100) && (x>=150 && x<=286))
        {
            return 4;
        }
        else if ((y>=100 && y<=110) && (x>=150 && x<=286))
        {
            return 5;
        }
        else if ((y>=110 && y<=120) && (x>=150 && x<=286))
        {
            return 5;
        }
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
    HANDLE MiAgente;
    DWORD IdMerlin;
    MiAgente=CreateThread(NULL,0,merlin,NULL,0,&IdMerlin);
    system("color 03");
    ListaSimple listita;
    char palabra[70] ;
	int datoEntero = -1;
	int opc,opc1;
	int sino;
	int variableIngreso = 0;
    int variableEliminar = 0;
    int variableBuscar = 0;
	int datoPosicion = -1;
	int cont=0;
	int resp;
	int i=0;
	char palabraIng[70];
	char horarios[50];
	char recuperarArc[50];
	char validar;
    int validacionExistencia;
    int opcio2;
    int validarBackup=0;
	system ("cls");
	fflush(stdin);
	opc1=menumot();

	do{
            if(opc1==1)
    {
        system("cls");
        opc=menuPrincipal2();
         system("cls");

    }
    else
    {
        system("cls");
        opc=menuPrincipal();
        system("cls");
    }
        fflush(stdin);

			switch(opc)
			{
			case 1:
			    {
                    system ("cls");
                    fflush(stdin);
                    cout<<"Ingrese una palabra"<<endl;
                    fflush(stdin);
                    solo_letras(palabra);
                    for(i = 0; palabra[i]; i++)
                    palabra[i] = tolower(palabra[i]);

                    resp=listita.buscar(palabra);
                    if(resp==1)
                    {
                        system("cls");
                        gotoxy(15,1);
                        printf("La palabra ya existe en la Cola DESEA TRADUCIRLA");
                        sino=menuSiNo();
                        if(sino==1)
                        {
                            FILE *ar=NULL;
                            ar=fopen("datosEsp.txt","w");
                            fprintf(ar, palabra);
                            fclose(ar);
                            system("java -jar traducestesi.jar");
                        }
                        else if(sino==2)
                        {
                            system("cls");
                            printf("Vuelva Pronto !!\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        listita.insertar(palabra);
                    }
                    break;
			    }
			case 2:
			    {
                    system("cls");
                    fflush(stdin);
                    printf("Ingrese una palabra para traducir\n");
                    fflush(stdin);
                    solo_letras(palabra);
                    for(i = 0; palabra[i]; i++)
                    palabra[i] = tolower(palabra[i]);

                    resp=listita.buscar(palabra);
                      if (resp==1)
                      {
                        listita.copiar(palabra);
                        FILE *ar=NULL;
                        ar=fopen("datosEsp.txt","w");
                        fprintf(ar, palabra);
                        fclose(ar);
                        gotoxy(0,15);
                        printf("\nLa palabra traducida es: ");
                        system("java -jar traducestesi.jar");
                        leerfichero( palabraIng);
                        gotoxy(0,16);
                        printf("\nReproduciendo sonido.....\n");
                        system("java -jar C:\\Users\\usuario\\Desktop\\ProyectoTraductorV1\\audio\\dist\\audio.jar");
                        gotoxy(10,30);
                        printf("                                                                                   ");
                        printf("                                                                                   ");
                        system("cls");

                        listita.ficheroTraduccion(palabra, palabraIng);
                      }
                      else
                      {
                          printf("PALABRA NO ENCONTRADA");
                      }
                      system("pause ");


                    break;
			    }
			case 3:
			    {
			        system("cls");
                    listita.imprimir();
                    listita.FicheroCola1();
                    listita.generarPDF1();
                    system("pause ");
                    break;
			    }
			case 4:
			    {
			        system("cls");
			        resp=menubackip();

			        if (resp==1)
                    {
                        system ("cls");
                        listita.backup(horarios);
                        validarBackup++;
                    }
                    else{
                            system ("cls");


                                opcionesRecuperar(recuperarArc);
                                listita.recuperar(recuperarArc);

                    }

                    break;
			    }
            case 5:
                {
                    system("cls");
                    imagen();
                    Sleep(3000);

                    return 0;
                }

			}
	}while(opc!=8);
	gotoxy(3,17);
	return (0);
}
