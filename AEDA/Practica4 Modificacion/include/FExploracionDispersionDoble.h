//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FExploracionDispersionDoble.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_EXPLORACION_DISPERSION_DOBLE_H
#define F_EXPLORACION_DISPERSION_DOBLE_H

#include "FExploracionBase.h"
#include "FDispersionBase.h"
#include "FDispersionPrima.h"

namespace AEDA
{

template<class Clave>
class FExploracionDispersionDoble : public FExploracionBase<Clave>
{
  public:
    FExploracionDispersionDoble(int);
    ~FExploracionDispersionDoble();

    int operator()(Clave&, int i);

  private:
    FDispersionBase<Clave>* f_dispersion2_;   //Segunda Funcion Dispersion
    int nCeldas_;
};

template<class Clave>
FExploracionDispersionDoble<Clave>::FExploracionDispersionDoble(int nCeldas) :
FExploracionBase<Clave>(),
nCeldas_(nCeldas)
{
  //Crear la Segunda FDispersion
  f_dispersion2_ = new FDispersionPrima<Clave>(nCeldas);
}

template<class Clave>
FExploracionDispersionDoble<Clave>::~FExploracionDispersionDoble()
{
}

template<class Clave>
int FExploracionDispersionDoble<Clave>::operator()(Clave& X, int i)
{
  //Hallar la posicion libre para almacenar la clave
  return i * (*f_dispersion2_)(X);
}

}

#endif