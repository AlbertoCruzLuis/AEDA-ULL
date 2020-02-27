//==============================================================
//@Autor: Alberto Cruz Luis
//@Email: alu0101217734@ull.edu.es
//@Fecha: Febrero-Marzo 2020
//@Name: main.cpp
//@Version: Práctica 2 - El juego de la Vida
//==============================================================

#include "tablero.h"
#include "celula.h"

int main()
{
  int n, m, turnos;
  //Pedir las dimensiones de la malla y el numero de turnos
  std::cout << "Introducir Numero de Filas: ";
  std::cin >> n;
  std::cout << "Introducir Numero de Columnas: ";
  std::cin >> m;
  std::cout << "Introducir Numero de Turnos: ";
  std::cin >> turnos;

  //Creamos Nuestro Tablero
  AEDA::Tablero tablero(n,m,turnos);

  //Colocar las celulas vivas y actualizar el estado de las celulas
  tablero.poner_celula_viva(3,0);
  tablero.poner_celula_viva(0,1);
  tablero.poner_celula_viva(1,2);

  //Mostrar la malla del tablero
  tablero.print();

  //Ejecutar cada turno en un bucle
  //Cada turno actualizar y mostrar 
  return 0;
}