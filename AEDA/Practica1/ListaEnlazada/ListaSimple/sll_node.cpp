//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: sll_node.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

//#include "sll_node.h"

template <class TDato>
AEDA::sll_node<TDato>::sll_node() :
next_(nullptr),
data_()
{}

//Construir la lista simple con un dato
template <class TDato>
AEDA::sll_node<TDato>::sll_node(const TDato& data) :
next_(nullptr),
data_(data)
{}

//Destruir la lista simple para liberar memoria
template <class TDato>
AEDA::sll_node<TDato>::~sll_node()
{}

//Mostrar los datos de la lista simple
template <class TDato>
void AEDA::sll_node<TDato>::write(std::ostream& os)
{
  os << data_;
}