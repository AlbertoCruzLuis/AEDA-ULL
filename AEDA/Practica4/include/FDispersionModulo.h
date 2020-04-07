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
    FDispersionModulo(/* args */);
    ~FDispersionModulo();

    int operator()(const Clave&);
  
  private:
};

//Implementacion de los metodos

template<class Clave>
FDispersionModulo<Clave>::FDispersionModulo(/* args */) :
FDispersionBase<Clave>()
{

}

template<class Clave>
FDispersionModulo<Clave>::~FDispersionModulo()
{
}

template<class Clave>
int FDispersionModulo<Clave>::operator()(const Clave&)
{

}

}

#endif