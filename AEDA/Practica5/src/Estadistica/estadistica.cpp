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
#include <functional>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include "../../include/Insercion.h"
#include "../../include/BubbleSort.h"
#include "../../include/HeapSort.h"
#include "../../include/QuickSort.h"
#include "../../include/ShellSort.h"
#include "../../include/Contador.h"
#include "../../include/Dni.h"
#include "../../include/ISBN.h"
#include "../../include/DatosEstaditicos.h"

void estadistica()
{
  std::cout << "---------------------\n";
  std::cout << "| Modo Estadisticas |\n";
  std::cout << "---------------------\n";
  // 1) Solicitar Parametros Experimento
  int n;
  std::cout << "Tamaño de Secuencia [1..1000]: ";
  std::cin >> n;
  while(n < 1 || n > 1000)
  {
    std::cout << "Error\nIntroducir el numero de secuencia entre [1..25]: ";
    std::cin >> n;
  }
  int nPruebas;
  std::cout << "Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Definir la clave
  //typedef AEDA::Dni clave;
  typedef AEDA::ISBN clave;

  // 2) Crear Banco de Pruebas aleatoriamnete de secuencias Tipo DNI 
  std::vector<std::vector<clave>> banco_pruebas(nPruebas);
  //srand(time(NULL));
  srand(0);
  for(int i = 0; i < banco_pruebas.size(); i++)
  {
    for(int j = 0; j < n; j++)
    {
      banco_pruebas[i].push_back(clave(rand()));
    }
  }

  // 3) Realizar experimento para cada metodo de ordenacion

  //Tipos de Algoritmos Texto
  std::map<int, std::string> m_algorithm = {
    {1,"Insercion"},
    {2,"BubbleSort"},
    {3,"HeapSort"},
    {4,"ShellSort"},
    {5,"QuickSort"}
  };

  //Crear varibles para medir el tiempo de ejecucion de cada algoritmo
  std::vector<std::vector<clock_t>> t(m_algorithm.size());

  //Creamos un vector de Contadores para cada algoritmo
  std::vector<AEDA::Contador> contador(m_algorithm.size());

  //Creamos un vector de datos_estadisticos para cada algoritmo
  std::vector<AEDA::DatosEstaditicos<int>> data;

  //Creamos un vector de datos_estadisticos para el tiempo de cada algoritmo
  std::vector<AEDA::DatosEstaditicos<clock_t>> data_time;

  //Tipos de Algoritmos Funciones
  std::map<int, std::function<void(std::vector<clave>,int)>> f_algorithm = {
    {1,AEDA::Insercion::Insercion<clave>},
    {2,AEDA::BubbleSort::BubbleSort<clave>},
    {3,AEDA::HeapSort::HeapSort<clave>},
  };
  //Elegir constante de reduccion alfa
  double a;
  std::cout << "Elegir constante reduccion alfa[0 < a < 1]: ";
  std::cin >> a;
  while(a <= 0 || a >= 1)
  {
    std::cout << "Error\nElegir constante reduccion alfa[0 < a < 1]: ";
    std::cin >> a;
  }
  //Ejecutar todos los algoritmos para cada secuencia del banco de pruebas
  //NOTA: Si no quitas las referencias la secuencia quedara ordenada
  //Puede causar problemas a la hora de comparar los algoritmos
  for(int i = 0; i < nPruebas; i++)
  {
    //std::cout << "Iter: " << i << "\n";
    for(int j = 1; j <= f_algorithm.size(); j++)
    {
      AEDA::Contador::nComparaciones = 0;
      //Inicio Tiempo
      t[j-1].push_back(clock());
      f_algorithm[j](banco_pruebas[i],banco_pruebas[i].size());
      t[j-1].push_back(clock() - t[j-1][i]);
      //Final Tiempo
      contador[j-1].inc_vector();
    }
    //Caso Especiales - Distinto numero de parametros
    //ShellSort
    AEDA::Contador::nComparaciones = 0;
    t[3].push_back(clock());
    AEDA::ShellSort::ShellSort<clave>(banco_pruebas[i],banco_pruebas[i].size(),a);
    t[3].push_back(clock() - t[3][i]);
    contador[3].inc_vector();
    //QuickSort
    AEDA::Contador::nComparaciones = 0;
    t[4].push_back(clock());
    AEDA::QuickSort::QuickSort<clave>(banco_pruebas[i],0,banco_pruebas[i].size()-1);
    t[4].push_back(clock() - t[4][i]);
    contador[4].inc_vector();
  }
  //Para cada contador de un algoritmo.
  //Creamos un objeto que calcula los datos_estadisticos de cada algoritmo
  for(int i = 0; i < m_algorithm.size(); i++)
    data.push_back(AEDA::DatosEstaditicos<int>(contador[i].get_vComparacion()));

  //Creamos los datos_estadisticos para el tiempo de cada algoritmo
  for(int i = 0; i < m_algorithm.size(); i++)
    data_time.push_back(AEDA::DatosEstaditicos<clock_t>(t[i]));

  //Mostrar los Datos Obtenidos
  std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
  std::cout << "| Datos del Experimento - Nº Comparaciones |\n"; 
  std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";

  //Texto
  std::cout << "\t\t" <<
  "Minimo\t\tMedio\t\tMaximo\t\tTiempo Max\tTiempo Medio\tTiempo Min\n";

  //Resultados cada metodo
  for(int i = 1; i <= m_algorithm.size(); i++)
  {
    std::cout << m_algorithm[i] << "\t";
    //Minimo
    std::cout << data[i-1].min() << "\t\t";
    //Medio
    std::cout << std::setprecision(2) << std::fixed <<
    data[i-1].media() << "\t\t";
    //Maximo
    std::cout << data[i-1].max() << "\t\t";
    //Tiempo Maximo
    std::cout << std::setprecision(4) << std::fixed <<
    double(data_time[i-1].max())/CLOCKS_PER_SEC << "\t\t";
    //Tiempo Medio
    std::cout << std::setprecision(4) << std::fixed <<
    data_time[i-1].media()/CLOCKS_PER_SEC << "\t\t";
    //Tiempo Minimo
    std::cout << std::setprecision(4) << std::fixed <<
    double(data_time[i-1].min())/CLOCKS_PER_SEC << "\n";
  }
}

#endif
