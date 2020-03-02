//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: celula.h
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#include "celula.h"
#include "tablero.h"

AEDA::Celula::Celula(int estado, std::pair<int,int> pos)
{
  estado_ = estado;
  pos_.first = pos.first;
  pos_.second = pos.second;
  vecinas_ = 0;
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

void AEDA::Celula::contar_vecinas(const Tablero& tablero, int Pos_col, int Pos_row)
{
  vecinas_ = 0;
  //int Pos_col = tablero.get_malla()[1]->data()[2]->pos_.first;
  //int Pos_col = 1;
  //int Pos_row = 1;
  //int Pos_row = tablero.get_malla()[1]->data()[2]->pos_.second;
  //Recorremos sus 8 Vecinas y vemos cuantas hay vivas
  for(int i = Pos_col-1; i <= Pos_col+1; i++)
    for(int j = Pos_row-1; j <= Pos_row+1; j++)
      if(tablero.get_malla()[i]->data()[j]->get_Estado() && ((i != Pos_col) || (j != Pos_row)))
      {
        vecinas_++;
        //Test Prueba
        //std::cout << "POS: " << i << "," << j << "N_Vecinas: " << vecinas_ << "\n";
      }
}

void AEDA::Celula::actualizar_estado()
{
  int next_state = 0;
  //Realizar la actualizacion de estado mediante las siguientes reglas
  /*Una célula “muerta” con exactamente 3 células vecinas “viva” pasa al estado “viva” en el
  siguiente turno. En cualquier otro caso permanece “muerta”*/
  if(!get_Estado() && (vecinas_ == 3))
    next_state = 1;

  /*Una célula “viva” con 2 ó 3 células vecinas “viva” continúa “viva” en el siguiente turno. En
  cualquier otro caso pasa al estado “muerta”.*/
  if(get_Estado() && ((vecinas_ == 2) || (vecinas_ == 3)))
    next_state = 1;

  set_Estado(next_state);
}