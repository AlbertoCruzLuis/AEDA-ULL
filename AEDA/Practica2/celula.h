//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: celula.h
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#ifndef CELULA_H
#define CELULA_H

#include <iostream>
//#include "tablero.h"

namespace AEDA
{
class Celula
{
  public:
    Celula(int, std::pair<int, int>);
    ~Celula(){}
    int get_Estado() const
    { return estado_; }
    void set_Estado(int estado)
    { estado_ = estado; }
    void actualizar_estado();
    void contar_vecinas(/*const Tablero&*/);
    //Sobrecargar Operador de flujo
    friend std::ostream& operator<<(std::ostream& os, const Celula *celula);
    std::ostream& print(std::ostream& os);

  private:
    int estado_;    //Muerto(0), Viva(1)
    std::pair<int,int> pos_;
};
}

#endif