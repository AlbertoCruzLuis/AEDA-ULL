//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: DatosEstadisticos.cpp
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/DatosEstaditicos.h"

namespace AEDA
{

DatosEstaditicos::DatosEstaditicos()
{
  nComparaciones_ = 0;
}

DatosEstaditicos::~DatosEstaditicos()
{
}

void DatosEstaditicos::Incremento()
{
  maxComparaciones_++;
  nComparaciones_++;
}

void DatosEstaditicos::max()
{
  maxComparaciones_ = 0;
}

int DatosEstaditicos::get_maxComparaciones()
{
  return maxComparaciones_;
}

int DatosEstaditicos::get_nComparaciones()
{
  return nComparaciones_;
}

}