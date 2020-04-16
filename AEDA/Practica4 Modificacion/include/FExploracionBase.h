//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: FExploracionBase.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef F_EXPLORACION_BASE
#define F_EXPLORACION_BASE

namespace AEDA
{

template<class Clave>
class FExploracionBase
{
  public:
    FExploracionBase(/* args */);
    ~FExploracionBase();

    virtual int operator()(Clave&, int i)=0;

  private:
};

//Implementacion de los metodos

template<class Clave>
FExploracionBase<Clave>::FExploracionBase(/* args */)
{
}

template<class Clave>
FExploracionBase<Clave>::~FExploracionBase()
{
}

}

#endif