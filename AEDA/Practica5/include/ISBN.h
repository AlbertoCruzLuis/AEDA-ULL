//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef ISBN_H
#define ISBN_H

#include <cstdlib>     //srand, rand
#include <iostream>
#include <vector>
#include <math.h>
#include "Contador.h"

namespace AEDA
{
  class ISBN
  {
    public:
      ISBN();
      ISBN(int);
      operator unsigned long();
      bool operator==(ISBN&);
      bool operator<(ISBN&);
      bool operator>(ISBN&);

    private:
      //Identificador de 10 digitos [0000000000...9999999999]
      std::vector<int> id_;
      Contador contador;
  };
}

#endif