//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: stack.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef STACK_H
#define STACK_H

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

  private:
    TDato* type_;
    int size_;
    int top_;

};
}

#include "stack.cpp"
#endif