#include<string.h>
#include <iostream>
#include <string>
using namespace std;
class Persona
{
    private:
        string nombre;
        string oficio;
        string sexo;
        int amigos;
    public:
        Persona *siguiente;
        Persona *anterior;
        Persona *padre;
        Persona *madre;
        Persona *hermanoMe;
        Persona *hermanoMa;
        Persona *primerHijo;
        Persona *conyuge;
        Persona *friends[];
        Persona *hijo;
        Persona(string nombre, string oficio, string sexo, int amigos)
        {
            this->nombre = nombre;
            this->oficio=oficio;
            this->sexo=sexo;
            this->amigos=amigos;
            siguiente = NULL;
            anterior =NULL;
            padre=NULL;
            madre=NULL;
            hermanoMa=NULL;
            hermanoMe=NULL;
            primerHijo=NULL;
            conyuge=NULL;
            hijo=NULL;
        }
        Persona()
        {
            siguiente = NULL;
            anterior =NULL;
            padre=NULL;
            madre=NULL;
            hermanoMa=NULL;
            hermanoMe=NULL;
            primerHijo=NULL;
            conyuge=NULL;
        }
        string getSexo()
        {
            return sexo;
        }
        void setSexo(string sexo)
        {
            this->sexo=sexo;
        }
        string getOficio()
        {
            return oficio;
        }
        void setOficio(string Oficio)
        {
            this->oficio=oficio;
        }
        string getNombre()
        {
            return nombre;
        }
        void setNombre(string nombre)
        {
            this->nombre=nombre;
        }
        int getAmigos()
        {
            return amigos;
        }
        void setAmigos(int amigos)
        {
            this->amigos=amigos;
        }
};
class RelacionSocial
{
    public:
        Persona *primero;//BisAbuelo;
        Persona *ultimo;//BisNieto;
    public:
        RelacionSocial()
        {
            primero=ultimo=NULL;
        }
    bool listaVacia()
    {
        return (primero == NULL);
    }
    void buscarSO(string , string );
    void parentesco(Persona*,Persona*);
    void crearPersona(Persona*);
    int busqueda(Persona *, string);
    int cuantosBisNietos(Persona *);
    void imprimirDatos(Persona *);
    bool vacia();
    void insertar(int);
    void copiar(Persona*);
    void eliminarPorPosicion(int );
    int  recorrerPrimero();
    Persona buscar(string);
    void imprimir();
};

