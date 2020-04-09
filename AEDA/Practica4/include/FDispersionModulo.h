//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionModulo.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_DISPERSION_MODULO
#define F_DISPERSION_MODULO

#include "FDispersionBase.h"

namespace AEDA
{

template<class Clave>
class FDispersionModulo : public FDispersionBase<Clave>
{
  public:
    FDispersionModulo(int);
    ~FDispersionModulo();

    int operator()(Clave&);
  
  private:
    int nCeldas_;
};

//Implementacion de los metodos

template<class Clave>
FDispersionModulo<Clave>::FDispersionModulo(int nCeldas) :
FDispersionBase<Clave>(),
nCeldas_(nCeldas)
{

}

template<class Clave>
FDispersionModulo<Clave>::~FDispersionModulo()
{
}

template<class Clave>
int FDispersionModulo<Clave>::operator()(Clave& X)
{
  //Hallar la posicion de la celda en la que deberia alojarse
  //std::cout << "X: " << X << "\nnClaves: " << nCeldas_ << "\n";
  return X % nCeldas_;
}

}

#endif