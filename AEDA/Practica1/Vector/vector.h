//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: vector.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iostream>

namespace AEDA 
{	
template <class TDato>
class vector
{
  public:
    vector();
    vector(int);
    vector(int, const TDato&);
    vector(const vector&);
    vector(std::initializer_list<TDato>);
    ~vector();

    int get_size()
    { return size_; }

    void resize(int);
    void insert(int, const TDato&);
    bool is_empty();
    TDato& at(int);
    TDato& front();
    TDato& back();
    void write(std::ostream& os = std::cout);
    TDato& operator[] (int);
    vector& operator= (vector&);


  private:
    TDato *type_;
    int size_;
    void build_vector()
    { type_ = new TDato[size_]; }
    void destroy_vector()
    { 
      if(type_ != nullptr)
      {
        delete[] type_;
        type_ = nullptr;
      } 
    }
};
}

#include "vector.cpp"
#endif