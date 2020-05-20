//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Mayo 2020
//@Name: Contador.cpp
//@Version: Práctica 7 - ​​Implementación árbol binario búsqueda balanceado
//=======================================================================

#include "Contador.h"

namespace AEDA
{

Contador::Contador(/* args */)
{
}

Contador::~Contador()
{
}

int Contador::nComparaciones;

void Contador::incremento()
{
  Contador::nComparaciones++;
}

void Contador::reset()
{
  Contador::nComparaciones = 0;
}

void Contador::inc_vector()
{
  v_comparacion.push_back(nComparaciones);
}

std::vector<int>& Contador::get_vComparacion()
{ 
  return v_comparacion;
}

}