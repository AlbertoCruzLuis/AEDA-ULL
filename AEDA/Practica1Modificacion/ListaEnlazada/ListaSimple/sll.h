//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: sll.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef SLL_H
#define SLL_H

#include <iostream>
#include <cassert>
#include "sll_node.h"

namespace AEDA
{
template <class TDato>
class sll
{
  public:
    sll();
    //sll(sll<TDato>&);
    ~sll();
    void insert_head(sll_node<TDato>*);
    sll_node<TDato>* extract_head();
    void insert_after(sll_node<TDato>* , sll_node<TDato>*);
    sll_node<TDato>* extract_after(sll_node<TDato>*);
    bool is_empty() const;
    void write(std::ostream& os = std::cout);
    bool search(const TDato&);
    int size();

  private:
    sll_node<TDato>* head_;
};

template <class TDato>
sll<TDato>::sll() :
head_(nullptr)
{}

//Constructor de copia
// template <class TDato>
// sll<TDato>::sll(sll<TDato>& l)
// {
//   // Comprobar Lista del mismo tamaño y tipo
//   sll_node<TDato>* aux = head_;
//   sll_node<TDato>* aux_this = *this->head_;
//   if(!l.is_empty())
//   {
//     while (aux != nullptr)
//     {
//       aux_this = aux;
//       aux = aux->get_next();
//       aux_this = aux_this->get_next();
//     }
//   }else
//   {
//     //Poner el head a null
//   }
// }

//Destructor que elimina los nodos de la lista simple
template <class TDato>
sll<TDato>::~sll()
{
  while (!is_empty())
  {
    sll_node<TDato>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  
}

//Insertar nuevo nodo por la cabeza
template <class TDato>
void sll<TDato>::insert_head(sll_node<TDato>* n)
{
     n->set_next(head_);
     head_ = n;
}

//Extraer un nodo por la cabeza
template <class TDato>
sll_node<TDato>* sll<TDato>::extract_head()
{
  sll_node<TDato>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(nullptr);

  return aux;
}

//Insertar un nodo posterior a otro
template <class TDato>
void sll<TDato>::insert_after(sll_node<TDato>* prev, sll_node<TDato>* n)
{
  n->set_next(prev->get_next());
  prev->set_next(n);
}

//Extraer un nodo posterior a otro
template <class TDato>
sll_node<TDato>* sll<TDato>::extract_after(sll_node<TDato>* prev)
{
  sll_node<TDato>* aux = prev->get_next();
  prev->set_next(aux->get_next());
  aux->set_next(nullptr);
}

//Comprobar si la lista esta vacia
template <class TDato>
bool sll<TDato>::is_empty() const
{
  return ( head_ == nullptr );
}

//Mostrar los datos de la lista simple
template <class TDato>
void sll<TDato>::write(std::ostream& os)
{
  sll_node<TDato>* aux = head_;
  while (aux != nullptr)
  {
    os << aux->get_data().name;
    os << aux->get_data().dni;
    os << "->";
    aux = aux->get_next();
  }
  os << "\n";
}

//Buscar el dato de un nodo en la lista 
template <class TDato>
bool sll<TDato>::search(const TDato& dato)
{
  sll_node<TDato>* aux = head_;
  while((aux != nullptr))
  {
    if(aux->get_data() == dato)
      return true;
    aux = aux->get_next();
  }
}

//Tamaño de la lista
template <class TDato>
int sll<TDato>::size()
{
  int sz = 0;
  sll_node<TDato>* aux = head_;
  while(aux != nullptr)
  {
    sz++;
    aux = aux->get_next();
  }
  return sz;
}

}

#endif
