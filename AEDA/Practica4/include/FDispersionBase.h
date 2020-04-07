//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FDispersionBase.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_DISPERSION_BASE
#define F_DISPERSION_BASE

#include <iostream>

namespace AEDA
{

template<class Clave>
class FDispersionBase
{
  public:
    FDispersionBase(/* args */);
    ~FDispersionBase();

    virtual int operator()(const Clave&)=0;

  private:

};

//Implementacion de los metodos

template<class Clave>
FDispersionBase<Clave>::FDispersionBase(/* args */)
{
}

template<class Clave>
FDispersionBase<Clave>::~FDispersionBase()
{
}

}

#endif