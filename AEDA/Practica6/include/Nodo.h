//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Nodo.h
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

#ifndef NODO_H
#define NODO_H

namespace AEDA
{

template <class Clave>
class Nodo
{
  public:
    Nodo(Clave, Nodo *izq = nullptr, Nodo *dcho = nullptr);
    ~Nodo();

    Nodo<Clave>* &get_izq();
    Nodo<Clave>* &get_dcho();
    Clave& get_dato();
    void print();

  private:
    Clave dato_;
    Nodo* izq_;
    Nodo* dcho_;
};

template <class Clave>
Nodo<Clave>::Nodo(Clave dato, Nodo *izq, Nodo *dcho) :
dato_(dato),
izq_(izq),
dcho_(dcho)
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
void Nodo<Clave>::print()
{
  if(this != NULL)
    std::cout << "[" << dato_ << "]";
  else
    std::cout << "[.]";
}

}

#endif