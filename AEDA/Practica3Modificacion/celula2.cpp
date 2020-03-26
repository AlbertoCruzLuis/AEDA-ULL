//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula2.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celula2.h"

AEDA::Celula2::Celula2(std::pair<int,int> pos) : Celula(pos)
{}

AEDA::Celula2::~Celula2()
{
  //std::cout << "Destructor de la Celula Tipo2\n";
}

int AEDA::Celula2::get_Estado() const
{
  return 2;
}

int AEDA::Celula2::actualizar_estado()
{
  int type = 0;

  //[Reglas de Supervivencia]/[Reglas de Nacimiento]
  //Celula 2: 245/368
  if(get_Estado() == 2 && (vecinas_ == 2 || vecinas_ == 4 || vecinas_ == 5))
    type = 2;
  else if(get_Estado() == 0 && (vecinas_ == 3 || vecinas_ == 6 || vecinas_ == 8))
    type = 2; 

  return type;
}

std::ostream& AEDA::Celula2::print(std::ostream& os)
{
  return os << "2";
}
