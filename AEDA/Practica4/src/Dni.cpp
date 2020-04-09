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

  //Generar 8 digitos [0...9] 
  for(int i = 0; i < 8; i++)
  {
    id_.push_back(rand() % 10);
  }
}

Dni::Dni(int semilla)
{
  //Generar Numero id aleatoriamente
  //Generar Semilla
  srand(semilla);

  //Generar 8 digitos [0...9] 
  for(int i = 0; i < 8; i++)
  {
    id_.push_back(rand() % 10);
  }
}

Dni::operator unsigned long()
{
  unsigned long valor_dni = 0;
  //Recorremos todos los digitos
  for(int i = 0; i < id_.size(); i++)
  {
    //Convertir el numero mediante su valor de unidad
    //Es decir: Unidades:1, Decenas:10 Centenas:100
    valor_dni += id_[i] * std::pow(10,id_.size()-1-i);
  }
  return valor_dni;
}
 
}