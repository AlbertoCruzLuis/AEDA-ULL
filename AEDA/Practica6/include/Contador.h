//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Contador.h
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

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

    std::vector<int>& get_vComparacion();
    static int nComparaciones;
    void incremento();
    void inc_vector();
    void reset();
  private:
    std::vector<int> v_comparacion;
};

}

#endif
