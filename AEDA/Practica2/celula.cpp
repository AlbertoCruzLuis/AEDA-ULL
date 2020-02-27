//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: celula.h
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#include "celula.h"

AEDA::Celula::Celula(int estado, std::pair<int,int> pos)
{
  estado_ = estado;
  pos_.first = pos.first;
  pos_.second = pos.second;
}

//Arreglar este metodo
std::ostream& operator<<(std::ostream& os, const AEDA::Celula *celula)
{
  if(celula->get_Estado())
    os << "X";
  else
    os << " ";
  return os;
}

std::ostream& AEDA::Celula::print(std::ostream& os)
{
  if(get_Estado())
    os << "X";
  else
    os << " ";
  return os;
}