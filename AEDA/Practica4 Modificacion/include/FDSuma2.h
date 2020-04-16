//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionSuma.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef FD_SUMA2_H
#define FD_SUMA2_H

#include "FDispersionBase.h"

namespace AEDA
{

template<class Clave>
class FDSuma2 : public FDispersionBase<Clave>
{
  public:
    FDSuma2(int);
    ~FDSuma2();

    int operator()(Clave&);

  private:
    int nCeldas_;
};

template<class Clave>
FDSuma2<Clave>::FDSuma2(int nCeldas) :
FDispersionBase<Clave>(),
nCeldas_(nCeldas)
{
}

template<class Clave>
FDSuma2<Clave>::~FDSuma2()
{
}

template<class Clave>
int FDSuma2<Clave>::operator()(Clave& X)
{
  //Hallar la posicion de la celda en la que deberia alojarse
  int d = 0;
  int x = X;
  while(x > 0)
  {
    int y = x % 100;
    d += y;
    x /= 100;
  }
  return d % nCeldas_;
}

}

#endif