//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula1.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#ifndef CELULA1_H
#define CELULA1_H

#include "celula.h"

namespace AEDA
{

class Celula1 : public Celula
{
  public:
    Celula1(std::pair<int,int>);
    ~Celula1();
    virtual int get_Estado() const;
    virtual int actualizar_estado();
    virtual std::ostream& print(std::ostream& os);
};
}

#endif