//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula1.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celula1.h"

AEDA::Celula1::Celula1(std::pair<int,int> pos) : Celula(pos)
{}

AEDA::Celula1::~Celula1()
{
  //std::cout << "Destructor de la Celula Tipo1\n";
}

int AEDA::Celula1::get_Estado() const
{
  return 1;
}

int AEDA::Celula1::actualizar_estado()
{
  int type = 0;

  //[Reglas de Supervivencia]/[Reglas de Nacimiento]
  //Celula 1: 23/3
  if(get_Estado() == 1 && (vecinas_ == 2 || vecinas_ == 3))
    type = 1;
  else if(get_Estado() == 0 && vecinas_ == 3)
    type = 1; 

  return type;
}

std::ostream& AEDA::Celula1::print(std::ostream& os)
{
  return os << "1";
}
