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

DatosEstaditicos::DatosEstaditicos(std::vector<int>& datos_comparaciones)
{
  //Recogemos los datos del contador
  for (int i = 0; i < datos_comparaciones.size(); i++)
  {
    //Copiamos la informacion de un vector a otro
    vComparaciones_.push_back(datos_comparaciones[i]);
  }
}

DatosEstaditicos::~DatosEstaditicos()
{
}

//Hallar el valor minimo de las comparaciones
int DatosEstaditicos::min()
{
  int min = INT_MAX;
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
int DatosEstaditicos::max()
{
  int max = 0;
  //Recorremos los datos de las comparaciones
  for(auto dato : vComparaciones_)
    //Calculamos el valor maximo de Comparaciones
    max = std::max(dato,max);
  return max;
}

//Hallar la media de las comparaciones
double DatosEstaditicos::media()
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
int DatosEstaditicos::total()
{
  //Suma acumulativa de todo los elementos del vector
  return std::accumulate(
    vComparaciones_.begin(),
    vComparaciones_.end(),
    0
  );
}

//Vector de Comparaciones
std::vector<int>& DatosEstaditicos::get_vComparaciones()
{
  return vComparaciones_;
}

//Mostrar el numero de comparaciones, max, media
void DatosEstaditicos::mostrar()
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