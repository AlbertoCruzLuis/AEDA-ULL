//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Marzo 2020
//@Name: celula.cpp
//@Version: Práctica 3 - El juego de la Vida Generalizado
//==============================================================

#include "celula.h"
#include "celula1.h"
#include "celula2.h"
#include "celula3.h"
#include "celulax.h"
#include "tablero.h"

AEDA::Celula::Celula(std::pair<int, int> pos)
{
  pos_.first = pos.first;
  pos_.second = pos.second;
}

AEDA::Celula::~Celula()
{
  //std::cout << "Desctructor de Celula Base\n";
}

int AEDA::Celula::get_Estado() const
{
  return 0;
}


AEDA::Celula* AEDA::Celula::create_celula(int type, int col, int fil)
{
  //Crear el tipo de Celula
  //Nota: Establecer una prioridad de Creacion: 1,2,3...
  switch (type)
  {
    case 0: return new Celula(std::make_pair(col,fil));

    case 1:
      return dynamic_cast<Celula1*>(new Celula1(std::make_pair(col,fil)));
    case 2:
      return dynamic_cast<Celula2*>(new Celula2(std::make_pair(col,fil)));
    case 3:
      return dynamic_cast<Celula3*>(new Celula3(std::make_pair(col,fil)));
    case 4:
      return dynamic_cast<CelulaX*>(new CelulaX(std::make_pair(col,fil)));
  }
}

std::ostream& operator<<(std::ostream& os, const AEDA::Celula *celula)
{
  //La celula base esta muerta siempre. Se muestra en blanco
  return os << " ";
}

std::ostream& AEDA::Celula::print(std::ostream& os)
{
  //La celula base esta muerta siempre. Se muestra en blanco
  return os << " ";
}

void AEDA::Celula::contar_vecinas(const Tablero& tablero)
{
  vecinas_ = 0;
  int Pos_col = pos_.first;
  int Pos_row = pos_.second;
  //Recorremos sus 8 Vecinas y vemos cuantas hay vivas
  for(int i = Pos_col-1; i <= Pos_col+1; i++)
    for(int j = Pos_row-1; j <= Pos_row+1; j++)
    {
      if(tablero.get_malla()[i]->data()[j]->get_Estado() != 0 && ((i != Pos_col) || (j != Pos_row)))
      {
        vecinas_++;
      }
    }
    //std::cout << vecinas_ << "\n"; 
}

int AEDA::Celula::actualizar_estado()
{
  //Implementar las Reglas de Nacimiento para cada celula
  //Retornar el tipo de celula que debe nacer (1,2,3...)
  //Nota: Celula debe morir retornar 0

  int type = 0;

  //[Reglas de Supervivencia]/[Reglas de Nacimiento]
  //Celula 1: 23/3
  if(get_Estado() == 0 && vecinas_ == 3)
    type = 1; 
  //Celula 2: 245/368
  else if(get_Estado() == 0 && (vecinas_ == 6 || vecinas_ == 8))
    type = 2;
  //Celula 3: 51/346
  else if(get_Estado() == 0 && (vecinas_ == 4))
    type = 3;
    //Celula X: 1/1
  else if(get_Estado() == 0 && (vecinas_ == 1))
    type = 4;

  return type;
}