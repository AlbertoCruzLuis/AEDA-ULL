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
#include "sll_node.h"

namespace AEDA
{
template <class TDato>
class sll
{
  public:
    sll();
    ~sll();
    void insert_head(sll_node<TDato>*);
    sll_node<TDato>* extract_head();
    void insert_after(sll_node<TDato>* , sll_node<TDato>*);
    sll_node<TDato>* extract_after(sll_node<TDato>*);
    bool is_empty();

  private:
    sll<TDato>* head_;
};
}

#endif