//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: tablero.h
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#include "tablero.h"

AEDA::Tablero::Tablero(int n, int m) :
n_(n),
m_(m)
{
  //Se crea un vector puntero para que cada vector en la matriz 
  //tenga diferente direcciones de memoria
  std::vector<Celula*> *aux;
  for(int i = 0; i < n+2; i++)
  {
    aux = new std::vector<Celula*>;
    for(int j = 0; j < m+2; j++)
    {
      aux->push_back(new Celula(0,std::make_pair(i,j)));
    }
    malla_.push_back(aux);
  }
}

void AEDA::Tablero::poner_celula_viva(int n, int m)
{
  //Al tener un vector puntero necesitamos acceder al dato
  malla_[n]->data()[m]->set_Estado(1);
}

void AEDA::Tablero::print(std::ostream& os)
{
  for(int i = -1; i <= n_+2; i++)
  {
    for(int j = -1; j <= m_+2; j++)
    {
      //Arreglar me muestra la Direccion de Memoria
      //os << &malla_[i][j];
      //Colocar un marco exterior
      if((i == -1) || (i == n_+2) || (j == -1) || (j == m_+2))
        os << "|";
      else
        malla_[i]->data()[j]->print(os);
    }
    os << "\n";
  }
}