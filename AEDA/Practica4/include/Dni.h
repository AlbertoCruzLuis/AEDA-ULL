//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef DNI_H
#define DNI_H

#include <cstdlib>     //srand, rand
#include <ctime>        //time
#include <vector>
#include <iostream>
#include <math.h>

namespace AEDA
{
class Dni
{
  public:
    Dni();
    Dni(int);
    operator unsigned long();

  private:
    //Identificador de 8 digitos [00000000...99999999]
    std::vector<int> id_;  
};
}

#endif