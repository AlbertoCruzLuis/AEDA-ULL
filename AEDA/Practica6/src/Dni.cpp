//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.cpp
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

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
    //std::cout << id_[i];
  }
  //std::cout << "\n";
}

std::vector<int>& Dni::get_id()
{ return id_; }

Dni::operator unsigned long()
{
  unsigned long valor_dni = 0;
  //Recorremos todos los digitos
  //std::cout << "TAM: " << id_.size() << "\n";
  for(int i = 0; i < id_.size(); i++)
  {
    //Convertir el numero mediante su valor de unidad
    //Es decir: Unidades:1, Decenas:10 Centenas:100
    valor_dni += id_[i] * std::pow(10,id_.size()-1-i);
  }
  return valor_dni;
}

bool Dni::operator==(Dni& dni)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C==: " << AEDA::Contador::nComparaciones << "\n";
  //std::cout << "Clave: " << dni << "\n";
  //Comprobamos que tenga el mismo tamaño
  if(id_.size() != dni.id_.size())
    return false;
  //Recorremos todos los digitos
  for (int i = 0; i < id_.size(); i++)
  {
    //Comparamos cada digito
    if(id_[i] != dni.id_[i])
      return false;
  }
  //contador.inc_vector();
  //Contador::nComparaciones = 0;
  return true;
}

bool Dni::operator<(Dni& dni)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C<: " << AEDA::Contador::nComparaciones << "\n";

  //Comprobamos el tamaño de los digitos
  if(id_.size() < dni.id_.size())
    return true;
  else if(id_.size() > dni.id_.size())
    return false;
  else
  {
    //Comparamos digito a digito si es menor
    for(int i = 0; i < id_.size(); i++)
    {
      if(id_[i] < dni.id_[i])
        return true;
      else if(id_[i] > dni.id_[i])
        return false;
    }
  }
  return false;
}

bool Dni::operator>(Dni& dni)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C>: " << AEDA::Contador::nComparaciones << "\n";

  //Comprobamos el tamaño de los digitos
  if(id_.size() > dni.id_.size())
    return true;
  else if(id_.size() < dni.id_.size())
    return false;
  else
  {
    //Comparamos digito a digito si es mayor
    for(int i = 0; i < id_.size(); i++)
    {
      if(id_[i] > dni.id_[i])
        return true;
      else if(id_[i] < dni.id_[i])
        return false;
    }
  }
  return false;
}

std::istream& operator>>(std::istream& is, Dni& dni)
{
  std::cout << "Introducir los 8 Digitos del Dni\n";
  for(int i = 0; i < dni.get_id().size(); i++)
  {
    is >> dni.get_id()[i];
  }
  return is;
}
 
}