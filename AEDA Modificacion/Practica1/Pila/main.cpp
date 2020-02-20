//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero 2020
//@Name: main.h
//@Version: Practica 1 - Implementación de Estructuras de Datos
//==============================================================

#include "stack.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
  AEDA::stack<int> A(4);
  AEDA::stack<std::vector<std::string>> B(4);

  for(int i = 0; i < A.get_size(); i++)
  {
    A.push(i);
    B.push(std::vector<std::string>{"blanco","negro","rojo","azul"});
  }

  for(int i = 0; i < A.get_size(); i++)
  {
    std::cout << A.get_top() << std::endl;
    for(int j = 0; j < B.get_top().size(); j++)
      std::cout << B.get_top()[j] << "-";
    std::cout << "\n";
    A.pop();
    B.pop();
  }

  //Sumar dos Pilas de enteros
  AEDA::stack<int> a(5),b(5),sum(5);
  for(int i = 0; i < a.get_size(); i++)
  {
    a.push(i+10);
    b.push(i);
  }
  (a + b).write();


  return 0;
}