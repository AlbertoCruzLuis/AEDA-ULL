//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula2.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#ifndef CELULA2_H
#define CELULA2_H

#include "celula.h"

namespace AEDA
{

class Celula2 : public Celula
{
  public:
    Celula2(std::pair<int,int>);
    ~Celula2();
    virtual int get_Estado() const;
    virtual int actualizar_estado();
    virtual std::ostream& print(std::ostream& os);
};
}

#endif