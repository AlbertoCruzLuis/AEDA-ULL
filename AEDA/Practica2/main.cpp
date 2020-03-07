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
  std::cout << "Introducir Numero de Columnas: ";
  std::cin >> n;
  std::cout << "Introducir Numero de Filas: ";
  std::cin >> m;
  std::cout << "Introducir Numero de Turnos: ";
  std::cin >> turnos;

  //Creamos Nuestro Tablero
  AEDA::Tablero tablero(n,m);

  //Elegir la forma de colocar las celulas vivas
  std::cout << "Pulsa 0 - Para introducir celulas manualmente\n"
  << "Pulsa 1 - Para introducir celulas aleatoriamente\n";
  int mode;
  std::cin >> mode;
  if(mode)
    tablero.random_tablero();
  else
    tablero.rellenar_tablero();

  //Mostrar la malla del tablero Inicialmente
  tablero.print();

  //Ejecutamos cada turno del juego en un bucle
  while(turnos--)
  {
    //Mostrar Turno
    std::cout << "------ Turnos Restantes " << turnos << "------\n";

    //Contar Vecinas y Actualizar estado
    tablero.update(); 
    //Mostrar por Pantalla
    tablero.print();
  }
  return 0;
}