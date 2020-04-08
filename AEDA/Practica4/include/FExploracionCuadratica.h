//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FExploracionCuadratica.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_EXPLORACION_CUADRATICA_H
#define F_EXPLORACION_CUADRATICA_H

#include "FExploracionBase.h"

namespace AEDA
{

template<class Clave>
class FExploracionCuadratica : public FExploracionBase<Clave>
{
  public:
    FExploracionCuadratica();
    ~FExploracionCuadratica();

    int operator()(const Clave&, int i);

  private:
};

template<class Clave>
FExploracionCuadratica<Clave>::FExploracionCuadratica() :
FExploracionBase<Clave>()
{
}

template<class Clave>
FExploracionCuadratica<Clave>::~FExploracionCuadratica()
{
}

template<class Clave>
int FExploracionCuadratica<Clave>::operator()(const Clave& X, int i)
{
  //Hallar la posicion libre para almacenar la clave
  return i*i;
}

}

#endif