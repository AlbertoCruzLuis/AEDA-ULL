//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula1.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celula1.h"
#include "tablero.h"

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

void AEDA::Celula1::contar_vecinas(const Tablero& tablero)
{
  vecinas_ = 0;
  int Pos_col = pos_.first;
  int Pos_row = pos_.second;
  //Recorremos sus 8 Vecinas y vemos cuantas hay vivas
  for(int i = Pos_col-1; i <= Pos_col+1; i++)
    for(int j = Pos_row-1; j <= Pos_row+1; j++)
    {
      if(tablero.get_malla()[i]->data()[j]->get_Estado() == 1 && ((i != Pos_col) || (j != Pos_row)))
      {
        vecinas_++;
      }
    }
    //std::cout  << "Tipo 1: " << vecinas_ << "\n"; 
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
