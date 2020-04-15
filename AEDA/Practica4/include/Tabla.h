//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Tabla.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef TABLA_H
#define TABLA_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "Celda.h"
#include "FDispersionBase.h"
#include "FDispersionModulo.h"
#include "FDispersionSuma.h"
#include "FDispersionPseudoaleatoria.h"
#include "FExploracionBase.h"
#include "FExploracionLineal.h"
#include "FExploracionCuadratica.h"
#include "FExploracionDispersionDoble.h"
#include "FExploracionRehashing.h"

namespace AEDA
{
template<class Clave>
class Tabla
{
  public:
    Tabla(int, int, int, int);
    ~Tabla();

    bool Buscar(Clave& X);
    bool Insertar(Clave& X);
    void Mostrar();
  
  private:
    std::vector<Celda<Clave>*> vCelda_;      //Vector de Celdas    
    int nCeldas_;                             //Numero de Celdas
    FDispersionBase<Clave>* f_dispersion_;    //Funcion Dispersion
    FExploracionBase<Clave>* f_exploracion_;  //Funcion Exploracion
};

//Implementacion de los metodos
template<class Clave>
Tabla<Clave>::Tabla(int nCeldas, int nClaves, int tipoFDispersion, int tipoFExploracion) :
nCeldas_(nCeldas)
//estadisticas_()
{
  //Creamos las Celdas
  for(int i = 0; i < nCeldas_; i++)
  {
    vCelda_.push_back(new Celda<Clave>(nClaves));
  }
  //Crear la funcion de dispersion
  switch (tipoFDispersion)
  {
    case 0: f_dispersion_ = new FDispersionModulo<Clave>(nCeldas);
      break;
    case 1: f_dispersion_ = new FDispersionSuma<Clave>(nCeldas);
      break;
    case 2: f_dispersion_ = new FDispersionPseudoaleatoria<Clave>(nCeldas);
      break;
  }
  //Crear la funcion de exploracion
  switch (tipoFExploracion)
  {
    case 0: f_exploracion_ = new FExploracionLineal<Clave>();
      break;
    case 1: f_exploracion_ = new FExploracionCuadratica<Clave>();
      break;
    case 2: f_exploracion_ = new FExploracionDispersionDoble<Clave>(nCeldas);
      break;
    case 3: f_exploracion_ = new FExploracionRehashing<Clave>(nCeldas);
      break;
  }
}

template<class Clave>
Tabla<Clave>::~Tabla()
{
  //Liberamos la memoria
  for(int i = 0; i < vCelda_.size(); i++)
  {
    delete vCelda_[i];
  }
}


template<class Clave>
bool Tabla<Clave>::Buscar(Clave& X)
{
  //Encontrar la clave en la tabla
  //1)Buscar en la posicion que deberia encontrase.
  int pos = (*f_dispersion_)(X);
  if(vCelda_[pos]->Buscar(X))
  {
    //std::cout << "Clave: " << X << " Ha sido encontrada\n";
    return true;
  }
  //2)Buscar en posiciones respecto a la funcion de exploracion
  int i = 0;
  pos = ((*f_dispersion_)(X) + (*f_exploracion_)(X,i)) % nCeldas_;
  i++;
  while(!vCelda_[pos]->Buscar(X))
  {
    pos = ((*f_dispersion_)(X) + (*f_exploracion_)(X,i)) % nCeldas_;
    i++;
    //std::cout << "POS: " << pos << "\n";
    //std::cout << "ITER Exploracion: " << i << "\n";
  }
  //std::cout << "Clave: " << X << " - Iter: " << i << "\n";
  return true;
}

template<class Clave>
bool Tabla<Clave>::Insertar(Clave& X)
{
  //Hallamos la posicion de la Clave mediante la FDispersion
  int pos = (*f_dispersion_)(X);
  std::cout << "Clave: " << X << " - POS: " << pos << "\n";
  
  int i=0;    //Numero de Intentos de exploracion
  //Comprobamos si hay espacio para insertar la clave
  while(!vCelda_[pos]->Insertar(X))
  {
    //Aplicamos la funcion de exploracion
    pos = ((*f_dispersion_)(X) + (*f_exploracion_)(X,i++)) % nCeldas_;
    std::cout << "ITER Exploracion: " << i << "\n";
  }

  return true;
}

template<class Clave>
void Tabla<Clave>::Mostrar()
{
  //Mostrar unicamente cuando se pueda adaptar a la pantalla
  if(nCeldas_ <= 30)
  {
    std::cout << "++++++++++++++\n";
    std::cout << "| Tabla Hash |\n";
    std::cout << "++++++++++++++\n";
    //Mostrar cada celda de la tabla
    for(int i = 0; i < vCelda_.size(); i++)
    {
      std::cout << i << " || ";
      vCelda_[i]->Mostrar();
      std::cout << "  " << std::setfill('-') << std::setw(nCeldas_*4) << "\n";
    }
  }else
  {
    std::cout << "Tamaño demasiado grande para mostrar la Tabla Hash\n";
  }
}

}

#endif