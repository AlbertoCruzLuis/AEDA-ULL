//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Contador.cpp
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/Contador.h"

namespace AEDA
{

Contador::Contador(/* args */)
{
}

Contador::~Contador()
{
}

std::vector<int> Contador::v_comparacion;
int Contador::nComparaciones = 0;

void Contador::incremento()
{
  Contador::nComparaciones++;
}

void Contador::reset()
{
  Contador::nComparaciones = 0;
  Contador::v_comparacion.clear();
}

void Contador::inc_vector()
{
  Contador::v_comparacion.push_back(Contador::nComparaciones);
}

}