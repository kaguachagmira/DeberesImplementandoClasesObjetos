#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"
#include <windows.h>
#include <string.h>
#include <dos.h>
#include<math.h>
#include <iostream>
#include <conio.h>
using namespace std;

int menuSexo();
void gotoxy(int,int);
inline int SetColor(const int foreground, const int background);

string menuOficios()
{
    system("cls");
	const char *opciones[]={"PERIODISTA ","CARPINTERO ","ELECTRICISTA","DOTERO    ","PLOMERO    ","INGENIERO ","NINGUNO"}; //OPCIONES
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
string menuSexos()
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
void RelacionSocial::crearPersona(Persona *aux)
{
    if(listaVacia()==true)
    {
        aux->hermanoMe;
        aux->hermanoMa;
        aux->primerHijo;
        aux->padre;
        aux->madre;
        aux->conyuge;
        aux->friends;
        primero=ultimo=aux;
    }
    else
    {
        aux->hermanoMe;
        aux->hermanoMa;
        aux->primerHijo;
        aux->padre;
        aux->madre;
        aux->conyuge;
        aux->friends;
        aux->siguiente=primero;
        primero->anterior=aux;
        primero=aux;
    }
}
void RelacionSocial::parentesco(Persona *primera,Persona *segunda)
{
    if(primera->conyuge==segunda->conyuge)
    {
        system("cls");
        cout<<"\nLa Persona "<<primera->getNombre()<<" es conyuge de : "<<segunda->getNombre();
        system("pause");
    }
    if(primera->padre==segunda->hijo)
    {
        system("cls");
        cout<<"\nLa Persona "<<primera->getNombre()<<" es padre de : "<<segunda->getNombre();
        system("pause");
    }
    if(primera->madre==segunda->hijo)
    {
        system("cls");
        cout<<"\nLa Persona "<<primera->getNombre()<<" es madre de : "<<segunda->getNombre();
        system("pause");
    }
    if(primera->hijo==segunda->padre)
    {
        system("cls");
        cout<<"\nLa Persona "<<primera->getNombre()<<" es Representante de : "<<segunda->getNombre();
        system("pause");
    }
    if(primera->hijo==segunda->madre)
    {
        system("cls");
        cout<<"\nLa Persona "<<primera->getNombre()<<" es Representante de : "<<segunda->getNombre();
        system("pause");
    }
}
Persona RelacionSocial :: buscar(string nombre)
{
    Persona *aux =primero;
    Persona *retorno = NULL;
    while(aux!=NULL)
    {
        if(aux->getNombre()==nombre)
        {
            return *aux;
        }
        aux=aux->siguiente;
    }
    return *retorno;
}
int  RelacionSocial :: cuantosBisNietos(Persona *p)
{
    int i=0;
    if(p!=NULL&&i<3)
    {
        cuantosBisNietos(p->hijo);
        i++;
    }
    if(i==1)
    {
        return i+2;
    }
    else
    {
        return 0;
    }
}
void RelacionSocial :: buscarSO(string sexo, string oficio)
{
    Persona *aux =primero;
    bool si=false;
    while(aux!=NULL)
    {
        if(aux->getSexo()==sexo && aux->getOficio()==oficio)
        {
            system("cls");
            printf("\nEsta persona coincide con los Paramaetros de Busqueda\n");
            imprimirDatos(aux);
            si=true;
        }
        aux=aux->siguiente;
    }
    if(si=false)
    {
        printf("\n No se encontro ninguna relacion con ese Sexo y ese Oficio\n");
        system("pause");
    }
}
int  RelacionSocial :: busqueda(Persona *individuo, string nombre)
{
    string name;
    string oficio;
    string sex;
    string hijo;
    string hijooficio;
    string hijosex;
    string conyuge;
    string conyugeoficio;
    string conyugesex;
    string sexo;

    Persona *aux1 = individuo;
    Persona *aux2 = individuo;
    Persona *actual =individuo;
    Persona *recorrer = individuo;

    int amigos=0;
    int cont=0;
    bool seguir=true;
    bool existe=false;
    while(actual!=NULL)
    {
        if(actual->getNombre()==nombre)
        {
            system("cls");
            cout<<"\n Si se encontro el individuo:"<<actual->getNombre();
            printf("\n");
            system("pause");
            imprimirDatos(actual);
            existe=true;
            recorrer=actual;
            actual=NULL;
        }
        if(existe==false)
        {
            actual=actual->siguiente;
            cont+=1;
        }
    }
    if(existe==true)
    {
        system("cls");
        name=recorrer->getNombre();
        oficio=recorrer->getOficio();
        sex=recorrer->getSexo();
        if(recorrer->conyuge==NULL)
        {
            cout<<"\nLa persona no posee un Conyuge!\n";
            cout<<"\nPara registrar un Hijo primero Ingrese los datos del Conyuge\n";
            cout<<"Ingrese el nombre del Conyuge: ";
            cin>>conyuge;

            system("cls");
            conyugeoficio=menuOficios();

            if(recorrer->getSexo()=="MASCULINO")
            {
                conyugesex="FEMENINO";
            }
            else if(recorrer->getSexo()=="FEMENINO")
            {
                conyugesex="MASCULINO";
            }
            //Creacion del Conyuge
            Persona *comyuge = new Persona(conyuge,conyugeoficio,conyugesex,0);
            this->crearPersona(comyuge);

            //Parentezco Esposo-Esposa

            recorrer->conyuge=comyuge;
            comyuge->conyuge=recorrer;
            this->imprimirDatos(comyuge);

            if(recorrer->hijo==NULL)
            {
                system("cls");
                cout<<"Ingrese el nombre del Hijo: ";
                cin>>hijo;
                system("cls");
                hijooficio=menuOficios();
                system("cls");
                hijosex=menuSexos();
                Persona *son = new Persona(hijo,hijooficio,hijosex,0);
                this->crearPersona(son);
                //Parentezco de Padre-Hijo
                recorrer->hijo=son;
                son->padre=recorrer;

                //Parentezco de Madre-Hijo
                son->madre=comyuge;
                comyuge->hijo=son;
                system("cls");
                printf("!!\nHIJO AGREGADO CON EXITO\n!!");
                this->imprimirDatos(son);
            }
            else
            {
                    system("cls");
                    cout<<"\nLa Persona:"<<recorrer->getNombre()<<"Ya Posee un Hijo Llamado"<<recorrer->hijo->getNombre()<<"\n";
                    system("pause");
                    return 0;
            }
        }
        else
        {
            if(recorrer->hijo==NULL)
            {
                system("cls");
                cout<<"Ingrese el nombre del Hijo: ";
                cin>>hijo;
                system("cls");
                hijooficio=menuOficios();
                system("cls");
                hijosex=menuSexos();

                Persona *son = new Persona(hijo,hijooficio,hijosex,0);
                this->crearPersona(son);

                son->padre=recorrer;
                recorrer->hijo=son;
                system("cls");
                printf("!!\nHIJO AGREGADO CON EXITO\n!!");
                this->imprimirDatos(son);
            }
            else
            {
                    system("cls");
                    cout<<"\nLa Persona:"<<recorrer->getNombre()<<"Ya Posee un Hijo Llamado"<<recorrer->hijo->getNombre()<<"\n";
                    system("pause");
                    return 0;
            }
        }
    }
    else
    {
        printf("\nLa persona que se desea Modificar no Existe en la Relacion Social\n");
        system("pause");
    }
}
void RelacionSocial :: imprimirDatos(Persona *individuo)
{
    Persona *aux = individuo;
    system("cls");
    printf("\n\tEstos son los datos de la Persona\n");
    cout<<"\nEl nombre de la Persona es: "<<aux->getNombre();
    cout<<"\nEl oficio de la Persona es: "<<aux->getOficio();
    cout<<"\nEl Sexo de la persona es : "<<aux->getSexo();
    printf("\n");
    system("pause");
}
bool RelacionSocial::vacia()
{
    primero=NULL;
    ultimo=NULL;
}

