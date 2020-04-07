//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Celda.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef CELDA_H
#define CELDA_H

#include <vector>
#include <iostream>

namespace AEDA
{
template<class Clave>
class Celda
{
  public:
    Celda(int);
    ~Celda();

    bool Buscar(Clave X);
    bool Insertar(Clave X);
    bool estaLlena();
    void Mostrar();

  private:
    int nClaves_;
    std::vector<Clave*> claves_;
};


//Implementacion de los metodos
template<class Clave>
Celda<Clave>::Celda(int nClaves) :
nClaves_(nClaves)
{
  //Reservo el tamaño de la celda
  //claves_.resize(nClaves);

}

template<class Clave>
Celda<Clave>::~Celda()
{
}

template<class Clave>
bool Celda<Clave>::Buscar(Clave X)
{

}

template<class Clave>
bool Celda<Clave>::Insertar(Clave X)
{
  //Añadir una clave a la celda
  if(!estaLlena())
  {
    claves_.push_back(new Clave(X));
    return true;
  }
  return false;
}

template<class Clave>
bool Celda<Clave>::estaLlena()
{
  //Comprobar si la Celda esta llena
  if(claves_.size() == nClaves_)
    return true;
  return false;
}

template<class Clave>
void Celda<Clave>::Mostrar()
{
  //Mostar los datos de la celda
  for(int i = 0; i < claves_.size(); i++)
  {
    std::cout << claves_[i];
  }
  std::cout << "\n";
}

}

#endif