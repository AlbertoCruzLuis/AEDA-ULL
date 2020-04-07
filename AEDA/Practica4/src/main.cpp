//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Abril 2020
//@Name: main.cpp
//@Version: Práctica 4 - Implementación de búsqueda mediante Tabla Hash
//==============================================================

#include "../include/Tabla.h"
#include "../include/Dni.h"
#include <iostream>
#include <vector>
#include "../include/Celda.h"

int main()
{
  //Parametros para crear la tabla Hash
  int nCeldas;
  int nClaves;

  //Solicitar los parametros para crear la tabla Hash
  std::cout << "Introducir Numero de Celdas: ";
  std::cin >> nCeldas;
  std::cout << "Introducir NUmero de Claves: ";
  std::cin >> nClaves;

  int mode;   //Tipo de Funcion de Dispersion
  std::cout << "Elegir una Funcion de Dispersion\n";
  std::cout << "Modulo: 0\nSuma: 1\nPseudoaleatoria: 2\n";
  std::cout << "Tipo: ";
  std::cin >> mode;

  AEDA::Tabla<int> tabla(nCeldas, nClaves, mode);
  tabla.Insertar(15);
  tabla.Insertar(5);
  tabla.Insertar(9);
  tabla.Mostrar();
  //tabla.Buscar(nCeldas);

  //Pedir Funcion de Dispersion
  //Pedir Funcion de Exploracion

  //Parametros del experimento
  int factor;     //Valor entre [0...1]
  int nPruebas;

  //Solicitar los parametros del experimento
  std::cout << "Introducir el factor de carga entre [0..1]: ";
  std::cin >> factor;
  std::cout << "Introducir el Numero de Pruebas: ";
  std::cin >> nPruebas;

  //Crear un banco de prueba
  //2*N Valores Tipo Dni Random
  //Tamaño banco de pruebas
  //int N = factor * nCeldas * nClaves;
  AEDA::Dni dni;
  //Banco de Pruebas
  //std::vector<AEDA::Dni> banco_pruebas(N);

  //Crear Tabla Hash e insertar los N valores obtenidos del Banco de Pruebas


  //1) Experimento Operacion Busqueda
  //Inicializar a 0 

  //Realizar la busqueda

  //Mostrar los datos obtenidos
  

  //2) Experimento Operacion Insercion
  //Inicializar a 0 

  //Realizar la busqueda

  //Mostrar los datos obtenidos


}