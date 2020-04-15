//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionPrima.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_DISPERSION_PRIMA_H
#define F_DISPERSION_PRIMA_H

#include "FDispersionBase.h"

namespace AEDA
{

template<class Clave>
class FDispersionPrima : public FDispersionBase<Clave>
{
  public:
    FDispersionPrima(int);
    ~FDispersionPrima();

    int operator()(Clave&);

  private:
    int nCeldas_;
};

template<class Clave>
FDispersionPrima<Clave>::FDispersionPrima(int nCeldas) :
nCeldas_(nCeldas)
{
}

template<class Clave>
FDispersionPrima<Clave>::~FDispersionPrima()
{
}

template<class Clave>
int FDispersionPrima<Clave>::operator()(Clave& X)
{
  srand(time(NULL));
  //Hallar un numero aleatorio entre [0,nCeldas-1]
  int n = rand() % nCeldas_;
  //Aplicar la formula: (1 + n) % (nCeldas -1)
  return (1 + n) % (nCeldas_ -1);
}

}

#endif