//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celulaX.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#ifndef CELULAX_H
#define CELULAX_H

#include "celula.h"

namespace AEDA
{

class CelulaX : public Celula
{
  public:
    CelulaX(std::pair<int,int>);
    ~CelulaX();
    virtual int get_Estado() const;
    virtual int actualizar_estado();
    virtual std::ostream& print(std::ostream& os);
};
}

#endif