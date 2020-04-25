//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Dni.h
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef DNI_H
#define DNI_H

#include <cstdlib>     //srand, rand
#include <ctime>        //time
#include <vector>
#include <iostream>
#include <math.h>
#include "Contador.h"

namespace AEDA
{
class Dni
{
  public:
    Dni();
    Dni(int);
    Dni(Dni&);   //Constructor de copia
    operator unsigned long();
    bool operator==(Dni&);
    bool operator<(Dni&);
    bool operator>(Dni&);

  private:
    //Identificador de 8 digitos [00000000...99999999]
    std::vector<int> id_;
    Contador contador;
};
}

#endif