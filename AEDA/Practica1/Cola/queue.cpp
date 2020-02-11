//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: queue.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "queue.h"

template <class TDato>
AEDA::queue<TDato>::queue() :
type_(nullptr),
size_(0)
{}

//Construye la cola con el tamaño indicado
template <class TDato>
AEDA::queue<TDato>::queue(int sz) :
type_(nullptr),
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
  //Completar metodo
}

//Quitar dato de la cola
template <class TDato>
TDato AEDA::queue<TDato>::pop()
{
  //Completar metodo
}

//Comprobar si la cola esta vacia
template <class TDato>
bool AEDA::queue<TDato>::is_empty()
{
  return ( /**/ );
}

//Comprobar si la cola esta llena
template <class TDato>
bool AEDA::queue<TDato>::is_full()
{
  return ( /**/ );
}

