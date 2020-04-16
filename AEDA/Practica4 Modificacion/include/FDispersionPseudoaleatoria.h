//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionPseudoaleatoria.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_DISPERSION_PSEUDOALEATORIA_H
#define F_DISPERSION_PSEUDOALEATORIA_H

#include "FDispersionBase.h"
#include <cstdlib>

namespace AEDA
{

template<class Clave>
class FDispersionPseudoaleatoria : public FDispersionBase<Clave>
{
  public:
    FDispersionPseudoaleatoria(int);
    ~FDispersionPseudoaleatoria();

    int operator()(Clave&);

  private:
    int nCeldas_;
};

template<class Clave>
FDispersionPseudoaleatoria<Clave>::FDispersionPseudoaleatoria(int nCeldas) :
FDispersionBase<Clave>(),
nCeldas_(nCeldas)
{
}

template<class Clave>
FDispersionPseudoaleatoria<Clave>::~FDispersionPseudoaleatoria()
{
}

template<class Clave>
int FDispersionPseudoaleatoria<Clave>::operator()(Clave& X)
{
  //Hallar la posicion de la celda en la que deberia alojarse
  srand(X);
  return rand() % nCeldas_;
}

}

#endif