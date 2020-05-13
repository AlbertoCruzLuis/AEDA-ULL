//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
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

template<class data>
class DatosEstaditicos
{
  public:
    DatosEstaditicos(std::vector<data>&);
    ~DatosEstaditicos();
    std::vector<data>& get_vComparaciones();
    data total();
    data max();
    data min();
    double media();
    void mostrar();

  private:
    std::vector<data> vComparaciones_;
};

template<class data>
DatosEstaditicos<data>::DatosEstaditicos(std::vector<data>& datos_comparaciones)
{
  //Recogemos los datos del contador
  for (int i = 0; i < datos_comparaciones.size(); i++)
  {
    //Copiamos la informacion de un vector a otro
    vComparaciones_.push_back(datos_comparaciones[i]);
  }
}

template<class data>
DatosEstaditicos<data>::~DatosEstaditicos()
{
}

//Hallar el valor minimo de las comparaciones
template<class data>
data DatosEstaditicos<data>::min()
{
  data min = INT_MAX;
  //Comprobar si ha habido comparaciones
  if(vComparaciones_.size() > 0)
  {
    //Recorremos los datos de las comparaciones
    for(auto dato : vComparaciones_)
      //Calculamos el valor minimo de Comparaciones
      min = std::min(dato,min);
    return min;
  }
  return 0;
}

//Hallar el valor maximo de las comparaciones
template<class data>
data DatosEstaditicos<data>::max()
{
  data max = 0;
  //Recorremos los datos de las comparaciones
  for(auto dato : vComparaciones_)
    //Calculamos el valor maximo de Comparaciones
    max = std::max(dato,max);
  return max;
}

//Hallar la media de las comparaciones
template<class data>
double DatosEstaditicos<data>::media()
{
  double media = 0;
  //Comprobar que ha habido comparaciones
  if(vComparaciones_.size() > 0)
  {
    //Hallar la suma de todos los elementos del vector
    //Dividirlos entre el numero de elementos para obtener la media
    //NOTA: Pasar uno de los dos numeros a double
    media = double(std::accumulate(
      vComparaciones_.begin(),
      vComparaciones_.end(),
      0)) / vComparaciones_.size();
  }
  return media;
}

//Total de Comparaciones
template<class data>
data DatosEstaditicos<data>::total()
{
  //Suma acumulativa de todo los elementos del vector
  return std::accumulate(
    vComparaciones_.begin(),
    vComparaciones_.end(),
    0
  );
}

//Vector de Comparaciones
template<class data>
std::vector<data>& DatosEstaditicos<data>::get_vComparaciones()
{
  return vComparaciones_;
}

//Mostrar el numero de comparaciones, max, media
template<class data>
void DatosEstaditicos<data>::mostrar()
{
  //Comprobar que existan comparaciones
  if(vComparaciones_.size() > 0)
  {
    std::cout << "Total Comparaciones: " << total() <<
    "\n";
    std::cout << "Minimo Comparaciones: " << min() << "\n";
    std::cout << "Maximo Comparaciones: " << max() << "\n";
    std::cout << "Media Comparaciones: " << media() << "\n";
  }else
  {
    std::cout << "No ha habido comparaciones\n";
  }
}

}

#endif
