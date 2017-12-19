#include <iostream>
class Nodo
{
    private:
        int TLlegada;
        int TServicio;
        int TEsperaCliente;
        int TDescansoCajero;
        int TSalida;
        int TEntreLlegadas;
    public:

        Nodo *siguiente;

        Nodo(int TLlegada, int TServicio)
        {
            this->TLlegada = TLlegada;
            this->TServicio = TServicio;
            this->TEsperaCliente = TEsperaCliente;
            this->TDescansoCajero = TDescansoCajero;
            this->TSalida = TSalida;
            this->TEntreLlegadas = TEntreLlegadas;

            siguiente = NULL;
        }

    int getTLlegada()
    {
        return TLlegada;
    }
    void setTLlegada(int llegada)
    {
        TLlegada=llegada;
    }
    // Setter y Getter Tiempo de Servicio
    int getTServicio()
    {
        return TServicio;
    }
    void setTServicio(int servicio)
    {
        TServicio=servicio;
    }
    // Setter y Getter Tiempo Espera Cliente
    int getTEsperaCliente()
    {
        return TEsperaCliente;
    }
    void setTEsperaCliente(int eCliente)
    {
        TEsperaCliente=eCliente;
    }
    //Setter y Getter Tiempo descanso del cajero
    int getTDescansoCajero()
    {
        return TDescansoCajero;
    }
    void setTDescansoCajero(int dCajero)
    {
        TDescansoCajero=dCajero;
    }
    //Setter y Getter Tiempo de Salida
    int getTSalida()
    {
        return TSalida;
    }
    void setTSalida(int salida)
    {
        TSalida=salida;
    }
    //Setter y getter Tiempo Entre Llegadas
    int getTEntreLlegadas()
    {
        return TEntreLlegadas;
    }
    void setTEntreLlegadas(int ellegadas)
    {
        TEntreLlegadas=ellegadas;
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
    bool ListaVacia()
    {
        return (primero == NULL);
    }

    void ingresar(int tllegada,int tservicio);
    void impresion();
    int random(int clientes);
    int randomico(int x);
    void primerCliente();
    void restodeClientes();
};
