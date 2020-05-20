//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: Nodo.h
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#ifndef NODO_H
#define NODO_H

namespace AEDA
{

template <class Clave>
class Nodo
{
  public:
    Nodo(Clave, Nodo *izq = nullptr, Nodo *dcho = nullptr, int bal = 0);
    ~Nodo();

    Nodo<Clave>* &get_izq();
    Nodo<Clave>* &get_dcho();
    Clave& get_dato();
    int& get_bal();
    void print();

  private:
    Clave dato_;
    Nodo* izq_;
    Nodo* dcho_;
    int bal_;
};

template <class Clave>
Nodo<Clave>::Nodo(Clave dato, Nodo *izq, Nodo *dcho, int bal) :
dato_(dato),
izq_(izq),
dcho_(dcho),
bal_(bal)
{}

template <class Clave>
Nodo<Clave>::~Nodo()
{
}

template <class Clave>
Clave& Nodo<Clave>::get_dato()
{ return dato_; }

template <class Clave>
Nodo<Clave>* &Nodo<Clave>::get_izq()
{ return izq_; }

template <class Clave>
Nodo<Clave>* &Nodo<Clave>::get_dcho()
{ return dcho_; }

template <class Clave>
int& Nodo<Clave>::get_bal()
{
  return bal_;
}

template <class Clave>
void Nodo<Clave>::print()
{
  if(this != NULL)
    std::cout << "[" << dato_ << "]";
  else
    std::cout << "[.]";
}

}

#endif