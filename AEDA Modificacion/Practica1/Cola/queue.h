//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: queue.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>

namespace AEDA
{
template <class TDato>
class queue
{
  public:
    queue();
    queue(int);
    ~queue();
    void push(TDato);
    TDato pop();
    bool is_empty();
    bool is_full();
    TDato& front();
    TDato& back();
    void write(std::ostream& os = std::cout);
    int get_size()
    { return size_; }

  private:
    TDato* type_;
    int front_;
    int back_;
    //Tamaño reservado a la cola
    int size_;
    void build_queue(int sz)
    { 
      size_ = sz;
      type_ = new TDato[size_];
    }
    void destroy_queue()
    { 
      if( type_ != nullptr )
      {
        delete[] type_;
        type_ = nullptr;
        size_ = 0;
      } 
    }
};

template <class TDato>
queue<TDato>::queue() :
type_(nullptr),
front_(0),
back_(-1),
size_(0)
{}

//Construye la cola con el tamaño indicado
template <class TDato>
queue<TDato>::queue(int sz) :
type_(nullptr),
front_(0),
back_(-1),
size_(sz)
{
  build_queue(sz);
}

//Libera la memoria reservada para la cola
template <class TDato>
queue<TDato>::~queue()
{
  destroy_queue();
}

//Introducir un nuevo dato a la cola
template <class TDato>
void queue<TDato>::push(TDato data)
{
  assert(!is_full());
  back_++;
  type_[back_] = data;
}

//Quitar dato de la cola
template <class TDato>
TDato queue<TDato>::pop()
{
  assert(!is_empty());
  front_++;
}

//Comprobar si la cola esta vacia
template <class TDato>
bool queue<TDato>::is_empty()
{
  return ( back_ < front_ );
}

//Comprobar si la cola esta llena
template <class TDato>
bool queue<TDato>::is_full()
{
  return ( (back_ - front_ + 1) >= size_ );
}

//Mostrar el primer dato de la cola
template <class TDato>
TDato& queue<TDato>::front()
{
  assert(!is_empty());
  return type_[front_];
}

//Mostrar el ultimo dato de la cola
template <class TDato>
TDato& queue<TDato>::back()
{
  assert(!is_empty());
  return type_[back_];
}

//Mostrar los datos de la cola
template <class TDato>
void queue<TDato>::write(std::ostream& os)
{
  for( int i = front_; i <= back_; i++ )
  {
    os << type_[i] << " - ";
  }
  os << "\n";
}
}

#endif