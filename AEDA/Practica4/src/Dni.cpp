//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/Dni.h"

namespace AEDA
{

Dni::Dni()
{
  //Generar Numero id aleatoriamente
  //Generar Semilla
  srand(time(NULL));

  //Generar cada digito [0...9] 
  for(int i = 0; i < 10; i++)
  {
    id_.push_back(rand() % 10);
    std::cout << id_[i];
  }
  std::cout << "\n";
}
 
}