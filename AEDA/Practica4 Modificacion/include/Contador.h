//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Contador.h
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#ifndef CONTADOR_H
#define CONTADOR_H

#include <vector>

namespace AEDA
{

class Contador
{
  public:
    Contador(/* args */);
    ~Contador();

    static std::vector<int> v_comparacion;
    static int nComparaciones;
    void incremento();
    void inc_vector();
    void reset();
};

}

#endif
