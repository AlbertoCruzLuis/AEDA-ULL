//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula3.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celula3.h"

AEDA::Celula3::Celula3(std::pair<int,int> pos) : Celula(pos)
{}

AEDA::Celula3::~Celula3()
{
  //std::cout << "Destructor de la Celula Tipo2\n";
}

int AEDA::Celula3::get_Estado() const
{
  return 3;
}

int AEDA::Celula3::actualizar_estado()
{
  int type = 0;

  //[Reglas de Supervivencia]/[Reglas de Nacimiento]
  //Celula 3: 51/346
  if(get_Estado() == 3 && (vecinas_ == 5 || vecinas_ == 1))
    type = 3;
  else if(get_Estado() == 0 && (vecinas_ == 3 || vecinas_ == 4 || vecinas_ == 6))
    type = 3; 

  return type;
}

std::ostream& AEDA::Celula3::print(std::ostream& os)
{
  return os << "3";
}