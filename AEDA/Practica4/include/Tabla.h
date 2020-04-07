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
#include "Celda.h"
#include "FDispersionBase.h"
#include "FDispersionModulo.h"

namespace AEDA
{
template<class Clave>
class Tabla
{
  public:
    Tabla(int, int, int);
    ~Tabla();

    bool Buscar(Clave X);
    bool Insertar(Clave X);
    void Mostrar();
  
  private:
    std::vector<Celda<Clave>*> vCelda_;      //Vector de Celdas    
    int nCeldas_;                            //Numero de Celdas
    FDispersionBase<Clave>* f_dispersion_;   //Funcion Dispersion
    //Funcion Exploracion
};

//Implementacion de los metodos
template<class Clave>
Tabla<Clave>::Tabla(int nCeldas, int nClaves, int tipoFDispersion) :
nCeldas_(nCeldas)
{
  //Creamos las Celdas
  for(int i = 0; i < nCeldas_; i++)
  {
    vCelda_.push_back(new Celda<Clave>(nClaves));
  }
  //Crear la funcion de dispersion
  switch (tipoFDispersion)
  {
    case 0: f_dispersion_ = new FDispersionModulo<Clave>();
      break;
  }
}

template<class Clave>
Tabla<Clave>::~Tabla()
{
}


template<class Clave>
bool Tabla<Clave>::Buscar(Clave X)
{
  
}

template<class Clave>
bool Tabla<Clave>::Insertar(Clave X)
{
  //Habria que decidir la pos mediante las FDispersion o FExploracion
  //Ejemplo pos 0
  vCelda_[0]->Insertar(X);
}

template<class Clave>
void Tabla<Clave>::Mostrar()
{
  std::cout << "---Tabla Hash---\n";
  //Mostrar cada celda de la tabla
  for(int i = 0; i < vCelda_.size(); i++)
  {
    vCelda_[i]->Mostrar();
  }
}

}

#endif