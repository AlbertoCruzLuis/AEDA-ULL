//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: queue.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef QUEUE_H
#define QUEUE_H

namespace AEDA
{
template <class TDato>
class queue
{
  public:
    queue();
    queue(int);
    ~queue();
    int get_size()
    { return size_; }
    void push(TDato);
    TDato pop();
    bool is_empty();
    bool is_full();
  private:
    TDato* type_;
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

#include "queue.cpp"
#endif