//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.cpp
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#include "../include/ISBN.h"

namespace AEDA
{

ISBN::ISBN()
{
  //Generar Numero id aleatoriamente
  //Generar Semilla
  srand(time(NULL));

  //Generar 8 digitos [0...9] 
  for(int i = 0; i < 10; i++)
  {
    id_.push_back(rand() % 10);
  }
}

ISBN::ISBN(int semilla)
{
  //Generar Numero id aleatoriamente
  //Generar Semilla
  srand(semilla);

  //Generar 10 digitos [0...9] 
  for(int i = 0; i < 10; i++)
  {
    id_.push_back(rand() % 10);
    //std::cout << id_[i];
  }
  //std::cout << "\n";
}

ISBN::operator unsigned long()
{
  unsigned long valor_isbn = 0;
  //Recorremos todos los digitos
  //std::cout << "TAM: " << id_.size() << "\n";
  for(int i = 0; i < id_.size(); i++)
  {
    //Convertir el numero mediante su valor de unidad
    //Es decir: Unidades:1, Decenas:10 Centenas:100
    valor_isbn += id_[i] * std::pow(10,id_.size()-1-i);
  }
  return valor_isbn;
}

bool ISBN::operator==(ISBN& isbn)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C==: " << AEDA::Contador::nComparaciones << "\n";
  //std::cout << "Clave: " << dni << "\n";
  //Comprobamos que tenga el mismo tamaño
  if(id_.size() != isbn.id_.size())
    return false;
  //Recorremos todos los digitos
  for (int i = 0; i < id_.size(); i++)
  {
    //Comparamos cada digito
    if(id_[i] != isbn.id_[i])
      return false;
  }
  //contador.inc_vector();
  //Contador::nComparaciones = 0;
  return true;
}

bool ISBN::operator<(ISBN& isbn)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C<: " << AEDA::Contador::nComparaciones << "\n";

  //Comprobamos el tamaño de los digitos
  if(id_.size() < isbn.id_.size())
    return true;
  else if(id_.size() > isbn.id_.size())
    return false;
  else
  {
    //Comparamos digito a digito si es menor
    for(int i = 0; i < id_.size(); i++)
    {
      if(id_[i] < isbn.id_[i])
        return true;
      else if(id_[i] > isbn.id_[i])
        return false;
    }
  }
  return false;
}

bool ISBN::operator>(ISBN& isbn)
{
  //Contar las comparaciones
  contador.incremento();
  //std::cout << "C>: " << AEDA::Contador::nComparaciones << "\n";

  //Comprobamos el tamaño de los digitos
  if(id_.size() > isbn.id_.size())
    return true;
  else if(id_.size() < isbn.id_.size())
    return false;
  else
  {
    //Comparamos digito a digito si es mayor
    for(int i = 0; i < id_.size(); i++)
    {
      if(id_[i] > isbn.id_[i])
        return true;
      else if(id_[i] < isbn.id_[i])
        return false;
    }
  }
  return false;
}

}