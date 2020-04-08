//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FExploracionLineal.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_EXPLORACION_LINEAL
#define F_EXPLORACION_LINEAL

#include "FExploracionBase.h"

namespace AEDA
{

template<class Clave>
class FExploracionLineal : public FExploracionBase<Clave>
{
  public:
    FExploracionLineal();
    ~FExploracionLineal();

    int operator()(const Clave&, int i);

  private:
};

template<class Clave>
FExploracionLineal<Clave>::FExploracionLineal() :
FExploracionBase<Clave>()
{
}

template<class Clave>
FExploracionLineal<Clave>::~FExploracionLineal()
{
}

template<class Clave>
int FExploracionLineal<Clave>::operator()(const Clave& X, int i)
{
  //Hallar la posicion libre para almacenar la clave
  return ++i;
}


}

#endif