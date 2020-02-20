//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: stack.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

namespace AEDA
{
template <class TDato>
class stack
{
  public:
    stack();
    stack(int);
    ~stack();
    int get_size()
    { return size_; }
    TDato get_top()
    { return type_[top_]; }
    void build_stack(int);
    void destroy_stack();
    void push(TDato);
    TDato pop();
    bool is_empty();
    bool is_full();
    stack<TDato> operator+ (const stack<TDato>&);
    void write(std::ostream& os = std::cout);

  private:
    TDato* type_;
    int size_;
    int top_;

};

template<class TDato>
stack<TDato>::stack() :
type_(nullptr),
size_(0),
top_(-1)
{}

//Inicializa la pila con el tamaño indicado
template<class TDato>
stack<TDato>::stack(int sz) :
top_(-1),
size_(sz)
{
  build_stack(size_);
}

//Libera la memoria reservada para la pila
template<class TDato>
stack<TDato>::~stack()
{
  destroy_stack();
}

//Construye la pila con el tamaño indicado
template<class TDato>
void stack<TDato>::build_stack(int sz)
{
  size_ = sz;
  type_ = new TDato[size_];
}

//Destruye la pila
template<class TDato>
void stack<TDato>::destroy_stack()
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
void stack<TDato>::push(TDato data)
{
  if(!is_full())
  {
    top_++;
    type_[top_] = data;
  }  
}

//Quitar un dato de la pila
template<class TDato>
TDato stack<TDato>::pop()
{
  if(!is_empty())
    top_--;
}

//Comprobar si la pila esta vacia
template<class TDato>
bool stack<TDato>::is_empty()
{
  return (size_ < 0);
}

//Comprobar si la pila esta llena
template<class TDato>
bool stack<TDato>::is_full()
{
  return ((size_ - 1) == top_);
}

//Sobrecargamos el operador + para sumar dos pilas
template <class TDato>
stack<TDato> stack<TDato>::operator+ (const stack<TDato>& a)
{
  assert(size_ == a.size_);
  stack<TDato> sum(size_);
  for(int i = 0; i < size_; i++)
    sum.type_[i] = type_[i] + a.type_[i];
  return sum;
}

//Sobrecarga operador<< salida para mostrar los datos de la pila
template <class TDato>
void stack<TDato>::write(std::ostream& os)
{
  for(int i = 0; i < size_; i++)
    os << "Dato[" << i << "] = " << type_[i] << "\n";
}

}

#endif