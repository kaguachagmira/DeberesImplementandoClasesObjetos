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
int menuBuscar()
{
    system("cls");
	const char *opciones[]={"POR SEXO-OFICIO       ","POR PARENTESCO"}; //OPCIONES
	int n=2; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU BUSCAR \n\n");
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
string menuOficio()
{
    system("cls");
	const char *opciones[]={"PERIODISTA ","CARPINTERO ","ELECTRICISTA","ARQUITECTO    ","PLOMERO    ","INGENIERO ","NINGUNO"}; //OPCIONES
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
		gotoxy(25,0); printf("MENU OFICIO \n\n");
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
    if(selec==1)
    {
        return "PERIODISTA";
    }
    else if(selec==2)
    {
        return "CARPINTERO";
    }
    else if(selec==3)
    {
        return "ELECTRICISTA";
    }
    else if(selec==4)
    {
        return "DOTERO";
    }
    else if(selec==5)
    {
        return "PLOMERO";
    }
    else if(selec==6)
    {
        return "INGENIERO";
    }
    else if(selec==7)
    {
        return "NINGUNO";
    }
}
string menuSexo()
{
    system("cls");
	const char *opciones[]={"MASCULINO ","FEMENINO "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU SEXO \n\n");
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
    if(selec==1)
    {
        return "MASCULINO";
    }
    else if(selec==2)
    {
        return "FEMENINO";
    }
}
int menuEditar()
{
    system("cls");
	const char *opciones[]={"TENER UN HIJO     ","CALCULAR BISNIETOS "}; //OPCIONES
	int n=2; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU EDITAR \n\n");
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
    system("cls");
	const char *opciones[]={"INGRESO DE PERSONAS      ","EDITAR DATOS               ","BUSQUEDA                  ","IMPRIMIR LISTADO                    ","SALIR               "}; //OPCIONES
	int n=4; //NUMERO OPCIONES
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
		gotoxy(25,0); printf("MENU PROBLEMA 8-12\n\n");
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
int main()
{
    RelacionSocial individuos;
    Persona *busqueda;
    string nombre;
    string oficio;
    string sexo;
    string meOficio;
    int amigos;
    int opedi;
    int opcion;
    int opcBuscar;
    int bisnietos;
    do
    {
        system("cls");
        opcion=menuPrincipal();
        switch (opcion)
        {

        case 1:
            {
                if(individuos.listaVacia()==true)
                {
                    system("cls");
                    //Ingreso del Nombre
                    printf("\nPorfavor Ingrese el nombre de la Persona: ");
                    cin>>nombre;
                    //Seleccion del Oficio
                    oficio=menuOficio();
                    system("cls");
                    //Seleccion del Sexo
                    sexo=menuSexo();
                    system("cls");

                    Persona *raza = new Persona(nombre,oficio,sexo,0);
                    individuos.crearPersona(raza);
                    system("cls");
                    individuos.imprimirDatos(individuos.primero);
                    printf("\n");
                }
                else
                {
                    system("cls");
                    //Ingreso del Nombre
                    printf("\nPorfavor Ingrese el nombre de la Persona: ");
                    cin>>nombre;
                    //Seleccion del Oficio
                    oficio=menuOficio();
                    system("cls");
                    //Seleccion del Sexo
                    sexo=menuSexo();
                    system("cls");

                    Persona *raza = new Persona(nombre,oficio,sexo,0);
                    individuos.crearPersona(raza);
                    system("cls");
                    individuos.imprimirDatos(individuos.primero);
                    printf("\n");
                }
                system("cls");
                break;
            }
        case 2:
            {
                system("cls");
                if(individuos.listaVacia()==true)
                {
                    printf("\nAun no se han Registrado Ninguna Persona\n");
                    system("pause");
                }
                else
                {
                    opedi=menuEditar();
                    if(opedi==1)
                    {
                        system("cls");
                        cout<<"\nIngrese el nombre de la Persona a la cual le desea editar los datos: \n";
                        cin>>nombre;
                        individuos.busqueda(individuos.primero,nombre);
                    }
                    else if(opedi==2)
                    {
                        system("cls");
                        cout<<"\nIngrese el nombre de la Persona a la cual le desea calcular los Bisnietos: \n";
                        cin>>nombre;
                        Persona *pers = new Persona();
                        *pers=individuos.buscar(nombre);
                        bisnietos=individuos.cuantosBisNietos(pers);
                        system("cls");
                        cout<<"\nLa persona: "<<pers->getNombre()<<" tiene: "<<bisnietos<<" Bisniestos\n";
                        system("pause");
                    }
                }


                system("cls");
                break;
            }
        case 3:
            {
                system("cls");
                opcBuscar=menuBuscar();
                if(opcBuscar==1)
                {
                    system("cls");
                    sexo=menuSexo();
                    system("cls");
                    oficio=menuOficio();
                    individuos.buscarSO(sexo,oficio);
                }
                else if(opcBuscar==2)
                {
                    system("cls");
                    cout<<"\nIngrese el nombre de la Primera Persona : \n";
                    cin>>nombre;
                    Persona *pers = new Persona();
                    *pers=individuos.buscar(nombre);
                    system("cls");
                    cout<<"\nIngrese el nombre de la Segunda Persona : \n";
                    cin>>nombre;
                    Persona *perso = new Persona();
                    *perso=individuos.buscar(nombre);
                    system("cls");
                    individuos.parentesco(pers,perso);
                }
                system("cls");
                break;
            }
        case 4:
            {
                system("cls");
                return 0;
                break;
            }
        }

    }while(opcion!=5);
}
