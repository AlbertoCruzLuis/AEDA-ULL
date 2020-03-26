//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula3.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celulax.h"

AEDA::CelulaX::CelulaX(std::pair<int,int> pos) : Celula(pos)
{}

AEDA::CelulaX::~CelulaX()
{
  //std::cout << "Destructor de la Celula TipoX\n";
}

int AEDA::CelulaX::get_Estado() const
{
  return 4;
}

int AEDA::CelulaX::actualizar_estado()
{
  int type = 0;

  //[Reglas de Supervivencia]/[Reglas de Nacimiento]
  //Celula X: 1/1
  if(get_Estado() == 4 && (vecinas_ == 1))
    type = 4; 

  return type;
}

std::ostream& AEDA::CelulaX::print(std::ostream& os)
{
  return os << "X";
}