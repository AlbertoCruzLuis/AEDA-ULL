//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: queue.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

//#include "queue.h"

template <class TDato>
AEDA::queue<TDato>::queue() :
type_(nullptr),
front_(0),
back_(-1),
size_(0)
{}

//Construye la cola con el tamaño indicado
template <class TDato>
AEDA::queue<TDato>::queue(int sz) :
type_(nullptr),
front_(0),
back_(-1),
size_(sz)
{
  build_queue(sz);
}

//Libera la memoria reservada para la cola
template <class TDato>
AEDA::queue<TDato>::~queue()
{
  destroy_queue();
}

//Introducir un nuevo dato a la cola
template <class TDato>
void AEDA::queue<TDato>::push(TDato data)
{
  assert(!is_full());
  back_++;
  type_[back_] = data;
}

//Quitar dato de la cola
template <class TDato>
TDato AEDA::queue<TDato>::pop()
{
  assert(!is_empty());
  front_++;
}

//Comprobar si la cola esta vacia
template <class TDato>
bool AEDA::queue<TDato>::is_empty()
{
  return ( back_ < front_ );
}

//Comprobar si la cola esta llena
template <class TDato>
bool AEDA::queue<TDato>::is_full()
{
  return ( (back_ - front_ + 1) >= size_ );
}

//Mostrar el primer dato de la cola
template <class TDato>
TDato& AEDA::queue<TDato>::front()
{
  assert(!is_empty());
  return type_[front_];
}

//Mostrar el ultimo dato de la cola
template <class TDato>
TDato& AEDA::queue<TDato>::back()
{
  assert(!is_empty());
  return type_[back_];
}

//Mostrar los datos de la cola
template <class TDato>
void AEDA::queue<TDato>::write(std::ostream& os)
{
  for( int i = front_; i <= back_; i++ )
  {
    os << type_[i] << " - ";
  }
  os << "\n";
}

