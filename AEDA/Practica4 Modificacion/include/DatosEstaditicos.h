//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: DatosEstadisticos.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef DATOS_ESTADISTICOS_H
#define DATOS_ESTADISTICOS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>      // std::accumulate
#include <limits.h>       //std::INT_MAX

namespace AEDA
{

class DatosEstaditicos
{
  public:
    DatosEstaditicos(std::vector<int>&);
    ~DatosEstaditicos();
    std::vector<int>& get_vComparaciones();
    int total();
    int max();
    int min();
    double media();
    void mostrar();

  private:
    std::vector<int> vComparaciones_;
};

}

#endif
