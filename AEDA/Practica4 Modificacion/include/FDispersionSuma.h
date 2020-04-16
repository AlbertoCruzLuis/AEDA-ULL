//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionSuma.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_DISPERSION_SUMA
#define F_DISPERSION_SUMA

#include "FDispersionBase.h"

namespace AEDA
{

template<class Clave>
class FDispersionSuma : public FDispersionBase<Clave>
{
  public:
    FDispersionSuma(int);
    ~FDispersionSuma();

    int operator()(Clave&);

  private:
    int nCeldas_;
};


template<class Clave>
FDispersionSuma<Clave>::FDispersionSuma(int nCeldas) :
FDispersionBase<Clave>(),
nCeldas_(nCeldas)
{
}

template<class Clave>
FDispersionSuma<Clave>::~FDispersionSuma()
{
}

template<class Clave>
int FDispersionSuma<Clave>::operator()(Clave& X)
{
  //Hallar la posicion de la celda en la que deberia alojarse
  int d = 0;
  int x = X;
  while(x > 0)
  {
    int y = x % 10;
    d += y;
    x /= 10;
  }
  return d % nCeldas_;
}

}

#endif