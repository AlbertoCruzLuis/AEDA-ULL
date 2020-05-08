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
#include "../../include/ShellSort.h"
#include "../../include/QuickSort.h"
#include "../../include/Dni.h"
#include "../../include/ISBN.h"

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
    {4,"QuickSort"},
    {5,"ShellSort"}
  };
  int type_algorithm;
  std::cout << "1.Insercion\t2.BubbleSort\t3.HeapSort\t4.QuickSort\t5.ShellSort\n";
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
  //typedef AEDA::Dni clave;
  typedef AEDA::ISBN clave;
  srand(time(NULL));
  std::vector<clave> secuencia(n);
  for(int i = 0; i < secuencia.size(); i++)
  {
    secuencia[i] = clave(rand());
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
  //Creamos el vector en donde va a estar guardado el vector ordenado
  std::vector<clave> secuencia_ordenada;
  switch (type_algorithm)
  {
    case 1: secuencia_ordenada = AEDA::Insercion::Insercion<clave>(secuencia, n);
      break;
    case 2: secuencia_ordenada = AEDA::BubbleSort::BubbleSort<clave>(secuencia, n);
      break;
    case 3: secuencia_ordenada = AEDA::HeapSort::HeapSort<clave>(secuencia, n);
      break;
    case 4: secuencia_ordenada = AEDA::QuickSort::QuickSort<clave>(secuencia,0,n-1);
      break;
    case 5: 
      double a;
      std::cout << "Elegir constante reduccion alfa[0 < a < 1]: ";
      std::cin >> a;
      while(a <= 0 || a >= 1)
      {
        std::cout << "Error\nElegir constante reduccion alfa[0 < a < 1]: ";
        std::cin >> a;
      }
      secuencia_ordenada = AEDA::ShellSort::ShellSort<clave>(secuencia,n,a);
      break;
  }
  //Mostrar Secuencia Ordenada
  std::cout << "Vector Ordenado\n";
  for(auto d : secuencia_ordenada)
  {
    std::cout << d << "  ";
  }
  std::cout << "\n";
}

#endif