//=======================================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: Estadisticas.cpp
//@Version: Práctica 6 - ​​ Implementación de un árbol binario de búsqueda
//=======================================================================

#ifndef PROGRAMA_ESTADISTICAS
#define PROGRAMA_ESTADISTICAS

#include <iostream>
#include <vector>
#include "ArbolBB.h"
#include "Dni.h"
#include "Contador.h"
#include "DatosEstaditicos.h"

void estadistica()
{
  std::cout << "-----------------------\n";
  std::cout << "|  Modo Estadisticas  |\n";
  std::cout << "-----------------------\n";
  //Definimos el Tipo de Clave a Usar
  typedef AEDA::Dni clave;

  //Solicitar Parametros para el experimento
  int n;
  std::cout << "Tamaño del Arbol: ";
  std::cin >> n;

  int nPruebas;
  std::cout << "Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Creamos un Banco de Pruebas de valores tipo DNI aleatorios
  srand(time(NULL));
  std::vector<clave> banco(2*n);
  for(int i = 0; i < banco.size(); i++)
  {
    banco[i] = clave(rand());
  }

  //Generamos un Arbol binario de busqueda
  AEDA::ArbolBB<clave> ABB;

  //Insertamos los n primeros valores del banco
  for(int i = 0; i < n; i++)
  {
    ABB.Insertar(banco[i]);
  }

  //ABB.RecorreNivel();
  //Experimentos
  //Creamos el Contador
  AEDA::Contador contador;
  // 1) Experimento de Busqueda
  //Buscar nPruebas de las primeras n claves del banco aleatoriamente
  for(int i = 0; i < nPruebas; i++)
  {
    contador.reset();
    ABB.Buscar(banco[rand() % n]);
    //std::cout << "NComparacionB: " << AEDA::Contador::nComparaciones << "\n";
    contador.inc_vector();
  }
  //Hallamos los datos correspondientes
  AEDA::DatosEstaditicos<int> datos_busqueda(contador.get_vComparacion());
  //Limpiamos el vector
  contador.get_vComparacion().clear();
  // 2) Experimento de Insercion
  //Buscar nPruebas de las ultimas n claves del banco aleatoriamente
  for(int i = 0; i < nPruebas; i++)
  {
    contador.reset();
    ABB.Buscar(banco[rand() % (banco.size()-n) + n]);
    //std::cout << "NComparacionI: " << AEDA::Contador::nComparaciones << "\n";
    contador.inc_vector();
  }
  //Hallamos los datos correspondientes
  AEDA::DatosEstaditicos<int> datos_insercion(contador.get_vComparacion());

  // Mostramos los Datos Obtenidos
  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  std::cout << "| Datos del Experimento - Numero de Comparaciones |\n"; 
  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";

  //Texto
  std::cout << "\t\t" << 
  "N\t\tPruebas\t\tMinimo\t\tMedio\t\tMaximo\n";
  std::cout << "Busqueda";

  //Resultados Busquedas
  std::cout << "\t" << n << "\t\t" << nPruebas << "\t\t" <<
  datos_busqueda.min() << "\t\t" <<
  datos_busqueda.media() << "\t\t" <<
  datos_busqueda.max() << "\n";

  //Texto
  std::cout << "Insercion";
  
  //Resultados Insercion
  std::cout << "\t" << n << "\t\t" << nPruebas << "\t\t" <<
  datos_insercion.min() << "\t\t" <<
  datos_insercion.media() << "\t\t" <<
  datos_insercion.max() << "\n";
}

#endif