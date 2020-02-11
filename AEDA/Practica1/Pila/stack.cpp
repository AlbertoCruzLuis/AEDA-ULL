//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: stack.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "stack.h"
 
template<class TDato>
AEDA::stack<TDato>::stack() :
type_(nullptr),
size_(0),
top_(-1)
{}

//Inicializa la pila con el tamaño indicado
template<class TDato>
AEDA::stack<TDato>::stack(int sz) :
top_(-1),
size_(sz)
{
  build_stack(size_);
}

//Libera la memoria reservada para la pila
template<class TDato>
AEDA::stack<TDato>::~stack()
{
  destroy_stack();
}

//Construye la pila con el tamaño indicado
template<class TDato>
void AEDA::stack<TDato>::build_stack(int sz)
{
  size_ = sz;
  type_ = new TDato[size_];
}

//Destruye la pila
template<class TDato>
void AEDA::stack<TDato>::destroy_stack()
{
  if( type_ != nullptr )
  {
    delete[] type_;
    type_ = nullptr;
    top_ = -1;
    size_ = 0;
  }
}

//Añadir un nuevo dato en la pila
template<class TDato>
void AEDA::stack<TDato>::push(TDato data)
{
  if(!is_full())
  {
    top_++;
    type_[top_] = data;
  }  
}

//Quitar un dato de la pila
template<class TDato>
TDato AEDA::stack<TDato>::pop()
{
  if(!is_empty())
    top_--;
}

//Comprobar si la pila esta vacia
template<class TDato>
bool AEDA::stack<TDato>::is_empty()
{
  return (size_ < 0);
}

//Comprobar si la pila esta llena
template<class TDato>
bool AEDA::stack<TDato>::is_full()
{
  return ((size_ - 1) == top_);
}
