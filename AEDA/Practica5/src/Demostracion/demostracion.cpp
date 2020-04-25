//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: demostracion.cpp
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef PROGRAMA_DEMOSTRACION
#define PROGRAMA_DEMOSTRACION

#include <iostream>
#include <map>
#include <vector>
#include "../../include/Insercion.h"
#include "../../include/BubbleSort.h"
#include "../../include/HeapSort.h"
#include "../../include/QuickSort.h"
#include "../../include/Dni.h"

void demostracion()
{
  std::cout << "---------------------\n";
  std::cout << "| Modo Demostracion |\n";
  std::cout << "---------------------\n";
  // 1) Solicitar Parametros
  int n;
  std::cout << "Tamaño de Secuencia [1..25]: ";
  std::cin >> n;
  while(n < 1 || n > 25)
  {
    std::cout << "Error\nIntroducir el factor de carga entre [1..25]: ";
    std::cin >> n;
  }

  std::map<int, std::string> m_algorithm = {
    {1,"Insercion"},
    {2,"BubbleSort"},
    {3,"HeapSort"},
    {4,"QuickSort"}
  };
  int type_algorithm;
  std::cout << "1.Insercion\t2.BubbleSort\t3.HeapSort\t4.QuickSort\n";
  std::cout << "Tipo de Algoritmo: ";
  std::cin >> type_algorithm;
  //Comprobar si la clave se encuentra en el mapa
  auto itD = m_algorithm.find(type_algorithm);
  while(itD == m_algorithm.end())
  {
    std::cout << "Error" << "\nTipo de Algoritmo: ";
    std::cin >> type_algorithm;
    itD = m_algorithm.find(type_algorithm);
  }

  // 2)Generar aleatoriamente una secuencia de tamaño N ​de objetos DNI​
  //Definir la clave
  typedef AEDA::Dni clave;
  srand(time(NULL));
  std::vector<clave> secuencia(n);
  for(int i = 0; i < secuencia.size(); i++)
  {
    secuencia[i] = clave(rand());
    //secuencia[i] = rand() % 100;
  }

  //Mostrar Vector Original
  std::cout << "Vector Original\n";
  for(auto d : secuencia)
  {
    std::cout << d << "  ";
  }
  std::cout << "\n";

  // 3) Ejecucion del Algoritmo Paso a Paso
  std::cout << "----| Pulsar -> Enter en cada Paso-----\n";
  std::cout << "Ejecucion del Algoritmo " << 
  m_algorithm[type_algorithm] << "\n";
  switch (type_algorithm)
  {
    case 1: AEDA::Insercion::Insercion<clave>(secuencia, n);
      break;
    case 2: AEDA::BubbleSort::BubbleSort<clave>(secuencia, n);
      break;
    case 3: AEDA::HeapSort::HeapSort<clave>(secuencia, n);
      break;
    case 4: AEDA::QuickSort::QuickSort<clave>(secuencia,0,n-1);
      break;
  }
  //Mostrar Secuencia Ordenada
  std::cout << "Vector Ordenado\n";
  for(auto d : secuencia)
  {
    std::cout << d << "  ";
  }
  std::cout << "\n";
}

#endif