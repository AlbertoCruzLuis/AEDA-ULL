//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: sll_node.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef SLL_NODE_H
#define SLL_NODE_H

#include <iostream>

namespace AEDA
{
template <class TDato>
class sll_node
{
  public:
    sll_node();
    sll_node(const TDato&);
    ~sll_node(){}
    sll_node<TDato>* get_next()
    { return next_; }
    void set_next(sll_node<TDato>* next)
    { next_ = next; }
    TDato& get_data()
    { return data_; }
    void set_data(const TDato& data)
    { data_ = data; }
    void write(std::ostream& os = std::cout);

  private:
    sll_node<TDato>* next_;
    TDato data_;
};

template <class TDato>
sll_node<TDato>::sll_node() :
next_(nullptr),
data_()
{}

//Construir la lista simple con un dato
template <class TDato>
sll_node<TDato>::sll_node(const TDato& data) :
next_(nullptr),
data_(data)
{}

//Mostrar los datos de la lista simple
template <class TDato>
void sll_node<TDato>::write(std::ostream& os)
{
  os << data_;
}
}

#endif