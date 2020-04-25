//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: estadistica.cpp
//@Version: Práctica 5 - ​Implementación de métodos de ordenación
//==============================================================

#ifndef PROGRAMA_ESTADISTICA
#define PROGRAMA_ESTADISTICA

#include <iostream>
#include <typeinfo>
#include <functional>
#include "../../include/Insercion.h"
#include "../../include/BubbleSort.h"
#include "../../include/HeapSort.h"
#include "../../include/QuickSort.h"
#include "../../include/Contador.h"
#include "../../include/Dni.h"
#include "../../include/DatosEstaditicos.h"

void estadistica()
{
  std::cout << "---------------------\n";
  std::cout << "| Modo Estadisticas |\n";
  std::cout << "---------------------\n";
  // 1) Solicitar Parametros Experimento
  int n;
  std::cout << "Tamaño de Secuencia [1..25]: ";
  std::cin >> n;
  while(n < 1 || n > 25)
  {
    std::cout << "Error\nIntroducir el numero de secuencia entre [1..25]: ";
    std::cin >> n;
  }
  int nPruebas;
  std::cout << "Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Definir la clave
  typedef AEDA::Dni clave;

  // 2) Crear Banco de Pruebas aleatoriamnete de secuencias Tipo DNI 
  std::vector<std::vector<clave>> banco_pruebas(nPruebas);
  srand(time(NULL));
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    for(int j = 0; j < n; j++)
      banco_pruebas[i].push_back(clave(rand()));
  }

  // 3) Realizar experimento para cada metodo de ordenacion

  //Tipos de Algoritmos Texto
  std::map<int, std::string> m_algorithm = {
    {1,"Insercion"},
    {2,"BubbleSort"},
    {3,"HeapSort"},
    {4,"QuickSort"}
  };

  //Creamos un vector de Contadores para cada algoritmo
  std::vector<AEDA::Contador> contador(m_algorithm.size());

  //Creamos un vector de datos_estadisticos para cada algoritmo
  std::vector<AEDA::DatosEstaditicos> data;

  //Tipos de Algoritmos Funciones
  //std::cout << "Tipo: " << typeid(AEDA::Insercion::Insercion<void(void)>(banco_pruebas, 8)).name() << "\n";
  std::map<int, std::function<void(std::vector<clave>&,int)>> f_algorithm = {
    {1,AEDA::Insercion::Insercion<clave>},
    {2,AEDA::BubbleSort::BubbleSort<clave>},
    {3,AEDA::HeapSort::HeapSort<clave>}
    //{4,AEDA::QuickSort::QuickSort<int>}
  };
  //Ejecutar todos los algoritmos para cada secuencia del banco de pruebas
  for(int i = 0; i < nPruebas; i++)
  {
    for(int j = 1; j <= f_algorithm.size(); j++)
    {
      AEDA::Contador::nComparaciones = 0;
      f_algorithm[j](banco_pruebas[i],n);
      contador[j-1].inc_vector();
      std::cout << j << ". NComparaciones: " 
      << AEDA::Contador::nComparaciones << "\n";
    }
    //Caso Especial - Distinto numero de parametros
    AEDA::Contador::nComparaciones = 0;
    AEDA::QuickSort::QuickSort<clave>(banco_pruebas[i],0,n-1);
    contador[3].inc_vector();
  }
  //Para cada contador de un algoritmo.
  //Creamos un objeto que calcula los datos_estadisticos de cada algoritmo
  for(int i = 0; i < m_algorithm.size(); i++)
    data.push_back(AEDA::DatosEstaditicos(contador[i].get_vComparacion()));

  //Mostrar los Datos Obtenidos
  std::cout << "+++++++++++++++++++++++++\n";
  std::cout << "| Datos del Experimento |\n"; 
  std::cout << "+++++++++++++++++++++++++\n";

  //Texto
  std::cout << "\t\t" <<
  "Minimo\t\tMedio\t\tMaximo\n";

  //Resultados cada metodo
  for(int i = 1; i <= m_algorithm.size(); i++)
  {
    std::cout << m_algorithm[i] << "\t";
    //Minimo
    std::cout << data[i-1].min() << "\t\t";
    //Medio
    std::cout << data[i-1].media() << "\t\t";
    //Maximo
    std::cout << data[i-1].max() << "\n";
  }
}

#endif