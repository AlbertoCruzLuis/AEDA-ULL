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

template <class TDato>
vector<TDato>::vector() :
type_(nullptr),
size_(0)
{}

//Construir vector con el tamaño indicado
template <class TDato>
vector<TDato>::vector(int sz) :
type_(nullptr),
size_(sz)
{
  build_vector();
}

//Construir vector con el tamaño y valor indicado
template <class TDato>
vector<TDato>::vector(int sz, const TDato& value) :
type_(nullptr),
size_(sz)
{
  build_vector();
  for(int i = 0; i < size_; i++)
    type_[i] = value;
}

//Construir vector con el tamaño indicado
template <class TDato>
vector<TDato>::vector(const vector<TDato>& v) :
type_(nullptr),
size_(v.size_)
{
  build_vector();
  for(int i = 0; i < v.size_; i++)
    type_[i] = v.type_[i];

}

//Construir vector mediante una lista de inicializacion {}
template <class TDato>
vector<TDato>::vector(std::initializer_list<TDato> init_list) :
type_(nullptr),
size_(0)
{
  for(TDato i : init_list)
  {
    resize(size_+ 1);
    type_[size_ -1] = i;
  }
}

//Eliminar la memoria reservada Dinamicamente
template <class TDato>
vector<TDato>::~vector()
{
  destroy_vector();
}

//Introducir Posicion y dato a insertar
template <class TDato>
void vector<TDato>::insert(int indx, const TDato& dato)
{
  if( size_ == 0 )
    resize(indx);
  type_[indx] = dato;
}

//Redimensionar el Tamaño del Vector y conservar los antiguos valores
template <class TDato>
void vector<TDato>::resize(int new_sz)
{
  // 1)Guardamos los valores del vector Antiguo en aux
  vector<TDato> aux(*this);
  // 2)Redimensionamos el vector this
  size_ = new_sz;
  build_vector();
  // 3)Rellenamos el nuevo vector con los valores Antiguos
  for(int i = 0; i < aux.size_; i++)
    type_[i] = aux.type_[i];
}

//Comprueba si el vector esta vacio
template <class TDato>
bool vector<TDato>::is_empty()
{
  return ( size_ == 0 );
}

//Acceder a la posicion indicada del vector
template <class TDato>
TDato& vector<TDato>::at(int indx)
{
  return type_[indx];
}

//Acceder al primer dato del vector
template <class TDato>
TDato& vector<TDato>::front()
{
  return type_[0];
}

//Acceder al ultimo dato del vector
template <class TDato>
TDato& vector<TDato>::back()
{
  return type_[size_ - 1];
}

//Mostrar los datos del vector
template <class TDato>
void vector<TDato>::write(std::ostream& os)
{
  for(int i = 0; i < this->size_; i++)
    os << "Valor[" << i << "] = " << type_[i] << "\n";
}


//Acceder a la posicion del vector
template <class TDato>
TDato& vector<TDato>::operator[] (int indx)
{
  return type_[indx];
}

//Asignar un vector a otro vector
template <class TDato>
vector<TDato>& vector<TDato>::operator= (vector<TDato>& vector_b)
{
  resize(vector_b.size_);
  for(int i = 0; i < vector_b.size_; i++)
    this->type_[i] = vector_b.type_[i];
  return *this;
}
}

#endif