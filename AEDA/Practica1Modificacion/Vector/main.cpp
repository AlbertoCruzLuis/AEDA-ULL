//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: main.cpp
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "vector.h"
#include <string>

int main()
{
  AEDA::vector<std::string> A{"a0","a1","a2"};
  AEDA::vector<std::string> B(2,"rellenar");
  AEDA::vector<AEDA::vector<int>> B1(2);
  
  std::cout << A.get_size() << std::endl;
  std::cout << B[0] << std::endl;
  std::cout << B[1] << std::endl;
  AEDA::vector<int> D(2,0);
  for(int i = 0; i < B1.get_size(); i++)
  {
    B1[i] = D;
    B1[i].write();
  }

  for(int i = 0; i < A.get_size(); i++)
  {
    std::cout << "DATO: " << A.at(i) << std::endl;
  }
  A.write();

  std::cout << B.at(0);
  std::cout << B[0] << std::endl;

  std::cout << B.front() << std::endl;
  std::cout << B.back() << std::endl;

  B.write();

  AEDA::vector<char> E{'1','a','5'};
  E.write();
    
  return 0;
}