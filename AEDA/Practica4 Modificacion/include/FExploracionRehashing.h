//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FExploracionLineal.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_EXPLORACION_REHASHING
#define F_EXPLORACION_REHASHING

#include "FExploracionBase.h"
#include "FDispersionBase.h"
#include "FDispersionModulo.h"
#include "FDispersionSuma.h"
#include "FDispersionPseudoaleatoria.h"

namespace AEDA
{

template<class Clave>
class FExploracionRehashing : public FExploracionBase<Clave>
{
  public:
    FExploracionRehashing(int);
    ~FExploracionRehashing();

    int operator()(Clave&, int i);

  private:
    FDispersionBase<Clave>* h_dispersion_;
    int nCeldas_;
};

template<class Clave>
FExploracionRehashing<Clave>::FExploracionRehashing(int nCeldas) :
nCeldas_(nCeldas)
{
  srand(time(NULL));
  switch (rand()%3)
  {
    case 0: h_dispersion_ = new FDispersionModulo<Clave>(nCeldas);
      break;
    case 1: h_dispersion_ = new FDispersionSuma<Clave>(nCeldas);
      break;
    case 2: h_dispersion_ = new FDispersionPseudoaleatoria<Clave>(nCeldas);
      break;
  }
}

template<class Clave>
FExploracionRehashing<Clave>::~FExploracionRehashing()
{
}

template<class Clave>
int FExploracionRehashing<Clave>::operator()(Clave& X, int i)
{
  //Aplicar una familia de funciones aleatorias
  srand(i+X);
  switch (rand()%3)
  {
    case 0: h_dispersion_ = static_cast<FDispersionModulo<Clave>*>(h_dispersion_);
      std::cout << "0-";
      break;
    case 1: h_dispersion_ = static_cast<FDispersionSuma<Clave>*>(h_dispersion_);
      std::cout << "1-";
      break;
    case 2: h_dispersion_ = static_cast<FDispersionPseudoaleatoria<Clave>*>(h_dispersion_);
      std::cout << "2-";
      break;
  }
  return ((*h_dispersion_)(X)+i) % nCeldas_;
}


}

#endif