//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula3.h
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#ifndef CELULA3_H
#define CELULA3_H

#include "celula.h"

namespace AEDA
{

class Celula3 : public Celula
{
  public:
    Celula3(std::pair<int,int>);
    ~Celula3();
    virtual int get_Estado() const;
    virtual void contar_vecinas(const Tablero&);
    virtual int actualizar_estado();
    virtual std::ostream& print(std::ostream& os);
};
}

#endif